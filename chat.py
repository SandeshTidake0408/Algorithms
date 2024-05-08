
# Define a dictionary containing a list of responses for each message
import random


knowledge_base = {
    "hello": ["Hello! How can I assist you today?"],
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
print(get_response("bye"))
