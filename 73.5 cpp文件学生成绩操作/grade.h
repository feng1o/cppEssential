#ifndef GRADE_H_
#define GRADE_H_

class Grade{
public:
	Grade(char name[20], int n=0):m_numStu(n){
		strcpy(m_name, name);
	}
	~Grade(){};

//private:
	//string  m_name;
	char	 m_name[20];
	int		 m_numStu;
};
#endif