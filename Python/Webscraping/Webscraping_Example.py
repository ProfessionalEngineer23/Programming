# Beautiful Soup Objects:
# Beautiful Soup is a Python library for pulling data out of HTML and XML files.
# This is accomplished by representing the HTML as a set of objects with methods used to parse the HTML.
# We can navigate the HTML as a tree, and/or filter out what we are looking for.

# Beutiful soup documentation: https://www.crummy.com/software/BeautifulSoup/bs4/doc/

from bs4 import BeautifulSoup # this module helps in web scrapping.
import requests  # this module helps us to download a web page

# Consider the following HTML:
# %%html # For Jupiter Notebook
# <!DOCTYPE html>
# <html>
# <head>
# <title>Page Title</title>
# </head>
# <body>
# <h3><b id='boldest'>Lebron James</b></h3>
# <p> Salary: $ 92,000,000 </p>
# <h3> Stephen Curry</h3>
# <p> Salary: $85,000, 000 </p>
# <h3> Kevin Durant </h3>
# <p> Salary: $73,200, 000</p>
# </body>
# </html>

# We can store it as a string in the variable HTML:
html="<!DOCTYPE html><html><head><title>Page Title</title></head><body><h3><b id='boldest'>Lebron James</b></h3><p> Salary: $ 92,000,000 </p><h3> Stephen Curry</h3><p> Salary: $85,000, 000 </p><h3> Kevin Durant </h3><p> Salary: $73,200, 000</p></body></html>"

# To parse a document, pass it into the BeautifulSoup constructor. 
# The BeautifulSoup object represents the document as a nested data structure:
soup = BeautifulSoup(html, 'html.parser')

# First, the document is converted to Unicode (similar to ASCII) and HTML entities are converted to Unicode characters. 
# Beautiful Soup transforms a complex HTML document into a complex tree of Python objects. 
# The BeautifulSoup object can create other types of objects.

# Use the method prettify() to display the HTML in the nested structure:
print(soup.prettify())

# Extract the title of the page and the name of the top player 
tag_object=soup.title
print("\ntag object:",tag_object)

# See the tag type bs4.element.Tag:
print("tag object type:",type(tag_object))

# If there is more than one Tag with the same name, 
# the first element with that Tag name is called. 
# This corresponds to the most paid player:
tag_object=soup.h3
print("\n", tag_object)

# Enclosed in the bold attribute b, it helps to use the tree representation. 
# We can navigate down the tree using the child attribute to get the name.

# Children, Parents, and Siblings:

# We can access the child of the tag or navigate down the branch as follows:
tag_child =tag_object.b
print("\n", tag_child)

# This is identical to:
print("\n", tag_object)

# tag_object parent is the body element.
print("\n", tag_object.parent)

# tag_object sibling is the paragraph element
sibling_1=tag_object.next_sibling
print("\ntag_object: ", sibling_1)

sibling_2=sibling_1.next_sibling
print("\nNext sibling: ", sibling_2)

# Use the object sibling_2 and the method next_sibling to find the salary of Stephen Curry:
print("\n", sibling_2.next_sibling)

# HTML Attributes:
# If the tag has attributes, the tag id="boldest" has an attribute id whose value is boldest. 
# You can access a tag’s attributes by treating the tag like a dictionary:

print("\n", tag_child['id'])

# You can access that dictionary directly as attrs:
print("\n", tag_child.attrs)

# You can also work with Multi-valued attributes.
# We can also obtain the content of the attribute of the tag using the Python get() method.

# You can also work with Multi-valued attributes. Check out Beautiful soup documentation for more.

# We can also obtain the content of the attribute of the tag using the Python get() method.
print("\n", tag_child.get('id'))

# Navigable String:

# A string corresponds to a bit of text or content within a tag. 
# Beautiful Soup uses the NavigableString class to contain this text. 
# In our HTML we can obtain the name of the first player by extracting the string of the Tag object tag_child as follows:
tag_string=tag_child.string
print("\n", tag_string)

# We can verify the type is Navigable String:
print("\n", type(tag_string))

# A NavigableString is similar to a Python string or Unicode string. 
# To be more precise, the main difference is that it also supports some BeautifulSoup features. 
# We can convert it to string object in Python:
unicode_string = str(tag_string)
print("\n", unicode_string)

# Filters:

# Filters allow you to find complex patterns, the simplest filter is a string. 
# In this section we will pass a string to a different filter method and 
# Beautiful Soup will perform a match against that exact string. Consider the following HTML of rocket launches:

# %%html
# <table>
#  <tr>
#    <td id='flight' >Flight No</td>
#    <td>Launch site</td> 
#    <td>Payload mass</td>
#   </tr>
#  <tr> 
#    <td>1</td>
#    <td><a href='https://en.wikipedia.org/wiki/Florida'>Florida</a></td>
#    <td>300 kg</td>
#  </tr>
#  <tr>
#    <td>2</td>
#    <td><a href='https://en.wikipedia.org/wiki/Texas'>Texas</a></td>
#    <td>94 kg</td>
#  </tr>
#  <tr>
#    <td>3</td>
#    <td><a href='https://en.wikipedia.org/wiki/Florida'>Florida<a> </td>
#    <td>80 kg</td>
#  </tr>
#</table>

