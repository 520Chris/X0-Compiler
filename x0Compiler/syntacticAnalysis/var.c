#include "../global.h"

/*
 * var�﷨��������
 */
void var ()
{
	if (sym == ident)
	{
		/* �����ʱ�ı�ʶ������ */
		char tempId[MAX_SIZE_IDENT + 1];
		strcpy (tempId, id);

		getSym ();
		if (sym == lbracket)
		{
			getSym ();
			expression ();
			if (sym == rbracket)
			{
				int pos = findPosition (tempId);
				if (pos == -1)	/* ��ʶ��δ���� */
				{
					error (24);
				}
				/* ��ʶ������int��char���� */
				else if (table[pos].kind != intArray 
					&& table[pos].kind != charArray)
				{
					error (26);
				}

				getSym ();
			}
			else /* ȱ��] */
			{
				error (9);
			}
		}
		else
		{
			int pos = findPosition (tempId);
			if (pos == -1)	/* ��ʶ��δ���� */
			{
				error (24);
			}
			/* ��ʶ������int��char���� */
			else if (table[pos].kind != intVar && table[pos].kind != charVar)
			{
				error (25);
			}
		}
	}
	else /* ȱ�ٱ�ʶ�� */
	{
		error (6);
	}
}