#pragma once

class TNode {
public:
	int data;
	TNode* next;

    TNode(int value);
};

class Stack {
private:
    TNode* top;

public:

    Stack();

    // FIX_ME: Для освобождения динамической памяти добавлен деструктор.
    ~Stack();

    // Добавление элемента в стек.
    void push(int value);

    // Удаление элемента из стека.
    void pop();

    // Вывод элементов стека.
    void print();

    // Получение адреса вершины стека.
	//FIX_ME: Название метода должно быть написано lower_case_with_underscores
    // Node* getTop()
    TNode* get_top();

	// Очистка стека.
    //FIX_ME: Название метода должно быть написано lower_case_with_underscores
    //void clearStack();
    void clear_stack();

    // FIX_ME: Имя дружественной функции приведено к lower_case_with_underscores.
    //friend void addElementAndPrintAddress(Stack& stack, int D);
    friend void add_element_and_print_address(Stack& stack, int d);
};