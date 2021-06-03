#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h> // ��ҹ��� �Ǻ� �Լ�
#include <string.h>


void insertionlower(char lower_ary[], int n);
void insertionupper(char upper_ary[], int n);

void main(void) {
	//�Է� ���� ���ڿ� �����Ϳ� �����ϱ�
	char input_ary[10]; // 10�� ũ�⸸ŭ ���� �޸� �Ҵ� / �Է¹��� ���ڸ� �ӽ� ����


	printf("��,�ҹ��� ���о��� ���ĺ��� �Է��ϼ��� : ");
	scanf("%s", input_ary); // ǥ�� �Է��� �޾Ƽ� �迭 ������ ���ڿ��� ����
	printf("�Է¹��� �� : %s\n\n", input_ary);

	int len = strlen(input_ary);

	// �ҹ��� ����
	char lower_ary[10];	// �ҹ��� ���� �迭
	char upper_ary[10];	// �빮�� ���� �迭
	int n = 0;  //�迭�� �����ϱ� ���� �ε��� ��

	printf("==== �ҹ��ڸ�~!\n");
	for (int i = 0; i < len; i++)
	{
		if (islower(input_ary[i]))	//islower => �ҹ��� ���� �Լ�
		{
			printf("%c \n", input_ary[i]); // �ҹ��ڸ� ���
			lower_ary[n] = input_ary[i]; // lower_ary �迭�� ����
			n++;
			
		}

	}
	// �ҹ��� ���� ���� ����
	insertionlower(lower_ary, n);

	printf("\n ==== �빮�ڸ�~!\n");
	// �빮�� ����
	n = 0;
	for (int i = 0; i<len; i++)
	{
		if (isupper(input_ary[i]))	//isupper => �빮�� ���� �Լ�
		{
			printf("%c \n", input_ary[i]); // �빮�ڸ� ���
			upper_ary[n] = input_ary[i];// upper_ary �迭�� ����
			n++;
		}
	}

	// �빮�� ���� ���� ����
	insertionupper(upper_ary, n);

	return 0;
}


 // ���� ���� �Լ� => �ҹ��ڸ�
void insertionlower(char lower_ary[], int n)
{
	int i, j, k, key;

	for (i = 1; i < n; i++) { 
		key = lower_ary[i];	
		j = i;
		while ((j > 0) && (lower_ary[j - 1] > key))
		{
			lower_ary[j] = lower_ary[j - 1];
			j = j - 1;
		}
		lower_ary[j] = key; 
		
	}
	printf("=>");
	for (k = 0; k < n; k++)
	{
		printf("%3c	", lower_ary[k]);
	}
	printf("\n\n============= �ҹ��� ���� ���� �Ϸ� =============\n");
	printf("\n\n");

}


// ���� ���� �Լ� => �빮�ڸ�
void insertionupper(char upper_ary[], int n)
{
	int i, j, k, key;

	for (i = 1; i < n; i++) {
		key = upper_ary[i];
		j = i;
		while ((j > 0) && (upper_ary[j - 1] > key))
		{
			upper_ary[j] = upper_ary[j - 1];
			j = j - 1;
		}
		upper_ary[j] = key;

	}
	printf("=>");
	for (k = 0; k < n; k++)
	{
		printf("%3c	", upper_ary[k]);
	}
	printf("\n\n============= �빮�� ���� ���� �Ϸ� =============\n");
}