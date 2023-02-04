#pragma once
#include <string>
#include "Component.h"
#include "CharType.h"

enum class CommentType{
    SingleLineComment,
    MultiLineComment,
    Unknown
};

class CommentComponent: public Component
{
    private:
        std::string value;
        std::vector<std::string> lines;

    public:
        CommentComponent(): Component()
        {}
        
        virtual ~CommentComponent() = default;
        virtual std::string getCommentTypeAsString(CommentType type);
        virtual ComponentType type(){ return ComponentType::CommentComponent;}
        virtual CommentType commentType(){ return CommentType::Unknown;}
        virtual std::string getCommentType(){return this->getCommentTypeAsString(this->commentType());}
        virtual std::string inspect() { assert(0); }
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getCommentType();}
};


class SingleLineComment: public CommentComponent
{
    private:
        std::string value; 
        std::vector<std::string> lines;

    public:
        SingleLineComment(
            std::shared_ptr<ForwardSlash> forwardSlash1,
            std::shared_ptr<ForwardSlash> forwardSlash2,
            std::string commentString
        ): CommentComponent()
        {
            this->value = forwardSlash1->getValue() 
                + forwardSlash2->getValue() 
                + " " 
                + commentString;
        }
        virtual CommentType commentType(){ return CommentType::SingleLineComment;}
        virtual std::string getValue(){ return value;}
        virtual std::string getCommentType(){return this->getCommentTypeAsString(this->commentType());}
        virtual std::string inspect(){ return "Type " + getCommentType() + ": \n\n" + getValue() + "\n";}
};



class MultiLineComment: public CommentComponent
{
    private:
        std::string value; 
        std::vector<std::string> lines;

    public:
        MultiLineComment(
            std::shared_ptr<ForwardSlash> forwardSlash,
            std::shared_ptr<AsteriskSymbol> asterisk,
            std::vector<std::string> comments
            ): CommentComponent()
        {
            this->value = forwardSlash->getValue() + asterisk->getValue() + "\n";
            for(std::string line : comments){
                this->value += " * " + line + "\n";
            }
            this->value += "*/";

            this->lines = comments; 
        }
        virtual CommentType commentType(){ return CommentType::MultiLineComment;}
        virtual std::string getValue(){ return value;}
        virtual std::string getCommentType(){return this->getCommentTypeAsString(this->commentType());}
        virtual std::string inspect(){ return "Type " + getCommentType() + ":" + "\n\n" + getValue() + "\n";}
};
