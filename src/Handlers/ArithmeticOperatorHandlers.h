#pragma once
#include <string>
#include <memory>
#include <vector>
#include <map>
#include "../Types/Component.h"
#include "../Types/Operators/Operator.h"
#include "../Types/Operators/ArithmeticOperator.h"
#include "../Utils/CharacterUtilities.h"


/**
 * @brief A set of static functions to generate Arithmetic Operator components
 * 
 */
class ArithmeticOperatorHandlers
{
    public:

        static std::shared_ptr<AdditionOperator> buildAdditionOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);
        
        static std::shared_ptr<SubtractionOperator> buildSubtractionOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);

        static std::shared_ptr<MultiplicationOperator> buildMultiplicationOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);    
        
        static std::shared_ptr<ExponentOperator> buildExponentOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);    

        static std::shared_ptr<DivisionOperator> buildDivisionOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);    
        
        static std::shared_ptr<ModulusOperator> buildModulusOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);    
        
        static std::shared_ptr<IncrementOperator> buildIncrementOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);   

        static std::shared_ptr<DecrementOperator> buildDecrementOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);    
};