#include "../global.h"

/*
 * expression�﷨��������
 */
void expression ()
{
	if (sym == hashsym)	/* sym == '#' */	
	{
		getSym ();

		/* 
		 * ͨ������ַ�ķ�ʽ֪���������ڻ��¼�е�ƫ�ơ��ñ����Ƿ������顢�ñ����Ƿ�����/��
		 * (IncOrDec��1��������2���Լ���3ǰ������4ǰ�Լ���5������)
		 */
		int offset;
		int isArray;
		int IncOrDec;
		variable (&offset, &isArray, &IncOrDec);

		/* ��ֵ�����߲��������������Լ����� */
		if (IncOrDec != 5)
		{
			error (32);
		}

		if (sym == eql)
		{
			getSym ();
			expression ();

			/* ��expression��ֵ�洢��var�� */
			if (isArray)
			{
				gen (stf, 0, offset);
			}
			else
			{
				gen (sto, 0, offset);
			}
		}
		else /* ȱ��= */
		{
			error (11);
		}
	}
	else if (sym == lparen || sym == number || sym == ident || sym == minus
			|| sym == incsym || sym == decsym || sym == oddsym || sym == notsym)	/* sym����first(valueExpr) */
	{
		valueExpr ();
	}
	else /* ȱ��#���ʶ����(�����ֻ�-��++��--��odd��! */
	{
		error (12);
	}
}