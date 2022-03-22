/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-12-24 18:47:47
 *   Description   ：
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** removeComments(char ** source, int sourceSize, int* returnSize){
    int block_mode = 0, count = 0, pos = 0;
    char tmp[160];
    char **target = (char **)malloc(sizeof(char *) * 100);
    for (int i = 0; i < sourceSize; ++i) {
        char *str = source[i];
        char prev = str[0];
        if (prev == '\0')
            continue;
        char curr = str[1];
        if (!block_mode) {
            pos = 0;
            tmp[pos++] = prev;
        }
        for (int j = 1; curr != '\0'; ++j) {
            if (block_mode) {
                if (prev == '*' && curr == '/') {
                    block_mode = 0;
                    if ((curr = str[++j]) == '\0')
                        break;
                }
            } else if (prev == '/') {
                if (curr == '/') {
                    pos--;
                    break;
                } else if (curr == '*') {
                    block_mode = 1;
                   pos--;
                    j++;
                    if ((prev = str[j]) != '\0' && (curr = str[j+1]) != '\0')
                        continue;
                    else
                        break;
                }
            }
            if (!block_mode)
                tmp[pos++] = curr;
            prev = curr;
            curr = str[j+1];
        }
        if (!block_mode) {
            if (pos == 0)
                continue;
            target[count] = (char *)malloc(sizeof(char) * (pos+1));
            char *dest = target[count++];
            for (int k = 0; k < pos; ++k)
                dest[k] = tmp[k];
            dest[pos] = '\0';
        }
    }
    *returnSize = count;
    return target;
} 

