#include "global.h"

int main ()
{
	//printf ("������x0�ļ�����");
	//scanf ("%s", fileName);		/* �����ļ��� */

	strcpy (fileName, "./testSamples/1.txt");

	if ((fin = fopen (fileName, "r")) == NULL)
	{
		printf ("�ļ��޷���!\n");
		return 1;
	}

	if (feof(fin))    /* �ļ�Ϊ�� */
	{
		printf ("�����ļ�Ϊ��!\n");
		fclose (fin);
		return 1;
	}
	rewind (fin);
	return 0;
}