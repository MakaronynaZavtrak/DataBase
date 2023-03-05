#include "Header.h"
#include <fstream>
#include <iostream>
using namespace std;

void print(int value) {
	cout << value << endl;
};
void print(string value) {
	cout << value << endl;
};
void checkAndOpenning(ifstream& file, string path) {
	file.open(path);
	if (file.is_open()) {
		cout << "Файл успешно открыт" << endl;
	}
	else {
		cout << "Произошла ошибка при открытии файла" << endl;
	};
};

int countStudents(ifstream& file, string path_of_file) {//функция-препроцессинг, которая считывает суммарное количество студентов
	int counter_of_students = 0;
	string str;
	file.open(path_of_file);
	while (!file.eof()) {
		str = "";
		getline(file, str);
		counter_of_students++;
	};
	file.close();
	return counter_of_students;
};

StudentsDB* recordData(int amount, StudentsDB *BaseArr, ifstream& file, string path_of_file) {//функция для записи студентов в массив
	string str;
	int j = 0;
	int i = 0;
	file.open(path_of_file);
	while (!file.eof()) {
		getline(file, str);
		string lastName;
		string name;
		string father;
		string groupNumber;
		string studNumber;
		int i = 0;
		while (str[i] != ' ') {
			lastName += str[i];
			i++;
		};
		i++;
		while (str[i] != ' ') {
			name += str[i];
			i++;
		};
		i++;
		while (str[i] != ' ') {
			father += str[i];
			i++;
		};
		i++;
		while (str[i] != ' ') {
			groupNumber += str[i];
			i++;
		};
		i++;
		int endCounter = 0;
		while (endCounter != 8) {
			studNumber += str[i];
			endCounter++;
			i++;
		};
		BaseArr[j].lastName = lastName;
		BaseArr[j].name = name;
		BaseArr[j].father = father;
		BaseArr[j].groupNumber = groupNumber;
		BaseArr[j].studNumber = studNumber;
		j++;
	};
	file.close();
	return BaseArr;
};
