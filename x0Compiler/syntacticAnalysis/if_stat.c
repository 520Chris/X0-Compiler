#include "../global.h"

/*
 * if����﷨��������
 */
void if_stat ()
{
	if (sym == ifsym)
	{
		getSym ();
		if (sym == lparen)
		{
			getSym ();
			expression ();
			if (sym == rparen)
			{
				getSym ();
				statement ();
				if (sym == elsesym)
				{
					getSym ();
					statement ();
				}
			}
			else /* ȱ��) */
			{
				error (14);
			}
		}
		else /* ȱ��( */
		{
			error (16);
		}
	}
	else /* ȱ��if */
	{
		error (17);
	}
}