# change application name here (executable output name)
TARGET=TypeScriptParser
TESTTARGET=Test_TypeScriptParser
LIBTARGET=libtypescriptparser.so
ARCHIVELIBTARGET=libtypescriptparser.a
# compiler
CC=g++
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall -Wextra -Werror
#src directory
SRCDIR=src
#object directoy
CPPVERSION=-std=c++17
LIBFLAGS=-fPIC
OBJDIR=obj
#Libraries
GTEST = /usr/local/lib/libgtest.a

#target directory

CCFLAGS=$(DEBUG) ${CPPVERSION} $(OPT) $(WARN) -pipe

LIBCCFLAGS=$(DEBUG) ${LIBFLAGS} ${CPPVERSION} $(OPT) $(WARN)
# linker
LD=g++
LDFLAGS=-lstdc++

LIBLDFLAGS=-lstdc++ -shared -W1,-soname,${LIBTARGET}

STATICLIBOBJ=$(OBJDIR)/CharType.o \
$(OBJDIR)/ComponentBuilder.o \
$(OBJDIR)/Tokenizer.o \
$(OBJDIR)/TokenHandlers.o \
$(OBJDIR)/Symbol.o \
$(OBJDIR)/WhiteSpace.o \
$(OBJDIR)/Component.o \
$(OBJDIR)/Operator.o \
$(OBJDIR)/AssignmentOperator.o \
$(OBJDIR)/ArithmeticOperator.o \
$(OBJDIR)/ComparisonOperator.o \
$(OBJDIR)/LogicalOperator.o \
$(OBJDIR)/BitwiseOperator.o \
$(OBJDIR)/OtherOperator.o \
$(OBJDIR)/Keyword.o \
$(OBJDIR)/VariableKeyword.o \
$(OBJDIR)/DataTypeKeyword.o \
$(OBJDIR)/ContainerKeyword.o \
$(OBJDIR)/Primitive.o \
$(OBJDIR)/CommentComponent.o \
$(OBJDIR)/DocTag.o \
$(OBJDIR)/PrimitiveHandlers.o \
$(OBJDIR)/ElementHandlers.o \
$(OBJDIR)/KeywordHandlers.o \
$(OBJDIR)/CommentHandlers.o \
$(OBJDIR)/OperatorHandlers.o \
$(OBJDIR)/ArithmeticOperatorHandlers.o \
$(OBJDIR)/AssignmentOperatorHandlers.o \
$(OBJDIR)/BitwiseOperatorHandlers.o \
$(OBJDIR)/ComparisonOperatorHandlers.o \
$(OBJDIR)/LogicalOperatorHandlers.o \
$(OBJDIR)/OtherOperatorHandlers.o \
$(OBJDIR)/PrimitiveBuilder.o \
$(OBJDIR)/ElementBuilder.o \
$(OBJDIR)/Element.o \
$(OBJDIR)/ComponentUtilities.o \
$(OBJDIR)/CharacterUtilities.o \
$(OBJDIR)/TokenizerUtilities.o \

