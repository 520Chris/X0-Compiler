#include "../global.h"

/*
 * if����﷨��������
 */
void ifStat ()
{
	if (sym == ifsym)
	{
		getSym ();
		if (sym == lparen)
		{
			getSym ();
			expression ();

			int pos1 = iterCode; /* �������ڵ�iterCodeֵ�������ʱ��ʹ�� */
			gen (jpc, 0, 0);  /* ��ת��λ�û���ȷ����������� */

			if (sym == rparen)
			{
				getSym ();
				statement ();

				if (sym == elsesym)
				{
					int pos2 = iterCode; /* �������ڵ�iterCodeֵ�������ʱ��ʹ�� */
					gen (jmp, 0, 0);  /* ��ת��λ�û���ȷ����������� */
					
					code[pos1].offset = iterCode; /* ���� */

					getSym ();
					statement ();

					code[pos2].offset = iterCode; /* ���� */
				}
				else
				{
					code[pos1].offset = iterCode; /* ���� */
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
	else /* ȱ��if */
	{
		error (17);
	}
}