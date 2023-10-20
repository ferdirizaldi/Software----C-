#include<stdio.h>
/*program3 233378 Ferdi Rizaldi Rangkuti*/
int main(int agrc, char *agrv[]){
    int MAX_BUFFER = 10; /*fgetsで最大inputStreamのlength*/
    char buffer[MAX_BUFFER];/*MAX_BUFFERの長さでbuffer[]を宣言*/
    while(1){
        printf("input > ");
        fgets(buffer, MAX_BUFFER, stdin);/*fgetsでMAX＿BUFFERの長さでinputstreamをbufferに代入*/
        printf("string = %s\n", buffer);/*出力*/
        if(buffer[0]=='q') break;/*qが入力されたら、loopから抜ける*/
    }
    return 0;
}