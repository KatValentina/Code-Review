//Археолог нашел N артефактов.Известны веса(сi) и налоговое бремя(di) находок.
//Нужно выбрать такое подмножество находок, чтобы их суммарный вес превысил Z кг, а их общее 
//налоговое бремя оказалось минимальным.Известно, что решение единственно.Укажите
//порядковые номера вещей, которые нужно взять.Исходный данные находятся в текстовом файле, 
//в первой строке указаны N и Z, а во второй строке значения весов(в кг), в третьей - величина
//налога по каждой находке.Вывести так же суммарный вес и общую ценность результата.

#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <climits>

//FIX_ME: Директива using namespace std запрещена Google Style Guide.
//using namespace std;
// Используйте полные имена std::.

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //FIX_ME: Имена переменных должны быть написаны lower_case_with_underscores
    // int N, Z;
    int n, z;

    //FIX_ME: не используется полное имя 
    // ifstream input("input.txt");
    std::ifstream input("input.txt");
    if (!input.is_open()){
        //FIX_ME: не используется полное имя 
        // cerr << "Ошибка. Не удалось открыть файл.";
        std:: cerr << "Ошибка. Не удалось открыть файл.";
        return 1;
    }

    if (!(input >> n >> z)){ 
        //FIX_ME: не используется полное имя
        //cerr << "Ошибка. Неверное значение переменных N и Z.";
        std::cerr << "Ошибка. Неверное значение переменных N и Z.";
        return 1;
    }

    //FIX_ME: N должно быть > 0, Z >= 0. Проверка N<0 пропускает N=0.
    // if (N<0 || Z<0)
    if (n <= 0 || z < 0){
        //FIX_ME: не используется полное имя
        //cerr << "Ошибка. параметры N и Z должны быть больше 0.";
        std::cerr << "Ошибка. N должно быть больше 0, "
            << "Z не может быть отрицательным.\n";
        return 1;
    }

    //FIX_ME: не используется полное имя
    //vector<int> weights(n); 
    std::vector<int> weights(n); // хранение веса
    for (int i = 0; i < n; i++){
        input >> weights[i];
    }

    //FIX_ME: не используется полное имя
    //vector<int> tax(n);
    std::vector<int> tax(n); // хранение налогового бремени
    for (int i = 0; i < n; i++){
        input >> tax[i];
    }

    //FIX_ME: Не проверялось, что данные считаны полностью.
    // (добавлена проверка)
    if (input.fail()) {
        std::cerr << "Ошибка. Недостаточно данных в файле.\n";
        return 1;
    }

    //FIX_ME: для проверки добавим
    int total_weight = 0; 
    for (int weight : weights){ 
        total_weight += weight; 
    }
    
    if (total_weight < z){ 
        std::cerr << "Ошибка. Невозможно набрать необходимый вес.\n"; 
        return 1; 
    }

    //FIX_ME: Имена переменных должны быть написаны lower_case_with_underscores
    //const int INF = INT_MAX;
    const int kInf = INT_MAX;

    //FIX_ME: число z + 110 не объясняет размер массива.
    // FIX_ME: не используется полное имя
    //vector<int> dp(z + 110, kInf);
    std::vector<int> dp(total_weight + 1, kInf); // массив для динам.програм.
    dp[0] = 0;

    // FIX_ME: не используется полное имя
    /*vector<vector<bool>> used(
    z + 110, vector<bool>(n, false));
    */
    std::vector<std::vector<bool>> used(
        total_weight + 1, std::vector<bool>(n, false)); // хранение использованных артефактов

    for (int i = 0; i < n; i++) {

        //FIX_ME: число z + 109 не объясняется использование артефакта 
        //for (int j = z + 109; j >= weights[i]; j--)
        for (int j = total_weight; j >= weights[i]; j--) {

            if (dp[j - weights[i]] != kInf && 
                dp[j - weights[i]] + tax[i] < dp[j]) {

                dp[j] = dp[j - weights[i]] + tax[i];
                used[j] = used[j - weights[i]];
                used[j][i] = true;
            }

        }
    }

    int min_tax = kInf;
    int best_weight = 0;

    // FIX_ME: не используется полное имя
    //vector<bool> best_use(n, false);
    std::vector<bool> best_use(n, false);

    //FIX_ME: число z + 109 не объясняется использование артефакта
    //for (int j = z + 1; j <= z + 109; j++)
    for (int j = z + 1; j <= total_weight; j++) {
        if (dp[j] < min_tax) {
            min_tax = dp[j];
            best_weight = j;
            best_use = used[j];
        }
    }

    //FIX_ME: добавим доп проверку
    if (min_tax == kInf) {
        std::cerr << "Ошибка. Не удалось найти подходящее подмножество.\n";
        return 1;
    }

    // FIX_ME: не используется полное имя
    //cout << "Выбранные артефакты: ";
    std::cout << "Выбранные артефакты: ";
    for (int i = 0; i < n; i++)
    {
        if (best_use[i])
        {
            std::cout << i + 1 << " ";
        }
    }
    std::cout << '\n';

    std::cout << "Cуммарный вес артефактов: " << best_weight << '\n';
    std::cout << "Общая ценность: " << min_tax << '\n';

    return 0;
}