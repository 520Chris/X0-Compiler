#include "../global.h"

/*
 * compound_stat�﷨��������
 */
void compound_stat ()
{
	if (sym == lbrace)
	{
		getSym ();
		statement_list ();
		if (sym == rbrace)
		{
			getSym ();
		}
		else /* ȱ��} */
		{
			error (4);
		}
	}
	else /* ȱ��{ */
	{
		error (5);
	}
}