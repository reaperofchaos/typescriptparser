#pragma once
#include <string>
#include <memory>
#include <vector>
#include <map>
#include "../Types/Component.h"
#include "../Types/Operators/Operator.h"
#include "../Types/Operators/AssignmentOperator.h"
#include "../Utils/CharacterUtilities.h"

/**
 * @brief A set of static functions to generate Assignment Operator components
 * 
 */
class AssignmentOperatorHandlers
{
    public:
        
        static std::shared_ptr<IncrementAssignmentOperator> buildIncrementAssignmentOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);
        

        static std::shared_ptr<EqualAssignmentOperator> buildEqualAssignmentOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);
        
        static std::shared_ptr<DecrementAssignmentOperator> buildDecrementAssignmentOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);

        static std::shared_ptr<ProductAssignmentOperator> buildProductAssignmentOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);    
        
        static std::shared_ptr<ExponentAssignmentOperator> buildExponentAssignmentOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);    

        static std::shared_ptr<DivisionAssignmentOperator> buildDivisionAssignmentOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);    
        
        static std::shared_ptr<ModulusAssignmentOperator> buildModulusAssignmentOperator(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);
};