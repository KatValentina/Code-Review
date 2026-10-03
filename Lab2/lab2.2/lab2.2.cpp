#include "Header.h"
#include <iostream>

int main() {

    //FIX_ME: Директива using namespace std запрещена Google Style Guide.
    //using namespace std;
    //Использовать полные имена std::.

    // FIX_ME: Добавим для вывода кирилицы
    setlocale(LC_ALL, "Russian");

    Queue queue_odd;
    Queue queue_even;
    // FIX_ME: Убираем явный вызов Initialize(), так как конструктор уже делает это.
    // старый код: Ochered1.Inicializaciya(); Ochered2.Inicializaciya();

    std::cout << "Введите 10 чисел:\n";
    for (int i = 1; i <= 10; ++i) {
        int number;
        std::cout << "Число " << i << ": ";
        if (!(std::cin >> number)) {
            // FIX_ME: Обработка ошибки ввода без преждевременного возврата из main.
            std::cout << "Ошибка. Введите число!.\n";
            return 1;
        }

        if (i % 2 != 0) {
            queue_odd.add_element(number);
        }
        else {
            queue_even.add_element(number);
        }
    }

    //FIX_ME: не используется полное имя
    //FIX_ME: Название метода должно быть написано lower_case_with_underscores
    std::cout << "\nНечетная очередь:\n";
    queue_odd.print_elements();
    queue_odd.print_pointers();

    std::cout << "\nЧётная очередь:\n";
    queue_even.print_elements();
    queue_even.print_pointers();

    return 0;
}
