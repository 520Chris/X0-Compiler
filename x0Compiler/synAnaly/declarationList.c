#include "../global.h"

/*
 * declaration_list�﷨��������
 */
void declarationList (int* ptr_offset)
{	
	/* ���sym����first(declarationStat)����ִ��declarationStat�������� */
	while (sym == charsym || sym == intsym || sym == bolsym)
	{
		declarationStat (ptr_offset);
	}
}