OBJS=$(OBJDIR)/main.o\
$(OBJDIR)/CharType.o \
$(OBJDIR)/ComponentBuilder.o \
$(OBJDIR)/Tokenizer.o \
$(OBJDIR)/TokenHandlers.o \
$(OBJDIR)/Symbol.o \
$(OBJDIR)/WhiteSpace.o \
$(OBJDIR)/Component.o \
$(OBJDIR)/Operator.o \
$(OBJDIR)/AssignmentOperator.o \
$(OBJDIR)/ArithmeticOperator.o \
$(OBJDIR)/ComparisonOperator.o \
$(OBJDIR)/LogicalOperator.o \
$(OBJDIR)/BitwiseOperator.o \
$(OBJDIR)/OtherOperator.o \
$(OBJDIR)/Keyword.o \
$(OBJDIR)/VariableKeyword.o \
$(OBJDIR)/DataTypeKeyword.o \
$(OBJDIR)/ContainerKeyword.o \
$(OBJDIR)/Primitive.o \
$(OBJDIR)/CommentComponent.o \
$(OBJDIR)/DocTag.o \
$(OBJDIR)/PrimitiveHandlers.o \
$(OBJDIR)/ElementHandlers.o \
$(OBJDIR)/KeywordHandlers.o \
$(OBJDIR)/CommentHandlers.o \
$(OBJDIR)/OperatorHandlers.o \
$(OBJDIR)/ArithmeticOperatorHandlers.o \
$(OBJDIR)/AssignmentOperatorHandlers.o \
$(OBJDIR)/BitwiseOperatorHandlers.o \
$(OBJDIR)/ComparisonOperatorHandlers.o \
$(OBJDIR)/LogicalOperatorHandlers.o \
$(OBJDIR)/OtherOperatorHandlers.o \
$(OBJDIR)/PrimitiveBuilder.o \
$(OBJDIR)/ElementBuilder.o \
$(OBJDIR)/Element.o \
$(OBJDIR)/ComponentUtilities.o \
$(OBJDIR)/CharacterUtilities.o \
$(OBJDIR)/TokenizerUtilities.o 

LIBOBJS=$(OBJDIR)/LCharType.o \
$(OBJDIR)/LComponentBuilder.o \
$(OBJDIR)/LTokenizer.o \
$(OBJDIR)/LTokenHandlers.o \
$(OBJDIR)/LSymbol.o \
$(OBJDIR)/LWhiteSpace.o \
$(OBJDIR)/LComponent.o \
$(OBJDIR)/LOperator.o \
$(OBJDIR)/LAssignmentOperator.o \
$(OBJDIR)/LArithmeticOperator.o \
$(OBJDIR)/LComparisonOperator.o \
$(OBJDIR)/LLogicalOperator.o \
$(OBJDIR)/LBitwiseOperator.o \
$(OBJDIR)/LOtherOperator.o \
$(OBJDIR)/LKeyword.o \
$(OBJDIR)/LVariableKeyword.o \
$(OBJDIR)/LDataTypeKeyword.o \
$(OBJDIR)/LContainerKeyword.o \
$(OBJDIR)/LPrimitive.o \
$(OBJDIR)/LCommentComponent.o \
$(OBJDIR)/DocTag.o \
$(OBJDIR)/LPropHandlers.o \
$(OBJDIR)/LPrimitiveHandlers.o \
$(OBJDIR)/LElementHandlers.o \
$(OBJDIR)/LKeywordHandlers.o \
$(OBJDIR)/LCommentHandlers.o \
$(OBJDIR)/LOperatorHandlers.o \
$(OBJDIR)/LArithmeticOperatorHandlers.o \
$(OBJDIR)/LAssignmentOperatorHandlers.o \
$(OBJDIR)/LBitwiseOperatorHandlers.o \
$(OBJDIR)/LComparisonOperatorHandlers.o \
$(OBJDIR)/LLogicalOperatorHandlers.o \
$(OBJDIR)/LOtherOperatorHandlers.o \
$(OBJDIR)/LPrimitiveBuilder.o \
$(OBJDIR)/LElementBuilder.o \
$(OBJDIR)/LElement.o \
$(OBJDIR)/LProp.o \
$(OBJDIR)/LComponentUtilities.o \
$(OBJDIR)/LCharacterUtilities.o \
$(OBJDIR)/LTokenizerUtilities.o 


all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS)  $(LDFLAGS)

lib: $(LIBOBJS)
	$(LD) $(LIBLDFLAGS) -o $(LIBTARGET) $(LIBOBJS) -lc

staticLib: $(STATICLIBOBJ)
	ar rcs $(ARCHIVELIBTARGET) $(STATICLIBOBJ)

$(OBJDIR)/Prop.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/Prop.cpp -o $(OBJDIR)/Prop.o

