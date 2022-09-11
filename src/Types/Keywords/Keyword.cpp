#include "Keyword.h"

std::string Keyword::getKeywordTypeAsString(KeywordType type)
{
    switch (type)
    {
        case KeywordType::VariableKeyword:
            return "Variable Keyword";
        case KeywordType::DataTypeKeyword:
            return "Data Type Keyword";
        case KeywordType::ContainerKeyword:
            return "Container Keyword";
        default: 
            return "Not a Keyword";
    }
};