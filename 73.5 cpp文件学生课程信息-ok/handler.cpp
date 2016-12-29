/*
修改文件部分内容，使用c++的seekg，seekp为什么失败了？？？怎么做的》
此时用c的*/
#include "handler.h"
#include "vector"
#include "algorithm"
#include "utility"
using namespace std;
int gCourseNum = -1;

Handler::Handler(string fileStu, string fileCourse) :m_fileStu(fileStu), m_fileCourse(fileCourse){
}

Handler::~Handler(){

};
//set course
void Handler::setCourse(){
	//fstream fs;
	//remove(m_fileCourse.c_str());
	//fs.open(m_fileCourse, ios::app | ios::in | ios::binary);
	FILE* fs = fopen(m_fileCourse.c_str(), "ab+");
	if (fs)
	{
		std::cout << "please input Course Name: ";
		char  name[20];
		std::cin >> name;
		Course course(name, ++gCourseNum);
		std::cout << "please input Course credit(int): ";
		std::cin >> course.m_credit;
		//fs.write((char*)&course, sizeof(course));
		fwrite((char*)&course, sizeof(course), 1, fs);
		//fs.close();
		fclose(fs);
	}
	else{
		std::cout << "open error~\n";
		return;
	}
}

void Handler::printCourse(){
	fstream fs;
	fs.open(m_fileCourse, ios::in | ios::binary);
	if (fs.is_open())
	{
		Course course;
		int n = 0;
		/*		while (!fs.eof()){
		fs.read((char*)&course, sizeof(course));
		std::cout << n++ << ":" << course.m_name << " " << course.m_number << course.m_score << endl;
		}*/
		while (fs.read((char*)&course, sizeof(course))){
			std::cout << n++ << ": " << course.m_name << " " << course.m_number << " " << course.m_score << " " << course.m_credit << endl;
			//if (fs.eof())
			//	break;
		}
		fs.close();
	}
	else{
		std::cout << "open error~\n";
		return;
	}
}

Course Handler::findCourse(char *name){
	fstream fs;
	Course course;
	fs.open(m_fileCourse, ios::in | ios::binary);
	if (fs.is_open())
	{
		while (fs.read((char*)&course, sizeof(course))){
			if (strcmp(course.m_name, name) == 0){
				fs.close();	return course;
			}
		}
	}
	else{ std::cout << "open file error~!\n"; }
	Course ncour;
	return ncour;
}

