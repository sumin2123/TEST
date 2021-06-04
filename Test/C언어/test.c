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


typedef struct Fitness{
	int num;		//ȸ�� ��ȣ
	char name[20];	//�̸��� ������ ����
	double weight;	// �����Ը� ������ ����

} Fitness; //���


// �迭,����� ���� �ڷ���, ������, ������Լ�, �޸� ���� �Ҵ�, ���, ǥ�� ����� �Լ� ��� => �� ���


void total_number(int count); // 1.��ü ��� ȸ�� �� ��ȯ
double average_weight(Fitness** pary, int count); // 2. ��� ü�� ��ȯ
int max_weight(Fitness** pary, int count); // 3.�ִ� ü�� ȸ���� index ��ȯ
void print_info(Fitness** pary, int index); // 4.ȸ�� ���� ���
void free_ary(Fitness** pary, int count); // 5.���� �Ҵ� ���� ����



int main(void) {
	
	Fitness* pary[100];	//������ �迭 ����

	// ȸ�� ���� �Է¹ޱ�  >> ���� �Է� �� ���� ����
	for (int i = 0; i < 100; i++) {
		// �������� �ƴ��� Ȯ�� >> ����
		
		//else
		pary[i] = (struct ary*)malloc(sizeof(struct Fitness));
		printf("%d��° ȸ�� �Է�\n", i + 1);
		pary[i]->num = i + 1;

		printf("�̸��� �Է��ϼ��� : ");
		scanf("%s", pary[i]->name);

		printf("�����Ը� �Է��ϼ���: ");
		scanf("%.2f",pary[i]->weight);
		puts("");

	}

	return 0;
}

void print_info(Fitness** pary, int index) // 4.ȸ�� ���� ���
{
	// ���������� ȸ�� ��ü ���� ���� �����ؼ� ����. -> ������ ��� ���
	// �迭�� ��ȣ�� �Է� �޾Ƽ� �ش� �迭�� ������ ����Ѵ�.
	// ȸ����ȣ �Է� �ޱ�

	printf("ȸ�� ��ȣ�� �Է��ϼ���: ");
	scanf("%d", &index);
	



	//printf("%d�� ȸ�� ���� ��� ~!\n", i + 1, pary[i]->num);

	
}


// ��ü ��� ȸ�� �� ��ȯ
void total_number(int count) {
	printf("<============ ��ü ��� ȸ�� �� ============>");
	
	
}

// ��� ü�� ��ȯ
double average_weight(Fitness** pary, int count) {
	printf("<============ ȸ���� ��� ü�� �� ============>");	

	int total; // ������ ����
	int averageWe; // ��� ü�� ���� ����

	



}

//�ִ� ü�� ȸ���� index ��ȯ => �ִ� ã�°� ��
int max_weight(Fitness** pary, int count) {
	printf("<============ �ִ� ü�� ȸ�� ============>");
	Fitness* ary = pary;
	// ��� ��ü�� �̵��ϸ鼭 ���Լ����� �����Ѵ�.

	// �ִ� ü�� ã�� Start~!
	int Max = 0;
	for (int i=0;i<count;i++){
		if (pary[i] > Max) {
			Max = pary[i];
		}
		printf("%d�� ȸ�� ������ ����մϴ�.\n", i + 1, pary[i]->num);
}



//// ���� �Ҵ� ���� ����
//void free_ary(Fitness** pary, int count) {
//	
//}










/* ��ȭ �������� �����*/
//int SelectMenu();
//void total();
//void average();
//void maxw();
//void printall();
//
//void Initialize(); // ȸ�� ������ �ʱ�ȭ
//void Run();
//
//void Run() {
//	int key = 0;
//	while ((key = SelectMenu()) != 0) // ������ �޴��� 0�� �ƴϸ� �ݺ�
//	{
//		switch (key) //key ���ÿ� ���� ��� ����
//		{
//		case 1: total(); break;
//		case 2: average(); break;
//		case 3: maxw(); break;
//		case 4: printall(); break;
//		default: printf("�߸� �����ϼ̽��ϴ�.\n");
//			break;
//		}
//		printf("���α׷� ����\n");
//	}
//
//
//	int SelectMenu();
//	{
//		int key = 0;
//		printf("ȸ�� ���� ���α׷� 0:����\n");
//		printf("1.���ȸ�� ��\n 2.��� ü�� \n 3.�ִ� ü�� ȸ�� \n 4.ȸ�� ���� ��ü Ȯ��\n");
//		scanf("%d", &key);
//		return key;
//	}
//
//	int IsAvailNum(int num);//��ȿ�� ��ȣ���� �Ǻ�
//	int IsAvailScore(int weight);//��ȿ�� �������� �Ǻ�
