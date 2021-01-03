[TOC]
# 数组与链表
# Array
从严格意义上来说:Python里没有严格意义上的数组。
List可以说是Python里的数组
## 概念
* 请求空间以后大小固定，不能再改变（数据溢出问题）
* 在内存中有空间连续性的表现，中间不会存在其他程序需要调用的数据，为此数组的专用内存空间；
* 在旧式编程语言中，程序不会对数组的操作做下界判断，也就有潜在的越界操作的风险（比如会把数据写在运行中程序需要调用的核心部分的内存上）。
## 练习
### 实现一个支持动态扩容的数组
```
class DynamicArray(object): 
      
    def __init__(self): 
        self.n = 0 # Count actual elements (Default is 0) 
        self.capacity = 1 # Default Capacity 
        self.A = self.make_array(self.capacity) 
          
    def __len__(self): 
        """ 
        返回以数组排序的元素数 
        """
        return self.n 
      
    def __getitem__(self, k): 
        """ 
        返回索引为k的元素
        """
        if not 0 <= k <self.n: 
            # Check it k index is in bounds of array 
            return IndexError('K is out of bounds !')  
          
        return self.A[k] # Retrieve from the array at index k 
          
    def append(self, ele): 
        """ 
       将元素添加到数组的末尾 
        """
        if self.n == self.capacity: 
            # Double capacity if not enough room 
            self._resize(2 * self.capacity)  
          
        self.A[self.n] = ele # Set self.n index to element 
        self.n += 1
          
    def _resize(self, new_cap): 
        """ 
        将数组的容量大小调整为new_cap 
        """
          
        B = self.make_array(new_cap) # New bigger array 
          
        for k in range(self.n): # Reference all existing values 
            B[k] = self.A[k] 
              
        self.A = B # Call A the new bigger array 
        self.capacity = new_cap # Reset the capacity 
          
    def make_array(self, new_cap): 
        """ 
        返回新数组 
        """
        return (new_cap * ctypes.py_object)()
```
### 实现一个大小固定的有序数组，支持动态增删改操作
```python
#函数上会标明该方法的时间复杂度
#动态数组的类

class DynamicArray:
    
    def __init__ (self):
        'Create an empty array.'
        self._n = 0 #size
        self._capacity = 10    #先给个10
        self._A = self._make_array(self._capacity)
        
    def __len__ (self):
        return self._n
    
    def is_empty(self):
        return self._n == 0
    
    # O(1)
    def __getitem__ (self, k):
        if not 0 <= k < self._n:
            raise ValueError('invalid index') 
        return self._A[k]
       
    # O(1) 
    def append(self, obj):
        if self._n == self._capacity:    #首先要判断该容器是否放得下
            self._resize(2 * self._capacity)
        self._A[self._n] = obj    
        self._n += 1
        
    def _make_array(self, c):
        return (c * ctypes.py_object)( )
    
    def _resize(self, c):
        B = self._make_array(c)
        for k in range(self._n):
            B[k] = self._A[k]
        self._A = B
        self._capacity = c   

    # O(n)
    def insert(self, k, value):
        if self._n == self._capacity:
            self._resize(2 * self._capacity)
        for j in range(self._n, k, -1):    #从后往前一个一个往后移
            self._A[j] = self._A[j-1]
        self._A[k] = value
        self._n += 1
     
    # O(n)    
    def remove(self, value):
        for k in range(self._n):
            if self._A[k] == value:     #一个个查value
                for j in range(k, self._n - 1):
                    self._A[j] = self._A[j+1]   ##再一个个移上来
                self._A[self._n - 1] = None
                self._n -= 1
                return
        raise ValueError( 'value not found' )
    
    def _print(self):
        for i in range(self._n):
            print(self._A[i], end = ' ')
        print()

mylist = DynamicArray()
print ('size was: ', str(len(mylist)))
mylist.append(10)
mylist.append(20)
mylist.append(30)
mylist.insert(0, 0)
mylist.insert(1, 5)
mylist.insert(3, 15)
mylist._print()
mylist.remove(20)
mylist._print()
print ('size is: ', str(len(mylist)))
#输出结果
size was:  0
0 5 10 15 20 30 
0 5 10 15 30 
size is:  5
```

