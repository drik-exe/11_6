//6. Разработайте программу в консольном приложении для работы с вещественным двумерным массивом.
//Реализовать возможность ввода размерности массива и его элементов из текстового файла(+1.5)
//Вычислить количество отрицательных элементов массива и вывести его на экран. (+0.5)
//Найти в каждом столбце произведение положительных элементов и вывести найденные значения(+1) в текстовый файл в столбик(+1).
//Найти второй отрицательный элемент массива и вывести его на экран.Если нет двух отрицательных элементов, то выведите соответствующее сообщение(+1).
//Заменить в предпоследней строке все однозначные элементы нулевыми(+1).
//Вывести измененный массив на экран в виде матрицы(+1.5)
//Найти последний положительный элемент и отбросить его дробную часть(+0.5).Вычислить количество цифр в найденном значении(+1).Оформить алгоритм в виде функции(+1).
//Вывод информации должен сопровождаться соответствующими комментариями.Не использовать библиотеку cmath.



#include <iostream>
#include <fstream>
#include <string>

using namespace std;



int CountNeg(double(&arr)[10][100], int size1, int size2) {
    int neg = 0;

    for (int i = 0; i < size1; ++i) {
        for (size_t k = 0; k < size2; k++)
        {
            if (arr[i][k] < 0) {
                ++neg;
            }
        }
    }
    return neg;
}

double SecondNeg(double(&arr)[10][100], int size1, int size2){
    int now_neg = 0;
    double neg = 0;
    for (int i = 0; i < size1; ++i) {
        for (size_t k = 0; k < size2; k++)
        {
            if (arr[i][k] < 0) {
                neg = arr[i][k];
                now_neg++;
            }
            if(now_neg == 2){
                break;
            }
        }
        if(now_neg == 2){
            break;
        }
    }
    if(now_neg == 1 || now_neg == 0){
        neg = 0;
        return neg;
    } else{
        return neg;
    }

}

int LastPos(double(&arr)[10][100], int size1, int size2){

    double pos = 0;
    int count_num = 0;
    for (int i = 0; i < size1; ++i) {
        for (size_t k = 0; k < size2; k++)
        {
            if (arr[i][k] > 0) {
                pos = arr[i][k];
            }
        }
    }
    int pos_int = pos;
    while(pos_int > 0){
        count_num++;
        pos_int/=10;
    }
    return count_num;
}

void Change(double(&arr)[10][100], int size1, int size2){
    for (int i = 0; i < size2; ++i) {
        if(arr[size1 - 2][i] > 0 && arr[size1 - 2][i] < 9){
            arr[size1 - 2][i] = 0;
        }
    }
}

int main() {


    setlocale(0, "");


    fstream file("Array.txt", ios::in);

    double arr[10][100];
    int size1 = 0;
    int size2 = 0;

    if (!file.is_open()) {
        cout << "Ошибка открытия файла" << endl;
    }
    else {
        cout << "Файл открыт" << endl;
        while (!file.eof()) {

            file >> size1 >> size2;
            for (size_t i = 0; i < size1; i++)
            {
                for (size_t j = 0; j < size2; j++)
                {
                    file >> arr[i][j];
                }
            }

        }
    }

    file.close();

    cout << "количество отрицательных элементов массива: " << CountNeg(arr, size1, size2) << endl;

    fstream MultPosFile("MultPos.txt", ios::out);

    for (size_t i = 0; i < size2; i++)
    {
        double mult_pos = 1;
        for (size_t j = 0; j < size1; j++)
        {
            if (arr[j][i] > 0) {
                mult_pos *= arr[j][i];
            }
        }
        MultPosFile << mult_pos << endl;
    }
    MultPosFile.close();

    if(SecondNeg(arr, size1, size2) == 0){
        cout << "В массиве нет двух отрицательных" << endl;
    } else{
        cout << "Второй отрицательный = " << SecondNeg(arr, size1, size2) << endl;
    }
    cout << "Количество цифр в последнем положительном элементе = " << LastPos(arr, size1, size2) << endl;
    Change(arr, size1, size2);
    for (int i = 0; i < size1; ++i) {
        for (size_t k = 0; k < size2; k++)
        {
            if (k == 3) {
                cout << arr[i][k];
            }
            else {
                cout << arr[i][k] << ' ';
            }

        }
        cout << endl;
    }
}
