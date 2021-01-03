[TOC]
# 排序
## 归并排序
```
def mergeSort(alist):
    if len(alist) > 1:
        mid = len(alist)//2
        lefthalf = alist[:mid]
        righthalf = alist[mid:]

        mergeSort(lefthalf)
        mergeSort(righthalf)

        i = 0; j = 0; k = 0
        while i < len(lefthalf) and j < len(righthalf):
            if lefthalf[i] < righthalf[j]:
                alist[k] = lefthalf[i]
                i += 1
            else:
                alist[k] = righthalf[j]
                j += 1
            k += 1

        while i < len(lefthalf):
            alist[k] = lefthalf[i]
            i += 1
            k += 1
        while j < len(righthalf):
            alist[k] = righthalf[j]
            j += 1
            k += 1

alist = [54,26,93,17,77,31,44,55,20]
mergeSort(alist)
print(alist)
```
## 快速排序
```
def quickSort(alist):
    quickSortHelper(alist, 0, len(alist)-1)

def quickSortHelper(alist, first, last):
    if first < last:
        splitPoint = partition(alist, first, last)

        quickSortHelper(alist, first, splitPoint-1)
        quickSortHelper(alist, splitPoint+1, last)

def partition(alist, first, last):
    pivotvlue = alist[first]

    leftmark = first+1
    rightmark = last
    done = False

    while not done:
        while leftmark <= rightmark and alist[leftmark] <= pivotvlue: # bugfix: 先比较index, 不然数组会越界
            leftmark += 1
        while rightmark >= leftmark and alist[rightmark] >= pivotvlue:
            rightmark -= 1

        if leftmark > rightmark:
            done = True
        else:
            alist[leftmark], alist[rightmark] = alist[rightmark], alist[leftmark]
    alist[rightmark], alist[first] = alist[first], alist[rightmark]
    return rightmark

alist = [54,26,93,17,77,31,44,55,20]
alist2 = [1]
quickSort(alist2)
print(alist2)


if __name__ == "__main__":
    test_data = [3,2,111,3,-1,0,0,1,0,2,4]

    res_stable = sorted(test_data)
    quickSort(test_data)
    print(test_data)
    print(res_stable)
    assert all(map(lambda x: x[0] == x[1], zip(res_stable, test_data)))
```
## 插入排序
```
def insertionSort(alist):
    for key, item in enumerate(alist):
        index = key
        while index > 0 and alist[index-1] > item:
            alist[index] = alist[index-1]
            index -= 1
        alist[index] = item
    return alist

alist = [54,26,93,17,77,31,44,55,20]
print(insertionSort(alist))

def insertionSort2(alist):
    for index in range(1, len(alist)):
        currentvalue = alist[index]
        position = index

        while position > 0 and alist[position-1] > currentvalue:
            alist[position] = alist[position-1]
            position -= 1
        alist[position] = currentvalue

    return alist

print(insertionSort2(alist))
```
## 冒泡排序
```
def bubbleSort(alist):
    for passnum in range(len(alist)-1, 0, -1):
        for i in range(passnum):
            if alist[i] > alist[i+1]:
                alist[i], alist[i+1] = alist[i+1], alist[i]
    return alist

alist = [54,26,93,17,77,31,44,55,20]
print(bubbleSort(alist))

# 改进的冒泡排序, 加入一个校验, 如果某次循环发现没有发生数值交换, 直接跳出循环
def modiBubbleSort(alist):
    exchange = True
    passnum = len(alist) - 1
    while passnum >= 1 and exchange:
        exchange = False
        for i in range(passnum):
            if alist[i] > alist[i+1]:
                alist[i], alist[i+1] = alist[i+1], alist[i]
                exchange = True
        passnum -= 1
    return alist

print(bubbleSort(alist))
```
## 选择排序
```
def selectionSort(alist):
    for i in range(len(alist)-1):
        min = i
        for j in range(i+1, len(alist)):
            if alist[j] < alist[min]:
                min = j
        alist[i], alist[min] = alist[min], alist[i]
    return alist

alist = [54,26,93,17,77,31,44,55,20]
print(selectionSort(alist))
```
## 堆排序
```
def heapSort(alist):
    if alist == None or len(alist) == 0:
        return
    length = len(alist)
    output = []
    for i in range(length):
        tempLen = len(alist)
        for j in range(tempLen//2-1, -1, -1):
            preIndex = j
            preVal, heap = alist[preIndex], False
            while 2 * preIndex < tempLen - 1 and not heap:
                curIndex = 2 * preIndex + 1
                if curIndex < tempLen - 1:
                    if alist[curIndex] < alist[curIndex+1]:
                        curIndex += 1
                if preVal >= alist[curIndex]:
                    heap = True
                else:
                    alist[preIndex] = alist[curIndex]
                    preIndex = curIndex
            alist[preIndex] = preVal
        output.insert(0, alist.pop(0))
    return output

test = [2, 6, 5, 9, 10, 3, 7]
print(heapSort(test))
```
## LeetCode239返回滑动窗口中的最大值
```
from collections import deque
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        if len(nums) == 0:
            return []
        q = deque()
        for i in range(k):
            while q and nums[i] >= nums[q[-1]]:
                q.pop()
            q.append(i)
            
        result = []
        for i in range(k, len(nums)):
            result.append(nums[q[0]])
            
            while q and q[0] <= i-k:
                q.popleft()
            while q and nums[i] >= nums[q[-1]]:
                q.pop()
                
            q.append(i)
            
        result.append(nums[q[0]])
        return result 
```
## 编程实现 O(n) 时间复杂度内找到一组数据的第 K 大元素
```
 
def quicksort(num ,low ,high):  #快速排序
    if low< high:
        location = partition(num, low, high)
        quicksort(num, low, location - 1)
        quicksort(num, location + 1, high)
 
def partition(num, low, high):
    pivot = num[low]
    while (low < high):
        while (low < high and num[high] > pivot):
            high -= 1
        while (low < high and num[low] < pivot):
            low += 1
        temp = num[low]
        num[low] = num[high]
        num[high] = temp
    num[low] = pivot
    return low
 
def findkth(num,low,high,k):   #找到数组里第k个数
        index=partition(num,low,high)
        if index==k:return num[index]
        if index<k:
            return findkth(num,index+1,high,k)
        else:
            return findkth(num,low,index-1,k)
 
 
pai = [2,3,1,5,4,6]
print(findkth(pai,0,len(pai)-1,0))
```
# 二分查找
## 实现一个有序数组的二分查找算法
```
def binarySearch(alist, item):
    first = 0
    last = len(alist) - 1

    while first <= last:
        mid = (first + last)//2
        print(mid)
        if alist[mid] > item:
            last = mid - 1
        elif alist[mid] < item:
            first = mid + 1
        else:
            return mid+1
    return -1

test = [0, 1, 2, 8, 13, 17, 19, 32, 42]
print(binarySearch(test, 3))
```
## 实现模糊二分查找算法
```
def half_search(array,target):
  low = 0
  high = len(array) - 1
  while low < high:
     mid = (low + high)/2
     if array[mid] > target:
      high = mid - 1
     elif array[mid] < target:
      low = mid + 1
     elif array[mid] == target:
      print 'I find it! It is in the position of:',mid
      return mid
     else:
      print "please contact the coder!"
  return -1
 
array = [1, 2, 2, 4, 4, 5]
```
## LeetCode69 x的平方根
```
class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        low, high, mid = 0, x, x / 2
        while low <= high:
            if mid * mid > x:
                high = mid - 1
            else:
                low = mid + 1
            mid = (low + high) / 2
        return mid
```