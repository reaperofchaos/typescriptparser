#pragma once
#include <string>
#include "Keyword.h"
#include "../Component.h"
#include "../CharType.h"

class ContainerKeyword: public Keyword
{
    private:
        std::string value;
    public:
        ContainerKeyword(std::vector<std::shared_ptr<Lowercase>> letters): Keyword(letters)
        {
            std::string value = ""; 
            for(std::shared_ptr<Lowercase> letter: letters){
                value += letter->getValue(); 
            }
            this->value = value;
        }
        
        virtual ~ContainerKeyword() = default;
        virtual std::string getContainerKeywordAsString(ContainerKeywordType type);
        virtual KeywordType keywordType(){ return KeywordType::ContainerKeyword;}
        virtual ContainerKeywordType containerKeywordType(){ return ContainerKeywordType::Unknown;}
        virtual std::string inspect() { assert(0); }
        virtual std::string getValue(){ return value;}
        virtual std::string getKeywordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string getContainerKeywordType(){return this->getContainerKeywordAsString(this->containerKeywordType());}
};

class ArrayKeyword: public ContainerKeyword{
    private:
        std::string value; 
    public:
        ArrayKeyword(std::vector<std::shared_ptr<Lowercase>> letters): ContainerKeyword(letters)
        {
            std::string value = ""; 
            for(std::shared_ptr<Lowercase> letter: letters){
                value += letter->getValue(); 
            }
            this->value = value;
        }
        virtual ContainerKeywordType containerKeywordType(){ return ContainerKeywordType::ArrayKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getContainerKeywordType(){return this->getContainerKeywordAsString(this->containerKeywordType());}
        virtual std::string inspect(){ return "Type " + getContainerKeywordType() + " - " + getValue();}
};

class MapKeyword: public ContainerKeyword{
    private:
        std::string value; 
    public:
        MapKeyword(std::vector<std::shared_ptr<Lowercase>> letters): ContainerKeyword(letters)
        {
            std::string value = ""; 
            for(std::shared_ptr<Lowercase> letter: letters){
                value += letter->getValue(); 
            }
            this->value = value;
        }
        virtual ContainerKeywordType containerKeywordType(){ return ContainerKeywordType::MapKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getContainerKeywordType(){return this->getContainerKeywordAsString(this->containerKeywordType());}
        virtual std::string inspect(){ return "Type " + getContainerKeywordType() + " - " + getValue();}
};

class SetKeyword: public ContainerKeyword{
    private:
        std::string value; 
    public:
        SetKeyword(std::vector<std::shared_ptr<Lowercase>> letters): ContainerKeyword(letters)
        {
            std::string value = ""; 
            for(std::shared_ptr<Lowercase> letter: letters){
                value += letter->getValue(); 
            }
            this->value = value;
        }
        virtual ContainerKeywordType containerKeywordType(){ return ContainerKeywordType::SetKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getContainerKeywordType(){return this->getContainerKeywordAsString(this->containerKeywordType());}
        virtual std::string inspect(){ return "Type " + getContainerKeywordType() + " - " + getValue();}
};

class ObjectKeyword: public ContainerKeyword{
    private:
        std::string value; 
    public:
        ObjectKeyword(std::vector<std::shared_ptr<Lowercase>> letters): ContainerKeyword(letters)
        {
            std::string value = ""; 
            for(std::shared_ptr<Lowercase> letter: letters){
                value += letter->getValue(); 
            }
            this->value = value;
        }
        virtual ContainerKeywordType containerKeywordType(){ return ContainerKeywordType::ObjectKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getContainerKeywordType(){return this->getContainerKeywordAsString(this->containerKeywordType());}
        virtual std::string inspect(){ return "Type " + getContainerKeywordType() + " - " + getValue();}
};