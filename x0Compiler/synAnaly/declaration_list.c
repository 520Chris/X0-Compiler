#include "../global.h"

/*
 * declaration_list�﷨��������
 */
void declaration_list (int* ptr_offset)
{	
	/* ���sym����first(declaration_stat)����ִ��declaration_stat�������� */
	while (sym == charsym || sym == intsym)
	{
		declaration_stat (ptr_offset);
	}
}