# Create a 2D Numpy Array:

# Import the libraries
import numpy as np

# Create a list
a = [[11, 12, 13], [21, 22, 23], [31, 32, 33]]
print("\n", a)

# Convert list to Numpy Array
# Every element is the same type
A = np.array(a)
print("\n", A)

# Show the numpy array dimensions
print("\n", A.ndim)

# Show the numpy array shape
print("\n", A.shape)

# Show the numpy array size
print("\n", A.size)

# Accessing different elements of a Numpy Array:

# Access the element on the second row and third column
print("\n", A[1, 2])

# Access the element on the second row and third column
print("\n", A[1][2])

# Access the element on the first row and first column
print("\n", A[0][0])

# Access the element on the first row and first and second columns
print("\n", A[0][0:2])

# Access the element on the first and second rows and third column
print("\n", A[0:2, 2])

# Basic Operations with 2D arrays:

# Create a numpy array X
X = np.array([[1, 0], [0, 1]]) 
print("\n", X)

# Create a numpy array Y
Y = np.array([[2, 1], [1, 2]]) 
print("\n", Y)

# Add X and Y
Z = X + Y
print("\n", Z)

# Create a numpy array Y
Y = np.array([[2, 1], [1, 2]]) 
print("\n", Y)

# Multiply Y with 2
Z = 2 * Y
print("\n", Z)

# Multiplication of two arrays corresponds to an element-wise product or Hadamard product. 
# Consider matrix X and Y. The Hadamard product corresponds to multiplying each of the elements in the same position, 
# i.e. multiplying elements contained in the same color boxes together. 
# The result is a new matrix that is the same size as matrix Y or X

# Create a numpy array Y
Y = np.array([[2, 1], [1, 2]]) 
print("\n", Y)

# Create a numpy array X
X = np.array([[1, 0], [0, 1]]) 
print("\n", X)

# Multiply X with Y
Z = X * Y
print("\n", Z)

# We can also perform matrix multiplication with the numpy arrays A and B as follows:

# Create a matrix A
A = np.array([[0, 1, 1], [1, 0, 1]])
print("\n", A)

# Create a matrix B
B = np.array([[1, 1], [1, 1], [-1, 1]])
print("\n", B)

# Calculate the dot product
Z = np.dot(A,B)
print("\n", Z)

# Calculate the sine of Z
print("\n", np.sin(Z))

# We use the numpy attribute T to calculate the transposed matrix:

# Create a matrix C

C = np.array([[1,1],[2,2],[3,3]])
print("\n", C)

# Get the transposed of C
print("\n", C.T)



