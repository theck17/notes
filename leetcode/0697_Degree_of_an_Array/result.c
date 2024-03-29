/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-04 21:24:26
 *   Description   ：
 */
struct node{
    int key;
    int val;
    int times;
    struct node *next;
};
struct table{
    int size;
    struct node **list;
};
struct table *createTable(int size){
    struct table *t = (struct table*)malloc(sizeof(struct table));
    t->size = size;
    t->list = (struct node**)malloc(sizeof(struct node*)*size);
    int i;
    for(i=0;i<size;i++)
        t->list[i] = NULL;
    return t;
}
int hashCode(struct table *t,int key){
    if(key<0)
        return -(key%t->size);
    return key%t->size;
}
void insert(struct table *t,int key,int val,int *max,int *ret){
    int pos = hashCode(t,key);
    struct node *list = t->list[pos];
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    struct node *temp = list;
    while(temp){
        if(temp->key==key){
            temp->times++;
            if(temp->times>=*max)
            {
                
                if(temp->times>*max||*ret>val-temp->val)
                    *ret=val-temp->val;
                *max=temp->times;
           }
            return;
        }
        temp = temp->next;
    }
    newNode->key = key;
    newNode->val = val;
    newNode->times = 1;
    newNode->next = list;
    t->list[pos] = newNode;
}

int findShortestSubArray(int* nums, int numsSize){
    struct table *t = createTable(50);
    int max=0,ret=INT_MAX;
    for(int i=0;i<numsSize;i++)
    {
        insert(t,nums[i],i,&max,&ret);
    }
    if(ret==INT_MAX)
        return 1;
    return ret+1;
} 

int main(){
    return 0;
}
