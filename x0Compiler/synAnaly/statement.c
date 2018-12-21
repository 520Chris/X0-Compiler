#include "../global.h"

/*
 * statement�﷨��������
 */
void statement ()
{
	if (sym == ifsym)	/* if��� */
	{
		if_stat ();
	}
	else if (sym == whilesym)	/* while��� */
	{
		while_stat ();
	}
	else if (sym == readsym)	/* read��� */
	{
		read_stat ();
	}
	else if (sym == writesym)	/* write��� */
	{
		write_stat ();
	}
	else if (sym == lbrace)	/* compound��� */
	{
		compound_stat ();
	}
	else if (sym == semic || sym == ident || sym == hashsym
		|| sym == lparen || sym == number || sym == minus)	/* expression��� */
	{
		expression_stat ();
	}
	else if (sym == forsym) /* for��� */
	{
		for_stat ();
	}
	else /* ȱ��if��while��read��write��{��;���ʶ�������ֻ�#��( */
	{
		error (19);
	}
}