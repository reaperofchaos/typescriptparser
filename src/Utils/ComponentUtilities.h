#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include "../Types/Component.h"

/**
 * A class used to traverse component vectors
 */
class ComponentUtilities {
    public:
        static void IgnoreWhiteSpace( 
            std::vector<std::shared_ptr<Component>> &components,
            size_t &m_index);
        
        static void IncrementIndex( 
            std::vector<std::shared_ptr<Component>> &components,
            size_t &m_index);
        
        static void DisplayCurrent( 
            std::vector<std::shared_ptr<Component>> &characters,
            size_t &m_index);
};