#include "../global.h"

/*
 * while����﷨��������
 */
void whileStat ()
{
	int startBreakNum = iterBreakList; /* ��¼while��������ʼʱ��Ҫ�����break������� */

	int startContinueNum = iterCtnList; /* ��¼while��������ʼʱ��Ҫ�����continue������� */

	if (sym == whilesym)
	{
		getSym ();

		if (sym == lparen)
		{
			int pos1 = iterCode; /* �������ڵ�iterCodeֵ */

			getSym ();
			expression ();

			if (sym == rparen)
			{
				int pos2 = iterCode; /* �������ڵ�iterCodeֵ�������ʱ��ʹ�� */

				gen (jpc, 0, 0);  /* ��ת��λ�û���ȷ����������� */
				
				getSym ();
				statement ();

				/* ����continue��� */
				for (int i = startContinueNum; i < iterCtnList; i++)
				{
					int pos = continueList[i];
					code[pos].offset = iterCode;
				}

				iterCtnList = startContinueNum; /* ��iterCtnList����Ϊ�տ�ʼ��ֵ */

				gen (jmp, 0, pos1);
				code[pos2].offset = iterCode;
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

	/* ����break��� */
	for (int i = startBreakNum; i < iterBreakList; i++)
	{
		int pos = breakList[i];
		code[pos].offset = iterCode;
	}

	iterBreakList = startBreakNum; /* ��iterBreakList����Ϊ�տ�ʼ��ֵ */
}