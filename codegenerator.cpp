#include "codegenerator.hpp"
#include "symboltable.hpp"

extern SymbolTable *symbolTable;

CodeGenerator::CodeGenerator()
{
    this->outputFile.open("output.asm");
    this->output.precision(2);
}

CodeGenerator::~CodeGenerator()
{
    this->outputFile << this->output.str();
    this->outputFile.close();
}

void CodeGenerator::createExitStatement()
{
    this->output << "\texit" << endl;
}

void CodeGenerator::createJumpStatement(string labelName)
{
    this->output << "\tjump.i #" << labelName << endl;
}

void CodeGenerator::createLabelStatement(string labelName)
{
    this->output << labelName << ":" << endl;
}

void CodeGenerator::createMovStatement(Symbol src, Symbol dst, VarType varType)
{
    char opType = varType == INT_TYPE ? 'i' : 'r';
	cout<<"----------DST.GETASMOPERAND "<<dst.getASMOperand()<<endl;
    this->output << "\tmov." << opType << " " << dst.getASMOperand();
    this->output << "," << src.getASMOperand();
    this->output << endl;
}

void CodeGenerator::createAssignmentStatement()
{
    this->output << "\tmov" << endl;
}

void CodeGenerator::createWriteStatement(Symbol symbol)
{
    char opType = symbol.getVarType() == INT_TYPE ? 'i' : 'r';
    this->output << "\twrite." << opType << " "
                     << symbol.getASMOperand() << " " << endl;
}

void CodeGenerator::createReadStatement()
{
    this->output << "\tread" << endl;
}

void CodeGenerator::createArithmeticStatement(Symbol left, Symbol right, Symbol dst, char op)
{
    char operationType = left.getVarType() == INT_TYPE ? 'i' : 'r';
    switch (op)
    {
    case '+':
        this->output << "\tadd." << operationType << " " << left.getASMOperand() << ","
             << right.getASMOperand() << "," << dst.getASMOperand() << endl;
        break;
    case '*':
        this->output << "\tmul." << operationType << " " << left.getAddress() << ","
                         << right.getAddress() << "," << dst.getAddress() << endl;
        break;
    case '-':
        this->output << "\tsub." << operationType << " " << left.getAddress() << ","
                         << right.getAddress() << "," << dst.getAddress() << endl;
        break;
    }
}

void CodeGenerator::createIntToRealStatement(Symbol src, Symbol dst)
{
    this->output << "\tinttoreal.i " << src.getASMOperand() << "," << dst.getASMOperand()
                 << endl;
}

void CodeGenerator::createRealToIntStatement(Symbol src, Symbol dst)
{
    this->output << "\trealtoint.r " << src.getAddress() << "," << dst.getAddress()
                 << endl;
}

bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if (start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

void CodeGenerator::createProcedureEnterStatement(string func, int num)
{
    string s("$enter-" + func);
    string tmp(this->output.str());
    replace(tmp, s, "enter.i #" + std::to_string(num));
    this->output.str("");
    this->output << tmp;
}

void CodeGenerator::createEnterPlaceholder(string func)
{
    this->output << "\t$enter-" << func << endl;
}

void CodeGenerator::createSubProgramReturnStatements()
{
    this->output << "\tleave" << endl
                 << "\treturn" << endl;
}

void CodeGenerator::createCallStatement(string procedureName)
{
    this->output << "\tcall.i #" << procedureName << endl;
}

void CodeGenerator::createPushStatement(Symbol symbol)
{
    this->numberOfPushes += 1;
    this->output << "\tpush.i #" << symbol.getAddress();
    this->output << endl;
}

void CodeGenerator::createIncSPStatement()
{
    if (this->numberOfPushes != 0)
    {
        symbolTable->insertConstant(this->numberOfPushes * 4);
        this->output << "\tincsp.i #" << this->numberOfPushes * 4 << endl;
        this->numberOfPushes = 0;
    }
}

CodeGenerator *codeGenerator = new CodeGenerator();