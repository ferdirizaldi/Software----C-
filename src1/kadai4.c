#include<stdio.h>
#include<string.h>
/*program3_modified 233378 Ferdi Rizaldi Rangkuti*/
int main(int agrc, char *agrv[]){
    int MAX_BUFFER = 10; /*fgetsで最大inputStreamのlength*/
    char buffer[MAX_BUFFER];/*MAX_BUFFERの長さでbuffer[]を宣言*/
    int c;
    while(1){
        printf("input > ");
        fgets(buffer, MAX_BUFFER, stdin);/*fgetsでMAX＿BUFFERの長さでinputstreamをbufferに代入*/
        /*printf("%zu",strlen(buffer));*/
        printf("string = %s\n", buffer);/*出力*/
        if(strlen(buffer)==(MAX_BUFFER-1)&&(buffer[MAX_BUFFER-2]!='\n')){
            /*bufferの中身が満杯になったとき AND 最後の要素が’¥n’でない時だけインプットストリームを空にする*/
            while ((c=getchar())!='\n'){}
        }
        if(buffer[0]=='q') break;/*qが入力されたら、loopから抜ける*/
    }
    return 0;
}