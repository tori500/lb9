#include <stdio.h>
#include <locale.h>
#include <string.h>

void task1(void);
void task2(void);
void task3(void);
void task4(void);

#define ROW 9
#define COL 9

int multiply(int row, int col)
{
    return row * col;
}

int main() {
    setlocale(LC_ALL, "RUS");

    task1();
    task2();
    task3();
    task4();

    return 0;
}

//задание 1
void task1(void) {
    setlocale(LC_ALL, "");

    int row, col;

    // Задание 1. Таблица Пифагора
    printf("Задание 1. Таблица умножения\n");

    for (row = 1; row <= ROW; row++)
    {
        for (col = 1; col <= COL; col++)
        {
            printf("%5d", multiply(row, col));
        }
        printf("\n");
    }

    // Задание 2. Левый нижний треугольник
    printf("Задание 2. Левый нижний треугольник\n");

    for (row = 1; row <= ROW; row++)
    {
        for (col = 1; col <= row; col++)
        {
            printf("%5d", multiply(row, col));
        }
        printf("\n");
    }

    // Задание 3. Индивидуальный вариант 8
    printf("Задание 3. Вариант 8\n");

    for (row = 1; row <= 5; row++)
    {
        for (col = 1; col <= row; col++)
        {
            printf("%5d", row * 10);
        }
        printf("\n");
    }
}

//задание 2
void task2(void) {
    setlocale(LC_ALL, "");

    int MAX;
    char number[MAX];
    char answer;

    do
    {
        int count3 = 0;
        int countLast = 0;
        int countEven = 0;
        int countMore5 = 0;

        int sumOdd = 0;
        int sumMore7 = 0;

        long double product = 1;
        long double productTwo = 0;

        int sumEvenExceptLast = 0;
        int equalPairs = 0;

        int sumFirst = 0;
        int sumSecond = 0;

        int sumEvenPositions = 0;
        int sumOddPositions = 0;

        printf("\nВведите длинное целое число: ");

        if (scanf("%999s", number) != 1)
        {
            printf("Ошибка ввода!\n");
            break;
        }

        int len = strlen(number);
        int valid = 1;

        // Проверка: введены только цифры
        for (int i = 0; i < len; i++)
        {
            if (number[i] < '0' || number[i] > '9')
            {
                valid = 0;
                break;
            }
        }

        if (!valid || len == 0)
        {
            printf("Ошибка! Нужно ввести целое положительное число.\n");
        }
        else
        {
            int lastDigit = number[len - 1] - '0';

            // Анализ цифр числа
            for (int i = 0; i < len; i++)
            {
                int digit = number[i] - '0';

                // 1. Количество цифр 3
                if (digit == 3)
                    count3++;

                // 2. Количество повторений последней цифры
                if (digit == lastDigit && i != len - 1)
                    countLast++;

                // 3. Количество четных цифр
                if (digit % 2 == 0)
                    countEven++;

                // 4. Количество цифр больше 5
                if (digit > 5)
                    countMore5++;

                // 5. Сумма нечетных цифр
                if (digit % 2 != 0)
                    sumOdd += digit;

                // 6. Сумма цифр больше или равных 7
                if (digit >= 7)
                    sumMore7 += digit;

                // 7. Произведение всех цифр, исключая 0
                if (digit != 0)
                    product *= digit;

                // 9. Сумма четных цифр, исключая последнюю
                if (i != len - 1 && digit % 2 == 0)
                    sumEvenExceptLast += digit;

                // 10. Рядом расположенные одинаковые цифры
                if (i > 0 && number[i] == number[i - 1])
                    equalPairs++;

                // 12. Суммы цифр четных и нечетных разрядов
                // Младший разряд считается первым
                int position = len - i;

                if (position % 2 == 0)
                    sumEvenPositions += digit;
                else
                    sumOddPositions += digit;
            }

            // 8. Произведение предпоследней и второй цифры
            if (len >= 3)
            {
                int secondDigit = number[1] - '0';
                int beforeLast = number[len - 2] - '0';

                productTwo = secondDigit * beforeLast;
            }

            // 11. Сумма первой и второй половины числа
            // Если количество цифр нечетное, средняя цифра не учитывается
            for (int i = 0; i < len / 2; i++)
            {
                sumFirst += number[i] - '0';
                sumSecond += number[len / 2 + (len % 2) + i] - '0';
            }

            printf("\nРезультаты вычислений:\n");

            printf("1. Количество цифр 3: %d\n", count3);

            printf("2. Повторений последней цифры (%d): %d\n",
                   lastDigit, countLast);

            printf("3. Количество четных цифр: %d\n", countEven);

            printf("4. Количество цифр больше 5: %d\n", countMore5);

            printf("5. Сумма нечетных цифр: %d\n", sumOdd);

            printf("6. Сумма цифр больше или равных 7: %d\n",
                   sumMore7);

            printf("7. Произведение цифр без нулей: %.0Lf\n",
                   product);

            if (len >= 3)
                printf("8. Произведение второй и предпоследней цифр: %.0Lf\n",
                       productTwo);
            else
                printf("8. Недостаточно цифр для вычисления.\n");

            printf("9. Сумма четных цифр без последней: %d\n",
                   sumEvenExceptLast);

            printf("10. Количество соседних одинаковых пар: %d\n",
                   equalPairs);

            if (equalPairs > 0)
            {
                printf("    Найденные пары: ");

                for (int i = 1; i < len; i++)
                {
                    if (number[i] == number[i - 1])
                        printf("%c%c ", number[i - 1], number[i]);
                }

                printf("\n");
            }

            printf("11. Сумма первой половины: %d\n", sumFirst);
            printf("    Сумма второй половины: %d\n", sumSecond);

            if (sumFirst == sumSecond)
                printf("    Суммы равны.\n");
            else
                printf("    Суммы не равны.\n");

            printf("12. Произведение сумм четных и нечетных разрядов: %d\n",
                   sumEvenPositions * sumOddPositions);
        }

        printf("Продолжить? (Да - 1, нет - 0):\n");
        scanf(" %c", &answer);

    } while (answer != '0');

    printf("Программа завершена.\n");
}

