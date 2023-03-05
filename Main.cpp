#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include "Header.h"
using namespace std;
//перегрузка оператора cout для объектов структур
ostream& operator<<(ostream& os, const StudentsDB& student)
{
	os << student.lastName << " " << student.name << " " << student.father << " " << student.groupNumber << " " << student.studNumber << endl;
	return os;
};

int main()
{
	setlocale(LC_ALL, "RUS");
	string path = "students_db.txt";
	ifstream File;
	ifstream& copy = File;


	//проверка открытия файла
	

	int amounOfAllStudents = countStudents(File, path);
	print(amounOfAllStudents);

	StudentsDB* allStudents = new StudentsDB[amounOfAllStudents];//создаём массив структур абсолютно всех студентов
	allStudents = recordData(amounOfAllStudents, allStudents, File, path);
	for (int i = 0; i < amounOfAllStudents; i++) {
		cout << allStudents[i] << endl;
	};
	return 0;
};
