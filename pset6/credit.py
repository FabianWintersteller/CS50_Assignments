number = input("Number: ")

if number.isnumeric() == False:
    print("INVALID")

if len(number) < 15:
    print("INVALID")

if len(number) > 16:
    print("INVALID")

number = int(number)

if number >= 5000000000000000 and number < 6000000000000000:
    print("MASTERCARD")

elif number >= 4000000000000000 and number < 5000000000000000:
    print("VISA")

elif number >= 300000000000000 and number < 400000000000000:
    print("AMEX")

else:
    print("INVALID")