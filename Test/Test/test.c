#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h> // 대소문자 판별 함수
#include <string.h>


void insertionlower(char lower_ary[], int n);
void insertionupper(char upper_ary[], int n);

void main(void) {
	//입력 값을 문자열 포인터에 저장하기
	char input_ary[10]; // 10개 크기만큼 동적 메모리 할당 / 입력받은 문자를 임시 저장


	printf("대,소문자 구분없이 알파벳을 입력하세요 : ");
	scanf("%s", input_ary); // 표준 입력을 받아서 배열 형태의 문자열에 저장
	printf("입력받은 값 : %s\n\n", input_ary);

	int len = strlen(input_ary);

	// 소문자 구분
	char lower_ary[10];	// 소문자 저장 배열
	char upper_ary[10];	// 대문자 저장 배열
	int n = 0;  //배열에 삽입하기 위한 인덱스 값

	printf("==== 소문자만~!\n");
	for (int i = 0; i < len; i++)
	{
		if (islower(input_ary[i]))	//islower => 소문자 구분 함수
		{
			printf("%c \n", input_ary[i]); // 소문자만 출력
			lower_ary[n] = input_ary[i]; // lower_ary 배열에 저장
			n++;
			
		}

	}
	// 소문자 삽입 정렬 수행
	insertionlower(lower_ary, n);

	printf("\n ==== 대문자만~!\n");
	// 대문자 구분
	n = 0;
	for (int i = 0; i<len; i++)
	{
		if (isupper(input_ary[i]))	//isupper => 대문자 구분 함수
		{
			printf("%c \n", input_ary[i]); // 대문자만 출력
			upper_ary[n] = input_ary[i];// upper_ary 배열에 저장
			n++;
		}
	}

	// 대문자 삽입 정렬 수행
	insertionupper(upper_ary, n);

	return 0;
}


 // 삽입 정렬 함수 => 소문자만
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
	printf("\n\n============= 소문자 삽입 정렬 완료 =============\n");
	printf("\n\n");

}


// 삽입 정렬 함수 => 대문자만
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
	printf("\n\n============= 대문자 삽입 정렬 완료 =============\n");
}