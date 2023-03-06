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

void preProcessing(string& FileStudentsDB, int& amountOfStudents)
{
	ifstream config("config.txt");
	config >> FileStudentsDB;
	config >> amountOfStudents;
	config.close();
}

