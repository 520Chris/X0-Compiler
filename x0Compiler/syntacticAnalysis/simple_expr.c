#include "../global.h"

/*
 * simple_expr�﷨��������
 */
void simple_expr ()
{
	additive_expr ();
	if (sym == great || sym == less || sym == greateql
		|| sym == lesseql || sym == eqleql || sym == neql)
	{
		getSym ();
		additive_expr ();
	}
}