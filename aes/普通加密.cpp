#include<stdio.h>

int main()
{
	//�����ļ���
	FILE *fp;
	FILE *temp;

	char tempChar;
	//���ļ�
	fopen_s(&fp, "C:\\Users\\Zmore\\Desktop\\new.txt", "rb+");
	if (fp == NULL)
	{
		printf("open failed");
		return 0;
	}
	//�������ļ�
	fopen_s(&temp, "C:\\Users\\Zmore\\Desktop\\new1.txt", "wb+");
	if (temp == NULL)
	{
		printf("create failed");
		return 0;
	}
	while (!feof(fp))
	{
		tempChar = fgetc(fp);
		if (tempChar != 0 && tempChar != -1)
		{
			tempChar = ~tempChar;
			fputc(tempChar, temp);
		}
	}
	fclose(fp);
	fclose(temp);
	printf("ok");
	getchar();
	return 0;
}