#include "../global.h"

/*
 * for����﷨��������
 */
void forStat ()
{
	int startBreakNum = iterBreakList; /* ��¼for��������ʼʱ��Ҫ�����break������� */
	int startContinueNum = iterCtnList; /* ��¼while��������ʼʱ��Ҫ�����continue������� */

	if (sym == forsym)
	{
		getSym ();

		if (sym == lparen)
		{
			getSym ();
			expression ();
			int L0 = iterCode; /* ��ת��� */

			if (sym == semic)
			{
				getSym ();
				expression ();

				int pos1 = iterCode; /* �������ڵ�iterCodeֵ�������ʱ��ʹ�� */
				gen (jpc, 0, 0);  /* ��ת��λ�û���ȷ����������� */
				gen (jmp, 0, 0);

				int L1 = iterCode; /* ��ת��� */

				if (sym == semic)
				{
					getSym ();
					expression ();
					gen (jmp, 0, L0);

					int L2 = iterCode; /* ��ת��� */

					if (sym == rparen)
					{
						getSym ();
						statement ();

						/* ����continue��� */
						for (int i = startContinueNum; i < iterCtnList; i++)
						{
							int pos = continueList[i];
							code[pos].offset = iterCode;
						}

						gen (jmp, 0, L1);
						
						/* ���� */
						code[pos1].offset = iterCode;
						code[pos1 + 1].offset = L2;
					}
					else /* ȱ��) */
					{
						error (14);
					}
				}
				else /* ȱ��; */
				{
					error (10);
				}
			}
			else /* ȱ��; */
			{
				error (10);
			}
		}
		else /* ȱ��( */
		{
			error (16);
		}
	}
	else /* ȱ��for */
	{
		error (31);
	}

	/* ����break��� */
	for (int i = startBreakNum; i < iterBreakList; i++)
	{
		int pos = breakList[i];
		code[pos].offset = iterCode;
	}
}