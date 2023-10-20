#include<stdio.h>
#include<stdlib.h>
#include"5.5struct.h"
#include"5.5function.h"

//main関数
int main(void){
    // リストのroot（head）を宣言
    struct List* root = NULL;
    //　連結リストをイテレーションする用変数
    struct List* ptr;
    //１０回ループで、１０ノードを生成する
    for(int i=10;i>=1;i--){
        //rootがNULLであるとき、Rootのノードを生成
        if(!root){
            root = new_node(i);
            ptr = root;
        }else{//rootがNULLでないとき
            ptr->next= new_node(i);
            ptr = ptr->next;
        }
    }
    //ptrを最初のポインタroot(head)に戻す
    ptr = root;
    //nodePrint関数で連結リストを出力する
    nodePrint(ptr);
    //連結リストをソートする
    ptr = root;
    sort_list(ptr);
    //出力
    printf("\n Sortした後のリスト：\n");
    ptr = root;
    nodePrint(ptr);
    
    return 0;
}