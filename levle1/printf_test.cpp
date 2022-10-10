#include<iostream>
#include<cstdio> 

using namespace std;

int main ()
{
    //printf("Hello world;");
    
    printf("%d \n", 2);


    printf("%f \n", 1.2f);
    printf("%lf \n", 1.222);
    // 保留若干位小数
    printf("%.3f \n", 1.2321);
    printf("%.3lf \n", 1.23453);
    // 最小数字宽度


    printf("%c \n", 65);
    printf("%d \n", 'A');
    
    
    int a = 3;
    float b = 3.12345678;
    double c = 3.12345678;

    printf("%8d|\n", a);
    printf("%8.4f|\n", b);
    printf("%8.3lf|\n", c);

    printf("%-8d|\n", a);
    printf("%-8.4f|\n", b);
    printf("%-8.3lf|\n", c);

    printf("%08d|\n", a);
    printf("%08.4f|\n", b);
    printf("%08.3lf|\n", c);

    return 0;
}