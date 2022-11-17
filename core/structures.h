#include <stdio.h>

#ifndef STRUCTURES_H
#define STRUCTURES_H

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
string stringify_date(struct date date1);
string stringify_order(order order);
int parse_date(string date2, struct date date1);
int parse_order(string order2, struct order order1);
//-----------------------------------------//

typedef struct node{
    int id;
    int dish;
    struct node* left;
    struct node* right;
}node;


typedef struct ride{
    string to;
    string from;
    int distance;
    string user;
    date date;
}ride;

typedef struct general{
    order order;
    ride ride;
}general;
#endif