void Handler::addStuInfo(){
	Student stu;
	fstream fs;
	fs.open(m_fileStu, ios::app | ios::binary);
	std::cout << " Input student id: ";
	fflush(stdin);
	gets(stu.m_id);
	Student fstu = findStuInfo(stu.m_id);
	if (strcmp(fstu.m_id, "$$") != 0){
		std::cout << "  existed~!\n"; return;
	}
	std::cout << " Input student name: ";
	fflush(stdin);
	gets(stu.m_name);
	std::cout << " Input student gender(B/G): ";
	scanf("%c", &stu.m_gender);
	std::cout << " Input student age(unsined int) : ";
	std::cin >> stu.m_age;
	std::cout << " Input student choosed course: \n";
	int n = 0;
	char cname[20];
	while (1){
		std::cout << "	Input course " << n + 1 << " name (add course over, input:##):"; fflush(stdin); gets(cname);
		if (strcmp(cname, "##") == 0) break;
		Course course = findCourse(cname);
		if (strcmp(course.m_name, "$$") == 0){ std::cout << "	 no this course, reinput.\n"; continue; }
		strcpy(stu.m_course[n].m_name, cname);
		stu.m_course[n].m_number = course.m_number;
		stu.m_course[n].m_credit = course.m_credit;
		std::cout << "	Input course " << n + 1 << " score:"; fflush(stdin); std::cin >> stu.m_course[n].m_score;
		stu.m_sumScore += stu.m_course[n].m_score;
		if (++n > 19){ break; }
	}
	std::cout << " Input student Grade:";
	std::cin >> stu.m_grade.m_name;
	fs.write((char*)&stu, sizeof(stu));
	fs.close();
};
Student Handler::findStuInfo(char* id){
	fstream fs;
	Student fstu;
	fs.open(m_fileStu, ios::in | ios::binary);
	if (fs.is_open())
	{
		while (fs.read((char*)&fstu, sizeof(fstu))){
			if (strcmp(fstu.m_id, id) == 0){
				fs.close();	return fstu;
			}
		}
	}
	else{ std::cout << "open file error~!\n"; }
	Student nstu;
	return nstu;
}
/*
修改文件部分内容，使用c++的seekg，seekp为什么失败了？？？怎么做的》
此时用c的*/
void Handler::changeStuInfo(){
	char id[10];
	std::cout << " Input student id: ";
	fflush(stdin);
	gets(id);
	Student stu = findStuInfo(id);
	if (strcmp(stu.m_id, id) != 0){
		std::cout << "  not existed~!\n";
		return;
	}
	//fstream fs(m_fileStu, ios::out | ios::in | ios::binary);
	FILE* fp = fopen(const_cast<char*>(m_fileStu.c_str()), "rb+");
	if (fp)
	{
		while (fread((char*)&stu, sizeof(stu), 1, fp)){
			if (strcmp(stu.m_id, id) == 0){

				std::cout << " Input student new name: ";
				fflush(stdin);
				char name[20];
				gets(stu.m_name);
				//gets(name);
				//strcpy(stu.m_name, name);
				std::cout << " Input student new gender(B/G): ";
				scanf("%c", &stu.m_gender);
				std::cout << " Input student new age(unsined int) : ";
				std::cin >> stu.m_age;
				std::cout << " Input student choosed course: \n";
				int n = 0;
				char cname[20];
				while (1){
					std::cout << "	Input course " << n + 1 << " name (add course over, input:##):"; fflush(stdin); gets(cname);
					if (strcmp(cname, "##") == 0) break;
					Course course = findCourse(cname);
					if (strcmp(course.m_name, "$$") == 0){ std::cout << "	 no this course, reinput.\n"; continue; }
					strcpy(stu.m_course[n].m_name, cname);
					stu.m_course[n].m_number = course.m_number;
					stu.m_course[n].m_credit = course.m_credit;
					std::cout << "	Input course " << n + 1 << " score:"; fflush(stdin); std::cin >> stu.m_course[n].m_score;
					stu.m_sumScore += stu.m_course[n].m_score;
					if (++n > 19){ break; }
				}
				if (n < 20)
				{
					Course cour;
					stu.m_course[n++] = cour;
				}
				std::cout << " Input student Grade:";
				std::cin >> stu.m_grade.m_name;
				fseek(fp, -(int)sizeof(stu), SEEK_CUR);
				//fs.seekg(-sizeof(stu), ios::cur);
				fwrite(&stu, sizeof(stu), 1, fp);
				fclose(fp);
				//	fs.write((char*)&stu, sizeof(stu));

				//fs.close();	
				return;
			}
		}
	}
	else{ std::cout << "open file error~!\n"; }
	//fs.close();
	fclose(fp);
	return;
};
void Handler::delStuInfo(){
	char id[10];
	std::cout << " Input student id: ";
	fflush(stdin);
	gets(id);
	Student stu = findStuInfo(id);
	if (strcmp(stu.m_id, id) != 0){
		std::cout << "  not existed~!\n";
		return;
	}
	//fstream fs(m_fileStu, ios::out | ios::in | ios::binary);
	FILE* fp = fopen(const_cast<char*>(m_fileStu.c_str()), "rb+");
	if (fp)
	{
		while (fread((char*)&stu, sizeof(stu), 1, fp)){
			if (strcmp(stu.m_id, id) == 0){

				strcpy(stu.m_name, "$$");
				fseek(fp, -(int)sizeof(stu), SEEK_CUR);
				//fs.seekg(-sizeof(stu), ios::cur);
				fwrite(&stu, sizeof(stu), 1, fp);
				fclose(fp);
				//	fs.write((char*)&stu, sizeof(stu));

				//fs.close();	
				return;
			}
		}
	}
	else{ std::cout << "open file error~!\n"; }
	//fs.close();
	fclose(fp);
	return;
};
void Handler::printStuInfo(){
	fstream fs;
	Student fstu;
	fs.open(m_fileStu, ios::out | ios::in | ios::binary);
	if (fs.is_open())
	{
		int n = 0;
		while (fs.read((char*)&fstu, sizeof(fstu))){
			if (strcmp(fstu.m_name, "$$") == 0)continue;
			std::cout << " " << ++n << ": " << fstu.m_id << " name=" << fstu.m_name << " age=" << fstu.m_age << endl;
		}
		//std::cout << fstu.m_course[12].m_name << endl;
	}
	else{ std::cout << "open file error~!\n"; }
	return;
};

