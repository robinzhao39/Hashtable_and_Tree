#include "tree.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


NODE *root;

void rec_insert_node(NODE* n, NODE* r){
  if(strcmp(n->word,r->word)<0){
    if(r->left==0){
      r->left=n;
    }
    else{
      rec_insert_node(n,r->left);
    }
  }
  else{
    if(r->right==0){
      r->right=n;
    }
    else{
      rec_insert_node(n,r->right);
    }
  }
}

void insert_node(char* str){
  NODE *newnode=(NODE*)malloc(sizeof(NODE));
  newnode->word=str;
  if(root!=0){
    rec_insert_node(newnode,root);
  }
  else{
    root=newnode;
  }
}


void print_tree(NODE* r){
  if(r==0){
    return;
  }
  else{
    print_tree(r->left);
    printf("%s\n", r->word);
    print_tree(r->right);
  }
}
