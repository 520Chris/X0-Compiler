#include "../global.h"

/*
 * statementList�﷨��������
 */
void statementList ()
{
	/* ���sym����first(statement)��ִ��statement�������� */
	while (sym == ifsym || sym == whilesym || sym == readsym
		|| sym == writesym || sym == lbrace || sym == semic
		|| sym == ident || sym == lparen || sym == number
		|| sym == hashsym || sym == minus || sym == forsym
		|| sym == incsym || sym == decsym || sym == oddsym
		|| sym == notsym || sym == brksym || sym == exitsym
		|| sym == ctnsym || sym == swtcsym || sym == dosym 
		|| sym == reptsym || sym == truesym || sym == falsesym)
	{
		statement ();
	}
}