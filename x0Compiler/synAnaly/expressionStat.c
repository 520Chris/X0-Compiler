#include "../global.h"

/*
 * expressionStat�﷨��������
 */
void expressionStat ()
{
	/* ���sym����first(expression)����ִ��expression�﷨�������� */
	if (sym == hashsym || sym == ident|| sym == lparen 
		|| sym == number || sym == minus || sym == incsym 
		|| sym == decsym || sym == oddsym || sym == notsym)
	{
		expression ();

		if (sym == semic)
		{
			getSym ();
		}
		else /* ȱ��; */
		{
			error (10);
		}
	}
	else if (sym == semic)
	{
		getSym ();
	}
	else /* ȱ��#���ʶ����(�����ֻ�-��++��--��odd��!��; */
	{
		error (13);
	}
}