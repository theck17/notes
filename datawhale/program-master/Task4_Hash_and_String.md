[TOC]
# 散列表（哈希表）
## 实现一个基于链表法解决冲突问题的散列表
```python
class BetterMap(object):
    def __init__(self,n=100):
        self.maps = []         
        for i in range(n):      
            self.maps.append(LinearMap())
    
    def find_map(self,k):       
        index = hash(k) % len(self.maps)
        return self.maps[index]     

    def add(self, k, v):
        m = self.find_map(k)        
        m.add(k,v)
    
    def get(self, k):
        m = self.find_map(k)
        return m.get(k)
```
## 实现一个 LRU 缓存淘汰算法
```python
import collections
class LRUCache:
    def __init__(self, capacity):
        self.capacity = capacity
        self.cache = collections.OrderedDict()

    def get(self, key):
        try:
            value = self.cache.pop(key)
            self.cache[key] = value
            return value
        except KeyError:
            return -1

    def set(self, key, value):
        try:
            self.cache.pop(key)
        except KeyError:
            if len(self.cache) >= self.capacity:
                self.cache.popitem(last=False)
        self.cache[key] = value
```
# 字符串
## 实现一个字符集，只包含 a～z 这 26 个英文字母的 Trie 树
```python
class Trie:
    root = {}
    END = '/'
    def add(self, word):
        #从根节点遍历单词,char by char,如果不存在则新增,最后加上一个单词结束标志
        node = self.root
        for c in word:
            node=node.setdefault(c,{})
        node[self.END] = None
 
    def find(self, word):
        node = self.root
        for c in word:
            if c not in node:
                return False
            node = node[c]
        return self.END in node

```
## 实现朴素的字符串匹配算法
```python
def matchingKMP(t,p,pnext):     #需要传入一个部分匹配表pnext
    i, j = 0, 0
    n, m = len(t), len(p)
    while i < n and j < m:
        if j == -1 or t[i] == p[j]: #如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i+1，j+1
            i, j = i+1, j+1
        else:                       #如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j] # next[j]即为j所对应的next值
            j = pnext[j]
        if j == m:                  # 找到匹配，返回索引值
            return i - j

    return -1                       # 无法匹配，返回-1

def genPNext0(p):
    j, k, m = 0, -1, len(p)
    pnext = [-1]*m
    while j < m-1:                  #生成pnext
        while k >= 0 and p[j] != p[k]:
            k = pnext[k]            
        j, k = j+1, k+1
        pnext[j] = k                #考虑前面

    return pnext

def genPNext(p):                    
    j, k, m = 0, -1, len(p)
    pnext = [-1]*m
    while j < m-1:                  #生成pnext
        while k >= 0 and p[j] != p[k]:
            k = pnext[k]            #设k = pnext[k]
        j, k = j+1, k+1
        if p[j] == p[k]:            #递推过程
            pnext[j] = pnext[k]
        else:
            pnext[j] = k            #next [j] = k 且 k > 0，表示下次匹配跳到j 之前的某个字符，而不是跳到开头，且具体跳过了k 个字符
    return pnext
```
# LeetCode
## LeetCode1
```python
class Solution(object):
    def twoSum(self, nums, target):
        hash_nums = {}
        for index, num in enumerate(nums):
        another = target - num
        try:
            hash_nums[another]
            return [hash_nums[another], index]
        except KeyError:
            hash_nums[num] = index
```
## LeetCode202
```python
class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        seen_numbers = set()
        while n > 1 and n not in seen_numbers:
            seen_numbers.add(n)
            n = sum(map(lambda x: int(x) * int(x), list(str(n))))
        return n == 1
```
## LeetCode344反转字符串
```python
class Solution(object):
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = list(s)
        for i in xrange(0, len(s)/2):
            tmp = s[i]
            s[i] = s[len(s)-1-i]
            s[len(s)-1-i] = tmp

        return ''.join(s)
```
## LeetCode151翻转字符串里的单词
```python
class Solution(object):
    def reverseWords(self, s):
        # remove tail space
        s = s.strip(' ')
        array_s = []
        last = ' '
        # remove multiple spaces
        for i in range(len(s)):
            if s[i] != ' ':
                array_s.append(s[i])
            else:
                if last != ' ':
                    array_s.append(s[i])
            last = s[i]
        array_s = array_s[::-1]
        ls, pos = len(array_s), 0
        for i in range(ls + 1):
            if i == ls or array_s[i] == ' ':
                self.reverse(array_s, pos, i)
                pos = i + 1
        return ''.join(array_s)

    def reverse(self, array_s, begin, end):
        for i in range((end - begin) / 2):
            array_s[begin + i], array_s[end - i - 1] = array_s[end - i - 1], array_s[begin + i]
```
## LeetCode8字符串转换整数(atoi)
```python
class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        sign = 1
        max_int, min_int = 2147483647, -2147483648
        result, pos = 0, 0
        ls = len(str)
        while pos < ls and str[pos] == ' ':
            pos += 1
        if pos < ls and str[pos] == '-':
            sign = -1
            pos += 1
        elif pos < ls and str[pos] == '+':
            pos += 1
        while pos < ls and ord(str[pos]) >= ord('0') and ord(str[pos]) <= ord('9'):
            num = ord(str[pos]) - ord('0')
            if result > max_int / 10 or ( result == max_int / 10 and num >= 8):
                if sign == -1:
                    return min_int
                return max_int
            result = result * 10 + num
            pos += 1
        return sign * result
```