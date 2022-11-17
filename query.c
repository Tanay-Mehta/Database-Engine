#include <stdio.h>
#include "core/structures.h"
#include <stdlib.h>

//find row//

//find row BT

//read full file//
// string find_item_BT(string tablename_data){
    
// }
string find_row(string tablename, int no){
    int i;
    FILE* pFile;
    char data[100];
    pFile = fopen (tablename , "r");
    string row_data;
    row_data = fgets(data, 100, pFile);
    for(i=0;i<no;i++){
        row_data = fgets(data, 100, pFile);
    }
    row_data = fgets(data, 100, pFile);
    fclose(pFile);
    return row_data;
}
int find(int id, char*tablename){
    char str[1000];
    FILE* pFile;
    pFile = fopen (tablename , "r");
    int i;
    int c;
    int f;
    string row_data;
    string data = fgets(str, 100, pFile);
    for(i=0;i<3;i++){
        data = fgets(str, 2, pFile);
        c = atoi(str);
        if(c==id){
            return i;
        }
        data = fgets(str, 100, pFile);
    }
    fclose (pFile);
    printf("no id found");
    return -2;
}

int read_full_file(string tablename){
    FILE *fp = fopen(tablename,"r");
    if (fp == NULL)
      return 0;
    do
    {
        char c = fgetc(fp);
        if (feof(fp))
            break ;
        printf("%c", c);
    }  while(1);
    fclose(fp);
    return(0);
}