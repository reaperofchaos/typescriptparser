#pragma once
#include <string>
#include <memory>
#include <vector>
#include <map>

#include "../Types/Symbol.h"
#include "../Types/Component.h"
#include "../Types/Operators/Operator.h"
#include "ArithmeticOperatorHandlers.h"
#include "AssignmentOperatorHandlers.h"
#include "BitwiseOperatorHandlers.h"
#include "ComparisonOperatorHandlers.h"
#include "LogicalOperatorHandlers.h"
#include "../Utils/CharacterUtilities.h"
/**
 * @brief A set of static functions to generate comment components
 * 
 */
class OperatorHandlers
{
    public:
        static std::shared_ptr<Component> buildOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);
};