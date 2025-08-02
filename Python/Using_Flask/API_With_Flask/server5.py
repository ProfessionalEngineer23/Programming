# Add dynamic URLs:

# An important part of back-end programming is creating APIs. 
# An API is a contract between a provider and a user. 
# It is common to create RESTful APIs that can be called by the front end or other clients. 
# In a REST based API, the resource information is sent as part of the request URL. For example, with your resource or persons, 
# the client can send the following request:

# GET http://localhost/person/unique_identifier
# DELETE http://localhost/person/unique_identifier

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

@app.route("/count")
def count():
    try:
        # Attempt to return the count of items in 'data' as a JSON response
        return {"data count": len(data)}, 200
    except NameError:
        # Handle the case where 'data' is not defined
        # Return a JSON response with a message and a 500 Internal Server Error status code
        return {"message": "data not defined"}, 500

@app.route("/person/<uuid:id>")
def find_by_uuid(id):
    # Iterate through the 'data' list to search for a person with a matching ID
    for person in data:
        # Check if the 'id' field of the person matches the 'id' parameter
        if person["id"] == str(id):
            # Return the matching person as a JSON response with a 200 OK status code
            return person
    # If no matching person is found, return a JSON response with a message and a 404 Not Found status code
    return {"message": "person not found"}, 404

@app.route("/person/<uuid:id>", methods=['DELETE'])
def delete_by_uuid(id):
    # Iterate through the 'data' list to search for a person with a matching ID
    for person in data:
        # Check if the 'id' field of the person matches the 'id' parameter
        if person["id"] == str(id):
            # Remove the person from the 'data' list
            data.remove(person)
            # Return a JSON response with a message confirming deletion and a 200 OK status code
            return {"message": f"Person with ID {id} deleted"}, 200
    # If no matching person is found, return a JSON response with a message and a 404 Not Found status code
    return {"message": "person not found"}, 404

# Ran:
# curl.exe -X GET -i -w '\n' "localhost:5000/count"
# curl.exe -X GET -i localhost:5000/person/66c09925-589a-43b6-9a5d-d1601cf53287
# curl.exe -X GET -i localhost:5000/person/not-a-valid-uuid
# curl.exe -X GET -i localhost:5000/person/11111111-589a-43b6-9a5d-d1601cf51111
# curl.exe -X DELETE -i localhost:5000/person/66c09925-589a-43b6-9a5d-d1601cf53287
# curl.exe -X GET -i localhost:5000/count
# curl.exe -X DELETE -i localhost:5000/person/not-a-valid-uuid
# curl.exe -X DELETE -i localhost:5000/person/11111111-589a-43b6-9a5d-d1601cf51111

# Outputs: 

# --- Test 1: GET /count ---
# Command:
# curl.exe -X GET -i -w '\n' "localhost:5000/count"

# Response:
# HTTP/1.1 200 OK
# Content-Type: application/json
# {
#   "data count": 5
# }

# --- Test 2: GET /person/<valid_uuid> ---
# Command:
# curl.exe -X GET -i localhost:5000/person/66c09925-589a-43b6-9a5d-d1601cf53287

# Response:
# HTTP/1.1 200 OK
# Content-Type: application/json
# {
#   "address": "637 Carey Pass",
#   "avatar": "http://dummyimage.com/174x100.png/ff4444/ffffff",
#   "city": "Gainesville",
#   "country": "United States",
#   "first_name": "Lilla",
#   "graduation_year": 1985,
#   "id": "66c09925-589a-43b6-9a5d-d1601cf53287",
#   "last_name": "Aupol",
#   "zip": "32627"
# }

# --- Test 3: GET /person/<invalid_uuid_format> ---
# Command:
# curl.exe -X GET -i localhost:5000/person/not-a-valid-uuid

# Response:
# HTTP/1.1 404 NOT FOUND
# Content-Type: text/html
# <html><title>404 Not Found</title><h1>Not Found</h1>...</html>

# --- Test 4: GET /person/<nonexistent_valid_uuid> ---
# Command:
# curl.exe -X GET -i localhost:5000/person/11111111-589a-43b6-9a5d-d1601cf51111

# Response:
# HTTP/1.1 404 NOT FOUND
# Content-Type: application/json
# {
#   "message": "person not found"
# }

# --- Test 5: DELETE /person/<valid_uuid> ---
# Command:
# curl.exe -X DELETE -i localhost:5000/person/66c09925-589a-43b6-9a5d-d1601cf53287

# Response:
# HTTP/1.1 200 OK
# Content-Type: application/json
# {
#   "message": "Person with ID 66c09925-589a-43b6-9a5d-d1601cf53287 deleted"
# }

# --- Test 6: GET /count (after deletion) ---
# Command:
# curl.exe -X GET -i localhost:5000/count

# Response:
# HTTP/1.1 200 OK
# {
#   "data count": 4
# }

# --- Test 7: DELETE /person/<invalid_uuid_format> ---
# Command:
# curl.exe -X DELETE -i localhost:5000/person/not-a-valid-uuid

# Response:
# HTTP/1.1 404 NOT FOUND
# Content-Type: text/html
# <html><title>404 Not Found</title><h1>Not Found</h1>...</html>

# --- Test 8: DELETE /person/<nonexistent_valid_uuid> ---
# Command:
# curl.exe -X DELETE -i localhost:5000/person/11111111-589a-43b6-9a5d-d1601cf51111

# Response:
# HTTP/1.1 404 NOT FOUND
# Content-Type: application/json
# {
#   "message": "person not found"
# }


