#include "CharacterUtilities.h"

/**
 * @brief Function that checks if the current character
 * is a whitespace character and then increments until a non-whitespace
 * character is found. 
 * 
 * @param characters 
 * @param m_index 
 */
void CharacterUtilities::IgnoreWhiteSpace( 
    std::vector<std::shared_ptr<Character>> &characters,
    size_t &m_index)
{
    while(characters[m_index]->type() == CharacterType::WhiteSpace )
    {
        CharacterUtilities::IncrementIndex(characters, m_index);
    } 
}

/**
 * @brief A function to safely increment the index of a character vector
 * 
 * @param characters 
 * @param m_index 
 */
void CharacterUtilities::IncrementIndex( 
    std::vector<std::shared_ptr<Character>> &characters,
    size_t &m_index)
{
    if(m_index < characters.size())
    {
        m_index++;
    }
}

/**
 * @brief A function to display the current character at a given index
 * 
 * @param characters 
 * @param m_index 
 */
void CharacterUtilities::DisplayCurrent( 
    std::vector<std::shared_ptr<Character>> &characters,
    size_t &m_index)
{
    std::cout << characters[m_index]->inspect() << "\n"; 
}