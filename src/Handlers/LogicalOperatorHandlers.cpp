#include "LogicalOperatorHandlers.h"

std::shared_ptr<LogicalAndOperator> LogicalOperatorHandlers::buildLogicalAndOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);

    return std::make_shared<LogicalAndOperator>(
            std::dynamic_pointer_cast<AndSymbol>(m_tokens[start]),
            std::dynamic_pointer_cast<AndSymbol>(m_tokens[m_index])
            );
}

std::shared_ptr<LogicalOrOperator> LogicalOperatorHandlers::buildLogicalOrOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);

    return std::make_shared<LogicalOrOperator>(
            std::dynamic_pointer_cast<PipeSymbol>(m_tokens[start]),
            std::dynamic_pointer_cast<PipeSymbol>(m_tokens[m_index])
            );
}

std::shared_ptr<LogicalNotOperator> LogicalOperatorHandlers::buildLogicalNotOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);

    return std::make_shared<LogicalNotOperator>(
            std::dynamic_pointer_cast<Exclamation>(m_tokens[start]));
}