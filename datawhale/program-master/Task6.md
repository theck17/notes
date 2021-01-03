[TOC]

# 图
## 实现有向图、无向图、有权图、无权图的邻接矩阵和邻接表表示方法
```python
class Graph_Matrix:
    """
    Adjacency Matrix
    """
    def __init__(self, vertices=[], matrix=[]):
        """

        :param vertices:a dict with vertex id and index of matrix , such as {vertex:index}
        :param matrix: a matrix
        """
        self.matrix = matrix
        self.edges_dict = {}  # {(tail, head):weight}
        self.edges_array = []  # (tail, head, weight)
        self.vertices = vertices
        self.num_edges = 0

        # if provide adjacency matrix then create the edges list
        if len(matrix) > 0:
            if len(vertices) != len(matrix):
                raise IndexError
            self.edges = self.getAllEdges()
            self.num_edges = len(self.edges)

        # if do not provide a adjacency matrix, but provide the vertices list, build a matrix with 0
        elif len(vertices) > 0:
            self.matrix = [[0 for col in range(len(vertices))] for row in range(len(vertices))]

        self.num_vertices = len(self.matrix)

    def isOutRange(self, x):
        try:
            if x >= self.num_vertices or x <= 0:
                raise IndexError
        except IndexError:
            print("节点下标出界")

    def isEmpty(self):
        if self.num_vertices == 0:
            self.num_vertices = len(self.matrix)
        return self.num_vertices == 0

    def add_vertex(self, key):
        if key not in self.vertices:
            self.vertices[key] = len(self.vertices) + 1

        # add a vertex mean add a row and a column
        # add a column for every row
        for i in range(self.getVerticesNumbers()):
            self.matrix[i].append(0)

        self.num_vertices += 1

        nRow = [0] * self.num_vertices
        self.matrix.append(nRow)

    def getVertex(self, key):
        pass

    def add_edges_from_list(self, edges_list):  # edges_list : [(tail, head, weight),()]
        for i in range(len(edges_list)):
            self.add_edge(edges_list[i][0], edges_list[i][1], edges_list[i][2], )

    def add_edge(self, tail, head, cost=0):
        # if self.vertices.index(tail) >= 0:
        #   self.addVertex(tail)
        if tail not in self.vertices:
            self.add_vertex(tail)
        # if self.vertices.index(head) >= 0:
        #   self.addVertex(head)
        if head not in self.vertices:
            self.add_vertex(head)

        # for directory matrix
        self.matrix[self.vertices.index(tail)][self.vertices.index(head)] = cost
        # for non-directory matrix
        # self.matrix[self.vertices.index(fromV)][self.vertices.index(toV)] = \
        #   self.matrix[self.vertices.index(toV)][self.vertices.index(fromV)] = cost

        self.edges_dict[(tail, head)] = cost
        self.edges_array.append((tail, head, cost))
        self.num_edges = len(self.edges_dict)

    def getEdges(self, V):
        pass

    def getVerticesNumbers(self):
        if self.num_vertices == 0:
            self.num_vertices = len(self.matrix)
        return self.num_vertices

    def getAllVertices(self):
        return self.vertices

    def getAllEdges(self):
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix)):
                if 0 < self.matrix[i][j] < float('inf'):
                    self.edges_dict[self.vertices[i], self.vertices[j]] = self.matrix[i][j]
                    self.edges_array.append([self.vertices[i], self.vertices[j], self.matrix[i][j]])

        return self.edges_array

    def __repr__(self):
        return str(''.join(str(i) for i in self.matrix))

    def to_do_vertex(self, i):
        print('vertex: %s' % (self.vertices[i]))

    def to_do_edge(self, w, k):
        print('edge tail: %s, edge head: %s, weight: %s' % (self.vertices[w], self.vertices[k], str(self.matrix[w][k])))


def create_undirected_matrix(my_graph):
	nodes = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']

	matrix = [[0, 1, 1, 1, 1, 1, 0, 0],  # a
			  [0, 0, 1, 0, 1, 0, 0, 0],  # b
			  [0, 0, 0, 1, 0, 0, 0, 0],  # c
			  [0, 0, 0, 0, 1, 0, 0, 0],  # d
			  [0, 0, 0, 0, 0, 1, 0, 0],  # e
			  [0, 0, 1, 0, 0, 0, 1, 1],  # f
			  [0, 0, 0, 0, 0, 1, 0, 1],  # g
			  [0, 0, 0, 0, 0, 1, 1, 0]]  # h

	my_graph = Graph_Matrix(nodes, matrix)
	print(my_graph)
	return my_graph

def create_directed_matrix(my_graph):
	nodes = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']
	inf = float('inf')
	matrix = [[0, 2, 1, 3, 9, 4, inf, inf],  # a
			  [inf, 0, 4, inf, 3, inf, inf, inf],  # b
			  [inf, inf, 0, 8, inf, inf, inf, inf],  # c
			  [inf, inf, inf, 0, 7, inf, inf, inf],  # d
			  [inf, inf, inf, inf, 0, 5, inf, inf],  # e
			  [inf, inf, 2, inf, inf, 0, 2, 2],  # f
			  [inf, inf, inf, inf, inf, 1, 0, 6],  # g
			  [inf, inf, inf, inf, inf, 9, 8, 0]]  # h

	my_graph = Graph_Matrix(nodes, matrix)
	print(my_graph)
	return my_graph

def create_directed_graph_from_edges(my_graph):
	nodes = ['A', 'B', 'C', 'D', 'E', 'F', 'G']
	edge_list = [('A', 'F', 9), ('A', 'B', 10), ('A', 'G', 15), ('B', 'F', 2),
				 ('G', 'F', 3), ('G', 'E', 12), ('G', 'C', 10), ('C', 'E', 1),
				 ('E', 'D', 7)]

	my_graph = Graph_Matrix(nodes)
	my_graph.add_edges_from_list(edge_list)
	print(my_graph)

	# my_graph.DepthFirstSearch()
	#
	# draw_directed_graph(my_graph)

	return my_graph



def draw_undircted_graph(my_graph):
	G = nx.Graph()  # 建立一个空的无向图G
	for node in my_graph.vertices:
		G.add_node(str(node))
	for edge in my_graph.edges:
		G.add_edge(str(edge[0]), str(edge[1]))

	print("nodes:", G.nodes())  # 输出全部的节点
	print("edges:", G.edges())  # 输出全部的边
	print("number of edges:", G.number_of_edges())  # 输出边的数量
	nx.draw(G, with_labels=True)
	plt.savefig("undirected_graph.png")
	plt.show()


def draw_directed_graph(my_graph):
	G = nx.DiGraph()  # 建立一个空的无向图G
	for node in my_graph.vertices:
		G.add_node(str(node))
	# for edge in my_graph.edges:
	# G.add_edge(str(edge[0]), str(edge[1]))
	G.add_weighted_edges_from(my_graph.edges_array)

	print("nodes:", G.nodes())  # 输出全部的节点
	print("edges:", G.edges())  # 输出全部的边
	print("number of edges:", G.number_of_edges())  # 输出边的数量
	nx.draw(G, with_labels=True)
	plt.savefig("directed_graph.png")
	plt.show()


if __name__ == '__main__':
	my_graph = Graph_Matrix()
	# created_graph = create_undirected_matrix(my_graph)
	created_graph = create_directed_matrix(my_graph)
	# created_graph = create_directed_graph_from_edges(my_graph)

	# draw_undircted_graph(created_graph)
	draw_directed_graph(created_graph)
```
## 实现图的深度优先搜索、广度优先搜索
### 深度优先算法：
* 访问初始顶点v并标记顶点v已访问。
* 查找顶点v的第一个邻接顶点w。
* 若顶点v的邻接顶点w存在，则继续执行；否则回溯到v，再找v的另外一个未访问过的邻接点。
* 若顶点w尚未被访问，则访问顶点w并标记顶点w为已访问。
* 继续查找顶点w的下一个邻接顶点wi，如果v取值wi转到步骤（3）。直到连通图中所有顶点全部访问过为止。

