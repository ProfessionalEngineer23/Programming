# Downloading And Scraping The Contents Of A Web Page:

# We Download the contents of the web page:
url = "http://www.ibm.com"

# We use get to download the contents of the webpage in text format and store in a variable called data:
data  = requests.get(url).text 

# We create a BeautifulSoup object using the BeautifulSoup constructor
soup = BeautifulSoup(data,"html.parser")  # create a soup object using the variable 'data'

# Scrape all links:
for link in soup.find_all('a',href=True):  # in html anchor/link is represented by the tag <a>

    print(link.get('href'))

# Scrape all images Tags:
for link in soup.find_all('img'):# in html image is represented by the tag <img>
    print(link)
    print(link.get('src'))

# Scrape data from HTML tables:
#The below url contains an html table with data about colors and color codes.
url = "https://cf-courses-data.s3.us.cloud-object-storage.appdomain.cloud/IBM-DA0321EN-SkillsNetwork/labs/datasets/HTMLColorCodes.html"

# Before proceeding to scrape a web site, you need to examine the contents and the way data is organized on the website. 
# Open the above url in your browser and check how many rows and columns there are in the color table. 
# 33 ROWS, 5 COLUMNS

# get the contents of the webpage in text format and store in a variable called data
data  = requests.get(url).text

soup = BeautifulSoup(data,"html.parser")

#find a html table in the web page
table = soup.find('table') # in html table is represented by the tag <table>

#Get all rows from the table
for row in table.find_all('tr'): # in html table row is represented by the tag <tr>
    # Get all columns in each row.
    cols = row.find_all('td') # in html a column is represented by the tag <td>
    color_name = cols[2].string # store the value in column 3 as color_name
    color_code = cols[3].string # store the value in column 4 as color_code
    print("{}--->{}".format(color_name,color_code))
