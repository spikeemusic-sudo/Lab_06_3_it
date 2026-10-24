// Lab_06_3_it.cpp
// Фащевський Богдан
// Лабораторна робота № 6.3
// Варіант 28
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів


#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

// Прототипи функцій
int Sum(int* a, const int size);

template <typename T>
T Sum(T* a, const int size);

template <typename T>
void Print(T* a, const int size);


int main()
{
    // Встановлення UTF-8 для правильного відображення кирилиці в консолі
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    const int n = 5;

    // 1. Демонстрація роботи з масивом цілих чисел (int)
    int a[n] = { 5, -2, 10, 4, -7 };
    cout << "Масив int:" << endl;
    Print(a, n);

    // Виклик звичайної функції
    int s1 = Sum(a, n);
    cout << "Sum(a, n) = " << s1 << endl;

    // Виклик шаблонної функції для int
    int s2 = Sum<int>(a, n);
    cout << "Sum<int>(a, n) = " << s2 << endl;


    // 2. Демонстрація роботи з масивом дійсних чисел (double)
    double b[n] = { 1.5, 2.2, -3.1, 4.8, 5.0 };
    cout << "\nМасив double:" << endl;
    Print(b, n);

    // Виклик шаблонної функції для double
    double s3 = Sum<double>(b, n);
    cout << "Sum<double>(b, n) = " << s3 << endl;

    return 0;
}

// ---------------------------------------------------------
// Звичайна ітераційна функція (тільки для int)
// ---------------------------------------------------------
int Sum(int* a, const int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
    {
        s += a[i];
    }
    return s;
}

// ---------------------------------------------------------
// Шаблонна ітераційна функція (універсальна для будь-яких чисел)
// ---------------------------------------------------------
template <typename T>
T Sum(T* a, const int size)
{
    T s = T(); // Присвоїли нульове значення для відповідного типу
    for (int i = 0; i < size; i++)
    {
        s += a[i];
    }
    return s;
}

// ---------------------------------------------------------
// Шаблонна функція для виведення масиву (форматне виведення)
// ---------------------------------------------------------
template <typename T>
void Print(T* a, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(7) << a[i];
    }
    cout << endl;
}