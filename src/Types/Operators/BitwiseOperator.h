#pragma once
#include <string>
#include "Operator.h"
#include "../CharType.h"
#include "../Symbol.h"

class BitAndOperator;
class BitOrOperator;
class BitNotOperator;
class BitXOROperator;
class BitLeftShiftOperator;
class BitRightShiftOperator;
class BitUnsignedRightOperator;

class BitwiseOperator: public Operator{
    private: 
        std::string value; 
    public:
        BitwiseOperator(std::shared_ptr<Symbol> value): Operator(value)
        {
            this->value = value->getValue();
        }

        BitwiseOperator(std::shared_ptr<Symbol> value1, std::shared_ptr<Symbol> value2): 
        Operator(value1, value2)
        {
            this->value = value1->getValue() + value2->getValue();
        }

        BitwiseOperator(std::shared_ptr<Symbol> value1, std::shared_ptr<Symbol> value2, std::shared_ptr<Symbol> value3): Operator(value1, value2, value3)
        {
            this->value = value1->getValue() + value2->getValue() + value3->getValue();
        }
        
        
        virtual std::string getBitwiseOperatorTypeAsString(BitwiseOperatorType type){
            switch (type)
            {
                case BitwiseOperatorType::BitAndOperator:
                    return "Bitwise And Operator";
                case BitwiseOperatorType::BitOrOperator:
                    return "Bitwise Or Operator";
                case BitwiseOperatorType::BitNotOperator:
                    return "Bitwise Not Operator";
                case BitwiseOperatorType::BitXOROperator:
                    return "Bitwise XOR Operator";
                case BitwiseOperatorType::BitLeftShiftOperator:
                    return "Bitwise Left Shift Operator";
                case BitwiseOperatorType::BitRightShiftOperator:
                    return "Bitwise Right Shift Operator";
                case BitwiseOperatorType::BitUnsignedRightOperator:
                    return "Bitwise Unsigned Right Shift Operator";
                default: 
                    return "Not a bitwise operator"; 
            }
        }
        virtual OperatorType operatorType(){return OperatorType::BitwiseOperator;}
        virtual BitwiseOperatorType bitwiseOperatorType(){ return BitwiseOperatorType::Unknown;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getBitwiseOperatorTypeAsString(this->bitwiseOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class BitAndOperator: public BitwiseOperator{
    private:
        std::string value; 
    public:
        BitAndOperator(std::shared_ptr<AndSymbol> andSymbol): BitwiseOperator(std::dynamic_pointer_cast<Symbol>(andSymbol))
        {
            this->value = andSymbol->getValue();
        }
        virtual BitwiseOperatorType bitwiseOperatorType(){ return BitwiseOperatorType::BitAndOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getBitwiseOperatorTypeAsString(this->bitwiseOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class BitOrOperator: public BitwiseOperator{
    private:
        std::string value; 
    public:
        BitOrOperator(std::shared_ptr<TildeSymbol> pipe): BitwiseOperator(std::dynamic_pointer_cast<Symbol>(pipe))
        {
            this->value = pipe->getValue();
        }
        virtual BitwiseOperatorType bitwiseOperatorType(){ return BitwiseOperatorType::BitOrOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getBitwiseOperatorTypeAsString(this->bitwiseOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class BitNotOperator: public BitwiseOperator{
    private:
        std::string value; 
    public:
        BitNotOperator(std::shared_ptr<TildeSymbol> tilde): BitwiseOperator(std::dynamic_pointer_cast<Symbol>(tilde))
        {
            this->value = tilde->getValue();
        }
        virtual BitwiseOperatorType bitwiseOperatorType(){ return BitwiseOperatorType::BitNotOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getBitwiseOperatorTypeAsString(this->bitwiseOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class BitXOROperator: public BitwiseOperator{
    private:
        std::string value; 
    public:
        BitXOROperator(std::shared_ptr<CaratSymbol> carat): BitwiseOperator(std::dynamic_pointer_cast<Symbol>(carat))
        {
            this->value = carat->getValue();
        }
        virtual BitwiseOperatorType bitwiseOperatorType(){ return BitwiseOperatorType::BitXOROperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getBitwiseOperatorTypeAsString(this->bitwiseOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class BitLeftShiftOperator: public BitwiseOperator{
    private:
        std::string value; 
    public:
        BitLeftShiftOperator(std::shared_ptr<LessThanSymbol> lessThan1, std::shared_ptr<LessThanSymbol> lessThan2): BitwiseOperator(std::dynamic_pointer_cast<Symbol>(lessThan1), std::dynamic_pointer_cast<Symbol>(lessThan2))
        {
            this->value = lessThan1->getValue() + lessThan2->getValue();
        }
        virtual BitwiseOperatorType bitwiseOperatorType(){ return BitwiseOperatorType::BitLeftShiftOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getBitwiseOperatorTypeAsString(this->bitwiseOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class BitRightShiftOperator: public BitwiseOperator{
    private:
        std::string value; 
    public:
        BitRightShiftOperator(std::shared_ptr<GreaterThanSymbol> greaterThan1, std::shared_ptr<GreaterThanSymbol> greaterThan2): BitwiseOperator(std::dynamic_pointer_cast<Symbol>(greaterThan1), std::dynamic_pointer_cast<Symbol>(greaterThan2))
        {
            this->value = greaterThan1->getValue() + greaterThan2->getValue();
        }
        virtual BitwiseOperatorType bitwiseOperatorType(){ return BitwiseOperatorType::BitRightShiftOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getBitwiseOperatorTypeAsString(this->bitwiseOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class BitUnsignedRightOperator: public BitwiseOperator{
    private:
        std::string value; 
    public:
        BitUnsignedRightOperator(std::shared_ptr<GreaterThanSymbol> greaterThan1, std::shared_ptr<GreaterThanSymbol> greaterThan2, std::shared_ptr<GreaterThanSymbol> greaterThan3): BitwiseOperator(std::dynamic_pointer_cast<Symbol>(greaterThan1), std::dynamic_pointer_cast<Symbol>(greaterThan2), std::dynamic_pointer_cast<Symbol>(greaterThan3))
        {
            this->value = greaterThan1->getValue() + greaterThan2->getValue();
        }
        virtual BitwiseOperatorType bitwiseOperatorType(){ return BitwiseOperatorType::BitRightShiftOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getBitwiseOperatorTypeAsString(this->bitwiseOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};