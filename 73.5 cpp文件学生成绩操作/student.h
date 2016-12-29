#ifndef STUDENT_H_
#define STUDENT_H_

#include "course.h"
#include "grade.h"

class Student{
public:
	Student();
	~Student();

//private:
//	string  m_id;
//	string  m_name;
//	char	m_gender;
//	Course	m_course;
//	Grade	m_grade;
//	float	m_sumScore;
	//float	m_avgScore;
	char	m_id[10];
	char	m_name[20];
	char	m_gender;
	Course	m_course[20];
	Grade	m_grade;
	float	m_sumScore;

};
#endif