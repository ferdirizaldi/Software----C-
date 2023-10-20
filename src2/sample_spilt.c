#include <stdio.h>

//関数split(引数はstring型のinput, char型のseparator, 二次元配列のitems, int型のmax_items, int型のmax_wordLen)
int split(char input[], char separator, char items[][100], int max_items, int max_wordLen) {
    
    //変数の宣言と値の代入
    int n = 0, nItems = 0, pos = 0;
    
    //ループ(一文字ずつ調べる)
    while (input[n] != '\0') {

        //区切り文字でない場合、itemsに文字を追加
        if (input[n] != separator) {
            if(pos < max_wordLen) {
                items[nItems][pos] = input[n];
                pos++;
            }

        //区切り文字である場合、itemsに終端記号を追加し、次の配列要素に移行            
        } else {
            if(nItems < max_items) {
                items[nItems][pos] = '\0';
                nItems++;
                pos = 0;
            }
        }
        //printf("%d", nItems);

        n++; //inputの次の文字要素にする
    
    }

    //inputの終端である場合、最後の配列要素に終端記号を追加
    if (nItems < max_items) {
        items[nItems][pos] = '\0';
        nItems++;
    }
    return nItems; //nItemsを戻り値にする
}

//メインプログラム
int main() {
    //変数の宣言
    char input[100];
    int maxNumArr;
    int maxNumStr;
    char chrSeparator;
    char items[5][100];

    //最大分割数の値を入力
    printf("max number of items in array > ");
    scanf("%d", &maxNumArr);

    //分割後の文字列の最大長の値の入力
    printf("max length of a string of each item > ");
    scanf("%d", &maxNumStr);

    //inputの入力
    printf("input > ");
    scanf("%s", input);

    //separatorの入力
    printf("separator > ") ;
    scanf(" %c", &chrSeparator);

    //numItemsにsplitの戻り値を代入
    int numItems = split(input, chrSeparator, items, maxNumArr, maxNumStr);

    //分割結果の表示
    for(int i = 0; i < numItems; i++) {
        printf("items[%d] = %s\n", i, items[i]);
    }
    return 0;
}