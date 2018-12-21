#include "global.h"

/* 
 * ������������
 */
void compile ()
{
	gen (jmp, 0, 1);
	getSym ();

	if (sym == mainsym)
	{
		getSym ();

		if (sym == lbrace)
		{
			getSym ();

			int offset = 3;	/* �ֲ���������ڻ��¼��ʼλ�õ�ƫ�� */
			declaration_list (&offset);

			gen (ini, 0, offset); /* ����������ʱ���֪������ҪԤ�����ٿռ� */

			statement_list ();

			if (sym == rbrace)
			{
				gen (opr, 0, 0); /* ���ص��ù��� */

				printf ("\n***************\n");
				printf ("�﷨��ȷ!\n");
				printf ("***************\n");
			}
			else /* ȱ��} */
			{
				error (4);
			}
		}
		else /* ȱ��{ */
		{
			error (5);
		}
	}
	else /* ȱ��main */
	{
		error (23);
	}
}

int main ()
{
	//printf ("������x0�ļ�����");
	//scanf ("%s", fileName);

	strcpy (fileName, "./testSamples/test_synAnaly.txt");

	if ((fin = fopen (fileName, "r")) == NULL) /* �ļ��޷��� */
	{
		printf ("�ļ��޷���!\n");
		return 1;
	}

	if (feof(fin))	/* �ļ�Ϊ�� */
	{
		printf ("�����ļ�Ϊ��!\n");
		fclose (fin);
		return 1;
	}

	compile ();	/* ����﷨�Ƿ���ȷ����������м���� */

	FILE* fout = fopen ("./testSamples/output.txt", "w");
	
	for (int i = 0; i < iterCode; i++)
	{
		fprintf (fout, "[%d] %s %d %d\n", i, fctCode_string[code[i].fct], code[i].lev_dif, code[i].offset);
	}

	fclose (fout);

	Interpret (); /* ����ִ�����ɵ��м���� */

	return 0;
}