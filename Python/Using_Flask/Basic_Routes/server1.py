# Return JSON:

# Import the Flask class from the flask module
from flask import Flask

# Create an instance of the Flask class, passing in the name of the current module
app = Flask(__name__)

# Define a route for the root URL ("/")
@app.route("/")
def index():
    # Function that handles requests to the root URL
    # Create a dictionary to return as a response
    return {"message": "Hello World"}

# To Host:
# (.venv) PS C:\Users\nikit\Documents\GitHub\Programming\Python\Using_Flask\lab> flask --app server1 --debug run
# >>


# Ran command in separate terminal: 
# curl.exe -X GET -i -w '\n' localhost:5000

# Output:
# (.venv) PS C:\Users\nikit\Documents\GitHub\Programming\Python\Using_Flask\Basic_Routes> curl.exe -X GET -i -w '\n
# ' localhost:5000
# HTTP/1.1 200 OK
# Server: Werkzeug/2.2.3 Python/3.13.4
# Date: Sat, 02 Aug 2025 08:31:22 GMT
# Content-Type: application/json
# Content-Length: 31
# Connection: close

# {
#   "message": "Hello World"
# }
# (.venv) PS C:\Users\nikit\Documents\GitHub\Programming\Python> 
