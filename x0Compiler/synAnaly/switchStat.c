#include "../global.h"

/*
 * switchStat�﷨��������
 */
void switchStat ()
{
	int startBreakNum = iterBreakList; /* ��¼switch��������ʼʱ��Ҫ�����break������� */
	
	if (sym == swtcsym)
	{
		getSym ();

		if (sym == lparen)
		{
			getSym ();
			expression ();

			if (sym == rparen)
			{
				getSym ();

				if (sym == lbrace)
				{
					getSym ();
					int pos1 = -1; /* ��һ��case���������jpcλ�� */
					int pos2 = -1; /* ��һ��case���������jmpλ�� */

					while (sym == cassym)
					{
						if (pos1 != -1)
						{
							code[pos1].offset = iterCode; /* ���� */
						}
						
						getSym ();

						if (sym == number)
						{
							gen (lit, 0, num);
							gen (opr, 0, 21);
							gen (jpc, 0, 0);
							pos1 = iterCode - 1;
							getSym ();

							if (sym == colonsym)
							{
								getSym ();

								if (pos2 != -1)
								{
									code[pos2].offset = iterCode; /* ���� */
								}

								statementList ();
								gen (jmp, 0, 0);
								pos2 = iterCode - 1;
							}
							else /* ȱ��: */
							{
								error (38);
							}
						}
						else /* ȱ������ */
						{
							error (8);
						}
					}

					if (pos1 != -1)
					{
						code[pos1].offset = iterCode; /* ���� */
					}

					if (pos2 != -1)
					{
						code[pos2].offset = iterCode; /* ���� */
					}

					if (sym == defausym)
					{
						getSym ();

						if (sym == colonsym)
						{
							getSym ();
							statementList ();
						}
						else /* ȱ��: */
						{
							error (38);
						}
					}

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
	else /* ȱ��switch */
	{
		error (37);
	}

	/* ����break��� */
	for (int i = startBreakNum; i < iterBreakList; i++)
	{
		int pos = breakList[i];
		code[pos].offset = iterCode;
	}

	iterBreakList = startBreakNum; /* ��iterBreakList����Ϊ�տ�ʼ��ֵ */
}