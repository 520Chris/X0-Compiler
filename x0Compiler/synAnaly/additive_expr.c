#include "../global.h"

/*
 * additive_expr�﷨��������
 */
void additive_expr ()
{
	if (sym == minus) /* ������ſ������� */
	{
		getSym ();
		term ();
		gen (opr, 0, 1);
	}
	else
	{
		term ();
	}

	while (sym == plus || sym == minus || sym == modsym)
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
			case modsym:
				gen (opr, 0, 6);
				break;
			default: /* ���Ϸ�������� */
				error (30);
		}
	}
}