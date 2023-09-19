#include <iostream>
#include <stdio.h>
#include <math.h>

int* InputData(int action) {
    switch (action) {
    case 1: {
        int* pABC = (int*) calloc(3, sizeof(int));
        printf("\nКвадратное уравнение имеет вид: ax+bx+c=0.\nВведите коэффициент a: ");
        scanf_s("%d", &pABC[0]);
        printf("Введите коэффициент b: ");
        scanf_s("%d", &pABC[1]);
        printf("Введите свободный член c: ");
        scanf_s("%d", &pABC[2]);
        return pABC;
    }
    case 2:
    {
        int* pCoefficients = (int*)calloc(6, sizeof(int));
        printf("\nУравнение системы двух линейных уравнений имеет вид: a1x+a2y=b.\nВвод значений для первого уравнения:\n");
        printf("Введите коэффициент а1: ");
        scanf_s("%d", &pCoefficients[0]);
        printf("Введите коэффициент а2: ");
        scanf_s("%d", &pCoefficients[1]);
        printf("Введите b: ");
        scanf_s("%d", &pCoefficients[2]);
        printf("\nВвод значений для второго уравнения:\nВведите коэффициент а1: ");
        scanf_s("%d", &pCoefficients[3]);
        printf("Введите коэффициент а2: ");
        scanf_s("%d", &pCoefficients[4]);
        printf("Введите b: ");
        scanf_s("%d", &pCoefficients[5]);
        return pCoefficients;
    }
    case 3:
    {
        int * pN = (int*)malloc(sizeof(int));
        printf("\nПерестановка имеет вид: P(n)=n!.\nВведите n: ");
        scanf_s("%d", pN);
        return pN;
    }
    }
}

double* RootOfQuadraticEquation(int* pABC) {
    printf("\n%dx^2+%dx+%d=0", pABC[0], pABC[1], pABC[2]);
    if ((pow(pABC[1], 2) - 4 * pABC[0] * pABC[2]) < 0) {
        double* pNone = (double*) calloc(3, sizeof(double));
        return pNone;
    }
    double* pRoots = (double*)calloc(3, sizeof(double));
    pRoots[0] = (-pABC[1] - sqrt(pow(pABC[1], 2) - 4 * pABC[0] * pABC[2])) / (2 * pABC[0]);
    pRoots[1] = (-pABC[1] + sqrt(pow(pABC[1], 2) - 4 * pABC[0] * pABC[2])) / (2 * pABC[0]);
    pRoots[2] = 1;
    return pRoots;
}

double* SystemOfLinearEquations(int* pCoefficients) {
    printf("\n%dx-%dy=%d\n%dx+%dy=%d", pCoefficients[0], pCoefficients[1], pCoefficients[2], pCoefficients[3], pCoefficients[4], pCoefficients[5]);
    if (pCoefficients[0] * pCoefficients[4] - pCoefficients[3] * pCoefficients[2] == 0) {
        double* pNone = (double*)calloc(3, sizeof(double));
        return pNone;
    }
    double* pXY = (double*)calloc(3, sizeof(double));
    pXY[0] = (pCoefficients[2] * pCoefficients[4] - pCoefficients[1] * pCoefficients[5]) / (pCoefficients[0] * pCoefficients[4] - pCoefficients[1] * pCoefficients[3]);
    pXY[1] = (pCoefficients[0] * pCoefficients[5] - pCoefficients[2] * pCoefficients[3]) / (pCoefficients[0] * pCoefficients[4] - pCoefficients[1] * pCoefficients[3]);
    pXY[2] = 1;
    return pXY;
}

double* Factorial(int* pN) {
    double* pFactorial = (double*)malloc(sizeof(double));
    *pFactorial = 1;
    for (int i = 2; i <= *pN; i++) {
        *pFactorial *= i;
    }
    return pFactorial;
}


void OutputData(double* pRezult, int action) {
    switch (action) {
    case 1:
    {
        if (pRezult[2] == 0) printf("\n\nНет корней.");
        else {
            if (pRezult[0] == pRezult[1]) printf("\n\nx = %.3f", pRezult[0]);
            else printf("\n\nx1 = %.3f\nx2 = %.3f", pRezult[0], pRezult[1]);
        }
    }
    break;
    case 2:
    {
        if (pRezult[2] == 0) printf("\nСистема несовместна/Имеет бесконечное количество решений.");
        else printf("\n\nx = %.3f\ny = %.3f", pRezult[0], pRezult[1]);
    }
    break;
    case 3:
    {
        printf("\n\nФакториал = %.f", pRezult[0]);
    }
    break;
    }
}
int main()
{
    setlocale(LC_ALL, "Rus");
    int action;
    while (true) {
        printf("\nВыберите задачу:\n1 - Найти корень квадратного уравнения;\n2. Решить систему двух линейных уравнений;\n3. Найти перестановку (факториал числа).\nЗначение: ");
        scanf_s("%d", &action);
        switch (action) {
        case 1:
            OutputData(RootOfQuadraticEquation(InputData(1)), 1);
            break;
        case 2:
            OutputData(SystemOfLinearEquations(InputData(2)), 2);
            break;
        case 3:
            OutputData(Factorial(InputData(3)), 3);
            break;
        default:
            printf("\nВы ввели некорректное значение.");
        }
        printf("\n\nХотите решить еще задачу? 1/0\nДействие: ");
        scanf_s("%d", &action);
        if (action != 1) break;
    }
    return 0;
}