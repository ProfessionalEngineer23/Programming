import requests

import os 
from PIL import Image
from IPython.display import IFrame

# make a GET request via the method get to www.ibm.com:
url='https://www.ibm.com/'
r=requests.get(url)

# We have the response object r, this has information about the request, 
# like the status of the request. 
# We can view the status code using the attribute status_code.
r.status_code

print(r.request.headers)

# You can view the request body, in the following line, 
# as there is no body for a get request we get a None:
print("request body:", r.request.body)

# You can view the HTTP response header using the attribute headers. 
# This returns a python dictionary of HTTP response headers.
header=r.headers
print(r.headers)

# Date the request was sent using the key Date.
header['Date']

# Content-Type indicates the type of data:
header['Content-Type']

# check the encoding:
r.encoding

# As the Content-Type is text/html we can use the attribute text to display the HTML in the body. 
# We can review the first 100 characters:
r.text[0:100]

# You can load other types of data for non-text requests, like images. 
# Consider the URL of the following image:

# Use single quotation marks for defining string
url='https://cf-courses-data.s3.us.cloud-object-storage.appdomain.cloud/IBMDeveloperSkillsNetwork-PY0101EN-SkillsNetwork/IDSNlogo.png'

# make a get request:
r=requests.get(url)

# Look at the response header:
print(r.headers)

# see the 'Content-Type'
r.headers['Content-Type']

# An image is a response object that contains the image as a bytes-like object. 
# As a result, we must save it using a file object. 
# First, we specify the file path and name
path=os.path.join(os.getcwd(),'image.png')

# We save the file, in order to access the body of the response we use the attribute content then save it using the open function and write method:
with open(path,'wb') as f:
    f.write(r.content)

# view the image:
Image.open(path)

################################################################################################################################################################
# Practice:
# Source: https://cf-courses-data.s3.us.cloud-object-storage.appdomain.cloud/IBMDeveloperSkillsNetwork-PY0101EN-SkillsNetwork/labs/Module%205/data/Example1.txt

url = 'https://cf-courses-data.s3.us.cloud-object-storage.appdomain.cloud/IBMDeveloperSkillsNetwork-PY0101EN-SkillsNetwork/labs/Module%205/data/Example1.txt'

path=os.path.join(os.getcwd(),'image.png')

# make a get request:
r=requests.get(url)

with open(path, 'wb') as f:
    f.write(r.content)
################################################################################################################################################################

# Get Request with URL Parameters:
url_get='http://httpbin.org/get'

# create a Query string, add a dictionary. 
# The keys are the parameter names and the values are the value of the Query string.

payload={"name":"Niki","ID":"123"}

# Then passing the dictionary payload to the params parameter of the  get() function:
r=requests.get(url_get,params=payload)

# print out the URL and see the name and values.
print("\n", r.url)

# There is no request body.
print("\n", r.status_code)

# View the response as text:
print("\n", r.text)

print("\n", r.headers['Content-Type'])

# As the content 'Content-Type' is in the JSON format we can use the method json(), 
# it returns a Python dict:
r.json()

# The key args has the name and values:
r.json()['args']



# Post Requests:
url_post='http://httpbin.org/post'

# This endpoint will expect data as a file or as a form. 
# A form is convenient way to configure an HTTP request to send data to a server.

r_post=requests.post(url_post,data=payload)

# Comparing the URL from the response object of the GET and POST request we see the POST request has no name or value pairs.
#print("POST request URL:",response.url )
#print("GET request URL:",r.url)
print("POST request URL:", r_post.url)  # Use r_post instead of response

# compare the POST and GET request body, we see only the POST request has a body:
print("\nPOST request body:",r_post.request.body)
print("\nGET request body:",r.request.body)

# View the form as well:
r_post.json()['form']
