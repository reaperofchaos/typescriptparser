#include "ElementHandlers.h"

/**
 * @brief Builds a nested string from the provided components
 * 
 * @param components 
 * @param m_index 
 * @param start 
 * @return std::shared_ptr<NestedString> 
 */
std::shared_ptr<NestedString> ElementHandlers::buildNestedString(
    std::vector<std::shared_ptr<Component>> &components,
    size_t &m_index,  
    size_t &start)
{
    std::string value = ""; 
    value += components[start]->getValue();
    ComponentUtilities::IncrementIndex(components, m_index);

    // while(components[m_index]->type() != ComponentType::ClosingOpenTag &&
    //     components[m_index]->type() != ComponentType::OpenTag)
    // {
    //     value += components[m_index]->getValue();
    //     ComponentUtilities::IncrementIndex(components, m_index);
    // }
    std::shared_ptr<StringType> stringValue = std::make_shared<StringType>(value);
    
    return std::make_shared<NestedString>(stringValue);
}

/**
 * @brief Creates a nested object from the provided components
 * 
 * @param components 
 * @param m_index 
 * @param start 
 * @return std::shared_ptr<NestedObject> 
 */
std::shared_ptr<NestedObject> ElementHandlers::buildNestedObject(
    std::vector<std::shared_ptr<Component>> &components,
    size_t &m_index,  
    size_t &start)
{
    std::string value = ""; 
    value += components[start]->getValue();
    ComponentUtilities::IncrementIndex(components, m_index);

    while(components[m_index]->type() != ComponentType::CloseObject)
    {
        value += components[m_index]->getValue();
        ComponentUtilities::IncrementIndex(components, m_index);
    }

    if(components[m_index]->type() == ComponentType::CloseParenthesisComponent)
    {
        value += components[m_index]->getValue();
        ComponentUtilities::IncrementIndex(components, m_index);
    }

    if(components[m_index]->type() == ComponentType::CloseObject)
    {
        value += components[m_index]->getValue();
        ComponentUtilities::IncrementIndex(components, m_index);
    }

    std::shared_ptr<StringType> stringValue = std::make_shared<StringType>(value);
    
    return std::make_shared<NestedObject>(stringValue);
}