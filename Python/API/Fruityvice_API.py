# Fruityvice website: https://www.fruityvice.com/

import pandas as pd
import requests
import json

#  obtain the fruityvice API data using requests.get("url") function. 
# The data is in a json format.
data = requests.get("https://web.archive.org/web/20240929211114/https://fruityvice.com/api/fruit/all")

# Retrieve results using json.loads() function.
results = json.loads(data.text)

# Convert our json data into pandas data frame.
pd.DataFrame(results)

# The result is in a nested json format. 
# The 'nutrition' column contains multiple subcolumns, 
# so the data needs to be 'flattened' or normalized.

df2 = pd.json_normalize(results)

print("\n", df2)

# Extracting data about the cherry from dataframe
cherry = df2.loc[df2["name"] == 'Cherry']
print("\nCherry family:", (cherry.iloc[0]['family']) , "\nCherry genus: ", (cherry.iloc[0]['genus']))

# Extracting data about the papaya from dataframe
papaya = df2.loc[df2["name"] == 'Papaya']
print("\nPapaya family: ", (cherry.iloc[0]['family']) , "\nPapaya genus: ", (papaya.iloc[0]['genus']))

# Extracting how many calories are contained in a banana
cal_banana = df2.loc[df2["name"] == 'Banana']
print("\nBanana calories: ", cal_banana.iloc[0]['nutritions.calories'])
