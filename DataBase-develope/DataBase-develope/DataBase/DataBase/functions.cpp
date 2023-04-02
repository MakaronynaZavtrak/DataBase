#include "header.h"

using namespace std;

void print(int value) {
	cout << value << endl;
};
void print(string value) {
	cout << value << endl;
};
void checkOfOpen(ifstream& file, string path) {
	file.open(path);
	if (file.is_open()) {
		cout << "Файл успешно открыт" << endl;
	}
	else {
		cout << "Произошла ошибка при открытии файла" << endl;
	};
	file.close();
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
	ifstream config("config.txt");//нужно добавить обработку айди из файла
	config >> FileStudentsDB;
	config >> amountOfStudents;
	config.close();
}

StudentsDB::Student* find(StudentsDB::Student* arr, int id, string lastName, string name, string father, string groupNumber, string studNumber) {//функция нахождения студентов (с частично одинаковыми персональными данными
	StudentsDB::Student* temp = new StudentsDB::Student[sizeof(arr) / sizeof(arr[0])];
	int j = 0;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		if (id != -1) {
			if (arr[i].id == id) {
				temp[j] = arr[i];
				break;
			};
		};

		if (lastName != "") {
			if (arr[i].lastName == lastName) {
				temp[j] = arr[i];
				j++;
			};
		};

		if (name != "") {
			if (arr[i].name == name) {
				temp[j] = arr[i];
				j++;
			};
		};

		if (father != "") {
			if (arr[i].father == father) {
				temp[j] = arr[i];
				j++;
			};
		};

		if (groupNumber != "") {
			if (arr[i].groupNumber == groupNumber) {
				temp[j] = arr[i];
				j++;
			};
		};

		if (studNumber != "") {
			if (arr[i].studNumber == studNumber) {
				temp[j] = arr[i];
				j++;
			};
		};
	};
	return temp;
};

/*string addIdIENIM(int groupnumber) {
	string id = "МЕН-" + tostring(groupnumber);
	allUsableId[globalSize] = id;
	globalSize++;
	return id;
};

string addIdUGI(int groupnumber) {
	string id = "УГИ-" + tostring(groupnumber);
	allUsableId[globalSize] = id;
	globalSize++;
	return id;
};

void deleteStudent(int index) {
	delete arr[index];
};*/