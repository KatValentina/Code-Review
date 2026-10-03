//FIX_ME: Во всех случаях, где использовалась глобальная переменная std добавим полное имя

#include "Header.h"
#include <fstream>
#include <iostream>

// FIX_ME: конструктор Node должен быть в cpp, чтобы не усложнять заголовок
Node::Node(int val) : value(val), next(nullptr) {}

LinkedList::LinkedList() : head_(nullptr) {}

// FIX_ME: Добавим деконструктор
LinkedList::~LinkedList() {
    Node* current = head_;
    while (current != nullptr) {
        Node* next_node = current->next;
        delete current;
        current = next_node;
    }
}

// FIX_ME: Имена методов в lower_case_with_underscores
//  void insertSorted(int value) {. . .
void LinkedList::insert_sorted(int value) {
    Node* new_node = new Node(value);

    if (head_ == nullptr || head_->value < value) {
        new_node->next = head_;
        head_ = new_node;
        return;
    }

    Node* current = head_;
    //FIX_ME: Исменим логику
    while (current->next != nullptr && current->next->value > value) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
}

void LinkedList::print() {
    Node* current = head_;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << "\n";
}

//FIX_ME: Исменим логику. Соеденим метод readFromFile и Дружественную функцию friend void readFromFile
void LinkedList::read_from_file(const std::string& filename) {
    std::ifstream file(filename);
    // FIX_ME: не используем using namespace std; везде пишем std::
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла!" << "\n";
        return;
    }

    //FIX_ME: имя переменной должно быть написано lower_case_with_underscores
    //int N;
    int n;

    //FIX_ME: добавим проверку на считывание 
    if (!(file >> n)) {
        std::cerr << "Ошибка. Не удалось считать размер доски N.\n";
        return;
    }

    int value;
    for (int i = 0; i < n; ++i) {
        //FIX_ME: добавим проверку на считывание
        if (!(file >> value)) {
            std::cerr << "Ошибка. Недостаточно данных для доски.\n";
            return;
        }
        insert_sorted(value);
    }

    // FIX_ME: file.close() не обязателен: деструктор ifstream закроет файл сам
}