# We can store it as a string in the variable table:
table="<table><tr><td id='flight'>Flight No</td><td>Launch site</td> <td>Payload mass</td></tr><tr> <td>1</td><td><a href='https://en.wikipedia.org/wiki/Florida'>Florida<a></td><td>300 kg</td></tr><tr><td>2</td><td><a href='https://en.wikipedia.org/wiki/Texas'>Texas</a></td><td>94 kg</td></tr><tr><td>3</td><td><a href='https://en.wikipedia.org/wiki/Florida'>Florida<a> </td><td>80 kg</td></tr></table>"

table_bs = BeautifulSoup(table, 'html.parser')
print("\n", table_bs)

# find All:

# The find_all() method looks through a tag’s descendants and retrieves all descendants that match your filters.
# The Method signature for find_all(name, attrs, recursive, string, limit, **kwargs)

# Name: 

# When we set the name parameter to a tag name, the method will extract all the tags with that name and its children.

table_rows=table_bs.find_all('tr')
print("\n", table_rows)

# The result is a Python Iterable just like a list, each element is a tag object:

first_row =table_rows[0]
print("\n", first_row)

# The type is tag
print("\n", type(first_row))

# We can obtain the child:
print("\n", first_row.td)

# If we iterate through the list, each element corresponds to a row in the table:
for i,row in enumerate(table_rows):
    print("row",i,"is",row)

# As row is a cell object, we can apply the method find_all to it and extract table cells in the object cells using the tag td, 
# this is all the children with the name td. 
# The result is a list, each element corresponds to a cell and is a Tag object, we can iterate through this list as well. 
# We can extract the content using the string attribute.

for i,row in enumerate(table_rows):
    print("row",i)
    cells=row.find_all('td')
    for j,cell in enumerate(cells):
        print('colunm',j,"cell",cell)

# If we use a list we can match against any item in that list.

list_input=table_bs .find_all(name=["tr", "td"])
print("\n", list_input)

# Attributes:

# If the argument is not recognized it will be turned into a filter on the tag’s attributes. 
# For example with the id argument, Beautiful Soup will filter against each tag’s id attribute. 
# For example, the first td elements have a value of id of flight, therefore we can filter based on that id value.
print("\n", table_bs.find_all(id="flight"))

# We can find all the elements that have links to the Florida Wikipedia page:
list_input=table_bs.find_all(href="https://en.wikipedia.org/wiki/Florida")
print("\n", list_input)

# If we set the href attribute to True, regardless of what the value is, the code finds all tags with href value:
print("\n", table_bs.find_all(href=True))

# There are other methods for dealing with attributes and other related methods. Check out the following: https://www.crummy.com/software/BeautifulSoup/bs4/doc/#css-selectors

# Finding the elements without a href value:
print("\n", table_bs.find_all(href=False))

# Finding the element with the id attribute content set to "boldest" using the soup object soup:
print("\n", soup.find_all(id="boldest"))

# string:
# With string you can search for strings instead of tags, where we find all the elments with Florida:
print("\n", table_bs.find_all(string="Florida"))

# find:
# The find_all() method scans the entire document looking for results. 
# It’s useful if you are looking for one element, as you can use the find() method to find the first element in the document. 
# Consider the following two tables:

# %%html
# <h3>Rocket Launch </h3>

# <p>
# <table class='rocket'>
#  <tr>
#    <td>Flight No</td>
#    <td>Launch site</td> 
#    <td>Payload mass</td>
#  </tr>
#  <tr>
#    <td>1</td>
#    <td>Florida</td>
#    <td>300 kg</td>
#  </tr>
#  <tr>
#    <td>2</td>
#    <td>Texas</td>
#    <td>94 kg</td>
#  </tr>
#  <tr>
#    <td>3</td>
#    <td>Florida </td>
#    <td>80 kg</td>
#  </tr>
# </table>
# </p>
# <p>

# <h3>Pizza Party  </h3>
# <table class='pizza'>
#  <tr>
#    <td>Pizza Place</td>
#    <td>Orders</td> 
#    <td>Slices </td>
#   </tr>
#  <tr>
#    <td>Domino's Pizza</td>
#    <td>10</td>
#    <td>100</td>
#  </tr>
#  <tr>
#    <td>Little Caesars</td>
#    <td>12</td>
#    <td >144 </td>
#  </tr>
#  <tr>
#    <td>Papa John's </td>
#    <td>15 </td>
#    <td>165</td>
#  </tr>

# We store the HTML as a Python string and assign two_tables:
two_tables="<h3>Rocket Launch </h3><p><table class='rocket'><tr><td>Flight No</td><td>Launch site</td> <td>Payload mass</td></tr><tr><td>1</td><td>Florida</td><td>300 kg</td></tr><tr><td>2</td><td>Texas</td><td>94 kg</td></tr><tr><td>3</td><td>Florida </td><td>80 kg</td></tr></table></p><p><h3>Pizza Party  </h3><table class='pizza'><tr><td>Pizza Place</td><td>Orders</td> <td>Slices </td></tr><tr><td>Domino's Pizza</td><td>10</td><td>100</td></tr><tr><td>Little Caesars</td><td>12</td><td >144 </td></tr><tr><td>Papa John's </td><td>15 </td><td>165</td></tr>"

# We create a BeautifulSoup object two_tables_bs:
two_tables_bs= BeautifulSoup(two_tables, 'html.parser')

# We can find the first table using the tag name table:
print("\nTwo Tables Example:\n", two_tables_bs.find("table"))

# We can filter on the class attribute to find the second table, but because class is a keyword in Python, 
# we add an underscore to differentiate them.
print("\n", two_tables_bs.find("table",class_='pizza'))

###############################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################################

# Source: IBM