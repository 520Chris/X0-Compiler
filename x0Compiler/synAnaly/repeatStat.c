#include "../global.h"

/*
 * repeatStat�﷨��������
 */
void repeatStat ()
{
	if (sym == reptsym)
	{
		getSym ();

		if (sym == lbrace)
		{
			getSym ();

			int pos = iterCode; /* ��¼��statementList��һ�������λ�� */

			statementList ();

			if (sym == rbrace)
			{
				getSym ();

				if (sym == untlsym)
				{
					getSym ();

					if (sym == lparen)
					{
						getSym ();
						expression ();
						gen (jpc, 0, pos);

						if (sym == rparen)
						{
							getSym ();

							if (sym == semic)
							{
								getSym ();
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
	else /* ȱ��do */
	{
		error (39);
	}
}