#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include <string>
#include <vector>
#include "symbol.hpp"

using namespace std;

class SymbolTable
{
private:
    string name;
    int address;
	int nextLabelId;
    SymbolTable *parent;
    string printTable(SymbolTable *table);

public:
    int enterArg;
    int temporaryVariableCount;
    vector<Symbol *> *symbols;
    vector<SymbolTable *> *children;
	vector<string> pendingLabels;
    int localSpaceAddress;
    int lastLocalSpaceAddress;
    SymbolTable();
    ~SymbolTable();
    int lookupSymbol(const char *symbol);
    int lookupSymbol(int intValue);
    int lookupSymbol(double doubleValue);
    int createTemporaryVariable(VarType varType);
    Symbol &getSymbolByIndex(int tokenIndex);
    int insertSymbol(const char *symbol);
    int insertSymbol(const char *symbol, VarType varType);
    int insertConstant(int intValue);
    int insertDoubleConstant(double doubleValue);
    string commandLineTablePrint();
    void increaseAddress(int increaseBy);
    int getAddress();
    SymbolTable *addNewSymbolTable(string name);
    string getName()
    {cout<<"@@@@SYMBOLTABLE@@@@ NAME: "<<this->name<<endl<<endl;
      return this->name;
    }
    Symbol* lookupFuncReturnReference(string funcName);
    int lookupReturnVariable(Symbol funcSymbol);
    int createReference(string name, VarType type);
    int createLabel(bool pending);
    string getNextLabel(bool remove = true);
    string getLastPendingLabel()
    {
        return this->pendingLabels[this->pendingLabels.size() - 1];
    }
};

#endif