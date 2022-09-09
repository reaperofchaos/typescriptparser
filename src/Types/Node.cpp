#include "Node.h"


/**
 * @brief Get the level property of the bottom of the tree
 * Uses recursion to navigate the most right most and most bottom node
 * @param node, a tree
 * @return int the level of the node
 */
int Node::getLastLevel(std::shared_ptr<Node> node)
{
    int childNodes = node->children.size();
    if(childNodes > 0)
    {
        getLastLevel(node->children[node->children.size() - 1]);
    }
    return node->level;
}

/**
 * @brief Function to navigate the tree and find the next 
 * node with a value equal to the string of the value provided
 * Reads trees bottom up
 * @param tree pointer to a node on the tree
 * @param currentValue value to find
 * @return Node* 
 */
std::shared_ptr<Node> Node::findNode(std::shared_ptr<Node> tree,
    std::shared_ptr<Element> currentValue)
{
    int numberOfChildren = tree->children.size();
    // Tree is root (no parents) and currentValue is an end tag and has a value
    // string equal to the tree's value string then return the root node
    if(tree->parent == NULL && tree->value->getValue() == currentValue->getValue())
    {
        if(Node::isPair(tree, currentValue))
        {
            return tree;
        }
    }
    //if the node has children check to see if we have a tag that is a pair
    // for the current value going most recently added to oldest (right to left)
    if(numberOfChildren > 0)
    {
        //Check to see if parent has children with a match
        //go right to left
        int i = numberOfChildren -1; 
        while(i >= 0)
        {
            //If we get a matching name
            if(tree->children[i]->value->getValue() == currentValue->getValue())
            {
                //if we get a matching pair
                if(Node::isPair(tree->children.at(i), currentValue))
                {
                    //return the parent of the found element
                    return tree->children.at(i)->parent;
                }
                //if the pair doesn't match, we have a linting error,
                // an end tag without a start tag
                std::cout   << "Error: A " << tree->children.at(i)->value->getType() 
                            << " for " << currentValue->getValue()
                            << " was found after a " << currentValue->getType()  
                            << "\n"; 
                return NULL;
            }
            i--; 
        }
    }
    //No matches were found in the children
    //Check if we have a parent node
    if(tree->parent != NULL){
            //no nodes at this level, go up one
            return Node::findNode(tree->parent, currentValue);
        }else{
            std::cout   << "Error: A " << currentValue->getType() 
                    << " for " << currentValue->getValue()
                    << " was found without a starting tag "   
                    << "\n"; 
                return NULL;
        }
    return NULL; 
}

/**
 * @brief Get the bottom right node of the tree
 * Uses recursion to navigate the most right most and most bottom node
 * @param node, a tree
 * @return int the level of the node
 */
std::shared_ptr<Node> Node::getLastNode(std::shared_ptr<Node> node)
{
    int childNodes = node->children.size();
    if(childNodes > 0)
    {
        return Node::getLastNode(node->children[childNodes - 1]);   
    }

    return node;
}

/**
 * @brief Create a Tree object
 * 
 * @param valuesToAdd 
 * @return Node shared pointer
 */
std::shared_ptr<Node> Node::createTree(std::vector<std::shared_ptr<Element>> valuesToAdd)
{
    std::shared_ptr<Node> root =  std::make_shared<Node>(); 
    std::cout << "Creating tree from the Elements" << "\n\n"; 
    for(std::shared_ptr<Element> valueToAdd : valuesToAdd)
    {
        root->insertValue(root, valueToAdd);
    }
    return root; 
}


/**
 * @brief Checks if two nodes are a match
 * 
 * @param node1 a node
 * @param node2 a different node
 * @return boolean
 */
bool Node::isPair(std::shared_ptr<Node> node1, std::shared_ptr<Element> valueToCompare){
    if(node1->value->getValue() == valueToCompare->getValue())
    {
        if(node1->value->type() == ElementType::Tag &&
                node1->value->tagType() == TagType::CloseTagElement)
        {
            return valueToCompare->type() == ElementType::Tag && 
                valueToCompare->tagType() == TagType::OpenTagElement;
        }

        if(node1->value->type() == ElementType::Tag && 
            node1->value->tagType() == TagType::OpenTagElement)
        {
            return valueToCompare->type() == ElementType::Tag && 
                valueToCompare->tagType() == TagType::CloseTagElement;
        }
    }

    return false;
}


