text = input("Text: ")

letters = 0
words = 1
sentences = 0

letters_string = ""
space_string = ""
punct_string = ""
special_string = ""

for i in range(len(text)):
    if text[i].isalpha() == True:
        letters_string += text[i]
        letters = letters + 1

    elif text[i] == " ":
        space_string += "/"
        words = words + 1

    elif text[i] == "!" or text[i] == "?" or text[i] == ".":
        punct_string += text[i]
        sentences = sentences + 1

    else:
        special_string += text[i]
        continue


l = float(letters) / words * 100
s = float(sentences) / words * 100

result = 0.0588 * float(l) - 0.296 * float(s) - 15.8
result = round(result)

if result > 16:
    print("Grade 16+")

elif result < 1:
    print("Before Grade 1")

else:
    print(f"Grade {result}")
