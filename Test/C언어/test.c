/*	��Ʈ�Ͻ� ȸ������ ���α׷�

	1. �ű� ��� => �������� ���� (ȸ����ȣ, �̸�, ü��)
		�Է� �ޱ�(scanf) -> ȸ�� ��ȣ ������ �Է½� �Է� ����
	2. ����ؼ� �Է� ������ Ȯ���غ���

	3.��½� �� ȸ�� ��, ��� ü��, �ְ� ü�� ȸ�� ���

 */
#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h> //memcpy �Լ��� ����ϱ� ����


typedef struct Fitness {
	int num;		//ȸ�� ��ȣ
	char name[20];	//�̸��� ������ ����
	double weight;	// �����Ը� ������ ����

} Fitness; //���


// �迭,����� ���� �ڷ���, ������, ������Լ�, �޸� ���� �Ҵ�, ���, ǥ�� ����� �Լ� ��� => �� ���

int insert_info(Fitness** pary);
int max_weight(Fitness** pary, int count); // 3.�ִ� ü�� ȸ���� index ��ȯ
/*
void total_number(int count); // 1.��ü ��� ȸ�� �� ��ȯ
double average_weight(Fitness** pary, int count); // 2. ��� ü�� ��ȯ

void print_info(Fitness** pary, int index); // 4.ȸ�� ���� ���
void free_ary(Fitness** pary, int count); // 5.���� �Ҵ� ���� ����
*/



int insert_info(Fitness** pary) {
	int i;
	int k;
	int count = 0;
	printf("������ �Է��ϸ� ���ᰡ �˴ϴ�.\n");
	printf("�߰��� ȸ�� ��ȣ�� �Է��ϼ���: ");
	scanf("%d", &i);

	// i�� ȸ�� ��ȣ�� ���ϴ� ���̸�, num�� ����.

	if (i < 0)
		return 0; // �����̸� >> ����
	else
	{
		pary[i] = (struct ary*)malloc(sizeof(struct Fitness));
		printf("%d��° ȸ�� �Է�\n", i);

		for (i; i < 100; i++)
		{
			pary[i] = (struct ary*)malloc(sizeof(struct Fitness));
			pary[i]->num = i;
			printf("�̸��� �Է��ϼ��� : ");
			scanf("%s", pary[i]->name);

			printf("�����Ը� �Է��ϼ���: ");
			scanf("%lf", &pary[i]->weight);


			printf("\n");
			
			printf("����Ͻðھ��? ����Ͻ÷��� ����� �Է��ϼ���. \n ������ �Է� �� �޴��� ���Ե˴ϴ�.\n");
			scanf("%d", &k);
			if (k < 0) { return count+1; }
			else count++;
			// �Է¿��� �ٷ� �Ѿ��
			printf("%d��° ȸ�� �Է�\n", i + 1);	// ���� ȸ����ȣ �ڵ����� �Է�

		}
	}
}

void print_info(Fitness** pary, int index) // 4.ȸ�� ���� ��� , index = ȸ�� ����
{
	// ���������� ȸ�� ��ü ���� ���� �����ؼ� ����. -> ������ ��� ���
	// �迭�� ��ȣ�� �Է� �޾Ƽ� �ش� �迭�� ������ ����Ѵ�.
	// ȸ����ȣ �Է� �ޱ�
	int number;
	printf("ȸ�� ��ȣ�� �Է��ϼ���: ");
	scanf("%d", &number);

	printf("%d�� ȸ�� ���� ��� ~!\n", number + 1, pary[number]->num);
	// while ������ ȸ�� ���� ��ġ�ϴ� ��� ã��
	while (index)
	{

	}


	// �迭����r... ���Ḯ��.... 
	//printf("%d�� ȸ�� ���� ��� ~!\n", i + 1, pary[i]->num);

}


// ��ü ��� ȸ�� �� ��ȯ
void total_number(int count) {

	printf("%d���� ȸ���� �����մϴ�.\n\n", count);

}

