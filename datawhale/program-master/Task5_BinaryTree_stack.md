[TOC]
# 二叉树
## 实现一个二叉查找树，并且支持插入、删除、查找操作
```python
class Node:
    def __init__(self, data):
        self.data = data
        self.lchild = None
        self.rchild = None
    
    # 搜索
    def search(self, node, parent, data):
        if node is None:
            return False, node, parent
        if node.data == data:
            return True, node, parent
        if node.data > data:
            return self.search(node.lchild, node, data)
        else:
            return self.search(node.rchild, node, data)

    # 插入
    def insert(self, data):
        flag, n, p = self.search(self.root, self.root, data)
        if not flag:
            new_node = Node(data)
            if data > p.data:
                p.rchild = new_node
            else:
                p.lchild = new_node
    # 删除
    def delete(self, root, data):
        flag, n, p = self.search(root, root, data)
        if flag is False:
            print "无该关键字，删除失败"
        else:
            if n.lchild is None:
                if n == p.lchild:
                    p.lchild = n.rchild
                else:
                    p.rchild = n.rchild
                del n
            elif n.rchild is None:
                if n == p.lchild:
                    p.lchild = n.lchild
                else:
                    p.rchild = n.lchild
                del n
            else:  # 左右子树均不为空
                pre = n.rchild
                if pre.lchild is None:
                    n.data = pre.data
                    n.rchild = pre.rchild
                    del pre
                else:
                    next = pre.lchild
                    while next.lchild is not None:
                        pre = next
                        next = next.lchild
                    n.data = next.data
                    pre.lchild = next.rchild
                    del next
```
## 实现查找二叉查找树中某个节点的后继、前驱节点
```python
    def successor(self, node):
        #node是二叉查找树中的一个节点
        curNode = node
        if curNode.right is not None:
            #右子树非空，返回右子树最左节点
            return self.minimun(curNode.right)
        else:
            #右子树为空，则返回“最低祖先”
            parNode = curNode.parent
            while parNode is not None and parNode.right == curNode:
                curNode = parNode
                parNode = parNode.parent
            return parNode
```
## 实现二叉树前、中、后序以及按层遍历
```python
    # 先序遍历
    def preOrderTraverse(self, node):
        if node is not None:
            print node.data,
            self.preOrderTraverse(node.lchild)
            self.preOrderTraverse(node.rchild)

    # 中序遍历
    def inOrderTraverse(self, node):
        if node is not None:
            self.inOrderTraverse(node.lchild)
            print node.data,
            self.inOrderTraverse(node.rchild)

    # 后序遍历
    def postOrderTraverse(self, node):
        if node is not None:
            self.postOrderTraverse(node.lchild)
            self.postOrderTraverse(node.rchild)
            print node.data,
```
## leetCode98验证二叉搜索树
```python
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
	        return True

        stack, result = [], []
        while stack or root:
        	if root:
        		stack.append(root)
        		root = root.left
        	else:
        		root = stack.pop()
        		result.append(root.val)
        		root = root.right

        previous = result[0]
        for index in range(1, len(result)):
        	if previous >= result[index]:
        		return False
        	previous = result[index]
        return True
```
# 堆
## 实现一个小顶堆、大顶堆、优先级队列
```python
    import sys
    import heapq

    class TopKHeap(object):
        def __init__(self, k):
            self.k = k
            self.data = []

        def push(self, elem):
            if len(self.data) < self.k:
                heapq.heappush(self.data, elem)
            else:
                topk_small = self.data[0]
                if elem > topk_small:
                    heapq.heapreplace(self.data, elem)
        def topk(self):
            return [x for x in reversed([heapq.heappop(self.data) for x in xrange(len(self.data))])]
    
    class MyHeap(object):
       def __init__(self, initial=None, key=lambda x:x):
           self.key = key
           if initial:
               self._data = [(key(item), item) for item in initial]
               heapq.heapify(self._data)
           else:
               self._data = []

       def push(self, item):
           heapq.heappush(self._data, (self.key(item), item))

       def pop(self):
           return heapq.heappop(self._data)[1]
```
## 实现堆排序
```python
import random

def MAX_Heapify(heap,HeapSize,root):
    #在堆中做结构调整使得父节点的值大于子节点
    left = 2*root + 1
    right = left + 1
    larger = root
    if left < HeapSize and heap[larger] < heap[left]:
        larger = left
    if right < HeapSize and heap[larger] < heap[right]:
        larger = right
    if larger != root:
    #如果做了堆调整则larger的值等于左节点或者右节点的，这个时候做对调值操作
        heap[larger],heap[root] = heap[root],heap[larger]
        MAX_Heapify(heap, HeapSize, larger)

def Build_MAX_Heap(heap):
#构造一个堆，将堆中所有数据重新排序
    HeapSize = len(heap)
    #将堆的长度当独拿出来方便
    for i in xrange((HeapSize -2)//2,-1,-1):
    #从后往前出数
        MAX_Heapify(heap,HeapSize,i)

def HeapSort(heap):
#将根节点取出与最后一位做对调，对前面len-1个节点继续进行对调整过程。
    Build_MAX_Heap(heap)
    for i in range(len(heap)-1,-1,-1):
        heap[0],heap[i] = heap[i],heap[0]
        MAX_Heapify(heap, i, 0)
    return heap
```
## 利用优先级队列合并 K 个有序数组
```python
def MergeSort(nums):
    if len(nums) <= 1:
        return nums
    #取中间位置
    mid = len(nums) // 2
    
    #此处实现递归
    #记住此处得到的也是多维数组
    Left = MergeSort(nums[:mid])
    
    Right = MergeSort(nums[mid:])

    #print(Left[0], Right[0])
    #要传入的参数是数组中第一个索引处的值
    return Sort_list(Left[0], Right[0])

def Sort_list(Left, Right):
    #存储排序后的值
    res = []
    a = 0
    b = 0

    while a < len(Left) and b < len(Right):
    
        if Left[a] < Right[b]:
            res.append(Left[a])
            a += 1
        else:
            res.append(Right[b])
            b += 1
    #因为存在一个到终点后，另一个还没到终点
    #这时就需要将没到终点的剩下的值添加到数组中
    while a < len(Left):
        res.append(Left[a])
        a += 1

    while b < len(Right):
        res.append(Right[b])
        b += 1
        #将一维数组二维化
    res = [res]

    return res
```
## 求一组动态数据集合的最大 Top K
```python
class solution:
    def topk(self, inputs, k):
        import heapq
        if inputs == None or len(inputs) < k or len(inputs) <= 0 or k <= 0:# 注意极限条件的确定
            return []
        output = []
        for number in inputs:
            if len(output) < k:
                output.append(number)
            else:
                output = heapq.nlargest(k, output)
                if number >= output[0]:
                    continue
                else:
                    output[0] = number
        return output[::-1]  
```
## leetCode226翻转二叉树
```python
class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if not root:
        	return None
        
        queue = [root]
        while queue:
        	node = queue.pop(0)
        	node.left, node.right = node.right, node.left
        	if node.left:
        		queue.append(node.left)
        	if node.right:
        		queue.append(node.right)

        return root
```
## leetCode104二叉树的最大深度
```python
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None:
            return 0
        return max(self.maxDepth(root.left),self.maxDepth(root.right)) + 1
```
## leetCode98验证二叉查找树
```python
class Solution(object):
    def isValidBST(self, root):
        self.List=[]
        self.left_root_right(root) #调用left_root_right()函数，中序遍历二叉搜索树，将节点的值存入列表List中
        for i in range(1,len(self.List)):
            if self.List[i]<=self.List[i-1]: #通过for循环遍历列表，若当前值少于或等于前一个值，则返回False
                return False
        return True 
    
    def left_root_right(self,root):
        if root==None:
            return 
        
        self.left_root_right(root.left) #中序遍历当前子树的左子树
        self.List.append(root.val) #将当前子树的根节点的值存入列表List中
        self.left_root_right(root.right)#中序遍历当前子树的右子树

```
## leetCode112路径总和
```python
class Solution(object):
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if not root:
        	return False

        if not root.left and not root.right and root.val == sum:
        	return True

        return self.hasPathSum(root.left, sum-root.val) or self.hasPathSum(root.right, sum-root.val)
```

