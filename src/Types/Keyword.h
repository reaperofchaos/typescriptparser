#include <Vector>
#include <Memory>
#include <String>
#include "CharType.h";
#include "Symbol.h"; 

enum class KeywordType
{
    LetWord,
    VarWord, 
    ConstWord,
};

class Keyword
{
    private:
        std::string value;
    public:
        virtual ~Component() = default;
        virtual std::string getTypeAsString(ComponentType type){
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
                    return "Close Parenthesis";
                default: 
                    return "Unknown";
            }
        }
        
        virtual ComponentType type(){ return ComponentType::Unknown;}
        virtual std::string inspect() { assert(0); }
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
};