//задание 3
void task3(void) {
    char symbol;
    int size;

    printf("Введите символ для контура ромба: ");
    scanf(" %c", &symbol);

    printf("Введите размер (половину высоты): ");
    if (scanf("%d", &size) != 1 || size < 2) {
        size = 3;
        printf("Некорректный ввод, используется размер %d\n", size);
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            putchar(' ');
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            if (j == 0 || j == 2 * i) {
                putchar(symbol);
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }

    for (int i = size - 2; i >= 0; i--) {
        for (int j = 0; j < size - i - 1; j++) {
            putchar(' ');
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            if (j == 0 || j == 2 * i) {
                putchar(symbol);
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

//дз, задача А, вариант 26
void task4(void) {
    char symbol;
    int height, width;
    int answer;

    do {
        printf("Введите символ из которого будет строиться фигура:\n");
        scanf(" %c", &symbol);

        printf("Введите высоту:\n");
        scanf("%d", &height);

        printf("Введите ширину:\n");
        scanf("%d", &width);

        if (height < 2 || width < 3) {
            printf("Ошибка! Высота должна быть не меньше 2, "
                   "ширина — не меньше 3.\n");
        }
        else {
            printf("\nФигура варианта 26:\n\n");

            int innerWidth = width / 3;
            int leftWidth = (width - innerWidth) / 2;
            int rightWidth = width - innerWidth - leftWidth;

            // Область 1: верхняя часть и боковые стороны
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if (i == 0 || j < leftWidth ||
                        j >= leftWidth + innerWidth) {
                        printf("%c", symbol);
                        }
                    else {
                        printf(" ");
                    }
                }
                printf("\n");
            }

            // Область 3: нижний прямоугольник по центру
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if (j >= leftWidth &&
                        j < leftWidth + innerWidth) {
                        printf("%c", symbol);
                        }
                    else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }

        printf("Продолжить? (Да — введите любое число, Нет — введите 0):\n");
        scanf("%d", &answer);

    } while (answer != 0);

    printf("Программа завершена.\n");
}