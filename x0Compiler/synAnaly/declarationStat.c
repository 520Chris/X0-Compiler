#include "../global.h"

/*
 * declarationStat�﷨��������
 */
void declarationStat (int* ptr_offset)
{
	/* 
	 * �������ڵķ�������, 1: int, 2: char, 3: bool
	 */
	int typeSym;

	switch (sym)
	{
		case intsym:
			typeSym = 1;
			break;
		case charsym:
			typeSym = 2;
			break;
		case bolsym:
			typeSym = 3;
			break;
	}

	type ();

	if (sym == ident)
	{
		getSym ();
		if (sym == semic)
		{
			/* ��������char���� */
			if (typeSym == 2)
			{
				enter (charVar, *ptr_offset, 1);
				*ptr_offset = *ptr_offset + 1;
			}
			else if (typeSym == 1) /* ��������int���� */
			{
				enter (intVar, *ptr_offset, 1);
				*ptr_offset = *ptr_offset + 1;
			}
			else /* ��������bool���� */
			{
				enter (boolVar, *ptr_offset, 1);
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
						if (typeSym == 2)
						{
							enter (charArray, *ptr_offset, num);
							*ptr_offset = *ptr_offset + num;
						}
						else if(typeSym == 1) /* ��������int���� */
						{
							enter (intArray, *ptr_offset, num);
							*ptr_offset = *ptr_offset + num;
						}
						else /* ��������bool���� */
						{
							enter (boolArray, *ptr_offset, num);
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