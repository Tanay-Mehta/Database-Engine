#include <stdio.h>
#include "structures.h"

int main(void){
    string filepath_data = "../data/data.csv";
    // string filepath_tables = "../data/tables.csv";
    // string filepath_id = "../data/id.txt";
    // string temp_file = "../data/temp.txt";
    //goal = find dish id 7

    int hello = find_item_BT(filepath_data, 9);
    printf("%i", hello);
}