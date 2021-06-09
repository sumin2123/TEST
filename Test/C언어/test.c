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


typedef struct Fitness {
	int num;		//회원 번호
	char name[20];	//이름을 저장할 변수
	double weight;	// 몸무게를 저장할 변수

} Fitness; //노드


// 배열,사용자 정의 자료형, 포인터, 사용자함수, 메모리 동적 할당, 제어문, 표준 입출력 함수 사용 => 평가 목록

int insert_info(Fitness** pary);
int max_weight(Fitness** pary, int count); // 3.최대 체중 회원의 index 반환
/*
void total_number(int count); // 1.전체 등록 회원 수 반환
double average_weight(Fitness** pary, int count); // 2. 평균 체중 반환

void print_info(Fitness** pary, int index); // 4.회원 정보 출력
void free_ary(Fitness** pary, int count); // 5.동적 할당 영역 해제
*/



int insert_info(Fitness** pary) {
	int i;
	int k;
	int count = 0;
	printf("음수를 입력하면 종료가 됩니다.\n");
	printf("추가할 회원 번호를 입력하세요: ");
	scanf("%d", &i);

	// i는 회원 번호를 뜻하는 것이며, num과 같다.

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
			
			printf("계속하시겠어요? 계속하시려면 양수를 입력하세요. \n 음수를 입력 시 메뉴로 가게됩니다.\n");
			scanf("%d", &k);
			if (k < 0) { return count+1; }
			else count++;
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


	// 배열보ㄷr... 연결리스.... 
	//printf("%d번 회원 정보 출력 ~!\n", i + 1, pary[i]->num);

}


// 전체 등록 회원 수 반환
void total_number(int count) {

	printf("%d명의 회원이 존재합니다.\n\n", count);

}

// 평균 체중 반환
double average_weight(Fitness** pary, int count) {

	int total = 0; // 몸무게 총합
	double averageWe; // 평균 체중 담을 변수

	if (count > 0) // 회원이 없는 경우 예외처리
	{
		for (int i = 0; i < count; i++) //회원 수 만큼 반복시킨다.
		{
			total = total + pary[i]->weight;
			averageWe = total / count;
		}
	}
	
	// 회원들 체중을 모두 더해준다(for문으로)
	// 전체 회원 수 count 를 가져와서 나눠준다.

	return averageWe;	//몸무게 반환 
}

//최대 체중 회원의 index 반환 => 최댓값 찾는거 비교
int max_weight(Fitness** pary, int count) {
	// 노드 전체를 이동하면서 무게순으로 갱신한다.

	// 최대 체중 찾기 Start~!
	int Max_index = 0; //배열이 인덱스, 최대일때의 인덱스
	for (int i = 0; i < count; i++) {
		if (pary[i]->weight > pary[Max_index]->weight) { // max는 인덱스이기 때문에 max번째의 무게와 비교 
			Max_index = i; // 무게를 출력하는것이 아니라 회원 index를 반환하기 때문에 이렇게 해줘야 한다.
		}
	}
	printf("%d회원의 정보를 출력합니다.\n", Max_index); // Max_index가 회원 번호
	printf("이름: %s\n", pary[Max_index]->name);			// Max_index번 회원의 이름 출력
	printf("몸무게:%lf\n\n", pary[Max_index]->weight);		// Max_index번 회원의 몸무게 출력

	return Max_index; // 인덱스를 리턴
}
	// 동적 할당 영역 해제
	void free_ary(Fitness **pary, int count) {
		for (int i = 0; i < count; i++)
		{
			free(pary[i]);
		}
		printf("\n동적 할당 해제\n");
	}



	int main(void) {

		int count = 0;
		Fitness* pary[100];	//포인터 배열 선언

		int k;
		while (1)
		{
			printf("<======== 메뉴 ========>\n");
			printf("1.회원 정보 입력하기\t");
			printf("2.전체 등록 회원 수 보기\n");
			printf("3.평균 체중 확인하기\t");
			printf("4.최대 몸무게 회원 정보 출력하기\n");
			printf("5.회원 정보 출력하기\n");
			printf("음수를 입력하면 종료됩니다.\n"); //음수 입력시 종료
			printf("원하는 번호를 입력하세요: ");
			scanf("%d", &k);

			if (k < 0)  // 음수 입력시 실행 종료
			{
				free_ary(pary, count);
				break;
			}
			else
			{
				if (1 == k) {
					printf("\n<==== 회원 정보 입력하기 ====>\n");
					count += insert_info(pary); // 등록할때마다 카운트수 증가

					//입력 함수 호출
				}
				else if (2 == k) {
					printf("\n<==== 전체 등록 회원 수 확인 ====>\n");
					// 전체 등록 회원 수 확인하는 함수 호출
					// 회원 수 출력하기

					//회원 수를 몇명인지 체크하기
					total_number(count);
				}
				else if (3 == k) {
					double averageWe;
					printf("\n<==== 평균 체중 확인 ====>\n");
					// 평균 체중 확인하는 함수 호출
					averageWe = average_weight(pary, count);
					//평균 값을 화면에 출력
					printf("총 회원들의 평균 체중은 %g입니다.", averageWe);
				}
				else if (4 == k) {
					printf("\n<==== 최대 몸무게 회원 정보 출력 ====>\n");
					// 최대 몸무게 회원 정보 출력하는 함수 호출
					int Max_index = max_weight(pary, count);
				}
				else if (5 == k)
					printf("\n<==== 회원 정보 출력 ====>\n");
				// 회원 정보 출력하는 함수 호출

				else {
					printf("\n<==== 올바른 수를 입력해주세요~! ====>");
					return 0;
				}
			}
			
		}
		
	}


