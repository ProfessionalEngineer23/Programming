from math import pi

def area_of_rectangle(length,breadth):
    """
    This function returns the area of a rectangle or a square
    """
    return length * breadth

def area_of_circle(radius):
    """
    This function returns the area of a circle
    """
    return pi * (radius ** 2)

# Outputs: 
# PS C:\Users\nikit\Documents\GitHub\Programming\Python> python3
# Python 3.11.9 (tags/v3.11.9:de54cf5, Apr  2 2024, 10:12:12) [MSC v.1938 64 bit (AMD64)] on win32
# Type "help", "copyright", "credits" or "license" for more information.
# >>> import mymath
# >>> mymath.basic.add(3,4)        
# 7
# >>> mymath.stats.mean([3,4,5])
# 4.0
# >>> mymath.geometry.area_of_rectangle(2,4)
# 8
# >>> mymath.geometry.area_of_circle(3)
# 28.274333882308138
# >>> exit()
# PS C:\Users\nikit\Documents\GitHub\Programming\Python> 