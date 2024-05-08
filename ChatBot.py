pairs = {
    "Hello": "Hi how are you",
    "how are you": "Good, How can i help you?",
    "Bye": "Bye, Have a good day"
}

print("How can i help you ?")
while (True):
    x = input()
    if x in pairs.keys():
        print(pairs[x])
    else:
        print("incorrect Input")