### 广度优先算法：
* 顶点v入队列。
* 当队列非空时则继续执行，否则算法结束。
* 出队列取得队头顶点v；访问顶点v并标记顶点v已被访问。
* 查找顶点v的第一个邻接顶点col。
* 若v的邻接顶点col未被访问过的，则col入队列。
* 继续查找顶点v的另一个新的邻接顶点col，转到步骤（5）。直到顶点v的所有未被访问过的邻接点处理完。转到步骤（2）。
```python
# -*- coding:utf-8 -*-\
# *args 把参数打包成tuple供函数调用。**kwargs把 x = a，y=b打包成字典{x:a,y:b}供函数调用
class Graph(object):
    def __init__(self, *args, **kwargs):
        self.node_neighbors = {}
        self.visited = {}
 
    def add_nodes(self, nodelist):
 
        for node in nodelist:
            self.add_node(node)
 
    def add_node(self, node):
        if not node in self.nodes():
            self.node_neighbors[node] = []
 
    def add_edge(self, edge):
        u, v = edge
        if (v not in self.node_neighbors[u]) and (u not in self.node_neighbors[v]):
            self.node_neighbors[u].append(v)
 
            if (u != v):
                self.node_neighbors[v].append(u)
 
    def nodes(self):
        return self.node_neighbors.keys()
 
    #递归DFS
    def depth_first_search(self,root=None):
        order=[]
        def dfs(node):
            self.visited[node] = True
            order.append(node)
            for n in self.node_neighbors[node]:
                if not n in self.visited:
                    dfs(n)
 
        if root:
            dfs(root)
 
        #对于不连通的结点（即dfs（root）完仍是没有visit过的单独处理，再做一次dfs
        for node in self.nodes():
            if not node in self.visited:
                dfs(node)
        self.visited = {}
        print order
        return order
 
    #非递归DFS
    def depth_first_search2(self,root=None):
        stack = []
        order = []
        #self.visited[root] = True
        def dfs():
            while stack:
                node = stack[-1]
                for n in self.node_neighbors[node]:
                    if not n in self.visited:
                        order.append(n)
                        stack.append(n)
                        self.visited[n] = True
                        break
                else:
                    stack.pop()
        if root:
            stack.append(root)
            order.append(root)
            self.visited[root]=True
            dfs()
 
        for node in self.nodes():
            if node not in self.visited:
                stack.append(node)
                order.append(node)
                self.visited[node]=True
                dfs()
 
        self.visited = {}
        print order
        return order
 
    def breadth_first_search(self,root=None):
        queue = []
        order = []
        def bfs():
            while len(queue)>0:
                node = queue.pop(0)
                self.visited[node] = True
                for n in self.node_neighbors[node]:
                    if (not n in self.visited) and (not n in queue):
                        queue.append(n)
                        order.append(n)
 
        if root:
            queue.append(root)
            order.append(root)
            bfs()
 
        for node in self.nodes():
            if not node in self.visited:
                queue.append(node)
                order.append(node)
                bfs()
 
        self.visited = {}
        print order
        return order
 
if __name__ == '__main__':
    g = Graph()
    g.add_nodes([i + 1 for i in range(8)])
    g.add_edge((1, 2))
    g.add_edge((1, 3))
    g.add_edge((2, 4))
    g.add_edge((2, 5))
    g.add_edge((4, 8))
    g.add_edge((5, 8))
    g.add_edge((3, 6))
    g.add_edge((3, 7))
    g.add_edge((6, 7))
    print "nodes:", g.nodes()
 
    print "BFS："
    order = g.breadth_first_search(1)
    # self.visited 在经历了一次bfs之后已经有了值，如果dfs直接进行，就会发生只输出结点1的情况
    print "递归DFS："
    order = g.depth_first_search(1)
    print "非递归DFS"
    order = g.depth_first_search2(1)

```

