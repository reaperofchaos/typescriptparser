#pragma once
#include <string>
#include "../Component.h"
#include "../CharType.h"

enum class KeywordType
{
    VariableKeyword,
    Unknown
};

enum class VariableKeywordType
{
    LetWord,
    VarWord, 
    ConstWord,
    Unknown
};

class Keyword: public Component
{
    private:
        std::string value;
    public:
        Keyword(std::vector<std::shared_ptr<Lowercase>> letters)
        {
            std::string value = ""; 
            for(std::shared_ptr<Lowercase> letter: letters){
                value += letter->getValue(); 
            }
            this->value = value;
        }
        
        virtual ~Keyword() = default;
        virtual std::string getKeywordTypeAsString(KeywordType type){
            switch (type)
            {
                case KeywordType::VariableKeyword:
                    return "Variable Keyword";
                default: 
                    return "Not a Keyword";
            }
        }
        virtual ComponentType type(){ return ComponentType::Operator;}
        virtual KeywordType operatorType(){ return KeywordType::Unknown;}
        virtual VariableKeywordType variableKeywordType(){ return VariableKeywordType::Unknown;}
        virtual std::string inspect() { assert(0); }
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
};
