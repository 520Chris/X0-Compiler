#include "../global.h"

/*
 * declaration_stat�﷨��������
 */
void declaration_stat ()
{
	/* 
	 * �������ڵķ�������, 1: char, 0: int 
	 */
	int isChar = (sym == charsym);

	type ();

	if (sym == ident)
	{
		getSym ();
		if (sym == semic)
		{
			/* ��������char���� */	
			if (isChar)
			{
				enum objectKind temp = charVar;
				enter (temp);
			}
			else /* ��������int���� */
			{
				enum objectKind temp = intVar;
				enter (temp);
			}

			getSym ();
		}
		else if (sym == lbracket)
		{
			getSym ();
			if (sym == number)
			{
				getSym ();
				if (sym == rbracket)
				{
					getSym ();
					if (sym == semic)
					{
						/* ��������char���� */
						if (isChar)
						{
							enum objectKind temp = charArray;
							enter (temp);
						}
						else /* ��������int���� */
						{
							enum objectKind temp = intArray;
							enter (temp);
						}
						
						getSym ();
					}
					else /* ȱ��; */
					{
						error (10);
					}
				}
				else /* ȱ��] */
				{
					error (9);
				}
			}
			else /* ȱ������ */
			{
				error (8);
			}
		}
		else /* ȱ��;��[ */
		{
			error (7);
		}
	}
	else /* ȱ�ٱ�ʶ�� */
	{
		error (6);
	}
}