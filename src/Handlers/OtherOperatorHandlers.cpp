#include "OtherOperatorHandlers.h"

std::shared_ptr<MethodOperator> OtherOperatorHandlers::buildMethodOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);

    return std::make_shared<MethodOperator>(
            std::dynamic_pointer_cast<PeriodSymbol>(m_tokens[start])
            );
}

std::shared_ptr<SpreadOperator> OtherOperatorHandlers::buildSpreadOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);

    return std::make_shared<SpreadOperator>(
            std::dynamic_pointer_cast<PeriodSymbol>(m_tokens[start]),
            std::dynamic_pointer_cast<PeriodSymbol>(m_tokens[m_index-1]),
            std::dynamic_pointer_cast<PeriodSymbol>(m_tokens[m_index])
            );
}

std::shared_ptr<NullCoalescingOperator> OtherOperatorHandlers::buildNullCoalescingOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);

    return std::make_shared<NullCoalescingOperator>(
            std::dynamic_pointer_cast<QuestionMark>(m_tokens[start]),
            std::dynamic_pointer_cast<QuestionMark>(m_tokens[m_index])
            );
}