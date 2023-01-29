#include "BitwiseOperatorHandlers.h"

std::shared_ptr<BitAndOperator> BitwiseOperatorHandlers::buildBitAndOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);


    return std::make_shared<BitAndOperator>(
            std::dynamic_pointer_cast<AndSymbol>(m_tokens[start]));

}

std::shared_ptr<BitOrOperator> BitwiseOperatorHandlers::buildBitOrOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);


    return std::make_shared<BitOrOperator>(
            std::dynamic_pointer_cast<PipeSymbol>(m_tokens[start]));

}

std::shared_ptr<BitNotOperator> BitwiseOperatorHandlers::buildBitNotOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);


    return std::make_shared<BitNotOperator>(
            std::dynamic_pointer_cast<TildeSymbol>(m_tokens[start]));

}

std::shared_ptr<BitXOROperator> BitwiseOperatorHandlers::buildBitXOROperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);


    return std::make_shared<BitXOROperator>(
            std::dynamic_pointer_cast<CaratSymbol>(m_tokens[start]));

}

std::shared_ptr<BitLeftShiftOperator> BitwiseOperatorHandlers::buildBitLeftShiftOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);


    return std::make_shared<BitLeftShiftOperator>(
            std::dynamic_pointer_cast<LessThanSymbol>(m_tokens[start]),
            std::dynamic_pointer_cast<LessThanSymbol>(m_tokens[m_index]));

}

std::shared_ptr<BitRightShiftOperator> BitwiseOperatorHandlers::buildBitRightShiftOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);


    return std::make_shared<BitRightShiftOperator>(
            std::dynamic_pointer_cast<GreaterThanSymbol>(m_tokens[start]),
            std::dynamic_pointer_cast<GreaterThanSymbol>(m_tokens[m_index]));

}

std::shared_ptr<BitUnsignedRightOperator> BitwiseOperatorHandlers::buildBitUnsignedRightOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index,
    size_t &start)
{
    CharacterUtilities::IncrementIndex(m_tokens, m_index);
    CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);


    return std::make_shared<BitUnsignedRightOperator>(
            std::dynamic_pointer_cast<GreaterThanSymbol>(m_tokens[start]),
            std::dynamic_pointer_cast<GreaterThanSymbol>(m_tokens[m_index-1]),
            std::dynamic_pointer_cast<GreaterThanSymbol>(m_tokens[m_index]));

}