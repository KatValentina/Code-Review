#include "Header.h"

// FIX_ME: Конструктор должен инициализировать поля
Queue::Queue() : head_(nullptr), tail_(nullptr) {}

Queue::~Queue() {
    // FIX_ME: Добавим деконструктор
    while (head_ != nullptr) {
        Node* temp = head_;
        head_ = head_->next_;
        delete temp;
    }
    tail_ = nullptr;
}

// FIX_ME: Инициализация через конструктор предпочтительнее; этот метод теперь избыточен, поэтому уберём
//void Initialize() {. . .}

void Queue::add_element(int value) {
    Node* new_node = new Node{ value, nullptr };

    if (head_ == nullptr) {
        head_ = new_node;
        tail_ = new_node;
    }
    else {
        tail_->next_ = new_node;
        tail_ = new_node;
    }
}

void Queue::remove_element() {
    if (head_ == nullptr) {
        std::cout << "Queue is empty!\n";
        return;
    }

    Node* temp = head_;
    head_ = head_->next_;
    delete temp;

    if (head_ == nullptr) {
        tail_ = nullptr;
    }
}

void Queue::print_elements() const {
    Node* current = head_;
    while (current != nullptr) {
        std::cout << current->value_ << " ";
        current = current->next_;
    }
    std::cout << "\n";
}

void Queue::print_pointers() const {
    std::cout << "Head address: " << head_;
    if (head_ != nullptr) {
        std::cout << " (value: " << head_->value_ << ")";
    }
    std::cout << "\n";

    std::cout << "Tail address: " << tail_;
    if (tail_ != nullptr) {
        std::cout << " (value: " << tail_->value_ << ")";
    }
    std::cout << "\n";
}
