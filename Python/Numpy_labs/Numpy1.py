#What is Numpy?
# NumPy is a Python library used for working with arrays, linear algebra, fourier transform, and matrices. NumPy stands for Numerical Python and it is an open source project. 
# The array object in NumPy is called ndarray, it provides a lot of supporting functions that make working with ndarray very easy.
# Arrays are very frequently used in data science, where speed and resources are very important.
# NumPy is usually imported under the np alias.
# It's usually fixed in size and each element is of the same type. We can cast a list to a numpy array by first importing numpy:

# import numpy library
from matplotlib import pyplot as plt
import numpy as np 

# Create a numpy array
a = np.array([0, 1, 2, 3, 4])
print("\n",a)

# Print each element
print("\na[0]:", a[0])
print("\na[1]:", a[1])
print("\na[2]:", a[2])
print("\na[3]:", a[3])
print("\na[4]:", a[4])

# Print numpy version 
print("\n", np.__version__)

# Check the type of the array
print("\n", type(a))

# Check the type of the values stored in numpy array
print("\n", a.dtype)

# Change the first element to 100
a[0] = 100
print("\n", a[0])

# Change the 5th element to 0
a[4] = 0
print("\n", a[4])

# Slicing
# Set the fourth element and fifth element to 300 and 400 
a[3:5] = 300, 400
print("\n", a)

# We can also define the steps in slicing, like this: [start:end:step].
arr = np.array([1, 2, 3, 4, 5, 6, 7, 8])
print("\n\n", arr[1:5:2])

# If we don't pass start its considered 0
print("\n", arr[:4])

# If we don't pass end it considers till the length of array.
print("\n", arr[4:])

# If we don't pass step its considered 1
print("\n", arr[1:5:])

# Print the even elements in the given array.
print("\n", arr[1:8:2])

# Similarly, we can use a list to select more than one specific index. 
# The list select contains several values:

# Create the index list
select = [0, 2, 3, 4]
print("\n", select)

# We can use the list as an argument in the brackets. 
# The output is the elements corresponding to the particular indexes:

# Use List to select elements
d = a[select]
print("\n", d)


# Assign the specified elements to new value
a[select] = 100000
print("\n", a)

# Get the size of numpy array
print("\n", a.size)

# The next two attributes will make more sense when we get to higher dimensions but let's review them. 
# The attribute ndim represents the number of array dimensions, or the rank of the array. 
# In this case, one:

# Get the number of dimensions of numpy array
print("\n", a.ndim)

# The attribute shape is a tuple of integers indicating the size of the array in each dimension:

# Get the shape/size of numpy array
print("\n", a.shape)

# Create a numpy array u
u = np.array([1, -1, 1, -1])

# Get the mean of numpy array
mean = a.mean()
print("\n", mean)

# Get the standard deviation of numpy array
standard_deviation=a.std()
print("\n", standard_deviation)

# Create a numpy array
y = np.array([-1, 2, 3, 4, 5])
print("\n", y)

# Get the biggest value in the numpy array
max_y = y.max()
print("\n", max_y)

# Get the smallest value in the numpy array
min_y = y.min()
print("\n", min_y)

# Sum of arrays:
Sum = (a + y)
print("\n", Sum)

# Numpy Array Operations:

u = np.array([1, 0])
print("\n", u)

v = np.array([0, 1])
print("\n", v)

# Numpy Array Addition
z = np.add(u, v)
print("\n", z)

# Array Subtraction
s = np.subtract(u, v)
print("\n", s)

# Array Multiplication
m = np.multiply(u, v)
print("\n" ,m)

# Array Division
t = np.array([1, 2])
t1 = np.array([1, 4])
d = np.divide(t, t1)
print("\n", d)

# Dot Product

# If the vectors are perpendicular. As a result, the dot product is zero. 

p = np.dot(u, v)
print("\n", p)

# Adding Constant to a Numpy Array
j = np.array([1, 2, 3, -1])
arr1 = j + 1 
print("\n", arr1)

# Mathematical Functions

# The value of pi
print("\n", np.pi)

# Create the numpy array in radians
r = np.array([0, np.pi/2 , np.pi])
print("\n", r)

# Calculate the sin of each elements
r1 = np.sin(r)
print("\n", r1)

# Linspace
# A useful function for plotting mathematical functions is linspace. Linspace returns evenly spaced numbers over a specified interval.
# numpy.linspace(start, stop, num = int value)
# start : start of interval range
# stop : end of interval range
# num : Number of samples to generate.

# Makeup a numpy array within [-2, 2] and 5 elements
l = np.linspace(-2, 2, num=5)
print("\n", l)

# If we change the parameter num to 9, we get 9 evenly spaced numbers over the interval from -2 to 2:
l1 = np.linspace(-2, 2, num=9)
print("\n", l1)

# Make a numpy array within [0, 2π] and 100 elements 
h = np.linspace(0, 2*np.pi, num=100)
print("\n", h)
h1 = np.linspace(0, 2*np.pi, num=100)
print("\n", h1)

# Calculate the sine of h list
h2 = np.sin(h)

# Plot the result
plt.plot(h1, h2)

# Iterating 1-D Arrays
# Iterating means going through elements one by one.

arr1 = np.array([1, 2, 3])
print("\n", arr1)

# But if you want to result in the form of the list, then you can use for loop:
for x in arr1:
  print("\n", x)

# Convert the list [1, 2, 3, 4, 5] and [6, 7, 8, 9, 10] to numpy arrays arr1 and arr2. 
# Then find the even and odd numbers from arr1 and arr2.

arr11 = np.array([1, 2, 3, 4, 5])
arr22 = np.array([6, 7, 8, 9, 10])

#Starting index in slice is 1 as first even element(2) in array1 is at index 1
even_arr11 = arr11[1:5:2]
print("\neven for array1",even_arr11)
    
#Starting index in slice is 0 as first odd element(1) in array1 is at index 0
odd_arr11=arr11[0:5:2]
print("\nodd for array1",odd_arr11)

#Starting index in slice is 0 as first even element(6) in array2 is at index 0
even_arr22 = arr22[0:5:2]
print("\neven for array2",even_arr22)
    
    
#Starting index in slice is 1 as first odd element(7) in array2 is at index 1
odd_arr22=arr22[1:5:2]
print("\nodd for array2",odd_arr22)

# Reshaping
a = np.array([1, 2, 3, 4, 5, 6])
b = a.reshape(2, 3)

print("\n", b, "\nShape: ", d.shape)

# Output:
# [[1 2 3]
#  [4 5 6]]




