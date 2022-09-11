#pragma once
#include <string>
#include <memory>
#include <vector>
#include <map>

#include "../Types/Component.h"
#include "../Types/Keywords/Keyword.h"
#include "../Types/Keywords/VariableKeyword.h"
#include "../Types/Keywords/ContainerKeyword.h"
#include "../Types/Keywords/DataTypeKeyword.h"

/**
 * @brief A set of static functions to generate keyword components
 * 
 */
class KeywordHandlers
{
    public:
        static std::map<std::string, KeywordType> keywordToString;
        static std::map<std::string, VariableKeywordType> variableKeywordToString;
        static std::map<std::string, ContainerKeywordType> containerKeywordToString;
        static std::map<std::string, DataTypeKeywordType> dataTypeKeywordToString;

        static std::shared_ptr<Component> buildKeyword(std::string value);
        static std::shared_ptr<Component> buildDataTypeKeyword(std::string value);
        static std::shared_ptr<Component> buildContainerKeyword(std::string value);
        static std::shared_ptr<Component> buildVariableKeyword(std::string value);

};