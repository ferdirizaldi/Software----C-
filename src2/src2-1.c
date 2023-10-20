#include<stdio.h>
/*233378 Ferdi Rizaldi Rangkuti*/
int main(int agrc, char *agrv[]){
    char month[2][5] = {"April","May"}; /*一個のstringに対して、５個の大きさ*/
    int n;
    for(n=0;n<2;n++){
        printf("month[%d] = %s\n" ,n,month[n]);
    }
    return 0;
}
