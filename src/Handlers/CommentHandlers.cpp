#include "CommentHandlers.h"

/**
 * @brief Builds a comment component from the provided characters
 * 
 * @param m_tokens vector of tokens 
 * @param m_index position in the vector
 * @param start initial position in the vector
 * @return std::shared_ptr<Component> 
 */
std::shared_ptr<Component> CommentHandlers::buildOpenCommentComponent(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index, 
    size_t &start)
{
    switch(m_tokens[start]->type())
    {
        case CharacterType::Symbol:
            switch(m_tokens[start]->symbolType())
            {
                case SymbolType::ForwardSlash:
                    if(m_index + 1 < m_tokens.size() 
                    && (m_tokens[m_index]->symbolType() == SymbolType::AsteriskSymbol 
                    || m_tokens[m_index]->symbolType() == SymbolType::ForwardSlash)
                    ){
                        CharacterUtilities::IncrementIndex(m_tokens, m_index);
                        if(m_tokens[m_index]->type() == CharacterType::Symbol &&
                        m_tokens[m_index]->symbolType() == SymbolType::AsteriskSymbol)
                        {
                            CharacterUtilities::IncrementIndex(m_tokens, m_index);
                            CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);
                            return CommentHandlers::buildOpenMultilineComment(std::make_shared<ForwardSlash>(m_tokens[start]->getValue()),
                            std::make_shared<AsteriskSymbol>(m_tokens[m_index-1]->getValue()) );
                        }
                        if(m_tokens[m_index]->type() == CharacterType::Symbol &&
                        m_tokens[m_index]->symbolType() == SymbolType::ForwardSlash)
                        {
                            CharacterUtilities::IncrementIndex(m_tokens, m_index);
                            CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);
                            return CommentHandlers::buildOpenSingleLineComment(
                                std::make_shared<ForwardSlash>(m_tokens[start]->getValue()),
                                std::make_shared<ForwardSlash>(m_tokens[m_index-1]->getValue()));
                        }
                    }
                    //operator
                    m_index = start; 
                    return OperatorHandlers::buildOperator(m_tokens, m_index, start);

                default:
                    return NULL;

            };
        default:
            return NULL; 
    }
    return NULL; 
}

std::shared_ptr<Component> CommentHandlers::buildOpenMultilineComment(
    std::shared_ptr<ForwardSlash> forwardSlash, 
    std::shared_ptr<AsteriskSymbol> asterisk)
{
    return std::make_shared<OpenMultiLineComment>(forwardSlash, asterisk);
}

std::shared_ptr<Component> CommentHandlers::buildOpenSingleLineComment(
    std::shared_ptr<ForwardSlash> forwardSlash1, 
    std::shared_ptr<ForwardSlash> forwardSlash2)
{
    return std::make_shared<OpenSingleLineComment>(forwardSlash1, forwardSlash2);
}

std::shared_ptr<Component> CommentHandlers::buildCloseMultilineComment(
    std::shared_ptr<AsteriskSymbol> asterisk, 
    std::shared_ptr<ForwardSlash> forwardSlash)
{
    return std::make_shared<CloseMultiLineComment>(asterisk, forwardSlash);
}