void Handler::getStuScoreGrade(){
	fstream fs;
	Student fstu;
	char id[10];
	cout << " Input stu id:";
	fflush(stdin);
	gets(id);
	fs.open(m_fileStu, ios::in | ios::binary);
	if (fs.is_open())
	{
		while (fs.read((char*)&fstu, sizeof(fstu))){
			if (strcmp(fstu.m_id, id) == 0 && strcmp(fstu.m_name, "$$") != 0){
				for (int i = 0; i < 20; ++i)
				{
					if (strcmp(fstu.m_course[i].m_name, "$$") != 0){
						cout << "	" << fstu.m_course[i].m_name << " score =" << fstu.m_course[i].m_score << "; credit=" << fstu.m_course[i].m_credit << endl;
					}
					else break;
				}
				fs.close();	return;
			}
		}
		cout << " There is no this student..\n";
	}
	else{ std::cout << "open file error~!\n"; }
	return;
};
void Handler::getCourseStuScore(){
	char cname[20];
	cout << " Input course name :";
	fflush(stdin);
	gets(cname);
	Course course = findCourse(cname);
	if (strcmp(course.m_name, "$$") == 0){
		cout << " there is no this course.\n";
		return;
	}
	fstream fs;
	Student fstu;
	fs.open(m_fileStu, ios::in | ios::binary);
	if (fs.is_open())
	{
		while (fs.read((char*)&fstu, sizeof(fstu))){
			if (strcmp(fstu.m_name, "$$") == 0) continue;
			for (int i = 0; i < 20; ++i)
			{
				if (strcmp(fstu.m_course[i].m_name, cname) == 0){
					std::cout << "	" << fstu.m_course[i].m_name << " score =" << fstu.m_course[i].m_score << endl;
				}
			}
		}
	}
	else{ std::cout << "open file error~!\n"; }
};

void Handler::flunkedStu(){
	char cname[20];
	cout << " Input course name :";
	fflush(stdin);
	gets(cname);
	Course course = findCourse(cname);
	if (strcmp(course.m_name, "$$") == 0){
		cout << " there is no this course.\n";
		return;
	}
	fstream fs;
	Student fstu;
	fs.open(m_fileStu, ios::in | ios::binary);
	if (fs.is_open())
	{
		cout << " FLUNKED STUDENTS: \n";
		while (fs.read((char*)&fstu, sizeof(fstu))){
			if (strcmp(fstu.m_name, "$$") == 0) continue;
			for (int i = 0; i < 20; ++i)
			{
				if (strcmp(fstu.m_course[i].m_name, cname) == 0 && fstu.m_course[i].m_score - 60 < 0.000001){
					std::cout << "	" << "ID=" << fstu.m_id << " | name= " << fstu.m_name << " | score =" << fstu.m_course[i].m_score << endl;
				}
			}
		}
	}
	else{ std::cout << "open file error~!\n"; }
};
void Handler::sortBySumScore(){

	fstream fs;
	Student fstu;
	fs.open(m_fileStu, ios::in | ios::binary);
	if (fs.is_open())
	{
		cout << "  SORTED :\n";
		std::vector<Student> vec;
		while (fs.read((char*)&fstu, sizeof(fstu))){
			if (strcmp(fstu.m_name, "$$") == 0) continue;
			vec.push_back(fstu);
		}
		std::sort(vec.begin(), vec.end(), [](Student st1, Student st2){return st1.m_sumScore > st2.m_sumScore; });
		for (int i = 0; i < vec.size(); ++i)
		{
			cout << "	id:" << vec[i].m_id << " name =" << vec[i].m_name << " score=" << vec[i].m_sumScore << endl;
		}
	}
	else{ std::cout << "open file error~!\n"; }
};
void Handler::sortCourse(){
	char cname[20];
	cout << " Input course name :";
	fflush(stdin);
	gets(cname);
	Course course = findCourse(cname);
	if (strcmp(course.m_name, "$$") == 0){
		cout << " there is no this course.\n";
		return;
	}
	fstream fs;
	Student fstu;
	fs.open(m_fileStu, ios::in | ios::binary);
	if (fs.is_open())
	{
		cout << "  SORTED :\n";
		std::vector<float> vec;
		while (fs.read((char*)&fstu, sizeof(fstu))){
			if (strcmp(fstu.m_name, "$$") == 0) continue;
			for (int i = 0; i < 20; ++i)
			{
				if (strcmp(fstu.m_course[i].m_name, cname) == 0){
					//std::cout << "	" << "ID=" << fstu.m_id << " | name= " << fstu.m_name << " | score =" << fstu.m_course[i].m_score << endl;
					vec.push_back(fstu.m_course[i].m_score);
				}
			}
		}
		std::sort(vec.begin(), vec.end());
		for (int i = 0; i < vec.size(); ++i)
		{
			cout << "	" << vec[i] << endl;
		}
	}
	else{ std::cout << "open file error~!\n"; }
};


void Handler::stuInfo(){
	while (1){
		std::cout << m_menuInfo;
		int n = 4;
		std::cin >> n;
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
		case 4:{
			printStuInfo();
		}
		default:return;
		}
	}
}
void Handler::search(){
	while (1){
		std::cout << m_menuSearch;
		int n = 4;
		std::cin >> n;
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
		std::cout << m_menuStatic;
		int n = 4;
		std::cin >> n;
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

void Handler::courseInfo(){
	while (1){
		int n = 3;
		std::cout << m_menuCourse;
		std::cin >> n;
		switch (n){
		case 1:{
			setCourse();
			break;
		}
		case 2:{
			printCourse();
			break;
		}
		default:return;
		}
	}
}