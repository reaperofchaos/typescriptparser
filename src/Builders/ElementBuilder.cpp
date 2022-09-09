#include "ElementBuilder.h"

/**
 * @brief Function to iterate through the components
 * and creates elements
 */
std::shared_ptr<Element>ElementBuilder::next(){
    size_t start = this->m_index;

    while (this->m_index < this->m_components.size()-1)
    {
        switch(m_components[m_index]->type())
        { 
            case ComponentType::Name:
            case ComponentType::StringType:
                return ElementHandlers::buildNestedString(m_components, m_index, start);    
            case ComponentType::OpenObject:
                return ElementHandlers::buildNestedObject(m_components, m_index, start);    

            default:
                    m_index++;
                    return {};
        }
        return {};

    } 
    return {};

}

/**
 * @brief Builds primitives from components
 * 
 */
void ElementBuilder::buildElements() 
{
    while (auto element = this->next()) 
    {
        this->m_elements.push_back(element);
    }
}

/** 
 * function to read a string, 
 * tokenizes and analyzes the tokens 
 * and returns an Abstract Syntax Tree
 **/
void ElementBuilder::read_str(std::string input) 
{
    std::cout << "Parsing the file: " << "\n";
    std::cout << "\n";  
    Tokenizer tokenizer = Tokenizer(input);
    tokenizer.tokenize();
    std::vector<std::shared_ptr<Character>>tokens = tokenizer.getTokens(); 
    std::cout << "Number of tokens(characters) found: " << tokens.size() << "\n"; 
    ComponentBuilder componentBuilder = ComponentBuilder(tokens);  
    componentBuilder.build_components();
    std::vector<std::shared_ptr<Component>>components = componentBuilder.getComponents(); 
    std::cout << "Number of components found: " << components.size() << "\n"; 
    // ElementBuilder elementBuilder(components);
    // elementBuilder.buildElements();
    // std::vector<std::shared_ptr<Element>>elements = elementBuilder.getElements(); 
    // std::cout << "Number of elements found: " << elements.size() << "\n";
    // std::cout << "\n"; 
    // std::shared_ptr<Node> targetNode;
    // std::shared_ptr<Node> tree = targetNode->createTree(elements);
    // return tree; 
}

/**
 * @brief A function to iterate through a 
 * vector of elements and displays the  element type
 * and value
 * 
 */
void ElementBuilder::displayElements(){
    for(auto element : this->m_elements)
    {
        std::cout << element->inspect();
    }
}