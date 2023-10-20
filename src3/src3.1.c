#include<stdio.h>
//Ferdi Rizaldi Rangkuti 
struct member{
    char ID[9]; //char型配列：メンバID、最大有効文字長（８文字）
    char name[33]; //char型配列：メンバ名、最大有効文字長（３２文字）
    int score; //int型：score
};

int main(){
    //ひとつのデータでメンバを定義する
    struct member one_member = {"ID10001","Ferdi Rangkuti",90}; 
    //リストに複数のメンバを定義する
    struct member member_list[] = {{"ID10001","Ferdi Rangkuti",90},{"ID10002","aaa",80}}; 

    //Structをアクセスし、出力
    printf("one_member出力:\n%s, %s, %d\n",one_member.ID,one_member.name,one_member.score);
    printf("member_list[]出力:\n");
    for(int i=0; i<2;i++){
        printf("%s, %s, %d\n",member_list[i].ID,member_list[i].name,member_list[i].score);
    }

    
}
