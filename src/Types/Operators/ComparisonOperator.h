#pragma once
#include <string>
#include "Operator.h"
#include "../CharType.h"
#include "../Symbol.h"

class EqualOperator;
class StrictEqualOperator;
class NotEqualOperator;
class StrictNotEqualOperator;
class GreaterThanOperator;
class GreaterThanOrEqualOperator;
class LessThanOperator;
class LessThanOrEqualOperator;
class TernaryOperator;
class TernaryNotOperator;

class ComparisonOperator: public Operator{
    private: 
        std::string value; 
    public:
        ComparisonOperator(std::shared_ptr<Symbol> value): Operator(value)
        {
            this->value = value->getValue();
        }

        ComparisonOperator(std::shared_ptr<Symbol> value1, std::shared_ptr<Symbol> value2): 
        Operator(value1, value2)
        {
            this->value = value1->getValue() + value2->getValue();
        }

        ComparisonOperator(std::shared_ptr<Symbol> value1, std::shared_ptr<Symbol> value2, std::shared_ptr<Symbol> value3): Operator(value1, value2, value3)
        {
            this->value = value1->getValue() + value2->getValue() + value3->getValue();
        }
        
        
        virtual std::string getComparisonOperatorTypeAsString(ComparisonOperatorType type){
            switch (type)
            {
                case ComparisonOperatorType::EqualOperator:
                    return "Equal Operator";
                case ComparisonOperatorType::StrictEqualOperator:
                    return "Strict Equal Operator";
                case ComparisonOperatorType::NotEqualOperator:
                    return "Not Equal Operator";
                case ComparisonOperatorType::StrictNotEqualOperator:
                    return "Strict Not Equal Operator";
                case ComparisonOperatorType::GreaterThanOperator:
                    return "Greater Than Operator";   
                case ComparisonOperatorType::GreaterThanOrEqualOperator:
                    return "Greater Than Or Equal Operator";    
                case ComparisonOperatorType::LessThanOperator:
                    return "Less Than Operator";  
                case ComparisonOperatorType::LessThanOrEqualOperator:
                    return "Less Than Or Equal Operator";  
                case ComparisonOperatorType::TernaryOperator:
                    return "Ternary Operator";           
                case ComparisonOperatorType::TernaryNotOperator:
                    return "Ternary Not Operator"; 
                default: 
                    return "Not a comparison operator"; 
            }
        }
        virtual OperatorType operatorType(){return OperatorType::ComparisonOperator;}
        virtual ComparisonOperatorType comparisonOperatorType(){ return ComparisonOperatorType::Unknown;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getComparisonOperatorTypeAsString(this->comparisonOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class EqualOperator: public ComparisonOperator{
    private:
        std::string value; 
    public:
        EqualOperator(std::shared_ptr<EqualSymbol> equal1, std::shared_ptr<EqualSymbol> equal2): ComparisonOperator(std::dynamic_pointer_cast<Symbol>(equal1), std::dynamic_pointer_cast<Symbol>(equal2))
        {
            this->value = equal1->getValue()+equal2->getValue();
        }
        virtual ComparisonOperatorType comparisonOperatorType(){ return ComparisonOperatorType::EqualOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getComparisonOperatorTypeAsString(this->comparisonOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class StrictEqualOperator: public ComparisonOperator{
    private:
        std::string value; 
    public:
        StrictEqualOperator(std::shared_ptr<EqualSymbol> equal1, std::shared_ptr<EqualSymbol> equal2, std::shared_ptr<EqualSymbol> equal3): ComparisonOperator(std::dynamic_pointer_cast<Symbol>(equal1), std::dynamic_pointer_cast<Symbol>(equal2), std::dynamic_pointer_cast<Symbol>(equal3))
        {
            this->value = equal1->getValue() + equal2->getValue() + equal3->getValue();
        }
        virtual ComparisonOperatorType comparisonOperatorType(){ return ComparisonOperatorType::StrictEqualOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getComparisonOperatorTypeAsString(this->comparisonOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class NotEqualOperator: public ComparisonOperator{
    private:
        std::string value; 
    public:
        NotEqualOperator(std::shared_ptr<Exclamation> exclamation, std::shared_ptr<EqualSymbol> equal): ComparisonOperator(std::dynamic_pointer_cast<Symbol>(exclamation), std::dynamic_pointer_cast<Symbol>(equal))
        {
            this->value = exclamation->getValue() + equal->getValue();
        }
        virtual ComparisonOperatorType comparisonOperatorType(){ return ComparisonOperatorType::NotEqualOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getComparisonOperatorTypeAsString(this->comparisonOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class StrictNotEqualOperator: public ComparisonOperator{
    private:
        std::string value; 
    public:
        StrictNotEqualOperator(std::shared_ptr<Exclamation> exclamation, std::shared_ptr<EqualSymbol> equal1, std::shared_ptr<EqualSymbol> equal2): ComparisonOperator(std::dynamic_pointer_cast<Symbol>(exclamation), std::dynamic_pointer_cast<Symbol>(equal1), std::dynamic_pointer_cast<Symbol>(equal2))
        {
            this->value = exclamation->getValue() + equal1->getValue() + equal2->getValue();
        }
        virtual ComparisonOperatorType comparisonOperatorType(){ return ComparisonOperatorType::StrictNotEqualOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getComparisonOperatorTypeAsString(this->comparisonOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class GreaterThanOperator: public ComparisonOperator{
    private:
        std::string value; 
    public:
        GreaterThanOperator(std::shared_ptr<GreaterThanSymbol> greaterThan): ComparisonOperator(std::dynamic_pointer_cast<Symbol>(greaterThan))
        {
            this->value = greaterThan->getValue();
        }
        virtual ComparisonOperatorType comparisonOperatorType(){ return ComparisonOperatorType::GreaterThanOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getComparisonOperatorTypeAsString(this->comparisonOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class GreaterThanOrEqualOperator: public ComparisonOperator{
    private:
        std::string value; 
    public:
        GreaterThanOrEqualOperator(std::shared_ptr<GreaterThanSymbol> greaterThan, std::shared_ptr<EqualSymbol> equal): ComparisonOperator(std::dynamic_pointer_cast<Symbol>(greaterThan), std::dynamic_pointer_cast<Symbol>(equal))
        {
            this->value = greaterThan->getValue() + equal->getValue();
        }
        virtual ComparisonOperatorType comparisonOperatorType(){ return ComparisonOperatorType::GreaterThanOrEqualOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getComparisonOperatorTypeAsString(this->comparisonOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class LessThanOperator: public ComparisonOperator{
    private:
        std::string value; 
    public:
        LessThanOperator(std::shared_ptr<LessThanSymbol> lessThan): ComparisonOperator(std::dynamic_pointer_cast<Symbol>(lessThan))
        {
            this->value = lessThan->getValue();
        }
        virtual ComparisonOperatorType comparisonOperatorType(){ return ComparisonOperatorType::LessThanOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getComparisonOperatorTypeAsString(this->comparisonOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class LessThanOrEqualOperator: public ComparisonOperator{
    private:
        std::string value; 
    public:
        LessThanOrEqualOperator(std::shared_ptr<LessThanSymbol> lessThan, std::shared_ptr<EqualSymbol> equal): ComparisonOperator(std::dynamic_pointer_cast<Symbol>(lessThan), std::dynamic_pointer_cast<Symbol>(equal))
        {
            this->value = lessThan->getValue() + equal->getValue();
        }
        virtual ComparisonOperatorType comparisonOperatorType(){ return ComparisonOperatorType::LessThanOrEqualOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getComparisonOperatorTypeAsString(this->comparisonOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class TernaryOperator: public ComparisonOperator{
    private:
        std::string value; 
    public:
        TernaryOperator(std::shared_ptr<QuestionMark> questionMark): ComparisonOperator(std::dynamic_pointer_cast<Symbol>(questionMark))
        {
            this->value = questionMark->getValue();
        }
        virtual ComparisonOperatorType comparisonOperatorType(){ return ComparisonOperatorType::TernaryOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getComparisonOperatorTypeAsString(this->comparisonOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class TernaryNotOperator: public ComparisonOperator{
    private:
        std::string value; 
    public:
        TernaryNotOperator(std::shared_ptr<Colon> colon): ComparisonOperator(std::dynamic_pointer_cast<Symbol>(colon))
        {
            this->value = colon->getValue();
        }
        virtual ComparisonOperatorType comparisonOperatorType(){ return ComparisonOperatorType::TernaryNotOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getComparisonOperatorTypeAsString(this->comparisonOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};