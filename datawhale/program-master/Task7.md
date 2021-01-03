[TOC]
# 递归
## LeetCode70
```
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
# 回溯
## 利用回溯算法求解八皇后问题
```
def place(x, k): #判断是否冲突
    for i in range(1, k):
        #x[i] == x[k]判断是否为同一行
        # abs(x[i] - x[k]) == abs(i - k)判断是否在k个的对角线上
        if x[i] == x[k] or abs(x[i] - x[k]) == abs(i - k):
            return False
    return True
def queens(n):
    k = 1    #设置初始皇后为第一个
    x = [0 for row in range(n + 1)]# 设置x列表初始值为0
    while k > 0:
        x[k] = x[k] + 1 # 在当前列的下一列开始
        while (x[k] <= n) and (not place(x, k)): # 不满足条件，继续搜索下一列位置
            x[k] = x[k] + 1
        if x[k] <= n:# 判断是否为最后一个，不是就执行下一行
            if k == n:# 是最后一个皇后，退出
                break
            else: # 不是，则处理下一行皇后
                k = k + 1   #执行下一行
                x[k] = 0    #初始化，从第一列开始
        else:#n列均不满足，回溯到上一行
            x[k] = 0    #初始化列到第一列
            k = k - 1   #回溯到上一行
    return x[1:]    #返回1-8个皇后的位置
print(queens(8))

```
## 利用回溯算法求解 0-1 背包问题
```
bestV=0
curW=0
curV=0
bestx=None
 
def backtrack(i):
	global bestV,curW,curV,x,bestx
	if i>=n:
		if bestV<curV:
			bestV=curV
			bestx=x[:]
	else:
		if curW+w[i]<=c:
			x[i]=True
			curW+=w[i]
			curV+=v[i]
			backtrack(i+1)
			curW-=w[i]
			curV-=v[i]
		x[i]=False
		backtrack(i+1)
	
 
if __name__=='__main__':
	n=5
	c=10
	w=[2,2,6,5,4]
	v=[6,3,5,4,6]
	x=[False for i in range(n)]
	backtrack(0)
	print(bestV)
	print(bestx)
```
# 分治
## 利用分治算法求一组数据的逆序对个数
```
def InversionNum(lst):
    # 改写归并排序,在归并排序中，每当R部分元素先于L部分元素插入原列表时，逆序对数要加L剩余元素数
    if len(lst) == 1:
        return lst,0
    else:
        n = len(lst) // 2
        lst1,count1 = InversionNum(lst[0:n])
        lst2,count2 = InversionNum(lst[n:len(lst)])
        lst,count = Count(lst1,lst2,0)
        return lst,count1+count2+count
 
def Count(lst1, lst2,count): 
    i = 0
    j = 0
    res = []
    while i < len(lst1) and j < len(lst2):
        if lst1[i] <= lst2[j]:
            res.append(lst1[i])
            i += 1
        else:
            res.append(lst2[j])
            count += len(lst1)-i # 当右半部分的元素先于左半部分元素进入有序列表时，逆序对数量增加左半部分剩余的元素数
            j += 1
    res += lst1[i:]
    res += lst2[j:]
    return res,count
 
 
print(InversionNum([11,10,9,8,7,6,5,4,3,2,1]))  # 输出为：[1,2,3,4,5,6,7,8,9,10,11] 55
```
# 动态规划
## 编程实现莱文斯坦最短编辑距离
```
# 这里的实现过程对算法进行了稍微的优化(运算结果应该稍快一些)：首先计算两个字符串开头以及结尾
# 的共同字符子串，然后去掉相同部分，重新构造新字符串，减少迭代过程次数。
# 如：string_a = "GGATCGA" string_b = "GAATTCAGTTA"构造的新字符串为：
# new_a = "AATTCAGTT" new_b = "GATCG" 

