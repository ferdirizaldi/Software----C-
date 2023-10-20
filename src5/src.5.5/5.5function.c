#include<stdio.h>
#include<stdlib.h>
#include "5.5struct.h"

//新しいノードを生成する関数
struct List* new_node(int val){
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
void sort_list(struct List* list){
    for(struct List* node_ptr1=list; node_ptr1->next!=NULL; node_ptr1 = node_ptr1->next){
        for(struct List* node_ptr2=node_ptr1->next; node_ptr2!=NULL; node_ptr2=node_ptr2->next){
            if(node_ptr2->data < node_ptr1->data){
                int temp = node_ptr1->data;
                node_ptr1->data = node_ptr2->data;
                node_ptr2->data = temp;   
            }
        }
    }
}
