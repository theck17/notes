/** Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-22 16:40:43
 *   Description   ：
 */
char * addStrings(char * num1, char * num2){
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int len = len1>len2?len1+1:len2+1;
    char * num = malloc((len+1) * sizeof(char));
    memset(num, 0, len+1);
    int carry = 0;
    for(int i=0; i<len; i++){
        if(i>=len1 && i>=len2){
            if(carry) num[len-1-i] = '1';
            else num+=1;
            break;
        }else if(i>=len1){
            num[len-1-i] = '0' + (num2[len2-1-i] - '0' + carry)%10;
            carry = (num2[len2-1-i] - '0' + carry)/10;
        }else if(i>=len2){
            num[len-1-i] = '0' + (num1[len1-1-i] - '0' + carry)%10;
            carry = (num1[len1-1-i] - '0' + carry)/10;
        }else{
            num[len-1-i] = '0' + (num1[len1-1-i] - '0' + num2[len2-1-i] - '0' + carry)%10;
            carry = (num1[len1-1-i] - '0' + num2[len2-1-i] - '0' + carry)/10;
        }
    }
    return num;
}

int main(){
    return 0;
}