$(OBJDIR)/Element.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/Element.cpp -o $(OBJDIR)/Element.o

$(OBJDIR)/ElementBuilder.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Builders/ElementBuilder.cpp -o $(OBJDIR)/ElementBuilder.o

$(OBJDIR)/PrimitiveBuilder.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Builders/PrimitiveBuilder.cpp -o $(OBJDIR)/PrimitiveBuilder.o

$(OBJDIR)/CharacterUtilities.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Utils/CharacterUtilities.cpp -o $(OBJDIR)/CharacterUtilities.o

$(OBJDIR)/ComponentUtilities.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Utils/ComponentUtilities.cpp -o $(OBJDIR)/ComponentUtilities.o

$(OBJDIR)/TokenizerUtilities.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Utils/TokenizerUtilities.cpp -o $(OBJDIR)/TokenizerUtilities.o

$(OBJDIR)/PropHandlers.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Handlers/PropHandlers.cpp -o $(OBJDIR)/PropHandlers.o

$(OBJDIR)/ElementHandlers.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Handlers/ElementHandlers.cpp -o $(OBJDIR)/ElementHandlers.o

$(OBJDIR)/PrimitiveHandlers.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Handlers/PrimitiveHandlers.cpp -o $(OBJDIR)/PrimitiveHandlers.o

$(OBJDIR)/CommentHandlers.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Handlers/CommentHandlers.cpp -o $(OBJDIR)/CommentHandlers.o

$(OBJDIR)/OperatorHandlers.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Handlers/OperatorHandlers.cpp -o $(OBJDIR)/OperatorHandlers.o

$(OBJDIR)/AssignmentOperatorHandlers.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Handlers/AssignmentOperatorHandlers.cpp -o $(OBJDIR)/AssignmentOperatorHandlers.o

$(OBJDIR)/ArithmeticOperatorHandlers.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Handlers/ArithmeticOperatorHandlers.cpp -o $(OBJDIR)/ArithmeticOperatorHandlers.o

$(OBJDIR)/BitwiseOperatorHandlers.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Handlers/BitwiseOperatorHandlers.cpp -o $(OBJDIR)/BitwiseOperatorHandlers.o

$(OBJDIR)/LogicalOperatorHandlers.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Handlers/LogicalOperatorHandlers.cpp -o $(OBJDIR)/LogicalOperatorHandlers.o

$(OBJDIR)/ComparisonOperatorHandlers.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Handlers/ComparisonOperatorHandlers.cpp -o $(OBJDIR)/ComparisonOperatorHandlers.o

$(OBJDIR)/OtherOperatorHandlers.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Handlers/OtherOperatorHandlers.cpp -o $(OBJDIR)/OtherOperatorHandlers.o

$(OBJDIR)/CommentComponent.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/CommentComponent.cpp -o $(OBJDIR)/CommentComponent.o

$(OBJDIR)/DocTag.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/DocTag.cpp -o $(OBJDIR)/DocTag.o

$(OBJDIR)/Primitive.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/Primitive.cpp -o $(OBJDIR)/Primitive.o

$(OBJDIR)/Component.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/Component.cpp -o $(OBJDIR)/Component.o

$(OBJDIR)/TokenHandlers.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Handlers/TokenHandlers.cpp -o $(OBJDIR)/TokenHandlers.o

$(OBJDIR)/KeywordHandlers.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Handlers/KeywordHandlers.cpp -o $(OBJDIR)/KeywordHandlers.o

$(OBJDIR)/Operator.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/Operators/Operator.cpp -o $(OBJDIR)/Operator.o

$(OBJDIR)/AssignmentOperator.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/Operators/AssignmentOperator.cpp -o $(OBJDIR)/AssignmentOperator.o

$(OBJDIR)/ArithmeticOperator.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/Operators/ArithmeticOperator.cpp -o $(OBJDIR)/ArithmeticOperator.o

$(OBJDIR)/ComparisonOperator.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/Operators/ComparisonOperator.cpp -o $(OBJDIR)/ComparisonOperator.o

