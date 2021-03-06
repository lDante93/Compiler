#ifndef CODE_GENERATOR_HPP
#define CODE_GENERATOR_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

#include "symbol.hpp"

using namespace std;


class CodeGenerator
{
private:
    stringstream output;
    ofstream outputFile;
    int numberOfPushes;

public:
    CodeGenerator();
    ~CodeGenerator();
 
    void createExitStatement();
    void createJumpStatement(string labelName);
    void createLabelStatement(string labelName);
    void createMovStatement(Symbol src, Symbol dst, VarType varType);
    void createAssignmentStatement();
    void createWriteStatement(Symbol symbol);
    void createReadStatement(Symbol symbol);
    void createArithmeticStatement(Symbol left, Symbol right, Symbol dst, char op);
    void createDivStatement(Symbol left, Symbol right, Symbol dst);
    void createModStatement(Symbol left, Symbol right, Symbol dst);
    void createIntToRealStatement(Symbol src, Symbol dst);
    void createRealToIntStatement(Symbol src, Symbol dst);
    void createProcedureEnterStatement(string func, int numberOfArguments);
    void createEnterPlaceholder(string func);
    void createSubProgramReturnStatements();
    void createCallStatement(string procedureName);
    void createPushStatement(Symbol symbol);
    void createIncreaseSPStatement();
    int getNumberOfPushes() {return this->numberOfPushes;}
    void createJumpLessStatement(Symbol left, Symbol right, Symbol label);
    void createJumpGreaterStatement(Symbol left, Symbol right, Symbol label);
    void createJumpEqualStatement(Symbol left, Symbol right, Symbol label);
    void createAndStatement(Symbol left, Symbol right, Symbol to);
    void createOrStatement(Symbol left, Symbol right, Symbol to);
};

#endif