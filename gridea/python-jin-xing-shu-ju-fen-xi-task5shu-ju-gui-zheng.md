---
title: 'Python进行数据分析task5：数据规整'
date: 2019-07-09 15:42:37
tags: [Data Analysis]
published: true
hideInList: false
feature: /post-images/python-jin-xing-shu-ju-fen-xi-task5shu-ju-gui-zheng.png
---


```python
# 层次化索引
import pandas as pd
data = pd.Series(np.random.randn(9),
                 index=[['a', 'a', 'a', 'b', 'b', 'c', 'c', 'd', 'd'], 
                 [1, 2, 3, 1, 3, 1, 2, 2, 3]])
data
```



```
a  1   -0.804807
   2   -0.968349
   3   -1.530875
b  1   -0.020642
   3    0.898301
c  1    0.597119
   2    2.274233
d  2    1.235025
   3   -0.252788
dtype: float64
```



```python
data.index
```



```
MultiIndex(levels=[['a', 'b', 'c', 'd'], [1, 2, 3]],
           labels=[[0, 0, 0, 1, 1, 2, 2, 3, 3], [0, 1, 2, 0, 2, 0, 1, 1, 2]])
```



```python
data['b']
```



```
1   -0.020642
3    0.898301
dtype: float64
```



```python
data['b':'c']
```



```
b  1   -0.020642
   3    0.898301
c  1    0.597119
   2    2.274233
dtype: float64
```



```python
data.loc[['b', 'd']]

```



```
b  1   -0.020642
   3    0.898301
d  2    1.235025
   3   -0.252788
dtype: float64

```



```python
data.loc[:, 2]

```



```
a   -0.968349
c    2.274233
d    1.235025
dtype: float64

```



```python
# 可以通过 unstack 方法将这段数据重新安排到一个 DataFrame 中
data.unstack()

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>1</th>
      <th>2</th>
      <th>3</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>a</th>
      <td>-0.804807</td>
      <td>-0.968349</td>
      <td>-1.530875</td>
    </tr>
    <tr>
      <th>b</th>
      <td>-0.020642</td>
      <td>NaN</td>
      <td>0.898301</td>
    </tr>
    <tr>
      <th>c</th>
      <td>0.597119</td>
      <td>2.274233</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>d</th>
      <td>NaN</td>
      <td>1.235025</td>
      <td>-0.252788</td>
    </tr>
  </tbody>
</table>

</div>



```python
data.unstack().stack()# unstack 的逆运算是 stack

```



```
a  1   -0.804807
   2   -0.968349
   3   -1.530875
b  1   -0.020642
   3    0.898301
c  1    0.597119
   2    2.274233
d  2    1.235025
   3   -0.252788
dtype: float64

```



```python
frame = pd.DataFrame(np.arange(12).reshape((4, 3)),
                     index=[['a', 'a', 'b', 'b'], [1, 2, 1, 2]], 
                     columns=[['Ohio', 'Ohio', 'Colorado'],
                    ['Green', 'Red', 'Green']]) 
