#pragma once
#include <string>
#include "../Component.h"
enum class OperatorType
{
    AssignmentOperator,
    ArithmeticOperator,
    ComparisonOperator, 
    LogicalOperator,
    BitwiseOperator,
    OtherOperator,
    Unknown,
};

enum class AssignmentOperatorType
{
    EqualAssignmentOperator, // =
    IncrementAssignmentOperator, // +=
    DecrementAssignmentOperator, // -=
    ProductAssignmentOperator, // *=
    DivisionAssignmentOperator, // /=
    ModulusAssignmentOperator, // %=
    ExponentAssignmentOperator, // **=
    Unknown
};

enum class ArithmeticOperatorType
{
    AdditionOperator, // +
    SubtractionOperator, // -
    MultiplicationOperator, // *
    ExponentOperator, // *
    DivisionOperator, // /
    ModulusOperator, // %
    IncrementOperator, // ++
    DecrementOperator, // --
    Unknown
};

enum class ComparisonOperatorType
{
    EqualOperator, // ==
    StrictEqualOperator, // ===
    NotEqualOperator, // !=
    StrictNotEqualOperator, // !==
    GreaterThanOperator, // >
    GreaterThanOrEqualOperator, // >=
    LessThanOperator, // <
    LessThanOrEqualOperator, // <==
    TernaryOperator, // ?
    TernaryNotOperator, // :
    Unknown
};

enum class OtherOperatorType
{
    MethodOperator, // .
    SpreadOperator, // ...
    NullCoalescingOperator, // ??
    Unknown
};

enum class LogicalOperatorType
{
    LogicalAndOperator, // &&
    LogicalOrOperator, // ||
    LogicalNotOperator, // !
    Unknown
};

enum class BitwiseOperatorType
{
    BitAndOperator, // &
    BitOrOperator, // |
    BitNotOperator, // ~
    BitXOROperator, // ^
    BitLeftShiftOperator, // <<
    BitRightShiftOperator, // >>
    BitUnsignedRightOperator, // >>>
    Unknown
};

class Operator: public Component
{
    private:
        std::string value;
    public:
        Operator(std::shared_ptr<Symbol> value)
        {
            this->value = value->getValue();
        }
        Operator(
            std::shared_ptr<Symbol> value1,
            std::shared_ptr<Symbol> value2)
        {
            this->value = value1->getValue() + value2->getValue();
        }

        Operator(
            std::shared_ptr<Symbol> value1,
            std::shared_ptr<Symbol> value2, 
            std::shared_ptr<Symbol> value3)
        {
            this->value = value1->getValue() + value2->getValue() + value3->getValue();
        }
        virtual ~Operator() = default;
        virtual std::string getOperatorTypeAsString(OperatorType type){
            switch (type)
            {
                case OperatorType::AssignmentOperator:
                    return "Assignment Operator";
                case OperatorType::ArithmeticOperator:
                    return "Arithmetic Operator";
                case OperatorType::ComparisonOperator:
                    return "Comparison Operator";
                case OperatorType::LogicalOperator:
                    return "Logical Operator";
                case OperatorType::BitwiseOperator:
                    return "Bitwise Operator";
                case OperatorType::OtherOperator:
                    return "Misc Operator";
                default: 
                    return "Not an operator";
            }
        }
        virtual ComponentType type(){ return ComponentType::Operator;}
        virtual OperatorType operatorType(){ return OperatorType::Unknown;}
        virtual AssignmentOperatorType assignmentOperatorType(){ return AssignmentOperatorType::Unknown;}
        virtual ArithmeticOperatorType arithmeticOperatorType(){ return ArithmeticOperatorType::Unknown;}
        virtual ComparisonOperatorType comparisonOperatorType(){ return ComparisonOperatorType::Unknown;}
        virtual LogicalOperatorType logicalOperatorType(){ return LogicalOperatorType::Unknown;}
        virtual BitwiseOperatorType bitwiseOperatorType(){ return BitwiseOperatorType::Unknown;}
        virtual OtherOperatorType otherOperatorType(){ return OtherOperatorType::Unknown;}

        virtual std::string inspect() { assert(0); }
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
};