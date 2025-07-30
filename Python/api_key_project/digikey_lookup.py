# Version:0.9.4

import os
import csv
import subprocess
import sys
import socket
import logging
from pathlib import Path
from datetime import datetime
from dotenv import load_dotenv

# Load environment variables from .env file
# Please edit the .env.example file with your Digikey client credentials
load_dotenv()

# Setup error logging
logging.basicConfig(filename='errors.log', level=logging.ERROR, format='%(asctime)s - %(levelname)s - %(message)s')

# Attempt to install required dependencies
REQUIRED_PACKAGES = ["pandas", "openpyxl"]
for package in REQUIRED_PACKAGES:
    try:
        __import__(package)
    except ImportError:
        subprocess.check_call([sys.executable, "-m", "pip", "install", package])

import pandas as pd
import digikey
from digikey.v4.productinformation import KeywordRequest

# ANSI colors for styling
RESET = "\033[0m"
BOLD = "\033[1m"
GREEN = "\033[92m"
RED = "\033[91m"
CYAN = "\033[96m"
YELLOW = "\033[93m"
BLUE = "\033[94m"

# Set DigiKey environment variables
os.environ["DIGIKEY_CLIENT_ID"] = os.getenv("DIGIKEY_CLIENT_ID")
os.environ["DIGIKEY_CLIENT_SECRET"] = os.getenv("DIGIKEY_CLIENT_SECRET")
os.environ["DIGIKEY_STORAGE_PATH"] = str(Path("digikey_cache"))
os.environ["DIGIKEY_CLIENT_SANDBOX"] = "False"

# Global list to store all looked-up parts
searched_parts = []

def is_connected():
    try:
        socket.create_connection(("8.8.8.8", 53), timeout=3)
        return True
    except OSError:
        return False

def search_and_select_part(part_input):
    if not is_connected():
        print(f"{RED}❌ No internet connection. Please check your connection and try again.{RESET}")
        return

    try:
        request = KeywordRequest(keywords=part_input, limit=20)
        results = digikey.keyword_search(body=request)

        if not results.products:
            print(f"{RED}❌ No results found.{RESET}")
            return

        print(f"\n{BLUE}🔍 Matching Parts:{RESET}\n")
        for idx, product in enumerate(results.products):
            desc = product.description.get("product_description", "No short description") \
                   if isinstance(product.description, dict) else str(product.description)
            print(f"{idx + 1}. {product.manufacturer_product_number} - {desc}")

        if len(results.products) == 1:
            selected = results.products[0]
        else:
            while True:
                try:
                    choice = int(input(f"\n{BOLD}Enter the number of the part you want to inspect: {RESET}")) - 1
                    if 0 <= choice < len(results.products):
                        selected = results.products[choice]
                        break
                    else:
                        print(f"{YELLOW}⚠️ Invalid selection. Try again.{RESET}")
                except ValueError:
                    print(f"{YELLOW}⚠️ Please enter a number.{RESET}")

        display_part_info(selected)

    except Exception as e:
        logging.error(f"Error in search_and_select_part: {e}")
        print(f"{RED}⚠️ Error: {e}{RESET}")

