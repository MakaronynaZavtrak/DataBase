//#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class StudentsDB
{
public:
	int amountOfPoles;

	StudentsDB(const int amount)
	{
		ifstream file("students.txt");

		students = new Student[amount];
		amountOfPoles = amount;
		record(file, students);

		file.close();
	}

	struct Student
	{
		string lastName;//фамилия
		string name;//имя
		string father;//отчество
		string groupNumber;//номер группы
		string studNumber;//номер студенческого билета
	};
	Student* students;
	
	//TODO: сделать проверку на открытие в конструкторе
	//TODO: сделать деструктор с чисткой памяти
	
	void print()
	{
		for (int i = 0; i < amountOfPoles; i++)
		{
			cout << students[i].lastName << " ";
			cout << students[i].name << " ";
			cout << students[i].father << " ";
			cout << students[i].groupNumber << " ";
			cout << students[i].studNumber << endl;
		};
	}
		

	void record(ifstream& file, Student* students)
	{
		int i(0);
		while (!file.eof())
		{
			file >> students[i].lastName;
			file >> students[i].name;
			file >> students[i].father;
			file >> students[i].groupNumber;
			file >> students[i].studNumber;
			i++;
		}
	};
private:
};


int countStudents(ifstream& file, string path_of_file);
void checkAndOpenning(ifstream& file, string path);
void preProcessing(string& FileStudentsDB, int& amountOfStudents);
