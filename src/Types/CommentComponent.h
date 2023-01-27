#pragma once
#include <string>
#include "Component.h"
#include "CharType.h"

enum class CommentType{
    OpenSingleLineComment,
    EndSingleLineComment,
    OpenMultiLineComment,
    CloseMultiLineComment,
    Unknown
};

class CommentComponent: public Component
{
    private:
        std::string value;
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
        virtual std::string getType(){return this->getTypeAsString(this->type());}
};


class OpenSingleLineComment: public CommentComponent
{
    private:
        std::string value; 
    public:
        OpenSingleLineComment(std::shared_ptr<ForwardSlash> forwardSlash1, std::shared_ptr<ForwardSlash> forwardSlash2): CommentComponent()
        {
            this->value = forwardSlash1->getValue() + forwardSlash2->getValue();
        }
        virtual CommentType commentType(){ return CommentType::OpenSingleLineComment;}
        virtual std::string getValue(){ return value;}
        virtual std::string getCommentType(){return this->getCommentTypeAsString(this->commentType());}
        virtual std::string inspect(){ return "Type " + getCommentType() + " - " + getValue();}
};

class EndSingleLineComment: public CommentComponent
{
    private:
        std::string value; 
    public:
        EndSingleLineComment(std::shared_ptr<WhiteSpace> WhiteSpace): CommentComponent()
        {
            this->value = WhiteSpace->getValue();
        }
        virtual CommentType commentType(){ return CommentType::EndSingleLineComment;}
        virtual std::string getValue(){ return value;}
        virtual std::string getCommentType(){return this->getCommentTypeAsString(this->commentType());}
        virtual std::string inspect(){ return "Type " + getCommentType() + " - " + getValue();}
};

class OpenMultiLineComment: public CommentComponent
{
    private:
        std::string value; 
    public:
        OpenMultiLineComment(std::shared_ptr<ForwardSlash> forwardSlash, std::shared_ptr<AsteriskSymbol> asterisk): CommentComponent()
        {
            this->value = forwardSlash->getValue() + asterisk->getValue();
        }
        virtual CommentType commentType(){ return CommentType::OpenMultiLineComment;}
        virtual std::string getValue(){ return value;}
        virtual std::string getCommentType(){return this->getCommentTypeAsString(this->commentType());}
        virtual std::string inspect(){ return "Type " + getCommentType() + " - " + getValue();}
};

class CloseMultiLineComment: public CommentComponent
{
    private:
        std::string value; 
    public:
        CloseMultiLineComment( std::shared_ptr<AsteriskSymbol> asterisk, std::shared_ptr<ForwardSlash> forwardSlash): CommentComponent()
        {
            this->value = asterisk->getValue() + forwardSlash->getValue();
        }
        virtual CommentType commentType(){ return CommentType::CloseMultiLineComment;}
        virtual std::string getValue(){ return value;}
        virtual std::string getCommentType(){return this->getCommentTypeAsString(this->commentType());}
        virtual std::string inspect(){ return "Type " + getCommentType() + " - " + getValue();}
};