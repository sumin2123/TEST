#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h> // ��ҹ��� �Ǻ� �Լ�
#include <string.h>

void main(void) {
	//�Է� ���� ���ڿ� �����Ϳ� �����ϱ�
	char input_ary[10]; // 10�� ũ�⸸ŭ ���� �޸� �Ҵ�
	char lower_ary[10];	// �ҹ��� ���� �迭
	char upper_ary[10];	// �빮�� ���� �迭

	printf("��,�ҹ��� ���о��� ���ĺ��� �Է��ϼ��� : ");
	scanf("%s", input_ary); // ǥ�� �Է��� �޾Ƽ� �迭 ������ ���ڿ��� ����

	printf("�Է¹��� �� : %s\n\n", input_ary);
	printf("<============ ��ҹ��� ���� ============>\n");

	// �ҹ��� ����
	for (int i = 0; i < (int)strlen(input_ary); ++i)
	{
		if (islower(input_ary[i]) != 0)
			printf("%c ", input_ary[i]);
		lower_ary[i] = input_ary[i];
	}


	printf("\n");
	// �빮�� ����
	for (int i = 0; i < (int)strlen(input_ary); i++)
	{
		if (isupper(input_ary[i]) != 0)
			printf("%c ", input_ary[i]);
		upper_ary[i] = input_ary[i];
	}


	// ���� ���� ����
	insertion_sort(lower_ary, upper_ary);

	// ���� ��� ���
	int i;
	for (i = 0; i < 10; i++) {
		printf("%d\n", input_ary[i]);
	}

	return 0;
}

// ���� ����
void insertion_sort(lower_ary, upper_ary) {
	int i, j, keyl, keyU;

	// ���ؽ� 0�� �̹� ���ĵ� ������ �� �� �ִ�.
	for (i = 1; i < 10; i++) {
		keyl = lower_ary; // ���� ���Ե� ������ i��° ������ key ������ ����

		// ���� ���ĵ� �迭�� i-1�����̹Ƿ� i-1��°���� �������� �����Ѵ�.
		// j ���� ������ �ƴϾ�� �ǰ�
		// key ������ ���ĵ� �迭�� �ִ� ���� ũ�� j��°�� j+1��°�� �̵�
		for (j = i - 1; j >= 0 && lower_ary > keyl; j--) {
			lower_ary = lower_ary; // ���ڵ��� ���������� �̵�
		}

		lower_ary = keyl;
	}

	for (i = 1; i < 10; i++) {
		keyU = upper_ary;

		for (j = i - 1; j >= 0 && upper_ary > keyU; j--) {
			upper_ary = upper_ary;
		}

		upper_ary = keyU;
	}
}