#include "../global.h"

/*
 * breakStat�﷨��������
 */
void breakStat ()
{
	if (sym == brksym)
	{
		getSym ();

		if (sym == semic)
		{
			getSym ();
			gen (jmp, 0, 0);
			breakList[iterBreakList++] = iterCode - 1;
		}
		else /* ȱ��; */
		{
			error (10);
		}
	}
	else /* ȱ��break */
	{
		error (34);
	}
}