### 实现两个有序数组合并为一个有序数组
```
class Array_to_Array(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        index = m + n - 1
        m -= 1
        n -= 1
        while m >= 0 and n >= 0:
            if nums1[m] > nums2[n]:
                nums1[index] = nums1[m]
                m -= 1
            else:
                nums1[index] = nums2[n]
                n -= 1
            index -= 1
        if m < 0:
            nums1[:n + 1] = nums2[:n + 1]

```
### 学习哈希表思想，并完成leetcode上的两数之和(1)及Happy  Number(202)！(要求全部用哈希思想实现！)
1. 散列表(也叫哈希表)是一种数据结构，其数据元素的地址或索引值由散列函数生成。 这使得访问数据的速度更快，因为索引值是数据值的关键字。 换句话说，哈希表存储键值对，但键是通过哈希函数生成的。
2. 因此，数据元素的搜索和插入函数变得更快，因为键值本身成为存储数据的数组的索引。
3. 在Python中，字典数据类型表示哈希表的实现。字典中的键满足以下要求。
- 字典的键是可散列的，即通过散列函数生成该散列函数，该散列函数为提供给散列函数的每个唯一值生成唯一结果。
- 字典中数据元素的顺序不固定。
```
# 用Python实现hash表
# hash的查找操作时间复杂度O(1)
# hash每个位置被称为slot槽。可以使用list实现hash,每个slot对应一个key,存放元素
# 按照正常的字母在ASCII中的顺序mod tablesize构造hash
def hash(astring, tablesize):
    sum = 0
    for pos in astring:
        sum = sum + ord(pos)

    return sum%tablesize

print(hash('cat', 11))  # cat在hash中的位置,hash table长度11

# 改进hash, 让每一位的字母乘以该字母在字串中的位置然后mod
def hash2(astring, tablesize):
    sum = 0
    for pos in range(len(astring)):
        sum += (pos+1) * ord(astring[pos])
    return sum%tablesize

print(hash2('cat', 11))

# 冲突解决:分离链--冲突位置排成一个链; linear probing发生冲突去下一个位置

class HashTable:
    def __init__(self):
        self.size = 11
        self.slots = [None] * self.size
        self.data = [None] * self.size

    def put(self, key, data):
        hashvalue = self.hashfunction(key, self.size)

        if self.slots[hashvalue] == None:
            self.slots[hashvalue] = key
            self.data[hashvalue] = data
        else:
            if self.slots[hashvalue] == key:
                self.data[hashvalue] = data         # 替换相同索引对应的项目
            else:
                if None not in self.slots and key not in self.slots:
                    # 判断hash是否已经满了, 必须添加key not in self.slots, 否则修改已有hash值会直接返回-1
                    print('sorry, there is not enough slots for you!')
                    return -1
                nextslot = self.rehash(hashvalue, len(self.slots))
                while self.slots[nextslot] != None and self.slots[nextslot] != key:
                    nextslot = self.rehash(nextslot, len(self.slots))

                if self.slots[nextslot] == None:
                    self.slots[nextslot] = key
                    self.data[nextslot] = data
                else:
                    self.data[nextslot] = data

    def hashfunction(self, key, size):
        return key%size

    def rehash(self, oldhash, size):
        return (oldhash+1)%size

    def get(self, key):
        startslot = self.hashfunction(key, len(self.slots))

        data = None
        stop = False
        found = False
        position = startslot
        while self.slots[position] != None and not found and not stop:
            if self.slots[position] == key:
                found = True
                data = self.data[position]
            else:
                position = self.rehash(position, len(self.slots))
                if position == startslot:
                    stop = True
        return data

    def __getitem__(self, key):
        return self.get(key)

    def __setitem__(self, key, data):
        self.put(key, data)
```
# List
## 概念
1. 单链表中每个结点的存储地址是存放在其前趋结点next域中，而开始结点无前趋，故应设头指针head指向开始结点。同时，由于最后一个结点无后继，故结点的指针域为空，即NULL。头插法建表(逆序)、尾插法建表(顺序)。增加头结点的目的是算法实现上的方便，但增大了内存开销。
* 查找：只能从链表的头指针出发，顺链域next逐个结点往下搜索，直到搜索到第i个结点为止。因此，链表不是随机存取结构。
* 插入：先找到表的第i-1的存储位置，然后插入。新结点先连后继，再连前驱。
* 删除：首先找到ai-1的存储位置p。然后令p–>next指向ai的直接后继结点，即把ai从链上摘下。最后释放结点ai的空间.r=p->next;p->next=r->next;delete r。
* 判断一个单向链表中是否存在环的最佳方法是快慢指针。
2. 静态链表：用一维数组来实现线性链表，这种用一维数组表示的线性链表，称为静态链表。静态：体现在表的容量是一定的。（数组的大小）；链表：插入与删除同前面所述的动态链表方法相同。静态链表中指针表示的是下一元素在数组中的位置。
3. 循环链表：是一种头尾相接的链表。其特点是无须增加存储量，仅对表的链接方式稍作改变，即可使得表处理更加方便灵活。
4. 双向链表:在单链表的每个结点里再增加一个指向其直接前趋的指针域prior。这样就形成的链表中有两个方向不同的链。双链表一般由头指针唯一确定的，将头结点和尾结点链接起来构成循环链表，并称之为双向链表。设指针p指向某一结点，则双向链表结构的对称性可用下式描述：p—>prior—>next=p=p—>next—>prior。从两个方向搜索双链表，比从一个方向搜索双链表的方差要小。
## 练习
### 实现单链表、循环链表、双向链表，支持增删操作
```

class Node():
    """节点"""
    def __init__(self,elem):
        self.elem=elem
        self.next=None
 
class Single_CYCLE_LinkList():
    """单向循环链表"""
    def __init__(self,node=None):
        self._head=node
        if node:
            node.next=node
    def is_empty(self):
        #链表是否为空
        if self._head==None:
            return True
        else:
            return False
 
    def length(self):
        #链表长度
        if self.is_empty():
            return 0
        cur=self._head
        count=1
        while cur.next!=self._head:
            count+=1
            cur=cur.next
        return count
 
    def travel(self):
        #遍历整个链表
        if self.is_empty():
            return
        else:
            cur=self._head
            while cur.next!=self._head:
                print(cur.elem,end=' ')
                cur=cur.next
            print(cur.elem)
 
    def add(self,item):
        node=Node(item)
        if self.is_empty():
            self._head=node
            node.next=node
        else:
            cur=self._head
            while cur.next!=self._head:
                cur=cur.next
            node.next=self._head
            self._head=node
            cur.next=node
 
    def append(self,item):
        node=Node(item)
        if self._head == None:
            self._head = node
            node.next=node
        else:
            cur=self._head
            while cur.next!=self._head:
                cur=cur.next
            cur.next=node
            node.next=self._head
 
    def insert(self,pos,item):
        if pos<=0:
            self.add(item)
        elif pos>=self.length():
            self.append(item)
        else:
            node=Node(item)
            pre=self._head
            count=0
            while count<pos-1:
                count+=1
                pre=pre.next
            node.next=pre.next
            pre.next=node
 
    def remove(self,item):
        """删除一个节点"""
        # 若链表为空，则直接返回
        if self.is_empty():
            return
        # 将cur指向头节点
        pre=None
        cur=self._head
        while cur.next !=self._head:
            if cur.elem==item:
                #先判断此节点是否是头结点
                if cur==self._head:
                    #先找到尾节点
                    rear=self._head
                    while rear.next !=self._head:
                        rear=rear.next
                    rear.next=self._head
                    self._head=cur.next
 
                else:
                    #中间节点
                    pre.next=cur.next
                return
            else:
                pre=cur
                cur=cur.next
        #退出循环，cur指向尾节点
        if cur.elem==item:
            if self.length()==1:
                self._head=None
            else:
                pre.next = cur.next
 
    def search(self,item):
        if self.is_empty():
            return False
        cur=self._head
        while cur.next!=self._head:
            if cur.elem==item:
                return True
            else:
                cur=cur.next
        if cur.elem==item:
            return True
        return False
```
```
"""节点类"""
class Node(object):
    def __init__(self, data=None):
        self.data = data
        self.pre = None
        self.next = None

"""初始化双向链表"""
def __init__(self):
    """
    设置头尾，操作比较容易
    头－－（next）－－》尾
    尾－－（pre）－－》头
    :return:
    """
    head = Node()
    tail = Node()
    self.head = head
    self.tail = tail
    self.head.next = self.tail
    self.tail.pre = self.head
    
"""获取链表长度"""
def __len__(self):
    length = 0
    node = self.head
    while node.next != self.tail:
        length += 1
        node = node.next
    return length
"""追加节点"""

def append(self, data):
    """
    :param data:
    :return:
    """
    node = Node(data)
    pre = self.tail.pre
    pre.next = node
    node.pre = pre
    self.tail.pre = node
    node.next = self.tail
    return node
    
"""获取节点"""
def get(self, index):
    """
    获取第index个值，若index>0正向获取else 反向获取
    :param index:
    :return:
    """
    length = len(self)
    index = index if index >= 0 else length + index
    if index >= length or index < 0: return None
    node = self.head.next
    while index:
        node = node.next
        index -= 1
    return node
    
"""插入节点"""
def insert(self, index, data):
    """
    因为加了头尾节点所以获取节点node就一定存在node.next 和 node.pre
    :param index:
    :param data:
    :return:
    """
    length = len(self)
    if abs(index + 1) > length:
        return False
    index = index if index >= 0 else index + 1 + length

    next_node = self.get(index)
    if next_node:
        node = Node(data)
        pre_node = next_node.pre
        pre_node.next = node
        node.pre = pre_node
        node.next = next_node
        next_node.pre = node
        return node
        
"""删除节点"""
def delete(self, index):
    node = self.get(index)
    if node:
        node.pre.next = node.next
        node.next.pre = node.pre
        return True
    return False
    
"""反转链表"""
def __reversed__(self):
    """
    1.node.next --> node.pre
      node.pre --> node.next
    2.head.next --> None
      tail.pre --> None
    3.head-->tail
     tail-->head
    :return:
    """
    pre_head = self.head
    tail = self.tail

    def reverse(pre_node, node):
        if node:
            next_node = node.next
            node.next = pre_node
            pre_node.pre = node
            if pre_node is self.head:
                pre_node.next = None
            if node is self.tail:
                node.pre = None
            return reverse(node, next_node)
        else:
            self.head = tail
            self.tail = pre_head
    return reverse(self.head, self.head.next)

```
### 实现两个有序的链表合并为一个有序链表
```
class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 is None and l2 is None:
            return None
        elif l1 is not None and l2 is None:
            return l1
        elif l2 is not None and l1 is None:
            return l2

        l = []
        while l1 is not None:
            l.append(l1.val)
            l1 = l1.next
        while l2 is not None:
            l.append(l2.val)
            l2 = l2.next

        l = sorted(l)
        new_l = ListNode(l[0])
        head_l = new_l
        for i in range(1,len(l)):
            new_l.next = ListNode(l[i])
            new_l = new_l.next
        new_l.next = None
        return head_l
```
### 实现求链表的中间结点
```
import math
class Solution:
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # 首先要知道链表一共有多少个结点
        count = 0
        res = {}
        while head != None:
            count += 1
            res[count] = head
            head = head.next
        #j = math.ceil(count/2)
        #if count % 2 == 0:
        #    return res[j+1]
        #else:
        #    return res[j]
        j = math.ceil((count-1)/2) + 1
        return res[j]
```

