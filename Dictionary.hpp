//
//  Dictionary.hpp
//  chatbot
//
//  Created by Mirek Stejskal on 30.09.2026.
//

#ifndef Dictionary_hpp
#define Dictionary_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
class Dictionary{
private:
    std::vector<std::string> loadFromFile(); //zavola se pro nacteni frazi ze souboru do atributu phrases
    std::vector<std::string> phrases = loadFromFile();
    std::vector<std::string> getWordsFromString(std::string input); //z toho co zadal uzivatel to rozseka na slova
public:
    std::string getResponse(std::string question);
};

#endif /* Dictionary_hpp */
