#include "../global.h"

/*
 * continueStat�﷨��������
 */
void continueStat ()
{
	if (sym == ctnsym)
	{
		getSym ();

		if (sym == semic)
		{
			getSym ();
			gen (jmp, 0, 0);
			continueList[iterCtnList++] = iterCode - 1;
		}
		else /* ȱ��; */
		{
			error (10);
		}
	}
	else /* ȱ��continue */
	{
		error (36);
	}
}