#pragma once
#include <string>
#include "../Component.h"
#include "../CharType.h"

enum class KeywordType
{
    VariableKeyword,
    DataTypeKeyword,
    ContainerKeyword,
    ExtendsKeyword,
    DeleteKeyword,
    DebuggerKeyword,
    DefaultKeyword,
    ImportKeyword,
    InstanceOfKeyword,
    TypeOfKeyword,
    RequireKeyword,
    WithKeyword,
    AsKeyword,
    ImplementsKeyword,
    PackageKeyword,
    YieldKeyword,
    ConstructorKeyword,
    ModuleKeyword,
    GetKeyword,
    DeclareKeyword,
    FromKeyword,
    AwaitKeyword,
    AsyncKeyword, 
    PromiseKeyword,
    SwitchKeyword,
    CaseKeyword,
    BreakKeyword,
    ReturnKeyword,
    IfKeyword,
    ElseKeyword,
    ForKeyword,
    WhileKeyword,
    DoKeyword,
    ContinueKeyword,
    OfKeyword,
    InKeyword,
    ErrorKeyword,
    TryKeyword,
    CatchKeyword,
    FinallyKeyword,
    ThrowKeyword,
    PublicKeyword,
    PrivateKeyword,
    ProtectedKeyword,
    StaticKeyword,
    NewKeyword,
    SuperKeyword,
    ThisKeyword,
    Unknown
};

enum class VariableKeywordType
{
    LetKeyWord,
    VarKeyWord, 
    ConstKeyWord,
    EnumKeyWord,
    InterfaceKeyWord,
    FunctionKeyWord,
    ClassKeyWord,
    Unknown
};

enum class DataTypeKeywordType
{
    StringKeyword,
    BooleanKeyword,
    BigIntKeyword,
    NullKeyword,
    UndefinedKeyword,
    SymbolKeyword,
    NeverKeyword,
    UnknownKeyword,
    AnyKeyword, 
    VoidKeyword,
    Unknown
};


enum class ContainerKeywordType{
    SetKeyword,
    ArrayKeyword,
    ObjectKeyword,
    MapKeyword,
    Unknown
};

class Keyword: public Component
{
    private:
        std::string value;
    public:
        Keyword(std::string letters): Component()
        {
            this->value = letters;
        }
        
