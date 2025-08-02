# Add error handlers:

# This code will add application level global handlers to handle errors like 
# 404 (not found) and 500 (internal server error). 
# Flask makes it easy to handle these global error handlers using the errorhandler() decorator.

# If you  an invalid request is made to the server, Flask will return an HTML page with the 404 error. 
# Something like this:
# curl.exe -X POST -i -w '\n' http://localhost:5000/notvalid

from flask import Flask, make_response, request
app = Flask(__name__)

data = [
    {
        "id": "3b58aade-8415-49dd-88db-8d7bce14932a",
        "first_name": "Tanya",
        "last_name": "Slad",
        "graduation_year": 1996,
        "address": "043 Heath Hill",
        "city": "Dayton",
        "zip": "45426",
        "country": "United States",
        "avatar": "http://dummyimage.com/139x100.png/cc0000/ffffff",
    },
    {
        "id": "d64efd92-ca8e-40da-b234-47e6403eb167",
        "first_name": "Ferdy",
        "last_name": "Garrow",
        "graduation_year": 1970,
        "address": "10 Wayridge Terrace",
        "city": "North Little Rock",
        "zip": "72199",
        "country": "United States",
        "avatar": "http://dummyimage.com/148x100.png/dddddd/000000",
    },
    {
        "id": "66c09925-589a-43b6-9a5d-d1601cf53287",
        "first_name": "Lilla",
        "last_name": "Aupol",
        "graduation_year": 1985,
        "address": "637 Carey Pass",
        "city": "Gainesville",
        "zip": "32627",
        "country": "United States",
        "avatar": "http://dummyimage.com/174x100.png/ff4444/ffffff",
    },
    {
        "id": "0dd63e57-0b5f-44bc-94ae-5c1b4947cb49",
        "first_name": "Abdel",
        "last_name": "Duke",
        "graduation_year": 1995,
        "address": "2 Lake View Point",
        "city": "Shreveport",
        "zip": "71105",
        "country": "United States",
        "avatar": "http://dummyimage.com/145x100.png/dddddd/000000",
    },
    {
        "id": "a3d8adba-4c20-495f-b4c4-f7de8b9cfb15",
        "first_name": "Corby",
        "last_name": "Tettley",
        "graduation_year": 1984,
        "address": "90329 Amoth Drive",
        "city": "Boulder",
        "zip": "80305",
        "country": "United States",
        "avatar": "http://dummyimage.com/198x100.png/cc0000/ffffff",
    }
]

@app.errorhandler(404)
def api_not_found(error):
    # This function is a custom error handler for 404 Not Found errors
    # It is triggered whenever a 404 error occurs within the Flask application
    return {"message": "API not found"}, 404

# A global Error Handler for 500 (internal server error)
@app.errorhandler(Exception)
def handle_exception(e):
    return {"message": str(e)}, 500

# This tells Flask to catch any unhandled Exception raised anywhere in your app and route 
# it to this handler, returning a 500 Internal Server Error response with the error message.

# Deliberately raise an exception to test the global handler. 
# Add the following route before your error handlers:
@app.route("/test500")
def test500():
    raise Exception("Forced exception for testing")

# Ran:

# curl.exe http://localhost:5000/test500

# Outputs: 

# (.venv) PS C:\Users\nikit\Documents\GitHub\Programming\Python\Using_Flask\API_With_Flask> curl.exe http://localhost:5000/test500
# {
#   "message": "Forced exception for testing"
# }
# (.venv) PS C:\Users\nikit\Documents\GitHub\Programming\Python\Using_Flask\API_With_Flask> 