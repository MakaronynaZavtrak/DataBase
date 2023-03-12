#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

class StudentsDB
{
public:
	int amountOfStudents;

	StudentsDB(const int amount)
	{
		ifstream file("students.txt");

		students = new Student[amount];
		amountOfStudents = amount;
		record(file, students);

		file.close();
	}
	

	void editStudent(int id, bool lastName=0, bool name=0, bool father=0, bool groupNumber=0, bool studNumber=0)
	{
		if (lastName)
		{
			cout << "Enter Surname of pupil: ";
			cin >> students[id].lastName;
			cout << endl;
		}
		if (name)
		{
			cout << "Введите имя ученика: ";
			cin >> students[id].name;
			cout << endl;
		}
		if (father)
		{
			cout << "Введите отчество ученика: ";
			cin >> students[id].father;
			cout << endl;
		}
		if (groupNumber)
		{
			cout << "Введите номер группы ученика: ";
			cin >> students[id].groupNumber;
			cout << endl;
		}
		if (studNumber)
		{
			cout << "Введите номер студенческого ученика: ";
			cin >> students[id].studNumber;
			cout << endl;
		}
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
		for (int i = 0; i < amountOfStudents; i++)
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

	void dumpStudents()
	{
		ofstream out;
		out.open("students.txt");
		for (int i = 0; i < amountOfStudents; i++)
		{
			out << students[i].lastName << " ";
			out << students[i].name << " ";
			out << students[i].father<< " ";
			out << students[i].groupNumber << " ";
			out << students[i].studNumber << endl;
		}
		out.close();
	}

	void addStudent()
	{
		amountOfStudents++;
		Student* temp = new Student[amountOfStudents];
		memcpy(temp, students, (amountOfStudents - 1) * sizeof(students[0]));
		delete[] students;
		students = new Student[amountOfStudents];
		memcpy(students, temp, (amountOfStudents) * sizeof(temp[0]));
		//delete[] temp;
		editStudent(amountOfStudents - 1, 1, 1, 1, 1, 1);
	}//TODO

private:
};

int countStudents(ifstream& file, string path_of_file);
void checkAndOpenning(ifstream& file, string path);
void preProcessing(string& FileStudentsDB, int& amountOfStudents);