## 实现 Dijkstra 算法、A* 算法
```python
import json
def dijkstra(graph,src):
    if graph ==None:
        return None
    # 定点集合
    nodes = [i for i in range(len(graph))] # 获取顶点列表，用邻接矩阵存储图
    # 顶点是否被访问
    visited = []
    visited.append(src)
    # 初始化dis
    dis = {src:0}# 源点到自身的距离为0
    for i in nodes:
        dis[i] = graph[src][i]
    path={src:{src:[]}}  # 记录源节点到每个节点的路径
    k=pre=src

    while nodes:
        temp_k = k
        mid_distance=float('inf') # 设置中间距离无穷大
        for v in visited:
            for d in nodes:
                if graph[src][v] != float('inf') and graph[v][d] != float('inf'):# 有边
                    new_distance = graph[src][v]+graph[v][d]
                    if new_distance <= mid_distance:
                        mid_distance=new_distance
                        graph[src][d]=new_distance  # 进行距离更新
                        k=d
                        pre=v
        if k!=src and temp_k==k:
            break
        dis[k]=mid_distance  # 最短路径
        path[src][k]=[i for i in path[src][pre]]
        path[src][k].append(k)

        visited.append(k)
        nodes.remove(k)
        print(nodes)
    return dis,path

if __name__ == '__main__':
    # 输入的有向图,有边存储的就是边的权值，无边就是float('inf')，顶点到自身就是0
    graph = [ 
        [0, float('inf'), 10, float('inf'), 30, 100],
        [float('inf'), 0, 5, float('inf'), float('inf'), float('inf')],
        [float('inf'), float('inf'), 0, 50, float('inf'), float('inf')],
        [float('inf'), float('inf'), float('inf'), 0, float('inf'), 10],
        [float('inf'), float('inf'), float('inf'), 20, 0, 60],
        [float('inf'), float('inf'), float('inf'), float('inf'), float('inf'), 0]]

    dis,path= dijkstra(graph, 0)  # 查找从源点0开始带其他节点的最短路径
    print(dis)
    print(json.dumps(path, indent=4))
```
## 实现拓扑排序的 Kahn 算法、DFS 算法
```python
def topological_sort( graph ):
 
    is_visit = dict( ( node, False ) for node in graph )
    li = []
 
    def dfs( graph, start_node ):
        
        for end_node in graph[start_node]:
            if not is_visit[end_node]:
                is_visit[end_node] = True
                dfs( graph, end_node )
        li.append( start_node )
    
    for start_node in graph:
        if not is_visit[start_node]:
            is_visit[start_node] = True
            dfs( graph, start_node )
 
    li.reverse()
    return li
    
            
if __name__ == '__main__':
    graph = {
        'v1': ['v5'],
        'v2': ['v1'],
        'v3': ['v1', 'v5'],
        'v4': ['v2', 'v5'],
        'v5': [],
    }
    li = topological_sort( graph )
    print li

```
# LeetCode
## LeetCode200 Number of Islands（岛屿的个数）
```python
class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if not grid:
        	return 0

        count = 0
        for row in range(len(grid)):
        	for col in range(len(grid[0])):
        		if grid[row][col] == '1':
        			count +=1
        			self.merge(grid, row, col)

        return count

    def merge(self, grid, row, col):
    	if 0 > row or row >= len(grid) or col < 0 or col >= len(grid[0]):
    		return

    	if grid[row][col] != '1':
    		return 

    	grid[row][col] = '#'
    	self.merge(grid, row+1, col)
    	self.merge(grid, row-1, col)
    	self.merge(grid, row, col+1)
    	self.merge(grid, row, col-1)
```
## LeetCode36 Sudoku（有效的数独）
```python
class Solution(object):
    def isValidSudoku(self, board):
        s=set()
        list=board
        for i in range(9):
            for j in range(9):
                if list[i][j] in s:
                    return False
                if list[i][j]!='.':
                    s.add(list[i][j])
            s = set()
        for i in range(9):
            for j in range(9):
                if list[j][i] in s:
                    return False
                if list[j][i]!='.':
                    s.add(list[j][i])
            s = set()
        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                for m in range(i, i + 3):
                    for n in range(j, j + 3):
                        if list[m][n] in s:
                            return False
                        if list[m][n] != '.':
                            s.add(list[m][n])
                s = set()
        return True

```