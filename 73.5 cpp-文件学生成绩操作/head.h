#ifndef		HEAD_H_
#define		HEAD_H_

#include <stdio.h>
#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//class course
class Course{
public:
	Course(char* name = "$$", int number = -1, float score = 0, int credit = 1) :m_number(number), m_score(score), m_credit(credit){
		strcpy(m_name, name);
	};
	~Course(){};
	int		m_number;
	char	m_name[20];
	float	m_score;
	float	m_credit;
};

//class grade
class Grade{
public:
	Grade(char *name = "$$", int n=0):m_numStu(n){
		strcpy(m_name, name);
	}
	~Grade(){};
	char	 m_name[20];
	int		 m_numStu;
};

//class sutdent
class Student{
public:
	Student(char *id = "$$", char* name = "$$", char gender = 'B', int age=20, float sumscore=0):\
		m_gender(gender), m_age(age), m_sumScore(sumscore){
		strcpy(m_id, id);
		strcpy(m_name, name);
	}
	~Student(){};
	char	m_id[10];
	char	m_name[20];
	char	m_gender;
	int		m_age;
	Course	m_course[20]; //course of the student
	Grade	m_grade;	// students grade...
	float	m_sumScore;

};



#endif
