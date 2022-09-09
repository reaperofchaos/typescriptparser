#pragma once
#include <string>
#include "Operator.h"
#include "../CharType.h"
#include "../Symbol.h"

class LogicalAndOperator;
class LogicalOrOperator;
class LogicalNotOperator;

class LogicalOperator: public Operator{
    private: 
        std::string value; 
    public:
        LogicalOperator(std::shared_ptr<Symbol> value): Operator(value)
        {
            this->value = value->getValue();
        }

        LogicalOperator(std::shared_ptr<Symbol> value1, std::shared_ptr<Symbol> value2): 
        Operator(value1, value2)
        {
            this->value = value1->getValue() + value2->getValue();
        }
        
        virtual std::string getLogicalOperatorTypeAsString(LogicalOperatorType type){
            switch (type)
            {
                case LogicalOperatorType::LogicalAndOperator:
                    return "Logical And Operator";
                case LogicalOperatorType::LogicalOrOperator:
                    return "Logical Or Operator";
                case LogicalOperatorType::LogicalNotOperator:
                    return "Logical Not Operator";
                default: 
                    return "Not an arithmetic operator"; 
            }
        }
        virtual OperatorType operatorType(){return OperatorType::LogicalOperator;}
        virtual LogicalOperatorType logicalOperatorType(){ return LogicalOperatorType::Unknown;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getLogicalOperatorTypeAsString(this->logicalOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};


class LogicalAndOperator: public LogicalOperator{
    private:
        std::string value; 
    public:
        LogicalAndOperator(std::shared_ptr<AndSymbol> and1, std::shared_ptr<AndSymbol> and2): LogicalOperator(std::dynamic_pointer_cast<Symbol>(and1), std::dynamic_pointer_cast<Symbol>(and2))
        {
            this->value = and1->getValue() + and2->getValue();
        }
        virtual LogicalOperatorType logicalOperatorType(){ return LogicalOperatorType::LogicalAndOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getLogicalOperatorTypeAsString(this->logicalOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class LogicalOrOperator: public LogicalOperator{
    private:
        std::string value; 
    public:
        LogicalOrOperator(std::shared_ptr<PipeSymbol> pipe1, std::shared_ptr<PipeSymbol> pipe2): LogicalOperator(std::dynamic_pointer_cast<Symbol>(pipe1), std::dynamic_pointer_cast<Symbol>(pipe2))
        {
            this->value = pipe1->getValue() + pipe2->getValue();
        }
        virtual LogicalOperatorType logicalOperatorType(){ return LogicalOperatorType::LogicalAndOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getLogicalOperatorTypeAsString(this->logicalOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class LogicalNotOperator: public LogicalOperator{
    private:
        std::string value; 
    public:
        LogicalNotOperator(std::shared_ptr<Exclamation> exclamation): LogicalOperator(std::dynamic_pointer_cast<Symbol>(exclamation))
        {
            this->value = exclamation->getValue();
        }
        virtual LogicalOperatorType logicalOperatorType(){ return LogicalOperatorType::LogicalNotOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getLogicalOperatorTypeAsString(this->logicalOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};