#include "../global.h"

/*
 * valueExpr�﷨��������
 */
void valueExpr ()
{
	simpleValue ();

	while (sym == andsym || sym == orsym || sym == xorsym)
	{
		enum symbol tempSym = sym; /* �����ʱ��sym */
		getSym ();
		simpleValue ();

		switch (tempSym)
		{
			case andsym:
				gen (opr, 0, 16);
				break;
			case orsym:
				gen (opr, 0, 17);
				break;
			case xorsym:
				gen (opr, 0, 19);
				break;
			default: /* ���Ϸ�������� */
				error (30);
		}
	}
}