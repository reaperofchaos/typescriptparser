#include "ComponentUtilities.h"

/**
 * @brief Function that checks if the current component
 * is a whitespace component and then increments until a non-whitespace
 * component is found. 
 * 
 * @param components 
 * @param m_index 
 */
void ComponentUtilities::IgnoreWhiteSpace( 
    std::vector<std::shared_ptr<Component>> &components,
    size_t &m_index)
{
    while(components[m_index]->type() == ComponentType::WhiteSpaces )
    {
        ComponentUtilities::IncrementIndex(components, m_index);
    } 
}

/**
 * @brief A function to safely increment the index of a component vector
 * 
 * @param components 
 * @param m_index 
 */
void ComponentUtilities::IncrementIndex( 
    std::vector<std::shared_ptr<Component>> &components,
    size_t &m_index)
{
    if(m_index < components.size()-1)
    {
        m_index++;
    } 
}

/**
 * @brief A function to display the value of the current
 * component at a given index
 * 
 * @param components 
 * @param m_index 
 */
void ComponentUtilities::DisplayCurrent( 
    std::vector<std::shared_ptr<Component>> &components,
    size_t &m_index)
{
    std::cout << components[m_index]->inspect() << "\n"; 
}