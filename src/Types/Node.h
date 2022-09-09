#pragma once
#include <vector>
#include <iostream>
#include <queue>
#include <optional>
#include <memory>
#include "Element.h"
class Node{
    public:
        std::shared_ptr<Element> value = NULL; 
        std::shared_ptr<Node> parent = NULL;
        std::vector<std::shared_ptr<Node>> children;
        int level = 0; 

    Node(){};    
    Node(std::shared_ptr<Element> element)
    {
        this->value = element;
    }
    
    Node(std::shared_ptr<Element> newValue, std::shared_ptr<Node> parentNode)
    {
        this->value = newValue;
        this->parent = parentNode;
    }

    Node(std::shared_ptr<Element> newValue, int level, std::shared_ptr<Node> parentNode)
    {
        this->value = newValue;
        this->level = level;
        this->parent = parentNode;

    }

    void setValue(std::shared_ptr<Element> value){this->value = value; }
    void insertValue(std::shared_ptr<Node> node, std::shared_ptr<Element> valueToAdd);

    static int getLastLevel(std::shared_ptr<Node> node);
    static std::shared_ptr<Node> findLastNode(std::shared_ptr<Node> node);
    static std::shared_ptr<Node> getLastNode(std::shared_ptr<Node> node);
    static std::shared_ptr<Node> createTree(std::vector<std::shared_ptr<Element>> valuesToAdd); 
    static bool isPair(std::shared_ptr<Node> node1, std::shared_ptr<Node> node2);   
    static bool isPair(std::shared_ptr<Node> node1, std::shared_ptr<Element> valueToCompare);
    static void display(std::shared_ptr<Node> node);

    static std::shared_ptr<Node> findNode(std::shared_ptr<Node> tree,
        std::shared_ptr<Element> currentValue);

};