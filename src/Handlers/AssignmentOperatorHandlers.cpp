#include "AssignmentOperatorHandlers.h"

std::shared_ptr<EqualAssignmentOperator> AssignmentOperatorHandlers::buildEqualAssignmentOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);


    return std::make_shared<EqualAssignmentOperator>(
            std::dynamic_pointer_cast<EqualSymbol>(m_tokens[start]));

}

std::shared_ptr<IncrementAssignmentOperator> AssignmentOperatorHandlers::buildIncrementAssignmentOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);


    return std::make_shared<IncrementAssignmentOperator>(
            std::dynamic_pointer_cast<PlusSymbol>(m_tokens[start]),
            std::dynamic_pointer_cast<EqualSymbol>(m_tokens[m_index]));
}

std::shared_ptr<DecrementAssignmentOperator> AssignmentOperatorHandlers::buildDecrementAssignmentOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);


    return std::make_shared<DecrementAssignmentOperator>(
            std::dynamic_pointer_cast<Dash>(m_tokens[start]),
            std::dynamic_pointer_cast<EqualSymbol>(m_tokens[m_index]));
}

std::shared_ptr<ProductAssignmentOperator> AssignmentOperatorHandlers::buildProductAssignmentOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);


    return std::make_shared<ProductAssignmentOperator>(
            std::dynamic_pointer_cast<AsteriskSymbol>(m_tokens[start]),
            std::dynamic_pointer_cast<EqualSymbol>(m_tokens[m_index]));
}

std::shared_ptr<DivisionAssignmentOperator> AssignmentOperatorHandlers::buildDivisionAssignmentOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);


    return std::make_shared<DivisionAssignmentOperator>(
            std::dynamic_pointer_cast<ForwardSlash>(m_tokens[start]),
            std::dynamic_pointer_cast<EqualSymbol>(m_tokens[m_index]));
}

std::shared_ptr<ExponentAssignmentOperator> AssignmentOperatorHandlers::buildExponentAssignmentOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);


    return std::make_shared<ExponentAssignmentOperator>(
            std::dynamic_pointer_cast<AsteriskSymbol>(m_tokens[start]),
            std::dynamic_pointer_cast<AsteriskSymbol>(m_tokens[m_index -1]),
            std::dynamic_pointer_cast<EqualSymbol>(m_tokens[m_index]));
}

std::shared_ptr<ModulusAssignmentOperator> AssignmentOperatorHandlers::buildModulusAssignmentOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);


    return std::make_shared<ModulusAssignmentOperator>(
            std::dynamic_pointer_cast<Percentage>(m_tokens[start]),
            std::dynamic_pointer_cast<EqualSymbol>(m_tokens[m_index]));
}