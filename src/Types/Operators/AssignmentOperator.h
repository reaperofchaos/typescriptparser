#pragma once
#include <string>
#include "Operator.h"
#include "../CharType.h"
#include "../Symbol.h"

class EqualAssignmentOperator;
class IncrementAssignmentOperator;
class DecrementAssignmentOperator;
class ProductAssignmentOperator;
class DivisionAssignmentOperator;
class ModulusAssignmentOperator;
class ExponentAssignmentOperator;


class AssignmentOperator: public Operator{
    private: 
        std::string value; 
    public:
        AssignmentOperator(std::shared_ptr<Symbol> value): Operator(value)
        {
            this->value = value->getValue();
        }
        
        virtual std::string getAssignmentOperatorTypeAsString(AssignmentOperatorType type){
            switch (type)
            {
                case AssignmentOperatorType::EqualAssignmentOperator:
                    return "Equal Assignment Operator";
                case AssignmentOperatorType::IncrementAssignmentOperator:
                    return "Increment Assignment Operator";
                case AssignmentOperatorType::DecrementAssignmentOperator:
                    return "Decrement Assignment Operator";
                case AssignmentOperatorType::ProductAssignmentOperator:
                    return "Product Assignment Operator";
                case AssignmentOperatorType::DivisionAssignmentOperator:
                    return "Division Assignment Operator";
                case AssignmentOperatorType::ModulusAssignmentOperator:
                    return "Modulus Assignment Operator";
                case AssignmentOperatorType::ExponentAssignmentOperator:
                    return "Exponent Assignment Operator";
                default: 
                    return "Unknown"; 
            }
        }
        virtual AssignmentOperatorType assignmentOperatorType(){ return AssignmentOperatorType::Unknown;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getAssignmentOperatorTypeAsString(this->assignmentOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};


class EqualAssignmentOperator: public AssignmentOperator{
    private:
        std::string value; 
    public:
        EqualAssignmentOperator(std::shared_ptr<EqualSymbol> equal): AssignmentOperator(std::dynamic_pointer_cast<Symbol>(equal))
        {
            this->value = equal->getValue();
        }
        virtual AssignmentOperatorType assignmentOperatorType(){ return AssignmentOperatorType::Unknown;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getAssignmentOperatorTypeAsString(this->assignmentOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};


