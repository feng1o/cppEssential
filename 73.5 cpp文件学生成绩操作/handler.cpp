
#include "handler.h"
using namespace std;

Handler::Handler(string fileStu, string fileCourse){
	m_fileCourse = fileCourse;
	m_fileStu = fileStu;
}

Handler::~Handler(){
	
};



void Handler::stuInfo(){
	while (1){
		cout << m_menuInfo;
		int n = 4;
		cin >> n;
		switch (n){
		case 1:{
			addStuInfo();
			break;
		}
		case 2:{
			changeStuInfo();
			break;
		}
		case 3:{
			delStuInfo();
			break;
		}
		default:return;
		}
	}
}
void Handler::search(){
	while (1){
		cout << m_menuSearch;
		int n = 4;
		cin >> n;
		switch (n){
		case 1:{
			getStuScoreGrade();
			break;
		}
		case 2:{
			getCourseStuScore();
			break;
		}
		default:return;
		}
	}

}
void Handler::statistic(){
	while (1){
		cout << m_menuStatic;
		int n = 4;
		cin >> n;
		switch (n){
		case 1:{
			flunkedStu();
			break;
		}
		case 2:{
			sortCourse();
			break;
		}
		case 3:{
			sortBySumScore();
			break;
		}
		default:return;
		}
	}

}