// ��� ü�� ��ȯ
double average_weight(Fitness** pary, int count) {

	int total = 0; // ������ ����
	double averageWe; // ��� ü�� ���� ����

	if (count > 0) // ȸ���� ���� ��� ����ó��
	{
		for (int i = 0; i < count; i++) //ȸ�� �� ��ŭ �ݺ���Ų��.
		{
			total = total + pary[i]->weight;
			averageWe = total / count;
		}
	}
	
	// ȸ���� ü���� ��� �����ش�(for������)
	// ��ü ȸ�� �� count �� �����ͼ� �����ش�.

	return averageWe;	//������ ��ȯ 
}

//�ִ� ü�� ȸ���� index ��ȯ => �ִ� ã�°� ��
int max_weight(Fitness** pary, int count) {
	// ��� ��ü�� �̵��ϸ鼭 ���Լ����� �����Ѵ�.

	// �ִ� ü�� ã�� Start~!
	int Max_index = 0; //�迭�� �ε���, �ִ��϶��� �ε���
	for (int i = 0; i < count; i++) {
		if (pary[i]->weight > pary[Max_index]->weight) { // max�� �ε����̱� ������ max��°�� ���Կ� �� 
			Max_index = i; // ���Ը� ����ϴ°��� �ƴ϶� ȸ�� index�� ��ȯ�ϱ� ������ �̷��� ����� �Ѵ�.
		}
	}
	printf("%dȸ���� ������ ����մϴ�.\n", Max_index); // Max_index�� ȸ�� ��ȣ
	printf("�̸�: %s\n", pary[Max_index]->name);			// Max_index�� ȸ���� �̸� ���
	printf("������:%lf\n\n", pary[Max_index]->weight);		// Max_index�� ȸ���� ������ ���

	return Max_index; // �ε����� ����
}
	// ���� �Ҵ� ���� ����
	void free_ary(Fitness **pary, int count) {
		for (int i = 0; i < count; i++)
		{
			free(pary[i]);
		}
		printf("\n���� �Ҵ� ����\n");
	}



	int main(void) {

		int count = 0;
		Fitness* pary[100];	//������ �迭 ����

		int k;
		while (1)
		{
			printf("<======== �޴� ========>\n");
			printf("1.ȸ�� ���� �Է��ϱ�\t");
			printf("2.��ü ��� ȸ�� �� ����\n");
			printf("3.��� ü�� Ȯ���ϱ�\t");
			printf("4.�ִ� ������ ȸ�� ���� ����ϱ�\n");
			printf("5.ȸ�� ���� ����ϱ�\n");
			printf("������ �Է��ϸ� ����˴ϴ�.\n"); //���� �Է½� ����
			printf("���ϴ� ��ȣ�� �Է��ϼ���: ");
			scanf("%d", &k);

			if (k < 0)  // ���� �Է½� ���� ����
			{
				free_ary(pary, count);
				break;
			}
			else
			{
				if (1 == k) {
					printf("\n<==== ȸ�� ���� �Է��ϱ� ====>\n");
					count += insert_info(pary); // ����Ҷ����� ī��Ʈ�� ����

					//�Է� �Լ� ȣ��
				}
				else if (2 == k) {
					printf("\n<==== ��ü ��� ȸ�� �� Ȯ�� ====>\n");
					// ��ü ��� ȸ�� �� Ȯ���ϴ� �Լ� ȣ��
					// ȸ�� �� ����ϱ�

					//ȸ�� ���� ������� üũ�ϱ�
					total_number(count);
				}
				else if (3 == k) {
					double averageWe;
					printf("\n<==== ��� ü�� Ȯ�� ====>\n");
					// ��� ü�� Ȯ���ϴ� �Լ� ȣ��
					averageWe = average_weight(pary, count);
					//��� ���� ȭ�鿡 ���
					printf("�� ȸ������ ��� ü���� %g�Դϴ�.", averageWe);
				}
				else if (4 == k) {
					printf("\n<==== �ִ� ������ ȸ�� ���� ��� ====>\n");
					// �ִ� ������ ȸ�� ���� ����ϴ� �Լ� ȣ��
					int Max_index = max_weight(pary, count);
				}
				else if (5 == k)
					printf("\n<==== ȸ�� ���� ��� ====>\n");
				// ȸ�� ���� ����ϴ� �Լ� ȣ��

				else {
					printf("\n<==== �ùٸ� ���� �Է����ּ���~! ====>");
					return 0;
				}
			}
			
		}
		
	}


