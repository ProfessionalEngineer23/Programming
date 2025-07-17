import pandas as pd

filename = "Product-sales.csv"
df = pd.read_csv(filename)

# Print first five rows of the dataframe
print("\n",df.head(),"\n")

# Access to the column Length
x = df[['Quantity']]
print("\n",x)

# Get the column as a series
x = df['Product']
print("\n", x)

# Get the column as a dataframe
x = df[['Quantity']]
print("\n",type(x))

# Access to multiple columns
y = df[['Product','Category', 'Quantity']]
print("\n", y)

# Access the value on the first row and the first column
print("\nFirst Row, first column:\n", df.iloc[0, 0])

# Access the value on the second row and the first column
print("\nSecond row, first column:\n", df.iloc[1,0])

# Access the value on the first row and the third column
print("\nFirst row, third column\n", df.iloc[0,2])

# Access the value on the second row and the third column
print("\nSecond row, third column\n", df.iloc[1,2])

# Access the column using the name
print("\n", df.loc[0, 'Product'])

# Access the column using the name

print("\n", df.loc[1, 'Product'])

# Access the column using the name
print("\n", df.loc[1, 'CustomerCity'])

# Access the column using the name
print("\n", df.loc[1, 'Total'])

# Slicing the dataframe
print(" \n", df.iloc[0:2, 0:3])

# Slicing the dataframe using name
print("\n", df.loc[0:2, 'OrderID':'Category'])

# variable q to store the column Price as a dataframe
q = df[["Price"]]
print("\n", q)

# variable q to the dataframe that is made up of the column Product and Category:
q = df[["Product","Category"]]
print("\n",q)

# Access the 2nd row and the 3rd column of df:
print("\n", df.iloc[1, 2], "\n\n")

# Use the following list to convert the dataframe index df to characters and assign it to df_new;
new_index=['a','b','c','d','e']
df_new=df
df_new.index=new_index
# find the element corresponding to the row index a and column 'CustomerCity'. 
print("\n", df_new.loc['a', 'CustomerCity'])
# Then select the rows a through d for the column 'CustomerCity'.
print("\n", df_new.loc['a':'d', 'CustomerCity'])
print("\n", df_new)