#include "../global.h"

/*
 * read����﷨��������
 */
void read_stat ()
{
	if (sym == readsym)
	{
		getSym ();
		
		int offset;
		int isArray;
		var (&offset, &isArray); /* ͨ������ַ�ķ�ʽ֪���������ڻ��¼�е�ƫ�ơ��ñ����Ƿ������� */

		gen (opr, 0, 14); /* ��scanf��ȡһ������ */
		
		/* �����ǵ�������������ѡ��ͬ��store��ʽ */
		if (isArray)
		{
			gen (stof, 0, offset);
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