/*	휘트니스 회원관리 프로그램

	1. 신규 등록 => 힙영역에 저장 (회원번호, 이름, 체중)
		입력 받기(scanf) -> 회원 번호 음수로 입력시 입력 종료
	2. 출력해서 입력 받은값 확인해보기

	3.출력시 총 회원 수, 평균 체중, 최고 체중 회원 출력

 */
typedef struct {
	int mun;
	char name[20];
	double weight;
} Fitness;

Fitness* ary[100];	//포인터 배열 선언
void total_number(int count); // 전체 등록 회원 수 반환
double average_weight(Fitness** pary, int count); // 평균 체중 반환
int max_weight(Fitness** pary, int count); // 최대 체중 회원의 index 반환
void print_info(Fitness** pary, int index); // 회원 정보 출력
void free_ary(Fitness** pary, int count); // 동적 할당 영역 해제

// 배열,사용자 정의 자료형, 포인터, 사용자함수, 메모리 동적 할당, 제어문, 표준 입출력 함수 사용 => 평가 목록