# LeetCode

## 15三数之和

```
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()

        if (len(nums) >= 3) and (nums[0] == nums[len(nums) -1]) and (nums[0] == 0):
            return [[0, 0, 0]]

        result = []
        for index in range(len(nums) - 1):
        	left = index+1
        	right = len(nums) - 1

        	while left < right:
        		currSum = nums[index] + nums[left] + nums[right]
        		if currSum == 0:
        			result.append([nums[index], nums[left], nums[right]])
        			left += 1
        			right -= 1
        		elif currSum < 0:
        			left += 1
        		else:
        			right -= 1
        return  [list(t) for t in set(tuple(element) for element in result)]
```
##  169求众数

```
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
#       cnts = {}
#       for num in nums:
#           if num in cnts:
#               cnts[num] += 1 
#           else:
#               cnts[num] = 1
#           if cnts[num]> len(nums)/2:
#               return num
		vote = 0
    	majorNum = nums[0]
    	for num in nums:
            if vote>0:
            	if num == majorNum:
                	vote = vote + 1
            	else:
                	vote = vote - 1 
            if vote == 0:
                majorNum = num 
                vote = 1
                
        return majorNum
```
## 41缺失的第一个正数

```
class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        index_i = 0
        for index_j in range(len(nums)):
        	if nums[index_j] <= 0:
        		nums[index_i], nums[index_j] = nums[index_j], nums[index_i]
        		index_i += 1

        for index in range(index_i, len(nums)):
        	if abs(nums[index]) - 1 < len(nums) and nums[abs(nums[index]) - 1] > 0:
        		nums[abs(nums[index]) - 1] =  -nums[abs(nums[index]) - 1]

        for index in range(nums):
        	if nums[index] > 0:
        		return index + 1
        return len(nums) + 1
```
## 141环形链表

