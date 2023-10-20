//B233378 Ferdi Rizaldi Rangkuti
// 自由課題 Software1b
// Cashier Application with Excel Receipt
#ifndef __STRING_OPERATION_function__
#define __STRING_OPERATION_function__

#include "struct.h"
#include "function.c"

//function.cにある関数のプロトタイプ

ReceiptItem generate_receipt_item(MenuItem item, int Quantity);
void set_menu(MenuItem **menulist, int *menu_count);
void print_menu_list(MenuItem *menu_list, int MenuCount);
void print_receipt(ReceiptItem receiptFinal[],int receiptCnt, int total);
void generate_receiptFile(ReceiptItem receiptFinal[], int receiptCnt, int total);
void flush_input_buffer();


#endif /*__STRING_OPERATION_H__*/