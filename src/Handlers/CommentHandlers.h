#pragma once
#include <string>
#include <memory>
#include <vector>
#include <map>

#include "../Types/Component.h"
#include "../Types/CommentComponent.h"
#include "OperatorHandlers.h"
#include "../Utils/CharacterUtilities.h"
/**
 * @brief A set of static functions to generate comment components
 * 
 */
class CommentHandlers
{
    public:
        static std::shared_ptr<Component> buildCommentComponent(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index, 
            size_t &start);
        
        static std::shared_ptr<Component> buildSingleLineComment(
            std::shared_ptr<ForwardSlash> forwardSlash1, 
            std::shared_ptr<ForwardSlash> forwardSlash2,
            std::string commentString);

        
        static std::shared_ptr<Component> buildMultilineComment(
            std::shared_ptr<ForwardSlash> forwardSlash, 
            std::shared_ptr<AsteriskSymbol> asterisk,
            std::vector<std::string> comments);  
        
        static std::string ParseCommentLine(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index);

};