```
class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        
        if not head:
        	return False

        slow, fast = head,head
        while fast and fast.next:
        	slow = slow.next
        	fast = fast.next.next
        	if slow == fast:
        		return True
        return False
```
## 23合并k个排序链表

```
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """

        def merge2Lists(l1, l2):
        	head = point = ListNode(0)
        	while l1 and l2:
        		if l1.val <= l2.val:
        			point.next = ListNode(l1.val)
        			l1 = l1.next
        		else:
        			point.next = ListNode(l2.val)
        			l2 = l2.next
        		point = point.next

        	if l1:
        		point.next = l1
        	else:
        		point.next = l2
        	return head.next

        if not lists:
        	return lists

        interval = 1
        while interval < len(lists):
        	for index in range(0, len(lists) - interval ,interval*2):
        		lists[index] = merge2Lists(lists[index], lists[index+interval])

        	interval *= 2

        return lists[0]
```

https://github.com/facert/python-data-structure-cn
https://github.com/Jack-Lee-Hiter/AlgorithmsByPython
https://github.com/Jack-Lee-Hiter/AlgorithmsByPython/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84.md
https://www.yiibai.com/python/py_data_structure/python_linked_lists.html
https://blog.csdn.net/slibra_L/article/details/78177911
https://blog.csdn.net/u012505432/article/details/52071537
https://blog.csdn.net/weixin_41722370/article/details/83314501
http://pythonfiddle.com/leetcode169-majority-element/