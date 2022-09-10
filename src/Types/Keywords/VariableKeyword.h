#pragma once
#include <string>
#include "Keyword.h"
#include "../Component.h"
#include "../CharType.h"

class VariableKeyword: public Keyword
{
    private:
        std::string value;
    public:
        VariableKeyword(std::vector<std::shared_ptr<Lowercase>> letters): Keyword(letters)
        {
            std::string value = ""; 
            for(std::shared_ptr<Lowercase> letter: letters){
                value += letter->getValue(); 
            }
            this->value = value;
        }
        
        virtual ~VariableKeyword() = default;
        virtual std::string getVariableKeywordTypeAsString(VariableKeywordType type){
            switch (type)
            {
                case VariableKeywordType::LetWord:
                    return "Let";
                case VariableKeywordType::VarWord:
                    return "Var";
                case VariableKeywordType::ConstWord:
                    return "Const";
                default: 
                    return "Not a variable Keyword";
            }
        }
        virtual ComponentType type(){ return ComponentType::Operator;}
        virtual KeywordType operatorType(){ return KeywordType::VariableKeyword;}
        virtual VariableKeywordType variableKeywordType(){ return VariableKeywordType::Unknown;}
        virtual std::string inspect() { assert(0); }
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
};

class LetWord: public VariableKeyword{
    private:
        std::string value; 
    public:
        LetWord(std::vector<std::shared_ptr<Lowercase>> letters): VariableKeyword(letters)
        {
            std::string value = ""; 
            for(std::shared_ptr<Lowercase> letter: letters){
                value += letter->getValue(); 
            }
            this->value = value;
        }
        virtual VariableKeywordType variableKeywordType(){ return VariableKeywordType::LetWord;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getVariableKeywordTypeAsString(this->variableKeywordType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class VarWord: public VariableKeyword{
    private:
        std::string value; 
    public:
        VarWord(std::vector<std::shared_ptr<Lowercase>> letters): VariableKeyword(letters)
        {
            std::string value = ""; 
            for(std::shared_ptr<Lowercase> letter: letters){
                value += letter->getValue(); 
            }
            this->value = value;
        }
        virtual VariableKeywordType variableKeywordType(){ return VariableKeywordType::VarWord;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getVariableKeywordTypeAsString(this->variableKeywordType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class ConstWord: public VariableKeyword{
    private:
        std::string value; 
    public:
        ConstWord(std::vector<std::shared_ptr<Lowercase>> letters): VariableKeyword(letters)
        {
            std::string value = ""; 
            for(std::shared_ptr<Lowercase> letter: letters){
                value += letter->getValue(); 
            }
            this->value = value;
        }
        virtual VariableKeywordType variableKeywordType(){ return VariableKeywordType::ConstWord;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getVariableKeywordTypeAsString(this->variableKeywordType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};