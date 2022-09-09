#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include "../Types/CharType.h"
#include "../Types/Component.h"
#include "../Utils/CharacterUtilities.h"

/**
 * A class used to create Components from Token vectors
 */
class TokenHandlers {
    public:
        static std::shared_ptr<NumberType> buildNumberComponent(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index,
            std::vector<std::shared_ptr<Number>> &numbers);

        static std::shared_ptr<CloseArray> buildCloseArray(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index,
            size_t &start);
        
        static std::shared_ptr<CloseObject> buildCloseObject(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index,
            size_t &start);


        static std::shared_ptr<WhiteSpaces> buildWhiteSpaces(
            std::vector<std::shared_ptr<WhiteSpace>> &whiteSpaces);

        static std::shared_ptr<Name> buildName(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index,
            size_t &start,
            std::vector<std::shared_ptr<Character>> &characters);

        static std::shared_ptr<StringType> buildString(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index,
            std::vector<std::shared_ptr<Character>> &characters, 
            SymbolType symbolType);

        static std::shared_ptr<OpenArray> buildOpenArray(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index,
            size_t &start);

        static std::shared_ptr<OpenObject> buildOpenObject(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index,
            size_t &start);

        static std::shared_ptr<ExclamationComponent> buildExclamation(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index,
            size_t &start);

        static std::shared_ptr<EqualComponent> buildEqual(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index,
            size_t &start);
        
        static std::shared_ptr<SemicolonComponent> buildSemicolon(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index,
            size_t &start);
        
        static std::shared_ptr<ColonComponent> buildColon(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index,
            size_t &start);
        
        static std::shared_ptr<PercentageComponent> buildPercentage(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index,
            size_t &start);
        
        static std::shared_ptr<CommaComponent> buildComma(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index,
            size_t &start);
        
        static std::shared_ptr<HashTagComponent> buildHashTag(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index,
            size_t &start);

        static std::shared_ptr<StringType> buildNestedString(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index,
            std::vector<std::shared_ptr<Character>> &characters);

        static void findWhiteSpace(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index,
            std::vector<std::shared_ptr<WhiteSpace>> &whiteSpaces);
        
        static std::shared_ptr<OpenParenthesisComponent> buildOpenParenthesis(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index,
            size_t &start);
        
        static std::shared_ptr<CloseParenthesisComponent> buildCloseParenthesis(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index,
            size_t &start);
        
        static std::shared_ptr<AndComponent> buildAndComponent(
            std::vector<std::shared_ptr<Character>> &m_tokens, 
            size_t &m_index,
            size_t &start);
};
