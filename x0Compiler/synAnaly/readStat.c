#include "../global.h"

/*
 * read����﷨��������
 */
void readStat ()
{
	if (sym == readsym)
	{
		getSym ();
		
		/*
		* ͨ������ַ�ķ�ʽ֪���������ڻ��¼�е�ƫ�ơ��ñ����Ƿ������顢�ñ����Ƿ�����/��
		* (IncOrDec��1��������2���Լ���3ǰ������4ǰ�Լ���5������)
		*/
		int offset;
		int isArray;
		int IncOrDec;
		variable (&offset, &isArray, &IncOrDec);

		/* read���ܶ�ȡ����/������ */
		if (IncOrDec != 5)
		{
			error (33);
		}

		gen (opr, 0, 14); /* ��scanf��ȡһ������ */
		
		/* �����ǵ�������������ѡ��ͬ�Ĵ洢ָ�� */
		if (isArray)
		{
			gen (stf, 0, offset);
		}
		else
		{
			gen (sto, 0, offset);
		}

		if (sym == semic)
		{
			getSym ();
		}
		else /* ȱ��; */
		{
			error (10);
		}
	}
	else /* ȱ��read */
	{
		error (18);
	}
}