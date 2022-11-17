#include <stdio.h>

#ifndef STRUCTURES_H
#define STRUCTURES_H
typedef struct node{
    int id;
    int dish;
    struct node* left;
    struct node* right;
}node;
node *newnode(int id1,int dish1);
typedef char* string;
string find_row(string tablename, int no);
int find(int id, char*tablename);
int read_full_file(string tablename);
int insert(int item, string tablenamedata, string tablenameid);
int create_table(string tablename_data, string tablename_tables, string use_table_for);
int generate_id(string filename);
void delete_line(int id, string filepath_data, string filepath_new_file);
typedef struct date{
    int day;
    int month;
    int year;
}date;
typedef struct order{
    string time;
    string dish;
    date date;
}order;
typedef struct ride{
    string to;
    string from;
    int distance;
    string user;
    date date;
}ride;
typedef struct keyval{
    int id;
    int dish;
}keyval;

typedef struct keyval list[10];
typedef struct general{
    order order;
    ride ride;
}general;
string stringify_date(struct date date1);
string stringify_order(order order);
int parse_date(string date2, struct date date1);
int parse_order(string order2, struct order order1);
int find_item_BT(string tablename_data, int id);
node* sortedArrayToBST(list order, int start, int end);

#endif