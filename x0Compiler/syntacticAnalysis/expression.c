#include "../global.h"

/*
 * expression�﷨��������
 */
void expression ()
{
	if (sym == hashsym)	/* sym == '#' */	
	{
		getSym ();
		var ();
		if (sym == eql)
		{
			getSym ();
			expression ();
		}
		else /* ȱ��= */
		{
			error (11);
		}
	}
	else if (sym == lparen || sym == number || sym == ident)	/* sym����first(simple_expr) */
	{
		simple_expr ();
	}
	else /* ȱ��#��(�����ֻ��ʶ�� */
	{
		error (12);
	}
}