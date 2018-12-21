#include "../global.h"

/*
 * �������ļ��ж�ȡһ���ַ�
 */
void getCh ()
{
	if (posCh == chNum)	/* �жϻ��������Ƿ����ַ��������ַ����������һ���ַ�(�������з�)���������� */
	{
		/* ��ʼ�������� */
		chNum = 0;
		posCh = 0;

		/* �˴�Ҫע��feof�Ĳ��� */
		char temp = fgetc(fin);
		while (!feof (fin))
		{
			if (chNum >= MAX_SIZE_LINE)	/* �����ļ�һ�е��ַ�̫�� */
			{
				error (1);
			}

			printf ("%c", temp);
			lineCache[chNum++] = temp;

			if (temp == '\n')
			{
				break;
			}

			temp = fgetc (fin);
		}
	}
	if (posCh != chNum)
		ch = lineCache[posCh++];
}

/*
 * �ʷ���������һ�ζ�ȡһ���ս��
 */
void getSym ()
{
	int i, j, k;

	while (ch == ' ' || ch == '\n' || ch == 9)	/* ���˿ո񡢻��к��Ʊ�� */
	{
		getCh ();
	}

	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))	/* ��ǰ�ĵ����Ǳ�ʶ�����Ǳ����� */
	{
		char temp[MAX_SIZE_IDENT + 1];	/* temp�����Ŷ�ȡ�ı�ʶ��/�����ֵ����� */
		k = 0;
		do 
		{
			if (k < MAX_SIZE_IDENT)
			{
				temp[k++] = ch;
			}
			else /* ��ʶ������̫�� */
			{
				error (2);
			}
			getCh ();
		} while ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
		temp[k] = 0;

		strcpy (id, temp);	/* ����ʶ��/�����ֵ����ֿ�����id���� */
		
		/* ������ǰ�����Ƿ�Ϊ�����֣�ʹ�ö��ַ����� */
		i = 0;
		j = RESERVE_WORD_NUM - 1;
		do
		{
			k = (i + j) / 2;
			if (strcmp (id, reserveWord[k]) <= 0)
			{
				j = k - 1;
			}
			if (strcmp (id, reserveWord[k]) >= 0)
			{
				i = k + 1;
			}
		} while (i <= j);

		if (i - 1 > j)	/* ��ǰ�ĵ����Ǳ����� */
		{
			sym = wsym[k];
		}
		else  /* ��ǰ�ĵ����Ǳ�ʶ�� */
		{
			sym = ident;
		}
	}
	else
	{
		if (ch >= '0' && ch <= '9')	/* ��ǰ�ĵ��������� */
		{
			k = 0;
			num = 0;
			sym = number;

			/* ��ȡ���ֵ�ֵ */
			do 
			{
				num = 10 * num + ch - '0';
				k++;
				if (k > MAX_SIZE_NUMBER)	/* ����λ��̫�� */
				{
					error (3);
				}
				getCh ();
			} while (ch >= '0' && ch <= '9');
		}
		else
		{
			if (ch == '=')		/* ���=��==���� */
			{
				getCh ();
				if (ch == '=')
				{
					sym = eqleql;
					getCh ();
				}
				else
				{
					sym = eql;
				}
			}
			else
			{
				if (ch == '<')	/* ���С�ڻ�С�ڵ��ڷ��� */
				{
					getCh ();
					if (ch == '=')
					{
						sym = lesseql;
						getCh ();
					}
					else
					{
						sym = less;
					}
				}
				else
				{
					if (ch == '>')	/* �����ڻ���ڵ��ڷ��� */
					{
						getCh ();
						if (ch == '=')
						{
							sym = greateql;
							getCh ();
						}
						else
						{
							sym = great;
						}
					}
					else
					{
						if (ch == '!')	/* ��ⲻ���ڷ��� */
						{
							getCh ();
							if (ch == '=')
							{
								sym = neql;
								getCh ();
							}
							else
							{
								sym = nul;	/* ����ʶ��ķ��� */
							}
						}
						else
						{
							sym = ssym[ch];	/* �����Ų�������������ʱ��ȫ�����յ��ַ����Ŵ��� */
							getCh ();
						}
					}
				}
			}
		}
	}
}

#define DEBUG 0
#if DEBUG == 1

void test_getSym ()
{
	
	int i = 1;
	for (int i = 1; i <= 100; i++)
	{
		printf ("��ȡ�ĵ�%d���ս����: ", i++);
		getSym ();
		switch (sym)
		{
		case 0:
			printf ("nul");
		case 1:
			printf ("%s", id);
			break;
		case 2:
			printf ("main");
			break;
		case 3:
			printf ("char");
			break;
		case 4:
			printf ("int");
			break;
		case 5:
			printf ("if");
			break;
		case 6:
			printf ("else");
			break;
		case 7:
			printf ("while");
			break;
		case 8:
			printf ("read");
			break;
		case 9:
			printf ("write");
			break;
		case 10:
			printf ("+");
			break;
		case 11:
			printf ("-");
			break;
		case 12:
			printf ("*");
			break;
		case 13:
			printf ("/");
			break;
		case 14:
			printf ("(");
			break;
		case 15:
			printf (")");
			break;
		case 16:
			printf ("[");
			break;
		case 17:
			printf ("]");
			break;
		case 18:
			printf ("{");
			break;
		case 19:
			printf ("}");
			break;
		case 20:
			printf (";");
			break;
		case 21:
			printf ("=");
			break;
		case 22:
			printf (">");
			break;
		case 23:
			printf ("<");
			break;
		case 24:
			printf (">=");
			break;
		case 25:
			printf ("<=");
			break;
		case 26:
			printf ("==");
			break;
		case 27:
			printf ("!=");
			break;
		case 28:
			printf ("%d", num);
			break;
		case 29:
			printf ("#");
			break;
		}
		printf ("\n");
	}
}

#endif