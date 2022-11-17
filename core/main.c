#include <stdio.h>
#include "structures.h"
//--------tested working----------//
//1. create table//
//2. insert//
//3. find//
//4. find row//
//5. read full file//
//6. generate id//
int main(void){
    string filepath_data = "../data/data.csv";
    string filepath_tables = "../data/tables.csv";
    string filepath_id = "../data/id.txt";
    string temp_file = "../data/temp.txt";

    order order1;
    parse_order("M,0001,12/02/2020", order1);
    // printf("%i", date1.day);
    
    // date1.day = 30;
    // date1.month = 2;
    // date1.year = 2020;
    // string data = stringify_date(date1);
    // printf("%s", data);
    // create_table(filepath_data, filepath_tables, "data");
    // insert("pan1",filepath_data, filepath_id);
    // insert("pan2",filepath_data, filepath_id);
    // insert("pan3",filepath_data, filepath_id);
    
    // delete_line(1, filepath_data, temp_file);
}