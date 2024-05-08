
# Define a dictionary containing a list of responses for each message
import random


knowledge_base = {
    "hello": ["Hello! How can I assist you today?", "Hi there"],
    "bye": ["Bye Sir , Have a nice day !"],
    "create account": ["Sure, I can help you with that. Here are the steps..."],
    # Add more messages and responses as needed
}

# Define a function to get a response from the bot


def get_response(user_input):
    # Convert the user input to lower case (for simplicity)
    user_input = user_input.lower()

    # Find a response in the knowledge base, if available
    for message, responses in knowledge_base.items():
        if message in user_input:
            # Return a random response from the list
            return random.choice(responses)

    # If no response was found, return a default message
    return "I'm sorry, I didn't understand that. Can you please rephrase?"


# Test the bot
print(get_response("hello"))


# pairs = {
#     "Hello": "Hi how are you",
#     "how are you": "Good, How can i help you?",
#     "Bye": "Bye, Have a good day"
# }

# print("How can i help you ?")
# while (True):
#     x = input()
#     if x in pairs.keys():
#         print(pairs[x])
#     else:
#         print("incorrect Input")
