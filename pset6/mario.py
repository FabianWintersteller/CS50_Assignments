number = input("Height: ")

if number.isnumeric() == False:
    print("Not an integer.")
    number = input("Height: ")
    number = int(number)

number = int(number)

if number > 8:
    print("Too high.")
    number = input("Height: ")
    number = int(number)

elif number < 1:
    print("Too low.")
    number = input("Height: ")
    number = int(number)

for i in range(number - 1, -1, -1):
    for a in range(i):
        print(" ", end="")

    for j in range(number - i):
        print("#", end="")

    print("  ", end="")

    for k in range(number - i):
        print("#", end="")

    print("")