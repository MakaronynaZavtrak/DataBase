#include "header.h"
#include <string>
#include <fstream>
using namespace std;
/*
Должна быть расшифровка группы, как в обычном унике, а id группы может быть произвольным.
Под каждое поле в файле можно выделять некотороые число символов(9 значащих и один, который хранит количество исползованных). 
Все связи происходят через ID. тО етсь если удалить группу, то все студенты потеряют свзяь с ним. Тогда если удалить группу,
	то нужно изменить значения группы у всех таких студентов.
После удаления чего-либо, информация должна уходить в архив, где юудет хрнаиться 75 лет.
Поиск значнеи делается так: 1)поиск всех полей с таким значением, 2)удаление ненужных.
выгруженную таблицу можно хранить 
При добавлении нового пользователя, его id никогда не меняется. 
при удалении пользователя, можно ставить маркеры, при закрытии таблицы вся она будет обновляться
ID лучше рассмотреть отдельно, чтобы генерация была нормальной.
Количество студентов и айди последнего можно хранить в заголовке баз данных. В нем будут храниться 
	названия других баз данных и вспомогательные значения для них.?? - Файл конфигурации 
												ИЛИ
	Можно в начале каждой базы хрнаить вспомогательные значения.
Как хранить зачетку?



Группа Никиты: В классе Students. Номер группы это и есть ID группы. 
Группа Димы: Student структуры, класс Таблиц,

*/

//const int amountOfStudents;





int main()
{

	StudentsDB allStudents(3);
	allStudents.record();
	ofstream MEN("МЕН-120206");
	for (int i = 0; i < allStudents.amountOfStudents; i++) {
		if (allStudets.students[i].id == "МЕН-120206") {
				MEN << students[i].lastName
				MEN<< students[i].name
				MEN<< students[i].father
				MEN << students[i].groupNumber
				MEN << students[i].studNumber
		};
	};

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string studentFile;
	int amountOfStudents;
	preProcessing(studentFile, amountOfStudents);

	StudentsDB StudentDataBase = StudentsDB(amountOfStudents);
	StudentDataBase.print();
	StudentDataBase.addStudent();
	StudentDataBase.print();		
	StudentDataBase.dumpStudents();
	return 0;
};


/*TODO: функция для вывода всех данных, метод класса для отрытия файла, запись в конец файла новую запись,
	update(обновление поля структуры) 
*/