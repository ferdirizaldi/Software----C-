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

//ノードを削除する関数 deleteNode（ 連結リスト変数,先頭ポインター,削除するインデックス）
static struct List* deleteNode(struct List* list,struct List* root, int delete){
    // 連結リストのポインター変数
    struct List* ptr = list;
    //　削除のポインタのループ用変数
    struct List* deletePointer = list;
    //　最初値を削除する用変数
    struct List* firstNodeDelete;
    //削除するインデックスが１以外であるとき
    if(delete != 1){
        //削除したい値のポインターをゲットし、deletePointerに代入
        for(int i=1;i<=delete-1;i++){
            deletePointer = deletePointer->next;
            //printf("Delete %d ",i);
        }
        /*削除したいポインターの一個前の変数ポインタまでループし、
        そのポインターの "ptr->next" を"deletePointer->next"にする*/
        for(int i=1;i<=delete-1;i++){
            if (i==delete-1){
                ptr->next = deletePointer->next;
                // メモリ解放する
                free(deletePointer);
            }
            ptr=ptr->next;   
        }
    }
    //先頭・Root/Head・を削除する場合
    if(delete==1){
        //rootを一時的にfirstNodeDeleteに保存する
        firstNodeDelete = root;
        //rootをptr->nextに変更し、リスト最初の値を削除できた
        root = ptr->next;
        //firstNodeDeleteをメモリ解放する
        free(firstNodeDelete);
        //rootを戻り値とする
        return root;
    }
    return root;
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


    ptr = root;
    //root関数でリストの５番目を削除
    deleteNode(ptr,root,5);

    printf("\n ５を削除した後のリスト：\n");
    
    //出力
    ptr = root;
    nodePrint(ptr);

    ptr = root;
    //root関数でリストの１番目を削除
    root = deleteNode(ptr,root,1);

    printf("\n 1(root)を削除した後のリスト：\n");
    
    //出力
    ptr = root;
    nodePrint(ptr);
    return 0;
}