//B233378 Ferdi Rizaldi Rangkuti
// 自由課題 Software1b
// Cashier Application with Excel Receipt

//headerファイルをインクルード
#include"function.h"
#include"struct.h"

int main(){
    //メニュー構造体定義
    MenuItem *menu_list;
    //メニュー数
    int MenuCount;
    //メニューを設定
    set_menu(&menu_list,&MenuCount);

    while(1){
        //最終的のレシートのReceiptItem型配列
        ReceiptItem *receiptFinal = (ReceiptItem *)malloc(100 * sizeof(ReceiptItem));
        //入力番号、数
        int inputId, quantity;
        //合計、レシートにあるアイテム数
        int total = 0,receiptCnt = 0;

        printf("List of Menu and Prices:\n");
        //メニューリストの出力
        print_menu_list(menu_list,MenuCount);
        
        printf("Choose a menu by number to add to the receipt\n(input -1 when finish adding)\n");
        //入力のループ
        while(1){
            //メニュー番号
            printf("Menu number: ");
            scanf("%d",&inputId);
                //入力番号が−１の時、入力が終わり、計算される
                if(inputId == -1){
                    printf("Adding Complete\n");
                    break;
                }
            //個数
            printf("Quantity: ");
            scanf("%d",&quantity);
            //合計の計算
            total = total + quantity * menu_list[inputId].MenuPrice;
            //アイテムずつでレシートアイテムを構造体で作成
            ReceiptItem receipt = generate_receipt_item(menu_list[inputId], quantity);
            //最終レシートの配列に追加する
            receiptFinal[receiptCnt] = receipt;
            //最終レシートのインデックスをインクレメント
            receiptCnt++;
        }
        
        //レシートの出力
        print_receipt(receiptFinal,receiptCnt,total);
        //レシートのCSVファイルを出力する
        generate_receiptFile(receiptFinal,receiptCnt,total);
        //レシートを削除する
        free(receiptFinal);

        //続くか、終了かを入力
        printf("Y to continue, enter other than Y to end:");
        char endFlag;
        flush_input_buffer();  
        scanf("%c", &endFlag);
        if(endFlag=='Y'||endFlag=='y'){
            continue;
        }else{
            break;
        }
        printf("\n");
    } 
}
