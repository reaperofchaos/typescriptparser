#pragma once
#include <string>
#include <memory>
#include <vector>
#include <map>

#include "../Types/Component.h"
#include "../Types/Operators/Operator.h"
#include "../Types/Operators/ComparisonOperator.h"
#include "../Utils/CharacterUtilities.h"

/**
 * @brief A set of static functions to generate Arithmetic Operator components
 * 
 */
class ComparisonOperatorHandlers
{
    public:
        
        static std::shared_ptr<EqualOperator> buildEqualOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);

        static std::shared_ptr<StrictEqualOperator> buildStrictEqualOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);

        static std::shared_ptr<NotEqualOperator> buildNotEqualOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);
        
        static std::shared_ptr<StrictNotEqualOperator> buildStrictNotEqualOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);
        
        static std::shared_ptr<GreaterThanOperator> buildGreaterThanOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);

        static std::shared_ptr<GreaterThanOrEqualOperator> buildGreaterThanOrEqualOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);

        static std::shared_ptr<LessThanOperator> buildLessThanOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);

        static std::shared_ptr<LessThanOrEqualOperator> buildLessThanOrEqualOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);

        static std::shared_ptr<TernaryOperator> buildTernaryOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);

        static std::shared_ptr<TernaryNotOperator> buildTernaryNotOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);

        
        
};