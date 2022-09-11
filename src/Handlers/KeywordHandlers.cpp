#include "KeywordHandlers.h"

std::map<std::string, KeywordType> KeywordHandlers::keywordToString =
{
    {"class", KeywordType::VariableKeyword},
    {"function", KeywordType::VariableKeyword},
    {"interface", KeywordType::VariableKeyword},
    {"enum", KeywordType::VariableKeyword},
    {"const", KeywordType::VariableKeyword},
    {"var", KeywordType::VariableKeyword},
    {"let", KeywordType::VariableKeyword},
    {"string", KeywordType::DataTypeKeyword},
    {"boolean", KeywordType::DataTypeKeyword},
    {"number", KeywordType::DataTypeKeyword},
    {"BigInt", KeywordType::DataTypeKeyword},
    {"symbol", KeywordType::DataTypeKeyword},
    {"null", KeywordType::DataTypeKeyword},
    {"undefined", KeywordType::DataTypeKeyword},
    {"never", KeywordType::DataTypeKeyword},
    {"any", KeywordType::DataTypeKeyword},
    {"void", KeywordType::DataTypeKeyword},
    {"unknown", KeywordType::DataTypeKeyword},
    {"Array", KeywordType::ContainerKeyword},
    {"Map", KeywordType::ContainerKeyword},
    {"Set", KeywordType::ContainerKeyword},
    {"Object", KeywordType::ContainerKeyword},
    {"extends", KeywordType::ExtendsKeyword},
    {"delete", KeywordType::DeleteKeyword},
    {"debugger", KeywordType::DebuggerKeyword},
    {"default", KeywordType::DefaultKeyword},
    {"import", KeywordType::ImportKeyword},
    {"instanceOf", KeywordType::InstanceOfKeyword},
    {"typeOf", KeywordType::TypeOfKeyword},
    {"require", KeywordType::RequireKeyword},
    {"as", KeywordType::AsKeyword},
    {"implements", KeywordType::ImplementsKeyword},
    {"package", KeywordType::PackageKeyword},
    {"yield", KeywordType::InstanceOfKeyword},
    {"constructor", KeywordType::ConstructorKeyword},
    {"module", KeywordType::ModuleKeyword},
    {"get", KeywordType::GetKeyword},
    {"declare", KeywordType::DeclareKeyword},
    {"from", KeywordType::FromKeyword},
    {"await", KeywordType::AwaitKeyword},
    {"async", KeywordType::AsyncKeyword},
    {"promise", KeywordType::PromiseKeyword},
    {"switch", KeywordType::SwitchKeyword},
    {"case", KeywordType::CaseKeyword},
    {"break", KeywordType::BreakKeyword},
    {"return", KeywordType::ReturnKeyword},
    {"if", KeywordType::IfKeyword},
    {"else", KeywordType::ElseKeyword},
    {"for", KeywordType::ForKeyword},
    {"while", KeywordType::WhileKeyword},
    {"do", KeywordType::DoKeyword},
    {"continue", KeywordType::ContinueKeyword},
    {"of", KeywordType::OfKeyword},
    {"in", KeywordType::InKeyword},
    {"error", KeywordType::ErrorKeyword},
    {"try", KeywordType::TryKeyword},
    {"catch", KeywordType::CatchKeyword},
    {"finally", KeywordType::FinallyKeyword},
    {"throw", KeywordType::ThrowKeyword},
    {"public", KeywordType::PublicKeyword},
    {"private", KeywordType::PrivateKeyword},
    {"protected", KeywordType::ProtectedKeyword},
    {"static", KeywordType::StaticKeyword},
    {"new", KeywordType::NewKeyword},
    {"super", KeywordType::SuperKeyword},
    {"this", KeywordType::ThisKeyword},
};

std::map<std::string, VariableKeywordType> KeywordHandlers::variableKeywordToString =
{
    {"class", VariableKeywordType::ClassKeyWord},
    {"function", VariableKeywordType::FunctionKeyWord},
    {"interface", VariableKeywordType::InterfaceKeyWord},
    {"enum", VariableKeywordType::EnumKeyWord},
    {"const", VariableKeywordType::ConstKeyWord},
    {"var", VariableKeywordType::VarKeyWord},
    {"let", VariableKeywordType::LetKeyWord},
};

std::map<std::string, ContainerKeywordType> KeywordHandlers::containerKeywordToString =
{
    {"Array", ContainerKeywordType::ArrayKeyword},
    {"Map", ContainerKeywordType::MapKeyword},
    {"Set", ContainerKeywordType::SetKeyword},
    {"Object", ContainerKeywordType::ObjectKeyword},
};

