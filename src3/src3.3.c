#include<stdio.h>
#include<string.h>

//Ferdi Rizaldi Rangkuti 
typedef struct member{
    char ID[9]; //char型配列：メンバID、最大有効文字長（８文字）
    char name[33]; //char型配列：メンバ名、最大有効文字長（３２文字）
    int score; //int型：score
} member;  

int main(){
    //ファイル変数作成
    FILE* fileIN = fopen("students.csv","r");
    if(fileIN==NULL){
        printf("Error\n");
        return 1;
    }
    //member型配列,members[100]を宣言
    struct member members[100];
    //num_membersは列の反復用
    int num_members = 0;
    while(1){
        //ファイルを読み込む->student.csv 
        int n = fscanf(fileIN,"%[^,],", members[num_members].ID);
        fscanf(fileIN,"%[^,],", members[num_members].name);
        fscanf(fileIN,"%d\n", &members[num_members].score);
        //「メンバが１００である」または「fscanfがEOFに届いた」なら、終了
        if(num_members==100||n == EOF){
            printf("Finish\n");
            break;
        }
        num_members++;//次の行に移動する
    }
    //ファイルを閉じる
    fclose(fileIN);
    //members[]配列を出力
    printf("Member information:\n");
    for(int i=0;i<num_members;i++){
        printf("ID:%s\n", members[i].ID);
        printf("Name:%s\n", members[i].name);
        printf("Score:%d\n", members[i].score);
        printf("\n");
    }
    return 0;
}