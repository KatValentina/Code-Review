#pragma once

#include <iostream>

class DoubleList {
public:
    struct Node {
        int data;
        Node* next;
        Node* prev;

        explicit Node(int val) : data(val), next(nullptr), prev(nullptr) {}
    };

    DoubleList();
    ~DoubleList();

    void PushBack(int value);
    void PrintList() const;
    Node* RemoveSides();

private:
    Node* head_;

    // Вспомогательный метод для удаления конкретного узла
    Node* DeleteNode(Node* node);
};

