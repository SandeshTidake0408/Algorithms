import webbrowser


def open():
    webbrowser.open('https://www.youtube.com/')


def openImage():
    webbrowser.open(
        "https://tse4.mm.bing.net/th?id=OIP.yF3MuS-xsWEOE9XO7bHVSQHaEY&pid=Api&P=0&h=180")


dialogue = {
    "youtube": open,
    "hello": "How may i help you",
    "image": openImage
}


def main():
    condt = 1
    while (condt):
        x = input("Your response : ")
        if (x == "quit"):
            condt = 0

        if callable(dialogue[x]):
            dialogue[x]()

        print(dialogue[x])


main()
