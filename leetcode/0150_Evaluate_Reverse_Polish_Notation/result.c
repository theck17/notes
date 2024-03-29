/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-29 18:38:56
 *   Description   ：
 */
int evalRPN(char ** tokens, int tokensSize){
    // push numbers into stack, once we got operator, we pop numbers from stack and do the calculation,
    // and push the result into stack, then continue, finally we return the top element of the stack
    int stack[tokensSize];
    int stack_sz = 0;
    
    for (int i = 0; i < tokensSize; i++)
    {
        if (tokens[i][0] == '+' ||
            (tokens[i][0] == '-' && strlen(tokens[i]) == 1) ||
            tokens[i][0] == '*' ||
            tokens[i][0] == '/')
        {
            int operand1 = stack[--stack_sz];
            int operand2 = stack[--stack_sz];
            switch (tokens[i][0])
            {
                case '+':
                    stack[stack_sz++] = (operand1 + operand2);
                    break;
                case '-':
                    stack[stack_sz++] = (operand2 - operand1);
                    break;
                case '*':
                    stack[stack_sz++] = (operand1 * operand2);
                    break;
               default:    // it would be '/'
                    stack[stack_sz++] = (operand2 / operand1);
            }
        }
        else
        {
            stack[stack_sz++] = strtol(tokens[i], (char **)NULL, 10);
        }
    }
    
    return stack[stack_sz - 1];
} 

int main(){
    return 0;
}
