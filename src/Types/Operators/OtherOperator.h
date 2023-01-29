#pragma once
#include <string>
#include "Operator.h"
#include "OtherOperator.h"
#include "../CharType.h"
#include "../Symbol.h"


class OtherOperator: public Operator{
    private: 
        std::string value; 
    public:
        OtherOperator(std::shared_ptr<Symbol> value): Operator(value)
        {
            this->value = value->getValue();
        }

        OtherOperator(
            std::shared_ptr<Symbol> value1, 
            std::shared_ptr<Symbol> value2): 
        Operator(value1, value2)
        {
            this->value = value1->getValue() + value2->getValue();
        }
        
        OtherOperator(
            std::shared_ptr<Symbol> value1,
            std::shared_ptr<Symbol> value2, 
            std::shared_ptr<Symbol> value3): 
        Operator(value1, value2, value3)
        {
            this->value = value1->getValue() + value2->getValue() + value3->getValue();
        }
        
        virtual std::string getOtherOperatorTypeAsString(OtherOperatorType type){
            switch (type)
            {
                case OtherOperatorType::MethodOperator:
                    return "Method Operator";
                case OtherOperatorType::SpreadOperator:
                    return "Spread Operator";
                case OtherOperatorType::NullCoalescingOperator:
                    return "Null Coalescing Operator";
                default: 
                    return "Not a misc operator"; 
            }
        }
        virtual OperatorType operatorType(){return OperatorType::LogicalOperator;}
        virtual OtherOperatorType otherOperatorType(){ return OtherOperatorType::Unknown;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getOtherOperatorTypeAsString(this->otherOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};


class MethodOperator: public OtherOperator{
    private:
        std::string value; 
    public:
        MethodOperator(std::shared_ptr<PeriodSymbol> period1): OtherOperator(
            std::dynamic_pointer_cast<Symbol>(period1))
        {
            this->value = period1->getValue();
        }
        virtual OtherOperatorType otherOperatorType(){ return OtherOperatorType::MethodOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getOtherOperatorTypeAsString(this->otherOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class SpreadOperator: public OtherOperator{
    private:
        std::string value; 
    public:
        SpreadOperator(
            std::shared_ptr<PeriodSymbol> period1,
            std::shared_ptr<PeriodSymbol> period2,
            std::shared_ptr<PeriodSymbol> period3
            ): OtherOperator(
                std::dynamic_pointer_cast<Symbol>(period1),
                std::dynamic_pointer_cast<Symbol>(period2),
                std::dynamic_pointer_cast<Symbol>(period3)
            )
        {
            this->value = period1->getValue() + period2->getValue() + period3->getValue();
        }
        virtual OtherOperatorType otherOperatorType(){ return OtherOperatorType::SpreadOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getOtherOperatorTypeAsString(this->otherOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};

class NullCoalescingOperator: public OtherOperator{
    private:
        std::string value; 
    public:
        NullCoalescingOperator(
            std::shared_ptr<QuestionMark> questionMark1,
            std::shared_ptr<QuestionMark> questionMark2
            ): OtherOperator(
                std::dynamic_pointer_cast<Symbol>(questionMark1),
                std::dynamic_pointer_cast<Symbol>(questionMark2))
        {
            this->value = questionMark1->getValue() + questionMark2->getValue();
        }
        virtual OtherOperatorType otherOperatorType(){ return OtherOperatorType::NullCoalescingOperator;}
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getOtherOperatorTypeAsString(this->otherOperatorType());}
        virtual std::string inspect(){ return "Type " + getType() + " - " + getValue();}
};