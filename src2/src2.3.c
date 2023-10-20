#include<stdio.h>
#include<string.h>
/*233378 Ferdi Rizaldi Rangkuti*/
int countCommaFunc(char stringInput[],int nelements){/*課題２の関数化*/
    int commaCount=0;
    for(int i=0;i<nelements;i++){
        if(stringInput[i]==','){
            commaCount++;
        }
    }
    return commaCount;
}
int main(){
    int MAX_BUFFER = 50;
    char stringInput[MAX_BUFFER];
    char comma = ',';

    printf("Input>");
    fgets(stringInput, MAX_BUFFER, stdin);
    printf("%s", stringInput);

    int commaCount = countCommaFunc(stringInput,MAX_BUFFER);/*関数使用*/
    printf("There are %d','s. in the input string",commaCount);
    return 0;
}   