$(OBJDIR)/LogicalOperator.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/Operators/LogicalOperator.cpp -o $(OBJDIR)/LogicalOperator.o

$(OBJDIR)/BitwiseOperator.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/Operators/BitwiseOperator.cpp -o $(OBJDIR)/BitwiseOperator.o

$(OBJDIR)/OtherOperator.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/Operators/OtherOperator.cpp -o $(OBJDIR)/OtherOperator.o

$(OBJDIR)/Keyword.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/Keywords/Keyword.cpp -o $(OBJDIR)/Keyword.o

$(OBJDIR)/VariableKeyword.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/Keywords/VariableKeyword.cpp -o $(OBJDIR)/VariableKeyword.o

$(OBJDIR)/DataTypeKeyword.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/Keywords/DataTypeKeyword.cpp -o $(OBJDIR)/DataTypeKeyword.o

$(OBJDIR)/ContainerKeyword.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/Keywords/ContainerKeyword.cpp -o $(OBJDIR)/ContainerKeyword.o

$(OBJDIR)/Symbol.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/Symbol.cpp -o $(OBJDIR)/Symbol.o

$(OBJDIR)/WhiteSpace.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/WhiteSpace.cpp -o $(OBJDIR)/WhiteSpace.o

$(OBJDIR)/CharType.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/CharType.cpp -o $(OBJDIR)/CharType.o

$(OBJDIR)/ComponentBuilder.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Builders/ComponentBuilder.cpp -o $(OBJDIR)/ComponentBuilder.o

$(OBJDIR)/Tokenizer.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Builders/Tokenizer.cpp -o $(OBJDIR)/Tokenizer.o

$(OBJDIR)/main.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o

##Library variants
$(OBJDIR)/LProp.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/Prop.cpp -o $(OBJDIR)/LProp.o

$(OBJDIR)/LElement.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/Element.cpp -o $(OBJDIR)/LElement.o

$(OBJDIR)/LElementBuilder.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Builders/ElementBuilder.cpp -o $(OBJDIR)/LElementBuilder.o

$(OBJDIR)/LPrimitiveBuilder.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Builders/PrimitiveBuilder.cpp -o $(OBJDIR)/LPrimitiveBuilder.o

$(OBJDIR)/LCharacterUtilities.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Utils/CharacterUtilities.cpp -o $(OBJDIR)/LCharacterUtilities.o

$(OBJDIR)/LComponentUtilities.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Utils/ComponentUtilities.cpp -o $(OBJDIR)/LComponentUtilities.o

$(OBJDIR)/LTokenizerUtilities.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Utils/LTokenizerUtilities.cpp -o $(OBJDIR)/LTokenizerUtilities.o

$(OBJDIR)/LPropHandlers.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Handlers/PropHandlers.cpp -o $(OBJDIR)/LPropHandlers.o

$(OBJDIR)/LElementHandlers.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Handlers/ElementHandlers.cpp -o $(OBJDIR)/LElementHandlers.o

$(OBJDIR)/LKeywordHandlers.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Handlers/KeywordHandlers.cpp -o $(OBJDIR)/LKeywordHandlers.o

$(OBJDIR)/LPrimitiveHandlers.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Handlers/PrimitiveHandlers.cpp -o $(OBJDIR)/LPrimitiveHandlers.o

$(OBJDIR)/LCommentHandlers.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Handlers/CommentHandlers.cpp -o $(OBJDIR)/LCommentHandlers.o

$(OBJDIR)/LOperatorHandlers.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Handlers/OperatorHandlers.cpp -o $(OBJDIR)/LOperatorHandlers.o

$(OBJDIR)/LAssignmentOperatorHandlers.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Handlers/AssignmentOperatorHandlers.cpp -o $(OBJDIR)/LAssignmentOperatorHandlers.o