def LD(string_a, string_b):
    diff_start = -1
    diff_end = -1
    len_a = len(string_a)
    len_b = len(string_b)
    short = min(len_a, len_b)

    # 寻找开头和结尾的共同字符串，并记录位置
    for i in range(0, short):
        if string_a[i] != string_b[i]:
            diff_start = i
            break
    if diff_start == -1:
        return abs(len_b - len_a)
    for i in range(0, short):
        if string_a[len_a - i -1] != string_b[len_b - i - 1]:
            diff_end = i
            break
    if diff_end == -1:
        return abs(len_b - len_a)

    # L(A+C, B+C) = LD(A, B)
    # 出去开头以及结尾相同的字符串，构建新的字符串
    long_str = unicode(string_a[diff_start: len_a - diff_end] if len_a >= len_b else string_b[diff_start: len_b - diff_end])
    short_str = unicode(string_a[diff_start: len_a - diff_end] if len_a < len_b else string_b[diff_start: len_b - diff_end])
    # print long_str
    # print short_str

    long_len = len(long_str)
    short_len = len(short_str)

    # store保存迭代过程中每次计算的结果
    store = range(0, long_len + 1)

    for i in range(short_len):
        temp = [i+1] * (long_len + 1)
        for j in range(long_len):
            if long_str[j] == short_str[i]:
                temp[j+1] = store[j]
            else:
                # 注意这时各个位置数据的对应关系
                temp[j+1] = min(store[j], store[j+1], temp[j]) + 1
        store = temp
        # print store
    # 最右下角即为编辑距离
    return store[-1]


# Test
string_a = "GGATCGA"
string_b = "GAATTCAGTTA"

ld = LD(string_a, string_b)
print ld
```
## 编程实现查找两个字符串的最长公共子序列
```
import numpy
def find_lcseque(s1, s2): 
	 # 生成字符串长度加1的0矩阵，m用来保存对应位置匹配的结果
	m = [ [ 0 for x in range(len(s2)+1) ] for y in range(len(s1)+1) ] 
	# d用来记录转移方向
	d = [ [ None for x in range(len(s2)+1) ] for y in range(len(s1)+1) ] 
 
	for p1 in range(len(s1)): 
		for p2 in range(len(s2)): 
			if s1[p1] == s2[p2]:            #字符匹配成功，则该位置的值为左上方的值加1
				m[p1+1][p2+1] = m[p1][p2]+1
				d[p1+1][p2+1] = 'ok'          
			elif m[p1+1][p2] > m[p1][p2+1]:  #左值大于上值，则该位置的值为左值，并标记回溯时的方向
				m[p1+1][p2+1] = m[p1+1][p2] 
				d[p1+1][p2+1] = 'left'          
			else:                           #上值大于左值，则该位置的值为上值，并标记方向up
				m[p1+1][p2+1] = m[p1][p2+1]   
				d[p1+1][p2+1] = 'up'         
	(p1, p2) = (len(s1), len(s2)) 
	print numpy.array(d)
	s = [] 
	while m[p1][p2]:    #不为None时
		c = d[p1][p2]
		if c == 'ok':   #匹配成功，插入该字符，并向左上角找下一个
			s.append(s1[p1-1])
			p1-=1
			p2-=1 
		if c =='left':  #根据标记，向左找下一个
			p2 -= 1
		if c == 'up':   #根据标记，向上找下一个
			p1 -= 1
	s.reverse() 
	return ''.join(s) 
 
print find_lcseque('abdfg','abcdfg')
```
## 编程实现一个数据序列的最长递增子序列
```
class myStack:
    #找出以元素i结尾的最长递增子序列
    #每一次为ｉ进行分配时，要检查前面所有的算法ai(i<x)
    #若ai小于ax，则说明ax可以跟在ai后形成一个新的递增子序列
    #否则，以ax结尾的递增子序列的最长长度为1
    def getHeight(self, men, n):
        longest = {}    #c存一个字典
        longest[0] = 1
        for i in range(1, len(men)):
            maxlen = -1
            for j in range(0, i):
                if men[i]>men[j] and maxlen<longest[j]:
                    maxlen = longest[j]
            if maxlen>=1:    #说明之前的递增序列中，有ax可以跟的
                longest[i] = maxlen +1
            else:
                longest[i] = 1
        return max(longest.values())

```
# LeetCode
## LeetCode17
```
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        
        phoneMap = { '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7' : 'pqrs', '8': 'tuv', '9':'wxyz'}
        number = str(digits)

        if number == "":
        	return []

        result = ['']
        for char in number:
        	values = phoneMap[char]
        	new_result = []
        	for prefix in result:
        		currElement = prefix
        		for value in values:
        			new_result.append(currElement+value)

        	result = new_result
        	# result = [prefix+value for prefix in result for value in values]
        return result

print Solution().letterCombinations("23")
```
## LeetCode46
```
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        if len(nums) == 0:
        	return []
        if len(nums) == 1:
        	return [nums]

        result = []
        for index in range(len(nums)):
        	for p in self.permute(nums[0:index] + nums[index+1:]):
        		result.append([nums[index]] + p)

        return result
