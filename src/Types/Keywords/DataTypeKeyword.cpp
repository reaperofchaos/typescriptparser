#include "DataTypeKeyword.h"

std::string DataTypeKeyword::getDataTypeKeywordAsString(DataTypeKeywordType type)
{
    switch (type)
    {
        case DataTypeKeywordType::StringKeyword:
            return "String keyword";
        case DataTypeKeywordType::BooleanKeyword:
            return "Boolean Keyword";
        case DataTypeKeywordType::BigIntKeyword:
            return "BigInt Keyword";
        case DataTypeKeywordType::NullKeyword:
            return "Null Keyword";
        case DataTypeKeywordType::UndefinedKeyword:
            return "Undefined Keyword";
        case DataTypeKeywordType::SymbolKeyword:
            return "Symbol Keyword";
        case DataTypeKeywordType::NeverKeyword:
            return "Never Keyword";
        case DataTypeKeywordType::VoidKeyword:
            return "Void Keyword";
        case DataTypeKeywordType::UnknownKeyword:
            return "Unknown Keyword";
        case DataTypeKeywordType::AnyKeyword:
            return "Any Keyword";
        default: 
            return "Not a variable Keyword";
    }
}