####################################################
for i, color in enumerate(['red','yellow','green']):
    print(f"Color {i}: {color}")
####################################################
squares = ['orange', 'orange', 'purple', 'blue ', 'orange']
new_squares = []
i = 0
while(i < len(squares) and squares[i] == 'orange'):
    new_squares.append(squares[i])
    i = i + 1
print (f"\n",new_squares)
#####################################################
PlayListRatings = [10, 9.5, 10, 8, 7.5, 5, 10, 10]
i = 0
Rating = PlayListRatings[0]
while(i < len(PlayListRatings) and Rating >= 6):
    print(Rating)
    #i = i + 1 # This prints the value 10 only once 
    Rating = PlayListRatings[i]
    i = i + 1  # This prints 10 twice because the rating is assigned PlayListRatings[i] later in the while loop,
    # However, the first '10' was printed from the PlayListRatings[0] and is initially 0.

######################################################
# Defining custom exception
class NegativeNumberError(Exception):
    def __init__(self, value):
        self.value = value
        super().__init__(f"Negative number not allowed: {value}")

# Use it in code
def square_root(x):
    if x < 0:
        raise NegativeNumberError(x)  # Raise your custom exception
    return x ** 0.5

#Handle with try-except

b = float(input("Please enter a value for b that will be square rooted: "))
try:
    print(square_root(b))
except NegativeNumberError as e:
    print("Custom Exception Caught:", e)