frame 

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead tr th {
    text-align: left;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr>
      <th></th>
      <th></th>
      <th colspan="2" halign="left">Ohio</th>
      <th>Colorado</th>
    </tr>
    <tr>
      <th></th>
      <th></th>
      <th>Green</th>
      <th>Red</th>
      <th>Green</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th rowspan="2" valign="top">a</th>
      <th>1</th>
      <td>0</td>
      <td>1</td>
      <td>2</td>
    </tr>
    <tr>
      <th>2</th>
      <td>3</td>
      <td>4</td>
      <td>5</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">b</th>
      <th>1</th>
      <td>6</td>
      <td>7</td>
      <td>8</td>
    </tr>
    <tr>
      <th>2</th>
      <td>9</td>
      <td>10</td>
      <td>11</td>
    </tr>
  </tbody>
</table>

</div>



```python
frame.index.names = ['key1', 'key2']
frame.columns.names = ['state', 'color']
frame 

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead tr th {
    text-align: left;
}

.dataframe thead tr:last-of-type th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr>
      <th></th>
      <th>state</th>
      <th colspan="2" halign="left">Ohio</th>
      <th>Colorado</th>
    </tr>
    <tr>
      <th></th>
      <th>color</th>
      <th>Green</th>
      <th>Red</th>
      <th>Green</th>
    </tr>
    <tr>
      <th>key1</th>
      <th>key2</th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th rowspan="2" valign="top">a</th>
      <th>1</th>
      <td>0</td>
      <td>1</td>
      <td>2</td>
    </tr>
    <tr>
      <th>2</th>
      <td>3</td>
      <td>4</td>
      <td>5</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">b</th>
      <th>1</th>
      <td>6</td>
      <td>7</td>
      <td>8</td>
    </tr>
    <tr>
      <th>2</th>
      <td>9</td>
      <td>10</td>
      <td>11</td>
    </tr>
  </tbody>
</table>

</div>



```python
frame['Ohio']

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>color</th>
      <th>Green</th>
      <th>Red</th>
    </tr>
    <tr>
      <th>key1</th>
      <th>key2</th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th rowspan="2" valign="top">a</th>
      <th>1</th>
      <td>0</td>
      <td>1</td>
    </tr>
    <tr>
      <th>2</th>
      <td>3</td>
      <td>4</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">b</th>
      <th>1</th>
      <td>6</td>
      <td>7</td>
    </tr>
    <tr>
      <th>2</th>
      <td>9</td>
      <td>10</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.MultiIndex.from_arrays([['Ohio', 'Ohio', 'Colorado'], 
                        ['Green','Red', 'Green']],                        
                       names=['state', 'color'])

```



```
MultiIndex(levels=[['Colorado', 'Ohio'], ['Green', 'Red']],
           labels=[[1, 1, 0], [0, 1, 0]],
           names=['state', 'color'])

```



```python
# 重排与分级排序
frame.swaplevel('key1', 'key2')

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead tr th {
    text-align: left;
}

.dataframe thead tr:last-of-type th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr>
      <th></th>
      <th>state</th>
      <th colspan="2" halign="left">Ohio</th>
      <th>Colorado</th>
    </tr>
    <tr>
      <th></th>
      <th>color</th>
      <th>Green</th>
      <th>Red</th>
      <th>Green</th>
    </tr>
    <tr>
      <th>key2</th>
      <th>key1</th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>1</th>
      <th>a</th>
      <td>0</td>
      <td>1</td>
      <td>2</td>
    </tr>
    <tr>
      <th>2</th>
      <th>a</th>
      <td>3</td>
      <td>4</td>
      <td>5</td>
    </tr>
    <tr>
      <th>1</th>
      <th>b</th>
      <td>6</td>
      <td>7</td>
      <td>8</td>
    </tr>
    <tr>
      <th>2</th>
      <th>b</th>
      <td>9</td>
      <td>10</td>
      <td>11</td>
    </tr>
  </tbody>
</table>

</div>



```python
frame.sort_index(level=1) 

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead tr th {
    text-align: left;
}

.dataframe thead tr:last-of-type th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr>
      <th></th>
      <th>state</th>
      <th colspan="2" halign="left">Ohio</th>
      <th>Colorado</th>
    </tr>
    <tr>
      <th></th>
      <th>color</th>
      <th>Green</th>
      <th>Red</th>
      <th>Green</th>
    </tr>
    <tr>
      <th>key1</th>
      <th>key2</th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>a</th>
      <th>1</th>
      <td>0</td>
      <td>1</td>
      <td>2</td>
    </tr>
    <tr>
      <th>b</th>
      <th>1</th>
      <td>6</td>
      <td>7</td>
      <td>8</td>
    </tr>
    <tr>
      <th>a</th>
      <th>2</th>
      <td>3</td>
      <td>4</td>
      <td>5</td>
    </tr>
    <tr>
      <th>b</th>
      <th>2</th>
      <td>9</td>
      <td>10</td>
      <td>11</td>
    </tr>
  </tbody>
</table>

</div>



```python
frame.swaplevel(0, 1).sort_index(level=0)

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead tr th {
    text-align: left;
}

.dataframe thead tr:last-of-type th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr>
      <th></th>
      <th>state</th>
      <th colspan="2" halign="left">Ohio</th>
      <th>Colorado</th>
    </tr>
    <tr>
      <th></th>
      <th>color</th>
      <th>Green</th>
      <th>Red</th>
      <th>Green</th>
    </tr>
    <tr>
      <th>key2</th>
      <th>key1</th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th rowspan="2" valign="top">1</th>
      <th>a</th>
      <td>0</td>
      <td>1</td>
      <td>2</td>
    </tr>
    <tr>
      <th>b</th>
      <td>6</td>
      <td>7</td>
      <td>8</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">2</th>
      <th>a</th>
      <td>3</td>
      <td>4</td>
      <td>5</td>
    </tr>
    <tr>
      <th>b</th>
      <td>9</td>
      <td>10</td>
      <td>11</td>
    </tr>
  </tbody>
</table>

</div>



```python
# 根据级别汇总统计
frame.sum(level='key2')

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead tr th {
    text-align: left;
}

.dataframe thead tr:last-of-type th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr>
      <th>state</th>
      <th colspan="2" halign="left">Ohio</th>
      <th>Colorado</th>
    </tr>
    <tr>
      <th>color</th>
      <th>Green</th>
      <th>Red</th>
      <th>Green</th>
    </tr>
    <tr>
      <th>key2</th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>1</th>
      <td>6</td>
      <td>8</td>
      <td>10</td>
    </tr>
    <tr>
      <th>2</th>
      <td>12</td>
      <td>14</td>
      <td>16</td>
    </tr>
  </tbody>
</table>

</div>



```python
frame.sum(level='color', axis=1)

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>color</th>
      <th>Green</th>
      <th>Red</th>
    </tr>
    <tr>
      <th>key1</th>
      <th>key2</th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th rowspan="2" valign="top">a</th>
      <th>1</th>
      <td>2</td>
      <td>1</td>
    </tr>
    <tr>
      <th>2</th>
      <td>8</td>
      <td>4</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">b</th>
      <th>1</th>
      <td>14</td>
      <td>7</td>
    </tr>
    <tr>
      <th>2</th>
      <td>20</td>
      <td>10</td>
    </tr>
  </tbody>
</table>

</div>



```python
# 使用 DataFrame 的列进行索引
frame = pd.DataFrame({'a': range(7), 
                      'b': range(7, 0, -1),  
                      'c': ['one', 'one', 'one', 'two', 'two', 'two', 'two'], 
                      'd': [0, 1, 2, 0, 1, 2, 3]})
frame 

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>a</th>
      <th>b</th>
      <th>c</th>
      <th>d</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>0</td>
      <td>7</td>
      <td>one</td>
      <td>0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1</td>
      <td>6</td>
      <td>one</td>
      <td>1</td>
    </tr>
    <tr>
      <th>2</th>
      <td>2</td>
      <td>5</td>
      <td>one</td>
      <td>2</td>
    </tr>
    <tr>
      <th>3</th>
      <td>3</td>
      <td>4</td>
      <td>two</td>
      <td>0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>4</td>
      <td>3</td>
      <td>two</td>
      <td>1</td>
    </tr>
    <tr>
      <th>5</th>
      <td>5</td>
      <td>2</td>
      <td>two</td>
      <td>2</td>
    </tr>
    <tr>
      <th>6</th>
      <td>6</td>
      <td>1</td>
      <td>two</td>
      <td>3</td>
    </tr>
  </tbody>
</table>

</div>



```python
frame2 = frame.set_index(['c', 'd'])
frame2 

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th></th>
      <th>a</th>
      <th>b</th>
    </tr>
    <tr>
      <th>c</th>
      <th>d</th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th rowspan="3" valign="top">one</th>
      <th>0</th>
      <td>0</td>
      <td>7</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1</td>
      <td>6</td>
    </tr>
    <tr>
      <th>2</th>
      <td>2</td>
      <td>5</td>
    </tr>
    <tr>
      <th rowspan="4" valign="top">two</th>
      <th>0</th>
      <td>3</td>
      <td>4</td>
    </tr>
    <tr>
      <th>1</th>
      <td>4</td>
      <td>3</td>
    </tr>
    <tr>
      <th>2</th>
      <td>5</td>
      <td>2</td>
    </tr>
    <tr>
      <th>3</th>
      <td>6</td>
      <td>1</td>
    </tr>
  </tbody>
</table>

</div>



```python
frame.set_index(['c', 'd'], drop=False)

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th></th>
      <th>a</th>
      <th>b</th>
      <th>c</th>
      <th>d</th>
    </tr>
    <tr>
      <th>c</th>
      <th>d</th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th rowspan="3" valign="top">one</th>
      <th>0</th>
      <td>0</td>
      <td>7</td>
      <td>one</td>
      <td>0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1</td>
      <td>6</td>
      <td>one</td>
      <td>1</td>
    </tr>
    <tr>
      <th>2</th>
      <td>2</td>
      <td>5</td>
      <td>one</td>
      <td>2</td>
    </tr>
    <tr>
      <th rowspan="4" valign="top">two</th>
      <th>0</th>
      <td>3</td>
      <td>4</td>
      <td>two</td>
      <td>0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>4</td>
      <td>3</td>
      <td>two</td>
      <td>1</td>
    </tr>
    <tr>
      <th>2</th>
      <td>5</td>
      <td>2</td>
      <td>two</td>
      <td>2</td>
    </tr>
    <tr>
      <th>3</th>
      <td>6</td>
      <td>1</td>
      <td>two</td>
      <td>3</td>
    </tr>
  </tbody>
</table>

</div>



```python
# reset_index 的功能跟 set_index 刚好相反，层次化索引的级别会被转移到列里面
frame2.reset_index()

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>c</th>
      <th>d</th>
      <th>a</th>
      <th>b</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>one</td>
      <td>0</td>
      <td>0</td>
      <td>7</td>
    </tr>
    <tr>
      <th>1</th>
      <td>one</td>
      <td>1</td>
      <td>1</td>
      <td>6</td>
    </tr>
    <tr>
      <th>2</th>
      <td>one</td>
      <td>2</td>
      <td>2</td>
      <td>5</td>
    </tr>
    <tr>
      <th>3</th>
      <td>two</td>
      <td>0</td>
      <td>3</td>
      <td>4</td>
    </tr>
    <tr>
      <th>4</th>
      <td>two</td>
      <td>1</td>
      <td>4</td>
      <td>3</td>
    </tr>
    <tr>
      <th>5</th>
      <td>two</td>
      <td>2</td>
      <td>5</td>
      <td>2</td>
    </tr>
    <tr>
      <th>6</th>
      <td>two</td>
      <td>3</td>
      <td>6</td>
      <td>1</td>
    </tr>
  </tbody>
</table>

</div>



```python
# 合并数据集

```

```python
# pandas.merge可根据一个或多个键将不同DataFrame中的行连接起来。
# SQL或其他关系型数据库的用户对此应该会比较熟悉，
# 因为它实现的就是数据库的join操作。

```

```python
# pandas.concat可以沿着一条轴将多个对象堆叠到一起。

```

```python
# 实例方法combine_first可以将重复数据编接在一起，
# 用一个对象中的值填充另一个对象中的缺失值。

```

```python
# 数据库风格的 DataFrame 合并
df1 = pd.DataFrame({'key': ['b', 'b', 'a', 'c', 'a', 'a', 'b'],  
                    'data1': range(7)})
df2 = pd.DataFrame({'key': ['a', 'b', 'd'],   
                    'data2': range(3)})

```

```python
df1

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>data1</th>
      <th>key</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>0</td>
      <td>b</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1</td>
      <td>b</td>
    </tr>
    <tr>
      <th>2</th>
      <td>2</td>
      <td>a</td>
    </tr>
    <tr>
      <th>3</th>
      <td>3</td>
      <td>c</td>
    </tr>
    <tr>
      <th>4</th>
      <td>4</td>
      <td>a</td>
    </tr>
    <tr>
      <th>5</th>
      <td>5</td>
      <td>a</td>
    </tr>
    <tr>
      <th>6</th>
      <td>6</td>
      <td>b</td>
    </tr>
  </tbody>
</table>

</div>



```python
df2

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>data2</th>
      <th>key</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>0</td>
      <td>a</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1</td>
      <td>b</td>
    </tr>
    <tr>
      <th>2</th>
      <td>2</td>
      <td>d</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.merge(df1, df2)

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>data1</th>
      <th>key</th>
      <th>data2</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>0</td>
      <td>b</td>
      <td>1</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1</td>
      <td>b</td>
      <td>1</td>
    </tr>
    <tr>
      <th>2</th>
      <td>6</td>
      <td>b</td>
      <td>1</td>
    </tr>
    <tr>
      <th>3</th>
      <td>2</td>
      <td>a</td>
      <td>0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>4</td>
      <td>a</td>
      <td>0</td>
    </tr>
    <tr>
      <th>5</th>
      <td>5</td>
      <td>a</td>
      <td>0</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.merge(df1, df2, on='key')

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>data1</th>
      <th>key</th>
      <th>data2</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>0</td>
      <td>b</td>
      <td>1</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1</td>
      <td>b</td>
      <td>1</td>
    </tr>
    <tr>
      <th>2</th>
      <td>6</td>
      <td>b</td>
      <td>1</td>
    </tr>
    <tr>
      <th>3</th>
      <td>2</td>
      <td>a</td>
      <td>0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>4</td>
      <td>a</td>
      <td>0</td>
    </tr>
    <tr>
      <th>5</th>
      <td>5</td>
      <td>a</td>
      <td>0</td>
    </tr>
  </tbody>
</table>

</div>



```python
df3 = pd.DataFrame({'lkey': ['b', 'b', 'a', 'c', 'a', 'a', 'b'],  
                    'data1': range(7)})
df4 = pd.DataFrame({'rkey': ['a', 'b', 'd'],  
                    'data2': range(3)})

```

```python
pd.merge(df3, df4, left_on='lkey', right_on='rkey')

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>data1</th>
      <th>lkey</th>
      <th>data2</th>
      <th>rkey</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>0</td>
      <td>b</td>
      <td>1</td>
      <td>b</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1</td>
      <td>b</td>
      <td>1</td>
      <td>b</td>
    </tr>
    <tr>
      <th>2</th>
      <td>6</td>
      <td>b</td>
      <td>1</td>
      <td>b</td>
    </tr>
    <tr>
      <th>3</th>
      <td>2</td>
      <td>a</td>
      <td>0</td>
      <td>a</td>
    </tr>
    <tr>
      <th>4</th>
      <td>4</td>
      <td>a</td>
      <td>0</td>
      <td>a</td>
    </tr>
    <tr>
      <th>5</th>
      <td>5</td>
      <td>a</td>
      <td>0</td>
      <td>a</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.merge(df1, df2, how='outer') 

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>data1</th>
      <th>key</th>
      <th>data2</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>0.0</td>
      <td>b</td>
      <td>1.0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1.0</td>
      <td>b</td>
      <td>1.0</td>
    </tr>
    <tr>
      <th>2</th>
      <td>6.0</td>
      <td>b</td>
      <td>1.0</td>
    </tr>
    <tr>
      <th>3</th>
      <td>2.0</td>
      <td>a</td>
      <td>0.0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>4.0</td>
      <td>a</td>
      <td>0.0</td>
    </tr>
    <tr>
      <th>5</th>
      <td>5.0</td>
      <td>a</td>
      <td>0.0</td>
    </tr>
    <tr>
      <th>6</th>
      <td>3.0</td>
      <td>c</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>7</th>
      <td>NaN</td>
      <td>d</td>
      <td>2.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
df1 = pd.DataFrame({'key': ['b', 'b', 'a', 'c', 'a', 'b'],  
                    'data1': range(6)})
df2 = pd.DataFrame({'key': ['a', 'b', 'a', 'b', 'd'],    
                    'data2': range(5)}) 

```

```python
df1

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>data1</th>
      <th>key</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>0</td>
      <td>b</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1</td>
      <td>b</td>
    </tr>
    <tr>
      <th>2</th>
      <td>2</td>
      <td>a</td>
    </tr>
    <tr>
      <th>3</th>
      <td>3</td>
      <td>c</td>
    </tr>
    <tr>
      <th>4</th>
      <td>4</td>
      <td>a</td>
    </tr>
    <tr>
      <th>5</th>
      <td>5</td>
      <td>b</td>
    </tr>
  </tbody>
</table>

</div>



```python
df2

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>data2</th>
      <th>key</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>0</td>
      <td>a</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1</td>
      <td>b</td>
    </tr>
    <tr>
      <th>2</th>
      <td>2</td>
      <td>a</td>
    </tr>
    <tr>
      <th>3</th>
      <td>3</td>
      <td>b</td>
    </tr>
    <tr>
      <th>4</th>
      <td>4</td>
      <td>d</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.merge(df1, df2, on='key', how='left')

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>data1</th>
      <th>key</th>
      <th>data2</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>0</td>
      <td>b</td>
      <td>1.0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>0</td>
      <td>b</td>
      <td>3.0</td>
    </tr>
    <tr>
      <th>2</th>
      <td>1</td>
      <td>b</td>
      <td>1.0</td>
    </tr>
    <tr>
      <th>3</th>
      <td>1</td>
      <td>b</td>
      <td>3.0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>2</td>
      <td>a</td>
      <td>0.0</td>
    </tr>
    <tr>
      <th>5</th>
      <td>2</td>
      <td>a</td>
      <td>2.0</td>
    </tr>
    <tr>
      <th>6</th>
      <td>3</td>
      <td>c</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>7</th>
      <td>4</td>
      <td>a</td>
      <td>0.0</td>
    </tr>
    <tr>
      <th>8</th>
      <td>4</td>
      <td>a</td>
      <td>2.0</td>
    </tr>
    <tr>
      <th>9</th>
      <td>5</td>
      <td>b</td>
      <td>1.0</td>
    </tr>
    <tr>
      <th>10</th>
      <td>5</td>
      <td>b</td>
      <td>3.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.merge(df1, df2, how='inner')

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>data1</th>
      <th>key</th>
      <th>data2</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>0</td>
      <td>b</td>
      <td>1</td>
    </tr>
    <tr>
      <th>1</th>
      <td>0</td>
      <td>b</td>
      <td>3</td>
    </tr>
    <tr>
      <th>2</th>
      <td>1</td>
      <td>b</td>
      <td>1</td>
    </tr>
    <tr>
      <th>3</th>
      <td>1</td>
      <td>b</td>
      <td>3</td>
    </tr>
    <tr>
      <th>4</th>
      <td>5</td>
      <td>b</td>
      <td>1</td>
    </tr>
    <tr>
      <th>5</th>
      <td>5</td>
      <td>b</td>
      <td>3</td>
    </tr>
    <tr>
      <th>6</th>
      <td>2</td>
      <td>a</td>
      <td>0</td>
    </tr>
    <tr>
      <th>7</th>
      <td>2</td>
      <td>a</td>
      <td>2</td>
    </tr>
    <tr>
      <th>8</th>
      <td>4</td>
      <td>a</td>
      <td>0</td>
    </tr>
    <tr>
      <th>9</th>
      <td>4</td>
      <td>a</td>
      <td>2</td>
    </tr>
  </tbody>
</table>

</div>



```python
left = pd.DataFrame({'key1': ['foo', 'foo', 'bar'],    
                     'key2': ['one', 'two', 'one'],   
                     'lval': [1, 2, 3]})
right = pd.DataFrame({'key1': ['foo', 'foo', 'bar', 'bar'],   
                      'key2': ['one', 'one', 'one', 'two'], 
                      'rval': [4, 5, 6, 7]})


```

```python
pd.merge(left, right, on=['key1', 'key2'], how='outer')

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>key1</th>
      <th>key2</th>
      <th>lval</th>
      <th>rval</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>foo</td>
      <td>one</td>
      <td>1.0</td>
      <td>4.0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>foo</td>
      <td>one</td>
      <td>1.0</td>
      <td>5.0</td>
    </tr>
    <tr>
      <th>2</th>
      <td>foo</td>
      <td>two</td>
      <td>2.0</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>3</th>
      <td>bar</td>
      <td>one</td>
      <td>3.0</td>
      <td>6.0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>bar</td>
      <td>two</td>
      <td>NaN</td>
      <td>7.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.merge(left, right, on='key1')

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>key1</th>
      <th>key2_x</th>
      <th>lval</th>
      <th>key2_y</th>
      <th>rval</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>foo</td>
      <td>one</td>
      <td>1</td>
      <td>one</td>
      <td>4</td>
    </tr>
    <tr>
      <th>1</th>
      <td>foo</td>
      <td>one</td>
      <td>1</td>
      <td>one</td>
      <td>5</td>
    </tr>
    <tr>
      <th>2</th>
      <td>foo</td>
      <td>two</td>
      <td>2</td>
      <td>one</td>
      <td>4</td>
    </tr>
    <tr>
      <th>3</th>
      <td>foo</td>
      <td>two</td>
      <td>2</td>
      <td>one</td>
      <td>5</td>
    </tr>
    <tr>
      <th>4</th>
      <td>bar</td>
      <td>one</td>
      <td>3</td>
      <td>one</td>
      <td>6</td>
    </tr>
    <tr>
      <th>5</th>
      <td>bar</td>
      <td>one</td>
      <td>3</td>
      <td>two</td>
      <td>7</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.merge(left, right, on='key1', suffixes=('_left', '_right'))

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>key1</th>
      <th>key2_left</th>
      <th>lval</th>
      <th>key2_right</th>
      <th>rval</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>foo</td>
      <td>one</td>
      <td>1</td>
      <td>one</td>
      <td>4</td>
    </tr>
    <tr>
      <th>1</th>
      <td>foo</td>
      <td>one</td>
      <td>1</td>
      <td>one</td>
      <td>5</td>
    </tr>
    <tr>
      <th>2</th>
      <td>foo</td>
      <td>two</td>
      <td>2</td>
      <td>one</td>
      <td>4</td>
    </tr>
    <tr>
      <th>3</th>
      <td>foo</td>
      <td>two</td>
      <td>2</td>
      <td>one</td>
      <td>5</td>
    </tr>
    <tr>
      <th>4</th>
      <td>bar</td>
      <td>one</td>
      <td>3</td>
      <td>one</td>
      <td>6</td>
    </tr>
    <tr>
      <th>5</th>
      <td>bar</td>
      <td>one</td>
      <td>3</td>
      <td>two</td>
      <td>7</td>
    </tr>
  </tbody>
</table>

</div>



```python
# 索引上的合并
left1 = pd.DataFrame({'key': ['a', 'b', 'a', 'a', 'b', 'c'], 
                      'value': range(6)})
right1 = pd.DataFrame({'group_val': [3.5, 7]}, index=['a', 'b'])

```

```python
left1 

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>key</th>
      <th>value</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>a</td>
      <td>0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>b</td>
      <td>1</td>
    </tr>
    <tr>
      <th>2</th>
      <td>a</td>
      <td>2</td>
    </tr>
    <tr>
      <th>3</th>
      <td>a</td>
      <td>3</td>
    </tr>
    <tr>
      <th>4</th>
      <td>b</td>
      <td>4</td>
    </tr>
    <tr>
      <th>5</th>
      <td>c</td>
      <td>5</td>
    </tr>
  </tbody>
</table>

</div>



```python
right1 

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>group_val</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>a</th>
      <td>3.5</td>
    </tr>
    <tr>
      <th>b</th>
      <td>7.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.merge(left1, right1, left_on='key', right_index=True)

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>key</th>
      <th>value</th>
      <th>group_val</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>a</td>
      <td>0</td>
      <td>3.5</td>
    </tr>
    <tr>
      <th>2</th>
      <td>a</td>
      <td>2</td>
      <td>3.5</td>
    </tr>
    <tr>
      <th>3</th>
      <td>a</td>
      <td>3</td>
      <td>3.5</td>
    </tr>
    <tr>
      <th>1</th>
      <td>b</td>
      <td>1</td>
      <td>7.0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>b</td>
      <td>4</td>
      <td>7.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.merge(left1, right1, left_on='key', right_index=True, how='outer')

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>key</th>
      <th>value</th>
      <th>group_val</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>a</td>
      <td>0</td>
      <td>3.5</td>
    </tr>
    <tr>
      <th>2</th>
      <td>a</td>
      <td>2</td>
      <td>3.5</td>
    </tr>
    <tr>
      <th>3</th>
      <td>a</td>
      <td>3</td>
      <td>3.5</td>
    </tr>
    <tr>
      <th>1</th>
      <td>b</td>
      <td>1</td>
      <td>7.0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>b</td>
      <td>4</td>
      <td>7.0</td>
    </tr>
    <tr>
      <th>5</th>
      <td>c</td>
      <td>5</td>
      <td>NaN</td>
    </tr>
  </tbody>
</table>

</div>



```python
lefth = pd.DataFrame({'key1': ['Ohio', 'Ohio', 'Ohio', 'Nevada', 'Nevada'],  
                      'key2': [2000, 2001, 2002, 2001,2002], 
                      'data': np.arange(5.)})
righth = pd.DataFrame(np.arange(12).reshape((6, 2)),    
                      index=[['Nevada', 'Nevada', 'Ohio', 'Ohio', 'Ohio', 'Ohio'],    
                      [2001, 2000, 2000, 2000, 2001, 2002]], 
                      columns=['event1', 'event2'])

```

```python
lefth 

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>data</th>
      <th>key1</th>
      <th>key2</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>0.0</td>
      <td>Ohio</td>
      <td>2000</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1.0</td>
      <td>Ohio</td>
      <td>2001</td>
    </tr>
    <tr>
      <th>2</th>
      <td>2.0</td>
      <td>Ohio</td>
      <td>2002</td>
    </tr>
    <tr>
      <th>3</th>
      <td>3.0</td>
      <td>Nevada</td>
      <td>2001</td>
    </tr>
    <tr>
      <th>4</th>
      <td>4.0</td>
      <td>Nevada</td>
      <td>2002</td>
    </tr>
  </tbody>
</table>

</div>



```python
righth 

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th></th>
      <th>event1</th>
      <th>event2</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th rowspan="2" valign="top">Nevada</th>
      <th>2001</th>
      <td>0</td>
      <td>1</td>
    </tr>
    <tr>
      <th>2000</th>
      <td>2</td>
      <td>3</td>
    </tr>
    <tr>
      <th rowspan="4" valign="top">Ohio</th>
      <th>2000</th>
      <td>4</td>
      <td>5</td>
    </tr>
    <tr>
      <th>2000</th>
      <td>6</td>
      <td>7</td>
    </tr>
    <tr>
      <th>2001</th>
      <td>8</td>
      <td>9</td>
    </tr>
    <tr>
      <th>2002</th>
      <td>10</td>
      <td>11</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.merge(lefth, righth, left_on=['key1', 'key2'], right_index=True)

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>data</th>
      <th>key1</th>
      <th>key2</th>
      <th>event1</th>
      <th>event2</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>0.0</td>
      <td>Ohio</td>
      <td>2000</td>
      <td>4</td>
      <td>5</td>
    </tr>
    <tr>
      <th>0</th>
      <td>0.0</td>
      <td>Ohio</td>
      <td>2000</td>
      <td>6</td>
      <td>7</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1.0</td>
      <td>Ohio</td>
      <td>2001</td>
      <td>8</td>
      <td>9</td>
    </tr>
    <tr>
      <th>2</th>
      <td>2.0</td>
      <td>Ohio</td>
      <td>2002</td>
      <td>10</td>
      <td>11</td>
    </tr>
    <tr>
      <th>3</th>
      <td>3.0</td>
      <td>Nevada</td>
      <td>2001</td>
      <td>0</td>
      <td>1</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.merge(lefth, righth, left_on=['key1', 'key2'],   
         right_index=True, how='outer')

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>data</th>
      <th>key1</th>
      <th>key2</th>
      <th>event1</th>
      <th>event2</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>0.0</td>
      <td>Ohio</td>
      <td>2000</td>
      <td>4.0</td>
      <td>5.0</td>
    </tr>
    <tr>
      <th>0</th>
      <td>0.0</td>
      <td>Ohio</td>
      <td>2000</td>
      <td>6.0</td>
      <td>7.0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1.0</td>
      <td>Ohio</td>
      <td>2001</td>
      <td>8.0</td>
      <td>9.0</td>
    </tr>
    <tr>
      <th>2</th>
      <td>2.0</td>
      <td>Ohio</td>
      <td>2002</td>
      <td>10.0</td>
      <td>11.0</td>
    </tr>
    <tr>
      <th>3</th>
      <td>3.0</td>
      <td>Nevada</td>
      <td>2001</td>
      <td>0.0</td>
      <td>1.0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>4.0</td>
      <td>Nevada</td>
      <td>2002</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>4</th>
      <td>NaN</td>
      <td>Nevada</td>
      <td>2000</td>
      <td>2.0</td>
      <td>3.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
left2 = pd.DataFrame([[1., 2.], [3., 4.], [5., 6.]],   
                     index=['a', 'c', 'e'],  
                     columns=['Ohio', 'Nevada'])
right2 = pd.DataFrame([[7., 8.], [9., 10.], [11., 12.], [13, 14]], 
                      index=['b', 'c', 'd', 'e'],  
                      columns=['Missouri', 'Alabama'])

```

```python
left2

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>Ohio</th>
      <th>Nevada</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>a</th>
      <td>1.0</td>
      <td>2.0</td>
    </tr>
    <tr>
      <th>c</th>
      <td>3.0</td>
      <td>4.0</td>
    </tr>
    <tr>
      <th>e</th>
      <td>5.0</td>
      <td>6.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
right2

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>Missouri</th>
      <th>Alabama</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>b</th>
      <td>7.0</td>
      <td>8.0</td>
    </tr>
    <tr>
      <th>c</th>
      <td>9.0</td>
      <td>10.0</td>
    </tr>
    <tr>
      <th>d</th>
      <td>11.0</td>
      <td>12.0</td>
    </tr>
    <tr>
      <th>e</th>
      <td>13.0</td>
      <td>14.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.merge(left2, right2, how='outer', left_index=True, right_index=True)

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>Ohio</th>
      <th>Nevada</th>
      <th>Missouri</th>
      <th>Alabama</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>a</th>
      <td>1.0</td>
      <td>2.0</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>b</th>
      <td>NaN</td>
      <td>NaN</td>
      <td>7.0</td>
      <td>8.0</td>
    </tr>
    <tr>
      <th>c</th>
      <td>3.0</td>
      <td>4.0</td>
      <td>9.0</td>
      <td>10.0</td>
    </tr>
    <tr>
      <th>d</th>
      <td>NaN</td>
      <td>NaN</td>
      <td>11.0</td>
      <td>12.0</td>
    </tr>
    <tr>
      <th>e</th>
      <td>5.0</td>
      <td>6.0</td>
      <td>13.0</td>
      <td>14.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
left2.join(right2, how='outer')

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>Ohio</th>
      <th>Nevada</th>
      <th>Missouri</th>
      <th>Alabama</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>a</th>
      <td>1.0</td>
      <td>2.0</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>b</th>
      <td>NaN</td>
      <td>NaN</td>
      <td>7.0</td>
      <td>8.0</td>
    </tr>
    <tr>
      <th>c</th>
      <td>3.0</td>
      <td>4.0</td>
      <td>9.0</td>
      <td>10.0</td>
    </tr>
    <tr>
      <th>d</th>
      <td>NaN</td>
      <td>NaN</td>
      <td>11.0</td>
      <td>12.0</td>
    </tr>
    <tr>
      <th>e</th>
      <td>5.0</td>
      <td>6.0</td>
      <td>13.0</td>
      <td>14.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
left1.join(right1, on='key')

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>key</th>
      <th>value</th>
      <th>group_val</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>a</td>
      <td>0</td>
      <td>3.5</td>
    </tr>
    <tr>
      <th>1</th>
      <td>b</td>
      <td>1</td>
      <td>7.0</td>
    </tr>
    <tr>
      <th>2</th>
      <td>a</td>
      <td>2</td>
      <td>3.5</td>
    </tr>
    <tr>
      <th>3</th>
      <td>a</td>
      <td>3</td>
      <td>3.5</td>
    </tr>
    <tr>
      <th>4</th>
      <td>b</td>
      <td>4</td>
      <td>7.0</td>
    </tr>
    <tr>
      <th>5</th>
      <td>c</td>
      <td>5</td>
      <td>NaN</td>
    </tr>
  </tbody>
</table>

</div>



```python
another = pd.DataFrame([[7., 8.], [9., 10.], [11., 12.], [16., 17.]], 
                       index=['a', 'c', 'e', 'f'],    
                       columns=['New York', 'Oregon'])
another

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>New York</th>
      <th>Oregon</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>a</th>
      <td>7.0</td>
      <td>8.0</td>
    </tr>
    <tr>
      <th>c</th>
      <td>9.0</td>
      <td>10.0</td>
    </tr>
    <tr>
      <th>e</th>
      <td>11.0</td>
      <td>12.0</td>
    </tr>
    <tr>
      <th>f</th>
      <td>16.0</td>
      <td>17.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
left2.join([right2, another]) 

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>Ohio</th>
      <th>Nevada</th>
      <th>Missouri</th>
      <th>Alabama</th>
      <th>New York</th>
      <th>Oregon</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>a</th>
      <td>1.0</td>
      <td>2.0</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>7.0</td>
      <td>8.0</td>
    </tr>
    <tr>
      <th>c</th>
      <td>3.0</td>
      <td>4.0</td>
      <td>9.0</td>
      <td>10.0</td>
      <td>9.0</td>
      <td>10.0</td>
    </tr>
    <tr>
      <th>e</th>
      <td>5.0</td>
      <td>6.0</td>
      <td>13.0</td>
      <td>14.0</td>
      <td>11.0</td>
      <td>12.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
left2.join([right2, another], how='outer')

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>Ohio</th>
      <th>Nevada</th>
      <th>Missouri</th>
      <th>Alabama</th>
      <th>New York</th>
      <th>Oregon</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>a</th>
      <td>1.0</td>
      <td>2.0</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>7.0</td>
      <td>8.0</td>
    </tr>
    <tr>
      <th>b</th>
      <td>NaN</td>
      <td>NaN</td>
      <td>7.0</td>
      <td>8.0</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>c</th>
      <td>3.0</td>
      <td>4.0</td>
      <td>9.0</td>
      <td>10.0</td>
      <td>9.0</td>
      <td>10.0</td>
    </tr>
    <tr>
      <th>d</th>
      <td>NaN</td>
      <td>NaN</td>
      <td>11.0</td>
      <td>12.0</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>e</th>
      <td>5.0</td>
      <td>6.0</td>
      <td>13.0</td>
      <td>14.0</td>
      <td>11.0</td>
      <td>12.0</td>
    </tr>
    <tr>
      <th>f</th>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>16.0</td>
      <td>17.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
# 轴向连接
arr = np.arange(12).reshape((3, 4))

```

```python
arr

```



```
array([[ 0,  1,  2,  3],
       [ 4,  5,  6,  7],
       [ 8,  9, 10, 11]])

```



```python
np.concatenate([arr, arr], axis=1)

```



```
array([[ 0,  1,  2,  3,  0,  1,  2,  3],
       [ 4,  5,  6,  7,  4,  5,  6,  7],
       [ 8,  9, 10, 11,  8,  9, 10, 11]])

```



```python
s1 = pd.Series([0, 1], index=['a', 'b'])
s2 = pd.Series([2, 3, 4], index=['c', 'd', 'e'])
s3 = pd.Series([5, 6], index=['f', 'g']) 

```

```python
pd.concat([s1, s2, s3])

```



```
a    0
b    1
c    2
d    3
e    4
f    5
g    6
dtype: int64

```



```python
 pd.concat([s1, s2, s3], axis=1)

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>0</th>
      <th>1</th>
      <th>2</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>a</th>
      <td>0.0</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>b</th>
      <td>1.0</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>c</th>
      <td>NaN</td>
      <td>2.0</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>d</th>
      <td>NaN</td>
      <td>3.0</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>e</th>
      <td>NaN</td>
      <td>4.0</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>f</th>
      <td>NaN</td>
      <td>NaN</td>
      <td>5.0</td>
    </tr>
    <tr>
      <th>g</th>
      <td>NaN</td>
      <td>NaN</td>
      <td>6.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
s4 = pd.concat([s1, s3])

```

```python
s4

```



```
a    0
b    1
f    5
g    6
dtype: int64

```



```python
pd.concat([s1, s4], axis=1)

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>0</th>
      <th>1</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>a</th>
      <td>0.0</td>
      <td>0</td>
    </tr>
    <tr>
      <th>b</th>
      <td>1.0</td>
      <td>1</td>
    </tr>
    <tr>
      <th>f</th>
      <td>NaN</td>
      <td>5</td>
    </tr>
    <tr>
      <th>g</th>
      <td>NaN</td>
      <td>6</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.concat([s1, s4], axis=1, join='inner')

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>0</th>
      <th>1</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>a</th>
      <td>0</td>
      <td>0</td>
    </tr>
    <tr>
      <th>b</th>
      <td>1</td>
      <td>1</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.concat([s1, s4], axis=1, join_axes=[['a', 'c', 'b','e']])

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>0</th>
      <th>1</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>a</th>
      <td>0.0</td>
      <td>0.0</td>
    </tr>
    <tr>
      <th>c</th>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>b</th>
      <td>1.0</td>
      <td>1.0</td>
    </tr>
    <tr>
      <th>e</th>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
  </tbody>
</table>

</div>



```python
result = pd.concat([s1, s1, s3], keys=['one','two', 'three'])

```

```python
result 

```



```
one    a    0
       b    1
two    a    0
       b    1
three  f    5
       g    6
dtype: int64

```



```python
result.unstack()

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>a</th>
      <th>b</th>
      <th>f</th>
      <th>g</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>one</th>
      <td>0.0</td>
      <td>1.0</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>two</th>
      <td>0.0</td>
      <td>1.0</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>three</th>
      <td>NaN</td>
      <td>NaN</td>
      <td>5.0</td>
      <td>6.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.concat([s1, s2, s3], axis=1, keys=['one','two', 'three'])

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>one</th>
      <th>two</th>
      <th>three</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>a</th>
      <td>0.0</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>b</th>
      <td>1.0</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>c</th>
      <td>NaN</td>
      <td>2.0</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>d</th>
      <td>NaN</td>
      <td>3.0</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>e</th>
      <td>NaN</td>
      <td>4.0</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>f</th>
      <td>NaN</td>
      <td>NaN</td>
      <td>5.0</td>
    </tr>
    <tr>
      <th>g</th>
      <td>NaN</td>
      <td>NaN</td>
      <td>6.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
df1 = pd.DataFrame(np.arange(6).reshape(3, 2), 
                   index=['a', 'b', 'c'],   
                   columns=['one', 'two'])
df2 = pd.DataFrame(5 + np.arange(4).reshape(2, 2), 
                   index=['a', 'c'],
                   columns=['three', 'four']) 

```

```python
df1

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>one</th>
      <th>two</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>a</th>
      <td>0</td>
      <td>1</td>
    </tr>
    <tr>
      <th>b</th>
      <td>2</td>
      <td>3</td>
    </tr>
    <tr>
      <th>c</th>
      <td>4</td>
      <td>5</td>
    </tr>
  </tbody>
</table>

</div>



```python
df2

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>three</th>
      <th>four</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>a</th>
      <td>5</td>
      <td>6</td>
    </tr>
    <tr>
      <th>c</th>
      <td>7</td>
      <td>8</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.concat([df1, df2], axis=1, keys=['level1', 'level2'])

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead tr th {
    text-align: left;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr>
      <th></th>
      <th colspan="2" halign="left">level1</th>
      <th colspan="2" halign="left">level2</th>
    </tr>
    <tr>
      <th></th>
      <th>one</th>
      <th>two</th>
      <th>three</th>
      <th>four</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>a</th>
      <td>0</td>
      <td>1</td>
      <td>5.0</td>
      <td>6.0</td>
    </tr>
    <tr>
      <th>b</th>
      <td>2</td>
      <td>3</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>c</th>
      <td>4</td>
      <td>5</td>
      <td>7.0</td>
      <td>8.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.concat({'level1': df1, 'level2': df2}, axis=1)

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead tr th {
    text-align: left;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr>
      <th></th>
      <th colspan="2" halign="left">level1</th>
      <th colspan="2" halign="left">level2</th>
    </tr>
    <tr>
      <th></th>
      <th>one</th>
      <th>two</th>
      <th>three</th>
      <th>four</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>a</th>
      <td>0</td>
      <td>1</td>
      <td>5.0</td>
      <td>6.0</td>
    </tr>
    <tr>
      <th>b</th>
      <td>2</td>
      <td>3</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>c</th>
      <td>4</td>
      <td>5</td>
      <td>7.0</td>
      <td>8.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.concat([df1, df2], axis=1,
          keys=['level1', 'level2'],  
          names=['upper', 'lower'])

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead tr th {
    text-align: left;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr>
      <th>upper</th>
      <th colspan="2" halign="left">level1</th>
      <th colspan="2" halign="left">level2</th>
    </tr>
    <tr>
      <th>lower</th>
      <th>one</th>
      <th>two</th>
      <th>three</th>
      <th>four</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>a</th>
      <td>0</td>
      <td>1</td>
      <td>5.0</td>
      <td>6.0</td>
    </tr>
    <tr>
      <th>b</th>
      <td>2</td>
      <td>3</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>c</th>
      <td>4</td>
      <td>5</td>
      <td>7.0</td>
      <td>8.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
df1 = pd.DataFrame(np.random.randn(3, 4),
                   columns=['a', 'b', 'c', 'd'])
df2 = pd.DataFrame(np.random.randn(2, 3),
                   columns=['b', 'd', 'a'])

```

```python
df1

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>a</th>
      <th>b</th>
      <th>c</th>
      <th>d</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>0.783680</td>
      <td>-0.400817</td>
      <td>-0.004622</td>
      <td>0.755882</td>
    </tr>
    <tr>
      <th>1</th>
      <td>-1.246342</td>
      <td>-0.382263</td>
      <td>0.836619</td>
      <td>-2.047165</td>
    </tr>
    <tr>
      <th>2</th>
      <td>0.926545</td>
      <td>-0.588521</td>
      <td>0.418693</td>
      <td>-0.294311</td>
    </tr>
  </tbody>
</table>

</div>



```python
df2

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>b</th>
      <th>d</th>
      <th>a</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>-0.218258</td>
      <td>0.113929</td>
      <td>-0.624806</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1.397493</td>
      <td>0.773885</td>
      <td>0.683046</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.concat([df1, df2], ignore_index=True)

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>a</th>
      <th>b</th>
      <th>c</th>
      <th>d</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>0.783680</td>
      <td>-0.400817</td>
      <td>-0.004622</td>
      <td>0.755882</td>
    </tr>
    <tr>
      <th>1</th>
      <td>-1.246342</td>
      <td>-0.382263</td>
      <td>0.836619</td>
      <td>-2.047165</td>
    </tr>
    <tr>
      <th>2</th>
      <td>0.926545</td>
      <td>-0.588521</td>
      <td>0.418693</td>
      <td>-0.294311</td>
    </tr>
    <tr>
      <th>3</th>
      <td>-0.624806</td>
      <td>-0.218258</td>
      <td>NaN</td>
      <td>0.113929</td>
    </tr>
    <tr>
      <th>4</th>
      <td>0.683046</td>
      <td>1.397493</td>
      <td>NaN</td>
      <td>0.773885</td>
    </tr>
  </tbody>
</table>

</div>



```python
# 合并重叠数据
a = pd.Series([np.nan, 2.5, np.nan, 3.5, 4.5, np.nan],  
              index=['f', 'e', 'd', 'c', 'b', 'a'])
b = pd.Series(np.arange(len(a), dtype=np.float64),   
              index=['f', 'e', 'd', 'c', 'b', 'a']) 

```

```python
b[-1] = np.nan

```

```python
a

```



```
f    NaN
e    2.5
d    NaN
c    3.5
b    4.5
a    NaN
dtype: float64

```



```python
b

```



```
f    0.0
e    1.0
d    2.0
c    3.0
b    4.0
a    NaN
dtype: float64

```



```python
np.where(pd.isnull(a), b, a)

```



```
array([0. , 2.5, 2. , 3.5, 4.5, nan])

```



```python
b[:-2].combine_first(a[2:])

```



```
a    NaN
b    4.5
c    3.0
d    2.0
e    1.0
f    0.0
dtype: float64

```



```python
df1 = pd.DataFrame({'a': [1., np.nan, 5., np.nan],
                    'b': [np.nan, 2., np.nan, 6.],
                    'c': range(2, 18, 4)})
df2 = pd.DataFrame({'a': [5., 4., np.nan, 3., 7.],
                    'b': [np.nan, 3., 4., 6., 8.]})

```

```python
df1

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>a</th>
      <th>b</th>
      <th>c</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1.0</td>
      <td>NaN</td>
      <td>2</td>
    </tr>
    <tr>
      <th>1</th>
      <td>NaN</td>
      <td>2.0</td>
      <td>6</td>
    </tr>
    <tr>
      <th>2</th>
      <td>5.0</td>
      <td>NaN</td>
      <td>10</td>
    </tr>
    <tr>
      <th>3</th>
      <td>NaN</td>
      <td>6.0</td>
      <td>14</td>
    </tr>
  </tbody>
</table>

</div>



```python
df2

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>a</th>
      <th>b</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>5.0</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>1</th>
      <td>4.0</td>
      <td>3.0</td>
    </tr>
    <tr>
      <th>2</th>
      <td>NaN</td>
      <td>4.0</td>
    </tr>
    <tr>
      <th>3</th>
      <td>3.0</td>
      <td>6.0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>7.0</td>
      <td>8.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
df1.combine_first(df2)

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>a</th>
      <th>b</th>
      <th>c</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1.0</td>
      <td>NaN</td>
      <td>2.0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>4.0</td>
      <td>2.0</td>
      <td>6.0</td>
    </tr>
    <tr>
      <th>2</th>
      <td>5.0</td>
      <td>4.0</td>
      <td>10.0</td>
    </tr>
    <tr>
      <th>3</th>
      <td>3.0</td>
      <td>6.0</td>
      <td>14.0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>7.0</td>
      <td>8.0</td>
      <td>NaN</td>
    </tr>
  </tbody>
</table>

</div>



```python
# 重塑和轴向旋转
# 重塑层次化索引

```

```python
# vstack：将数据的列“旋转”为行。
# unstack：将数据的行“旋转”为列。

```

```python
data = pd.DataFrame(np.arange(6).reshape((2, 3)),   
                    index=pd.Index(['Ohio','Colorado'], ame='state'),    
                    columns=pd.Index(['one', 'two', 'three'],
                    name='number'))

```

```python
data

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th>number</th>
      <th>one</th>
      <th>two</th>
      <th>three</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>Ohio</th>
      <td>0</td>
      <td>1</td>
      <td>2</td>
    </tr>
    <tr>
      <th>Colorado</th>
      <td>3</td>
      <td>4</td>
      <td>5</td>
    </tr>
  </tbody>
</table>

</div>



```python
result = data.stack()

```

```python
result 

```



```
          number
Ohio      one       0
          two       1
          three     2
Colorado  one       3
          two       4
          three     5
dtype: int32

```



```python
result.unstack() 

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th>number</th>
      <th>one</th>
      <th>two</th>
      <th>three</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>Ohio</th>
      <td>0</td>
      <td>1</td>
      <td>2</td>
    </tr>
    <tr>
      <th>Colorado</th>
      <td>3</td>
      <td>4</td>
      <td>5</td>
    </tr>
  </tbody>
</table>

</div>



```python
result.unstack(0)

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>Ohio</th>
      <th>Colorado</th>
    </tr>
    <tr>
      <th>number</th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>one</th>
      <td>0</td>
      <td>3</td>
    </tr>
    <tr>
      <th>two</th>
      <td>1</td>
      <td>4</td>
    </tr>
    <tr>
      <th>three</th>
      <td>2</td>
      <td>5</td>
    </tr>
  </tbody>
</table>

</div>



```python
# result.unstack('state')
# KeyError: 'Level state not found'

```

```python
s1 = pd.Series([0, 1, 2, 3], index=['a', 'b', 'c', 'd'])
s2 = pd.Series([4, 5, 6], index=['c', 'd', 'e'])

```

```python
data2 = pd.concat([s1, s2], keys=['one', 'two'])

```

```python
data2

```



```
one  a    0
     b    1
     c    2
     d    3
two  c    4
     d    5
     e    6
dtype: int64

```



```python
data2.unstack()

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>a</th>
      <th>b</th>
      <th>c</th>
      <th>d</th>
      <th>e</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>one</th>
      <td>0.0</td>
      <td>1.0</td>
      <td>2.0</td>
      <td>3.0</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>two</th>
      <td>NaN</td>
      <td>NaN</td>
      <td>4.0</td>
      <td>5.0</td>
      <td>6.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
data2.unstack()

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>a</th>
      <th>b</th>
      <th>c</th>
      <th>d</th>
      <th>e</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>one</th>
      <td>0.0</td>
      <td>1.0</td>
      <td>2.0</td>
      <td>3.0</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>two</th>
      <td>NaN</td>
      <td>NaN</td>
      <td>4.0</td>
      <td>5.0</td>
      <td>6.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
data2.unstack().stack()

```



```
one  a    0.0
     b    1.0
     c    2.0
     d    3.0
two  c    4.0
     d    5.0
     e    6.0
dtype: float64

```



```python
data2.unstack().stack(dropna=False)

```



```
one  a    0.0
     b    1.0
     c    2.0
     d    3.0
     e    NaN
two  a    NaN
     b    NaN
     c    4.0
     d    5.0
     e    6.0
dtype: float64

```



```python
df = pd.DataFrame({'left': result, 'right': result + 5},   
                  columns=pd.Index(['left', 'right'],name='side'))

```

```python
df

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>side</th>
      <th>left</th>
      <th>right</th>
    </tr>
    <tr>
      <th></th>
      <th>number</th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th rowspan="3" valign="top">Ohio</th>
      <th>one</th>
      <td>0</td>
      <td>5</td>
    </tr>
    <tr>
      <th>two</th>
      <td>1</td>
      <td>6</td>
    </tr>
    <tr>
      <th>three</th>
      <td>2</td>
      <td>7</td>
    </tr>
    <tr>
      <th rowspan="3" valign="top">Colorado</th>
      <th>one</th>
      <td>3</td>
      <td>8</td>
    </tr>
    <tr>
      <th>two</th>
      <td>4</td>
      <td>9</td>
    </tr>
    <tr>
      <th>three</th>
      <td>5</td>
      <td>10</td>
    </tr>
  </tbody>
</table>

</div>



```python
# df.unstack('state') 

```

```python
# df.unstack('state').stack('side') 

```

```python
# 将“长格式”旋转为“宽格式”
data = pd.read_csv('examples/macrodata.csv')

```

```python
data.head()

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>year</th>
      <th>quarter</th>
      <th>realgdp</th>
      <th>realcons</th>
      <th>realinv</th>
      <th>realgovt</th>
      <th>realdpi</th>
      <th>cpi</th>
      <th>m1</th>
      <th>tbilrate</th>
      <th>unemp</th>
      <th>pop</th>
      <th>infl</th>
      <th>realint</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1959.0</td>
      <td>1.0</td>
      <td>2710.349</td>
      <td>1707.4</td>
      <td>286.898</td>
      <td>470.045</td>
      <td>1886.9</td>
      <td>28.98</td>
      <td>139.7</td>
      <td>2.82</td>
      <td>5.8</td>
      <td>177.146</td>
      <td>0.00</td>
      <td>0.00</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1959.0</td>
      <td>2.0</td>
      <td>2778.801</td>
      <td>1733.7</td>
      <td>310.859</td>
      <td>481.301</td>
      <td>1919.7</td>
      <td>29.15</td>
      <td>141.7</td>
      <td>3.08</td>
      <td>5.1</td>
      <td>177.830</td>
      <td>2.34</td>
      <td>0.74</td>
    </tr>
    <tr>
      <th>2</th>
      <td>1959.0</td>
      <td>3.0</td>
      <td>2775.488</td>
      <td>1751.8</td>
      <td>289.226</td>
      <td>491.260</td>
      <td>1916.4</td>
      <td>29.35</td>
      <td>140.5</td>
      <td>3.82</td>
      <td>5.3</td>
      <td>178.657</td>
      <td>2.74</td>
      <td>1.09</td>
    </tr>
    <tr>
      <th>3</th>
      <td>1959.0</td>
      <td>4.0</td>
      <td>2785.204</td>
      <td>1753.7</td>
      <td>299.356</td>
      <td>484.052</td>
      <td>1931.3</td>
      <td>29.37</td>
      <td>140.0</td>
      <td>4.33</td>
      <td>5.6</td>
      <td>179.386</td>
      <td>0.27</td>
      <td>4.06</td>
    </tr>
    <tr>
      <th>4</th>
      <td>1960.0</td>
      <td>1.0</td>
      <td>2847.699</td>
      <td>1770.5</td>
      <td>331.722</td>
      <td>462.199</td>
      <td>1955.5</td>
      <td>29.54</td>
      <td>139.6</td>
      <td>3.50</td>
      <td>5.2</td>
      <td>180.007</td>
      <td>2.31</td>
      <td>1.19</td>
    </tr>
  </tbody>
</table>

</div>



```python
periods = pd.PeriodIndex(year=data.year, quarter=data.quarter,  
                         name='date')
columns = pd.Index(['realgdp', 'infl', 'unemp'], name='item')

```

```python
data = data.reindex(columns=columns)

```

```python
data.index = periods.to_timestamp('D', 'end')

```

```python
ldata = data.stack().reset_index().rename(columns={0:'value'})

```

```python
 pivoted = ldata.pivot('date', 'item', 'value') 

```

```python
pivoted

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th>item</th>
      <th>infl</th>
      <th>realgdp</th>
      <th>unemp</th>
    </tr>
    <tr>
      <th>date</th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>1959-03-31</th>
      <td>0.00</td>
      <td>2710.349</td>
      <td>5.8</td>
    </tr>
    <tr>
      <th>1959-06-30</th>
      <td>2.34</td>
      <td>2778.801</td>
      <td>5.1</td>
    </tr>
    <tr>
      <th>1959-09-30</th>
      <td>2.74</td>
      <td>2775.488</td>
      <td>5.3</td>
    </tr>
    <tr>
      <th>1959-12-31</th>
      <td>0.27</td>
      <td>2785.204</td>
      <td>5.6</td>
    </tr>
    <tr>
      <th>1960-03-31</th>
      <td>2.31</td>
      <td>2847.699</td>
      <td>5.2</td>
    </tr>
    <tr>
      <th>1960-06-30</th>
      <td>0.14</td>
      <td>2834.390</td>
      <td>5.2</td>
    </tr>
    <tr>
      <th>1960-09-30</th>
      <td>2.70</td>
      <td>2839.022</td>
      <td>5.6</td>
    </tr>
    <tr>
      <th>1960-12-31</th>
      <td>1.21</td>
      <td>2802.616</td>
      <td>6.3</td>
    </tr>
    <tr>
      <th>1961-03-31</th>
      <td>-0.40</td>
      <td>2819.264</td>
      <td>6.8</td>
    </tr>
    <tr>
      <th>1961-06-30</th>
      <td>1.47</td>
      <td>2872.005</td>
      <td>7.0</td>
    </tr>
    <tr>
      <th>1961-09-30</th>
      <td>0.80</td>
      <td>2918.419</td>
      <td>6.8</td>
    </tr>
    <tr>
      <th>1961-12-31</th>
      <td>0.80</td>
      <td>2977.830</td>
      <td>6.2</td>
    </tr>
    <tr>
      <th>1962-03-31</th>
      <td>2.26</td>
      <td>3031.241</td>
      <td>5.6</td>
    </tr>
    <tr>
      <th>1962-06-30</th>
      <td>0.13</td>
      <td>3064.709</td>
      <td>5.5</td>
    </tr>
    <tr>
      <th>1962-09-30</th>
      <td>2.11</td>
      <td>3093.047</td>
      <td>5.6</td>
    </tr>
    <tr>
      <th>1962-12-31</th>
      <td>0.79</td>
      <td>3100.563</td>
      <td>5.5</td>
    </tr>
    <tr>
      <th>1963-03-31</th>
      <td>0.53</td>
      <td>3141.087</td>
      <td>5.8</td>
    </tr>
    <tr>
      <th>1963-06-30</th>
      <td>2.75</td>
      <td>3180.447</td>
      <td>5.7</td>
    </tr>
    <tr>
      <th>1963-09-30</th>
      <td>0.78</td>
      <td>3240.332</td>
      <td>5.5</td>
    </tr>
    <tr>
      <th>1963-12-31</th>
      <td>2.46</td>
      <td>3264.967</td>
      <td>5.6</td>
    </tr>
    <tr>
      <th>1964-03-31</th>
      <td>0.13</td>
      <td>3338.246</td>
      <td>5.5</td>
    </tr>
    <tr>
      <th>1964-06-30</th>
      <td>0.90</td>
      <td>3376.587</td>
      <td>5.2</td>
    </tr>
    <tr>
      <th>1964-09-30</th>
      <td>1.29</td>
      <td>3422.469</td>
      <td>5.0</td>
    </tr>
    <tr>
      <th>1964-12-31</th>
      <td>2.05</td>
      <td>3431.957</td>
      <td>5.0</td>
    </tr>
    <tr>
      <th>1965-03-31</th>
      <td>1.28</td>
      <td>3516.251</td>
      <td>4.9</td>
    </tr>
    <tr>
      <th>1965-06-30</th>
      <td>2.54</td>
      <td>3563.960</td>
      <td>4.7</td>
    </tr>
    <tr>
      <th>1965-09-30</th>
      <td>0.89</td>
      <td>3636.285</td>
      <td>4.4</td>
    </tr>
    <tr>
      <th>1965-12-31</th>
      <td>2.90</td>
      <td>3724.014</td>
      <td>4.1</td>
    </tr>
    <tr>
      <th>1966-03-31</th>
      <td>4.99</td>
      <td>3815.423</td>
      <td>3.9</td>
    </tr>
    <tr>
      <th>1966-06-30</th>
      <td>2.10</td>
      <td>3828.124</td>
      <td>3.8</td>
    </tr>
    <tr>
      <th>...</th>
      <td>...</td>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th>2002-06-30</th>
      <td>1.56</td>
      <td>11538.770</td>
      <td>5.8</td>
    </tr>
    <tr>
      <th>2002-09-30</th>
      <td>2.66</td>
      <td>11596.430</td>
      <td>5.7</td>
    </tr>
    <tr>
      <th>2002-12-31</th>
      <td>3.08</td>
      <td>11598.824</td>
      <td>5.8</td>
    </tr>
    <tr>
      <th>2003-03-31</th>
      <td>1.31</td>
      <td>11645.819</td>
      <td>5.9</td>
    </tr>
    <tr>
      <th>2003-06-30</th>
      <td>1.09</td>
      <td>11738.706</td>
      <td>6.2</td>
    </tr>
    <tr>
      <th>2003-09-30</th>
      <td>2.60</td>
      <td>11935.461</td>
      <td>6.1</td>
    </tr>
    <tr>
      <th>2003-12-31</th>
      <td>3.02</td>
      <td>12042.817</td>
      <td>5.8</td>
    </tr>
    <tr>
      <th>2004-03-31</th>
      <td>2.35</td>
      <td>12127.623</td>
      <td>5.7</td>
    </tr>
    <tr>
      <th>2004-06-30</th>
      <td>3.61</td>
      <td>12213.818</td>
      <td>5.6</td>
    </tr>
    <tr>
      <th>2004-09-30</th>
      <td>3.58</td>
      <td>12303.533</td>
      <td>5.4</td>
    </tr>
    <tr>
      <th>2004-12-31</th>
      <td>2.09</td>
      <td>12410.282</td>
      <td>5.4</td>
    </tr>
    <tr>
      <th>2005-03-31</th>
      <td>4.15</td>
      <td>12534.113</td>
      <td>5.3</td>
    </tr>
    <tr>
      <th>2005-06-30</th>
      <td>1.85</td>
      <td>12587.535</td>
      <td>5.1</td>
    </tr>
    <tr>
      <th>2005-09-30</th>
      <td>9.14</td>
      <td>12683.153</td>
      <td>5.0</td>
    </tr>
    <tr>
      <th>2005-12-31</th>
      <td>0.40</td>
      <td>12748.699</td>
      <td>4.9</td>
    </tr>
    <tr>
      <th>2006-03-31</th>
      <td>2.60</td>
      <td>12915.938</td>
      <td>4.7</td>
    </tr>
    <tr>
      <th>2006-06-30</th>
      <td>3.97</td>
      <td>12962.462</td>
      <td>4.7</td>
    </tr>
    <tr>
      <th>2006-09-30</th>
      <td>-1.58</td>
      <td>12965.916</td>
      <td>4.7</td>
    </tr>
    <tr>
      <th>2006-12-31</th>
      <td>3.30</td>
      <td>13060.679</td>
      <td>4.4</td>
    </tr>
    <tr>
      <th>2007-03-31</th>
      <td>4.58</td>
      <td>13099.901</td>
      <td>4.5</td>
    </tr>
    <tr>
      <th>2007-06-30</th>
      <td>2.75</td>
      <td>13203.977</td>
      <td>4.5</td>
    </tr>
    <tr>
      <th>2007-09-30</th>
      <td>3.45</td>
      <td>13321.109</td>
      <td>4.7</td>
    </tr>
    <tr>
      <th>2007-12-31</th>
      <td>6.38</td>
      <td>13391.249</td>
      <td>4.8</td>
    </tr>
    <tr>
      <th>2008-03-31</th>
      <td>2.82</td>
      <td>13366.865</td>
      <td>4.9</td>
    </tr>
    <tr>
      <th>2008-06-30</th>
      <td>8.53</td>
      <td>13415.266</td>
      <td>5.4</td>
    </tr>
    <tr>
      <th>2008-09-30</th>
      <td>-3.16</td>
      <td>13324.600</td>
      <td>6.0</td>
    </tr>
    <tr>
      <th>2008-12-31</th>
      <td>-8.79</td>
      <td>13141.920</td>
      <td>6.9</td>
    </tr>
    <tr>
      <th>2009-03-31</th>
      <td>0.94</td>
      <td>12925.410</td>
      <td>8.1</td>
    </tr>
    <tr>
      <th>2009-06-30</th>
      <td>3.37</td>
      <td>12901.504</td>
      <td>9.2</td>
    </tr>
    <tr>
      <th>2009-09-30</th>
      <td>3.56</td>
      <td>12990.341</td>
      <td>9.6</td>
    </tr>
  </tbody>
</table>
<p>203 rows × 3 columns</p>

</div>



```python
ldata['value2'] = np.random.randn(len(ldata))

```

```python
ldata[:10]

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>date</th>
      <th>item</th>
      <th>value</th>
      <th>value2</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1959-03-31</td>
      <td>realgdp</td>
      <td>2710.349</td>
      <td>0.893833</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1959-03-31</td>
      <td>infl</td>
      <td>0.000</td>
      <td>0.132261</td>
    </tr>
    <tr>
      <th>2</th>
      <td>1959-03-31</td>
      <td>unemp</td>
      <td>5.800</td>
      <td>-0.558454</td>
    </tr>
    <tr>
      <th>3</th>
      <td>1959-06-30</td>
      <td>realgdp</td>
      <td>2778.801</td>
      <td>0.740192</td>
    </tr>
    <tr>
      <th>4</th>
      <td>1959-06-30</td>
      <td>infl</td>
      <td>2.340</td>
      <td>1.313905</td>
    </tr>
    <tr>
      <th>5</th>
      <td>1959-06-30</td>
      <td>unemp</td>
      <td>5.100</td>
      <td>0.386245</td>
    </tr>
    <tr>
      <th>6</th>
      <td>1959-09-30</td>
      <td>realgdp</td>
      <td>2775.488</td>
      <td>-2.524416</td>
    </tr>
    <tr>
      <th>7</th>
      <td>1959-09-30</td>
      <td>infl</td>
      <td>2.740</td>
      <td>-0.931893</td>
    </tr>
    <tr>
      <th>8</th>
      <td>1959-09-30</td>
      <td>unemp</td>
      <td>5.300</td>
      <td>-0.443384</td>
    </tr>
    <tr>
      <th>9</th>
      <td>1959-12-31</td>
      <td>realgdp</td>
      <td>2785.204</td>
      <td>-0.226368</td>
    </tr>
  </tbody>
</table>

</div>



```python
pivoted = ldata.pivot('date', 'item') 

```

```python
pivoted[:5]

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead tr th {
    text-align: left;
}

.dataframe thead tr:last-of-type th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr>
      <th></th>
      <th colspan="3" halign="left">value</th>
      <th colspan="3" halign="left">value2</th>
    </tr>
    <tr>
      <th>item</th>
      <th>infl</th>
      <th>realgdp</th>
      <th>unemp</th>
      <th>infl</th>
      <th>realgdp</th>
      <th>unemp</th>
    </tr>
    <tr>
      <th>date</th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>1959-03-31</th>
      <td>0.00</td>
      <td>2710.349</td>
      <td>5.8</td>
      <td>0.132261</td>
      <td>0.893833</td>
      <td>-0.558454</td>
    </tr>
    <tr>
      <th>1959-06-30</th>
      <td>2.34</td>
      <td>2778.801</td>
      <td>5.1</td>
      <td>1.313905</td>
      <td>0.740192</td>
      <td>0.386245</td>
    </tr>
    <tr>
      <th>1959-09-30</th>
      <td>2.74</td>
      <td>2775.488</td>
      <td>5.3</td>
      <td>-0.931893</td>
      <td>-2.524416</td>
      <td>-0.443384</td>
    </tr>
    <tr>
      <th>1959-12-31</th>
      <td>0.27</td>
      <td>2785.204</td>
      <td>5.6</td>
      <td>1.452034</td>
      <td>-0.226368</td>
      <td>0.286612</td>
    </tr>
    <tr>
      <th>1960-03-31</th>
      <td>2.31</td>
      <td>2847.699</td>
      <td>5.2</td>
      <td>-2.529139</td>
      <td>-0.013556</td>
      <td>0.490404</td>
    </tr>
  </tbody>
</table>

</div>



```python
pivoted['value'][:5]

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th>item</th>
      <th>infl</th>
      <th>realgdp</th>
      <th>unemp</th>
    </tr>
    <tr>
      <th>date</th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>1959-03-31</th>
      <td>0.00</td>
      <td>2710.349</td>
      <td>5.8</td>
    </tr>
    <tr>
      <th>1959-06-30</th>
      <td>2.34</td>
      <td>2778.801</td>
      <td>5.1</td>
    </tr>
    <tr>
      <th>1959-09-30</th>
      <td>2.74</td>
      <td>2775.488</td>
      <td>5.3</td>
    </tr>
    <tr>
      <th>1959-12-31</th>
      <td>0.27</td>
      <td>2785.204</td>
      <td>5.6</td>
    </tr>
    <tr>
      <th>1960-03-31</th>
      <td>2.31</td>
      <td>2847.699</td>
      <td>5.2</td>
    </tr>
  </tbody>
</table>

</div>



```python
unstacked = ldata.set_index(['date', 'item']).unstack('item')

```

```python
unstacked[:7]

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead tr th {
    text-align: left;
}

.dataframe thead tr:last-of-type th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr>
      <th></th>
      <th colspan="3" halign="left">value</th>
      <th colspan="3" halign="left">value2</th>
    </tr>
    <tr>
      <th>item</th>
      <th>infl</th>
      <th>realgdp</th>
      <th>unemp</th>
      <th>infl</th>
      <th>realgdp</th>
      <th>unemp</th>
    </tr>
    <tr>
      <th>date</th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>1959-03-31</th>
      <td>0.00</td>
      <td>2710.349</td>
      <td>5.8</td>
      <td>0.132261</td>
      <td>0.893833</td>
      <td>-0.558454</td>
    </tr>
    <tr>
      <th>1959-06-30</th>
      <td>2.34</td>
      <td>2778.801</td>
      <td>5.1</td>
      <td>1.313905</td>
      <td>0.740192</td>
      <td>0.386245</td>
    </tr>
    <tr>
      <th>1959-09-30</th>
      <td>2.74</td>
      <td>2775.488</td>
      <td>5.3</td>
      <td>-0.931893</td>
      <td>-2.524416</td>
      <td>-0.443384</td>
    </tr>
    <tr>
      <th>1959-12-31</th>
      <td>0.27</td>
      <td>2785.204</td>
      <td>5.6</td>
      <td>1.452034</td>
      <td>-0.226368</td>
      <td>0.286612</td>
    </tr>
    <tr>
      <th>1960-03-31</th>
      <td>2.31</td>
      <td>2847.699</td>
      <td>5.2</td>
      <td>-2.529139</td>
      <td>-0.013556</td>
      <td>0.490404</td>
    </tr>
    <tr>
      <th>1960-06-30</th>
      <td>0.14</td>
      <td>2834.390</td>
      <td>5.2</td>
      <td>1.101432</td>
      <td>-0.391130</td>
      <td>1.111119</td>
    </tr>
    <tr>
      <th>1960-09-30</th>
      <td>2.70</td>
      <td>2839.022</td>
      <td>5.6</td>
      <td>-0.201414</td>
      <td>-0.937953</td>
      <td>1.361491</td>
    </tr>
  </tbody>
</table>

</div>



```python
# 将“宽格式”旋转为“长格式”
df = pd.DataFrame({'key': ['foo', 'bar', 'baz'],   
                   'A': [1, 2, 3],   
                   'B': [4, 5, 6],   
                   'C': [7, 8, 9]})

```

```python
df

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>A</th>
      <th>B</th>
      <th>C</th>
      <th>key</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1</td>
      <td>4</td>
      <td>7</td>
      <td>foo</td>
    </tr>
    <tr>
      <th>1</th>
      <td>2</td>
      <td>5</td>
      <td>8</td>
      <td>bar</td>
    </tr>
    <tr>
      <th>2</th>
      <td>3</td>
      <td>6</td>
      <td>9</td>
      <td>baz</td>
    </tr>
  </tbody>
</table>

</div>



```python
melted = pd.melt(df, ['key'])

```

```python
melted 

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>key</th>
      <th>variable</th>
      <th>value</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>foo</td>
      <td>A</td>
      <td>1</td>
    </tr>
    <tr>
      <th>1</th>
      <td>bar</td>
      <td>A</td>
      <td>2</td>
    </tr>
    <tr>
      <th>2</th>
      <td>baz</td>
      <td>A</td>
      <td>3</td>
    </tr>
    <tr>
      <th>3</th>
      <td>foo</td>
      <td>B</td>
      <td>4</td>
    </tr>
    <tr>
      <th>4</th>
      <td>bar</td>
      <td>B</td>
      <td>5</td>
    </tr>
    <tr>
      <th>5</th>
      <td>baz</td>
      <td>B</td>
      <td>6</td>
    </tr>
    <tr>
      <th>6</th>
      <td>foo</td>
      <td>C</td>
      <td>7</td>
    </tr>
    <tr>
      <th>7</th>
      <td>bar</td>
      <td>C</td>
      <td>8</td>
    </tr>
    <tr>
      <th>8</th>
      <td>baz</td>
      <td>C</td>
      <td>9</td>
    </tr>
  </tbody>
</table>

</div>



```python
reshaped = melted.pivot('key', 'variable', 'value')

```

```python
reshaped 

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th>variable</th>
      <th>A</th>
      <th>B</th>
      <th>C</th>
    </tr>
    <tr>
      <th>key</th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>bar</th>
      <td>2</td>
      <td>5</td>
      <td>8</td>
    </tr>
    <tr>
      <th>baz</th>
      <td>3</td>
      <td>6</td>
      <td>9</td>
    </tr>
    <tr>
      <th>foo</th>
      <td>1</td>
      <td>4</td>
      <td>7</td>
    </tr>
  </tbody>
</table>

</div>



```python
reshaped.reset_index()

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th>variable</th>
      <th>key</th>
      <th>A</th>
      <th>B</th>
      <th>C</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>bar</td>
      <td>2</td>
      <td>5</td>
      <td>8</td>
    </tr>
    <tr>
      <th>1</th>
      <td>baz</td>
      <td>3</td>
      <td>6</td>
      <td>9</td>
    </tr>
    <tr>
      <th>2</th>
      <td>foo</td>
      <td>1</td>
      <td>4</td>
      <td>7</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.melt(df, id_vars=['key'], value_vars=['A', 'B'])

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>key</th>
      <th>variable</th>
      <th>value</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>foo</td>
      <td>A</td>
      <td>1</td>
    </tr>
    <tr>
      <th>1</th>
      <td>bar</td>
      <td>A</td>
      <td>2</td>
    </tr>
    <tr>
      <th>2</th>
      <td>baz</td>
      <td>A</td>
      <td>3</td>
    </tr>
    <tr>
      <th>3</th>
      <td>foo</td>
      <td>B</td>
      <td>4</td>
    </tr>
    <tr>
      <th>4</th>
      <td>bar</td>
      <td>B</td>
      <td>5</td>
    </tr>
    <tr>
      <th>5</th>
      <td>baz</td>
      <td>B</td>
      <td>6</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.melt(df, value_vars=['A', 'B', 'C'])

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>variable</th>
      <th>value</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>A</td>
      <td>1</td>
    </tr>
    <tr>
      <th>1</th>
      <td>A</td>
      <td>2</td>
    </tr>
    <tr>
      <th>2</th>
      <td>A</td>
      <td>3</td>
    </tr>
    <tr>
      <th>3</th>
      <td>B</td>
      <td>4</td>
    </tr>
    <tr>
      <th>4</th>
      <td>B</td>
      <td>5</td>
    </tr>
    <tr>
      <th>5</th>
      <td>B</td>
      <td>6</td>
    </tr>
    <tr>
      <th>6</th>
      <td>C</td>
      <td>7</td>
    </tr>
    <tr>
      <th>7</th>
      <td>C</td>
      <td>8</td>
    </tr>
    <tr>
      <th>8</th>
      <td>C</td>
      <td>9</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.melt(df, value_vars=['key', 'A', 'B'])

```



<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

```
.dataframe tbody tr th {
    vertical-align: top;
}

.dataframe thead th {
    text-align: right;
}

```

</style>

<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>variable</th>
      <th>value</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>key</td>
      <td>foo</td>
    </tr>
    <tr>
      <th>1</th>
      <td>key</td>
      <td>bar</td>
    </tr>
    <tr>
      <th>2</th>
      <td>key</td>
      <td>baz</td>
    </tr>
    <tr>
      <th>3</th>
      <td>A</td>
      <td>1</td>
    </tr>
    <tr>
      <th>4</th>
      <td>A</td>
      <td>2</td>
    </tr>
    <tr>
      <th>5</th>
      <td>A</td>
      <td>3</td>
    </tr>
    <tr>
      <th>6</th>
      <td>B</td>
      <td>4</td>
    </tr>
    <tr>
      <th>7</th>
      <td>B</td>
      <td>5</td>
    </tr>
    <tr>
      <th>8</th>
      <td>B</td>
      <td>6</td>
    </tr>
  </tbody>
</table>

</div>

