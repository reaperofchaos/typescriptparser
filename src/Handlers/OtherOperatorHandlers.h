#pragma once
#include <string>
#include <memory>
#include <vector>
#include <map>
#include "../Types/Component.h"
#include "../Types/Operators/Operator.h"
#include "../Types/Operators/OtherOperator.h"
#include "../Utils/CharacterUtilities.h"

/**
 * @brief A set of static functions to generate Other Operator components
 * 
 */
class OtherOperatorHandlers
{
    public:
        
        static std::shared_ptr<MethodOperator> buildMethodOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);
        
        static std::shared_ptr<SpreadOperator> buildSpreadOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);
        
        static std::shared_ptr<NullCoalescingOperator> buildNullCoalescingOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);
        
};