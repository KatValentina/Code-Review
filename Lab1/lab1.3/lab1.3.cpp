// К-ичные числа. Среди чисел в системе счисления с основанием K (2≤K≤10) определить сколько
// имеется чисел из N(1 < N < 20, N + K < 26) разрядов таких, что в их записи содержится два
// и более подряд идущих нулей.Для того, чтобы избежать переполнения, ответ представьте в виде
// вещественного числа.

#include <iostream>
#include <cmath>

//FIX_ME: Директива using namespace std запрещена Google Style Guide.
//using namespace std;
//Использовать полные имена std::.

//FIX_ME: Имена функций должны быть написаны lower_case_with_underscores
//double countNumbersWithConsecutiveZeros(int K, int N)
double count_numbers_with_consecutive_zeros(int k, int n)
{
	//FIX_ME: Имена переменных не несут информации о том, что они означают
    /*
     int nz = K - 1; // Числа, не начинающиеся с нуля (первая цифра от 1 до K-1)
    int oz = 0;     // Числа, заканчивающиеся на ноль (первая цифра от 1 до K-1, последняя - 0)
    int tz = 0;     // Числа с двумя подряд идущими нулями
    */
    double non_zero = k - 1;
    double one_zero = 0; 
    double two_or_more_zeros = 0;

    for (int i = 2; i <= n; i++)
    {

		//FIX_ME: Имена переменных должны быть написаны lower_case_with_underscores
        /*
        int _nz = non_zero;
        int _oz = one_zero;
        int _tz = two_or_more_zeros;
        */
        double previous_non_zero = non_zero; 
        double previous_one_zero = one_zero; 
        double previous_two_or_more_zeros = two_or_more_zeros;

		//FIX_ME: логика вычисления должна быть другая 
        //nz = (K - 1) * (_nz + _oz);
        non_zero = (k - 1) * previous_non_zero;

		//FIX_ME: Имена переменных должны быть написаны lower_case_with_underscores
        // oz = _nz;
        // oz: добавляем ноль к числам, которые не заканчиваются на ноль
        one_zero = previous_non_zero;

        //FIX_ME: Имена переменных должны быть написаны lower_case_with_underscores
        // tz = _tz * K + _oz;
        // tz: добавляем числа, которые заканчиваются на ноль и к которым добавляется ещё один ноль
        two_or_more_zeros = 
            previous_two_or_more_zeros * k + previous_one_zero;
    }

	//FIX_ME: Имена переменных должны быть написаны lower_case_with_underscores
    // return tz;
    // Возвращаем количество чисел с двумя подряд идущими нулями
    return two_or_more_zeros;
}

int main()
{
    setlocale(LC_ALL, "russian");
	//FIX_ME: Имена переменных должны быть написаны lower_case_with_underscores
    //int K, N;
    int k, n;

	//FIX_ME: не используется полное имя
    /*
    cout << "Введите основание системы счисления K: ";
    cin >> K;
    cout << "Введите количество разрядов N: ";
    cin >> N;
    */
    std::cout << "Введите основание системы счисления K: ";

    //FIX_ME: Не проверялось, что ввод K выполнен успешно.
    if (!(std::cin >> k)) { 
        std::cerr << "Ошибка. K должно быть целым числом.\n"; 
        return 1; 
    }

	//FIX_ME: не проверялось, что K удовлетворяет условию 2 ≤ K ≤ 10
    if (k < 2 || k > 10) {
        std::cerr << "Ошибка. K должно быть в диапазоне от 2 до 10.\n";
        return 1;
	}

    std::cout << "Введите количество разрядов N: ";

    // FIX_ME: Не проверялось, что ввод N выполнен успешно. 
    if (!(std::cin >> n)) { 
        std::cerr << "Ошибка. N должно быть целым числом.\n";
        return 1; 
    }

	//FIX_ME: не проверялось, что N удовлетворяет условию N + K < 26 и 1 < N < 20
    if (n + k >= 26 || n <= 1 || n >= 20) { 
        std::cerr << "Ошибка. N должно быть в диапазоне от 2 до 19 и N + K должно быть меньше 26.\n"; 
        return 1; 
    }


    double result = count_numbers_with_consecutive_zeros(k, n);
	//FIX_ME: не используется полное имя
    //cout << "Количество чисел с двумя подряд идущими нулями: " << result << endl;
    std::cout << "Количество чисел с двумя подряд идущими нулями: " << result << '\n';

    return 0;
}