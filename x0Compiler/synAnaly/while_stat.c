#include "../global.h"

/*
 * while����﷨��������
 */
void while_stat ()
{
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
}