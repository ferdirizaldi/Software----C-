#include<stdio.h>
/*show_argument 233378 Ferdi Rizaldi Rangkuti*/
int main(){
    char input[] = "This is a sample program\n";
    /*input[]の変数に、５単語がある文を代入*/
    int i; /*for loopのための変数*/
    printf("%s",input);
    for(i=0;input[i]!='\0';++i){ /*文字列の最初要素から最後まで*/
        printf("%c",input[i]); /*input[i]を一つずつ出力*/
        if (input[i]==' ') /*空白があるかどうか検知*/
        {
            printf("\n"); /*新しい行を出力する*/
        }
    }
}
