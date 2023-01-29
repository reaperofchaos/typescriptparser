#pragma once
#include <string>
#include <memory>
#include <vector>
#include <map>
#include "../Types/Component.h"
#include "../Types/Operators/Operator.h"
#include "../Types/Operators/LogicalOperator.h"
#include "../Utils/CharacterUtilities.h"

/**
 * @brief A set of static functions to generate Arithmetic Operator components
 * 
 */
class LogicalOperatorHandlers
{
    public:
        
        static std::shared_ptr<LogicalAndOperator> buildLogicalAndOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);
        
        static std::shared_ptr<LogicalOrOperator> buildLogicalOrOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);
        
        static std::shared_ptr<LogicalNotOperator> buildLogicalNotOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);
        
};