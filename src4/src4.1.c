#include<stdio.h>
#include<stdlib.h>
// Listの構造体の定義
struct List{
    int data;
    struct List* next;
};
//新しいノードを作る関数
static struct List* new_node(int val){
    struct List* instance = (struct List*)malloc(sizeof(struct List));
    instance->data=val;
    instance->next=NULL;
    return instance;
}
//連結リストの出力
void nodePrint(struct List* list){
    struct List* ptr = list;
    for(int i=1;i<=10;i++){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}
//main関数
int main(void){
    // リストのroot（head）を宣言
    struct List* root = NULL;
    //　連結リストをイテレーションする用変数
    struct List* ptr;

    //１０回ループで、１０ノードを生成する
    for(int i=1;i<=10;i++){
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

    return 0;
}