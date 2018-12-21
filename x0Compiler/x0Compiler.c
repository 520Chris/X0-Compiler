#include "global.h"

/* 
 * ������������
 */
void compile ()
{
	getSym ();
	if (sym == mainsym)
	{
		getSym ();
		if (sym == lbrace)
		{
			getSym ();
			declaration_list ();
			statement_list ();
			if (sym == rbrace)
			{
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
	rewind (fin);

	compile ();	/* ���� */

	return 0;
}