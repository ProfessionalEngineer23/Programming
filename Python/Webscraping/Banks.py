# The Pandas library in Python contains a function read_html() that can be used to extract tabular information from any web page.
# I want to Extract the list of the largest banks in the world by market capitalization:

import pandas as pd

URL = 'https://en.wikipedia.org/wiki/List_of_largest_banks'

# Extract tables of the URL in a dataframe
tables = pd.read_html(URL)
df = tables[0]
print("\nList of the largest banks:\n\n", df)

#######################################################################################################################################

# Web pages may contain elements such as hyperlink text and other denoters, which are also scraped directly using the pandas method. 
# This may lead to a requirement of further cleaning of data.

#######################################################################################################################################

# Here I extract a list of countries by their nominal GDP

URL1 = 'https://en.wikipedia.org/wiki/List_of_countries_by_GDP_(nominal)'

tables = pd.read_html(URL1)
df1 = tables[2] # the required table will have index 2 seen from webpage
print("\nGDP by country:\n\n", df1)

#######################################################################################################################################
# Output: 
# PS C:\Users\nikit\Documents\GitHub\Programming\Python\Webscraping> python .\Banks.py
# 
# List of the largest banks:
# 
#      Rank                                Bank name  Total assets (2024) (US$ billion)
# 0      1  Industrial and Commercial Bank of China                            6303.44
# 1      2               Agricultural Bank of China                            5623.12
# 2      3                  China Construction Bank                            5400.28
# 3      4                            Bank of China                            4578.28
# 4      5                           JPMorgan Chase                            4002.81
# ..   ...                                      ...                                ...
# 95    96                            Handelsbanken                             351.79
# 96    97                 Industrial Bank of Korea                             345.81
# 97    98                                      DNB                             339.21
# 98    99                      Qatar National Bank                             338.14
# 99   100                  National Bank of Canada                             337.65
# 
# [100 rows x 3 columns]
# 
# GDP by country:
# 
#      Country/Territory IMF[1][12]            World Bank[13]            United Nations[14]
#     Country/Territory   Forecast       Year       Estimate       Year           Estimate       Year
# 0               World  113795678       2025      111326370       2024          100834796       2022
# 1       United States   30507217       2025       29184890       2024           27720700       2023
# 2               China   19231705  [n 1]2025       18743803  [n 3]2024           17794782  [n 1]2023
# 3             Germany    4744804       2025        4659929       2024            4525704       2023
# 4               India    4187017       2025        3912686       2024            3575778       2023
# ..                ...        ...        ...            ...        ...                ...        ...
# 217          Kiribati        312       2025            308       2024                289       2023
# 218  Marshall Islands        297       2025            280       2024                270       2023
# 219             Nauru        169       2025            160       2024                176       2023
# 220        Montserrat          —          —              —          —                 80       2023
# 221            Tuvalu         65       2025             62       2023                 68       2023
# 
# [222 rows x 7 columns]
# PS C:\Users\nikit\Documents\GitHub\Programming\Python\Webscraping> 
#######################################################################################################################################
