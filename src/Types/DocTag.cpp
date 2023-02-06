#include "DocTag.h"

std::string DocTag::getTypeAsString(DocTagType type)
{
    switch (type)
    {
        case DocTagType::Summary:
            return "Summary document generation tag";
        case DocTagType::Remark:
            return "Remark document generation tag";
        case DocTagType::Param:
            return "Param document generation tag";
        case DocTagType::Return:
            return "Return document generation tag";
        case DocTagType::Example:
            return "Example document generation tag";
        case DocTagType::Unknown:
        default:
            return "Not a document generation tag";
    }
};
