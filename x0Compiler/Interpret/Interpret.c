#include "../global.h"

/* ���ͳ��� */
void Interpret ()
{
	int p = 0; /* ָ��ָ�� */
	int b = 1; /* ָ���ַ */
	int t = 0; /* ջ��ָ�� */
	struct instruction i;	/* ��ŵ�ǰָ�� */
	int s[MAX_SIZE_STACK];	/* ջ */

	printf ("���������\n");

	s[0] = 0; /* s[0]���� */
	s[1] = 0; /* �������SL, DL, RA����Ϊ0 */
	s[2] = 0;
	s[3] = 0;

	do 
	{
		i = code[p];  /* ����ǰָ�� */
		p = p + 1;
		switch (i.fct)
		{
			case lit:	/* ������a��ֵȡ��ջ�� */
				t = t + 1;
				s[t] = i.offset;
				break;
			case opr:	/* ��ѧ���߼������롢������� */
				switch (i.offset)
				{
					case 0:  /* �������ý����󷵻� */
						t = b - 1;
						p = s[t + 3];
						b = s[t + 2];
						break;
					case 1: /* ջ��Ԫ��ȡ�� */
						s[t] = -s[t];
						break;
					case 2: /* ��ջ�������ջ���������ջԪ�أ����ֵ��ջ */
						t = t - 1;
						s[t] = s[t] + s[t + 1];
						break;
					case 3: /* ��ջ�����ȥջ���� */
						t = t - 1;
						s[t] = s[t] - s[t + 1];
						break;
					case 4: /* ��ջ�������ջ���� */
						t = t - 1;
						s[t] = s[t] * s[t + 1];
						break;
					case 5: /* ��ջ�������ջ���� */
						t = t - 1;
						s[t] = s[t] / s[t + 1];
						break;
					case 6: /* ջ��Ԫ�ص���ż�ж� */
						s[t] = s[t] % 2;
						break;
					case 8: /* ��ջ������ջ�����Ƿ���� */
						t = t - 1;
						s[t] = (s[t] == s[t + 1]);
						break;
					case 9: /* ��ջ������ջ�����Ƿ񲻵� */
						t = t - 1;
						s[t] = (s[t] != s[t + 1]);
						break;
					case 10: /* ��ջ�����Ƿ�С��ջ���� */
						t = t - 1;
						s[t] = (s[t] < s[t + 1]);
						break;
					case 11: /* ��ջ�����Ƿ���ڵ���ջ���� */
						t = t - 1;
						s[t] = (s[t] >= s[t + 1]);
						break;
					case 12: /* ��ջ�����Ƿ����ջ���� */
						t = t - 1;
						s[t] = (s[t] > s[t + 1]);
						break;
					case 13: /* ��ջ�����Ƿ�С�ڵ���ջ���� */
						t = t - 1;
						s[t] = (s[t] <= s[t + 1]);
						break;
					case 14: /* ����һ�����ֵ�ջ�� */
						t = t + 1;
						scanf ("%d", &(s[t]));
						break;
					case 15: /* ��ջ��Ԫ����� */
						printf ("%d\n", s[t]);
						t = t - 1;
						break;
					case 16: /* �߼��� */
						t = t - 1;
						s[t] = s[t] && s[t + 1];
						break;
					case 17: /* �߼��� */
						t = t - 1;
						s[t] = s[t] || s[t + 1];
						break;
					case 18: /* �߼�ȡ�� */
						s[t] = !s[t];
						break;
					default: /* ���Ϸ���opr������ */
						error (28);
				}
				break;
			case lod:	/* ȡ����ڵ�ǰ���¼����ַƫ����Ϊoffset�ı���ֵ��ջ�� */
				t = t + 1;
				s[t] = s[1 + i.offset];
				break;
			case lodf:	/* ȡ����ֵ��ջ�����������ַΪ��ǰ���¼����ַ+offset�������ڲ�ƫ����Ϊs[t] */
				s[t] = s[1 + i.offset + s[t]];
				break;
			case sto:	/* ջ����ֵ�浽����ڵ�ǰ���¼����ַƫ����Ϊoffset�ı��� */
				s[1 + i.offset] = s[t];
				t = t - 1;
				break;
			case stof:	/* ջ����ֵ�浽����Ԫ����������ַΪ��ǰ���¼����ַ+offset�������ڲ�ƫ����Ϊs[t] */
				s[1 + i.offset + s[t - 1]] = s[t];
				t = t - 2;
				break;
			case cal:	/* �����ӹ��� */
				break;
			case ini:	/* ������ջ��Ϊ�����õĹ��̿���offset����Ԫ�������� */
				t = t + i.offset;
				break;
			case jmp:	/* ֱ����ת */
				p = i.offset;
				break;
			case jpc:	/* ������ת */
				if (s[t] == 0)
				{
					p = i.offset;
				}
				t = t - 1;
				break;
			default:
				error (29);
		}
	} while (p != 0);
}