#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <cassert>
#include "CharType.h"
#include "Symbol.h"

class Component;
class Name;
class StringType;
class ArrayType;
class ObjectType;
class NumberType;
class CloseObject;
class OpenObject;
class ObjectPair;
class OpenArray;
class CloseArray;
class CommaComponent;
class ColonComponent;
class ExclamationComponent;
class QuestionComponent;
class DashComponent;
class WhiteSpaces;
class EqualComponent;
class SemicolonComponent;
class PercentageComponent;
class HashTagComponent;
class OpenParenthesisComponent;
class CloseParenthesisComponent;
class AndComponent;

enum class ComponentType
{
    Name, 
    StringType,
    ArrayType,
    ObjectType,
    NumberType,
    Unknown,
    CloseObject,
    OpenObject,
    OpenArray,
    CloseArray,
    ColonComponent,
    CommaComponent, 
    ExclamationComponent,
    QuestionComponent,
    DashComponent,
    SemicolonComponent,
    WhiteSpaces,
    EqualComponent,
    PercentageComponent,
    HashTagComponent,
    OpenParenthesisComponent,
    CloseParenthesisComponent,
    AndComponent,
};

class Component
{
    private:
        std::string value;
    public:
        virtual ~Component() = default;
        virtual std::string getTypeAsString(ComponentType type){
            switch (type)
            {
                case ComponentType::Name:
                    return "Name";
                case ComponentType::StringType:
                    return "String";
                case ComponentType::NumberType:
                    return "Number";
                case ComponentType::OpenArray:
                    return "Open array";
                case ComponentType::OpenObject:
                    return "Open object";
                case ComponentType::CloseArray:
                    return "Close array";
                case ComponentType::CloseObject:
                    return "Close object";
                case ComponentType::WhiteSpaces:
                    return "White spaces";
                case ComponentType::ExclamationComponent:
                    return "Exclamation";
                case ComponentType::ColonComponent:
                    return "Colon";
                case ComponentType::CommaComponent:
                    return "Comma";
                case ComponentType::SemicolonComponent:
                    return "Semicolon";
                case ComponentType::EqualComponent:
                    return "Equal";
                case ComponentType::DashComponent:
                    return "Dash"; 
                case ComponentType::PercentageComponent:
                    return "Percentage Component";
                case ComponentType::HashTagComponent:
                    return "Hash Tag Component";
                case ComponentType::CloseParenthesisComponent:
                    return "Close Parenthesis";
                case ComponentType::OpenParenthesisComponent:
                    return "Close Parenthesis";
                default: 
                    return "Unknown";
            }
        }
        
        virtual ComponentType type(){ return ComponentType::Unknown;}
        virtual std::string inspect() { assert(0); }
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
};

class StringType: public Component
{
    private:
        std::string value;

    public:
        StringType(std::vector<std::shared_ptr<Character>> characters){
            std::string value = "";
            for(std::shared_ptr<Character> character : characters){
                value += character->getValue(); 
            }
            this->value = value;
            // std::cout << this->inspect() << "\n";
        }

        StringType(std::string value){            
            this->value = value;
        }

        virtual ComponentType type(){ return ComponentType::StringType;}
        std::string getValue(){ return value;}
        virtual void setValue(std::shared_ptr<Quote> q, std::vector<std::shared_ptr<Character>> characters, std::shared_ptr<Quote> q2)
        {
            std::string value = "";
            value += q->getValue();
            for(std::shared_ptr<Character> character : characters){
                value += character->getValue(); 
            }
            value += q2->getValue();
            this->value = value;
        }
        virtual void setValue(std::shared_ptr<SingleQuote> q, std::vector<std::shared_ptr<Character>> characters, std::shared_ptr<SingleQuote> q2)
        {
            std::string value = "";
            value += q->getValue();
            for(std::shared_ptr<Character> character : characters){
                value += character->getValue(); 
            }
            value += q2->getValue();
            this->value = value;
        }
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};



class NumberType: public Component
{
    private:
        std::string value;

