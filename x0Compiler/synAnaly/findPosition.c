#include "../global.h"

/*
 * ���ұ�ʶ���ڷ��ű��е�λ��, �ҵ��򷵻��ڷ��ű��е�λ��, ���򷵻�-1
 * identName: Ҫ���ҵ�����
 */
int findPosition (char* identName)
{
	for (int i = 0; i < iterTable; i++)
	{
		if (strcmp (table[i].name, identName) == 0)
		{
			return i;
		}
	}
	return -1;
}