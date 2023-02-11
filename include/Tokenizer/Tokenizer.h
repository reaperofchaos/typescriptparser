#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <optional>
#include <memory>
#include "Types/CharType.h"
#include "Types/Symbol.h"
#include "Types/WhiteSpace.h"
#include "Utils/TokenizerUtilities.h"

/**
 * @brief Class to break down string into smaller chunks
 * generally characters and identifies them with a charType
 * 
 */
class Tokenizer{
    private:
        std::string m_input; // string input
        size_t m_index = 0; // position in string
        std::vector<std::shared_ptr<Character>> tokens;

    public: 
        Tokenizer(std::string input)
        {
            this->m_input = input; 
        }

        std::vector<std::shared_ptr<Character>>getTokens(){return this->tokens;}
        std::shared_ptr<Character> next();
        void tokenize();
};