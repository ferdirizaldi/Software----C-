#include<stdio.h>
#include<stdlib.h>
//B233378 Ferdi Rizaldi Rangkuti
#define MY_ABS(a) ((a)>=0? (a): -(a))//マクロとしての実装

int main(int argc, char *argv[]){
    double c = 10.0;
    double d = 25.0;
    printf("MY_ABSを使用:\n");
    printf("%f\n", MY_ABS(c+d));
    printf("%f\n", MY_ABS(c-d));
    return 0;
}