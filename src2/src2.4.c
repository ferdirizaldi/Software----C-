#include<stdio.h>
#include<string.h>
// B233378 Ferdi Rizaldi Rangkuti
int countCommaFunc(char stringInput[],int nelements){/*分割後の配列サイズのために*/
    int commaCount=0;
    for(int i=0;i<nelements;i++){
        if(stringInput[i]==','){
            commaCount++;
        }
    }
    return commaCount;
}

int split(char input[], char separator, char items[][100]){/*splitの関数*/
    int n=0, nItems=0, pos = 0;
    int skipFlag = 0;
    for(n=0;n<strlen(input);n++){ //inputの長さで一文字ずつ反復（ループ）する
        if(input[n]==','){//入力文字がコンマであったとき、次のitem[]インデックスに入る
            nItems++;
            pos = 0;//posをリセットする
            skipFlag = 0;
        }else if(input[n]!=','&&skipFlag==0){//文字が','かつskipFlagが０の時
            items[nItems][pos] = input[n];
            pos++;
            if(pos>4){//posが指定した文字数以上（＞４）になった場合、終端記号とskipFlagをつける
                items[nItems][pos] = '\0';
                skipFlag = 1;
                printf("skipped%d\n",n);
            }
            if(input[n+1]=='\0'){
                //posが更新された後、input[n+1]が'\0'である場合、nItemsの最後要素として、終端記号を入れる
                items[nItems][pos] = '\0';
                nItems++;
            }
        }else{}        
    }
    return nItems;
}

int main(){
    char inputString[100]; //入力
    scanf("%s", inputString);

    int commaCount = countCommaFunc(inputString, 21);//commaCount関数
    printf("test");
    char splittedString[commaCount][100];
    printf("%dcomma\n", commaCount);
    
    int loopNum = split(inputString, ',', splittedString);//Splitの関数を使う
    // printf("data2= %s",splittedString[3]);
    for(int i=0;i<=loopNum;i++){
        printf("Item[%d]=%s\n",i,splittedString[i]);
    }
    // printf("Item[last]= %s",splittedString[4]);
    return 0;
}