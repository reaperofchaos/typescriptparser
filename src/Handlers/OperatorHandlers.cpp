#include "OperatorHandlers.h"


std::shared_ptr<Component> OperatorHandlers::buildOperator(
    std::vector<std::shared_ptr<Character>> &m_tokens, 
    size_t &m_index, 
    size_t &start)
    {   
        switch(m_tokens[start]->type())
        {
            std::cout << "start: " << m_tokens[start]->inspect() << "\n";
            std::cout << "m_index: " << m_tokens[m_index]->inspect() << "\n";
            std::cout << "m_index + 1: " << m_tokens[m_index + 1]->inspect() << "\n";
            m_index = start; 
            case CharacterType::Symbol:
                switch(m_tokens[m_index]->symbolType())
                {
                    std::cout << "operator symbol -start: " << m_tokens[start]->inspect() << "\n";
                    std::cout << "operator symbol - m_index: " << m_tokens[m_index]->inspect() << "\n";
                    std::cout << "operator symbol - m_index + 1: " << m_tokens[m_index + 1]->inspect() << "\n";

                    case SymbolType::EqualSymbol:
                        CharacterUtilities::IncrementIndex(m_tokens, m_index);
                        CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);
                        switch(m_tokens[m_index]->symbolType()){
                            case SymbolType::EqualSymbol:
                                if(m_index + 1 < m_tokens.size() -1 && m_tokens[m_index+1]->symbolType() == SymbolType::EqualSymbol){
                                    CharacterUtilities::IncrementIndex(m_tokens, m_index);
                                    // ===  ComparisonOperatorType   -   StrictEqualOperator
                                    return ComparisonOperatorHandlers::buildStrictEqualOperator(m_tokens, m_index, start);
                                }
                                    // ==  ComparisonOperatorType   -   EqualOperator
                                    return ComparisonOperatorHandlers::buildEqualOperator(m_tokens, m_index, start);
                            default:
                                // =   AssignmentOperatorHandlers -     EqualAssignmentOperator
                                return AssignmentOperatorHandlers::buildEqualAssignmentOperator(m_tokens, m_index, start);
                        }
                        // =   AssignmentOperatorHandlers -     EqualAssignmentOperator
                        return AssignmentOperatorHandlers::buildEqualAssignmentOperator(m_tokens, m_index, start);
                    case SymbolType::PlusSymbol:
                        CharacterUtilities::IncrementIndex(m_tokens, m_index);
                        CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);
                        switch(m_tokens[m_index]->symbolType()){
                            // && LogicalOperatorType -     LogicalAndOperator
                            case SymbolType::AndSymbol: //+=
                                return AssignmentOperatorHandlers::buildIncrementAssignmentOperator(m_tokens, m_index, start);
                            // ++    ArithmeticOperatorType -    IncrementOperator
                            case SymbolType::PlusSymbol:
                                return ArithmeticOperatorHandlers::buildIncrementOperator(m_tokens, m_index, start);

                            default: 
                                return ArithmeticOperatorHandlers::buildAdditionOperator(m_tokens, m_index, start);
                        }
                        // +    ArithmeticOperatorType -    AdditionOperator
                        return ArithmeticOperatorHandlers::buildAdditionOperator(m_tokens, m_index, start);
                    case SymbolType::Dash:
                        CharacterUtilities::IncrementIndex(m_tokens, m_index);
                        CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);
                        switch(m_tokens[m_index]->symbolType()){
                            // -=   AssignmentOperatorHandlers -     DecrementAssignmentOperator
                            case SymbolType::EqualSymbol: 
                                return AssignmentOperatorHandlers::buildDecrementAssignmentOperator(m_tokens, m_index, start);
                            // --    ArithmeticOperatorType -    DecrementOperator
                            case SymbolType::Dash:
                                return ArithmeticOperatorHandlers::buildDecrementOperator(m_tokens, m_index, start);

                            default: 
                                return ArithmeticOperatorHandlers::buildSubtractionOperator(m_tokens, m_index, start);
                        }
                        // -    ArithmeticOperatorType -    SubtractionOperator
                        return ArithmeticOperatorHandlers::buildSubtractionOperator(m_tokens, m_index, start);
                    case SymbolType::AsteriskSymbol:
                        CharacterUtilities::IncrementIndex(m_tokens, m_index);
                        CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);
                        switch(m_tokens[m_index]->symbolType()){
                            case SymbolType::EqualSymbol:
                                // *=   AssignmentOperatorHandlers -     ProductAssignmentOperator
                                return AssignmentOperatorHandlers::buildProductAssignmentOperator(m_tokens, m_index, start);
                            case SymbolType::AsteriskSymbol: //**
                                if(m_index < m_tokens.size() -1 && m_tokens[m_index + 1]->symbolType() == SymbolType::EqualSymbol){
                                    // **=   AssignmentOperatorHandlers -     ExponentAssignmentOperator
                                    return AssignmentOperatorHandlers::buildExponentAssignmentOperator(m_tokens, m_index, start);
                                }
                                // **    ArithmeticOperatorType -    ExponentOperator
                                return ArithmeticOperatorHandlers::buildExponentOperator(m_tokens, m_index, start);

                            default:
                                return ArithmeticOperatorHandlers::buildMultiplicationOperator(m_tokens, m_index, start);
                        }
                        // *    ArithmeticOperatorType -    MultiplicationOperator
                        return ArithmeticOperatorHandlers::buildMultiplicationOperator(m_tokens, m_index, start);
                    case SymbolType::ForwardSlash:
                        std::cout << "start: " << m_tokens[start]->inspect() << "\n";
                        std::cout << "m_index: " << m_tokens[m_index]->inspect() << "\n";
                        std::cout << "m_index + 1: " << m_tokens[m_index + 1]->inspect() << "\n";

                        if(m_index + 1 < m_tokens.size() 
                            && (m_tokens[m_index + 1]->type() == CharacterType::WhiteSpace 
                                || m_tokens[m_index + 1]->symbolType() == SymbolType::EqualSymbol)
                            ){
                            CharacterUtilities::IncrementIndex(m_tokens, m_index);
                            CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);
                        }
                        switch(m_tokens[m_index]->symbolType()){
                            // /=   AssignmentOperatorHandlers -     DivisionAssignmentOperator
                            case SymbolType::EqualSymbol: //+=
                                return AssignmentOperatorHandlers::buildDivisionAssignmentOperator(m_tokens, m_index, start);
                            default: 
                                return ArithmeticOperatorHandlers::buildDivisionOperator(m_tokens, m_index, start);
                        }
                        // /    ArithmeticOperatorType -    DivisionOperator
                        return ArithmeticOperatorHandlers::buildDivisionOperator(m_tokens, m_index, start);
                    case SymbolType::Percentage:
                        CharacterUtilities::IncrementIndex(m_tokens, m_index);
                        CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);
                        switch(m_tokens[m_index]->symbolType()){
                            // %=   AssignmentOperatorHandlers -     ModulusAssignmentOperator
                            case SymbolType::EqualSymbol:
                                return AssignmentOperatorHandlers::buildModulusAssignmentOperator(m_tokens, m_index, start);
                            default: 
                                return ArithmeticOperatorHandlers::buildModulusOperator(m_tokens, m_index, start);
                        }
                        // & BitwiseOperatorType -      BitAndOperator
                        return ArithmeticOperatorHandlers::buildModulusOperator(m_tokens, m_index, start);
                    case SymbolType::AndSymbol:
                        CharacterUtilities::IncrementIndex(m_tokens, m_index);
                        CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);
                        switch(m_tokens[m_index]->symbolType()){
                            // && LogicalOperatorType -     LogicalAndOperator
                            case SymbolType::AndSymbol: 
                                return LogicalOperatorHandlers::buildLogicalAndOperator(m_tokens, m_index, start);
                            default: 
                                return BitwiseOperatorHandlers::buildBitAndOperator(m_tokens, m_index, start);
                        }
                        // & BitwiseOperatorType -      BitAndOperator
                        return BitwiseOperatorHandlers::buildBitAndOperator(m_tokens, m_index, start);
                    case SymbolType::PipeSymbol:
                        CharacterUtilities::IncrementIndex(m_tokens, m_index);
                        CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);
                        switch(m_tokens[m_index]->symbolType()){
                            // || LogicalOperatorType -     LogicalOrOperator
                            case SymbolType::PipeSymbol: 
                                return LogicalOperatorHandlers::buildLogicalOrOperator(m_tokens, m_index, start);
                            default: 
                                return BitwiseOperatorHandlers::buildBitOrOperator(m_tokens, m_index, start);
                        }
                        // | BitwiseOperatorType -      BitOrOperator
                        return BitwiseOperatorHandlers::buildBitOrOperator(m_tokens, m_index, start);
                    case SymbolType::Exclamation:
                        CharacterUtilities::IncrementIndex(m_tokens, m_index);
                        CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);
                        switch(m_tokens[m_index]->symbolType()){
                            case SymbolType::EqualSymbol: 
                            if(m_index + 1 < m_tokens.size() -1 && m_tokens[m_index+1]->symbolType() == SymbolType::EqualSymbol){
                                    CharacterUtilities::IncrementIndex(m_tokens, m_index);
                                    // !==  ComparisonOperatorType   -   StrictNotEqualOperator
                                    return ComparisonOperatorHandlers::buildStrictNotEqualOperator(m_tokens, m_index, start);
                                }
                                    // !=  ComparisonOperatorType   -   NotEqualOperator
                                    return ComparisonOperatorHandlers::buildNotEqualOperator(m_tokens, m_index, start);
                            default: 
                                return LogicalOperatorHandlers::buildLogicalNotOperator(m_tokens, m_index, start);
                        }
                        // ! LogicalOperatorType -     LogicalNotOperator
                        return LogicalOperatorHandlers::buildLogicalNotOperator(m_tokens, m_index, start);
                    case SymbolType::LessThanSymbol:
                        CharacterUtilities::IncrementIndex(m_tokens, m_index);
                        CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);
                        switch(m_tokens[m_index]->symbolType()){
                            // <=  ComparisonOperatorType   -   LessThanOrEqualOperator
                            case SymbolType::EqualSymbol: 
                                return ComparisonOperatorHandlers::buildLessThanOrEqualOperator(m_tokens, m_index, start);
                            // << BitwiseOperatorType -          BitLeftShiftOperator
                            case SymbolType::LessThanSymbol:
                                    return BitwiseOperatorHandlers::buildBitLeftShiftOperator(m_tokens, m_index, start);
                            default: 
                                return ComparisonOperatorHandlers::buildLessThanOperator(m_tokens, m_index, start);
                        }
                        // <  ComparisonOperatorType   -   LessThanOperator
                        return ComparisonOperatorHandlers::buildLessThanOperator(m_tokens, m_index, start);
                    case SymbolType::GreaterThanSymbol:
                        CharacterUtilities::IncrementIndex(m_tokens, m_index);
                        CharacterUtilities::IgnoreWhiteSpace(m_tokens, m_index);
                        switch(m_tokens[m_index]->symbolType()){
                            // >=  ComparisonOperatorType   -   GreaterThanOrEqualOperator
                            case SymbolType::EqualSymbol: 
                                return ComparisonOperatorHandlers::buildGreaterThanOrEqualOperator(m_tokens, m_index, start);
                            case SymbolType::GreaterThanSymbol:
                                // >>> BitwiseOperatorType -          BitUnsignedRightOperator
                                if(m_index + 1 < m_tokens.size() - 1 && m_tokens[m_index+1]->symbolType() == SymbolType::GreaterThanSymbol){
                                    CharacterUtilities::IncrementIndex(m_tokens, m_index);
                                    return BitwiseOperatorHandlers::buildBitUnsignedRightOperator(m_tokens, m_index, start);
                                }
                                // >> BitwiseOperatorType -          BitRightShiftOperator
                                return BitwiseOperatorHandlers::buildBitRightShiftOperator(m_tokens, m_index, start);
                            default: 
                                return ComparisonOperatorHandlers::buildGreaterThanOperator(m_tokens, m_index, start);
                        }
                        // >  ComparisonOperatorType   -   GreaterThanOperator
                        return ComparisonOperatorHandlers::buildGreaterThanOperator(m_tokens, m_index, start);
                    case SymbolType::QuestionMark:
                        // ?  ComparisonOperatorType   -   TernaryOperator
                        return ComparisonOperatorHandlers::buildTernaryOperator(m_tokens, m_index, start);
                    case SymbolType::Colon:
                        // :  ComparisonOperatorType   -   TernaryNotOperator
                        return ComparisonOperatorHandlers::buildTernaryNotOperator(m_tokens, m_index, start);
                    case SymbolType::TildeSymbol:
                        // ~ BitwiseOperatorType -      BitNotOperator
                        return BitwiseOperatorHandlers::buildBitNotOperator(m_tokens, m_index, start);
                    case SymbolType::CaratSymbol:
                        // ^ BitwiseOperatorType -      BitXOROperator
                        return BitwiseOperatorHandlers::buildBitXOROperator(m_tokens, m_index, start);
                    default: 
                        CharacterUtilities::IncrementIndex(m_tokens, m_index);
                        return NULL;
                }
            default: 
                CharacterUtilities::IncrementIndex(m_tokens, m_index);
                return NULL; 
        }
    return NULL; 
}

