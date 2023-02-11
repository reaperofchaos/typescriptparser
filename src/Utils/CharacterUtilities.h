#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include "Tokenizer/Types/CharType.h"

/**
 * A class used to traverse and display Character vectors
 */
class CharacterUtilities {
    public: 
        static void IgnoreWhiteSpace( 
            std::vector<std::shared_ptr<Character>> &characters,
            size_t &m_index);

        static void IncrementIndex( 
            std::vector<std::shared_ptr<Character>> &characters,
            size_t &m_index);
        
        static void DisplayCurrent( 
            std::vector<std::shared_ptr<Character>> &characters,
            size_t &m_index);

};