#include "../global.h"

/*
 * var�﷨��������
 */
void variable (int* ptr_offset, int* ptr_isArray, int* ptr_IncOrDec)
{
	if (sym == ident)
	{
		simpleVariable (ptr_offset, ptr_isArray);

		if (sym == incsym)
		{
			*ptr_IncOrDec = 1;
			getSym ();
		}
		else if (sym == decsym)
		{
			*ptr_IncOrDec = 2;
			getSym ();
		}
		else
		{
			*ptr_IncOrDec = 5;
		}
	}
	else if (sym == incsym || sym == decsym)
	{
		if (sym == incsym)
		{
			*ptr_IncOrDec = 3;
		}
		else
		{
			*ptr_IncOrDec = 4;
		}

		getSym ();
		simpleVariable (ptr_offset, ptr_isArray);
	}
	else /* ȱ�ٱ�ʶ�� */
	{
		error (6);
	}
}