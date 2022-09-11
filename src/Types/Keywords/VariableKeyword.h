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
        LetKeyWord(std::vector<std::shared_ptr<Lowercase>> letters): VariableKeyword(letters)
        {
            std::string value = ""; 
            for(std::shared_ptr<Lowercase> letter: letters){
                value += letter->getValue(); 
            }
            this->value = value;
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
        VarKeyWord(std::vector<std::shared_ptr<Lowercase>> letters): VariableKeyword(letters)
        {
            std::string value = ""; 
            for(std::shared_ptr<Lowercase> letter: letters){
                value += letter->getValue(); 
            }
            this->value = value;
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
        ConstKeyWord(std::vector<std::shared_ptr<Lowercase>> letters): VariableKeyword(letters)
        {
            std::string value = ""; 
            for(std::shared_ptr<Lowercase> letter: letters){
                value += letter->getValue(); 
            }
            this->value = value;
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
        EnumKeyWord(std::vector<std::shared_ptr<Lowercase>> letters): VariableKeyword(letters)
        {
            std::string value = ""; 
            for(std::shared_ptr<Lowercase> letter: letters){
                value += letter->getValue(); 
            }
            this->value = value;
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
        InterfaceKeyWord(std::vector<std::shared_ptr<Lowercase>> letters): VariableKeyword(letters)
        {
            std::string value = ""; 
            for(std::shared_ptr<Lowercase> letter: letters){
                value += letter->getValue(); 
            }
            this->value = value;
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
        FunctionKeyWord(std::vector<std::shared_ptr<Lowercase>> letters): VariableKeyword(letters)
        {
            std::string value = ""; 
            for(std::shared_ptr<Lowercase> letter: letters){
                value += letter->getValue(); 
            }
            this->value = value;
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
        ClassKeyWord(std::vector<std::shared_ptr<Lowercase>> letters): VariableKeyword(letters)
        {
            std::string value = ""; 
            for(std::shared_ptr<Lowercase> letter: letters){
                value += letter->getValue(); 
            }
            this->value = value;
        }
        virtual VariableKeywordType variableKeywordType(){ return VariableKeywordType::ClassKeyWord;}
        virtual std::string getValue(){ return value;}
        virtual std::string getVariableKeywordType(){return this->getVariableKeywordTypeAsString(this->variableKeywordType());}
        virtual std::string inspect(){ return "Type " + getVariableKeywordType() + " - " + getValue();}
};