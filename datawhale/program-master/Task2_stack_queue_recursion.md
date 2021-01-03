[TOC]
# 栈
## 用数组实现一个顺序栈
```python
class Stack(object):
    def __init__(self):
        self.stack = []
 
    def push(self, item):
        """添加一个新的元素item到栈顶"""
        self.stack.append(item)
 
    def pop(self):
        """弹出栈顶元素"""
        return self.stack.pop()
    
    def is_empty(self):
        """判断栈是否为空"""
        return self.stack == []
    
    def peek(self):
        """返回栈顶元素"""
        if self.is_empty():
            return None
 
        return self.stack[-1]
 
    def size(self):
        """返回栈的元素个数"""
        return len(self.stack)
```
## 用链表实现一个链式栈
```python
class LinkedStack:
    
    # 创建节点
    class _Node:
        __slot__='_element','_next'
        
        def __init__(self,element,next):
            self._element = element
            self._next = next
        
    # 设置栈顶
    def __init__(self):
        self._head =None
        self._size = 0
        
    # 元素压栈
    def push(self,e):
        self._head = self._Node(e,self._head)
        self._size += 1
```
## 编程模拟实现一个浏览器的前进、后退功能
```python
class Stack(object):
    def __init__(self):
        self.array = [[], []]
 
    def push_a(self, data):
        self.array[0].append(data)
 
    def pop_a(self):
        if len(self.array[0]) == 0:
            print('Stack a is empty')
        else:
            self.array[0].pop()
 
    def push_b(self, data):
        self.array[1].append(data)
 
    def pop_b(self):
        if len(self.array[1]) == 0:
            print('Stack b is empty')
        else:
            self.array[1].pop()
 
    def show(self):
        if len(self.array[0]) == 0:
            print('Stack a is empty')
        else:
            print('Stack a:', self.array[0])
        if len(self.array[1]) == 0:
            print('Stack b is empty')
        else:
            print('Stack b:',self.array[1])
```
# 队列
## 用数组实现一个顺序队列
```python
class Queue(object):
    def __init__(self):
        self.l = []

    def empty(self):
        """
        判断队列是否为空
        :return:
        """
        return len(self.l) == 0

    def add(self, obj):
        """
        将指定元素加入队列的尾部
        :param obj:
        :return:
        """
        self.l.append(obj)

    def peek(self):
        """
        查看队首的对象，但不移除
        :return:
        """
        if not self.empty():
            return self.l[0]
        return None

    def poll(self):
        """
        移除队首对象，并返回该对象的值
        :return:
        """
        if not self.empty():
            return self.l.pop(0)
        return None
```
## 用链表实现一个链式队列
```python
class Node(object):
    # 节点
    def __init__(self, data=None):
        self.data = data
        self.next = None
 
class LkQueue():
 
    def __init__(self):
        self.front = Node()
        self.rear = Node()
        self.length = 0
 
    def get_length(self):
        return self.length
 
    def is_empty(self):
        empty = self.length == 0 and True or False
        return empty
 
    def enQueue(self, elem):
        # 入队
        tmp = Node(elem)
        if self.is_empty():
            self.front = tmp
            self.rear = tmp
        else:
            self.rear.next = tmp
            self.rear = tmp
        self.length += 1
 
    def deQueue(self):
        # 出队
        if self.is_empty():
            raise ValueError("LKQueue is empty!")
        else:
            del_elem = self.front.data
            self.front = self.front.next
            self.length -= 1
            return del_elem
 
    def showQueue(self):
        # 从对首 出队
        if self.is_empty():
            raise ValueError("LKQueue is empty!")
 
        j = self.length
        tmp = self.front
        while j > 0:
            print tmp.data,
            tmp = tmp.next
            j -= 1
        print ''
```
## 实现一个循环队列
```python
#!/usr/bin/python3.5
#_*_coding:utf-8_*_
 
class Queue():
    def __init__(self,capacity):
        self.queue = [None] * capacity
        self.capacity = capacity
        self.front = 0
        self.rear = 0
 
    def enQueue(self,element):
        if self.full():
            print('满')
            return
        self.queue[self.rear] = element
        self.rear  = (self.rear + 1) % self.capacity
 
    def deQueue(self):
        if self.empty():
            print('空')
            return
        temp = self.queue[self.front]
        self.queue[self.front] = None
        self.front = (self.front + 1) % self.capacity
        return temp
 
    def full(self):
        return (self.rear + 1) % self.capacity == self.front
 
    def empty(self):
        return self.front == self.rear
 
    def printQueue(self):
        temp = self.front
        while temp != self.rear:
            print(self.queue[temp])
            temp = (temp + 1) % self.capacity
 
    def clear(self):
        temp = self.front
        while temp != self.rear:
            self.queue[temp] = None
            temp = (temp + 1) % self.capacity
        self.rear = self.front
 
    def getHead(self):
        if self.empty():
            print('空')
            return
        return self.queue[self.front]
 
    def length(self):
        return (self.rear - self.front + self.capacity) % self.capacity
 
if __name__ == '__main__':
    queue = Queue(100)
```
# 递归
## 编程实现斐波那契数列求值 f(n)=f(n-1)+f(n-2)
```python
def Fibonacci_Recursion_tool(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return Fibonacci_Recursion_tool(n - 1) + Fibonacci_Recursion_tool(n - 2)


def Fibonacci_Recursion(n):
    result_list = []
    for i in range(1, n + 1): result_list.append(Fibonacci_Recursion_tool(i))
    return result_list
```
## 编程实现求阶乘 n!
```python
def fact(x):
    if x==1:
        return 1
    else:
        return x*fact(x-1)
```
## 编程实现一组数据集合的全排列
```python
def perm(data, begin, end):
    if begin == end:
    #递归结束条件，当交换到最后一个元素的时候不需要交换，1的全排列还是1。
        print(data)  
        # 打印一次排列完成后的数组。
    else:
        j = begin
        for i in range(begin, end):  # 从begin到end全排列。
            data[i], data[j] = data[j], data[i]
            perm(data, begin + 1, end)
            data[i], data[j] = data[j], data[i] 
```
# LeetCode
## 20有效的括号
```python
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        v=[]
        a=['(','{','[']
        for i in range(len(s)):
            if s[i] in a:
                v.append(s[i])
                continue
            elif s[i]==')':
                if len(v)==0 or v.pop()!='(':
                    return False
            elif s[i]==']':
                if len(v)==0 or v.pop()!='[':
                    return False           
            elif s[i]=='}':
                if len(v)==0 or v.pop()!='{':
                    return False         
        return len(v)==0
```
## 32最长有效括号
```python
class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack, result = [-1], 0

        for index in range(len(s)):
        	if s[index] == '(':
        		stack.append(index)
        	else:
        		currIndex = stack.pop()
        		if currIndex == -1:
        			stack.append(index)
        		else:
        			result = max(result, index-currIndex+1)
        return result
```
## 150逆波兰表达式求值 
```python
class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        
        if not tokens:
            return 0
        
        stack = []
        for val in tokens:
            if val == '+':
                val1 = stack.pop()
                val2 = stack.pop()
                stack.append(val1 + val2)
            elif val == '-':
                val1  = stack.pop()
                val2 = stack.pop()
                stack.append(val2-val1)
            elif val == '*':
                val1  = stack.pop()
                val2  = stack.pop()
                stack.append(val2*val1)
            elif val == '/':
                val1 = stack.pop()
                val2  = stack.pop()
                if val1*val2 < 0:
                    stack.append(-(-val2/val1))
                else:
                    stack.append(val2/val1)
            else:
                stack.append(int(val))
        return stack[0]
```
## 641设计循环双端队列
```python
class Node:
    def __init__(self, value):
        self.val = value
        self.next = self.pre = None
         
class MyCircularDeque:
 
    def __init__(self, k):
        self.head = self.tail = Node(-1)
        self.head.next = self.tail
        self.tail.pre = self.head
        self.size = k
        self.curSize = 0
 
    def add(self, value, preNode):
        new = Node(value)
        new.pre = preNode
        new.next = preNode.next
        new.pre.next = new.next.pre = new
        self.curSize += 1
         
    def remove(self, preNode):
        node = preNode.next
        node.pre.next = node.next
        node.next.pre = node.pre
        self.curSize -= 1
     
    def insertFront(self, value):
        if self.curSize < self.size:
            self.add(value, self.head)
            return True
        return False
 
    def insertLast(self, value):
        if self.curSize < self.size:
            self.add(value, self.tail.pre)
            return True
        return False
 
    def deleteFront(self):
        if self.curSize:
            self.remove(self.head)
            return True
        return False
 
    def deleteLast(self):
        if self.curSize:
            self.remove(self.tail.pre.pre)
            return True
        return False
 
    def getFront(self):
        if self.curSize:
            return self.head.next.val
        return -1
 
    def getRear(self):
        if self.curSize:
            return self.tail.pre.val
        return -1
 
    def isEmpty(self):
        return self.curSize == 0
 
    def isFull(self):
        return self.curSize == self.size
```
## 239滑动窗口最大值
```python
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
## 70爬楼梯
```python
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
        	return 0

        dp = [0]*n
        dp[0], dp[1] = 1, 2

        for index in range(2, n):
        	dp[index] = dp[index-1] + dp[index-2]
        return dp[n-1]
```