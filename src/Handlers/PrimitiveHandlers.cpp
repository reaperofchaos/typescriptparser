#include "PrimitiveHandlers.h"

/**
 * @brief Builds a primitive from the provided components
 * 
 * @param components 
 * @param m_index 
 * @return std::shared_ptr<Primitive> 
 */
std::shared_ptr<Primitive> PrimitiveHandlers::buildPrimitive(
    std::vector<std::shared_ptr<Component>> &components, 
    size_t &m_index)
{
    size_t start = m_index; 
    switch(components[start]->type()){
        case ComponentType::Name:
            return PrimitiveHandlers::buildBooleanPrimitive(components[start], m_index);
        case ComponentType::NumberType:
            return PrimitiveHandlers::buildNumberPrimitive(components, m_index);
        case ComponentType::StringType:
            return PrimitiveHandlers::buildStringPrimitive(components, m_index);
        case ComponentType::OpenObject:
            return PrimitiveHandlers::buildObject(components, m_index);
        case ComponentType::OpenArray:
            return PrimitiveHandlers::buildArray(components, m_index);
        default:
            ComponentUtilities::IncrementIndex(components, m_index);
            return NULL; 
    }
    return NULL; 
}

/**
 * @brief Creates a boolean primitive from the provided components
 * 
 * @param text 
 * @param m_index 
 * @return std::shared_ptr<BooleanPrimitive> 
 */
std::shared_ptr<BooleanPrimitive> PrimitiveHandlers::buildBooleanPrimitive(
    std::shared_ptr<Component> &text, 
    size_t &m_index)
{
    m_index++;
    return std::make_shared<BooleanPrimitive>(std::dynamic_pointer_cast<Name>(text));
}

/**
 * @brief Builds a string primitive from the provided components
 * 
 * @param components 
 * @param m_index 
 * @return std::shared_ptr<StringPrimitive> 
 */
std::shared_ptr<StringPrimitive> PrimitiveHandlers::buildStringPrimitive(
    std::vector<std::shared_ptr<Component>> &components,
    size_t &m_index)
{
    size_t start = m_index;
    ComponentUtilities::IncrementIndex(components, m_index);
    ComponentUtilities::IgnoreWhiteSpace(components, m_index);     
    return std::make_shared<StringPrimitive>(std::dynamic_pointer_cast<StringType>(components[start]));
}

/**
 * @brief Builds a number primitive from the provided components
 * 
 * @param components 
 * @param m_index 
 * @return std::shared_ptr<NumberPrimitive> 
 */
std::shared_ptr<NumberPrimitive> PrimitiveHandlers::buildNumberPrimitive(
    std::vector<std::shared_ptr<Component>> &components,
    size_t &m_index)
{
    ComponentUtilities::IncrementIndex(components, m_index);
    return std::make_shared<NumberPrimitive>(std::dynamic_pointer_cast<NumberType>(components[m_index-1]));
}

/**
 * @brief Builds an object from the provided components
 * 
 * @param components 
 * @param m_index 
 * @return std::shared_ptr<ObjectPrimitive> 
 */
std::shared_ptr<ObjectPrimitive> PrimitiveHandlers::buildObject(
    std::vector<std::shared_ptr<Component>> &components,
    size_t &m_index)
{
    std::vector<std::shared_ptr<ObjectPair>> objectPairs; 
    ComponentUtilities::IncrementIndex(components, m_index);

    while(components[m_index]->type() != ComponentType::CloseObject)
    {
        ComponentUtilities::IgnoreWhiteSpace(components, m_index);

        //Function to build an object pair
        if(components[m_index]->type() == ComponentType::Name){
            std::shared_ptr<Name> key = std::dynamic_pointer_cast<Name>(components[m_index]); 
            ComponentUtilities::IncrementIndex(components, m_index);
            ComponentUtilities::IgnoreWhiteSpace(components, m_index);
            if(components[m_index]->type() == ComponentType::ColonComponent)
            {
                m_index++;
            }

            ComponentUtilities::IgnoreWhiteSpace(components, m_index);
            std::shared_ptr<Primitive> primitive = PrimitiveHandlers::buildPrimitive(components, m_index);
            ComponentUtilities::IgnoreWhiteSpace(components, m_index);
            if(components[m_index]->type() == ComponentType::CommaComponent)
            {
                ComponentUtilities::IncrementIndex(components, m_index);
                ComponentUtilities::IgnoreWhiteSpace(components, m_index);
            }

            objectPairs.push_back(std::make_shared<ObjectPair>(key, primitive));
        }
    }

    ComponentUtilities::IncrementIndex(components, m_index);
    return std::make_shared<ObjectPrimitive>(objectPairs);
}

/**
 * @brief Builds an array from the provided components
 * 
 * @param components 
 * @param m_index 
 * @return std::shared_ptr<ArrayPrimitive> 
 */
std::shared_ptr<ArrayPrimitive> PrimitiveHandlers::buildArray(
    std::vector<std::shared_ptr<Component>> &components,
    size_t &m_index)
{
    std::vector<std::shared_ptr<Primitive>> primitives;
    ComponentUtilities::IncrementIndex(components, m_index);
    
    while(components[m_index]->type() != ComponentType::CloseArray)
    {
        ComponentUtilities::IgnoreWhiteSpace(components, m_index);
        if(components[m_index]->type() != ComponentType::CommaComponent)
        {
            primitives.push_back(PrimitiveHandlers::buildPrimitive(components, m_index));
            ComponentUtilities::IncrementIndex(components, m_index);
        }
        
        ComponentUtilities::IgnoreWhiteSpace(components, m_index);
        if(components[m_index]->type() == ComponentType::CommaComponent)
        {
            ComponentUtilities::IncrementIndex(components, m_index);
        }

        ComponentUtilities::IgnoreWhiteSpace(components, m_index);
    }
    
    ComponentUtilities::IncrementIndex(components, m_index);
    return std::make_shared<ArrayPrimitive>(primitives);
}