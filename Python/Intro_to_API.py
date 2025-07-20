# An API lets two pieces of software talk to each other. 
# Just like a function, you don't have to know how the API works, only its inputs and outputs. 
# An essential type of API is a REST API that allows you to access resources via the internet. 
# This is a review the Pandas Library in the context of an API. 
# We will also review a basic REST API.

import pandas as pd # Pandas is an API or a set of software components
import matplotlib.pyplot as plt

dict_={'a':[11,21,31],'b':[12,22,32]}

df=pd.DataFrame(dict_)
print("\n", type(df))

# When you create a Pandas object with the dataframe constructor, in API lingo this is an "instance". 
# The data in the dictionary is passed along to the pandas API. 
# You then use the dataframe to communicate with the API.

# When you call the method head the dataframe communicates with the API displaying the first few rows of the dataframe.
print("\n", df.head())

# Get mean of dataframe elements
print("\n", df.mean())

# REST APIs:

# Rest APIs function by sending a request, the request is communicated via HTTP message. 
# The HTTP message usually contains a JSON file. This contains instructions for what operation we would like the service or resource to perform. 
# In a similar manner, API returns a response, via an HTTP message, this response is usually contained within a JSON.

from nba_api.stats.static import teams
import matplotlib.pyplot as plt

def one_dict(list_dict):
    keys=list_dict[0].keys()
    out_dict={key:[] for key in keys}
    for dict_ in list_dict:
        for key, value in dict_.items():
            out_dict[key].append(value)
    return out_dict

nba_teams = teams.get_teams() # The method get_teams() returns a list of dictionaries.

# The dictionary key id has a unique identifier for each team as a value. 
# First three elements of the list:
print("\n", nba_teams[0:3])

# convert the dictionary to a table:
dict_nba_team=one_dict(nba_teams) # Creating the dictionary
df_teams=pd.DataFrame(dict_nba_team) # Convert the dictionary to a dataframe
print("\n", df_teams.head())

# Use the team's nickname to find the unique id
df_warriors=df_teams[df_teams['nickname']=='Warriors']
print("\n", df_warriors)

# To access the first column of the DataFrame:
id_warriors=df_warriors[['id']].values[0][0]
# we now have an integer that can be used to request the Warriors information 
print("\n", id_warriors)

# The function "League Game Finder " will make an API call, it's in the module stats.endpoints.

from nba_api.stats.endpoints import leaguegamefinder
gamefinder = leaguegamefinder.LeagueGameFinder(team_id_nullable=id_warriors)

# We can see the json file by running the following line of code.
gamefinder.get_json()

# The game finder object has a method get_data_frames(), that returns a dataframe. 
# If we view the dataframe, we can see it contains information about all the games the Warriors played. 
# The PLUS_MINUS column contains information on the score, 
# if the value is negative, the Warriors lost by that many points, 
# if the value is positive, the warriors won by that amount of points. 
# The column MATCHUP has the team the Warriors were playing, GSW stands for Golden State Warriors and TOR means Toronto Raptors. 
# vs signifies it was a home game and the @ symbol means an away game.

games = gamefinder.get_data_frames()[0]
games.head()

# You can download the dataframe from the API call for Golden State and run the rest like a video.
import requests

filename = "https://s3-api.us-geo.objectstorage.softlayer.net/cf-courses-data/CognitiveClass/PY0101EN/Chapter%205/Labs/Golden_State.pkl"

def download(url, filename):
    response = requests.get(url)
    if response.status_code == 200:
        with open(filename, "wb") as f:
            f.write(response.content)

##########################################

download(filename, "Golden_State.pkl")

file_name = "Golden_State.pkl"
games = pd.read_pickle(file_name)
games.head()

# We can create two dataframes, one for the games that the Warriors faced the raptors at home, and the second for away games.
games_home=games[games['MATCHUP']=='GSW vs. TOR']
games_away=games[games['MATCHUP']=='GSW @ TOR']

# We can calculate the mean for the column PLUS_MINUS for the dataframes games_home and  games_away:
games_home['PLUS_MINUS'].mean()
games_away['PLUS_MINUS'].mean()

# We can plot out the PLUS MINUS column for the dataframes games_home and  games_away. We see the warriors played better at home.
fig, ax = plt.subplots()

games_away.plot(x='GAME_DATE',y='PLUS_MINUS', ax=ax)
games_home.plot(x='GAME_DATE',y='PLUS_MINUS', ax=ax)
ax.legend(["away", "home"])
plt.show()

# mean for the column PTS for the dataframes games_home and  games_away:
games_home['PTS'].mean()
games_away['PTS'].mean()