std::map<std::string, DataTypeKeywordType> KeywordHandlers::dataTypeKeywordToString =
{
    {"string", DataTypeKeywordType::StringKeyword},
    {"boolean", DataTypeKeywordType::BooleanKeyword},
    {"number", DataTypeKeywordType::NumberKeyword},
    {"BigInt", DataTypeKeywordType::BigIntKeyword},
    {"symbol", DataTypeKeywordType::SymbolKeyword},
    {"null", DataTypeKeywordType::NullKeyword},
    {"undefined", DataTypeKeywordType::UndefinedKeyword},
    {"never", DataTypeKeywordType::NeverKeyword},
    {"any", DataTypeKeywordType::AnyKeyword},
    {"void", DataTypeKeywordType::VoidKeyword},
    {"unknown", DataTypeKeywordType::UnknownKeyword},
};

std::shared_ptr<Component> KeywordHandlers::buildKeyword(std::string value)
{
    KeywordType keyword = KeywordHandlers::keywordToString[value];

    switch(keyword)
    {
        case KeywordType::ExtendsKeyword:
            return std::make_shared<ExtendsKeyword>(value);
        case KeywordType::DeleteKeyword:
            return std::make_shared<DeleteKeyword>(value);
        case KeywordType::DebuggerKeyword:
            return std::make_shared<DebuggerKeyword>(value);
        case KeywordType::DefaultKeyword:
            return std::make_shared<DefaultKeyword>(value);
        case KeywordType::ImportKeyword:
            return std::make_shared<ImportKeyword>(value);
        case KeywordType::InstanceOfKeyword:
            return std::make_shared<InstanceOfKeyword>(value);
        case KeywordType::RequireKeyword:
            return std::make_shared<RequireKeyword>(value);
        case KeywordType::AsKeyword:
            return std::make_shared<AsKeyword>(value);
        case KeywordType::ImplementsKeyword:
            return std::make_shared<ImplementsKeyword>(value);
        case KeywordType::PackageKeyword:
            return std::make_shared<PackageKeyword>(value);
        case KeywordType::YieldKeyword:
            return std::make_shared<YieldKeyword>(value);
        case KeywordType::ConstructorKeyword:
            return std::make_shared<ConstructorKeyword>(value);
        case KeywordType::ModuleKeyword:
            return std::make_shared<ModuleKeyword>(value);
        case KeywordType::GetKeyword:
            return std::make_shared<GetKeyword>(value);
        case KeywordType::DeclareKeyword:
            return std::make_shared<DeclareKeyword>(value);
        case KeywordType::FromKeyword:
            return std::make_shared<FromKeyword>(value);
        case KeywordType::AwaitKeyword:
            return std::make_shared<AwaitKeyword>(value);
        case KeywordType::AsyncKeyword:
            return std::make_shared<AsyncKeyword>(value);
        case KeywordType::PromiseKeyword:
            return std::make_shared<PromiseKeyword>(value);
        case KeywordType::SwitchKeyword:
            return std::make_shared<SwitchKeyword>(value);
        case KeywordType::CaseKeyword:
            return std::make_shared<CaseKeyword>(value);
        case KeywordType::BreakKeyword:
            return std::make_shared<BreakKeyword>(value);
        case KeywordType::ReturnKeyword:
            return std::make_shared<ReturnKeyword>(value);
        case KeywordType::IfKeyword:
            return std::make_shared<IfKeyword>(value);
        case KeywordType::ElseKeyword:
            return std::make_shared<ElseKeyword>(value);
        case KeywordType::ForKeyword:
            return std::make_shared<ForKeyword>(value);
        case KeywordType::WhileKeyword:
            return std::make_shared<WhileKeyword>(value);
        case KeywordType::DoKeyword:
            return std::make_shared<DoKeyword>(value);
        case KeywordType::ContinueKeyword:
            return std::make_shared<ContinueKeyword>(value);
        case KeywordType::OfKeyword:
            return std::make_shared<OfKeyword>(value);
        case KeywordType::InKeyword:
            return std::make_shared<InKeyword>(value);
        case KeywordType::ErrorKeyword:
            return std::make_shared<ErrorKeyword>(value);
        case KeywordType::TryKeyword:
            return std::make_shared<TryKeyword>(value);
        case KeywordType::CatchKeyword:
            return std::make_shared<CatchKeyword>(value);
        case KeywordType::FinallyKeyword:
            return std::make_shared<FinallyKeyword>(value);
        case KeywordType::ThrowKeyword:
            return std::make_shared<ThrowKeyword>(value);
        case KeywordType::PublicKeyword:
            return std::make_shared<PublicKeyword>(value);
        case KeywordType::PrivateKeyword:
            return std::make_shared<PrivateKeyword>(value);
        case KeywordType::ProtectedKeyword:
            return std::make_shared<ProtectedKeyword>(value);
        case KeywordType::StaticKeyword:
            return std::make_shared<StaticKeyword>(value);
        case KeywordType::SuperKeyword:
            return std::make_shared<SuperKeyword>(value);
        case KeywordType::NewKeyword:
            return std::make_shared<NewKeyword>(value);
        case KeywordType::ThisKeyword:
            return std::make_shared<ThisKeyword>(value);
        case KeywordType::VariableKeyword:
            return KeywordHandlers::buildVariableKeyword(value);
        case KeywordType::ContainerKeyword:
            return KeywordHandlers::buildContainerKeyword(value);
        case KeywordType::DataTypeKeyword:
            return KeywordHandlers::buildDataTypeKeyword(value);
        default:
            return std::make_shared<Name>(value);

    }
};


