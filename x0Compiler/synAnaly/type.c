#include "../global.h"

/*
 * type�﷨��������
 */
void type ()
{
	if (sym != charsym && sym != intsym) /* ȱ��char��int */
	{
		error (20);
	}
	getSym ();
}