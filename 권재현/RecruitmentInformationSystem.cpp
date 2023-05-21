#include "RecruitmentInformationSystem.h"
#include "SearchEmploymentUI.h"

void doTask()
{
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    SearchEmploymentUI searchEmploymentUI;

    while (!is_program_exit)
    {
        // 입력파일에서 메뉴 숫자 2개를 읽기
        fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);


        // 메뉴 구분 및 해당 연산 수행
        switch (menu_level_1)
        {
            case 1:
                switch (menu_level_2)
                {
                    case 1:   // "1.1. 회원가입“ 메뉴 부분
                        // join() 함수에서 해당 기능 수행 
                        join();
                        break;
                    case 2:
                        //어쩌구
                        break;
                }
            case 4:
                switch (menu_level_2)
                {
                    case 1:
                        char company_name[MAX_STRING];
                        fscanf(in_fp, "%s", company_name);
                        searchEmploymentUI.SearchByCompanyName(company_name);
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                }

            case 7:
                switch (menu_level_2)
                {
                    case 1:   // "6.1. 종료“ 메뉴 부분
                        program_exit();
                        is_program_exit = 1;
                        break;
                }
        }

    }

    return;
}


void join()
{
    /*            !!!!!!!       중요        !!!!!!!!!
        * 단순히 파일을 통해 입출력하는 방법을 보이기 위한 코드이므로 이 함수에서 그대로 사용하면 안됨.
        * control 및 boundary class를 이용해서 해당 기능이 구현되도록 해야 함.
        */

    char user_type[MAX_STRING], name[MAX_STRING], SSN [MAX_STRING], address[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];

    // 입력 형식 : 이름, 주민번호, ID, Password를 파일로부터 읽음
    fscanf(in_fp, "%s %s %s %s", name, SSN, ID, password);


    // 해당 기능 수행  
    //''''''

        // 출력 형식
    fprintf(out_fp, "1.1. 회원가입\n");
    fprintf(out_fp, "%s %s %s %s\n", name, SSN, ID, password);
}


void program_exit()
{
    //'''''
}