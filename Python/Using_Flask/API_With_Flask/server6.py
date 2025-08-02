# Parse JSON from Request body:

# create another RESTful API. 
# The client can send a POST request to http://localhost:5000/person with the person detail JSON 
# as the body. 
# The server should parse the request for the body and then create a new person with that detail. 
# In your case, to create the person, simply add to the data list.

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

@app.route("/person", methods=['POST'])
def add_by_uuid():
    new_person = request.json
    if not new_person:
        return {"message": "Invalid input parameter"}, 422
    # code to validate new_person ommited
    try:
        data.append(new_person)
    except NameError:
        return {"message": "data not defined"}, 500

    return {"message": f"{new_person['id']}"}, 200

# Ran:

# curl.exe -X POST -i -w '\n' \
#   --url http://localhost:5000/person \
#   --header 'Content-Type: application/json' \
#   --data '{
#         "id": "4e1e61b4-8a27-11ed-a1eb-0242ac120002",
#         "first_name": "John",
#         "last_name": "Horne",
#         "graduation_year": 2001,
#         "address": "1 hill drive",
#         "city": "Atlanta",
#         "zip": "30339",
#         "country": "United States",
#         "avatar": "http://dummyimage.com/139x100.png/cc0000/ffffff"
# }'

# curl -X POST -i -w '\n' \
#   --url http://localhost:5000/person \
#   --header 'Content-Type: application/json' \
#   --data '{}'

# Outputs: 

# Made a file called person.json with the json formatted information about the person to be POSTED

# (.venv) PS C:\Users\nikit\Documents\GitHub\Programming\Python\Using_Flask\API_With_Flask>
# curl.exe -X POST -i -w "`n" `
#   --url http://localhost:5000/person `
#   --header "Content-Type: application/json" `
#   --data "@person.json"

# HTTP/1.1 200 OK
# Server: Werkzeug/2.2.3 Python/3.13.4
# Date: Sat, 02 Aug 2025 22:18:08 GMT
# Content-Type: application/json
# Content-Length: 56
# Connection: close
#
# {
#   "message": "4e1e61b4-8a27-11ed-a1eb-0242ac120002"
# }

# (.venv) PS C:\Users\nikit\Documents\GitHub\Programming\Python\Using_Flask\API_With_Flask>
# curl.exe -X POST -i -w "`n" `
#   --url http://localhost:5000/person `
#   --header "Content-Type: application/json" `
#   --data "{}"

# HTTP/1.1 422 UNPROCESSABLE ENTITY
# Server: Werkzeug/2.2.3 Python/3.13.4
# Date: Sat, 02 Aug 2025 22:19:50 GMT
# Content-Type: application/json
# Content-Length: 43
# Connection: close
#
# {
#   "message": "Invalid input parameter"
# }

# (.venv) PS C:\Users\nikit\Documents\GitHub\Programming\Python\Using_Flask\API_With_Flask>
