# Creating a method called name_search with the @app.route decorator. 
# This method should be called when a client requests for the /name_search URL. 
# The method will not accept any parameter, however, will look for the argument q 
# in the incoming request URL. This argument holds the first_name the client is looking for. 

# The method returns:
# Person information with a status of HTTP 200 if the first_name is found in the data
# Message of Invalid input parameter with a status of HTTP 400 if the argument q is missing from the request
# Message of Person not found with a status code of HTTP 404 if the person is not found in the data

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

@app.route("/name_search")
def name_search():
    """Find a person in the database based on the provided query parameter.

    Returns:
        json: Person if found, with status of 200
        404: If not found
        400: If the argument 'q' is missing
        422: If the argument 'q' is present but invalid (e.g., empty or numeric)
    """
    # Get the 'q' query parameter from the request URL
    query = request.args.get("q")

    # Check if the query parameter 'q' is missing
    if query is None:
        return {"message": "Query parameter 'q' is missing"}, 400

    # Check if the query parameter is present but invalid (empty or numeric)
    if query.strip() == "" or query.isdigit():
        return {"message": "Invalid input parameter"}, 422

    # Iterate through the 'data' list to search for a matching person
    for person in data:
        # Check if the query string is present in the person's first name (case-insensitive)
        if query.lower() in person["first_name"].lower():
            # Return the matching person as a JSON response with a 200 OK status code
            return person, 200

 # If no matching person is found, return a JSON response with a message and a 404 Not Found
    return {"message": "Person not found"}, 404

# Ran:
# curl.exe -X GET -i -w '\n' "localhost:5000/name_search?q=123"
# curl -X GET -i -w '\n' "localhost:5000/name_search?q="
# curl -X GET -i -w '\n' "localhost:5000/name_search?q=qwerty"

# Outputs: 
# (.venv) PS C:\Users\nikit\Documents\GitHub\Programming\Python\Using_Flask\API_With_Flask> curl.exe -X GET -i -w '\n' "localhost:5000/name_search?q=123"
# HTTP/1.1 422 UNPROCESSABLE ENTITY
# Server: Werkzeug/2.2.3 Python/3.13.4
# Date: Sat, 02 Aug 2025 08:57:07 GMT
# Content-Type: application/json
# Content-Length: 43
# Connection: close

# {
#   "message": "Invalid input parameter"
# }

# (.venv) PS C:\Users\nikit\Documents\GitHub\Programming\Python\Using_Flask\API_With_Flask> curl.exe -X GET -i -w '\n' "localhost:5000/name_search?q="
# HTTP/1.1 422 UNPROCESSABLE ENTITY
# Server: Werkzeug/2.2.3 Python/3.13.4
# Date: Sat, 02 Aug 2025 08:57:22 GMT
# Content-Type: application/json
# Content-Length: 43
# Connection: close

# {
#   "message": "Invalid input parameter"
# }

# (.venv) PS C:\Users\nikit\Documents\GitHub\Programming\Python\Using_Flask\API_With_Flask> curl.exe -X GET -i -w '\n' "localhost:5000/name_search?q=qwerty"
# HTTP/1.1 404 NOT FOUND
# Server: Werkzeug/2.2.3 Python/3.13.4
# Date: Sat, 02 Aug 2025 08:57:40 GMT
# Content-Type: application/json
# Content-Length: 36
# Connection: close

# {
#  "message": "Person not found"
# }

# (.venv) PS C:\Users\nikit\Documents\GitHub\Programming\Python\Using_Flask\API_With_Flask>