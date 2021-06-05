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

/*
void total_number(int count); // 1.��ü ��� ȸ�� �� ��ȯ
double average_weight(Fitness** pary, int count); // 2. ��� ü�� ��ȯ
int max_weight(Fitness** pary, int count); // 3.�ִ� ü�� ȸ���� index ��ȯ
void print_info(Fitness** pary, int index); // 4.ȸ�� ���� ���
void free_ary(Fitness** pary, int count); // 5.���� �Ҵ� ���� ����
*/

int main(void) {

	Fitness* pary[100];	//������ �迭 ����

	int k;
	printf("1.ȸ�� ���� �Է��ϱ�\t");
	printf("2.��ü ��� ȸ�� �� ����\n");
	printf("3.��� ü�� Ȯ���ϱ�\t");
	printf("4.ȸ�� ���� ����ϱ�\n");
	printf("������ �Է��ϸ� ����˴ϴ�.\n"); //���� �Է½� ����
	printf("���ϴ� ��ȣ�� �Է��ϼ���: ");
	scanf("%d", &k);

	if (k < 0)  // ���� �Է½� ���� ����
		return 0;
	else
	{
		switch (k)
		{
		case 1:
			printf("ȸ�� ���� �Է� �Լ� ȣ��\n");
			//�Է� �Լ� ȣ��
			insert_info(* pary);
		case 2:
			printf("��ü ��� ȸ�� �� Ȯ��\n");
			// ��ü ��� ȸ�� �� Ȯ���ϴ� �Լ� ȣ��
			//strcpy();
		case 3:
			printf("��� ü�� Ȯ��\n");
			// ��� ü�� Ȯ���ϴ� �Լ� ȣ��
			//strcpy();

		case 4:
			printf("ȸ�� ���� ����ϱ�\n");
			// ȸ�� ���� ����ϴ� �Լ� ȣ��
			//strcpy();


		default:
			printf("�ùٸ� ���� �Է����ּ���~!");
			break;
		}
	}
	return 0;
}

void insert_info(Fitness** pary) {
	int i;
	printf("������ �Է��ϸ� ���ᰡ �˴ϴ�.\n");
	printf("�߰��� ȸ�� ��ȣ�� �Է��ϼ���: ");
	scanf("%d", &i);

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
			int k;
			printf("����Ͻðھ��? ������ �Է� �� �޴��� ���Ե˴ϴ�.");
			scanf("%d", &k);
			if (k < 0)
				break;

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



	//printf("%d�� ȸ�� ���� ��� ~!\n", i + 1, pary[i]->num);

}


//
//
//// ��ü ��� ȸ�� �� ��ȯ
//void total_number(int count) {
//	printf("<============ ��ü ��� ȸ�� �� ============>");
//	
//	
//}
//
//// ��� ü�� ��ȯ
//double average_weight(Fitness** pary, int count) {
//	printf("<============ ȸ���� ��� ü�� �� ============>");	
//
//	int total; // ������ ����
//	int averageWe; // ��� ü�� ���� ����
//
//	
//
//
//
//}
//
////�ִ� ü�� ȸ���� index ��ȯ => �ִ� ã�°� ��
//int max_weight(Fitness** pary, int count) {
//	printf("<============ �ִ� ü�� ȸ�� ============>");
//	Fitness* ary = pary;
//	// ��� ��ü�� �̵��ϸ鼭 ���Լ����� �����Ѵ�.
//
//	// �ִ� ü�� ã�� Start~!
//	int Max = 0;
//	for (int i=0;i<count;i++){
//		if (pary[i] > Max) {
//			Max = pary[i];
//		}
//		printf("%d�� ȸ�� ������ ����մϴ�.\n", i + 1, pary[i]->num);
//}
//
//
//
////// ���� �Ҵ� ���� ����
////void free_ary(Fitness** pary, int count) {
////	
////}










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
