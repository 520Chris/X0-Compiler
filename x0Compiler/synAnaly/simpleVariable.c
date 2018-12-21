#include "../global.h"

/*
 * simpleVariable�﷨��������
 */
void simpleVariable (int* ptr_offset, int* ptr_isArray)
{
	if (sym == ident)
	{
		int pos = findPosition (id);

		if (pos == -1)	/* ��ʶ��δ���� */
		{
			error (24);
		}

		getSym ();

		if (sym == lbracket)
		{
			getSym ();
			expression ();

			if (sym == rbracket)
			{
				/* ��ʶ������int��char���� */
				if (table[pos].kind != intArray && table[pos].kind != charArray)
				{
					error (26);
				}

				*ptr_offset = table[pos].offset;
				*ptr_isArray = 1;
				getSym ();
			}
			else /* ȱ��] */
			{
				error (9);
			}
		}
		else
		{
			/* ��ʶ������int��char���� */
			if (table[pos].kind != intVar && table[pos].kind != charVar)
			{
				error (25);
			}

			*ptr_offset = table[pos].offset;
			*ptr_isArray = 0;
		}
	}
	else /* ȱ�ٱ�ʶ�� */
	{
		error (6);
	}
}