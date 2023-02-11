#ifndef WHITESPACE_H
#define WHITESPACE_H
#pragma once
#include <string>
#include <iostream>
#include <cassert>
#include "CharType.h"

class Symbol;
class WhiteSpace;
class ReturnLine;
class NewLine;
class Space;
class Tab; 


class WhiteSpace: public Character{
    private:
        std::string value;

    public:
        WhiteSpace(std::string str){
            this->value = str;
        }

        virtual std::string getWhiteSpaceTypeAsString(WhiteSpaceType type)
        {
            switch (type)
            {
                case WhiteSpaceType::NewLine:
                    return "New Line";
                case WhiteSpaceType::Return:
                    return "Return Type";
                case WhiteSpaceType::Space:
                    return "Space";
                case WhiteSpaceType::Tab:
                    return "Tab";
                case WhiteSpaceType::Unknown:
                default: 
                    return "Unknown"; 
            }
        }

        virtual CharacterType type(){ return CharacterType::WhiteSpace;}
        virtual WhiteSpaceType whiteSpaceType(){return WhiteSpaceType::Unknown;}
        std::string getValue(){ return value;}
        virtual std::string getWhiteSpaceType(){return this->getWhiteSpaceTypeAsString(this->whiteSpaceType());}
        virtual std::string inspect(){ return "Type " + getWhiteSpaceType() + " - " + getValue();}
};

class Space: public WhiteSpace{
    
    private: 
        std::string value; 
    
    public:
        Space(std::string value): WhiteSpace(value)
        {
            this->value = value;
        }
        virtual WhiteSpaceType whiteSpaceType(){ return WhiteSpaceType::Space;}
        virtual std::string getValue(){ return value;}
        virtual std::string getWhiteSpaceType(){return this->getWhiteSpaceTypeAsString(this->whiteSpaceType());}
        virtual std::string inspect(){ return "Type " + getWhiteSpaceType() + " - " + getValue();}
};

class Tab: public WhiteSpace{
    
    private: 
        std::string value; 
    
    public:
        Tab(std::string value): WhiteSpace(value)
        {
            this->value = value;
        }
        
        virtual WhiteSpaceType whiteSpaceType(){ return WhiteSpaceType::Tab;}
        virtual std::string getValue(){ return value;}
        virtual std::string getWhiteSpaceType(){return this->getWhiteSpaceTypeAsString(this->whiteSpaceType());}
        virtual std::string inspect(){ return "Type " + getWhiteSpaceType() + " - " + getValue();}
};

class NewLine: public WhiteSpace{
    
    private: 
        std::string value; 
    
    public:
        NewLine(std::string value): WhiteSpace(value)
        {
            this->value = value;
        }
        
        virtual WhiteSpaceType whiteSpaceType(){ return WhiteSpaceType::NewLine;}
        virtual std::string getValue(){ return value;}
        virtual std::string getWhiteSpaceType(){return this->getWhiteSpaceTypeAsString(this->whiteSpaceType());}
        virtual std::string inspect(){ return "Type " + getWhiteSpaceType() + " - " + getValue();}
};

class ReturnLine: public WhiteSpace{
    
    private: 
        std::string value; 

    public:
        ReturnLine(std::string value): WhiteSpace(value)
        {
            this->value = value;
        }
        
        virtual WhiteSpaceType whiteSpaceType(){ return WhiteSpaceType::Return;}
        virtual std::string getValue(){ return value;}
        virtual std::string getWhiteSpaceType(){return this->getWhiteSpaceTypeAsString(this->whiteSpaceType());}
        virtual std::string inspect(){ return "Type " + getWhiteSpaceType() + " - " + getValue();}
};

#endif