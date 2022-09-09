#include "PrimitiveBuilder.h"

/**
 * @brief Iterates through a vector of components and creates a primitive
 */
std::shared_ptr<Primitive>PrimitiveBuilder::next()
{
    while (this->m_index < this->m_components.size())
    {
        switch(m_components[m_index]->type())
        {   
            case ComponentType::NumberType:
            case ComponentType::StringType:
            case ComponentType::Name:
                return PrimitiveHandlers::buildPrimitive(m_components, m_index);
            case ComponentType::OpenObject:
                return PrimitiveHandlers::buildObject(m_components, m_index);
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
void PrimitiveBuilder::build_primitives() 
{
    while (auto primitive = this->next()) 
    {
        this->m_primitives.push_back(primitive);
    }
}

/**
 * @brief Displays the type and value of the primitives
 * 
 */
void PrimitiveBuilder::displayPrimitives()
{
    for(auto primitive : this->m_primitives)
    {
        std::cout << primitive->getType() << " - " << primitive->getValue() << "\n";
    }
}