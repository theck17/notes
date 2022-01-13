/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-13 21:40:58
 *   Description   ：
 */
typedef struct Node{
    int val;
    struct Node *next;
}Node;

typedef struct {
   int min;
   Node * top; 
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *stack=malloc(sizeof(MinStack)); 
    stack->top=NULL;
    return stack;
}

void minStackPush(MinStack* obj, int x) {
    Node *new = malloc(sizeof(Node));
    new->val=x;
    if(obj->top==NULL) obj->min=x;
    else obj->min=obj->min>x?x:obj->min;
    new->next=obj->top;
    obj->top=new;
}

void minStackPop(MinStack* obj) {
    Node *tmp = obj ->top;
    obj->top=obj->top->next;
    if(tmp->val==obj->min){
        Node *current=obj->top;
        obj->min=INT_MAX;
        while(current){
            obj->min=obj->min>current->val?current->val:obj->min;
            current=current->next;
        }
    }
    free(tmp);
}

int minStackTop(MinStack* obj) {
    return obj->top->val ;
}

int minStackGetMin(MinStack* obj) {
    return obj->min;  
}

void minStackFree(MinStack* obj) {
   Node *stack= obj->to; 
   while(stack) {
       Node *tmp=stack;
       stack=stack->next;
       free(tmp);
   }    
}

int main(){
    return 0;
}
