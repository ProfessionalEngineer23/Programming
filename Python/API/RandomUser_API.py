# Random User Documentation: https://randomuser.me/documentation

from randomuser import RandomUser
import pandas as pd

# Random user object r 
r = RandomUser()

# Get list of 10 random users
some_list = r.generate_users(10)

print("\n", some_list)

# Getting the full_name parameter
name = r.get_full_name()

# Get full name for 10 users from some_list
for user in some_list:
    print ("\n", user.get_full_name()," ",user.get_email())

# generate photos of the random 10 users
for user in some_list:
    print("\n", user.get_picture())

# Function with user parameters to return a Pandas dataframe with the users
def get_users():
    users =[]
     
    for user in RandomUser.generate_users(10):
        users.append({"Name":user.get_full_name(),"Gender":user.get_gender(),"City":user.get_city(),"State":user.get_state(),"Email":user.get_email(), "DOB":user.get_dob(),"Picture":user.get_picture()})
      
    return pd.DataFrame(users)   

# Calling the function to get the users dataframe
get_users()

# Assigining dataframe to df1
df1 = pd.DataFrame(get_users())  