```
## LeetCode132
```
class Solution(object):
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
        	return 0

        P = [[False for _ in range(len(s))] for _  in range(len(s))]
        cuts = [0 for _ in range(len(s))]

        for index in range(len(s)):
        	P[index][index] = True

        for length in range(2, len(s)+1):
        	for i in range(len(s)-length+1):
        		j = i+length - 1

        		if length == 2:
        			P[i][j] = s[i] == s[j]
        		else:
        			P[i][j] = (s[i] ==  s[j]) and P[i+1][j-1]

        for index in range(len(s)):
        	if P[0][index]:
        		cuts[index] = 0
        	else:
        		cuts[index] = float('inf')
        		for j in range(index):
        			if P[j+1][index] and (cuts[index] > 1 + cuts[j]):
        				cuts[index] = 1+cuts[j]

        return cuts[len(s)-1]
```
## LeetCode10 Regular Expression Matching
```
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        dp = [[False for _ in range(len(p) + 1)] for _ in range(len(s) + 1)]
        dp[0][0] = True

 		for index in range(1, len(dp[0])):
            if p[index-1] == '*':
                dp[0][index] = dp[0][index - 2]
                
        for index_i in range(1, len(dp)):
        	for index_j in range(1, len(dp[0])):
        		if s[index_i - 1] == p[index_j - 1] or p[index_j - 1] == '.':
        			dp[index_i][index_j] = dp[index_i-1][index_j-1]
        		elif p[index_j-1] == '*':
        			dp[index_i][index_j] = dp[index_i][index_j-2]

        			if s[index_i-1] == p[index_j-2] or p[index_j-2] == '.':
        				dp[index_i][index_j] = dp[index_i-1][index_j] or dp[index_i][index_j]

        		else:
        			dp[index_i][index_j] = False


        return dp[len(s)][len(p)]
```
## LeetCode64 Minimum Path Sum
```
class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid:
        	return 0

        row, col = len(grid), len(grid[0])
        dp = [[0 for _ in range(col)] for _ in range(row)]
        dp[0][0] = grid[0][0]

        for index in range(1, row):
        	dp[index][0] = dp[index-1][0] + grid[index][0]

        for index in range(1, col):
        	dp[0][index] = dp[0][index-1] + grid[0][index]

        print dp
        for index_i in range(1, row):
        	for index_j in range(1, col):
        		dp[index_i][index_j] = min(dp[index_i-1][index_j], dp[index_i][index_j-1]) + grid[index_i][index_j]

        return dp[row-1][col-1]
```
## LeetCode322 Coin Change
```
class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        if not coins:
        	return 0

        dp = [float('inf') for _ in range(amount+1)]
        dp[0] = 0

        for val in range(1, amount+1):
        	for coin in coins:
        		if coin <= val:
        			dp[val] = min(dp[val-coin]+1, dp[val])
        return dp[amount] if dp[amount] != float('inf') else -1
```
## LeetCode121 Best Time to Buy and Sell Stock
```
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) == 0:
            return 0
        minPrice = prices[0]
        dp = [0] * len(prices)
        for i in xrange(0, len(prices)):
            dp[i] = max(dp[i-1], prices[i] - minPrice)
            minPrice = min(minPrice, prices[i])
        return dp[-1]
```
## LeetCode152 Maximum Product Subarray
```
class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        if not nums:
        	return 0

        max_so_far, min_so_far, result = nums[0], nums[0], nums[0]

        for index in range(1, len(nums)):
        	if nums[index] > 0:
        		max_so_far = max(max_so_far*nums[index], nums[index])
        		min_so_far = min(min_so_far*nums[index], nums[index])
        	else:
        		temp = max_so_far
        		max_so_far = max(min_so_far*nums[index], nums[index])
        		min_so_far = min(temp*nums[index], nums[index])

        	result = max(result, max_so_far)
        return result
```
## LeetCode120 Triangle
```
class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        length = len(triangle)
        columns = len(triangle[length-1])
        
        matrix = [[ 0 for col in range(columns)] for row in range(length)]
        row_index = 0
        
        for row in range(length):
            elements = triangle[row]
            col_index = 0
            
            for val in elements:
                matrix[row_index][col_index] = val
                col_index += 1
            row_index += 1
            
        for row in range(length-2, -1, -1):
            for col in range(row+1):
                matrix[row][col] += min(matrix[row+1][col+1], matrix[row+1][col])
        return matrix[0][0]
```