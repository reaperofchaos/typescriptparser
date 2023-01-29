#include "ArithmeticOperatorHandlers.h"

std::shared_ptr<AdditionOperator> ArithmeticOperatorHandlers::buildAdditionOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);

    return std::make_shared<AdditionOperator>(
            std::dynamic_pointer_cast<PlusSymbol>(m_tokens[start]));

}

std::shared_ptr<SubtractionOperator> ArithmeticOperatorHandlers::buildSubtractionOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);

    return std::make_shared<SubtractionOperator>(
            std::dynamic_pointer_cast<Dash>(m_tokens[start]));

}

std::shared_ptr<MultiplicationOperator> ArithmeticOperatorHandlers::buildMultiplicationOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);

    return std::make_shared<MultiplicationOperator>(
            std::dynamic_pointer_cast<AsteriskSymbol>(m_tokens[start]));

}

std::shared_ptr<DivisionOperator> ArithmeticOperatorHandlers::buildDivisionOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);

    return std::make_shared<DivisionOperator>(
            std::dynamic_pointer_cast<ForwardSlash>(m_tokens[start]));

}

std::shared_ptr<ExponentOperator> ArithmeticOperatorHandlers::buildExponentOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);

    return std::make_shared<ExponentOperator>(
            std::dynamic_pointer_cast<AsteriskSymbol>(m_tokens[start]), 
            std::dynamic_pointer_cast<AsteriskSymbol>(m_tokens[m_index]));

}

std::shared_ptr<ModulusOperator> ArithmeticOperatorHandlers::buildModulusOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);

    return std::make_shared<ModulusOperator>(
            std::dynamic_pointer_cast<Percentage>(m_tokens[start]));

}

std::shared_ptr<IncrementOperator> ArithmeticOperatorHandlers::buildIncrementOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);


    return std::make_shared<IncrementOperator>(
            std::dynamic_pointer_cast<PlusSymbol>(m_tokens[start]), 
            std::dynamic_pointer_cast<PlusSymbol>(m_tokens[m_index]));

}

std::shared_ptr<DecrementOperator> ArithmeticOperatorHandlers::buildDecrementOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);


    return std::make_shared<DecrementOperator>(
            std::dynamic_pointer_cast<Dash>(m_tokens[start]), 
            std::dynamic_pointer_cast<Dash>(m_tokens[m_index]));

}