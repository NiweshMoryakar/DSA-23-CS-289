#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
int isempty(struct node* top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int isfull(struct node* top){
    struct node* p=(struct node*)malloc(sizeof(struct node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
struct node* push(struct node* top,int data){
    if (isfull(top)){
        printf("stack overflow\n");
    }
    else{
        struct node* p=(struct node*)malloc(sizeof(struct node));
        p->data=data;
        p->next=top;
        top=p;
        return top;
    }
}
int pop(struct node** top){
    if (isempty(*top)){
        printf("stack underflow\n");
        return 0;
    }
    else{
        struct node* p=*top;
        *top=(*top)->next;
        int x=p->data;
        free(p);
        return x;
    }
}
int peek(struct node* top,int val){
    struct node* ptr=top;
    for(int i=0;i<val-1 && ptr!=NULL;i++){
        ptr=ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
}
int stacktop(struct node* top){
    if(isempty(top)){
        printf("stack underflow\n");
    }
    else{
        return top->data;
    }
}
int stackbottom(struct node* top){
    if(isempty(top)){
        printf("stack underflow\n");
    }
    else{
        struct node* ptr=top;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        return ptr->data;
    }
}
void traversal(struct node* ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    struct node* top=NULL;
    top=push(top,5);
    top=push(top,4);
    top=push(top,3);
    top=push(top,2);
    traversal(top);
    printf("\n");
    int ele=pop(&top);
    printf("popped element: %d\n",ele);
    int x=peek(top,2);
    printf("%d\n",x);
    printf("stacktop: %d\n",stacktop(top));
    printf("stackbottom: %d\n",stackbottom(top));
    return 0;
}