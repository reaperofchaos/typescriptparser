#ifndef SYMBOL_H
#define SYMBOL_H
#pragma once
#include <string>
#include <iostream>
#include <cassert>
#include "CharType.h"

class Symbol;
class Colon;
class Comma;
class OpenBracket;
class CloseBracket;
class ArrayOpenBracket;
class ArrayCloseBracket;
class ObjectOpenBracket;
class ObjectCloseBracket;
class Exclamation;
class Dash;
class QuestionMark;
class EscapedSingleQuote;
class EscapedQuote;
class Quote;
class SingleQuote;
class Underscore;
class Semicolon;
class Percentage;
class HashTag;
class OpenParenthesis;
class CloseParenthesis;
class AndSymbol;
class TemplateLiteralSymbol;
class PeriodSymbol;
class CaratSymbol;
class AsteriskSymbol;
class PlusSymbol;
class AtSymbol;
class PipeSymbol;
class MoneySymbol;
class TildeSymbol;

class Symbol: public Character{
    private: 
        std::string value; 
    public:
        Symbol(std::string value){
            this->value = value;

        }
        
        virtual std::string getSymbolTypeAsString(SymbolType type){
            switch (type)
            {
                case SymbolType::NotASymbol:
                    return "Not a symbol";
                case SymbolType::Quote:
                    return "Quote";
                case SymbolType::SingleQuote:
                    return "Single Quote";
                case SymbolType::EscapedQuote:
                    return "Escaped Quote"; 
                case SymbolType::EscapedSingleQuote:
                    return "Escaped Single Quote";
                case SymbolType::Colon:
                    return "Colon";
                case SymbolType::Comma:
                    return "Comma";
                case SymbolType::Semicolon:
                    return "Semicolon";
                case SymbolType::OpenBracket:
                    return "Open Bracket";
                case SymbolType::CloseBracket:
                    return "Close Bracket"; 
                case SymbolType::ObjectOpenBracket:
                    return "Object Open Bracket"; 
                case SymbolType::ObjectCloseBracket:
                    return "Object Close Bracket"; 
                case SymbolType::ArrayOpenBracket:
                    return "Array Open Bracket"; 
                case SymbolType::ArrayCloseBracket:
                    return "Array Close Bracket"; 
                case SymbolType::Exclamation:
                    return "Exclamation";
                case SymbolType::Dash:
                    return "Dash";
                case SymbolType::QuestionMark:
                    return "Question Mark"; 
                case SymbolType::ForwardSlash:
                    return "Forward Slash"; 
                case SymbolType::ClosingCloseTag:
                    return "Closing close tag";
                case SymbolType::EqualSymbol:
                    return "Equal symbol";
                case SymbolType::Underscore:
                    return "Underscore";
                case SymbolType::Percentage:
                    return "Percentage";
                case SymbolType::HashTag:
                    return "Hash Tag";
                case SymbolType::OpenParenthesis:
                    return "Open Parenthesis";
                case SymbolType::CloseParenthesis:
                    return "Close Parenthesis";
                case SymbolType::AndSymbol:
                    return "And Symbol"; 
                case SymbolType::TemplateLiteralSymbol:
                    return "Template Literal symbol";
                case SymbolType::PeriodSymbol:
                    return "Period Symbol";
                case SymbolType::CaratSymbol:
                    return "Carat Symbol";
                case SymbolType::AsteriskSymbol:
                    return "Asterisk Symbol";
                case SymbolType::PlusSymbol:
                    return "Plus Symbol";
                case SymbolType::AtSymbol:
                    return "At Symbol";
                case SymbolType::MoneySymbol:
                    return "Money Symbol";
                case SymbolType::PipeSymbol:
                    return "Pipe Symbol";
                case SymbolType::TildeSymbol:
                    return "Tilde Symbol";
                default: 
                    return "Unknown"; 
            }
        }
        virtual CharacterType type(){ return CharacterType::Symbol;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};
class Quote: public Symbol{
    private:
        std::string value; 
    public:
        Quote(std::string value): Symbol(value){
            this->value = value;
        }
        virtual SymbolType symbolType(){ return SymbolType::Quote;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class ObjectOpenBracket: public Symbol{
    private:
        std::string value;

    public:
        ObjectOpenBracket(std::string value): Symbol(value){
            this->value = value; 
        }

        virtual SymbolType symbolType(){ return SymbolType::ObjectOpenBracket;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}

};
class ObjectCloseBracket: public Symbol{
    private:
        std::string value;

    public:
        ObjectCloseBracket(std::string value): Symbol(value){
            this->value = value;
        }

        virtual SymbolType symbolType(){ return SymbolType::ObjectCloseBracket;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}

};
class ArrayOpenBracket: public Symbol{
    private:
        std::string value;

    public:
        ArrayOpenBracket(std::string value): Symbol(value){
            this->value = value; 
        }

        virtual SymbolType symbolType(){ return SymbolType::ArrayOpenBracket;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class ArrayCloseBracket: public Symbol{
    private:
        std::string value;

    public:
        ArrayCloseBracket(std::string value): Symbol(value){
            this->value = value;
        }

        virtual SymbolType symbolType(){ return SymbolType::ArrayCloseBracket;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class OpenBracket: public Symbol{
    private:
        std::string value;

    public:
        OpenBracket(std::string value): Symbol(value){
            this->value = value;
        }

        virtual SymbolType symbolType(){ return SymbolType::OpenBracket;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class CloseBracket: public Symbol{
    private:
        std::string value;

    public:
        CloseBracket(std::string value): Symbol(value){
            this->value = value; 
        }

        virtual SymbolType symbolType(){ return SymbolType::CloseBracket;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class Colon: public Symbol{
    private:
        std::string value;

    public:
        Colon(std::string value): Symbol(value){
            this->value = value;
        }

        virtual SymbolType symbolType(){ return SymbolType::Colon;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class HashTag: public Symbol{
    private:
        std::string value;

    public:
        HashTag(std::string value): Symbol(value){
            this->value = value;
        }

        virtual SymbolType symbolType(){ return SymbolType::HashTag;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class Comma: public Symbol{
    private:
        std::string value;

    public:
        Comma(std::string value): Symbol(value){
            this->value = value;
        }

        virtual SymbolType symbolType(){ return SymbolType::Comma;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class Semicolon: public Symbol{
    private:
        std::string value;

    public:
        Semicolon(std::string value): Symbol(value){
            this->value = value;
        }

        virtual SymbolType symbolType(){ return SymbolType::Semicolon;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class Exclamation: public Symbol{
    private:
        std::string value;

    public:
        Exclamation(std::string value): Symbol(value){
            this->value = value;
        }

        virtual SymbolType symbolType(){ return SymbolType::Exclamation;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class Dash: public Symbol{
    private:
        std::string value;

    public:
        Dash(std::string value): Symbol(value){
            this->value = value;
        }

        virtual SymbolType symbolType(){ return SymbolType::Dash;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class QuestionMark: public Symbol{
    private:
        std::string value;

    public:
        QuestionMark(std::string value): Symbol(value){
            this->value = value;
        }

        virtual SymbolType symbolType(){ return SymbolType::QuestionMark;}
        std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class EscapedQuote: public Symbol{
    private:
        std::string value;
    public:
        EscapedQuote(std::string value): Symbol(value){
            this->value = value; 
        }
        virtual SymbolType symbolType(){ return SymbolType::EscapedQuote;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class SingleQuote: public Symbol{
    private:
        std::string value; 
    public:
        SingleQuote(std::string value): Symbol(value){
            this->value = value;
        }
        virtual SymbolType symbolType(){ return SymbolType::SingleQuote;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}

};

class EscapedSingleQuote: public Symbol{
    private:
        std::string value;

    public:
        EscapedSingleQuote(std::string value): Symbol(value){
            this->value = value;
        }
        virtual SymbolType symbolType(){ return SymbolType::EscapedSingleQuote;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class ForwardSlash: public Symbol{
    private:
        std::string value;

    public:
        ForwardSlash(std::string value): Symbol(value){
            this->value = value;
        }
        virtual SymbolType symbolType(){ return SymbolType::ForwardSlash;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class Percentage: public Symbol{
    private:
        std::string value;

    public:
        Percentage(std::string value): Symbol(value){
            this->value = value;
        }
        virtual SymbolType symbolType(){ return SymbolType::Percentage;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class EqualSymbol: public Symbol{
    private:
        std::string value;

    public:
        EqualSymbol(std::string value): Symbol(value){
            this->value = value;
        }
        virtual SymbolType symbolType(){ return SymbolType::EqualSymbol;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class Underscore: public Symbol{
    private:
        std::string value;

    public:
        Underscore(std::string value): Symbol(value){
            this->value = value;
        }
        virtual SymbolType symbolType(){ return SymbolType::Underscore;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class OpenParenthesis: public Symbol{
    private:
        std::string value;

    public:
        OpenParenthesis(std::string value): Symbol(value){
            this->value = value;
        }
        virtual SymbolType symbolType(){ return SymbolType::OpenParenthesis;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class CloseParenthesis: public Symbol{
    private:
        std::string value;

    public:
        CloseParenthesis(std::string value): Symbol(value){
            this->value = value;
        }
        virtual SymbolType symbolType(){ return SymbolType::CloseParenthesis;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class AndSymbol: public Symbol{
    private:
        std::string value;

    public:
        AndSymbol(std::string value): Symbol(value){
            this->value = value;
        }
        virtual SymbolType symbolType(){ return SymbolType::AndSymbol;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class TemplateLiteralSymbol: public Symbol{
    private:
        std::string value;

    public:
        TemplateLiteralSymbol(std::string value): Symbol(value){
            this->value = value;
        }
        virtual SymbolType symbolType(){ return SymbolType::TemplateLiteralSymbol;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class CaratSymbol: public Symbol{
    private:
        std::string value;

    public:
        CaratSymbol(std::string value): Symbol(value){
            this->value = value;
        }
        virtual SymbolType symbolType(){ return SymbolType::CaratSymbol;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class PeriodSymbol: public Symbol{
    private:
        std::string value;

    public:
        PeriodSymbol(std::string value): Symbol(value){
            this->value = value;
        }
        virtual SymbolType symbolType(){ return SymbolType::PeriodSymbol;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class AsteriskSymbol: public Symbol{
    private:
        std::string value;

    public:
        AsteriskSymbol(std::string value): Symbol(value){
            this->value = value;
        }
        virtual SymbolType symbolType(){ return SymbolType::AsteriskSymbol;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class PlusSymbol: public Symbol{
    private:
        std::string value;

    public:
        PlusSymbol(std::string value): Symbol(value){
            this->value = value;
        }
        virtual SymbolType symbolType(){ return SymbolType::PlusSymbol;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class AtSymbol: public Symbol{
    private:
        std::string value;

    public:
        AtSymbol(std::string value): Symbol(value){
            this->value = value;
        }
        virtual SymbolType symbolType(){ return SymbolType::AtSymbol;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class PipeSymbol: public Symbol{
    private:
        std::string value;

    public:
        PipeSymbol(std::string value): Symbol(value){
            this->value = value;
        }
        virtual SymbolType symbolType(){ return SymbolType::PipeSymbol;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};


class TildeSymbol: public Symbol{
    private:
        std::string value;

    public:
        TildeSymbol(std::string value): Symbol(value){
            this->value = value;
        }
        virtual SymbolType symbolType(){ return SymbolType::TildeSymbol;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class MoneySymbol: public Symbol{
    private:
        std::string value;

    public:
        MoneySymbol(std::string value): Symbol(value){
            this->value = value;
        }
        virtual SymbolType symbolType(){ return SymbolType::MoneySymbol;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getSymbolTypeAsString(this->symbolType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};
#endif
