#pragma once
#include <string>
#include "Keyword.h"
#include "../Component.h"
#include "../CharType.h"

class StringKeyword;
class BooleanKeyword;
class NumberKeyword;
class BigIntKeyword;
class NullKeyword;
class UndefinedKeyword;
class SymbolKeyword;
class NeverKeyword;
class VoidKeyword;
class UnknownKeyword;
class AnyKeyword; 

class DataTypeKeyword: public Keyword
{
    private:
        std::string value;
    public:
        DataTypeKeyword(std::string letters): Keyword(letters)
        {
            this->value = letters;
        }
        
        virtual ~DataTypeKeyword() = default;
        virtual std::string getDataTypeKeywordAsString(DataTypeKeywordType type);
        virtual KeywordType keywordType(){ return KeywordType::DataTypeKeyword;}
        virtual DataTypeKeywordType dataTypeKeywordType(){ return DataTypeKeywordType::Unknown;}
        virtual std::string inspect() { assert(0); }
        virtual std::string getValue(){ return value;}
        virtual std::string getKeywordType(){return this->getKeywordTypeAsString(this->keywordType());}
        virtual std::string getDataTypeKeywordType(){return this->getDataTypeKeywordAsString(this->dataTypeKeywordType());}
};

class StringKeyword: public DataTypeKeyword{
    private:
        std::string value; 
    public:
        StringKeyword(std::string letters): DataTypeKeyword(letters)
        {
            this->value = letters;
        }
        virtual DataTypeKeywordType dataTypeKeywordType(){ return DataTypeKeywordType::StringKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getDataTypeKeywordType(){return this->getDataTypeKeywordAsString(this->dataTypeKeywordType());}
        virtual std::string inspect(){ return "Type " + getDataTypeKeywordType() + " - " + getValue();}
};

class NumberKeyword: public DataTypeKeyword{
    private:
        std::string value; 
    public:
        NumberKeyword(std::string letters): DataTypeKeyword(letters)
        {
            this->value = letters;
        }
        virtual DataTypeKeywordType dataTypeKeywordType(){ return DataTypeKeywordType::NumberKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getDataTypeKeywordType(){return this->getDataTypeKeywordAsString(this->dataTypeKeywordType());}
        virtual std::string inspect(){ return "Type " + getDataTypeKeywordType() + " - " + getValue();}
};

class BooleanKeyword: public DataTypeKeyword{
    private:
        std::string value; 
    public:
        BooleanKeyword(std::string letters): DataTypeKeyword(letters)
        {
            this->value = letters;
        }
        virtual DataTypeKeywordType dataTypeKeywordType(){ return DataTypeKeywordType::BooleanKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getDataTypeKeywordType(){return this->getDataTypeKeywordAsString(this->dataTypeKeywordType());}
        virtual std::string inspect(){ return "Type " + getDataTypeKeywordType() + " - " + getValue();}
};

class BigIntKeyword: public DataTypeKeyword{
    private:
        std::string value; 
    public:
        BigIntKeyword(std::string letters): DataTypeKeyword(letters)
        {
            this->value = letters;
        }
        virtual DataTypeKeywordType dataTypeKeywordType(){ return DataTypeKeywordType::BigIntKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getDataTypeKeywordType(){return this->getDataTypeKeywordAsString(this->dataTypeKeywordType());}
        virtual std::string inspect(){ return "Type " + getDataTypeKeywordType() + " - " + getValue();}
};

class NullKeyword: public DataTypeKeyword{
    private:
        std::string value; 
    public:
        NullKeyword(std::string letters): DataTypeKeyword(letters)
        {
            this->value = letters;
        }
        virtual DataTypeKeywordType dataTypeKeywordType(){ return DataTypeKeywordType::NullKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getDataTypeKeywordType(){return this->getDataTypeKeywordAsString(this->dataTypeKeywordType());}
        virtual std::string inspect(){ return "Type " + getDataTypeKeywordType() + " - " + getValue();}
};

class UndefinedKeyword: public DataTypeKeyword{
    private:
        std::string value; 
    public:
        UndefinedKeyword(std::string letters): DataTypeKeyword(letters)
        {
            this->value = letters;
        }
        virtual DataTypeKeywordType dataTypeKeywordType(){ return DataTypeKeywordType::UndefinedKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getDataTypeKeywordType(){return this->getDataTypeKeywordAsString(this->dataTypeKeywordType());}
        virtual std::string inspect(){ return "Type " + getDataTypeKeywordType() + " - " + getValue();}
};

class SymbolKeyword: public DataTypeKeyword{
    private:
        std::string value; 
    public:
        SymbolKeyword(std::string letters): DataTypeKeyword(letters)
        {
            this->value = letters;
        }
        virtual DataTypeKeywordType dataTypeKeywordType(){ return DataTypeKeywordType::SymbolKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getDataTypeKeywordType(){return this->getDataTypeKeywordAsString(this->dataTypeKeywordType());}
        virtual std::string inspect(){ return "Type " + getDataTypeKeywordType() + " - " + getValue();}
};

class NeverKeyword: public DataTypeKeyword{
    private:
        std::string value; 
    public:
        NeverKeyword(std::string letters): DataTypeKeyword(letters)
        {
            this->value = letters;
        }
        virtual DataTypeKeywordType dataTypeKeywordType(){ return DataTypeKeywordType::NeverKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getDataTypeKeywordType(){return this->getDataTypeKeywordAsString(this->dataTypeKeywordType());}
        virtual std::string inspect(){ return "Type " + getDataTypeKeywordType() + " - " + getValue();}
};

class VoidKeyword: public DataTypeKeyword{
    private:
        std::string value; 
    public:
        VoidKeyword(std::string letters): DataTypeKeyword(letters)
        {
            this->value = letters;
        }
        virtual DataTypeKeywordType dataTypeKeywordType(){ return DataTypeKeywordType::VoidKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getDataTypeKeywordType(){return this->getDataTypeKeywordAsString(this->dataTypeKeywordType());}
        virtual std::string inspect(){ return "Type " + getDataTypeKeywordType() + " - " + getValue();}
};

class UnknownKeyword: public DataTypeKeyword{
    private:
        std::string value; 
    public:
        UnknownKeyword(std::string letters): DataTypeKeyword(letters)
        {
            this->value = letters;
        }
        virtual DataTypeKeywordType dataTypeKeywordType(){ return DataTypeKeywordType::UnknownKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getDataTypeKeywordType(){return this->getDataTypeKeywordAsString(this->dataTypeKeywordType());}
        virtual std::string inspect(){ return "Type " + getDataTypeKeywordType() + " - " + getValue();}
};

class AnyKeyword: public DataTypeKeyword{
    private:
        std::string value; 
    public:
        AnyKeyword(std::string letters): DataTypeKeyword(letters)
        {
            this->value = letters;
        }
        virtual DataTypeKeywordType dataTypeKeywordType(){ return DataTypeKeywordType::AnyKeyword;}
        virtual std::string getValue(){ return value;}
        virtual std::string getDataTypeKeywordType(){return this->getDataTypeKeywordAsString(this->dataTypeKeywordType());}
        virtual std::string inspect(){ return "Type " + getDataTypeKeywordType() + " - " + getValue();}
};