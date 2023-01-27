#include "CommentComponent.h"


std::string CommentComponent::getCommentTypeAsString(CommentType type)
{
    switch (type)
    {
        case CommentType::OpenSingleLineComment:
            return "Open Single Line Comment";
        case CommentType::EndSingleLineComment:
            return "End Single Line Comment";
        case CommentType::OpenMultiLineComment:
            return "Open Multiline Comment";
        case CommentType::CloseMultiLineComment:
            return "Close Multiline Comment";
        default: 
            return "Not a Comment component";
    }
}