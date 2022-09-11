#include "VariableKeyword.h"

std::string VariableKeyword::getVariableKeywordTypeAsString(VariableKeywordType type)
{
    switch (type)
    {
        case VariableKeywordType::LetKeyWord:
            return "Let";
        case VariableKeywordType::VarKeyWord:
            return "Var";
        case VariableKeywordType::ConstKeyWord:
            return "Const";
        case VariableKeywordType::EnumKeyWord:
            return "Enum";
        case VariableKeywordType::InterfaceKeyWord:
            return "Interface";
        case VariableKeywordType::FunctionKeyWord:
            return "Function";
        case VariableKeywordType::ClassKeyWord:
            return "Class";
        default: 
            return "Not a variable Keyword";
    }
}