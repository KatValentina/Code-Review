#pragma once

#include <string>

class Node {
public:
	int value;
	Node* next;

	explicit Node(int val);
};

class LinkedList {
private:
	Node* head_;

public:
	LinkedList();

	// FIX_ME: нужен деструктор для освобождения памяти
	~LinkedList();  

	//FIX_ME: Название метода должно быть написано lower_case_with_underscores
	// void insertSorted(int value)
	void insert_sorted(int value);

	//FIX_ME: Название метода должно быть написано lower_case_with_underscores
	void print();

	//FIX_ME: Название метода должно быть написано lower_case_with_underscores
	//void readFromFile(const std::string& filename)
	void read_from_file(const std::string& filename);

	// Не нужен friend: метод уже внутри класса и имеет доступ к приватным полям.
	// friend void readFromFile(LinkedList& list, const std::string& filename);
};

