#include "../global.h"

/*
 * compoundStat�﷨��������
 */
void compoundStat ()
{
	if (sym == lbrace)
	{
		getSym ();
		statementList ();
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