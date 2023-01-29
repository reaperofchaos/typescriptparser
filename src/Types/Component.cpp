#include "Component.h"

std::string Component::getTypeAsString(ComponentType type)
{
    switch (type)
    {
        case ComponentType::Name:
            return "Name";
        case ComponentType::StringType:
            return "String";
        case ComponentType::NumberType:
            return "Number";
        case ComponentType::OpenArray:
            return "Open array";
        case ComponentType::OpenObject:
            return "Open object";
        case ComponentType::CloseArray:
            return "Close array";
        case ComponentType::CloseObject:
            return "Close object";
        case ComponentType::WhiteSpaces:
            return "White spaces";
        case ComponentType::ExclamationComponent:
            return "Exclamation";
        case ComponentType::ColonComponent:
            return "Colon";
        case ComponentType::CommaComponent:
            return "Comma";
        case ComponentType::SemicolonComponent:
            return "Semicolon";
        case ComponentType::EqualComponent:
            return "Equal";
        case ComponentType::DashComponent:
            return "Dash"; 
        case ComponentType::PercentageComponent:
            return "Percentage Component";
        case ComponentType::HashTagComponent:
            return "Hash Tag Component";
        case ComponentType::CloseParenthesisComponent:
            return "Close Parenthesis";
        case ComponentType::OpenParenthesisComponent:
            return "Open Parenthesis";
        case ComponentType::Operator:
            return "Operator";
        case ComponentType::Keyword:
            return "Keyword";
        case ComponentType::OpenInstruction:
            return "Open Instruction";
        case ComponentType::CloseInstruction:
            return "Close Instruction";
        case ComponentType::ArrowFunctionComponent:
            return "Arrow Function Component";
        case ComponentType::OpenParameter:
            return "Open parameter";
        case ComponentType::CloseParameter:
            return "Close parameter";
        case ComponentType::EndStatementComponent:
            return "End Statement";
        case ComponentType::CommentComponent:
            return "Comment";
        default: 
            return "Unknown";
    }
}