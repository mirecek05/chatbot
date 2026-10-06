//
//  Chatbot.hpp
//  chatbot
//
//  Created by Mirek Stejskal on 30.09.2026.
//

#ifndef Chatbot_hpp
#define Chatbot_hpp

#include <stdio.h>
#include "Dictionary.hpp"
class Chatbot{
private:
    Dictionary dictionary;
public:
    void chat();
};

#endif /* Chatbot_hpp */
