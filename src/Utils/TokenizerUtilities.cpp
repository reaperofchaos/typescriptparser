#include "TokenizerUtilities.h"

/**
 * @brief A function safely increment the index of a string
 * 
 * @param text 
 * @param m_index 
 */
void TokenizerUtilities::IncrementIndex( 
    std::string text,
    size_t &m_index)
{
    if(m_index < text.size())
    {
        m_index++;
    } 
}