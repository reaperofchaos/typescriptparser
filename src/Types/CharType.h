#ifndef CHARTYPE_H
#define CHARTYPE_H
#pragma once
#include <string>
#include <iostream>
#include <cassert>

class Character;
class Number; 
class Letter; 
class Lowercase;
class Uppercase; 
class UnicodeCharacter; 
class UnknownCharacter;

enum class CharacterType
{
    Character,
    WhiteSpace,
    Number,
    Letter,
    Lowercase,
    Uppercase,
    Symbol,
    UnicodeCharacter,
    Unknown,
};

enum class WhiteSpaceType
{
    Return,
    NewLine, 
    Space, 
    Tab, 
    Unknown
};

enum class SymbolType
{
    NotASymbol,
    Symbol,
    Quote,
    SingleQuote,
    EscapedQuote,
    EscapedSingleQuote,
    Colon,
    Comma,
    LessThanSymbol,
    GreaterThanSymbol,
    LeftCurlyBracket,
    RightCurlyBracket,
    LeftSquareBracket,
    RightSquareBracket,
    Exclamation,
    Dash,
    Underscore,
    QuestionMark,
    ForwardSlash,
    EqualSymbol,
    Semicolon,
    Percentage,
    HashTag,
    LeftParenthesis,
    RightParenthesis,
    AndSymbol,
    GraveAccent,
    PeriodSymbol,
    CaratSymbol,
    AsteriskSymbol,
    PlusSymbol,
    AtSymbol,
    PipeSymbol,
    MoneySymbol,
    TildeSymbol
};
class Character{
    private:
        std::string value;

    public: 
        virtual ~Character() = default;
        virtual std::string getTypeAsString(CharacterType type){
            switch (type)
            {
                case CharacterType::Character:
                    return "Character Type";
                case CharacterType::WhiteSpace:
                    return "White space";
                case CharacterType::Number:
                    return "Number Type";
                case CharacterType::Letter:
                    return "Letter"; 
                case CharacterType::Lowercase:
                    return "Lowercase Letter";
                case CharacterType::Uppercase:
                    return "Uppercase Letter"; 
                case CharacterType::Symbol:
                    return "Symbol";
                case CharacterType::UnicodeCharacter:
                    return "Unicode Character"; 
                default: 
                    return "Unknown"; 
            }
        }

        virtual CharacterType type(){ return CharacterType::Character;}
        virtual SymbolType symbolType(){ return SymbolType::NotASymbol;}
        virtual WhiteSpaceType whiteSpaceType(){return WhiteSpaceType::Unknown;}
        virtual std::string inspect() { assert(0); }
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
};

class Number: public Character{
    private: 
        std::string value; 
    public:
        Number(std::string value){
            this->value = value;
        }

        virtual CharacterType type(){ return CharacterType::Number;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};



class Letter: public Character{
    private:
        std::string value; 

    public:
        Letter(std::string value)
        {
            this->value = value; 
        }
        
        virtual CharacterType type(){ return CharacterType::Letter;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class Lowercase: public Letter{
    private: 
        std::string value; 
    public:
        Lowercase(std::string value): Letter(value){
            this->value = value;
        }
        virtual CharacterType type(){ return CharacterType::Lowercase;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + this->getType() + " - " + this->getValue();}
};

class Uppercase: public Letter{
    private:
        std::string value;
    public:
        Uppercase(std::string value): Letter(value){
            this->value = value; 
        }
        virtual CharacterType type(){ return CharacterType::Uppercase;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class UnicodeCharacter: public Character{
    private: 
        std::string value;
    public:
        UnicodeCharacter(std::string value){
            this->value = value;
        }
        virtual CharacterType type(){ return CharacterType::UnicodeCharacter;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}

};

class UnknownCharacter: public Character{
    private: 
        std::string value;
    public:
        UnknownCharacter(std::string value){
            this->value = value;
        }
        virtual CharacterType type(){ return CharacterType::Unknown;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

#endif