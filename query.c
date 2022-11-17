#include <stdio.h>
#include "core/structures.h"
#include <stdlib.h>
int mid;
node* sortedArrayToBST(list order, int start, int end)
{
    
    if(start>end){
        return NULL;
    }
    if((start + end-1)%2 == 0){
    mid = ((start + end-1)/2);
    }
    else{
        mid = ((start+end)/2);
    }
    node *head;
    head->id = order[mid-1].id;
    // printf(order);
    head->dish = order[mid-1].dish;
    head->left =  sortedArrayToBST(order, start, mid-1);
    head->right = sortedArrayToBST(order, mid+1, end);
    // printf("%i, %i", order[mid-1].id, order[mid-1].dish);
    return head;
}
int search(node* root, int id){
    node *temp = root;
    while(temp->id != id){
        if(id < temp->id){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return temp->dish;
}
int find_item_BT(string tablename_data, int id){
    list order; 
    char data[100];
    FILE* ptr = fopen(tablename_data, "r");
    int i;
    fgets(data, 100, ptr);
    for(i=0;i<10;i++){
        fgets(data, 2, ptr);
        order[i].id = atoi(data);
        fgets(data, 2, ptr);
        fgets(data, 100, ptr);
        order[i].dish = atoi(data);
    }
    printf("%i",order[id-1].dish);
    node *root = sortedArrayToBST(order, 0, 10);
    int dish = search(root, id);
    
    return dish;
}
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