$(OBJDIR)/LArithmeticOperatorHandlers.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Handlers/ArithmeticOperatorHandlers.cpp -o $(OBJDIR)/LArithmeticOperatorHandlers.o

$(OBJDIR)/LBitwiseOperatorHandlers.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Handlers/BitwiseOperatorHandlers.cpp -o $(OBJDIR)/LBitwiseOperatorHandlers.o

$(OBJDIR)/LLogicalOperatorHandlers.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Handlers/LogicalOperatorHandlers.cpp -o $(OBJDIR)/LLogicalOperatorHandlers.o

$(OBJDIR)/LComparisonOperatorHandlers.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Handlers/ComparisonOperatorHandlers.cpp -o $(OBJDIR)/LComparisonOperatorHandlers.o

$(OBJDIR)/LOtherOperatorHandlers.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Handlers/OtherOperatorHandlers.cpp -o $(OBJDIR)/LOtherOperatorHandlers.o

$(OBJDIR)/LPrimitive.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/Primitive.cpp -o $(OBJDIR)/LPrimitive.o

$(OBJDIR)/LCommentComponent.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/CommentComponent.cpp -o $(OBJDIR)/LCommentComponent.o

$(OBJDIR)/LDocTag.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/DocTag.cpp -o $(OBJDIR)/LDocTag.o

$(OBJDIR)/LComponent.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/Component.cpp -o $(OBJDIR)/LComponent.o

$(OBJDIR)/LTokenHandlers.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Handlers/TokenHandlers.cpp -o $(OBJDIR)/LTokenHandlers.o

$(OBJDIR)/LOperator.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/Operators/Operator.cpp -o $(OBJDIR)/LOperator.o

$(OBJDIR)/LAssignmentOperator.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/Operators/AssignmentOperator.cpp -o $(OBJDIR)/LAssignmentOperator.o

$(OBJDIR)/LArithmeticOperator.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/Operators/ArithmeticOperator.cpp -o $(OBJDIR)/LArithmeticOperator.o

$(OBJDIR)/LComparisonOperator.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/Operators/ComparisonOperator.cpp -o $(OBJDIR)/LComparisonOperator.o

$(OBJDIR)/LLogicalOperator.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/Operators/LogicalOperator.cpp -o $(OBJDIR)/LLogicalOperator.o

$(OBJDIR)/LBitwiseOperator.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/Operators/BitwiseOperator.cpp -o $(OBJDIR)/LBitwiseOperator.o

$(OBJDIR)/LOtherOperator.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/Operators/OtherOperator.cpp -o $(OBJDIR)/LOtherOperator.o

$(OBJDIR)/LKeyword.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/Keywords/Keyword.cpp -o $(OBJDIR)/LKeyword.o

$(OBJDIR)/LVariableKeyword.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/Keywords/VariableKeyword.cpp -o $(OBJDIR)/LVariableKeyword.o

$(OBJDIR)/LDataTypeKeyword.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/Keywords/DataTypeKeyword.cpp -o $(OBJDIR)/LDataTypeKeyword.o

$(OBJDIR)/LContainerKeyword.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/Keywords/ContainerKeyword.cpp -o $(OBJDIR)/LContainerKeyword.o

$(OBJDIR)/LSymbol.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/Symbol.cpp -o $(OBJDIR)/LSymbol.o

$(OBJDIR)/LWhiteSpace.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/WhiteSpace.cpp -o $(OBJDIR)/LWhiteSpace.o

$(OBJDIR)/LCharType.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/CharType.cpp -o $(OBJDIR)/LCharType.o

$(OBJDIR)/LComponentBuilder.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/ComponentBuilder.cpp -o $(OBJDIR)/LComponentBuilder.o

$(OBJDIR)/LTokenizer.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Builders/Tokenizer.cpp -o $(OBJDIR)/LTokenizer.o
 
clean:
	rm -rf $(OBJDIR)/*.o $(TARGET) $(LIBTARGET) $(ARCHIVELIBTARGET)