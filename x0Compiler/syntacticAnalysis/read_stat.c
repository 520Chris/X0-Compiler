#include "../global.h"

/*
 * read����﷨��������
 */
void read_stat ()
{
	if (sym == readsym)
	{
		getSym ();
		var ();
		if (sym == semic)
		{
			getSym ();
		}
		else /* ȱ��; */
		{
			error (10);
		}
	}
	else /* ȱ��read */
	{
		error (18);
	}
}