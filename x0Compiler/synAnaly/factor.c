#include "../global.h"

/*
 * factor�﷨��������
 */
void factor ()
{
	int flag = 0; /* flag = 1������ֹ��߼��� */
	if (sym == notsym)
	{
		flag = 1;
		getSym ();
	}

	if (sym == lparen)
	{
		getSym ();
		expression ();
		if (sym == rparen)
		{
			getSym ();
		}
		else /* ȱ��) */
		{
			error (14);
		}
	}
	else if (sym == ident || sym == incsym || sym == decsym) /* sym����first(variable) */
	{
		/*
		* ͨ������ַ�ķ�ʽ֪���������ڻ��¼�е�ƫ�ơ��ñ����Ƿ������顢�ñ����Ƿ�����/��
		* (IncOrDec��1��������2���Լ���3ǰ������4ǰ�Լ���5������)
		*/
		int offset;
		int isArray;
		int IncOrDec;
		variable (&offset, &isArray, &IncOrDec);

		/* ���ر��� */
		if (isArray)
		{
			switch (IncOrDec)
			{
				case 1:
					gen (adf, 0, offset);
					gen (lof, 0, offset);
					gen (tad, 0, -1);
					break;
				case 2:
					gen (mif, 0, offset);
					gen (lof, 0, offset);
					gen (tad, 0, 1);
					break;
				case 3:
					gen (adf, 0, offset);
					gen (lof, 0, offset);
					break;
				case 4:
					gen (mif, 0, offset);
					gen (lof, 0, offset);
					break;
				case 5:
					gen (lof, 0, offset);
					break;
			}
		}
		else
		{
			switch (IncOrDec)
			{
				case 1:
					gen (add, 0, offset);
					gen (lod, 0, offset);
					gen (tad, 0, -1);
					break;
				case 2:
					gen (mis, 0, offset);
					gen (lod, 0, offset);
					gen (tad, 0, 1);
					break;
				case 3:
					gen (add, 0, offset);
					gen (lod, 0, offset);
					break;
				case 4:
					gen (mis, 0, offset);
					gen (lod, 0, offset);
					break;
				case 5:
					gen (lod, 0, offset);
					break;
			}
		}
	}
	else if (sym == number)
	{
		gen (lit, 0, num);
		getSym ();
	}
	else /* ȱ��(���ʶ�������ֻ�!��++��-- */
	{
		error (15);
	}

	/* ������ֹ��߼��� */
	if (flag)
	{
		gen (opr, 0, 18);
	}
}