#include "Header.h"
#include <iostream>

// Конструктор узла.
TNode::TNode(int value)
    : data(value), next(nullptr) {
}

// Конструктор стека.
Stack::Stack()
    : top(nullptr) {
}

// Деструктор стека.
Stack::~Stack() {
    clear_stack();
}

// Добавление элемента в стек
void Stack::push(int value) {
    // FIX_ME: Использовалось имя Node, которое не соответствует
    // типу узла из условия.
    // Node* newNode = new Node(value);
    TNode* new_node = new TNode(value); // Создаем новый узел
    new_node->next = top;             // Новый узел указывает на текущую вершину
    top = new_node;                   // Обновляем вершину стека

	// FIX_ME: не используется полное имя
    //  cout << "Элемент " << value << " добавлен в стек." << endl;
    std::cout << "Элемент " << value << " добавлен в стек." << '\n';
}

// Метод для удаления элемента из стека
void Stack::pop() {
    if (top == nullptr) {
        std::cout << "Стек пуст! Невозможно удалить элемент." << '\n';
        return;
    }
    TNode* temp = top;
    top = top->next;

    // FIX_ME: не используется полное имя
    //  cout << "Элемент " << temp->data << " удален из стека." << endl;
    std::cout << "Элемент " << temp->data << " удален из стека." << '\n';
    delete temp;
}

// Вывод элементов стека
void Stack::print() {
    if (top == nullptr) {
        std::cout << "Стек пуст!" << '\n';
        return;
    }
    TNode* current = top;
    std::cout << "Элементы стека: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << '\n';
}

// Получение адреса вершины стека.
// FIX_ME: Название метода должно быть написано lower_case_with_underscores
// Node* getTop()
TNode* Stack::get_top() {
    return top;
}

// Очистка стека.
// FIX_ME: Название метода должно быть написано lower_case_with_underscores
// void clearStack();
void Stack::clear_stack() {
    while (top != nullptr) {
        TNode* temp = top;
        top = top->next;
        delete temp;                 // Удаляем узел
    }
    std::cout << "Стек очищен." << '\n';
}

// Дружественный интерфейс.
void add_element_and_print_address(
    Stack& stack, int d) {
    stack.push(d);

    std::cout << "Адрес новой вершины стека: "
        << stack.get_top() << '\n';
}