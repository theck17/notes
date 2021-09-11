/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-09-10 19:11:00
 *   Description   ：
 */
#include <math.h>         //数学函数
#include <ctype.h>        //字符函数
#include <string.h>      //字符串函数
#include <stdio.h>       //输入输出函数 
#include <stdlib.h>      //动态分配函数和随机函数 
struct stack{
    int val;
    unsigned int cap;
    struct stack *link;
    struct stack *prev_link;
};
int head(struct stack** top){
    if((*top)==NULL)
        return 0;
    return (*top)->val;
}

void push(struct stack** top,struct stack **end,int x){
    struct stack *temp = (struct stack*)malloc(sizeof(struct stack));
    temp->val = x;
    temp->link = NULL;
    temp->prev_link = NULL;
    if((*top)!=NULL){
        temp->cap = ((*top)->cap)+1;
        (*top)->prev_link = temp;
        temp->link = *top;
        *top = temp;
    }
    else{
        temp->cap = 0;
        *top = *end = temp;
    }

}
void pop(struct stack** top){
    if((*top)==NULL)return ;
    struct stack *t = NULL;
    t=(*top);
    (*top) = t->link;
    free(t);
}
void pop_end(struct stack** end){
    if((*end)==NULL)return;
    struct stack *t = *end;
    (*end) = t->prev_link;
    free(t);
}
void print(struct stack* top){
    if(top==NULL)return;
    struct stack* t = top;
    printf("Stack - {");
    while(t!=NULL){
        pintf("%c ",t->val);
        t = t->link;
    }
    printf("}");
    printf("\n");
}
/*
	* encoding rules k[encoded_string]
	* using stack to push the brackets and values and follow accordingly
	* store the data in as an integer value , ascii table codes are in range of 0 to 255 int is capbale of storing this data and reversing it 
*/


char * decodeString(char * s){
    if(s==NULL)return NULL;
    if(strlen(s)==0)return "";
    struct stack *encoded_string = NULL;
    struct stack *end = NULL;

    int n = 0;
    int i = 0;
    int j = 0;

    while(*s){

        /// check if the value presented is a number or a char

        if((*s) >= '0' && (*s) <= '9'){

            //build sequence for number bigger than 9

            n = n*10 + (*s)-'0';

        }else if(*s=='['){
            //push the number and the bracket because the bracket comes immediately after the number
            push(&encoded_string,&end,n);
            push(&encoded_string,&end,(int)(*s));//push the bracket
            n=0;

        }else{
            //push the rest of the elements
            push(&encoded_string,&end,(int)(*s));
        }
        if(*s == ']'){
            i=0;
            pop(&encoded_string);           //pop ] bracket
            int len = strlen(s);
            int alloc = len;
            char *string= (char *)calloc(len,sizeof(char));

            int instruction = 0;
            while(head(&encoded_string)!=(int)('[')){
                if(i==len){
                    string = (char *)realloc(string,(len+=alloc));
                }
                string[i] = (char )head(&encoded_string);
                pop(&encoded_string);
                i++;
            }
            pop(&encoded_string);           //pop [ bracket
            instruction = head(&encoded_string);
            pop(&encoded_string);           //pop instruction
            j=i;
            while(instruction){
                while(i){
                    push(&encoded_string,&end,string[i-1]);
                    i--;
                }
                i=j;
                instruction--;
            }
        }
        s++;
    }
    char *res = (char *)calloc(encoded_string->cap+2,sizeof(char));
    while(head(&end)){
        char ch = (char )head(&end);
        res[end->cap] = ch;
        pop_end(&end);
    }
    return res;

}r

int main(){
    return 0;
}