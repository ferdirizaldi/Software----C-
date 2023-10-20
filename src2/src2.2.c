#include<stdio.h>
#include<string.h>
/*233378 Ferdi Rizaldi Rangkuti*/
int main(){
    int MAX_BUFFER = 50;
    char stringInput[MAX_BUFFER];
    int commaCount=0; /*コンマの数*/

    printf("Input>");
    fgets(stringInput, MAX_BUFFER, stdin);
    printf("%s", stringInput);

    for(int i=0;i<sizeof(stringInput);i++){/*コンマを数えるためのループ*/
        if(stringInput[i]==','){
            commaCount++;
        }
    }

    printf("There are %d','s. in the input string",commaCount);
    return 0;
}   