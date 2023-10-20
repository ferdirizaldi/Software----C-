//B233378 Ferdi Rizaldi Rangkuti
// 自由課題 Software1b
// Cashier Application with Excel Receipt
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//レシートのアイテムを生成する
ReceiptItem generate_receipt_item(MenuItem item, int Quantity){
    ReceiptItem new_ReceiptItem;
    new_ReceiptItem.item = item;
    new_ReceiptItem.Quantity = Quantity;
    return new_ReceiptItem;
}

//MenuItem型のメニューリストをセットする
void set_menu(MenuItem **menulist, int *menu_count){
    static MenuItem menu_list_static[] = {
        {"MN001","Chinese Fried Rice",970},
        {"MN002","Chinese Fried Noodle",870},
        {"MN003","Peking Duck",1270},
        {"MN004","Pork Dumplings",470},
        {"MN005","Egg Soup",380},
        {"MN006","Chili Sauce Shrimp",770},
        {"MN007","Tomato with Egg",650},
        {"MN008","Chinese Soup Noodle",880},
    };
    *menulist = menu_list_static;
    *menu_count = sizeof(menu_list_static)/sizeof(MenuItem);
}

//メニューリストを出力する
void print_menu_list(MenuItem *menu_list, int MenuCount){
    printf("-----------------------------\n");
    for(int i=0;i<MenuCount;i++){
        printf("%d.%s,%s,%d\n",i,menu_list[i].MenuId,menu_list[i].MenuName,menu_list[i].MenuPrice);
    }
    printf("-----------------------------\n");
}

//レシートを出力する
void print_receipt(ReceiptItem receiptFinal[],int receiptCnt, int total){
    printf("\nRECEIPT\n");
    printf("-----------------------------\n");
    for(int i=0; i<receiptCnt;i++){
        printf("%s ¥%d Qty:%d\n",receiptFinal[i].item.MenuName,receiptFinal[i].item.MenuPrice,receiptFinal[i].Quantity);
    }
    printf("-----------------------------\n");
    printf("%d 円\n", total);
    printf("-----------------------------\n\n");
}

//レシートをCSVファイルに出力する
void generate_receiptFile(ReceiptItem receiptFinal[], int receiptCnt, int total){
    FILE* fp;
    char* filename = "Receipt.csv";
    fp = fopen(filename, "w");
    fprintf(fp,"Menu ID,Name,Price,Qty\n");
    for(int i=0;i<receiptCnt;i++){
        fprintf(fp,"%s,",receiptFinal[i].item.MenuId);
        fprintf(fp,"%s,",receiptFinal[i].item.MenuName);
        fprintf(fp,"%d,",receiptFinal[i].item.MenuPrice);
        fprintf(fp,"%d,",receiptFinal[i].Quantity);
        fprintf(fp,"\n");
    }
    fprintf(fp,"Total = ,,¥%d",total);
    fclose(fp);//Fileを閉じる
}

//入力のバッファーを空にする
void flush_input_buffer(){
    int c;
    while ((c=getchar())!='\n')
    {
        printf("%c",c);
    }
}
