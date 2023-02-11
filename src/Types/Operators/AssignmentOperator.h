#pragma once
#include <string>
#include "Operator.h"
#include "Tokenizer/Types/CharType.h"
#include "Tokenizer/Types/Symbol.h"

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

        AssignmentOperator(
            std::shared_ptr<Symbol> value1,
            std::shared_ptr<Symbol> value2
            ): Operator(value1, value2)
        {
            this->value = value1->getValue() + value2->getValue();
        }

        AssignmentOperator(
            std::shared_ptr<Symbol> value1,
            std::shared_ptr<Symbol> value2, 
            std::shared_ptr<Symbol> value3
            ): Operator(value1, value2, value3)
        {
            this->value = value1->getValue() + value2->getValue() + value3->getValue();
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
                    return "Not an assignment operator"; 
            }
        }
        virtual OperatorType operatorType(){return OperatorType::AssignmentOperator;}
        virtual AssignmentOperatorType assignmentOperatorType(){ return AssignmentOperatorType::Unknown;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getAssignmentOperatorTypeAsString(this->assignmentOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class EqualAssignmentOperator: public AssignmentOperator{
    private:
        std::string value; 
    public:
        EqualAssignmentOperator(
            std::shared_ptr<EqualSymbol> equal
            ): AssignmentOperator(
                std::dynamic_pointer_cast<Symbol>(equal))
        {
            this->value = equal->getValue();
        }
        virtual AssignmentOperatorType assignmentOperatorType(){ return AssignmentOperatorType::EqualAssignmentOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getAssignmentOperatorTypeAsString(this->assignmentOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class IncrementAssignmentOperator: public AssignmentOperator{
    private:
        std::string value; 
    public:
        IncrementAssignmentOperator(
            std::shared_ptr<PlusSymbol> plus,
            std::shared_ptr<EqualSymbol> equal
            ): AssignmentOperator(
                std::dynamic_pointer_cast<Symbol>(plus),
                std::dynamic_pointer_cast<Symbol>(equal))
        {
            this->value = plus->getValue() + equal->getValue();
        }
        virtual AssignmentOperatorType assignmentOperatorType(){ return AssignmentOperatorType::IncrementAssignmentOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getAssignmentOperatorTypeAsString(this->assignmentOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class DecrementAssignmentOperator: public AssignmentOperator{
    private:
        std::string value; 
    public:
        DecrementAssignmentOperator(std::shared_ptr<Dash> minus, std::shared_ptr<EqualSymbol> equal): AssignmentOperator(std::dynamic_pointer_cast<Symbol>(minus), std::dynamic_pointer_cast<Symbol>(equal))
        {
            this->value = minus->getValue() + equal->getValue();
        }
        virtual AssignmentOperatorType assignmentOperatorType(){ return AssignmentOperatorType::DecrementAssignmentOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getAssignmentOperatorTypeAsString(this->assignmentOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class ProductAssignmentOperator: public AssignmentOperator{
    private:
        std::string value; 
    public:
        ProductAssignmentOperator(std::shared_ptr<AsteriskSymbol> product, std::shared_ptr<EqualSymbol> equal): AssignmentOperator(std::dynamic_pointer_cast<Symbol>(product), std::dynamic_pointer_cast<Symbol>(equal))
        {
            this->value = product->getValue() + equal->getValue();
        }
        virtual AssignmentOperatorType assignmentOperatorType(){ return AssignmentOperatorType::ProductAssignmentOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getAssignmentOperatorTypeAsString(this->assignmentOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class DivisionAssignmentOperator: public AssignmentOperator{
    private:
        std::string value; 
    public:
        DivisionAssignmentOperator(std::shared_ptr<ForwardSlash> division, std::shared_ptr<EqualSymbol> equal): AssignmentOperator(std::dynamic_pointer_cast<Symbol>(division), std::dynamic_pointer_cast<Symbol>(equal))
        {
            this->value = division->getValue() + equal->getValue();
        }
        virtual AssignmentOperatorType assignmentOperatorType(){ return AssignmentOperatorType::DivisionAssignmentOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getAssignmentOperatorTypeAsString(this->assignmentOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class ModulusAssignmentOperator: public AssignmentOperator{
    private:
        std::string value; 
    public:
        ModulusAssignmentOperator(std::shared_ptr<Percentage> modulus, std::shared_ptr<EqualSymbol> equal): AssignmentOperator(std::dynamic_pointer_cast<Symbol>(modulus), std::dynamic_pointer_cast<Symbol>(equal))
        {
            this->value = modulus->getValue() + equal->getValue();
        }
        virtual AssignmentOperatorType assignmentOperatorType(){ return AssignmentOperatorType::ModulusAssignmentOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getAssignmentOperatorTypeAsString(this->assignmentOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class ExponentAssignmentOperator: public AssignmentOperator{
    private:
        std::string value; 
    public:
        ExponentAssignmentOperator(std::shared_ptr<AsteriskSymbol> asterisk1, std::shared_ptr<AsteriskSymbol> asterisk2, std::shared_ptr<EqualSymbol> equal): AssignmentOperator(std::dynamic_pointer_cast<Symbol>(asterisk1), std::dynamic_pointer_cast<Symbol>(asterisk2), std::dynamic_pointer_cast<Symbol>(equal))
        {
            this->value = asterisk1->getValue() + asterisk2->getValue() + equal->getValue();
        }
        virtual AssignmentOperatorType assignmentOperatorType(){ return AssignmentOperatorType::ExponentAssignmentOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getAssignmentOperatorTypeAsString(this->assignmentOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};