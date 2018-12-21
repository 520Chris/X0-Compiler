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
	{
		ch = lineCache[posCh++];
	}
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
						if (ch == '&')	/* ����߼������ */
						{
							getCh ();
							if (ch == '&')
							{
								sym = andsym;
								getCh ();
							}
							else
							{
								sym = nul; /* ����ʶ��ķ��� */
							}
						}
						else
						{
							if (ch == '|')	/* ����߼������ */
							{
								getCh ();
								if (ch == '|')
								{
									sym = orsym;
									getCh ();
								}
								else
								{
									sym = nul; /* ����ʶ��ķ��� */
								}
							}
							else
							{
								if (ch == '+')	/* ����������� */
								{
									getCh ();
									if (ch == '+')
									{
										sym = incsym;
										getCh ();
									}
									else
									{
										sym = plus;
									}
								}
								else
								{
									if (ch == '-')	/* ����Լ����� */
									{
										getCh ();
										if (ch == '-')
										{
											sym = decsym;
											getCh ();
										}
										else
										{
											sym = minus;
										}
									}
									else
									{
										if (ch == '!')	/* ��ⲻ���ڻ��߼��Ƿ��� */
										{
											getCh ();
											if (ch == '=')
											{
												sym = neql;
												getCh ();
											}
											else
											{
												sym = notsym;
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
			}
		}
	}
}