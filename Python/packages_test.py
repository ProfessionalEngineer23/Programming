import mymath

# From basic.py
print("Basic module:")
print("Add:", mymath.basic.add(3, 4))
print("Double:", mymath.basic.double(5))
print("Square:", mymath.basic.square(6))

# From stats.py
print("\nStats module:")
print("Mean:", mymath.stats.mean([3, 4, 5, 6]))
print("Median:", mymath.stats.median([3, 4, 5, 6]))

# From geometry.py
print("\nGeometry module:")
print("Area of rectangle (2x4):", mymath.geometry.area_of_rectangle(2, 4))
print("Area of circle (r=5):", mymath.geometry.area_of_circle(5))

# Outputs: 
# Basic module:
# Add: 7
# Double: 10
# Square: 36

# Stats module:
# Mean: 4.5
# Median: 4.5

# Geometry module:
# Area of rectangle (2x4): 8
# Area of circle (r=5): 78.5
