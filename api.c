#include <stdio.h>
#include "core/structures.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//insert row //
//1//
//2
//3
//create table//

//delete row//

//generate id//
node *newnode(int id1,int dish1){
    node *newnode1;
    newnode1->id = id1;
    newnode1->dish = dish1;
    return newnode1;
}
int insert(int item, string tablenamedata, string tablenameid){
    int id = generate_id(tablenameid);
    FILE *fpt = fopen(tablenamedata, "a");
    fprintf(fpt, "%i,%i", id, item);
    fprintf(fpt, "\n");
    fclose(fpt);
}
int create_table(string tablename_data, string tablename_tables, string use_table_for){
    FILE *fptr = fopen(tablename_data, "r");
    if (fptr == NULL){
        FILE *ptr = fopen(tablename_data, "w");
        fclose(ptr);
        FILE *fpt = fopen(tablename_tables, "a");
        fprintf(fpt, "%s, %s",use_table_for, tablename_data);
        fclose(fpt);
    }
    else{
        printf("file aldready exists");
    }
    fclose(fptr);
    FILE *pt = fopen(tablename_tables, "r");
    if(pt == NULL){
        printf("it failed for some other reason");
    }
    return 0;
}

int generate_id(string tablename){
    FILE *ptr = fopen(tablename, "r");
    int no = 0;
    fscanf (ptr, "%d", &no);
    no++;
    fclose(ptr);
    FILE *fptr = fopen(tablename, "w");
    fprintf(fptr, "%d", no);
    fclose(fptr);
    return(no);
}

void delete_line(int id, string filepath_data, string filepath_new_file){
    
    FILE* file, *temp;
    file = fopen(filepath_data, "r");
    temp = fopen(filepath_new_file, "w");
    
    char buffer[100];
    int delete_line = find(id, filepath_data);
    // if(delete_line == -1){
    //     return 1;
    // }
    delete_line = delete_line + 2;
    bool keep_reading = true;
    int current_line = 1;
    do{
        fgets(buffer, 100, file);
        if(feof(file)){
            keep_reading = false;
            }
        else if(current_line != delete_line){
            fprintf(temp, "%s", buffer);
        }
        current_line++;
    }while(keep_reading);
    remove(filepath_data);
    rename(filepath_new_file, filepath_data);
    fclose(file);
    fclose(temp);
	FILE *fptr1, *fptr2;
	char filename[100], c;
	fptr1 = fopen(filepath_new_file, "r");
	fptr2 = fopen(filepath_data, "w");
	c = fgetc(fptr1);
	while (c != EOF)
	{
		fputc(c, fptr2);
		c = fgetc(fptr1);
	}
	fclose(fptr1);
	fclose(fptr2);
    remove(filepath_new_file);
}