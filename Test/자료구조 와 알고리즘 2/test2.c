#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h> // 대소문자 판별 함수
#include <string.h>

void main(void) {
	//입력 값을 문자열 포인터에 저장하기
	char input_ary[10]; // 10개 크기만큼 동적 메모리 할당 / 입력받은 문자를 임시 저장
	char lower_ary[10];	// 소문자 저장 배열
	char upper_ary[10];	// 대문자 저장 배열

	printf("대,소문자 구분없이 알파벳을 입력하세요 : ");
	scanf("%s", input_ary); // 표준 입력을 받아서 배열 형태의 문자열에 저장

	printf("입력받은 값 : %s\n\n", input_ary);

	printf("\n\n<============ 정렬하기============>\n");


	// 삽입 정렬 수행
	insertion_sort(input_ary, 10);

	// 정렬 결과 출력
	int i;

	for (i = 0; i < 10; i++) {
		printf("%d\n", input_ary[i]);
	}


	printf("\n\n<============ 대소문자 구별 ============>\n");

	// 소문자 구분
	int n = 0;
	printf("소문자 출력");
	for (int i = 0; i < (int)strlen(input_ary); ++i)
	{
		if (islower(input_ary[i]) != 0)
		{
			printf("%c ", input_ary[i]);
		}
		lower_ary[10] = input_ary[i];
	}

	printf("\n 대문자 출력");
	// 대문자 구분
	for (int i = 0; i < (int)strlen(input_ary); i++)
	{
		if (isupper(input_ary[i]) != 0)
			printf("%c ", input_ary[i]);
		upper_ary[10] = input_ary[i];
	}

	return 0;
}

// 삽입 정렬
void insertion_sort(char input_ary[], int n) {
	int i, j;
	char key;

	// 인텍스 0은 이미 정렬된 것으로 볼 수 있다.
	for (i = 1; i < n; i++) {
		key = input_ary[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사

		// 현재 정렬된 배열은 i-1까지이므로 i-1번째부터 역순으로 조사한다.
		// j 값은 음수가 아니어야 되고
		// key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+1번째로 이동
		for (j = i - 1; j >= 0 && input_ary[j] > key; j--) {
			input_ary[j + 1] = input_ary[j]; // 레코드의 오른쪽으로 이동
		}

		input_ary[j + 1] = key;
	}
}