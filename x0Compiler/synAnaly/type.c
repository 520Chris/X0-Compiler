#include "../global.h"

/*
 * type�﷨��������
 */
void type ()
{
	if (sym != charsym && sym != intsym && sym != bolsym) /* ȱ��char��int��bool */
	{
		error (20);
	}
	getSym ();
}