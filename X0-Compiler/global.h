#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_FILENAME 100        /* max length of file name */
#define MAX_SIZE_IDENT    20         /* max length of identifier */
#define MAX_SIZE_NUMBER   9          /* max digits of number */
#define MAX_SIZE_LINE     100		 /* max number of a line's character in input file */
#define MAX_SIZE_TABLE    100        /* max sizeArray of symbol table */
#define MAX_SIZE_CODE     1000       /* max number of intermidiate code */
#define MAX_SIZE_STACK    10000      /* max sizeArray of data stack */
#define MAX_SIZE_BREAK    1000       /* max number of 'break' statement */
#define MAX_SIZE_CONTINUE 1000       /* max number of 'continue' statement */
#define MAX_SIZE_BACKUP   100        /* max number of backups */
#define MAX_DIMENSION     10         /* max dimension of array */
#define MAX_NUM_FUNCTION  100        /* max number of functions */
#define FCTCODE_NUM       16         /* number of function code */
#define TERMINAL_SYM_NUM  58         /* number of terminal symbol */
#define RESERVE_WORD_NUM  27         /* number of reserved word */

/* terminal symbol */
typedef enum symbol
{
	nul, ident, mainsym, charsym, intsym, ifsym,
	elsesym, whilesym, readsym, writesym, plus, minus,
	times, slash, lparen, rparen, lbracket, rbracket, 
	lbrace, rbrace, semic, eql, great, less,
	greateql, lesseql, eqleql, neql, intnum, dblsym,
	andsym, orsym, forsym, modsym, oddsym, xorsym,
	incsym, decsym, notsym, brksym, ctnsym, exitsym,
	swtcsym, cassym, colonsym, defausym, dosym, reptsym,
	untlsym, bolsym, truesym, falsesym, doublenum, cstsym,
	comma, voidsym, retsym
}Symbol;

/* kind of the object stored in the symbol table */
typedef enum objectKind
{
	intVar, constIntVar, intArray,
	doubleVar, constDoubleVar, doubleArray,
	charVar, constCharVar, charArray,
	boolVar, constBoolVar, boolArray
}ObjectKind;

/* object stored in the symbol table */
typedef struct tableObject
{
	char name[MAX_SIZE_IDENT + 1];	/* name of the identifier */
	ObjectKind kind;				/* kind of the identifier */
	int offset;						/* offset relative to current activity record */
	int sizeArray[MAX_DIMENSION];	/* size of each dimension */
	int dimension;					/* the dimension of array */
	double value;					/* only used by constant */
}TableObject;

/* function code */
typedef enum fctCode
{
	lit, opr, lod, sto, cal, ini, jmp, jpc, add, tad
}FctCode;

/* intermediate code */
typedef struct instruction
{
	FctCode fct; /* function code */
	int operand1;
	int operand2;
	double operand3;
}Instruction;

/* object stored in data stack */
typedef struct stackObject
{
	int dataType; /* 1: int, 2: double, 3: char, 4: bool */
	int intData;
	double dblData;
}StackObject;

typedef enum retType
{
	Void, Int, Double, Char, Bool
}RetType;

/* information of function */
typedef struct functionInfo
{
	char name[MAX_SIZE_IDENT];
	int parameterNum;		/* number of parameters */
	int startINTCode;		/* position where the function starts in intermediate code */
	int posSymTables;		/* index of the function's symbol table in symTables */
	RetType retType;        /* type of return value */
}FunctionInfo;

/* backup object */
typedef struct backUp
{
	FILE* backupFin;                          /* backup the inputFile */
	Symbol backupSym;						  /* backup the sym */
	char backupCh;                            /* backup the ch */
	int backupPosCh;                          /* backup the posCh */
	char backupLineCache[MAX_SIZE_LINE];      /* backup the lineCache */
	int backupChNum;                          /* backup the chNum */
	double backupDoubleNum;                   /* backup the doubleNum */
	int backupIntNum;                         /* backup the intNum */
	char backupId[MAX_SIZE_IDENT + 1];        /* backup the id */
	int backupIterCode;                       /* in addition to above, iterCode also need to be backuped */
}BackUp;

