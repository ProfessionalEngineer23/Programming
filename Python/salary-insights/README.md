# This project is a global tech salary insights tracker

This project collects, analyzes, and visualizes remote tech salary data using Python.

## Features:
- Real-time job data via RemoteOK API
- Data cleaning and filtering using Pandas
- Salary trends by category and region
- Visualizations with Seaborn and Matplotlib
- Optional: Add cost-of-living comparisons via REST APIs

## Project Structure:
- `data/` - Raw and cleaned CSVs
- `src/` - Scripts for scraping, API calls, analysis
- `visuals/` - Charts and plots
- `notebook/` - Jupyter notebook for insights
- `README.md` - This file
- `requirements.txt` - Dependencies

## Tools Used:
- Python, Pandas, NumPy, requests, Matplotlib, Seaborn

## To run this program:
```bash
cd src
python scrape_jobs.py
python clean_analyze.py
