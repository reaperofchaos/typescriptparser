#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <cassert>
#include "Component.h"
enum class ElementType
{
    Element,
    DocumentTag, 
    Tag,
    NestedObject,
    NestedString,
};

class Element
{
    private:
        std::string value;
        std::string tagString;
    public:
        Element(){};
        virtual ~Element() = default;
        virtual std::string getTypeAsString(ElementType type){
            switch (type)
            {
                case ElementType::DocumentTag:
                    return "Document tag";
                case ElementType::Tag:
                    return "Tag";
                case ElementType::NestedObject:
                    return "Nested object";
                case ElementType::NestedString:
                    return "Nested string";
                default: 
                    return "Unknown";
            }
        }
        
        virtual ElementType type(){ return ElementType::Element;}
        virtual std::string inspect() { assert(0); }
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
};

class NestedString: public Element
{
    private:
        std::string value;

    public: 
        NestedString(std::shared_ptr<StringType> stringValue)
        {
            this->value = stringValue->getValue(); 
        }
        virtual ElementType type(){ return ElementType::NestedString;}
        virtual std::string inspect() { std::string text = this->getType() + " - " + this->getValue() +"\n";
        return text;  }
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
};

class NestedObject: public Element{
    private:
        std::string value;

    public: 
        NestedObject(std::shared_ptr<StringType> stringValue)
        {
            this->value = stringValue->getValue(); 
        }
        virtual ElementType type(){ return ElementType::NestedObject;}
        virtual std::string inspect() { std::string text = this->getType() + " - " + this->getValue() +"\n";
        return text;  }
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
};