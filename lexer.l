%option nounput
%option yylineno
%option noyywrap

%{

#include <iostream>
#include "parser.hpp"
#include "symboltable.hpp"
#include "symbol.hpp"

using namespace std;

extern SymbolTable *symbolTable;

%}

NEWLINE "\n"
TAB "\t"
SPACE " "
LETTER [a-zA-Z]
DIGIT [0-9]
INTEGER -?{DIGIT}+
REAL {DIGIT}*\.{DIGIT}+([eE][-+]?{DIGIT}+)?
ID {LETTER}({LETTER}|{DIGIT})*

%%

{SPACE} |
{TAB} |
{NEWLINE} |
"{"[^{]*"}" /* ignore */;

[\(\):;,\.\[\]] return yytext[0];

"program" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return PROGRAM;}

"var" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return VAR;}

"array" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return ARRAY;}

"of" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return OF;}

"integer" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return TOKEN_TYPE_INTEGER;}

"real" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return TOKEN_TYPE_REAL;}

"function" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return FUNCTION;}

"procedure" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return PROCEDURE;}

"begin" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return BEGIN_TOKEN;}

"end" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return END_TOKEN;}

"if" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return IF;}

"then" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return THEN;}

"else" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return ELSE;}

"while" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return WHILE;}

"do" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return DO;}

"div" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return DIV;}

"mod" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return MOD;}

"and" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return AND;}

"or" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return OR;}

"not" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return NOT;}

".." {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return DOTDOT;}

"+" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return PLUS;}

"-" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return MINUS;}

"/" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return DIVISION;}

"*" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return MULTIPLICATION;}

"=" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return RELOP;}

"<>" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return RELOP;}

"<" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return RELOP;}

">" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return RELOP;}

">=" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return RELOP;}

"<=" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return RELOP;}

":=" {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;
return ASSIGN;}

{INTEGER} {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;

    return INTEGER;
}

{REAL} {
cout<<endl<<endl<< "NON_TERMINAL YYLVAL (PREVIOUS TOKENINDEX): "<<yylval<<endl;
cout<<"NON_TERMINAL YYTEXT: "<<yytext<<endl;

    return REAL;
}

{ID} {
				cout<< endl<< endl<<"LEXER --{ID}--"<<endl;
				cout<<"YYTEXT: "<<yytext<<endl;
    int symbolIndex = symbolTable->lookupSymbol(yytext);
				cout<<endl<< "SYMBOLINDEX: " <<symbolIndex<<endl;

    if (symbolIndex == -1)
    {
				cout<<"WSTAWIAM SYMBOL DO TABLICY SYMBOLI: "<<endl;
    yylval = symbolTable->insertSymbol(yytext);
				cout<<"YYLVAL PO INSERT: "<<yylval<<endl;
				cout<<"YYTEXT PO INSERT: "<<yytext<<endl;
    } else {
				cout<<"NIE WSTAWIAM SYMBOL DO TABLICY SYMBOLI: "<<endl;
    yylval = symbolIndex;
				cout<<"YYLVAL BEZ INSERT: "<<yylval<<endl;
				cout<<"YYTEXT BEZ INSERT: "<<yytext<<endl;
    }

    return ID;

    return ID;
}

<<EOF>> return 0;

. {
    cout << "Mamy problem. Wykryto niepoprawny znak: " << yytext << endl;
}

%%
