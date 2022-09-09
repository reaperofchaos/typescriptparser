#pragma once
#include <string>
#include "Operator.h"
#include "../CharType.h"
#include "../Symbol.h"

class AdditionOperator;
class SubtractionOperator;
class MultiplicationOperator;
class ExponentOperator;
class DivisionOperator;
class ModulusOperator;
class IncrementOperator;
class DecrementOperator;

class ArithmeticOperator: public Operator{
    private: 
        std::string value; 
    public:
        ArithmeticOperator(std::shared_ptr<Symbol> value): Operator(value)
        {
            this->value = value->getValue();
        }

        ArithmeticOperator(std::shared_ptr<Symbol> value1, std::shared_ptr<Symbol> value2): 
        Operator(value1, value2)
        {
            this->value = value1->getValue() + value2->getValue();
        }
        
        virtual std::string getArithmeticOperatorTypeAsString(ArithmeticOperatorType type){
            switch (type)
            {
                case ArithmeticOperatorType::AdditionOperator:
                    return "Addition Operator";
                case ArithmeticOperatorType::SubtractionOperator:
                    return "Subtraction Operator";
                case ArithmeticOperatorType::MultiplicationOperator:
                    return "Multiplication Operator";
                case ArithmeticOperatorType::ExponentOperator:
                    return "Exponent Operator";
                case ArithmeticOperatorType::DivisionOperator:
                    return "Division Operator";
                case ArithmeticOperatorType::ModulusOperator:
                    return "Modulus Operator";
                case ArithmeticOperatorType::IncrementOperator:
                    return "Increment Operator";
                case ArithmeticOperatorType::DecrementOperator:
                    return "Decrement Operator";
                default: 
                    return "Unknown"; 
            }
        }
        virtual OperatorType operatorType(){return OperatorType::ArithmeticOperator;}
        virtual ArithmeticOperatorType arithmeticOperatorType(){ return ArithmeticOperatorType::Unknown;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getArithmeticOperatorTypeAsString(this->arithmeticOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class AdditionOperator: public ArithmeticOperator{
    private:
        std::string value; 
    public:
        AdditionOperator(std::shared_ptr<PlusSymbol> plus): ArithmeticOperator(std::dynamic_pointer_cast<Symbol>(plus))
        {
            this->value = plus->getValue();
        }
        virtual ArithmeticOperatorType arithmeticOperatorType(){ return ArithmeticOperatorType::AdditionOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getArithmeticOperatorTypeAsString(this->arithmeticOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class SubtractionOperator: public ArithmeticOperator{
    private:
        std::string value; 
    public:
        SubtractionOperator(std::shared_ptr<Dash> minus): ArithmeticOperator(std::dynamic_pointer_cast<Symbol>(minus))
        {
            this->value = minus->getValue();
        }
        virtual ArithmeticOperatorType arithmeticOperatorType(){ return ArithmeticOperatorType::SubtractionOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getArithmeticOperatorTypeAsString(this->arithmeticOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class MultiplicationOperator: public ArithmeticOperator{
    private:
        std::string value; 
    public:
        MultiplicationOperator(std::shared_ptr<AsteriskSymbol> asterisk): ArithmeticOperator(std::dynamic_pointer_cast<Symbol>(asterisk))
        {
            this->value = asterisk->getValue();
        }
        virtual ArithmeticOperatorType arithmeticOperatorType(){ return ArithmeticOperatorType::MultiplicationOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getArithmeticOperatorTypeAsString(this->arithmeticOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class DivisionOperator: public ArithmeticOperator{
    private:
        std::string value; 
    public:
        DivisionOperator(std::shared_ptr<ForwardSlash> division): ArithmeticOperator(std::dynamic_pointer_cast<Symbol>(division))
        {
            this->value = division->getValue();
        }
        virtual ArithmeticOperatorType arithmeticOperatorType(){ return ArithmeticOperatorType::DivisionOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getArithmeticOperatorTypeAsString(this->arithmeticOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class ExponentOperator: public ArithmeticOperator{
    private:
        std::string value; 
    public:
        ExponentOperator(std::shared_ptr<AsteriskSymbol> asterisk1, std::shared_ptr<AsteriskSymbol> asterisk2): ArithmeticOperator(std::dynamic_pointer_cast<Symbol>(asterisk1), std::dynamic_pointer_cast<Symbol>(asterisk2))
        {
            this->value = asterisk1->getValue() + asterisk2->getValue();
        }
        virtual ArithmeticOperatorType arithmeticOperatorType(){ return ArithmeticOperatorType::ExponentOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getArithmeticOperatorTypeAsString(this->arithmeticOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class ModulusOperator: public ArithmeticOperator{
    private:
        std::string value; 
    public:
        ModulusOperator(std::shared_ptr<Percentage> percentage): ArithmeticOperator(std::dynamic_pointer_cast<Symbol>(percentage))
        {
            this->value = percentage->getValue();
        }
        virtual ArithmeticOperatorType arithmeticOperatorType(){ return ArithmeticOperatorType::ModulusOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getArithmeticOperatorTypeAsString(this->arithmeticOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class IncrementOperator: public ArithmeticOperator{
    private:
        std::string value; 
    public:
        IncrementOperator(std::shared_ptr<PlusSymbol> plus1, std::shared_ptr<PlusSymbol> plus2): ArithmeticOperator(std::dynamic_pointer_cast<Symbol>(plus1), std::dynamic_pointer_cast<Symbol>(plus2))
        {
            this->value = plus1->getValue() + plus2->getValue();
        }
        virtual ArithmeticOperatorType arithmeticOperatorType(){ return ArithmeticOperatorType::IncrementOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getArithmeticOperatorTypeAsString(this->arithmeticOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class DecrementOperator: public ArithmeticOperator{
    private:
        std::string value; 
    public:
        DecrementOperator(std::shared_ptr<Dash> minus1, std::shared_ptr<Dash> minus2): ArithmeticOperator(std::dynamic_pointer_cast<Symbol>(minus1), std::dynamic_pointer_cast<Symbol>(minus2))
        {
            this->value = minus1->getValue() + minus2->getValue();
        }
        virtual ArithmeticOperatorType arithmeticOperatorType(){ return ArithmeticOperatorType::DecrementOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getArithmeticOperatorTypeAsString(this->arithmeticOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};