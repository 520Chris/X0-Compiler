#include "../global.h"

/*
 * additive_expr�﷨��������
 */
void additive_expr ()
{
	term ();
	while (sym == plus || sym == minus)
	{
		getSym ();
		term ();
	}
}