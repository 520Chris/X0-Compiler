#include "../global.h"

/*
 * additive_expr�﷨��������
 */
void additive_expr ()
{
	term ();
	while (sym == plus || sym == minus)
	{
		enum symbol tempSym = sym; /* �����ʱ�ķ��� */
		getSym ();
		term ();

		switch (tempSym)
		{
			case plus:
				gen (opr, 0, 2);
				break;
			case minus:
				gen (opr, 0, 3);
				break;
			default:
				printf ("����Ӧ��Ϊ+��-\n");
		}
	}
}