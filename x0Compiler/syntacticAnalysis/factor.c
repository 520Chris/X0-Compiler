#include "../global.h"

/*
 * factor�﷨��������
 */
void factor ()
{
	if (sym == lparen)
	{
		getSym ();
		expression ();
		if (sym == rparen)
		{
			getSym ();
		}
		else /* ȱ��) */
		{
			error (14);
		}
	}
	else if (sym == ident)
	{
		var ();
	}
	else if (sym == number)
	{
		getSym ();
	}
	else /* ȱ��(���ʶ�������� */
	{
		error (15);
	}
}