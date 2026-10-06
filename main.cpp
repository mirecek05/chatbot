//
//  main.cpp
//  chatbot
//
//  Created by Mirek Stejskal on 30.09.2026.
//

#include <iostream>
#include "Chatbot.hpp"

int main() {
    Chatbot *chat = new Chatbot();
    chat->chat();
    delete chat;
    return EXIT_SUCCESS;
}
