#include "../global.h"

/*
 * term�﷨��������
 */
void term ()
{
	factor ();
	while (sym == times || sym == slash)
	{
		enum symbol tempSym = sym; /* �����ʱ�ķ��� */
		getSym ();
		factor ();

		switch (tempSym)
		{
			case times:
				gen (opr, 0, 4);
				break;
			case slash:
				gen (opr, 0, 5);
				break;
			default:
				printf ("����Ӧ��Ϊ*��/\n");
		}
	}
}