/**
 * @brief Checks if two nodes are a match
 * 
 * @param node1 a node
 * @param node2 a different node
 * @return boolean
 */
bool Node::isPair(std::shared_ptr<Node> node1, std::shared_ptr<Node> node2)
{
    if(node1 && node2)
    {
        if(node1->value->getValue() == node2->value->getValue())
        {
            if(node1->value->type() == ElementType::Tag &&
                node1->value->tagType() == TagType::CloseTagElement)
            {
                return node2->value->tagType() == TagType::OpenTagElement;
            }

            if(node1->value->type() == ElementType::Tag &&
                node1->value->tagType() == TagType::OpenTagElement)
            {
                return node2->value->tagType() == TagType::CloseTagElement;
            }
        }
    }

    return false;
}

/**
 * @brief Function to add an element to a node to a tree
 * 
 * @param node - the tree
 * @param valueToAdd - the element to add to the tree
 */
void Node::insertValue(std::shared_ptr<Node> node, std::shared_ptr<Element> valueToAdd)
{
    //if Node pointer is null, create a root node
    if (node->value == NULL)
    {
        node->setValue(valueToAdd);
    }else{
        std::shared_ptr<Node> lastNode = Node::getLastNode(node);
        int bottomLevel = getLastLevel(node);
        //add tag to children vector if no children exist
        if(valueToAdd->type() != ElementType::Tag ||
            (valueToAdd->type() == ElementType::Tag &&
            valueToAdd->tagType() != TagType::CloseTagElement))
        {
            if(node->children.size() == 0)
            {
                node->children.push_back(
                    std::make_shared<Node>(valueToAdd, bottomLevel + 1, node));
            }else{
                // we have more than one child node
                // if the last node was a start tag, 
                // this next start tag should be nested under it
                if(lastNode->value->type() == ElementType::Tag && 
                    lastNode->value->tagType() == TagType::OpenTagElement)
                {
                    insertValue(node->children[node->children.size() - 1], valueToAdd);
                // This is a sibling node, so just add it to the child array
                }else{
                    //Add to the children of the parent of the last node. (Node is a sibling of last node)
                    lastNode->parent->children.push_back(
                        std::make_shared<Node>(valueToAdd, 
                            lastNode->parent->level +1, 
                            lastNode->parent));
                }
            }
        //We have an end tag, so we need to find the start tag before adding
        }else{
            if(lastNode->parent != NULL){
                    //Navigate through the tree and check to find a start tag with a string value equal
                    // to the value of the string of the value being added. 
                    std::shared_ptr foundParentNode = Node::findNode(lastNode->parent, valueToAdd); 
                    
                    if(foundParentNode != NULL)
                    {
                        foundParentNode->children.push_back(std::make_shared<Node>(valueToAdd, foundParentNode->level +1, foundParentNode));
                    }else{
                        std::cout << "Linting Error: No start tag was found for end tag named  " << valueToAdd->getValue()  << "\n"; 
                    }
            }else{
                std::cout << "Tree Error: The last node's parent is evidently not set \n"; 
            }

        }
    }
}

/**
 * @brief Traverses the tree and finds the bottom right most node. 
 * @param node, a tree
 * @return int the level of the node
 */
std::shared_ptr<Node> Node::findLastNode(std::shared_ptr<Node> node)
{
    int childNodes = node->children.size();
    if(childNodes > 0)
    {
        findLastNode(node->children[node->children.size() - 1]);
    }
    return node;
}

/**
* @brief Function to display the values 
* and levels of all nodes in the tree
* 
* @param node, a tree node with Values
*/
void Node::display(std::shared_ptr<Node> node)
{
        if(node->level == 0)
        {
            std::cout   << "Root is " << node->value->getValue() << "\n"; 
        }else{
            std::cout   << "Child Node: " << node->value->getValue() 
                        << " - ";
            if(node->value->type() == ElementType::Tag){
                std::cout << node->value->getTagType();
            } else{
                std::cout << node->value->getType();
            }
            std::cout   << " level: " << node->level << " \n";
            std::cout   << "Child of parent " << node->parent->value->getValue() 
                        << " - ";
            if(node->parent->value->type() == ElementType::Tag){
                std::cout << node->parent->value->getTagType();
            } else{
                std::cout << node->parent->value->getType();
            }
            std::cout << " level: " << node->parent->level << "\n";
        }
        if(node->children.size() > 0)
        {
            for(std::shared_ptr<Node> childNode : node->children)
            {
                display(childNode);
            };
        }     
};
