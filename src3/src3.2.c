#include<stdio.h>
#include<string.h>

//Ferdi Rizaldi Rangkuti 
typedef struct member{
    char ID[9]; //char型配列：メンバID、最大有効文字長（８文字）
    char name[33]; //char型配列：メンバ名、最大有効文字長（３２文字）
    int score; //int型：score
} member;  

//新しいメンバの作成関数、引数として（ID, name, score)
struct member generateNewMember(char* ID, char* name, int score){
    //新しいインスタンス宣言
    struct member new_member;
    //それぞれの項目に代入
    strncpy(new_member.ID,ID,9);
    strncpy(new_member.name,name,33);
    new_member.score = score;
    //新しく作った変数を戻り値とする
    return new_member;
}

int main(){
    //変数宣言
    char ID[9];
    char name[33];
    int score;
    //入力
    printf("IDを入力：");
    fgets(ID,9,stdin);
    printf("nameを入力：");
    fgets(name,33,stdin);
    printf("scoreを入力：");
    scanf("%d",&score);
    //memberのインスタンスを作成する
    struct member newMember = generateNewMember(ID,name,score);
    //Structをアクセスし、出力
    printf("メンバ情報：");
    printf("ID:%s",newMember.ID);
    printf("ID:%s",newMember.name);
    printf("ID:%d",newMember.score);

    return 0;
}