        virtual ~Keyword() = default;
        virtual std::string getKeywordTypeAsString(KeywordType type);
        virtual ComponentType type(){ return ComponentType::Keyword;}
        virtual KeywordType keywordType(){ return KeywordType::Unknown;}
        virtual VariableKeywordType variableKeywordType(){ return VariableKeywordType::Unknown;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect() { assert(0); }
        virtual std::string getValue(){ return value;}
        virtual std::string getType(){return this->getTypeAsString(this->type());}
};

class ExtendsKeyword: public Keyword{
    private:
        std::string value; 
    public:
        ExtendsKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::ExtendsKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class DeleteKeyword: public Keyword{
    private:
        std::string value; 
    public:
        DeleteKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::DeleteKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class DebuggerKeyword: public Keyword{
    private:
        std::string value; 
    public:
        DebuggerKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::DebuggerKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class DefaultKeyword: public Keyword{
    private:
        std::string value; 
    public:
        DefaultKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::DefaultKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class ImportKeyword: public Keyword{
    private:
        std::string value; 
    public:
        ImportKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::ImportKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};


class InstanceOfKeyword: public Keyword{
    private:
        std::string value; 
    public:
        InstanceOfKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::InstanceOfKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class TypeOfKeyword: public Keyword{
    private:
        std::string value; 
    public:
        TypeOfKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::TypeOfKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class RequireKeyword: public Keyword{
    private:
        std::string value; 
    public:
        RequireKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::RequireKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class WithKeyword: public Keyword{
    private:
        std::string value; 
    public:
        WithKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::WithKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class AsKeyword: public Keyword{
    private:
        std::string value; 
    public:
        AsKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::AsKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class ImplementsKeyword: public Keyword{
    private:
        std::string value; 
    public:
        ImplementsKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::ImplementsKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class PackageKeyword: public Keyword{
    private:
        std::string value; 
    public:
        PackageKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::PackageKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class YieldKeyword: public Keyword{
    private:
        std::string value; 
    public:
        YieldKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::YieldKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class ConstructorKeyword: public Keyword{
    private:
        std::string value; 
    public:
        ConstructorKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::ConstructorKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class ModuleKeyword: public Keyword{
    private:
        std::string value; 
    public:
        ModuleKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::ModuleKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class GetKeyword: public Keyword{
    private:
        std::string value; 
    public:
        GetKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::GetKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class DeclareKeyword: public Keyword{
    private:
        std::string value; 
    public:
        DeclareKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::DeclareKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class FromKeyword: public Keyword{
    private:
        std::string value; 
    public:
        FromKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::FromKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class AwaitKeyword: public Keyword{
    private:
        std::string value; 
    public:
        AwaitKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::AwaitKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class AsyncKeyword: public Keyword{
    private:
        std::string value; 
    public:
        AsyncKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::AsyncKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class PromiseKeyword: public Keyword{
    private:
        std::string value; 
    public:
        PromiseKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::PromiseKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class SwitchKeyword: public Keyword{
    private:
        std::string value; 
    public:
        SwitchKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::SwitchKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class CaseKeyword: public Keyword{
    private:
        std::string value; 
    public:
        CaseKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::CaseKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class BreakKeyword: public Keyword{
    private:
        std::string value; 
    public:
        BreakKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::BreakKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class ReturnKeyword: public Keyword{
    private:
        std::string value; 
    public:
        ReturnKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::ReturnKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class IfKeyword: public Keyword{
    private:
        std::string value; 
    public:
        IfKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::IfKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class ElseKeyword: public Keyword{
    private:
        std::string value; 
    public:
        ElseKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::ElseKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class ForKeyword: public Keyword{
    private:
        std::string value; 
    public:
        ForKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::ForKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class WhileKeyword: public Keyword{
    private:
        std::string value; 
    public:
        WhileKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::WhileKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class DoKeyword: public Keyword{
    private:
        std::string value; 
    public:
        DoKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::DoKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class ContinueKeyword: public Keyword{
    private:
        std::string value; 
    public:
        ContinueKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::ContinueKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class OfKeyword: public Keyword{
    private:
        std::string value; 
    public:
        OfKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::OfKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class InKeyword: public Keyword{
    private:
        std::string value; 
    public:
        InKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::InKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class ErrorKeyword: public Keyword{
    private:
        std::string value; 
    public:
        ErrorKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::ErrorKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class TryKeyword: public Keyword{
    private:
        std::string value; 
    public:
        TryKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::TryKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class CatchKeyword: public Keyword{
    private:
        std::string value; 
    public:
        CatchKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::CatchKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class ThrowKeyword: public Keyword{
    private:
        std::string value; 
    public:
        ThrowKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::ThrowKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class FinallyKeyword: public Keyword{
    private:
        std::string value; 
    public:
        FinallyKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::FinallyKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class PrivateKeyword: public Keyword{
    private:
        std::string value; 
    public:
        PrivateKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::PrivateKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class PublicKeyword: public Keyword{
    private:
        std::string value; 
    public:
        PublicKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::PublicKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class ProtectedKeyword: public Keyword{
    private:
        std::string value; 
    public:
        ProtectedKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::ProtectedKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class StaticKeyword: public Keyword{
    private:
        std::string value; 
    public:
        StaticKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::StaticKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class NewKeyword: public Keyword{
    private:
        std::string value; 
    public:
        NewKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::NewKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class SuperKeyword: public Keyword{
    private:
        std::string value; 
    public:
        SuperKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::SuperKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};

class ThisKeyword: public Keyword{
    private:
        std::string value; 
    public:
        ThisKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        virtual KeywordType keywordType(){ return KeywordType::ThisKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getKeyWordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string inspect(){ return "Type " + getKeyWordType() + " - " + getValue();}
};
