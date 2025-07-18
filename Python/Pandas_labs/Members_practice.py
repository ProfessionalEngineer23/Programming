# Step 1: Create sample member data
members = [
    "Jamil,2020-01-01,yes\n",
    "Emily,2019-05-12,no\n",
    "Mark,2021-03-15,yes\n",
    "Deryl,2018-07-21,no\n",
    "Frank,2022-02-02,yes\n"
]

# Step 2: Write all members to a file
with open("mini_members.txt", "w") as f:
    f.writelines(members)

# Step 3: Separate active and inactive members
with open("mini_members.txt", "r") as f:
    all_members = f.readlines()

with open("mini_members.txt", "w") as active_file, open("mini_inactive.txt", "w") as inactive_file:
    for member in all_members:
        if "no" in member:
            inactive_file.write(member)  # write to inactive file
        else:
            active_file.write(member)    # keep in active file

# Step 4: Display results
print("Active Members:")
with open("mini_members.txt", "r") as f:
    print(f.read())

print("Inactive Members:")
with open("mini_inactive.txt", "r") as f:
    print(f.read())
