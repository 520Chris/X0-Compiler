#include "../global.h"

void error (int error_code)
{
	char space[81];
	memset (space, 32, sizeof(space));

	/* ����ʱ��ǰ�ս���Ѿ�����, chΪ��ǰ�ս������һ���ַ�, posChָ�ŵ�ǰ�ս��������һ���ַ� */
	space[posCh - 2] = '\0';

	printf ("%s^", space); /* ��Ǵ���λ�� */

	switch (error_code)
	{
		case 1:
			printf ("�����ļ�һ�е��ַ�̫��\n");
			break;
		case 2:
			printf ("��ʶ������̫��\n");
			break;
		case 3:
			printf ("����λ��̫��\n");
			break;
		case 4:
			printf ("ȱ��}\n");
			break;
		case 5:
			printf ("ȱ��{\n");
			break;
		case 6:
			printf ("ȱ�ٱ�ʶ��\n");
			break;
		case 7:
			printf ("ȱ��;��[\n");
			break;
		case 8:
			printf ("ȱ������\n");
			break;
		case 9:
			printf ("ȱ��]\n");
			break;
		case 10:
			printf ("ȱ��;\n");
			break;
		case 11:
			printf ("ȱ��=\n");
			break;
		case 12:
			printf ("ȱ��#���ʶ����(�����ֻ�-��++��--��odd��!��true��false\n");
			break;
		case 13:
			printf ("ȱ��#���ʶ����(�����ֻ�-��++��--��odd��!��;��true��false\n");
			break;
		case 14:
			printf ("ȱ��)\n");
			break;
		case 15:
			printf ("ȱ��(���ʶ�������ֻ�!��++��--��true��false\n");
			break;
		case 16:
			printf ("ȱ��(\n");
			break;
		case 17:
			printf ("ȱ��if\n");
			break;
		case 18:
			printf ("ȱ��read\n");
			break;
		case 19:
			printf ("ȱ��if��while��read��write��{��for��#���ʶ����(�����ֻ�-��++��--��odd��!��;��true��false\n");
			break;
		case 20:
			printf ("ȱ��char��int��bool\n");
			break;
		case 21:
			printf ("ȱ��while\n");
			break;
		case 22:
			printf ("ȱ��write\n");
			break;
		case 23:
			printf ("ȱ��main\n");
			break;
		case 24:
			printf ("��ʶ��δ����\n");
			break;
		case 25:
			printf ("��ʶ������int��char����\n");
			break;
		case 26:
			printf ("��ʶ������int��char����\n");
			break;
		case 27:
			printf ("����̫��!\n");
			break;
		case 28:
			printf ("���Ϸ���opr������!\n");
			break;
		case 29:
			printf ("���Ϸ���ָ����!\n");
			break;
		case 30:
			printf ("���Ϸ��������!\n");
			break;
		case 31:
			printf ("ȱ��for\n");
			break;
		case 32:
			printf ("��ֵ�����߲��������������Լ�����\n");
			break;
		case 33:
			printf ("read���ܶ�ȡ����/������\n");
			break;
		case 34:
			printf ("ȱ��break\n");
			break;
		case 35:
			printf ("ȱ��break\n");
			break;
		case 36:
			printf ("ȱ��continue\n");
			break;
		case 37:
			printf ("ȱ��switch\n");
			break;
		case 38:
			printf ("ȱ��:\n");
			break;
		case 39:
			printf ("ȱ��do\n");
			break;
		default:
			printf ("�����ڵĴ�����!\n");
	}
	printf ("\ntip: ^��ָ������λ��\n");
	exit (0);
}