#include<stdio.h>
/*input_key 233378 Ferdi Rizaldi Rangkuti*/
int main(){
    int loop=1; /*無限ループで使用変数*/
    do{
        char inputChar; /*input変数宣言*/
        printf("input>");
        scanf("%c%*c", &inputChar); /*scanfでinputをゲット、"%*c"一個のcharをゲットし、* ⇨ どこにも記憶しない（）*/
        switch (inputChar) /*switchでStatements Control*/
        {
        case 'o':
            printf("Open File\n");
            break;
        case 's':
            printf("Save File\n");
            break;
        case 'p':
            printf("Print Data\n");
            break;
        case 'a':
            printf("Add data\n");
            break;
        case 'q':
            printf("Quit Program\n");
            loop = 0; /*inputがqである場合、loopが0になり、無限ループから抜ける*/
            break;
        default :
            printf("Invalid\n");
            break;
        }
    }while(loop==1);/*loopが1である限り、無限にループする*/
    return 0;
}