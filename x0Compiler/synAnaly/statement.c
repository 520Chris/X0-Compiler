#include "../global.h"

/*
 * statement�﷨��������
 */
void statement ()
{
	if (sym == ifsym)	/* if��� */
	{
		ifStat ();
	}
	else if (sym == whilesym)	/* while��� */
	{
		whileStat ();
	}
	else if (sym == readsym)	/* read��� */
	{
		readStat ();
	}
	else if (sym == writesym)	/* write��� */
	{
		writeStat ();
	}
	else if (sym == lbrace)	/* compound��� */
	{
		compoundStat ();
	}
	else if (sym == semic || sym == ident || sym == hashsym
		|| sym == lparen || sym == number || sym == minus
		|| sym == incsym || sym == decsym || sym == oddsym || sym == notsym)	/* expression��� */
	{
		expressionStat ();
	}
	else if (sym == forsym) /* for��� */
	{
		forStat ();
	}
	else if (sym == brksym) /* break��� */
	{
		breakStat ();
	}
	else if (sym == exitsym) /* exit��� */
	{
		exitStat ();
	}
	else if (sym == ctnsym) /* continue��� */
	{
		continueStat ();
	}
	else /* ȱ��if��while��read��write��{��for��#���ʶ����(�����ֻ�-��++��--��odd��!��; */
	{
		error (19);
	}
}