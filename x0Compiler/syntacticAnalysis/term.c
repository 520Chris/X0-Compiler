#include "../global.h"

/*
 * term�﷨��������
 */
void term ()
{
	factor ();
	while (sym == times || sym == slash)
	{
		getSym ();
		factor ();
	}
}