#include "../global.h"

/*
 * �ڷ��ű��м���һ��
 * k: ���ŵ�����(charVar/intVar/charArray/intArray)
 * offset: �ֲ���������ڻ��¼��ʼλ�õ�ƫ��
 * size: ����Ŀռ��С
 */
void enter (enum objectKind k, int offset, int size)
{
	strcpy (table[iterTable].name, id); /* ���ű��name���¼��ʶ�������� */
	table[iterTable].kind = k;
	table[iterTable].offset = offset;
	table[iterTable++].size = size;
}