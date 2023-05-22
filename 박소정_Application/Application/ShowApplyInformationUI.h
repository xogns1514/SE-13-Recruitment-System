#include "ShowApplyInformation.h"
#include <vector>

/*
* 지원 정보(Apply)를 화면에 출력하는 boundary class
*/
class ShowApplyInformationUI {
private:
	ShowApplyInformation showApplyInformation;
public:
	ShowApplyInformationUI();
	ShowApplyInformationUI(vector<Apply>& apply, vector<Recruitment>& recruitment);
	void inquireApply();
	void showWorkApply(Member member, string ID);			// 지원 정보 통계
	void cancelApply(int companyNumber, string applierID);	// 지원 취소
};