extern char fileName[MAX_SIZE_FILENAME + 1];     /* file name */

/* 
 * variables used in lexical analysis
 */
extern BackUp backups[MAX_SIZE_BACKUP];			 /* backups of lexical analysis's status */
extern int iterBackUp;                           /* iterator of backups */
extern FILE* inputFile;							 /* input file */
extern enum symbol sym;                          /* current terminal symbol read by ReadSymbol() */
extern char ch;                                  /* current character read by ReadCh() */
extern int posCh;								 /* counter using by ReadCh() */
extern char lineCache[MAX_SIZE_LINE];            /* line cache using by ReadCh() */
extern int chNum;								 /* counter using by line cache */
extern double doubleNum;                         /* current floating number */
extern int intNum;                               /* current integer */
extern char id[MAX_SIZE_IDENT + 1];              /* name of current identifier */
extern char* reserveWord[RESERVE_WORD_NUM];      /* reserved word */
extern Symbol ssym[256];						 /* symbol-value of single character */
extern Symbol wsym[RESERVE_WORD_NUM];			 /* symbol-value corresponding to reserved word */

/* 
 * variables used in syntactical analysis
 */
extern int continueList[MAX_SIZE_CONTINUE];						 /* continue statement to be backfilled */
extern int iterCtnList;											 /* the iterator of continueList */
extern int breakList[MAX_SIZE_BREAK];							 /* break statement to be backfilled */
extern int iterBreakList;										 /* the iterator of breakList */
extern char* fctCodeString[FCTCODE_NUM];						 /* strings corresponding to function code */
extern Instruction code[MAX_SIZE_CODE];							 /* intermediate code */
extern int iterCode;											 /* position of next intermediate code */
extern TableObject symTables[MAX_NUM_FUNCTION][MAX_SIZE_TABLE];  /* symbol tables */
extern int iterators[MAX_NUM_FUNCTION];							 /* iterator of each symbol table */
extern int tableNum;                                             /* number of symbol tables */       
extern FunctionInfo fctInfo[MAX_NUM_FUNCTION];                   /* information of each function */
extern int iterFctInfo;                                          /* iterator of fctInfo */

/* 
 * lexical analyzer
 */
void ReadSymbol ();
void backup ();		/* backup the status of lexical analysis */
void recover ();	/* recover the status of lexical analysis from backups */

/* 
 * syntactical analyzer
 * Tip: If no error occurs, sym should be the first symbol when a syntactical analyzer starts, and
 * sym should be the following symbol at the end of analysis.
 */
void FunctionCall ();
void FunctionList ();
void VarDeclarationList (int* ptr_offset);
void VarDeclarationStat (int* ptr_offset);
void ConstDeclarationList (int* ptr_offset);
void ConstDeclarationStat (int* ptr_offset);
void StatementList ();
void statement ();
void type ();
void IfStat ();
void WhileStat ();
void ReadStat ();
void WriteStat ();
void CompoundStat ();
void ExpressionStat ();
void variable (ObjectKind* ptr_kind, int* ptr_offset, int* ptr_IncOrDec);
void SimpleVariable (ObjectKind* ptr_kind, int* ptr_offset);
void expression ();
void SimpleValue ();
void term ();
void factor ();
void AdditiveExpr ();
void ForStat ();
void ValueExpr ();
void BreakStat ();
void ExitStat ();
void ContinueStat ();
void SwitchStat ();
void DoWhileStat ();
void RepeatStat ();
void ReturnStat ();

/* add a new entry to symbol table */
void EnterTable (ObjectKind k, int offset, int* size, int dimension, double value);

/* search the position of an identifier in symbol table according to its name */
int FindPosition_V1 (char* identName, int pos);

/* search the position of an identifier in symbol table according to its offset */
int FindPosition_V2 (int offset, int pos);

/* search the position of a function in fctInfo according to its name */
int FindPosition_V3 (char* fctName);

/* error handler */
void ErrorHandler (int error_code);

/* generate an intermediate code */
void GenerateINTCode (FctCode fct, int operand1, int operand2, double operand3);	

/* interpret and execute intermidiate code */
void Interpret();