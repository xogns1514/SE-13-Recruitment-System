#include <stdio.h>
#include <string.h>
#include "ShowApplyInformationUI.h"

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask();
void programExit();

// 변수 선언
FILE* inFp, * outFp;

// boundary class 변수 선언
ShowApplyInformationUI showApplyInformationUI;
int main() {
	// 파일 입출력을 위한 초기화
	inFp = fopen(INPUT_FILE_NAME, "r+");
	outFp = fopen(OUTPUT_FILE_NAME, "w+");

	doTask();

	return 0;
}

void doTask() {
	// 메뉴 파싱을 위한 level 구분을 위한 변수
	int menuLevel1 = 0, menuLevel2 = 0;
	int isProgramExit = 0;

	while (!isProgramExit) {
		// 입력 파일에서 메뉴 숫자 2개 읽기
		fscanf(inFp, "%d %d ", &menuLevel1, &menuLevel2);

		// 메뉴 구분 및 해당 연산 수행
		switch (menuLevel1)
		{
		case 1:
		{
			switch (menuLevel2)
			{
			case 1:		// 1.1 회원 가입 
			{
				break;
			}
			case 2:		// 1.2 회원 탈퇴
			{
				break;
			}
			}
		}
		case 2:
		{
			switch (menuLevel2)
			{
			case 1:		// 2.1 로그인
			{
				break;
			}
			case 2:		// 2.2 로그아웃
			{
				break;
			}
			}
		}
		case 3:
		{
			switch (menuLevel2)
			{
			case 1:		// 3.1 채용 정보 등록
			{
				break;
			}
			case 2:		//3.2 등록된 채용 정보 조회
			{
				break;
			}
			}
		case 4:
		{
			switch (menuLevel2)
			{
			case 1:		// 4.1 채용 정보 검색
			{
				break;
			}
			case 2:		// 4.2 채용 지원
			{
				break;
			}
			case 3:		// 4.3 지원 정보 조회
			{
				break;
			}
			case 4:		//4.4 지원 취소
			{
				showApplyInformationUI.cancelApply();
				break;
			}
			}
		}
		case 5:
		{
			switch (menuLevel2) {
			case 1:		// 5.1 지원 정보 통계
			{
				showApplyInformationUI.showWorkApply();
				break;
			}
			}
		}
		case 6:
			switch (menuLevel2) {
			case 1:		// 6.1 종료
			{
				programExit();
				isProgramExit = 1;
				break;
			}
			}
		}

		}
	}
}

void programExit() {

}