/*	휘트니스 회원관리 프로그램

	1. 신규 등록 => 힙영역에 저장 (회원번호, 이름, 체중)
		입력 받기(scanf) -> 회원 번호 음수로 입력시 입력 종료
	2. 출력해서 입력 받은값 확인해보기

	3.출력시 총 회원 수, 평균 체중, 최고 체중 회원 출력

 */
#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h> //memcpy 함수를 사용하기 위함


typedef struct Fitness{
	int num;		//회원 번호
	char name[20];	//이름을 저장할 변수
	double weight;	// 몸무게를 저장할 변수

} Fitness; //노드


// 배열,사용자 정의 자료형, 포인터, 사용자함수, 메모리 동적 할당, 제어문, 표준 입출력 함수 사용 => 평가 목록

/*
void total_number(int count); // 1.전체 등록 회원 수 반환
double average_weight(Fitness** pary, int count); // 2. 평균 체중 반환
int max_weight(Fitness** pary, int count); // 3.최대 체중 회원의 index 반환
void print_info(Fitness** pary, int index); // 4.회원 정보 출력
void free_ary(Fitness** pary, int count); // 5.동적 할당 영역 해제
*/

int main(void) {

	Fitness* pary[100];	//포인터 배열 선언

	int k;
	printf("1.회원 정보 입력하기\t");
	printf("2.전체 등록 회원 수 보기\n");
	printf("3.평균 체중 확인하기\t");
	printf("4.회원 정보 출력하기\n");
	printf("음수를 입력하면 종료됩니다.\n"); //음수 입력시 종료
	printf("원하는 번호를 입력하세요: ");
	scanf("%d", &k);

	if (k < 0)  // 음수 입력시 실행 종료
		return 0;
	else
	{
		switch (k)
		{
		case 1:
			printf("회원 정보 입력 함수 호출\n");
			//입력 함수 호출
			insert_info(* pary);
		case 2:
			printf("전체 등록 회원 수 확인\n");
			// 전체 등록 회원 수 확인하는 함수 호출
			//strcpy();
		case 3:
			printf("평균 체중 확인\n");
			// 평균 체중 확인하는 함수 호출
			//strcpy();

		case 4:
			printf("회원 정보 출력하기\n");
			// 회원 정보 출력하는 함수 호출
			//strcpy();


		default:
			printf("올바른 수를 입력해주세요~!");
			break;
		}
	}
	return 0;
}

void insert_info(Fitness** pary) {
	int i;
	printf("음수를 입력하면 종료가 됩니다.\n");
	printf("추가할 회원 번호를 입력하세요: ");
	scanf("%d", &i);

	if (i < 0)
		return 0; // 음수이면 >> 종료
	else
	{
		pary[i] = (struct ary*)malloc(sizeof(struct Fitness));
		printf("%d번째 회원 입력\n", i);

		for (i; i < 100; i++)
		{
			pary[i] = (struct ary*)malloc(sizeof(struct Fitness));
			pary[i]->num = i;
			printf("이름을 입력하세요 : ");
			scanf("%s", pary[i]->name);

			printf("몸무게를 입력하세요: ");
			scanf("%lf", &pary[i]->weight);

			printf("\n");
			int k;
			printf("계속하시겠어요? 음수를 입력 시 메뉴로 가게됩니다.");
			scanf("%d", &k);
			if (k < 0)
				break;

			// 입력에서 바로 넘어가기
			printf("%d번째 회원 입력\n", i + 1);	// 다음 회원번호 자동으로 입력
		}
	}
}

void print_info(Fitness** pary, int index) // 4.회원 정보 출력 , index = 회원 정보
{
	// 전역변수로 회원 전체 수를 따로 저장해서 쓴다. -> 연성이 언니 방법
	// 배열의 번호를 입력 받아서 해당 배열의 정보만 출력한다.
	// 회원번호 입력 받기
	int number;
	printf("회원 번호를 입력하세요: ");
	scanf("%d", &number);
	
	printf("%d번 회원 정보 출력 ~!\n", number + 1, pary[number]->num);

	// while 문으로 회원 정보 일치하는 사람 찾기
	while (index)
	{

	}



	//printf("%d번 회원 정보 출력 ~!\n", i + 1, pary[i]->num);

}


//
//
//// 전체 등록 회원 수 반환
//void total_number(int count) {
//	printf("<============ 전체 등록 회원 수 ============>");
//	
//	
//}
//
//// 평균 체중 반환
//double average_weight(Fitness** pary, int count) {
//	printf("<============ 회원들 평균 체중 수 ============>");	
//
//	int total; // 몸무게 총합
//	int averageWe; // 평균 체중 담을 변수
//
//	
//
//
//
//}
//
////최대 체중 회원의 index 반환 => 최댓값 찾는거 비교
//int max_weight(Fitness** pary, int count) {
//	printf("<============ 최대 체중 회원 ============>");
//	Fitness* ary = pary;
//	// 노드 전체를 이동하면서 무게순으로 갱신한다.
//
//	// 최대 체중 찾기 Start~!
//	int Max = 0;
//	for (int i=0;i<count;i++){
//		if (pary[i] > Max) {
//			Max = pary[i];
//		}
//		printf("%d번 회원 정보를 출력합니다.\n", i + 1, pary[i]->num);
//}
//
//
//
////// 동적 할당 영역 해제
////void free_ary(Fitness** pary, int count) {
////	
////}










/* 심화 프로프램 만들기*/
//int SelectMenu();
//void total();
//void average();
//void maxw();
//void printall();
//
//void Initialize(); // 회원 데이터 초기화
//void Run();
//
//void Run() {
//	int key = 0;
//	while ((key = SelectMenu()) != 0) // 선택한 메뉴가 0이 아니면 반복
//	{
//		switch (key) //key 선택에 따라 기능 수행
//		{
//		case 1: total(); break;
//		case 2: average(); break;
//		case 3: maxw(); break;
//		case 4: printall(); break;
//		default: printf("잘못 선택하셨습니다.\n");
//			break;
//		}
//		printf("프로그램 종료\n");
//	}
//
//
//	int SelectMenu();
//	{
//		int key = 0;
//		printf("회원 관리 프로그램 0:종료\n");
//		printf("1.등록회원 수\n 2.평균 체중 \n 3.최대 체중 회원 \n 4.회원 정보 전체 확인\n");
//		scanf("%d", &key);
//		return key;
//	}
//
//	int IsAvailNum(int num);//유효한 번호인지 판별
//	int IsAvailScore(int weight);//유효한 무게인지 판별
