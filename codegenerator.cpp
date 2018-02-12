#include "codegenerator.hpp"
#include "symboltable.hpp"

extern SymbolTable *symbolTable;

CodeGenerator::CodeGenerator()
{
    this->outputFile.open("output.asm");
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
	cout<<"----------DST.getBPOperand "<<dst.getBPOperand()<<endl;
    this->output << "\tmov." << opType << " " << dst.getBPOperand();
    this->output << "," << src.getBPOperand();
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
                     << symbol.getBPOperand() << " " << endl;
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
        this->output << "\tadd." << operationType << " " << left.getBPOperand() << ","
             << right.getBPOperand() << "," << dst.getBPOperand() << endl;
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
    this->output << "\tinttoreal.i " << src.getBPOperand() << "," << dst.getBPOperand()
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

void CodeGenerator::createIncreaseSPStatement()
{
    if (this->numberOfPushes != 0)
    {
        symbolTable->insertConstant(this->numberOfPushes * 4);
        this->output << "\tincsp.i #" << this->numberOfPushes * 4 << endl;
        this->numberOfPushes = 0;
    }
}

void CodeGenerator::createJumpLessStatement(Symbol left, Symbol right, Symbol label)
{
    if (left.getVarType() == right.getVarType())
    {
        if (left.getVarType() == INT_TYPE)
        {
            this->output << "\tjl.i " << left.getBPOperand() << ","
                         << right.getBPOperand() << ",#" << label.getSymbolName()
                         << endl;
        }
    }
}

void CodeGenerator::createJumpEqualStatement(Symbol left, Symbol right, Symbol label)
{
    this->output << "\tje.i " << left.getBPOperand() << ","
                 << right.getBPOperand() << ",#" << label.getSymbolName()
                 << endl;
}


void CodeGenerator::createAndStatement(Symbol left, Symbol right, Symbol to)
{
    this->output << "\tand.i " << left.getBPOperand() << ","
                 << right.getBPOperand() << ","
                 << to.getBPOperand()
                 << endl;
}
void CodeGenerator::createOrStatement(Symbol left, Symbol right, Symbol to)
{
    this->output << "\tor.i " << left.getBPOperand() << ","
                 << right.getBPOperand() << ","
                 << to.getBPOperand()
                 << endl;
}



CodeGenerator *codeGenerator = new CodeGenerator();