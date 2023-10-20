//B233378 Ferdi Rizaldi Rangkuti
// 自由課題 Software1b
// Cashier Application with Excel Receipt
#ifndef __STRING_OPERATION_struct__
#define __STRING_OPERATION_struct__

//構造体の定義

typedef struct MenuItem{
    char MenuId[10];
    char MenuName[20];
    int MenuPrice;
} MenuItem;

typedef struct ReceiptItem{
    MenuItem item;
    int Quantity;
} ReceiptItem;

#endif /*__STRING_OPERATION_H__*/