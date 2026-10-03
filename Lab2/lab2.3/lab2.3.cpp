#include "Header.h"
#include <iostream>
#include <string>

int main() {
	LinkedList list;
	std::string filename = "a.txt";

	// FIX_ME: Добавим для вывода кирилицы
	setlocale(LC_ALL, "Russian");
	

	list.read_from_file(filename);

	std::cout << "Упорядоченный список: ";
	list.print();

	return 0;
}
