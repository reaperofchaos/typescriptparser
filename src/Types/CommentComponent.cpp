#include "CommentComponent.h"


std::string CommentComponent::getCommentTypeAsString(CommentType type)
{
    switch (type)
    {
        case CommentType::SingleLineComment:
            return "Single Line Comment";
        case CommentType::MultiLineComment:
            return "Multiline Comment";
        default: 
            return "Not a Comment component";
    }
}