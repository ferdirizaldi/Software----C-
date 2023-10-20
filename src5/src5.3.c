#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    
    int a = atoi ("-4");
    int b;

    b = (a)>=0? (a):-(a);//3 項演算子の条件分岐

    printf("abs(%d) = %d\n", a,b);
    
    return 0;

}