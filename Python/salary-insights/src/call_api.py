# call_api.py
import requests

def get_country_data():
    url = "https://restcountries.com/v3.1/all"
    response = requests.get(url)
    if response.status_code == 200:
        return response.json()
    else:
        print("Error fetching country data")
        return []

if __name__ == "__main__":
    data = get_country_data()
    print(f"Fetched {len(data)} countries")
