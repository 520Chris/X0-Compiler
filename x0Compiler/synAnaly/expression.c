#include "../global.h"

/*
 * expression�﷨��������
 */
void expression ()
{
	if (sym == hashsym)	/* sym == '#' */	
	{
		getSym ();

		int offset;
		int isArray;
		var (&offset, &isArray); /* ͨ������ַ�ķ�ʽ֪���������ڻ��¼�е�ƫ�ơ��ñ����Ƿ������� */

		if (sym == eql)
		{
			getSym ();
			expression ();

			/* �����ǵ�������������ѡ��ͬ��store��ʽ */
			if (isArray)
			{
				gen (stof, 0, offset);
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
	else if (sym == lparen || sym == number || sym == ident || sym == minus)	/* sym����first(simple_expr) */
	{
		simple_expr ();
	}
	else /* ȱ��#��(�����ֻ��ʶ�� */
	{
		error (12);
	}
}