std::shared_ptr<Component> KeywordHandlers::buildVariableKeyword(std::string value)
{
    VariableKeywordType keyword = KeywordHandlers::variableKeywordToString[value];

    switch(keyword)
    {
        case VariableKeywordType::ClassKeyWord:
            return std::make_shared<ClassKeyWord>(value);
        case VariableKeywordType::FunctionKeyWord:
            return std::make_shared<FunctionKeyWord>(value);
        case VariableKeywordType::InterfaceKeyWord:
            return std::make_shared<InterfaceKeyWord>(value);
        case VariableKeywordType::EnumKeyWord:
            return std::make_shared<EnumKeyWord>(value);    
        case VariableKeywordType::ConstKeyWord:
            return std::make_shared<ConstKeyWord>(value);   
        case VariableKeywordType::VarKeyWord:
            return std::make_shared<VarKeyWord>(value);
        case VariableKeywordType::LetKeyWord:
            return std::make_shared<LetKeyWord>(value);
        default:
            return std::make_shared<Name>(value);
    }
}

std::shared_ptr<Component> KeywordHandlers::buildContainerKeyword(std::string value)
{
    ContainerKeywordType keyword = KeywordHandlers::containerKeywordToString[value];

    switch(keyword)
    {
        case ContainerKeywordType::ArrayKeyword:
            return std::make_shared<ArrayKeyword>(value);
        case ContainerKeywordType::MapKeyword:
            return std::make_shared<MapKeyword>(value);
        case ContainerKeywordType::SetKeyword:
            return std::make_shared<SetKeyword>(value);
        case ContainerKeywordType::ObjectKeyword:
            return std::make_shared<ObjectKeyword>(value);
        default:
            return std::make_shared<Name>(value);
    }
}


std::shared_ptr<Component> KeywordHandlers::buildDataTypeKeyword(std::string value)
{
    DataTypeKeywordType keyword = KeywordHandlers::dataTypeKeywordToString[value];

    switch(keyword)
    {
        case DataTypeKeywordType::StringKeyword:
            return std::make_shared<StringKeyword>(value);
        case DataTypeKeywordType::BooleanKeyword:
            return std::make_shared<BooleanKeyword>(value);
        case DataTypeKeywordType::NumberKeyword:
            return std::make_shared<NumberKeyword>(value);
        case DataTypeKeywordType::BigIntKeyword:
            return std::make_shared<BigIntKeyword>(value);
        case DataTypeKeywordType::SymbolKeyword:
            return std::make_shared<SymbolKeyword>(value);
        case DataTypeKeywordType::NullKeyword:
            return std::make_shared<NullKeyword>(value);
        case DataTypeKeywordType::UndefinedKeyword:
            return std::make_shared<UndefinedKeyword>(value);
        case DataTypeKeywordType::NeverKeyword:
            return std::make_shared<NeverKeyword>(value); 
        case DataTypeKeywordType::AnyKeyword:
            return std::make_shared<AnyKeyword>(value);  
        case DataTypeKeywordType::VoidKeyword:
            return std::make_shared<VoidKeyword>(value);
        case DataTypeKeywordType::UnknownKeyword:
            return std::make_shared<UnknownKeyword>(value);  
        default:
            return std::make_shared<Name>(value);
    }
}