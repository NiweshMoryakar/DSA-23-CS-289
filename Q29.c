#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};
int main(){
    struct node* p;
    struct node* p1;
    struct node* p2;
    p=(struct node*)malloc(sizeof(struct node));
    p1=(struct node*)malloc(sizeof(struct node));
    p2=(struct node*)malloc(sizeof(struct node));
    p->data=3;
    p->left=p1;
    p->right=p2;
    p1->data=2;
    p2->data=1;
}