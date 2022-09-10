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
$(OBJDIR)/Component.o \
$(OBJDIR)/Operator.o \
$(OBJDIR)/AssignmentOperator.o \
$(OBJDIR)/ArithmeticOperator.o \
$(OBJDIR)/ComparisonOperator.o \
$(OBJDIR)/LogicalOperator.o \
$(OBJDIR)/BitwiseOperator.o \
$(OBJDIR)/Keyword.o \
$(OBJDIR)/VariableKeyword.o \
$(OBJDIR)/Primitive.o \
$(OBJDIR)/PrimitiveHandlers.o \
$(OBJDIR)/ElementHandlers.o \
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
$(OBJDIR)/Component.o \
$(OBJDIR)/Operator.o \
$(OBJDIR)/AssignmentOperator.o \
$(OBJDIR)/ArithmeticOperator.o \
$(OBJDIR)/ComparisonOperator.o \
$(OBJDIR)/LogicalOperator.o \
$(OBJDIR)/BitwiseOperator.o \
$(OBJDIR)/Keyword.o \
$(OBJDIR)/VariableKeyword.o \
$(OBJDIR)/Primitive.o \
$(OBJDIR)/PrimitiveHandlers.o \
$(OBJDIR)/ElementHandlers.o \
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
$(OBJDIR)/LComponent.o \
$(OBJDIR)/LOperator.o \
$(OBJDIR)/LAssignmentOperator.o \
$(OBJDIR)/LArithmeticOperator.o \
$(OBJDIR)/LComparisonOperator.o \
$(OBJDIR)/LLogicalOperator.o \
$(OBJDIR)/LBitwiseOperator.o \
$(OBJDIR)/LKeyword.o \
$(OBJDIR)/LVariableKeyword.o \
$(OBJDIR)/LPrimitive.o \
$(OBJDIR)/LPropHandlers.o \
$(OBJDIR)/LPrimitiveHandlers.o \
$(OBJDIR)/LElementHandlers.o \
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

$(OBJDIR)/Primitive.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/Primitive.cpp -o $(OBJDIR)/Primitive.o

$(OBJDIR)/Component.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/Component.cpp -o $(OBJDIR)/Component.o

$(OBJDIR)/TokenHandlers.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Handlers/TokenHandlers.cpp -o $(OBJDIR)/TokenHandlers.o

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

$(OBJDIR)/Keyword.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/Keywords/Keyword.cpp -o $(OBJDIR)/Keyword.o

$(OBJDIR)/VariableKeyword.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/Keywords/VariableKeyword.cpp -o $(OBJDIR)/VariableKeyword.o

$(OBJDIR)/Symbol.o:
	$(CC) -c $(CCFLAGS) $(SRCDIR)/Types/Symbol.cpp -o $(OBJDIR)/Symbol.o

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

$(OBJDIR)/LPrimitiveHandlers.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Handlers/PrimitiveHandlers.cpp -o $(OBJDIR)/LPrimitiveHandlers.o

$(OBJDIR)/LPrimitive.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/Primitive.cpp -o $(OBJDIR)/LPrimitive.o

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

$(OBJDIR)/LKeyword.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/Keywords/Keyword.cpp -o $(OBJDIR)/LKeyword.o

$(OBJDIR)/LVariableKeyword.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/Keywords/VariableKeyword.cpp -o $(OBJDIR)/LVariableKeyword.o

$(OBJDIR)/LSymbol.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/Symbol.cpp -o $(OBJDIR)/LSymbol.o

$(OBJDIR)/LCharType.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Types/CharType.cpp -o $(OBJDIR)/LCharType.o

$(OBJDIR)/LComponentBuilder.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/ComponentBuilder.cpp -o $(OBJDIR)/LComponentBuilder.o

$(OBJDIR)/LTokenizer.o:
	$(CC) -c $(LIBCCFLAGS) $(SRCDIR)/Builders/Tokenizer.cpp -o $(OBJDIR)/LTokenizer.o
 
clean:
	rm -rf $(OBJDIR)/*.o $(TARGET) $(LIBTARGET) $(ARCHIVELIBTARGET)