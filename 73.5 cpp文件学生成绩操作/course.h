#ifndef		COURSE_H_
#define		COURSE_H_

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//class course
class Course{
public:
	//Course(string name, string number, float score = 0);
	Course(int number, char* name, float score = 0) :m_number(number), m_score(score){
//		strcpy(m_number, number);
		strcpy(m_name, name);
	};
	~Course(){};

//	float	getScore();
//	void	setScore(float score);
//
//private:
//	string	m_number;
//	string  m_name;
//	float	m_score;
//private:
	int		m_number;
	char	m_name[20];
	float	m_score;
};



#endif
