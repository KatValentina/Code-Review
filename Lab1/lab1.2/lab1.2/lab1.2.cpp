////Черепашка.На квадратной доске расставлены целые неотрицательные числа, каждое из которых 
////не превосходит 100. Черепашка, находящаяся в левом нижнем углу, мечтает по пасть в правый 
////верхний.При этом она может переползать только в клетку справа или сверху и хочет, чтобы 
////сумма всех чисел, оказавшихся у нее на пути, была бы минимальной.Определить эту сумму.Ввод и 
////вывод организовать при помощи текстовых файлов.Формат входных данных : в первой строке входного 
////файла записано число N - размер доски(1 < N < 80).Далее следует N строк, каждая из которых 
////содержит N целых чисел, представляющих доску.В выходной файл нужно вывести единственное число :
////минимальную сумму.

#include <iostream>
#include <fstream>
#include <vector>
#include <limits> 
#include <algorithm>

//FIX_ME: Директива using namespace std запрещена Google Style Guide.
//using namespace std;
//Использовать полные имена std::.

int main() {

    //FIX_ME: вывод кирилицы 
    setlocale(LC_ALL, "russian");

    //FIX_ME: не используется полное имя 
    /* ifstream file1("a.txt");
    ofstream file2("b.txt");
    */
    std::ifstream file1("a.txt");
    //FIX_ME: добавим проверки на открытие файла
    if (!file1.is_open()) {
        std::cerr << "Ошибка. Не удалось открыть входной файл a.txt.\n";
        return 1;
    }
    
    std::ofstream file2("b.txt");
    if (!file2.is_open()) {
        std::cerr << "Ошибка. Не удалось открыть выходной файл b.txt.\n";
        return 1;
    }

    //FIX_ME: Имена переменных должны быть написаны lower_case_with_underscores
    //FIX_ME: добавим проверку на считывание 
    //int N;
    int n;
    if (!(file1 >> n)) {
        std::cerr << "Ошибка. Не удалось считать размер доски N.\n";
        return 1;
    }


    //FIX_ME: добавим проверку на соответствие условию
    if (n <= 1 || n >= 80) {
        std::cerr << "Ошибка. N должно удовлетворять условию 1 < N < 80.\n";
        return 1;
    }

    //FIX_ME: не используется полное имя
    //vector<vector<int>> b(n, vector<int>(n));
    std::vector<std::vector<int>> b(n, std::vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

			//FIX_ME: добавим проверку на считывание
            if (!(file1 >> b[i][j])) {
                std::cerr << "Ошибка. Недостаточно данных для доски.\n";
                return 1;
            }

            //FIX_ME: не проверялось, что значения соответствуют условию
            if (b[i][j] < 0 || b[i][j] > 100) {
                std::cerr << "Ошибка. Числа на доске должны быть от 0 до 100.\n";
                return 1;
            }
        }
        
    }
    file1.close();

   

    //FIX_ME: не используется полное имя
    //vector<vector<int>> dp(n, vector<int>(n, numeric_limits<int>::max()));
    std::vector<std::vector<int>> dp(
        n, std::vector<int>(
            n, std::numeric_limits<int>::max()));;

	//FIX_ME: начало доски
    dp[n - 1][0] = b[n - 1][0];

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (i < n - 1) {

                //FIX_ME: не используется полное имя
                dp[i][j] = std::min(dp[i][j], dp[i + 1][j] + b[i][j]);
            }
            if (j > 0) {

                //FIX_ME: не используется полное имя
                dp[i][j] = std::min(dp[i][j], dp[i][j - 1] + b[i][j]);
            }
        }
    }

    // Результат в правом верхнем углу
    file2 << dp[0][n - 1];
    file2.close();
	//FIX_ME: добавим вывод, что программа записала результат в файл
	std::cout << "Минимальная сумма записана в файл b.txt.\n";
    return 0;
}