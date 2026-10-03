#pragma once
#include <iostream>

// FIX_ME: Имена структур/классов должны быть в CamelCase;
// старый код: struct Uzel { ... };
struct Node {
	int value_;
	Node* next_ = nullptr;
};

// FIX_ME: Имя класса на русском и не в CamelCase
// старый код: class Ochered { ... };
class Queue {
private:
	Node* head_;
	Node* tail_;

public:
	Queue();
	~Queue();

	// FIX_ME: Методы должны быть в lower_case_with_underscores. Также уберём избыточность
	// старый код: void Inicializaciya() { ... };

	// FIX_ME: Метод добавления в lower_case_with_underscores, параметры тоже
	// старый код: void DobavitElement(int Chislo) { ... };
	void add_element(int value);

	// FIX_ME: Удаление в lower_case_with_underscores
	// старый код: void UdalitElement() { ... };
	void remove_element();

	// FIX_ME: Вывод в lower_case_with_underscores
	// старый код: void VivodElementov() { ... };
	void print_elements() const;

	// FIX_ME: Вывод указателей в lower_case_with_underscores
	// старый код: void VivodUkazatelei() { ... };
	void print_pointers() const;
};