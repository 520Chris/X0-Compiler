#include "../global.h"

/*
 * exitStat�﷨��������
 */
void exitStat ()
{
	if (sym == exitsym)
	{
		getSym ();

		if (sym == lparen)
		{
			getSym ();

			if (sym == number)
			{
				getSym ();

				if (sym == rparen)
				{
					getSym ();

					if (sym == semic)
					{
						getSym ();
						gen (opr, 0, 7);
					}
					else /* ȱ��; */
					{
						error (10);
					}
				}
				else /* ȱ��) */
				{
					error (14);
				}
			}
			else /* ȱ������ */
			{
				error (8);
			}
		}
		else /* ȱ��( */
		{
			error (16);
		}
	}
	else /* ȱ��exit */
	{
		error (35);
	}
}