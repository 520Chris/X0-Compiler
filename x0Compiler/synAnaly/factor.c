#include "../global.h"

/*
 * factor�﷨��������
 */
void factor ()
{
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
	else if (sym == ident)
	{
		int offset;
		int isArray;
		var (&offset, &isArray); /* ͨ������ַ�ķ�ʽ֪���������ڻ��¼�е�ƫ�ơ��ñ����Ƿ������� */

		/* �����ǵ�������������ѡ��ͬ��load��ʽ */
		if (isArray)
		{
			gen (lodf, 0, offset);
		}
		else
		{
			gen (lod, 0, offset);
		}
	}
	else if (sym == number)
	{
		gen (lit, 0, num);
		getSym ();
	}
	else /* ȱ��(���ʶ�������� */
	{
		error (15);
	}
}