#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include "../Types/Component.h"
#include "../Types/Primitive.h"
#include "../Utils/ComponentUtilities.h"

/**
 * A class used to create Primitives from Component vectors
 */
class PrimitiveHandlers {
    public:
        static std::shared_ptr<Primitive> buildPrimitive(
            std::vector<std::shared_ptr<Component>> &components, 
            size_t &m_index);

        static std::shared_ptr<StringPrimitive> buildStringPrimitive(
            std::vector<std::shared_ptr<Component>> &components,
            size_t &m_index);
        
        static std::shared_ptr<BooleanPrimitive> buildBooleanPrimitive(
            std::shared_ptr<Component> &text, 
            size_t &m_index);
        
        static std::shared_ptr<NumberPrimitive> buildNumberPrimitive(
            std::vector<std::shared_ptr<Component>> &components,
            size_t &m_index);

        static std::shared_ptr<ObjectPrimitive> buildObject(
            std::vector<std::shared_ptr<Component>> &components,
            size_t &m_index);
        
        static std::shared_ptr<ArrayPrimitive> buildArray(
            std::vector<std::shared_ptr<Component>> &components,
            size_t &m_index);
};