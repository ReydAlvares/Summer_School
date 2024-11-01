#include <stdio.h>
#include <math.h>
#include <assert.h>

#define infinity -1

int check_vvod(double* input);
void input_coef(double* a, double* b, double* c);
int find_root(double a, double b, double c, double* x1, double* x2);
int solve_square(double a, double b, double c, double* x1, double* x2);


int main()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    input_coef(&a, &b, &c);
    solve_square(a, b, c, &x1, &x2);

    return 0;
}

int solve_square(double a, double b, double c, double* x1, double* x2)
{
    int check_root = 0;

    check_root = find_root(a, b, c, x1, x2);

    switch(check_root)
    {
        case 0:
            printf("Корней нет\n");
            break;

        case 1:
            printf("Один корень - %lg\n", *x1);
            break;

        case 2:
            printf("Два корня - %lg и %lg\n", *x1, *x2);
            break;

        case infinity:
            printf("Бесконечное количество корней\n");
            break;
        default:
            assert(0);
    }

    return 0;
}

/*void check_ss_work(double a, double b, double c, double x1_ozhid, double x2_ozhid)
 {
    double x1 = 0, x2 = 0;

    solve_square(a, b, c, &x1, &x2);

    if (x1 == x1_ozhid && x2 == x2_ozhid || x2 == x1_ozhid && x1 == x2_ozhid)
        {
            printf("�� ���������");
        }
    else
        {
            printf("���� ������������ %lg, %lg, %lg, ��������� ����� %lg, %lg ��� %lg, %lg, � ��������� ���������� ���: %lg, %lg", a, b, c, x1_ozhid, x2_ozhid, x2_ozhid, x1_ozhid, x1, x2);
        }
}*/

void input_coef(double* a, double* b, double* c)
{
    printf("Введите коэффициент a: ");
    check_vvod(a);


    printf("Введите коэффициент b: ");
    check_vvod(b);

    printf("Введите коэффициент c: ");
    check_vvod(c);
}

int find_root(double a, double b, double c, double* x1, double* x2)
{
    printf("Ваши коэффициенты: a - %lg, b - %lg, c - %lg\n", a, b, c);
    if (a == 0)
       {
        if (b == 0 || (b == 0 && c == 0))
            {
                return infinity;
            }
        else
            {
                *x1 = ((-c)/b);
                return 1;
            }
       }
    else
        {
            double d = b*b - 4*a*c;
            printf("Дискриминант : %lg\n", d);

            if (d < 0)
                {
                    return 0;

                }
            else if (d == 0)
                {
                    *x1 = (-b/(2*a));

                    return 1;
                }
            else
                {
                    double koren_d = sqrt(d);
                    *x1 = (-b + koren_d)/(2*a);
                    *x2 = (-b - koren_d)/(2*a);

                    return 2;
                }
        }
}

int check_vvod(double* input)
{
    int temp = ' ';
    while(scanf("%lg", input) != 1)
    {
        while((temp = getchar()) != EOF && temp != '\n'); 
        printf("Введите число: ");
    }

	return 0;
}
