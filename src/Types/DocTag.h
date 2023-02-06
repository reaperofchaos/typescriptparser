#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <cassert>

class DocTag;
class RemarkTag;
class ParamTag;
class ReturnTag;
class ExampleTag;

enum class DocTagType
{
    Summary,
    Remark,
    Param,
    Return,
    Example,
    Unknown
};

class DocTag
{
    private:
        std::string value;
    public:
        virtual ~DocTag() = default;
        virtual std::string getTypeAsString(DocTagType type);
        virtual DocTagType type(){ return DocTagType::Unknown;}
        virtual std::string inspect() { assert(0); }
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
};

class SummaryTag: public DocTag
{
    private:
        std::string value;

    public:
        SummaryTag(std::vector<std::string> lines){
            for(std::string line : lines){
                this->value += line + "\n";
            }
        }

        virtual DocTagType type(){ return DocTagType::Summary;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class RemarkTag: public DocTag
{
    private:
        std::string value;

    public:
        RemarkTag(std::vector<std::string> lines){
            for(std::string line : lines){
                this->value += line + "\n";
            }
        }

        virtual DocTagType type(){ return DocTagType::Remark;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class ParamTag: public DocTag
{
    private:
        std::string paramType;
        std::string typeDescription;

    public:
        ParamTag(std::string type, std::string typeDescription){
            this->paramType = type;
            this->typeDescription = typeDescription;
        }

        virtual DocTagType type(){ return DocTagType::Param;}
        std::string getParamType(){ return this->paramType;}
        std::string getTypeDescription(){ return this->typeDescription;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class ReturnTag: public DocTag
{
    private:
        std::string returnType;
        std::string typeDescription;

    public:
        ReturnTag(std::string type, std::string typeDescription ){
            this->returnType = type;
            this->typeDescription = typeDescription;
        }

        virtual DocTagType type(){ return DocTagType::Return;}
        std::string getReturnType(){ return this->returnType;}
        std::string getTypeDescription(){ return this->typeDescription;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};


class ExampleTag: public DocTag
{
    private:
        std::string value;

    public:
        ExampleTag(std::string value){
            this->value = value;
        }

        virtual DocTagType type(){ return DocTagType::Example;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};
