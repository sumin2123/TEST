#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h> // ��ҹ��� �Ǻ� �Լ�
#include <string.h>

void main(void) {
	//�Է� ���� ���ڿ� �����Ϳ� �����ϱ�
	char input_ary[10]; // 10�� ũ�⸸ŭ ���� �޸� �Ҵ� / �Է¹��� ���ڸ� �ӽ� ����
	char lower_ary[10];	// �ҹ��� ���� �迭
	char upper_ary[10];	// �빮�� ���� �迭

	printf("��,�ҹ��� ���о��� ���ĺ��� �Է��ϼ��� : ");
	scanf("%s", input_ary); // ǥ�� �Է��� �޾Ƽ� �迭 ������ ���ڿ��� ����

	printf("�Է¹��� �� : %s\n\n", input_ary);

	printf("\n\n<============ �����ϱ�============>\n");


	// ���� ���� ����
	insertion_sort(input_ary, 10);

	// ���� ��� ���
	int i;

	for (i = 0; i < 10; i++) {
		printf("%d\n", input_ary[i]);
	}


	printf("\n\n<============ ��ҹ��� ���� ============>\n");

	// �ҹ��� ����
	int n = 0;
	printf("�ҹ��� ���");
	for (int i = 0; i < (int)strlen(input_ary); ++i)
	{
		if (islower(input_ary[i]) != 0)
		{
			printf("%c ", input_ary[i]);
		}
		lower_ary[10] = input_ary[i];
	}

	printf("\n �빮�� ���");
	// �빮�� ����
	for (int i = 0; i < (int)strlen(input_ary); i++)
	{
		if (isupper(input_ary[i]) != 0)
			printf("%c ", input_ary[i]);
		upper_ary[10] = input_ary[i];
	}

	return 0;
}

// ���� ����
void insertion_sort(char input_ary[], int n) {
	int i, j;
	char key;

	// ���ؽ� 0�� �̹� ���ĵ� ������ �� �� �ִ�.
	for (i = 1; i < n; i++) {
		key = input_ary[i]; // ���� ���Ե� ������ i��° ������ key ������ ����

		// ���� ���ĵ� �迭�� i-1�����̹Ƿ� i-1��°���� �������� �����Ѵ�.
		// j ���� ������ �ƴϾ�� �ǰ�
		// key ������ ���ĵ� �迭�� �ִ� ���� ũ�� j��°�� j+1��°�� �̵�
		for (j = i - 1; j >= 0 && input_ary[j] > key; j--) {
			input_ary[j + 1] = input_ary[j]; // ���ڵ��� ���������� �̵�
		}

		input_ary[j + 1] = key;
	}
}