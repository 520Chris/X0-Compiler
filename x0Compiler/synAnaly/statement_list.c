#include "../global.h"

/*
 * statement_list�﷨��������
 */
void statement_list ()
{
	/* ���sym����first(statement)��ִ��statement�������� */
	while (sym == ifsym || sym == whilesym || sym == readsym
		|| sym == writesym || sym == lbrace || sym == semic
		|| sym == ident || sym == lparen || sym == number || sym == hashsym)
	{
		statement ();
	}
}