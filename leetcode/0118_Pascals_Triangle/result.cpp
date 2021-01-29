/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-01-27 20:08:02
 *   Description   ：
 */
k
#include <algorithm>        //STL 通用算法
#include <memory>          //STL通过分配器进行的内存分配
#include <new>             //动态内存分配
#include <iostream>        //数据流输入／输出
#include <istream>         //基本输入流
#include <iterator>        //STL迭代器
#include <ostream>         //基本输出流
#include <queue>           //STL 队列容器
#include <set>             //STL 集合容器
using namespace std;



class Solution {
public:
    static vector< vector < int > > generate( int numRows ) 
    {
        vector< vector< int > > result;
        result.resize( numRows );
        
        int rowIndex = 0;
        for (  const auto & row : result )
        {
            auto &currentRow = result[ rowIndex ];
            
            if ( rowIndex )
            {
                auto &prevRow = result[ rowIndex - 1 ];
                currentRow.reserve( rowIndex );
                std::adjacent_difference( begin( prevRow ), end( prevRow ), back_inserter( currentRow ), std::plus<>{} );
            }
            
            currentRow.push_back( 1 );
            
            ++rowIndex;
        }
        
        return result;
    }
};


int main(){
    return 0;
}
