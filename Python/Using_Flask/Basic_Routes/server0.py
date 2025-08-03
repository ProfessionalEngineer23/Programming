# Creating Flask apps:

# Create the main route.
# Import the Flask class from the flask module
from flask import Flask

# Create an instance of the Flask class, passing in the name of the current module
app = Flask(__name__)

# Define a route for the root URL ("/")
@app.route("/")
def hello_world():
    # Function that handles requests to the root URL
    return "Hello, World!"

# To activate venv enviornment: 
# C:\Users\nikit\Documents\GitHub\Programming\.venv\Scripts\Activate.ps1

# To Host:
# (.venv) PS C:\Users\nikit\Documents\GitHub\Programming\Python\Using_Flask\lab> flask --app server --debug run
# >>


# Ran command in separate terminal: 
# curl.exe -X GET -i -w '\n' localhost:5000

# Output:
# (.venv) PS C:\Users\nikit\Documents\GitHub\Programming\Python> curl.exe -X GET -i -w '\n' localhost:5000
# HTTP/1.1 200 OK
# Server: Werkzeug/2.2.3 Python/3.13.4
# Date: Fri, 01 Aug 2025 09:21:57 GMT
# Content-Type: text/html; charset=utf-8
# Content-Length: 13
# Connection: close

# Hello, World!
# (.venv) PS C:\Users\nikit\Documents\GitHub\Programming\Python> 

# Optional:

# If working in the terminal becomes difficult because the command prompt is long, 
# you can shorten the prompt using the following command:
# export PS1="[\[\033[01;32m\]\u\[\033[00m\]: \[\033[01;34m\]\W\[\033[00m\]]\$ "