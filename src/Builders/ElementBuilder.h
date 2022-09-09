#pragma once

#include <string>
#include <vector>
#include <optional>
#include <memory>
#include "../Types/Component.h"
#include "../Types/Primitive.h"
#include "../Types/Element.h"
#include "../Types/Node.h"
#include "../Handlers/ElementHandlers.h"
#include "ComponentBuilder.h"
#include "Tokenizer.h"

/**
 * @brief A class to build elements from components
 * 
 */
class ElementBuilder 
{
    private:
        std::vector<std::shared_ptr<Component>> m_components;
        std::vector<std::shared_ptr<Primitive>> m_primitives;
        std::vector<std::shared_ptr<Element>> m_elements; 
        std::shared_ptr<Node> tree;
        size_t m_index = 0; // position in string

    public:
        ElementBuilder(std::vector<std::shared_ptr<Component>> components)
        {
            this->m_components = components; 
        }

        std::vector<std::shared_ptr<Component>> getComponents(){return m_components;}
        std::vector<std::shared_ptr<Primitive>> getPrimitives(){return m_primitives;}
        std::vector<std::shared_ptr<Element>> getElements(){return m_elements;}
        std::shared_ptr<Node> getTree(){return this->tree;};

        void setTree(std::shared_ptr<Node> tree){ this->tree = tree;}; 

        static void read_str(std::string input);
        std::shared_ptr<Element> next();
        void displayComponents();
        void displayElements();
        void buildElements();
};

