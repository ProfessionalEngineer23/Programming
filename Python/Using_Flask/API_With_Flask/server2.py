# Set response status code:

# Import the Flask class and make_repsonse from the flask module
from flask import Flask, make_response

# Create an instance of the Flask class, passing in the name of the current module
app = Flask(__name__)

# Define a route for the root URL ("/")
@app.route("/")
def index():
    # Function that handles requests to the root URL
    # Return a plain text response
    return "hello world"

# Define a route for the "/no_content" URL
@app.route("/no_content")
def no_content():
    """Return 'no content found' with a status of 204.

    Returns:
        tuple: A tuple containing a dictionary and a status code.
    """
    # Create a dictionary with a message and return it with a 204 No Content status code
    return ({"message": "No content found"}, 204)

# Define a route for the "/exp" URL
@app.route("/exp")
def index_explicit():
    """Return 'Hello World' message with a status code of 200.

    Returns:
        response: A response object containing the message and status code 200.
    """
    # Create a response object with the message "Hello World"
    resp = make_response({"message": "Hello World"})
    # Set the status code of the response to 200
    resp.status_code = 200
    # Return the response object
    return resp

# To Host:
# (.venv) PS C:\Users\nikit\Documents\GitHub\Programming\Python\Using_Flask\API_With_Flask> flask --app server2 --debug run
# >>

# Ran command in separate terminal: 
# curl.exe -X GET -i -w '\n' localhost:5000
# curl.exe -X GET -i -w '\n' localhost:5000/no_content
# curl.exe -X GET -i -w '\n' localhost:5000/exp