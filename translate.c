#include <stdio.h>
#include "core/structures.h"
#include <string.h>
#include <stdlib.h>

char data_string[50];
char order_string[50];
string stringify_date(struct date date1){
    snprintf(data_string, 50, "%d/%d/%d", date1.day, date1.month, date1.year);
    return data_string;
}
string stringify_order(order order){
    snprintf(order_string, 50, "%c,%s,%s", order.time, order.dish, order.date);
    return order_string;
}
int parse_date(string date2, struct date date1){
    char ch[50];
    int i, j=0;
    for(i=0;i<10;i++){
        ch[j] = date2[i];
        j++;
        if(i == 1 || i == 3 || i == 7){
            if(i == 1){
                date1.day = atoi(ch);
            }
            if(i == 3){
                date1.month = atoi(ch);
            }
            if(i == 7){
                date1.year = atoi(ch);
            }
        }
        else if(i == 2 || i == 4 || i == 8){
            j = 0;
            memset(ch, 0, sizeof(ch));
        }
    }
    return 0;
}
int parse_order(string order2, order order1){
    char ch[50];
    date date;
    int i, j=0;
    for(i=0;i<10;i++){
        ch[j] = order2[i];
        j++;
        if(i == 0 || i == 5 || i == 15){
            if(i == 0){
                order1.time = ch;
            }
            if(i == 5){
                order1.dish = ch;
            }
            if(i == 15){
                parse_date(ch, date);
                order1.date = date;
            }
        }
        else if(i == 1 || i == 6 || i == 16){
            j = 0;
            memset(ch, 0, sizeof(ch));
        }
    }
    return 0;
}
    
