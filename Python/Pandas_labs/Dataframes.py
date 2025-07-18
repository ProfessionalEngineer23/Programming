#Using Dataframes in Python
#pip insatall pandas in terminal
import pandas as pd

#Define a dictionary 'x'

x = {
    'Name': ['Rose','John', 'Jane', 'Mary'], 
    'ID': [1, 2, 3, 4], ''
    'Department': ['Architect Group', 'Software Group', 'Design Team', 'Infrastructure'], 
    'Salary':[100000, 80000, 50000, 60000]
    }

#casting the dictionary to a DataFrame
df = pd.DataFrame(x)

#display the result df
print(df)


#Retrieving the "ID" column and assigning it to a variable x
x = df[['ID']]
print(f"\n",x)

#check the type of x
print("\n",type(x))

#Retrieving the Department, Salary and ID columns and assigning it to a variable z
z = df[['Department','Salary','ID']]
print("\n",z)

#loc and iloc functions:

# Access the value on the first row and the first column
print("\nRow 0, Column 0 element is:", df.iloc[0, 0])

# Access the value on the first row and the third column
print("\nRow 0, Column 2 element is:", df.iloc[0,2])

# Access the column using the name
print("\nAccess Row 0 and the column using the name Salary:", df.loc[0, 'Salary'])

#create a new dataframe called 'df2' and assign 'df' to it. 
#Now, set the "Name" column as an index column using the method set_index().
df2=df
df2=df2.set_index("Name")

#To display the first 5 rows of new dataframe
print("\nFirst 5 rows of new dataframe:\n\n", df2.head())

#Now, let us access the column using the name
print("\nAccess Row: Jane, Column: Salary\n", df2.loc['Jane', 'Salary'])

#Department of Jane
print("\nDepartment of Jane:\n", df2.loc["Jane", "Department"])

# loc() is a label-based data selecting method
# iloc() is an indexed-based selecting method

# iloc() function to get the Salary of Mary in the newly created dataframe df2.
print("\nSalary of Mary:\n", df2.iloc[3,2])

# let us do the slicing using old dataframe df
print("\nSlicning [0:2, 0:3]:\n", df.iloc[0:2, 0:3])

#let us do the slicing using loc() function on old dataframe df where index column is having labels as 0,1,2
print("\nSlicing [0:2, 'ID':'Department']\n", df.loc[0:2,'ID':'Department'])

#slicing on old dataframe df to retrieve the Name, ID and department of index column having labels as 2,3
print("\nSlicing [2:3,'Name':'Department']\n",df.loc[2:3,"Name":"Department"])