#include "../global.h"

/*
 * term�﷨��������
 */
void term ()
{
	factor ();
	while (sym == times || sym == slash || sym == modsym)
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
			case modsym:
				gen (opr, 0, 6);
				break;
			default: /* ���Ϸ�������� */
				error (30);
		}
	}
}