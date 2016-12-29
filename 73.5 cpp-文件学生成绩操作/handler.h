
#ifndef HANDLER_H_
#define HANDLER_H_

#include "head.h"

class Handler{
public:
	Handler(string fileStu, string fileCourse);
	~Handler();

	//init course
	void courseInfo();
	void setCourse();
	void printCourse();
	Course findCourse(char *name);


	//stu info
	void stuInfo();
	void addStuInfo();
	void changeStuInfo();
	void delStuInfo();
	void printStuInfo();
	Student findStuInfo(char* id);

	//search
	void search();
	void getStuScoreGrade();
	void getCourseStuScore();

	//statistic
	void statistic();
	void flunkedStu();
	void sortCourse();
	void sortBySumScore();
private:
	string	m_fileStu;
	string	m_fileCourse;

	string	m_menuInfo = "\t\t-------------student info----------------\n\
		\t\t	1.add student info\n\
		\t\t	2.change student info\n\
		\t\t	3.del stu info\n\
		\t\t	4.print stu info\n\
		\t\t	5.go out\n\
		\t\t-------------student info----------------\n\n";

	string	m_menuSearch = "\t\t-------------search score----------------\n\
		\t\t	1.search stu score by stu number\n\
		\t\t	2.search all score by coures\n\
		\t\t	3.go out\n\
		\t\t-------------search score----------------\n\n";

	string	m_menuStatic = "\t\t-----------statistic score---------------\n\
		\t\t	1.statistic flunked stu by course\n\
		\t\t	2.sort score by course\n\
		\t\t	3.sort by the sum socre \n\
		\t\t	4.go out\n\
		\t\t-----------statistic score---------------\n\n";

	string	m_menuCourse = "\t\t------------course info----------------\n\
		\t\t	1.add course info\n\
		\t\t	2.show course info\n\
		\t\t	3.go out\n\
		\t\t------------course info----------------\n\n";
};




#endif
