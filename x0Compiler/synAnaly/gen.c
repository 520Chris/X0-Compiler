#include "../global.h"

/*
* �����м����
*
* fct: ������
* lev_dif: ���ò���������Ĳ�β�
* offset: �����lodָ�offsetΪ����ڻ��¼��ʼλ�õ�ƫ��, �����calָ�offsetΪ�����ú������м�����еĿ�ʼλ��
*/
void gen (enum fctCode fct, int lev_dif, int offset)
{
	if (iterCode >= MAX_SIZE_CODE) /* ���ɵ���������������� */
	{
		error (27);
	}

	code[iterCode].fct = fct;
	code[iterCode].lev_dif = lev_dif;
	code[iterCode++].offset = offset;
}