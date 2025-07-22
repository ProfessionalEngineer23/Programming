# List of public APIs: https://mixedanalytics.com/blog/list-actually-free-open-no-auth-needed-apis/

import pandas as pd
import requests
import json

# Api I will use: https://official-joke-api.appspot.com/jokes/ten

# Loading the data from the URL
data = requests.get("https://official-joke-api.appspot.com/jokes/ten")

# Retrieving the results using the json.loads function
results = json.loads(data.text)

# Convert json data into pandas data frame
df1 = pd.DataFrame(results)

# Drop the type and id columns
df1.drop(columns=["type","id"], inplace=True)

print("\n", df1)

