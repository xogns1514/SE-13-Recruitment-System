#include "ShowApplyInformation.h"
#include <map>
#include <iterator>


ShowApplyInformation::ShowApplyInformation(Apply* applies, Recruitment* recruitments) {
	this->applies = applies;
	this->recruitments = recruitments;
}

/*
* 지원 취소 기능을 하는 함수
*/
void ShowApplyInformation::cancelApply(int companyNumber, string applierID) {

	for (int i = 0; i < sizeof(applies); i++) {
		// 지원 목록 중 현재 로그인한 회원이 지원하였으며
		// 입력받은 사업자 번호와 일치하는 지원 객체인 경우 해당 객체를 삭제
		if (applies[i].getCompanyNumber() == companyNumber && applies[i].getApplierID().compare(applierID)) {
			cout << applies[i].getCompanyName() << " " << companyNumber << " " << applies[i].getWork() << endl;
			applies[i].cancelApply();
		}
	}
}

/*
* 지원 정보 통계 정보를 가져오는 함수
*/
void ShowApplyInformation::showWorkApply(Member member, string ID) {

	// 회사 회원인 경우
	if (typeid(member) == typeid(CompanyMember)) {
		for (int i = 0; i < sizeof(recruitments); i++) {
			// 현재까지 등록한 모든 채용 정보에 대해 업무별 지원자 수 출력
			if (recruitments[i].getWriterID().compare(ID)) {
				cout << recruitments[i].getWork() << " " << recruitments[i].getApplyCount() << endl;
			}
		}
	}

	// 일반 회원인 경우
	else {
		map<string, int> countByWork;	// 업무별 지원 횟수를 저장하는 map 변수
		map<string, int>::iterator it;	// map을 순회하기 위한 iterator 변수

		for (int i = 0; i < sizeof(applies); i++) {

			// 본인이 지원한 정보에 대해 업무별 지원 횟수 출력
			if (applies[i].getApplierID().compare(ID)) {
				it = countByWork.find(applies[i].getWork());

				// 해당 업무가 map에 없는 경우
				if (it == countByWork.end()) {
					countByWork[applies[i].getWork()] = 1;	// map에 추가
				}
				// 해당 업무가 map에 있는 경우
				else {
					++countByWork[applies[i].getWork()];	// 기존 value 값을 1 증가
				}
				
			}
		}

		for (it = countByWork.begin(); it != countByWork.end(); it++) {
			cout << it->first << " " << it->second << endl;
		}
	}
}