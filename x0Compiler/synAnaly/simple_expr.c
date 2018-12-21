#include "../global.h"

/*
 * simple_expr�﷨��������
 */
void simple_expr ()
{
	additive_expr ();
	if (sym == great || sym == less || sym == greateql
		|| sym == lesseql || sym == eqleql || sym == neql)
	{
		enum symbol tempSym1 = sym; /* �����ʱ��sym */
		getSym ();
		additive_expr ();

		/* >, <, >=, <=, ==, != */
		switch (tempSym1)
		{
			case great:
				gen (opr, 0, 12);
				break;
			case less:
				gen (opr, 0, 10);
				break;
			case greateql:
				gen (opr, 0, 11);
				break;
			case lesseql:
				gen (opr, 0, 13);
				break;
			case eqleql:
				gen (opr, 0, 8);
				break;
			case neql:
				gen (opr, 0, 9);
				break;
			default: /* ���Ϸ�������� */
				error (30);
		}

		while (sym == andsym || sym == orsym)
		{
			enum symbol tempSym2 = sym; /* �����ʱ��sym */
			getSym ();
			additive_expr ();
			
			if (sym == great || sym == less || sym == greateql
				|| sym == lesseql || sym == eqleql || sym == neql)
			{
				tempSym1 = sym; /* �����ʱ��sym */
				getSym ();
				additive_expr ();

				/* >, <, >=, <=, ==, != */
				switch (tempSym1)
				{
					case great:
						gen (opr, 0, 12);
						break;
					case less:
						gen (opr, 0, 10);
						break;
					case greateql:
						gen (opr, 0, 11);
						break;
					case lesseql:
						gen (opr, 0, 13);
						break;
					case eqleql:
						gen (opr, 0, 8);
						break;
					case neql:
						gen (opr, 0, 9);
						break;
					default: /* ���Ϸ�������� */
						error (30);
				}

				/* &&, || */
				switch (tempSym2)
				{
					case andsym:
						gen (opr, 0, 16);
						break;
					case orsym:
						gen (opr, 0, 17);
						break;
					default: /* ���Ϸ�������� */
						error (30);
				}
			}
			else /* ���Ϸ�������� */
			{
				error (30);
			}
		}
	}
}