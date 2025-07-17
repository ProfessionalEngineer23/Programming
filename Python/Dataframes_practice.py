import pandas as pd
#Create a dataframe
a = {
    "Student": ["David","Samuel","Terry","Evan"],
    "Age": ["27","24","22","32"],
    "Country": ["UK","Canada","China","USA"],
    "Course": ["Python","Data Structures","Machine Learning","Web Development"],
    "Marks" : ["85","72","89","76"]
}

df1 = pd.DataFrame(a)
print("\n", df1)

#Retrieve the Country and Course columns and assign it to a variable c

b = df1[["Marks"]]
print("\n", b)

c = df1[["Country","Course"]]
print("\n", c)

x = df1['Student']
print("\n", x, "\n\n","Type of x (Column Student): ",type(x))