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
		if (file.is_open()) {
			cout << "Файл успешно открыт" << endl;
		}
		else {
			cout << "Произошла ошибка при открытии файла" << endl;
		};
		students = new Student[amount];
		amountOfStudents = amount;
		record(file, students);

		file.close();
	}
	

	void editStudent(int id, bool lastName=0, bool name=0, bool father=0, bool groupNumber=0, bool studNumber=0)
	{
		if (lastName)
		{
			cout << "Введите фамилию ученика : ";
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
			cout << "Введите номер студенческого билета ученика: ";
			cin >> students[id].studNumber;
			cout << endl;
		}
	}

	struct Student
	{
		int id;//айдишник
	string lastName;//фамилия
	string name;//имя
	string father;//отчество
	string groupNumber;//номер группы
	string studNumber;//номер студенческого билета
	};
	Student* students;

	//Done: сделать проверку на открытие в конструкторе
	//TODO: сделать деструктор с чисткой памяти



void deleteStudent(int index) {
	amountOfStudents--;
	UnusableId[counterInUnusId] = students[index].id;
	counterInUnusId++;
	Student* tmp = new Student[amountOfStudents];
	for (int i = 0, j = 0; i < amountOfStudents; i++, j++) {
		if (i != index) {
			tmp[i] = students[j];
		}
		else {
			i--;
		};
		for (int i = 0; i < amountofStudents + 1; i++) {
			delete students[i];
		};
		delete[] students;
		Student* students = new Student[amountofStudents];
		for (int i = 0; i < amountofStudents; i++) {
			students[i] = tmp[i];
		};
		for (int i = 0; i < amountofStudents; i++) {
			delete tmp[i];
		};
		delete[] tmp;
		//delete arr[index];
	};
};

	void print()
	{
		for (int i = 0; i < amountOfStudents; i++)
		{
			cout << students[i].id << " ";
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
			students[i].id = currentId;
			currentId++;
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
			out << students[i].id << " ";
			out << students[i].lastName << " ";
			out << students[i].name << " ";
			out << students[i].father << " ";
			out << students[i].groupNumber << " ";
			out << students[i].studNumber << endl;
		}
		out.close();
	};

	void addStudent()//добавляет поле
	{
		amountOfStudents++;
		int addId;
		if (UnusableId[0] > 1 && UnusableId[0] < 1000) {//псевдо-условие на хранение "мусора" в массиве UnusableId
			addId = UnusableId[0];
			shift();
		}
		else {
			addId = currentId;
			currentId++;
		};

		Student* temp = new Student[amountOfStudents];
		memcpy(temp, students, (amountOfStudents - 1) * sizeof(students[0]));
		delete[] students;
		students = new Student[amountOfStudents];
		memcpy(students, temp, (amountOfStudents) * sizeof(temp[0]));
		//delete[] temp;
		editStudent(amountOfStudents - 1, 1, 1, 1, 1, 1);
	}//TODO обрабатывать id 

private:
	//int* UsableId = new int[amountOfStudents];//массив, хранящие действительные id
	int* UnusableId = new int[amountOfStudents];//массив, хранящий id удалённых студентов
	int counterInUnusId = 0;//счетчик для массива неиспользуемых айдишников
	int currentId = 0;//отвечает за текущий идентификатор

	void shift() {//функция удаления первого элемента UnusableId
		int* newId = new int[amountOfStudents];
		for (int i = 1, j = 0; i < amountOfStudents; i++, j++) {
			newId[j] = UnusableId[i];
		};
		for int i = 0; i < amountOfStudents; i++){
		delete UnusableId[i];
		};
		delete[] UnusableId;
		int* UnusableId = new int[amountOfStudents];
		for (int i = 0; i < amountOfStudents; i++) {
			UnusableId[i] = newId[i];
		};
		for (int i = 0; i < amountOfStudents; i++) {
			delete newId[i];
		};
		delete[] newId;
	};

};

int countStudents(ifstream& file, string path_of_file);
void checkOfOpen(ifstream& file, string path);
void preProcessing(string& FileStudentsDB, int& amountOfStudents);