def display_part_info(product):
    manufacturer = product.manufacturer.get("name", "N/A") if isinstance(product.manufacturer, dict) else str(product.manufacturer)

    if isinstance(product.description, dict):
        detailed_desc = product.description.get("detailed_description", "N/A")
        short_desc = product.description.get("product_description", "N/A")
    else:
        detailed_desc = short_desc = str(product.description)

    category = getattr(product.category, "name", "N/A")
    family = getattr(getattr(product, "family", None), "name", "N/A")
    quantity = getattr(product, "quantity_available", 0)
    availability = f"{GREEN}✅ In Stock{RESET}" if quantity > 0 else f"{RED}❌ Out of Stock{RESET}"

    try:
        pricing_info = [f"{p.break_quantity}+: ${p.unit_price}" for p in getattr(product, "standard_pricing", [])]
        pricing_str = pricing_info if pricing_info else ["Not available"]
    except Exception:
        pricing_str = ["Not available"]

    part_number = getattr(product, "digi_key_part_number", None) or product.manufacturer_product_number
    product_url = f"https://www.digikey.ie/en/products/detail/{part_number}"

    print(f"\n{CYAN}{BOLD}📦 Product Information:{RESET}")
    print(f"{BOLD}Status:              {RESET}{availability}")
    print(f"{BOLD}Manufacturer:        {RESET}{manufacturer}")
    print(f"{BOLD}Part Number:         {RESET}{product.manufacturer_product_number}")
    print(f"{BOLD}Short Description:   {RESET}{short_desc}")
    print(f"{BOLD}Detailed Description:{RESET}{detailed_desc}")
    print(f"{BOLD}Category:            {RESET}{category}")
    print(f"{BOLD}Family:              {RESET}{family}")
    print(f"{BOLD}Quantity Available:  {RESET}{quantity}")
    print(f"{BOLD}Standard Pricing:    {RESET}{pricing_str}")
    print(f"{BOLD}Datasheet:           {RESET}{product.datasheet_url}")
    print(f"{BOLD}DigiKey Page:        {RESET}{product_url}\n")

    searched_parts.append({
        "Manufacturer": manufacturer,
        "Part Number": product.manufacturer_product_number,
        "Short Description": short_desc,
        "Detailed Description": detailed_desc,
        "Category": category,
        "Family": family,
        "Quantity Available": quantity,
        "Availability": "In Stock" if quantity > 0 else "Out of Stock",
        "Pricing": " | ".join(pricing_str),
        "Datasheet": product.datasheet_url,
        "DigiKey URL": product_url
    })

    export_menu()

def export_menu():
    print(f"{BOLD}\n📤 Export Options:{RESET}")
    print("1. Export this component")
    print("2. Export all searched components")
    print("3. Skip export")

    choice = input(f"{BOLD}Enter your choice (1/2/3): {RESET}")
    if choice not in ['1', '2']:
        return

    filename = input(f"{BOLD}📁 Enter filename (without extension, leave blank for timestamp): {RESET}").strip()
    if not filename:
        filename = f"digikey_export_{datetime.now().strftime('%Y%m%d_%H%M%S')}"

    filetype = input(f"{BOLD}📄 Save as CSV or XLSX? (csv/xlsx): {RESET}").strip().lower()
    if filetype not in ['csv', 'xlsx']:
        filetype = 'csv'

    full_filename = f"{filename}.{filetype}"
    export_data = [searched_parts[-1]] if choice == '1' else searched_parts

    try:
        df = pd.DataFrame(export_data)
        df = df.sort_values(by=["Quantity Available"], ascending=False)

        # Analytics Summary only (removed export preview)
        print(f"\n{CYAN}{BOLD}📈 Analytics Summary:{RESET}")
        print(f"{BOLD}Average Quantity: {RESET}{df['Quantity Available'].mean():.2f}")
        print(f"{BOLD}Parts per Manufacturer:{RESET}\n{df['Manufacturer'].value_counts().to_string()}\n")

        if filetype == 'xlsx':
            df.to_excel(full_filename, index=False)
        else:
            with open(full_filename, "w", newline="", encoding="utf-8") as csvfile:
                writer = csv.DictWriter(csvfile, fieldnames=export_data[0].keys())
                writer.writeheader()
                writer.writerows(export_data)

        print(f"{GREEN}✔️ Exported to {full_filename}{RESET}\n")
    except Exception as e:
        logging.error(f"Export failed: {e}")
        print(f"{RED}❌ Export failed. Check errors.log for details.{RESET}")

if __name__ == "__main__":
    print(f"{BOLD}{CYAN}🔧 DigiKey Component Lookup Tool{RESET}")
    while True:
        user_input = input(f"\n{BOLD}Enter part name or number (or 'q' to quit): {RESET}").strip()
        if user_input.lower() == 'q':
            print(f"\n{YELLOW}👋 Goodbye!{RESET}")
            break
        search_and_select_part(user_input)
