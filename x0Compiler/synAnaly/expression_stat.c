#include "../global.h"

/*
 * expression_stat�﷨��������
 */
void expression_stat ()
{
	/* ���sym����first(expression)����ִ��expression�﷨�������� */
	if (sym == hashsym || sym == ident|| sym == lparen || sym == number || sym == minus)
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
	else /* ȱ��#���ʶ�������ֻ�(��; */
	{
		error (13);
	}
}