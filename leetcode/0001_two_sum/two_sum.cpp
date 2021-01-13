/**
 *   Copyright (C) 2021 All rights reserved.
 *
 *   FileName      ：two_sum.cpp
 *   Author        ：C.K
 *   Email         ：theck17@163.com
 *   DateTime      ：2021-01-11 00:26:27
 *   Description   ：
 */
#include <algorithm>        //STL 通用算法
#include <bitset>           //STL 位集容器
#include <cctype>          //字符处理
#include <string>          //字符串类
#include <vector>          //STL 动态数组容器
#include <valarray>        //对包含值的数组的操作
#include <ctime>           //定义关于时间的函数
using namespace std;


// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int size_of_arr = sizeof nums;
//         for (int a=0; a<=size_of_arr;a++){
//             for (int b=a+1; b<=size_of_arr;b++){
//                 int temp = nums[a] + nums[b];
//                 if (temp == target){
//                     return {a ,b};
//                 }
//             }
//         }
//         return {};
//     }
// };
// // error
// =================================================================
// ==30==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x6020000001a0 at pc 0x000000344990 bp 0x7ffeca29db50 sp 0x7ffeca29db48
// READ of size 4 at 0x6020000001a0 thread T0
//     #2 0x7ff876c610b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
// 0x6020000001a0 is located 0 bytes to the right of 16-byte region [0x602000000190,0x6020000001a0)
// allocated by thread T0 here:
//     #6 0x7ff876c610b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
// Shadow bytes around the buggy address:
//   0x0c047fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0c047fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0c047fff8000: fa fa fd fa fa fa fd fa fa fa fd fa fa fa fd fa
//   0x0c047fff8010: fa fa fd fd fa fa fd fa fa fa fd fa fa fa fd fa
//   0x0c047fff8020: fa fa fd fa fa fa fd fa fa fa fd fa fa fa fd fa
// =>0x0c047fff8030: fa fa 00 00[fa]fa fa fa fa fa fa fa fa fa fa fa
//   0x0c047fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//   0x0c047fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//   0x0c047fff8060: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//   0x0c047fff8070: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
//   0x0c047fff8080: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
// Shadow byte legend (one shadow byte represents 8 application bytes):
//   Addressable:           00
//   Partially addressable: 01 02 03 04 05 06 07
//   Heap left redzone:       fa
//   Freed heap region:       fd
//   Stack left redzone:      f1
//   Stack mid redzone:       f2
//   Stack right redzone:     f3
//   Stack after return:      f5
//   Stack use after scope:   f8
//   Global redzone:          f9
//   Global init order:       f6
//   Poisoned by user:        f7
//   Container overflow:      fc
//   Array cookie:            ac
//   Intra object redzone:    bb
//   ASan internal:           fe
//   Left alloca redzone:     ca
//   Right alloca redzone:    cb
//   Shadow gap:              cc
// ==30==ABORTING


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> prevMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            
            if(prevMap.count(diff)) 
                return { prevMap[diff], i };
            prevMap[nums[i]] = i;
        }
        return {};
    }
};


int main(){
  std::vector<int> my_arr[4] = [2,7,11,15]
  int my_sum = 9
  Solution mySolution;          // 创建一个对象
  mySolution.twoSum(&my_arr, &my_sum);  // 调用该对象的成员函数
  
  return 0;
}
