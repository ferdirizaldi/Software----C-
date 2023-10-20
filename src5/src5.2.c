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
//連結リストをバブルソートする関数
static void sort_list(struct List* list){
    //連結リストの全部をループする
    for(struct List* node_ptr1=list; node_ptr1->next!=NULL; node_ptr1 = node_ptr1->next){
        //連結リストの全部を２行目からループする
        for(struct List* node_ptr2=node_ptr1->next; node_ptr2!=NULL; node_ptr2=node_ptr2->next){
            //比較
            if(node_ptr2->data < node_ptr1->data){
                //一個前の値が大きければ、交換する
                int temp = node_ptr1->data;
                node_ptr1->data = node_ptr2->data;
                node_ptr2->data = temp;   
            }
        }
    }
}
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