#include "ComponentBuilder.h"

/** 
 * function to read a string, 
 * tokenizes and analyzes the tokens 
 * and returns an Abstract Syntax Tree
 **/
void ComponentBuilder::read_str(std::string input) 
{
    Tokenizer tokenizer = Tokenizer(input);
    tokenizer.tokenize();
    std::vector<std::shared_ptr<Character>>tokens = tokenizer.getTokens(); 
    std::cout << "Total tokens " << tokens.size() << "\n"; 
    ComponentBuilder reader = ComponentBuilder(tokens);  
    reader.build_components();
    std::vector<std::shared_ptr<Component>>components = reader.getComponents(); 
    std::cout << "Total components " << components.size() << "\n"; 
    reader.displayComponents();
}

/**
 * @brief A function to iterate through a vector of characters and creates a
 * component
 * 
 */
std::shared_ptr<Component>ComponentBuilder::next(){
    size_t start = this->m_index;
    std::vector<std::shared_ptr<Character>> characters;
    std::vector< std::shared_ptr<Number>> numbers;
    std::vector<std::shared_ptr<WhiteSpace>> whiteSpaces;

    //handle strings between tags
    if(
        m_index > 0 &&
        m_index < m_tokens.size() &&
        (m_tokens[m_index -1]->symbolType() == SymbolType::GreaterThanSymbol ||
        m_tokens[m_index -1]->symbolType() == SymbolType::Dash) &&
        m_tokens[m_index]->type() != CharacterType::Symbol && 
        m_tokens[m_index]->type() != CharacterType::WhiteSpace) 
        return TokenHandlers::buildNestedString(m_tokens, m_index, characters);

    while (this->m_index < this->m_tokens.size())
    {
        std::cout << m_tokens[m_index]->inspect() << "\n";
        // CharacterUtilities::DisplayCurrent(this->m_tokens, this->m_index);
        switch(m_tokens[m_index]->type())
        {
            std::cout << m_tokens[m_index]->inspect() << "\n";
            case CharacterType::Number: //Build a number
                return TokenHandlers::buildNumberComponent(m_tokens, m_index, numbers);

            case CharacterType::WhiteSpace:
                if(m_index == start){
                    return {};
                }

            case CharacterType::Letter:
            case CharacterType::Uppercase:
            case CharacterType::Lowercase:
                return TokenHandlers::buildName(m_tokens, m_index, start, characters);

            case CharacterType::Symbol:
                switch(m_tokens[m_index]->symbolType())
                {
                    case SymbolType::LeftSquareBracket: //build the start of an array 
                        return TokenHandlers::buildOpenArray(m_tokens, m_index, start);
                    
                    case SymbolType::LeftCurlyBracket: //build the start of an object
                        return TokenHandlers::buildOpenObject(m_tokens, m_index, start);

                    case SymbolType::SingleQuote: //build the string
                        return TokenHandlers::buildString(m_tokens, m_index, characters, SymbolType::SingleQuote);
                        
                    case SymbolType::Quote: //build the string
                        return TokenHandlers::buildString(m_tokens, m_index, characters, SymbolType::Quote);
                        
                    case SymbolType::RightSquareBracket:
                        return TokenHandlers::buildCloseArray(m_tokens, m_index, start);

                    case SymbolType::RightCurlyBracket:
                        return TokenHandlers::buildCloseObject(m_tokens, m_index, start);

                    case SymbolType::ForwardSlash:
                        return CommentHandlers::buildOpenCommentComponent(m_tokens, m_index, start);
                    
                    case SymbolType::Comma:
                        return TokenHandlers::buildComma(m_tokens, m_index, start);
                    
                    case SymbolType::HashTag:
                        return TokenHandlers::buildHashTag(m_tokens, m_index, start);
                    
                    case SymbolType::LeftParenthesis:
                        return TokenHandlers::buildOpenParenthesis(m_tokens, m_index, start);
                    
                    case SymbolType::RightParenthesis:
                        return TokenHandlers::buildCloseParenthesis(m_tokens, m_index, start);
                    
                    case SymbolType::Semicolon:
                        return TokenHandlers::buildSemicolon(m_tokens, m_index, start);                        
                    
                    case SymbolType::QuestionMark:
                    case SymbolType::Colon:
                    case SymbolType::Exclamation:                    
                    case SymbolType::AndSymbol:
                    case SymbolType::PlusSymbol:
                    case SymbolType::EqualSymbol:
                    case SymbolType::AsteriskSymbol:
                    case SymbolType::Percentage:
                    case SymbolType::Dash:
                        return OperatorHandlers::buildOperator(m_tokens, m_index, start);

                    default: 
                        CharacterUtilities::IncrementIndex(m_tokens, m_index);
                        return {};
                }
                return {};
            default:
                    CharacterUtilities::IncrementIndex(m_tokens, m_index);
                    return {};
        }
        return {};

    } 
    return {};

}
/**
 * @brief Displays the type and value of the tokens
 * 
 */
void ComponentBuilder::displayCharacterTokens(){
    for(auto token : this->m_tokens)
    {
        std::cout << token->getType() << " - " << token->getValue() << "\n";
    }
}

/**
 * @brief Builds components from the characters
 * 
 */
void ComponentBuilder::build_components() 
{
    while (auto component = this->next()) 
    {
        this->m_components.push_back(component);
    }
}

/**
 * @brief Displays the type and value of the components
 * 
 */
void ComponentBuilder::displayComponents()
{
    for(auto component : this->m_components)
    {
        std::cout << component->getType() << " - " << component->getValue() << "\n";
    }
}
