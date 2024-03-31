#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
void traversal(struct node* ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int search(struct node* head,int val){
    struct node* ptr=head;
    int c=0;
    while(ptr->next!=NULL){
        if(ptr->data==val){
            break;
        }
        else{
            ptr=ptr->next;
            c++;
        }
    }
    return c;
}
int main(){
    struct node* head;
    struct node* second;
    struct node* third;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=NULL;
    int s=search(head,3);
    printf("element present at index: %d",s);
    return 0;
}