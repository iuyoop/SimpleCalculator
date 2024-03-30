#include <stdio.h>
#include <locale.h> 

#define errorInput printf("      !!!ERROR!!!\n  !!!НЕККОРЕКТНЫЙ ВВОД!!!\n");
#define errorMaxDivisor printf("                 !!!ERROR!!!\n!!!НОД ПРИНИМАЕТ ТОЛЬКО ЦЕЛОЧИСЛЕННЫЕ ЗНАЧЕНИЯ!!!\n");
#define errorZeroDivision printf("      !!!ERROR!!!\n  !!!ДЕЛЕНИЕ НА НОЛЬ!!!\n");



float function1(float a, float b)   // '+' 
{
    return a + b;
}

float function2(float a, float b)   // '-'
{
    return a - b;
}

float function3(float a, float b)   // '*'
{
    return a * b;
}

float function4(float a, float b)   // '/'  
{
    return a / b;
}

float function5(float a, float b)   // '%'
{
    return (int)a % (int)b;
}

float function6(int a, int b)      // НОД (#)
{
    /*                               ~~~Алгоритм поиска НОД~~~
    --------------------------------------------------------------------------------------------------
    (1)Из двух данных чисел большее число делят на меньшее.
    (2)Затем, меньшее число делят на остаток, получившийся от деления большего числа на меньшее.
    (3)Далее, первый остаток делят на второй остаток, 
    который получился от деления меньшего числа на первый остаток.
    (4)Второй остаток делят на третий, который получился от деления первого остатка на второй и т. д.
    (5)Таким образом деление продолжается до тех пор, пока в остатке не получится нуль. 
    Последний делитель как раз и будет наибольшим общим делителем.
    --------------------------------------------------------------------------------------------------
    */
 
    if (a < b)
    {
        int aRb;
        aRb = a;
        a = b;
        b = aRb;
    }

    if (b == 0)
    {
        return a;
    }

    return function6(b, a % b);
}

int main()  // главная функция 
{
    setlocale(LC_ALL, "Rus");

    int sch = 0;
    float num1, num2; // переменные чисел 1 и 2
    char operation; // переменная операция 

    printf("Работа калькулятора:\n");
    printf("(1)Ввод первого числа -> (2)Ввод второго числа -> (3)Ввод операции -> (4)Результат\n");
    printf("\n");

    printf("(1)Введите первое число:\n");
    scanf_s("%f", &num1);

    printf("(2)Введите второе число:\n");
    scanf_s("%f", &num2);

    printf("(3)Введите операцию (+, -, *, / - деление, %% - остаток от деления, НОД(#) - Наибольший Общий Делитель ПО МОДУЛЮ):\n ");
    scanf_s(" %c", &operation);

    switch (operation) { // операция 
    case '+':
        printf("(4) Ответ = %.3f\n", function1(num1, num2));
        printf("\n");
        break;
    case '-':
        printf("(4) Ответ = %.3f\n", function2(num1, num2));
        printf("\n");
        break;
    case '*':
        printf("(4) Ответ = %.3f\n", function3(num1, num2));
        printf("\n");
        break;
    case '/':
        if (num2 != 0)
        {
            printf("(4) Ответ = %.3f\n", function4(num1, num2));
            printf("\n");
            break;
        }
        if (num2 == 0)
        {
            sch = 3;  // выявления ошибок
            break;
            
        }
    case '%':
        if (num2 != 0)
        {
            printf("(4)Ответ = %.3f\n", function5(num1, num2));
            printf("\n");
            break;
        }
        if (num2 == 0)
        {
            sch = 3; // выявления ошибок
            break;
            
        }
    case '#':
        
        if (num1 < 0) // |num1|
        {
            num1 = -1 * num1;
        }
        
        if (num2 < 0) // |num2|
        {
            num2 = -1 * num2;
        }

        

        if ((num1 == (int)num1) & (num2 == (int)num2) & (num1 != 0) & (num2 != 0)) {
            printf("(4)Ответ = НОД(%.0f и %.0f) = %0.f\n", num1, num2, function6(num1, num2));
            printf("\n");
            break;
        }
        
        if ((num1 != (int)num1) || (num2 != (int)num2) || (num1 == 0) || (num2 == 0)); // выявления ошибок
        {
            sch = 2;
            break;

        }
        
        
    default:  // выявления ошибок
        sch = 1;
        break;
        
    }
    switch (sch) {  // проверка наличия оши
        case 1:
            errorInput;
            printf("\n");
            printf("совет: проверьте правильность написания чисел и операций.\n");
            break;
        case 2:
            errorMaxDivisor;
            printf("\n");
            printf("Совет: Используйте числа принадлежашие целым значениеям\n");
            printf("\n");
            break;
        case 3:
            errorZeroDivision;
            printf("\n");
            printf("Совет: Не дели на ноль броу");
            printf("\n");
            break;
        default:
            break;
    }

    return 0;
}