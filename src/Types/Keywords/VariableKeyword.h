#pragma once
#include <string>
#include "Keyword.h"
#include "../Component.h"
#include "Tokenizer/Types/CharType.h"

class VariableKeyword: public Keyword
{
    private:
        std::string value;
    public:
        VariableKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        
        virtual ~VariableKeyword() = default;
        virtual std::string getVariableKeywordTypeAsString(VariableKeywordType type);
        virtual KeywordType keywordType(){ return KeywordType::VariableKeyword;}
        virtual VariableKeywordType variableKeywordType(){ return VariableKeywordType::Unknown;}
        virtual std::string inspect() { assert(0); }
        virtual std::string getValue(){ return value;}
        virtual std::string getKeywordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string getVariableKeywordType(){return this->getVariableKeywordTypeAsString(this->variableKeywordType());}
};

class LetKeyWord: public VariableKeyword{
    private:
        std::string value; 
    public:
        LetKeyWord(std::string letters): VariableKeyword(letters)
        {
            this->value = letters;
        }
        virtual VariableKeywordType variableKeywordType(){ return VariableKeywordType::LetKeyWord;}
        virtual std::string getValue(){ return value;}
        virtual std::string getVariableKeywordType(){return this->getVariableKeywordTypeAsString(this->variableKeywordType());}
        virtual std::string inspect(){ return "Type " + getVariableKeywordType() + " - " + getValue();}
};

class VarKeyWord: public VariableKeyword{
    private:
        std::string value; 
    public:
        VarKeyWord(std::string letters): VariableKeyword(letters)
        {
            this->value = letters;
        }
        virtual VariableKeywordType variableKeywordType(){ return VariableKeywordType::VarKeyWord;}
        virtual std::string getValue(){ return value;}
        virtual std::string getVariableKeywordType(){return this->getVariableKeywordTypeAsString(this->variableKeywordType());}
        virtual std::string inspect(){ return "Type " + getVariableKeywordType() + " - " + getValue();}
};

class ConstKeyWord: public VariableKeyword{
    private:
        std::string value; 
    public:
        ConstKeyWord(std::string letters): VariableKeyword(letters)
        {
            this->value = letters;
        }
        virtual VariableKeywordType variableKeywordType(){ return VariableKeywordType::ConstKeyWord;}
        virtual std::string getValue(){ return value;}
        virtual std::string getVariableKeywordType(){return this->getVariableKeywordTypeAsString(this->variableKeywordType());}
        virtual std::string inspect(){ return "Type " + getVariableKeywordType() + " - " + getValue();}
};

class EnumKeyWord: public VariableKeyword{
    private:
        std::string value; 
    public:
        EnumKeyWord(std::string letters): VariableKeyword(letters)
        {
            this->value = letters;
        }
        virtual VariableKeywordType variableKeywordType(){ return VariableKeywordType::EnumKeyWord;}
        virtual std::string getValue(){ return value;}
        virtual std::string getVariableKeywordType(){return this->getVariableKeywordTypeAsString(this->variableKeywordType());}
        virtual std::string inspect(){ return "Type " + getVariableKeywordType() + " - " + getValue();}
};

class InterfaceKeyWord: public VariableKeyword{
    private:
        std::string value; 
    public:
        InterfaceKeyWord(std::string letters): VariableKeyword(letters)
        {
            this->value = letters;
        }
        virtual VariableKeywordType variableKeywordType(){ return VariableKeywordType::InterfaceKeyWord;}
        virtual std::string getValue(){ return value;}
        virtual std::string getVariableKeywordType(){return this->getVariableKeywordTypeAsString(this->variableKeywordType());}
        virtual std::string inspect(){ return "Type " + getVariableKeywordType() + " - " + getValue();}
};

class FunctionKeyWord: public VariableKeyword{
    private:
        std::string value; 
    public:
        FunctionKeyWord(std::string letters): VariableKeyword(letters)
        {
            this->value = letters;
        }
        virtual VariableKeywordType variableKeywordType(){ return VariableKeywordType::FunctionKeyWord;}
        virtual std::string getValue(){ return value;}
        virtual std::string getVariableKeywordType(){return this->getVariableKeywordTypeAsString(this->variableKeywordType());}
        virtual std::string inspect(){ return "Type " + getVariableKeywordType() + " - " + getValue();}
};

class ClassKeyWord: public VariableKeyword{
    private:
        std::string value; 
    public:
        ClassKeyWord(std::string letters): VariableKeyword(letters)
        {
            this->value = letters;
        }
        virtual VariableKeywordType variableKeywordType(){ return VariableKeywordType::ClassKeyWord;}
        virtual std::string getValue(){ return value;}
        virtual std::string getVariableKeywordType(){return this->getVariableKeywordTypeAsString(this->variableKeywordType());}
        virtual std::string inspect(){ return "Type " + getVariableKeywordType() + " - " + getValue();}
};