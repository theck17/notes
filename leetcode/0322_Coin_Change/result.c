/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-11-07 14:34:48
 *   Description   ：
 */
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int coinChange(int* coins, int coinsSize, int amount){
    // if we want to get the fewest number of 'amount'
    // we hope to get from the 'past', which would be
    // {amount - coin[0], amount - coin[1], ..., amount - coin[i]}
    // then we can add '1' to the minimal value
    int *dp = (int *)malloc(sizeof(int) * (amount + 1));
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) dp[i] = INT_MAX - 1;
    for (int i = 1; i <= amount; i++)
    {
        int min = INT_MAX;
        for (int j = 0; j < coinsSize; j++)
        {
            if (i - coins[j] >= 0)
            {
                if (min > dp[i - coins[j]])
                {
                    min = dp[i - coins[j]];
                }
            }
        }
        if (min != INT_MAX)
            dp[i] = min + 1;
    }
    
    return (dp[amount] >= INT_MAX - 1) ? -1 : dp[amount];
}

int main(){
    return 0;
}
