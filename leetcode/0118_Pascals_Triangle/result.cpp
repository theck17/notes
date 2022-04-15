/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：result.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-01-27 20:08:02
 *   Description   ：
 */
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

