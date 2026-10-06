//
//  Dictionary.cpp
//  chatbot
//
//  Created by Mirek Stejskal on 30.09.2026.
//


#include "Dictionary.hpp"
#include <fstream>
#include <regex>

std::vector<std::string> Dictionary::loadFromFile(){
    std::vector<std::string> lines;
    std::string oneLine;
    
    std::ifstream file("chat.txt");
    if(!file){ //nepodarilo se otevrit soubor || neexistuje
        return lines;
    }
    while (std::getline(file, oneLine)) {
        lines.push_back(oneLine);
    }
    file.close();
    return lines;
}


std::vector<std::string> Dictionary::getWordsFromString(std::string input){
    std::vector<std::string> words;
    std::regex wordRegex("[[:alpha:]]+");
    std::string oneWord;
    std::smatch result;
    std::string replacement = "";
    while (std::regex_search(input,result,wordRegex)) {
        oneWord = result.str();
        words.push_back(oneWord);
        input = std::regex_replace(input,std::regex("\\b" + oneWord + "\\b"),replacement); // "\\b" je ze je to cele slovo
    }
    return words;
}

std::string Dictionary::getResponse(std::string question){
    std::vector<std::string> wordsFromInput = getWordsFromString(question);
    std::regex wordRegex("[[:alpha:]]+ ");
    for(int i = 0; i <wordsFromInput.size(); i++){
        std::string wordInUse = wordsFromInput.at(i);
        std::regex wordToFind ("^"+ wordInUse+" ", std::regex::icase);
        for(int j = 0; j <phrases.size(); j++){
            std::string phraseInUse = phrases.at(j);
            if(std::regex_search(phraseInUse,wordToFind)){ //hledam v radku klicove slovo a vracim radek bez nej a mezery
                phraseInUse.replace(0, wordInUse.size()+1, ""); //+1 znamena oddelovaci mezera
                return phraseInUse;
            }
        }
    }
    return "Toto neznam, zeptej se jinak";
}

