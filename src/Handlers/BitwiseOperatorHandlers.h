#pragma once
#include <string>
#include <memory>
#include <vector>
#include <map>
#include "../Types/Component.h"
#include "../Types/Operators/Operator.h"
#include "../Types/Operators/BitwiseOperator.h"
#include "../Utils/CharacterUtilities.h"


/**
 * @brief A set of static functions to generate Bitwise Operator components
 * 
 */
class BitwiseOperatorHandlers
{
    public:
        
        static std::shared_ptr<BitAndOperator> buildBitAndOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);
        

        static std::shared_ptr<BitOrOperator> buildBitOrOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);
        
        static std::shared_ptr<BitNotOperator> buildBitNotOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);

        static std::shared_ptr<BitXOROperator> buildBitXOROperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);    
        
        static std::shared_ptr<BitLeftShiftOperator> buildBitLeftShiftOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);

        static std::shared_ptr<BitRightShiftOperator> buildBitRightShiftOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);  
        
        static std::shared_ptr<BitUnsignedRightOperator> buildBitUnsignedRightOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);
};