#include "../global.h"

/*
 * �ڷ��ű��м���һ��
 * k: ���ŵ�����(charVar/intVar/charArray/intArray)
 */
void enter (enum objectKind k)
{
	strcpy (table[iterTable].name, id); /* ���ű��name���¼��ʶ�������� */
	table[iterTable++].kind = k;
}