/**
 *   Copyright (C) 2022 All rights reserved.
 *
 *   FileName      ：result.c
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2022-01-21 10:47:25
 *   Description   ：
 */
bool isPalindrome( int x )
{
    if( x < 0) return 0;
    int size = log10( x );
    int max = pow( 10, size );
    int offset = 1;
    for( int i = 0; i < ( size + 1 ) / 2; ++i )
    {
        if( x % (10 * offset ) / offset != x / ( max / offset ) % 10 ) return 0;
        offset *= 10;
    }
    return 1;
}

int main(){
    return 0;
}
