#include "../global.h"

/*
 * for����﷨��������
 */
void forStat ()
{
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
}