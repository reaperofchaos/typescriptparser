#include "ContainerKeyword.h"

std::string ContainerKeyword::getContainerKeywordAsString(ContainerKeywordType type)
{
    switch (type)
    {
        case ContainerKeywordType::ArrayKeyword:
            return "Array keyword";
        case ContainerKeywordType::MapKeyword:
            return "Map Keyword";
        case ContainerKeywordType::SetKeyword:
            return "Set Keyword";
        case ContainerKeywordType::ObjectKeyword:
            return "Object Keyword";
        default: 
            return "Not a container Keyword";
    }
}