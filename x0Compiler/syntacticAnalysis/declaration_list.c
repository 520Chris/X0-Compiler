#include "../global.h"

/*
 * declaration_list�﷨��������
 */
void declaration_list ()
{
	/* ���sym����first(declaration_stat)����ִ��declaration_stat�������� */
	while (sym == charsym || sym == intsym)
	{
		declaration_stat ();
	}
}