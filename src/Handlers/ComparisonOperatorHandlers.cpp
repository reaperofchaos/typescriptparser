#include "ComparisonOperatorHandlers.h"

std::shared_ptr<EqualOperator> ComparisonOperatorHandlers::buildEqualOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);

    return std::make_shared<EqualOperator>(
            std::dynamic_pointer_cast<EqualSymbol>(m_tokens[start]),
            std::dynamic_pointer_cast<EqualSymbol>(m_tokens[m_index])
            );
}

std::shared_ptr<StrictEqualOperator> ComparisonOperatorHandlers::buildStrictEqualOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);

    return std::make_shared<StrictEqualOperator>(
            std::dynamic_pointer_cast<EqualSymbol>(m_tokens[start]),
            std::dynamic_pointer_cast<EqualSymbol>(m_tokens[m_index - 1]),
            std::dynamic_pointer_cast<EqualSymbol>(m_tokens[m_index])
            );
}

std::shared_ptr<NotEqualOperator> ComparisonOperatorHandlers::buildNotEqualOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);

    return std::make_shared<NotEqualOperator>(
            std::dynamic_pointer_cast<Exclamation>(m_tokens[start]),
            std::dynamic_pointer_cast<EqualSymbol>(m_tokens[m_index])
            );
}

std::shared_ptr<StrictNotEqualOperator> ComparisonOperatorHandlers::buildStrictNotEqualOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);

    return std::make_shared<StrictNotEqualOperator>(
            std::dynamic_pointer_cast<Exclamation>(m_tokens[start]),
            std::dynamic_pointer_cast<EqualSymbol>(m_tokens[m_index-1]),
            std::dynamic_pointer_cast<EqualSymbol>(m_tokens[m_index])
            );
}

std::shared_ptr<GreaterThanOperator> ComparisonOperatorHandlers::buildGreaterThanOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);

    return std::make_shared<GreaterThanOperator>(
            std::dynamic_pointer_cast<GreaterThanSymbol>(m_tokens[start])
            );
}

std::shared_ptr<GreaterThanOrEqualOperator> ComparisonOperatorHandlers::buildGreaterThanOrEqualOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);

    return std::make_shared<GreaterThanOrEqualOperator>(
            std::dynamic_pointer_cast<GreaterThanSymbol>(m_tokens[start]),
            std::dynamic_pointer_cast<EqualSymbol>(m_tokens[m_index])
            );
}

std::shared_ptr<LessThanOperator> ComparisonOperatorHandlers::buildLessThanOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);

    return std::make_shared<LessThanOperator>(
            std::dynamic_pointer_cast<LessThanSymbol>(m_tokens[start])
            );
}

std::shared_ptr<LessThanOrEqualOperator> ComparisonOperatorHandlers::buildLessThanOrEqualOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);

    return std::make_shared<LessThanOrEqualOperator>(
            std::dynamic_pointer_cast<LessThanSymbol>(m_tokens[start]),
            std::dynamic_pointer_cast<EqualSymbol>(m_tokens[m_index])
            );
}

std::shared_ptr<TernaryOperator> ComparisonOperatorHandlers::buildTernaryOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);

    return std::make_shared<TernaryOperator>(
            std::dynamic_pointer_cast<QuestionMark>(m_tokens[start])
            );
}

std::shared_ptr<TernaryNotOperator> ComparisonOperatorHandlers::buildTernaryNotOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);

    return std::make_shared<TernaryNotOperator>(
            std::dynamic_pointer_cast<Colon>(m_tokens[start])
            );
}