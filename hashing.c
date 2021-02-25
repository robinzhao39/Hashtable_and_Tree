#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tree.h"

typedef struct cell{
  char *word;
  struct cell *next;
} HASHCELL;

#define SIZE 100

HASHCELL *hashtable[SIZE];

unsigned int hash_string(char * newstring){
  unsigned int hash=1;
  for(int i=0; newstring[i];i++){
    hash=hash*7+newstring[i];
  }
  return hash%SIZE;
}

void insert_hash_cell(char* string){
  unsigned int index=hash_string(string);
  HASHCELL * newcell= (HASHCELL *)malloc(sizeof(HASHCELL));
  char *target=(char *)malloc(strlen(string)+1);
  newcell->word=target;
  strcpy(target,string);
  if(hashtable[index]==0){
    hashtable[index]=newcell;
  }
  else{
    HASHCELL *current=hashtable[index];
    while(1){
      int value=strcmp(current->word,newcell->word);
      if(value==0){
        break;
      }
      else if(current->next==0){
          current->next=newcell;
          break;
      }
      current=current->next;
    }
  }

}


void print_hash_table(){
  HASHCELL *current;
  for(int i=0;i<SIZE;i++){
    printf("%d :",i);
    current=hashtable[i];
    while(current!=0){
      printf("%s ", current->word);
      current=current->next;
    }
    printf("\n");
  }
}


int main(){
  char str[100];
  while (scanf("%s",str) != EOF) {
    insert_hash_cell(str);
    }
  for(int i=0;i<SIZE;i++){
    HASHCELL *current=hashtable[i];
    while(current!=0){
      insert_node(current->word);
      current=current->next;
    }
  }
  print_tree(root);
  //print_hash_table();
}
