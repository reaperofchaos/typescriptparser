#pragma once

#include <string>
#include <vector>
#include <optional>
#include <memory>
#include "../Types/Component.h"
#include "../Types/Primitive.h"
#include "../Handlers/PrimitiveHandlers.h"
#include "Tokenizer.h"

/**
 * @brief Class to build primitives from components
 * 
 */
class PrimitiveBuilder 
{
    private:
        std::vector<std::shared_ptr<Component>> m_components;
        std::vector<std::shared_ptr<Primitive>> m_primitives;
        size_t m_index = 0; // position in string

    public:
        PrimitiveBuilder(std::vector<std::shared_ptr<Component>> components)
        {
            this->m_components = components; 
        }

        std::vector<std::shared_ptr<Component>> getComponents(){return m_components;}
        std::vector<std::shared_ptr<Primitive>> getPrimitives(){return m_primitives;}
        static void read_str(std::string input);
        std::shared_ptr<Primitive> next();
        void build_primitives();
        void displayComponents();
        void displayPrimitives();
};
