//
//  Chatbot.cpp
//  chatbot
//
//  Created by Mirek Stejskal on 30.09.2026.
//

#include "Chatbot.hpp"


void Chatbot::chat(){
    while (1) {
        std::cout << "U: ";
        std::string userEntry;
        std::getline(std::cin, userEntry); //nacteni veskereho vstupu od uzivatele
        std::string chatResponse = dictionary.getResponse(userEntry);
        std::cout << "P: " << chatResponse <<std::endl;
    }
}
