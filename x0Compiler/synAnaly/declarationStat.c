#include "../global.h"

/*
 * declarationStat�﷨��������
 */
void declarationStat (int* ptr_offset)
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
				enter (charVar, *ptr_offset, 1);
				*ptr_offset = *ptr_offset + 1;
			}
			else /* ��������int���� */
			{
				enter (intVar, *ptr_offset, 1);
				*ptr_offset = *ptr_offset + 1;
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
							enter (charArray, *ptr_offset, num);
							*ptr_offset = *ptr_offset + num;
						}
						else /* ��������int���� */
						{
							enter (intArray, *ptr_offset, num);
							*ptr_offset = *ptr_offset + num;
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