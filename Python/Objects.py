# Define a class called Vehicle
class Vehicle:
    # Class attribute shared by all instances (default color)
    #color = "white" #Default color white

    # Constructor (__init__) method to initialize object-specific attributes
    def __init__(self, max_speed, mileage):
        self.max_speed = max_speed            # Instance attribute
        self.mileage = mileage                # Instance attribute
        self.seating_capacity = None          # Initially None; can be set later
        self.color = "white"                  # Default color

    # Method to assign seating capacity to the vehicle object
    def assign_seating_capacity(self, seating_capacity):
        self.seating_capacity = seating_capacity

    def assign_color(self, color):
        self.color = color

    # Method to display all the properties of the vehicle object
    def display_properties(self):
        print("Properties of the Vehicle:")
        print("Color:", self.color)                  # Accessing class attribute
        print("Maximum Speed:", self.max_speed)      # Instance attribute
        print("Mileage:", self.mileage)              # Instance attribute
        print("Seating Capacity:", self.seating_capacity)  # Instance attribute
        print()  # Adds a blank line between vehicles for readability

# --- Creating and using objects of the Vehicle class ---

# Create the first vehicle object with max_speed = 200, mileage = 20
vehicle1 = Vehicle(200, 20)
vehicle1.assign_seating_capacity(5)  # Set seating capacity to 5
vehicle1.assign_color("white")       # Set color to white
vehicle1.display_properties()        # Print details of vehicle1

# Create the second vehicle object with max_speed = 180, mileage = 25
vehicle2 = Vehicle(180, 25)
vehicle2.assign_seating_capacity(4)  # Set seating capacity to 4
vehicle2.assign_color("blue")        # Set color to blue
vehicle2.display_properties()        # Print details of vehicle2
