#include "../global.h"

/*
 * while����﷨��������
 */
void while_stat ()
{
	if (sym == whilesym)
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
	else /* ȱ��while */
	{
		error (21);
	}
}