    public:
        NumberType(std::vector<std::shared_ptr<Number>> numbers): Component(){
            std::string numberString = "";
            for(std::shared_ptr<Number> number : numbers ){
                numberString += number->getValue(); 
            }
            this->value = numberString;
            // std::cout << this->inspect() << "\n";
        }
        virtual void setValue(std::vector<std::shared_ptr<Number>> numbers)
        {
            std::string numberString = "";
            for(std::shared_ptr<Number> number : numbers ){
                numberString += number->getValue(); 
            }
            this->value = numberString;
        }
        std::string getValue(){ return this->value; }
        virtual ComponentType type(){ return ComponentType::NumberType;}
        int getValueAsNumber(){ return std::stoi(this->value);}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class Name: public Component
{
    private:
        std::string value;

    public:
        Name(std::shared_ptr<Letter> letter, std::vector<std::shared_ptr<Character>> characters){
            std::string value = letter->getValue();
            for(std::shared_ptr<Character> character : characters){
                value += character->getValue();
            }
            this->value = value;
            // std::cout << this->inspect() << "\n";
        }

        virtual ComponentType type(){ return ComponentType::Name;}
        virtual void setValue(std::shared_ptr<Letter> letter, std::vector<std::shared_ptr<Character>> characters)
        {
            std::string value = letter->getValue();
            for(std::shared_ptr<Character> character : characters){
                value += character->getValue();
            }
            this->value = value;
        }
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class OpenObject: public Component
{
    private:
        std::string value;

    public:
        OpenObject(std::shared_ptr<ObjectOpenBracket> openBracket){
            this->value = openBracket->getValue();
        }

        OpenObject(std::shared_ptr<ObjectOpenBracket> openBracket, std::vector<std::shared_ptr<WhiteSpace>> whiteSpaces){
            std::string value = "";
            value += openBracket->getValue();
        
            for(std::shared_ptr<WhiteSpace> whiteSpace : whiteSpaces)
            {
                value += whiteSpace->getValue();
            }
            this->value = value; 
        }

        virtual ComponentType type(){ return ComponentType::OpenObject;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};
class CloseObject: public Component
{
    private:
        std::string value;

    public:
        CloseObject(std::shared_ptr<ObjectCloseBracket> closeBracket){
            this->value = closeBracket->getValue();
        }

        CloseObject(std::vector<std::shared_ptr<WhiteSpace>> whiteSpaces, std::shared_ptr<ObjectCloseBracket> closeBracket){
            std::string value = "";
            for(std::shared_ptr<WhiteSpace> whiteSpace : whiteSpaces)
            {
                value += whiteSpace->getValue();
            }
            value += closeBracket->getValue();
            this->value = value;
        }

        virtual ComponentType type(){ return ComponentType::CloseObject;}
        virtual void setValue(std::shared_ptr<ObjectCloseBracket> closeBracket){this->value = closeBracket->getValue();}
        virtual void setValue(std::vector<std::shared_ptr<WhiteSpace>> whiteSpaces, std::shared_ptr<ObjectCloseBracket> closeBracket)
        {
            std::string value = "";
            for(std::shared_ptr<WhiteSpace> whiteSpace : whiteSpaces)
            {
                value += whiteSpace->getValue();
            }
            value += closeBracket->getValue();
            this->value = value;
        }

        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};
class OpenArray: public Component
{
    private:
        std::string value;

    public:
        OpenArray(std::shared_ptr<ArrayOpenBracket> openBracket){
            this->value = openBracket->getValue();
        }

        OpenArray(std::shared_ptr<ArrayOpenBracket> openBracket, std::vector<std::shared_ptr<WhiteSpace>> whiteSpaces){
            std::string value = "";
            value += openBracket->getValue();

            for(std::shared_ptr<WhiteSpace> whiteSpace : whiteSpaces)
            {
                value += whiteSpace->getValue();
            }
            this->value = value; 
        }

        virtual ComponentType type(){ return ComponentType::OpenArray;}
        virtual void setValue(std::shared_ptr<ArrayOpenBracket> openBracket){
            this->value = openBracket->getValue();
        }
        virtual void setValue(std::shared_ptr<ArrayOpenBracket> openBracket, std::vector<std::shared_ptr<WhiteSpace>> whiteSpaces){
            std::string value = "";
            value += openBracket->getValue();

            for(std::shared_ptr<WhiteSpace> whiteSpace : whiteSpaces)
            {
                value += whiteSpace->getValue();
            }
            this->value = value; 
        }
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class CloseArray: public Component
{
    private:
        std::string value;

    public:
        CloseArray(std::shared_ptr<ArrayCloseBracket> closeBracket){
            this->value = closeBracket->getValue();
        }

        CloseArray(std::vector<std::shared_ptr<WhiteSpace>> whiteSpaces, std::shared_ptr<ArrayCloseBracket> closeBracket){
            std::string value = "";
            for(std::shared_ptr<WhiteSpace> whiteSpace : whiteSpaces)
            {
                value += whiteSpace->getValue();
            }
            value += closeBracket->getValue();
            this->value = value; 
        }

        virtual ComponentType type(){ return ComponentType::CloseArray;}
        std::string getValue(){ return value;}
        virtual void setValue(std::shared_ptr<ArrayCloseBracket> closeBracket){this->value = closeBracket->getValue();}
        virtual void setValue(std::vector<std::shared_ptr<WhiteSpace>> whiteSpaces, std::shared_ptr<ArrayCloseBracket> closeBracket)
        {
            std::string value = "";
            for(std::shared_ptr<WhiteSpace> whiteSpace : whiteSpaces)
            {
                value += whiteSpace->getValue();
            }
            value += closeBracket->getValue();
            this->value = value; 
        }

        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class ColonComponent: public Component
{
    private:
        std::string value;

    public:
        ColonComponent(std::shared_ptr<Colon> colon ){
            this->value = colon->getValue();
        }

        virtual ComponentType type(){ return ComponentType::ColonComponent;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class SemicolonComponent: public Component
{
    private:
        std::string value;

    public:
        SemicolonComponent(std::shared_ptr<Semicolon> semicolon ){
            this->value = semicolon->getValue();
        }

        virtual ComponentType type(){ return ComponentType::SemicolonComponent;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class CommaComponent: public Component
{
    private:
        std::string value;

    public:
        CommaComponent(std::shared_ptr<Comma> comma ){
            this->value = comma->getValue();
        }

        virtual ComponentType type(){ return ComponentType::CommaComponent;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class WhiteSpaces: public Component
{
    private:
        std::string value;

    public:
        WhiteSpaces(std::vector<std::shared_ptr<WhiteSpace>> whiteSpaces ){
            std::string value = "";
            for(auto whiteSpace : whiteSpaces)
            {
                value += whiteSpace->getValue();
            }
            this->value = value;
        }

        virtual ComponentType type(){ return ComponentType::WhiteSpaces;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class ExclamationComponent: public Component
{
    private:
        std::string value;

    public:
        ExclamationComponent(std::shared_ptr<Exclamation> exclamation ){
            this->value = exclamation->getValue();
        }

        virtual ComponentType type(){ return ComponentType::ExclamationComponent;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class EqualComponent: public Component
{
    private:
        std::string value;

    public:
        EqualComponent(std::shared_ptr<EqualSymbol> equal ){
            this->value = equal->getValue();
        }

        virtual ComponentType type(){ return ComponentType::EqualComponent;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class PercentageComponent: public Component
{
    private:
        std::string value;

    public:
        PercentageComponent(std::shared_ptr<Percentage> percentage ){
            this->value = percentage->getValue();
        }

        virtual ComponentType type(){ return ComponentType::PercentageComponent;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class HashTagComponent: public Component
{
    private:
        std::string value;

    public:
        HashTagComponent(std::shared_ptr<HashTag> hashTag ){
            this->value = hashTag->getValue();
        }

        virtual ComponentType type(){ return ComponentType::HashTagComponent;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class DashComponent: public Component
{
    private:
        std::string value;

    public:
        DashComponent(std::shared_ptr<Dash> dash ){
            this->value = dash->getValue();
        }

        virtual ComponentType type(){ return ComponentType::DashComponent;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class AndComponent: public Component
{
    private:
        std::string value;

    public:
        AndComponent(std::shared_ptr<AndSymbol> andSymbol ){
            this->value = andSymbol->getValue();
        }

        virtual ComponentType type(){ return ComponentType::AndComponent;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};
class CloseParenthesisComponent: public Component
{
    private:
        std::string value;

    public:
        CloseParenthesisComponent(std::shared_ptr<CloseParenthesis> closeParenthesis ){
            this->value = closeParenthesis->getValue();
        }

        virtual ComponentType type(){ return ComponentType::CloseParenthesisComponent;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class OpenParenthesisComponent: public Component
{
    private:
        std::string value;

    public:
        OpenParenthesisComponent(std::shared_ptr<OpenParenthesis> openParenthesis ){
            this->value = openParenthesis->getValue();
        }

        virtual ComponentType type(){ return ComponentType::OpenParenthesisComponent;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};