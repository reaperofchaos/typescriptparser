#pragma once
#include <string>
#include <memory>
#include <vector>
#include <map>

#include "../Types/Component.h"
#include "../Types/CommentComponent.h"
#include "../Utils/CharacterUtilities.h"
/**
 * @brief A set of static functions to generate comment components
 * 
 */
class CommentHandlers
{
    public:
        static std::shared_ptr<Component> buildOpenCommentComponent(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);
        
        static std::shared_ptr<Component> buildOpenSingleLineComment(
            std::shared_ptr<ForwardSlash> forwardSlash1, 
            std::shared_ptr<ForwardSlash> forwardSlash2);

        static std::shared_ptr<Component> buildCloseSingleLineComment(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);    
        
        static std::shared_ptr<Component> buildOpenMultilineComment(
            std::shared_ptr<ForwardSlash> forwardSlash, 
            std::shared_ptr<AsteriskSymbol> asterisk);  

        static std::shared_ptr<Component> buildCloseMultilineComment(
            std::shared_ptr<AsteriskSymbol> asterisk, 
            std::shared_ptr<ForwardSlash> forwardSlash);  
};