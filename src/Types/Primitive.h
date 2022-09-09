#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <cassert>
#include "Component.h"

class ObjectPair; 

enum class PrimitiveType
{
    Primitive,
    StringPrimitive, 
    NumberPrimitive,
    BooleanPrimitive,
    ArrayPrimitive,
    ObjectPrimitive,
};

class Primitive{
    private:
        std::string name;
        std::string value;

    public:
        Primitive(){};
        virtual ~Primitive() = default;
        virtual std::string getTypeAsString(PrimitiveType type){
            switch (type)
            {
                case PrimitiveType::StringPrimitive:
                    return "String";
                case PrimitiveType::NumberPrimitive:
                    return "Number";
                case PrimitiveType::BooleanPrimitive:
                    return "Boolean";
                case PrimitiveType::ArrayPrimitive:
                    return "Array";
                case PrimitiveType::ObjectPrimitive:
                    return "Object";
                default: 
                    return "Unknown";
            }
        }
        
        virtual PrimitiveType type(){ return PrimitiveType::Primitive;}
        virtual std::string inspect() { assert(0); }
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
};

class StringPrimitive: public Primitive{
    private:
        std::string name;
        std::string value;

    public:
        StringPrimitive(std::shared_ptr<StringType> text): Primitive()
        {
            this->name = text->getValue();
            this->value = text->getValue();
        }

        StringPrimitive(std::vector<std::shared_ptr<Component>> characters): Primitive()
        {
            std::string value = ""; 
            for(std::shared_ptr<Component> character : characters)
            {
                value += character->getValue(); 
            }
            this->name = value; 
            this->value = value;
        }
        virtual PrimitiveType type(){ return PrimitiveType::StringPrimitive;}
        virtual std::string inspect() { return this->getType() + " - " + this->getValue(); }
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
};

class NumberPrimitive: public Primitive{
    private:
        std::string name;
        std::string value;

    public:
        NumberPrimitive(std::shared_ptr<NumberType> number): Primitive()
        {
            this->name = number->getValue();
            this->value = number->getValue();
        }

        virtual PrimitiveType type(){ return PrimitiveType::NumberPrimitive;}
        virtual std::string inspect() { return this->getType() + " - " + this->getValue(); }
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){ return this->getTypeAsString(this->type());}
};

class BooleanPrimitive: public Primitive
{
    private:
        std::string name; 
        std::string value;

    public:
        BooleanPrimitive(std::shared_ptr<Name> name): Primitive()
        {
            this->name = name->getValue();
            this->value = "true";
        }

        BooleanPrimitive(std::shared_ptr<Name> name, 
            std::shared_ptr<Name> value ): Primitive()
        {
            
            this->name = name->getValue();
            if(value->getValue() == "true" || 
                value->getValue() =="True" ||
                value->getValue() == "TRUE")
            {
                this->value = "true";
            }else{
                this->value = "false"; 
            }
        }
        virtual PrimitiveType type(){ return PrimitiveType::BooleanPrimitive;}
        virtual std::string inspect() { return this->getType() + " - " + this->getValue(); }
        virtual std::string getValue(){ return value;}
        bool getValueAsBool(){ 
            if(this->value == "true"){
                return true; 
            }
            return false;
        }
        virtual std::string getType(){return this->getTypeAsString(this->type());}
};

class ObjectPrimitive: public Primitive
{
    private:
        std::string name; 
        std::string value; 
        std::vector<std::shared_ptr<ObjectPair>> pairs;

    public:
        ObjectPrimitive(std::vector<std::shared_ptr<ObjectPair>> pairs): Primitive()
        {
            this->name = "object"; 
            this->pairs = pairs;
        }

        virtual PrimitiveType type(){ return PrimitiveType::ObjectPrimitive;}
        virtual std::string inspect() { return this->getType() + " - " + std::to_string(this->getKeyCount()) + " keys."; }
        virtual int getKeyCount(){ return this->pairs.size();}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
};

class ArrayPrimitive: public Primitive
{
    private:
        std::string name; 
        std::string value; 
        std::vector<std::shared_ptr<Primitive>> primitives;

    public:
        ArrayPrimitive(std::vector<std::shared_ptr<Primitive>> primitives): Primitive()
        {
            this->name = "object"; 
            this->primitives = primitives;
        }

        virtual PrimitiveType type(){ return PrimitiveType::ArrayPrimitive;}
        virtual std::string inspect() { return this->getType() + " - " + std::to_string(this->getElements()) + " elements."; }
        virtual int getElements(){ return this->primitives.size();}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
};

class ObjectPair{
    private:
        std::string key; 
        std::shared_ptr<Primitive> value; 

    public:
        ObjectPair(std::shared_ptr<Name> key, std::shared_ptr<Primitive> value)
        {
            this->value = value;
            this->key = key->getValue(); 
        }
        virtual ~ObjectPair() = default;

        virtual std::string type(){ return "Object Pair";}
        virtual std::string getType(){ return "Object Pair";}
        virtual std::shared_ptr<Primitive> getValue(){return value; }
        virtual std::string inspect() { return this->getType() + " - " + this->getValue()->inspect(); }
};
