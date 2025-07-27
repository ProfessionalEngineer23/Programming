# scrape_jobs.py
import requests
import json
import pandas as pd

def fetch_remoteok_jobs():
    url = "https://remoteok.com/api"
    headers = {'User-Agent': 'Mozilla/5.0'}
    
    response = requests.get(url, headers=headers)
    if response.status_code == 200:
        jobs = response.json()[1:]  # First item is metadata
        df = pd.DataFrame(jobs)
        df.to_csv("../data/remoteok_jobs.csv", index=False)
        print(f"Fetched {len(df)} jobs and saved to data/remoteok_jobs.csv")
    else:
        print(f"Error fetching data: {response.status_code}")

if __name__ == "__main__":
    fetch_remoteok_jobs()