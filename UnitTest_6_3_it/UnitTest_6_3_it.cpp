#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_3_it/Lab_06_3_it.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab063it
{
    TEST_CLASS(UnitTestLab063it)
    {
    public:

        // 1. Тестування звичайної функції для типу int
        TEST_METHOD(TestRegularSum_Int)
        {
            // Arrange
            int a[] = { 5, -2, 10, 4, -7 };
            int size = 5;
            int expected = 10; // 5 - 2 + 10 + 4 - 7 = 10

            // Act
            int actual = Sum(a, size);

            // Assert
            Assert::AreEqual(expected, actual);
        }

        // 2. Тестування шаблонної функції для типу double
        TEST_METHOD(TestTemplateSum_Double)
        {
            // Arrange
            double b[] = { 1.5, 2.5, -1.0, 4.0 };
            int size = 4;
            double expected = 7.0; // 1.5 + 2.5 - 1.0 + 4.0 = 7.0

            // Act
            double actual = Sum<double>(b, size);

            // Assert
            // Для порівняння дійсних чисел (double) вказуємо допустиму похибку (0.0001)
            Assert::AreEqual(expected, actual, 0.0001);
        }
    };
}