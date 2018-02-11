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
	
    void createPushStatement(Symbol symbol);
    void createIncSPStatement();
	void createExitStatement();
    void createJumpStatement(string labelName);
    void createLabelStatement(string labelName);
    void createArithmeticStatement(Symbol left, Symbol right, Symbol dst, char op);
    void createIntToRealStatement(Symbol src, Symbol dst);
    void createRealToIntStatement(Symbol src, Symbol dst);
    void createMovStatement(Symbol src, Symbol dst, VarType varType);
    void createAssignmentStatement();
    void createWriteStatement(Symbol symbol);
    void createReadStatement();
    void createCallStatement(string procedureName);
    void createProcedureEnterStatement(string func, int numberOfArguments);
    void createEnterPlaceholder(string func);
    void createSubProgramReturnStatements();
    int getNumberOfPushes()
    {
        return this->numberOfPushes;
    }
};

#endif