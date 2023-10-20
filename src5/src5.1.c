#include<stdio.h>
#include<stdlib.h>
// Ferdi Rizaldi Rangkuti B233378
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
    for(int i; ptr!=0;i++){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}
//挿入するため関数
struct List* insertNode(struct List* list, int addIndex, int val){
    struct List* ptr = list;
    struct List* insertSelect = list;
    struct List* root = list;
    if(addIndex!=1){//挿入したいインデックスが１（最初）でないとき
        for(int i=1; i<=addIndex-2;i++){
            insertSelect = insertSelect->next;//挿入したい位置の一個前のノードのポインターをゲット
        }
        for(int i=1;i<=addIndex-1;i++){
            if(i==addIndex-1){//挿入したい位置にたり着いた時
                struct List* insert;
                insert = new_node(val);//ノード生成
                insert->next = insertSelect->next;//新しく生成ひたノードのnextをinterSelect->nextにする
                ptr->next = insert;//一個後ろのノードをpointerにつなげる
            }else{//まだでない時
                ptr = ptr->next;//つぎのノードに行く
            }
        }
    }else if(addIndex==1){//挿入したいインデックスが１（最初）である時
        struct List* insert;
        insert = new_node(val);//ノード生成
        insert->next = ptr;//新しく生成ひたノードのnextを最初の項目のポインターにする
        root = insert;//insertがrootにする
        return root;//rootを戻り値とする
    }
    return root;//rootを戻り値とする
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
    //新しいデータを挿入する
    ptr = root;
    root = insertNode(ptr,1, 12);
    //出力
    printf("\n 12をrootにInsertした後のリスト：\n");
    ptr = root;
    nodePrint(ptr);
    //新しいデータを挿入する
    ptr = root;
    root = insertNode(ptr,5, 42);
    //出力
    printf("\n 42を5項目にInsertした後のリスト：\n");
    ptr = root;
    nodePrint(ptr);

    return 0;
}