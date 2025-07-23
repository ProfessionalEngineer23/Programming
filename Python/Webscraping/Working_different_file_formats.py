# Data Engineering Process: 
# There are several steps in Data Engineering process.

# 1. Extract - Data extraction is getting data from multiple sources. Ex. Data extraction from a website using Web scraping or gathering information from the data that are stored in different formats(JSON, CSV, XLSX etc.).

# 2. Transform - Transforming the data means removing the data that we don't need for further analysis and converting the data in the format that all the data from the multiple sources is in the same format.

# 3. Load - Loading the data inside a data warehouse. Data warehouse essentially contains large volumes of data that are accessed to gather insights.

##############################################################################################################################################################################################################################################################################################

# Working with different file formats: 
# Now, we will look at some file formats and how to read them in Python:

# Comma-separated values (CSV) file format
#The Comma-separated values file format falls under a spreadsheet file format.

#In a spreadsheet file format, data is stored in cells. Each cell is organized in rows and columns. A column in the spreadsheet file can have different types. For example, a column can be of string type, a date type, or an integer type.

# Each line in CSV file represents an observation, or commonly called a record. Each record may contain one or more fields which are separated by a comma.

# Reading data from CSV in Python
# The Pandas Library is a useful tool that enables us to read various datasets into a Pandas data frame

# Let us look at how to read a CSV file in Pandas Library.

# We use pandas.read_csv() function to read the csv file. In the parentheses, we put the file path along with a quotation mark as an argument, so that pandas will read the file into a data frame from that address. The file path can be either a URL or your local file address.

##############################################################################################################################################################################################################################################################################################

# import libraries
import pandas as pd
import numpy as np
import requests

# Download the CSV file using requests
url = "https://cf-courses-data.s3.us.cloud-object-storage.appdomain.cloud/IBMDeveloperSkillsNetwork-PY0101EN-SkillsNetwork/labs/Module%205/data/addresses.csv"
response = requests.get(url)

# Save the content to a file
with open("addresses.csv", "wb") as f:
    f.write(response.content)

# Read the CSV file
df = pd.read_csv("addresses.csv", header=None)

print("\n", df)

# Adding column name to the DataFrame:
df.columns = ['First Name', 'Last Name', 'Location ', 'City', 'State', 'Area Code']
print("\n", df)

# Selecting a single column:
# To select the first column 'First Name', 
# you can pass the column name as a string to the indexing operator.
print("\n", df["First Name"])

# Selecting multiple columns:
df = df[['First Name', 'Last Name', 'Location ', 'City', 'State', 'Area Code']]
print("\n", df)

# Selecting rows using .iloc and .loc:

# To select the first row
df.loc[0]

# To select the 0th, 1st and 2nd row of "First Name" column only
df.loc[[0, 1, 2], "First Name"]

# iloc() : iloc() is a indexed based selecting method which means that we have to pass integer index in the method to select specific row/column.

# To select the 0th, 1st and 2nd row of "First Name" column only
df.iloc[[0, 1, 2], 0]

# To see more look at Pandas documentation here: https://pandas.pydata.org/pandas-docs/stable/user_guide/indexing.html

# Transform Function in Pandas:

# Python's Transform function returns a self-produced dataframe with transformed values after applying the function specified in its parameter.

# creating a dataframe
df = pd.DataFrame(np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]]), columns=['a', 'b', 'c'])
print("\n", df)

# Let’s say we want to add 10 to each element in a dataframe:

# applying the transform function
df = df.transform(func=lambda x: x + 10)
print("\n", df)

# Now we will use DataFrame.transform() function to find the square root to each element of the dataframe.
result = df.transform(func=['sqrt'])
print("\n", result)

# For more info on transforms view: https://pandas.pydata.org/pandas-docs/stable/reference/api/pandas.DataFrame.transform.html

# JSON file Format:

# To be continued...
