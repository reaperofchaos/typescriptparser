#include "CommentHandlers.h"

/**
 * @brief Builds a comment component from the provided characters
 * 
 * @param m_tokens vector of tokens 
 * @param m_index position in the vector
 * @param start initial position in the vector
 * @return std::shared_ptr<Component> 
 */
std::shared_ptr<Component> CommentHandlers::buildCommentComponent(
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
                            std::vector<std::string> commentLines; 
                            bool stop = true; 
                            CharacterUtilities::IncrementIndex(m_tokens, m_index);
                            CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);

                            // loop until the multiline end is found */
                            while(stop){
                                //loop until new line
                                std::string commentString = CommentHandlers::ParseCommentLine(m_tokens, m_index);
                                if(commentString == ""){
                                    stop = false; 
                                }else{
                                    commentLines.push_back(commentString);
                                }

                            };

                            return CommentHandlers::buildMultilineComment(
                                std::make_shared<ForwardSlash>(m_tokens[start]->getValue()),
                                std::make_shared<AsteriskSymbol>(m_tokens[m_index-1]->getValue()),
                                commentLines );
                        }
                        if(m_tokens[m_index]->type() == CharacterType::Symbol &&
                        m_tokens[m_index]->symbolType() == SymbolType::ForwardSlash)
                        {
                            CharacterUtilities::IncrementIndex(m_tokens, m_index);
                            std::string commentString = CommentHandlers::ParseCommentLine(m_tokens, m_index); 
                            CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);
                            
                            return CommentHandlers::buildSingleLineComment(
                                std::make_shared<ForwardSlash>(m_tokens[start]->getValue()),
                                std::make_shared<ForwardSlash>(m_tokens[start + 1]->getValue()),
                                commentString);
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

std::shared_ptr<Component> CommentHandlers::buildMultilineComment(
    std::shared_ptr<ForwardSlash> forwardSlash, 
    std::shared_ptr<AsteriskSymbol> asterisk,
    std::vector<std::string> comments)
{
    return std::make_shared<MultiLineComment>(forwardSlash, asterisk, comments);
}

std::shared_ptr<Component> CommentHandlers::buildSingleLineComment(
    std::shared_ptr<ForwardSlash> forwardSlash1, 
    std::shared_ptr<ForwardSlash> forwardSlash2,
    std::string commentString)
{
    return std::make_shared<SingleLineComment>(forwardSlash1, forwardSlash2, commentString);
}

/**
 * @brief Parses text until a line return is found and returns a string 
 * or null if the end of the comment tag si found
 * 
 * @param m_tokens 
 * @param m_index 
 * @return std::string 
 */
std::string CommentHandlers::ParseCommentLine(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index)
{
    std::string line = ""; 
    bool stopLine = true; 

    //loop until new line
    while(stopLine)
    {

        //end of line
        if(m_tokens[m_index]->type() == CharacterType::WhiteSpace &&
            (m_tokens[m_index]->whiteSpaceType() == WhiteSpaceType::Return ||
            m_tokens[m_index]->whiteSpaceType() == WhiteSpaceType::NewLine))
        {
            CharacterUtilities::IncrementIndex(m_tokens, m_index);
            return line; 
        }

        if(m_tokens[m_index]->type() == CharacterType::Symbol 
            && m_tokens[m_index]->symbolType() == SymbolType::AsteriskSymbol)
        {
            // return an empty string if found the closing multiline tag
            if( m_index + 1 < m_tokens.size() -1
                && m_tokens[m_index + 1]->type() == CharacterType::Symbol 
                && m_tokens[m_index+1]->symbolType() == SymbolType::ForwardSlash)
            {
                CharacterUtilities::IncrementIndex(m_tokens, m_index);
                CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);
                return "";
            }
            // ignore the asterisk after a new line in a multiline
            if(m_tokens[m_index-1]->type() == CharacterType::WhiteSpace
                && m_tokens[m_index -1]->whiteSpaceType() == WhiteSpaceType::Return)
            {
                CharacterUtilities::IncrementIndex(m_tokens, m_index);
            }else{
                //add to comment string  and increment
                line = line + m_tokens[m_index]->getValue();
                CharacterUtilities::IncrementIndex(m_tokens, m_index);
            }
        }

        //add to comment string  and increment
        line = line + m_tokens[m_index]->getValue();
        CharacterUtilities::IncrementIndex(m_tokens, m_index);

    };

    return line;
}