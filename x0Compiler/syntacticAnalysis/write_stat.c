#include "../global.h"

/*
 * write����﷨��������
 */
void write_stat ()
{
	if (sym == writesym)
	{
		getSym ();
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
	else /* ȱ��write */
	{
		error (22);
	}
}