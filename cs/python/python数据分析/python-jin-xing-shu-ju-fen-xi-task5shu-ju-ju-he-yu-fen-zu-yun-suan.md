---
title: 'Python进行数据分析task6：数据聚合与分组运算'
date: 2019-07-09 15:43:54
tags: [Data Analysis]
published: true
hideInList: false
feature: /post-images/python-jin-xing-shu-ju-fen-xi-task5shu-ju-ju-he-yu-fen-zu-yun-suan.png
---


```python
# 数据聚合与分组运算
```

```python
# GroupBy 机制
```

```python
import pandas as pd
df = pd.DataFrame({'key1' : ['a', 'a', 'b', 'b', 'a'],
                   'key2' : ['one', 'two', 'one', 'two', 'one'], 
                   'data1' : np.random.randn(5),   
                   'data2' : np.random.randn(5)})
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
      <th>data1</th>
      <th>data2</th>
      <th>key1</th>
      <th>key2</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>-1.092636</td>
      <td>0.416290</td>
      <td>a</td>
      <td>one</td>
    </tr>
    <tr>
      <th>1</th>
      <td>-0.508328</td>
      <td>0.542952</td>
      <td>a</td>
      <td>two</td>
    </tr>
    <tr>
      <th>2</th>
      <td>1.140498</td>
      <td>0.262361</td>
      <td>b</td>
      <td>one</td>
    </tr>
    <tr>
      <th>3</th>
      <td>0.010311</td>
      <td>0.523283</td>
      <td>b</td>
      <td>two</td>
    </tr>
    <tr>
      <th>4</th>
      <td>-0.288394</td>
      <td>-0.852198</td>
      <td>a</td>
      <td>one</td>
    </tr>
  </tbody>
</table>

</div>



```python
grouped = df['data1'].groupby(df['key1'])
grouped
```



```
<pandas.core.groupby.SeriesGroupBy object at 0x000002BAB2E7A5F8>
```



```python
# mean 方法可以计算分组平均值
grouped.mean()
```



```
key1
a   -0.629786
b    0.575405
Name: data1, dtype: float64

```



```python
means = df['data1'].groupby([df['key1'], df['key2']]).mean()
means

```



```
key1  key2
a     one    -0.690515
      two    -0.508328
b     one     1.140498
      two     0.010311
Name: data1, dtype: float64

```



```python
means.unstack()

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
      <th>key2</th>
      <th>one</th>
      <th>two</th>
    </tr>
    <tr>
      <th>key1</th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>a</th>
      <td>-0.690515</td>
      <td>-0.508328</td>
    </tr>
    <tr>
      <th>b</th>
      <td>1.140498</td>
      <td>0.010311</td>
    </tr>
  </tbody>
</table>

</div>



```python
states = np.array(['Ohio', 'California', 'California','Ohio', 'Ohio'])

```

```python
years = np.array([2005, 2005, 2006, 2005, 2006])

```

```python
df['data1'].groupby([states, years]).mean()

```



```
California  2005   -0.508328
            2006    1.140498
Ohio        2005   -0.541162
            2006   -0.288394
Name: data1, dtype: float64

```



```python
df.groupby('key1').mean()

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
      <th>data2</th>
    </tr>
    <tr>
      <th>key1</th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>a</th>
      <td>-0.629786</td>
      <td>0.035681</td>
    </tr>
    <tr>
      <th>b</th>
      <td>0.575405</td>
      <td>0.392822</td>
    </tr>
  </tbody>
</table>

</div>



```python
df.groupby(['key1', 'key2']).mean()

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
      <th>data1</th>
      <th>data2</th>
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
      <th>one</th>
      <td>-0.690515</td>
      <td>-0.217954</td>
    </tr>
    <tr>
      <th>two</th>
      <td>-0.508328</td>
      <td>0.542952</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">b</th>
      <th>one</th>
      <td>1.140498</td>
      <td>0.262361</td>
    </tr>
    <tr>
      <th>two</th>
      <td>0.010311</td>
      <td>0.523283</td>
    </tr>
  </tbody>
</table>

</div>



```python
df.groupby(['key1', 'key2']).size()

```



```
key1  key2
a     one     2
      two     1
b     one     1
      two     1
dtype: int64

```



```python
for name, group in df.groupby('key1'):  
    print(name)  
    print(group)

```

```
a
      data1     data2 key1 key2
0 -1.092636  0.416290    a  one
1 -0.508328  0.542952    a  two
4 -0.288394 -0.852198    a  one
b
      data1     data2 key1 key2
2  1.140498  0.262361    b  one
3  0.010311  0.523283    b  two

```



```python
for (k1, k2), group in df.groupby(['key1', 'key2']):   
    print((k1, k2))   
    print(group)

```

```
('a', 'one')
      data1     data2 key1 key2
0 -1.092636  0.416290    a  one
4 -0.288394 -0.852198    a  one
('a', 'two')
      data1     data2 key1 key2
1 -0.508328  0.542952    a  two
('b', 'one')
      data1     data2 key1 key2
2  1.140498  0.262361    b  one
('b', 'two')
      data1     data2 key1 key2
3  0.010311  0.523283    b  two

```



```python
pieces = dict(list(df.groupby('key1')))

```

```python
pieces['b']

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
      <th>data2</th>
      <th>key1</th>
      <th>key2</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>2</th>
      <td>1.140498</td>
      <td>0.262361</td>
      <td>b</td>
      <td>one</td>
    </tr>
    <tr>
      <th>3</th>
      <td>0.010311</td>
      <td>0.523283</td>
      <td>b</td>
      <td>two</td>
    </tr>
  </tbody>
</table>

</div>



```python
df.dtypes 

```



```
data1    float64
data2    float64
key1      object
key2      object
dtype: object

```



```python
grouped = df.groupby(df.dtypes, axis=1)

```

```python
for dtype, group in grouped:   
    print(dtype)   
    print(group)

```

```
float64
      data1     data2
0 -1.092636  0.416290
1 -0.508328  0.542952
2  1.140498  0.262361
3  0.010311  0.523283
4 -0.288394 -0.852198
object
  key1 key2
0    a  one
1    a  two
2    b  one
3    b  two
4    a  one

```



```python
# 选取一列或列的子集

```

```python
df.groupby('key1')['data1']

```



```
<pandas.core.groupby.SeriesGroupBy object at 0x000002BAB2E633C8>

```



```python
df.groupby('key1')[['data2']]

```



```
<pandas.core.groupby.DataFrameGroupBy object at 0x000002BAB2E6C048>

```



```python
df['data1'].groupby(df['key1'])

```



```
<pandas.core.groupby.SeriesGroupBy object at 0x000002BAB2E3CB00>

```



```python
df[['data2']].groupby(df['key1'])

```



```
<pandas.core.groupby.DataFrameGroupBy object at 0x000002BAB2E3C128>

```



```python
df.groupby(['key1', 'key2'])[['data2']].mean()

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
      <th>data2</th>
    </tr>
    <tr>
      <th>key1</th>
      <th>key2</th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th rowspan="2" valign="top">a</th>
      <th>one</th>
      <td>-0.217954</td>
    </tr>
    <tr>
      <th>two</th>
      <td>0.542952</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">b</th>
      <th>one</th>
      <td>0.262361</td>
    </tr>
    <tr>
      <th>two</th>
      <td>0.523283</td>
    </tr>
  </tbody>
</table>

</div>



```python
s_grouped = df.groupby(['key1', 'key2'])['data2']
s_grouped

```



```
<pandas.core.groupby.SeriesGroupBy object at 0x000002BAB2E63D68>

```



```python
s_grouped.mean()

```



```
key1  key2
a     one    -0.217954
      two     0.542952
b     one     0.262361
      two     0.523283
Name: data2, dtype: float64

```



```python
# 通过字典或 Series 进行分组
people = pd.DataFrame(np.random.randn(5, 5),   
                      columns=['a', 'b', 'c', 'd', 'e'],    
                      index=['Joe', 'Steve', 'Wes', 'Jim', 'Travis'])

```

```python
people.iloc[2:3, [1, 2]] = np.nan
people 

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
      <th>Joe</th>
      <td>-1.402726</td>
      <td>1.127025</td>
      <td>0.188192</td>
      <td>-0.210086</td>
      <td>1.065474</td>
    </tr>
    <tr>
      <th>Steve</th>
      <td>0.060840</td>
      <td>0.692850</td>
      <td>0.964600</td>
      <td>-2.420033</td>
      <td>-0.030906</td>
    </tr>
    <tr>
      <th>Wes</th>
      <td>-0.327447</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>-2.124776</td>
      <td>1.150542</td>
    </tr>
    <tr>
      <th>Jim</th>
      <td>0.196755</td>
      <td>0.332546</td>
      <td>-2.086450</td>
      <td>-1.560407</td>
      <td>-0.205801</td>
    </tr>
    <tr>
      <th>Travis</th>
      <td>-0.147255</td>
      <td>-2.792737</td>
      <td>-0.335206</td>
      <td>0.719601</td>
      <td>0.854173</td>
    </tr>
  </tbody>
</table>

</div>



```python
mapping = {'a': 'red', 'b': 'red', 'c': 'blue', 
           'd': 'blue', 'e': 'red', 'f' : 'orange'}

```

```python
by_column = people.groupby(mapping, axis=1)

```

```python
by_column.sum()

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
      <th>blue</th>
      <th>red</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>Joe</th>
      <td>-0.021894</td>
      <td>0.789773</td>
    </tr>
    <tr>
      <th>Steve</th>
      <td>-1.455433</td>
      <td>0.722784</td>
    </tr>
    <tr>
      <th>Wes</th>
      <td>-2.124776</td>
      <td>0.823095</td>
    </tr>
    <tr>
      <th>Jim</th>
      <td>-3.646857</td>
      <td>0.323500</td>
    </tr>
    <tr>
      <th>Travis</th>
      <td>0.384395</td>
      <td>-2.085819</td>
    </tr>
  </tbody>
</table>

</div>



```python
map_series = pd.Series(mapping) 

```

```python
map_series 

```



```
a       red
b       red
c      blue
d      blue
e       red
f    orange
dtype: object

```



```python
people.groupby(map_series, axis=1).count()

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
      <th>blue</th>
      <th>red</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>Joe</th>
      <td>2</td>
      <td>3</td>
    </tr>
    <tr>
      <th>Steve</th>
      <td>2</td>
      <td>3</td>
    </tr>
    <tr>
      <th>Wes</th>
      <td>1</td>
      <td>2</td>
    </tr>
    <tr>
      <th>Jim</th>
      <td>2</td>
      <td>3</td>
    </tr>
    <tr>
      <th>Travis</th>
      <td>2</td>
      <td>3</td>
    </tr>
  </tbody>
</table>

</div>



```python
# 通过函数进行分组
people.groupby(len).sum()

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
      <th>3</th>
      <td>-1.533417</td>
      <td>1.459571</td>
      <td>-1.898258</td>
      <td>-3.895270</td>
      <td>2.010214</td>
    </tr>
    <tr>
      <th>5</th>
      <td>0.060840</td>
      <td>0.692850</td>
      <td>0.964600</td>
      <td>-2.420033</td>
      <td>-0.030906</td>
    </tr>
    <tr>
      <th>6</th>
      <td>-0.147255</td>
      <td>-2.792737</td>
      <td>-0.335206</td>
      <td>0.719601</td>
      <td>0.854173</td>
    </tr>
  </tbody>
</table>

</div>



```python
key_list = ['one', 'one', 'one', 'two', 'two']

```

```python
people.groupby([len, key_list]).min()

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
      <th>e</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th rowspan="2" valign="top">3</th>
      <th>one</th>
      <td>-1.402726</td>
      <td>1.127025</td>
      <td>0.188192</td>
      <td>-2.124776</td>
      <td>1.065474</td>
    </tr>
    <tr>
      <th>two</th>
      <td>0.196755</td>
      <td>0.332546</td>
      <td>-2.086450</td>
      <td>-1.560407</td>
      <td>-0.205801</td>
    </tr>
    <tr>
      <th>5</th>
      <th>one</th>
      <td>0.060840</td>
      <td>0.692850</td>
      <td>0.964600</td>
      <td>-2.420033</td>
      <td>-0.030906</td>
    </tr>
    <tr>
      <th>6</th>
      <th>two</th>
      <td>-0.147255</td>
      <td>-2.792737</td>
      <td>-0.335206</td>
      <td>0.719601</td>
      <td>0.854173</td>
    </tr>
  </tbody>
</table>

</div>



```python
# 根据索引级别分组
columns = pd.MultiIndex.from_arrays([['US', 'US', 'US', 'JP', 'JP'],  
                                     [1, 3, 5, 1, 3]],    
                                     names=['cty', 'tenor'])

```

```python
hier_df = pd.DataFrame(np.random.randn(4, 5), columns=columns)

```

```python
hier_df

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
      <th>cty</th>
      <th colspan="3" halign="left">US</th>
      <th colspan="2" halign="left">JP</th>
    </tr>
    <tr>
      <th>tenor</th>
      <th>1</th>
      <th>3</th>
      <th>5</th>
      <th>1</th>
      <th>3</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>-1.922322</td>
      <td>0.608164</td>
      <td>1.001256</td>
      <td>-1.365800</td>
      <td>0.489801</td>
    </tr>
    <tr>
      <th>1</th>
      <td>0.662488</td>
      <td>-0.607478</td>
      <td>-0.197785</td>
      <td>0.426749</td>
      <td>-0.432160</td>
    </tr>
    <tr>
      <th>2</th>
      <td>0.518344</td>
      <td>1.120054</td>
      <td>-0.519715</td>
      <td>0.488855</td>
      <td>0.056445</td>
    </tr>
    <tr>
      <th>3</th>
      <td>-0.472827</td>
      <td>0.233078</td>
      <td>-0.129130</td>
      <td>-0.360760</td>
      <td>-0.618475</td>
    </tr>
  </tbody>
</table>

</div>



```python
hier_df.groupby(level='cty', axis=1).count()

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
      <th>cty</th>
      <th>JP</th>
      <th>US</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>2</td>
      <td>3</td>
    </tr>
    <tr>
      <th>1</th>
      <td>2</td>
      <td>3</td>
    </tr>
    <tr>
      <th>2</th>
      <td>2</td>
      <td>3</td>
    </tr>
    <tr>
      <th>3</th>
      <td>2</td>
      <td>3</td>
    </tr>
  </tbody>
</table>

</div>



```python
# 数据聚合
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
      <th>data1</th>
      <th>data2</th>
      <th>key1</th>
      <th>key2</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>-1.092636</td>
      <td>0.416290</td>
      <td>a</td>
      <td>one</td>
    </tr>
    <tr>
      <th>1</th>
      <td>-0.508328</td>
      <td>0.542952</td>
      <td>a</td>
      <td>two</td>
    </tr>
    <tr>
      <th>2</th>
      <td>1.140498</td>
      <td>0.262361</td>
      <td>b</td>
      <td>one</td>
    </tr>
    <tr>
      <th>3</th>
      <td>0.010311</td>
      <td>0.523283</td>
      <td>b</td>
      <td>two</td>
    </tr>
    <tr>
      <th>4</th>
      <td>-0.288394</td>
      <td>-0.852198</td>
      <td>a</td>
      <td>one</td>
    </tr>
  </tbody>
</table>

</div>



```python
grouped = df.groupby('key1')

```

```python
grouped['data1'].quantile(0.9)

```



```
key1
a   -0.332381
b    1.027480
Name: data1, dtype: float64

```



```python
def peak_to_peak(arr):   
    return arr.max() - arr.min()

```

```python
grouped.agg(peak_to_peak)

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
      <th>data2</th>
    </tr>
    <tr>
      <th>key1</th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>a</th>
      <td>0.804242</td>
      <td>1.395150</td>
    </tr>
    <tr>
      <th>b</th>
      <td>1.130187</td>
      <td>0.260922</td>
    </tr>
  </tbody>
</table>

</div>



```python
grouped.describe()

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
      <th colspan="8" halign="left">data1</th>
      <th colspan="8" halign="left">data2</th>
    </tr>
    <tr>
      <th></th>
      <th>count</th>
      <th>mean</th>
      <th>std</th>
      <th>min</th>
      <th>25%</th>
      <th>50%</th>
      <th>75%</th>
      <th>max</th>
      <th>count</th>
      <th>mean</th>
      <th>std</th>
      <th>min</th>
      <th>25%</th>
      <th>50%</th>
      <th>75%</th>
      <th>max</th>
    </tr>
    <tr>
      <th>key1</th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
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
      <th>a</th>
      <td>3.0</td>
      <td>-0.629786</td>
      <td>0.415650</td>
      <td>-1.092636</td>
      <td>-0.800482</td>
      <td>-0.508328</td>
      <td>-0.398361</td>
      <td>-0.288394</td>
      <td>3.0</td>
      <td>0.035681</td>
      <td>0.77153</td>
      <td>-0.852198</td>
      <td>-0.217954</td>
      <td>0.416290</td>
      <td>0.479621</td>
      <td>0.542952</td>
    </tr>
    <tr>
      <th>b</th>
      <td>2.0</td>
      <td>0.575405</td>
      <td>0.799163</td>
      <td>0.010311</td>
      <td>0.292858</td>
      <td>0.575405</td>
      <td>0.857952</td>
      <td>1.140498</td>
      <td>2.0</td>
      <td>0.392822</td>
      <td>0.18450</td>
      <td>0.262361</td>
      <td>0.327591</td>
      <td>0.392822</td>
      <td>0.458052</td>
      <td>0.523283</td>
    </tr>
  </tbody>
</table>

</div>



```python
# 面向列的多函数应用
tips = pd.read_csv('examples/tips.csv') 

```

```python
tips['tip_pct'] = tips['tip'] / tips['total_bill'] 

```

```python
tips[:6] 

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
      <th>total_bill</th>
      <th>tip</th>
      <th>smoker</th>
      <th>day</th>
      <th>time</th>
      <th>size</th>
      <th>tip_pct</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>16.99</td>
      <td>1.01</td>
      <td>No</td>
      <td>Sun</td>
      <td>Dinner</td>
      <td>2</td>
      <td>0.059447</td>
    </tr>
    <tr>
      <th>1</th>
      <td>10.34</td>
      <td>1.66</td>
      <td>No</td>
      <td>Sun</td>
      <td>Dinner</td>
      <td>3</td>
      <td>0.160542</td>
    </tr>
    <tr>
      <th>2</th>
      <td>21.01</td>
      <td>3.50</td>
      <td>No</td>
      <td>Sun</td>
      <td>Dinner</td>
      <td>3</td>
      <td>0.166587</td>
    </tr>
    <tr>
      <th>3</th>
      <td>23.68</td>
      <td>3.31</td>
      <td>No</td>
      <td>Sun</td>
      <td>Dinner</td>
      <td>2</td>
      <td>0.139780</td>
    </tr>
    <tr>
      <th>4</th>
      <td>24.59</td>
      <td>3.61</td>
      <td>No</td>
      <td>Sun</td>
      <td>Dinner</td>
      <td>4</td>
      <td>0.146808</td>
    </tr>
    <tr>
      <th>5</th>
      <td>25.29</td>
      <td>4.71</td>
      <td>No</td>
      <td>Sun</td>
      <td>Dinner</td>
      <td>4</td>
      <td>0.186240</td>
    </tr>
  </tbody>
</table>

</div>



```python
grouped = tips.groupby(['day', 'smoker'])

```

```python
grouped_pct = grouped['tip_pct']

```

```python
grouped_pct.agg('mean')

```



```
day   smoker
Fri   No        0.151650
      Yes       0.174783
Sat   No        0.158048
      Yes       0.147906
Sun   No        0.160113
      Yes       0.187250
Thur  No        0.160298
      Yes       0.163863
Name: tip_pct, dtype: float64

```



```python
grouped_pct.agg(['mean', 'std', peak_to_peak])

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
      <th>mean</th>
      <th>std</th>
      <th>peak_to_peak</th>
    </tr>
    <tr>
      <th>day</th>
      <th>smoker</th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th rowspan="2" valign="top">Fri</th>
      <th>No</th>
      <td>0.151650</td>
      <td>0.028123</td>
      <td>0.067349</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.174783</td>
      <td>0.051293</td>
      <td>0.159925</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Sat</th>
      <th>No</th>
      <td>0.158048</td>
      <td>0.039767</td>
      <td>0.235193</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.147906</td>
      <td>0.061375</td>
      <td>0.290095</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Sun</th>
      <th>No</th>
      <td>0.160113</td>
      <td>0.042347</td>
      <td>0.193226</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.187250</td>
      <td>0.154134</td>
      <td>0.644685</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Thur</th>
      <th>No</th>
      <td>0.160298</td>
      <td>0.038774</td>
      <td>0.193350</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.163863</td>
      <td>0.039389</td>
      <td>0.151240</td>
    </tr>
  </tbody>
</table>

</div>



```python
grouped_pct.agg([('foo', 'mean'), ('bar', np.std)])

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
      <th>foo</th>
      <th>bar</th>
    </tr>
    <tr>
      <th>day</th>
      <th>smoker</th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th rowspan="2" valign="top">Fri</th>
      <th>No</th>
      <td>0.151650</td>
      <td>0.028123</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.174783</td>
      <td>0.051293</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Sat</th>
      <th>No</th>
      <td>0.158048</td>
      <td>0.039767</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.147906</td>
      <td>0.061375</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Sun</th>
      <th>No</th>
      <td>0.160113</td>
      <td>0.042347</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.187250</td>
      <td>0.154134</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Thur</th>
      <th>No</th>
      <td>0.160298</td>
      <td>0.038774</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.163863</td>
      <td>0.039389</td>
    </tr>
  </tbody>
</table>

</div>



```python
functions = ['count', 'mean', 'max']

```

```python
result = grouped['tip_pct', 'total_bill'].agg(functions)
result 

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
      <th></th>
      <th colspan="3" halign="left">tip_pct</th>
      <th colspan="3" halign="left">total_bill</th>
    </tr>
    <tr>
      <th></th>
      <th></th>
      <th>count</th>
      <th>mean</th>
      <th>max</th>
      <th>count</th>
      <th>mean</th>
      <th>max</th>
    </tr>
    <tr>
      <th>day</th>
      <th>smoker</th>
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
      <th rowspan="2" valign="top">Fri</th>
      <th>No</th>
      <td>4</td>
      <td>0.151650</td>
      <td>0.187735</td>
      <td>4</td>
      <td>18.420000</td>
      <td>22.75</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>15</td>
      <td>0.174783</td>
      <td>0.263480</td>
      <td>15</td>
      <td>16.813333</td>
      <td>40.17</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Sat</th>
      <th>No</th>
      <td>45</td>
      <td>0.158048</td>
      <td>0.291990</td>
      <td>45</td>
      <td>19.661778</td>
      <td>48.33</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>42</td>
      <td>0.147906</td>
      <td>0.325733</td>
      <td>42</td>
      <td>21.276667</td>
      <td>50.81</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Sun</th>
      <th>No</th>
      <td>57</td>
      <td>0.160113</td>
      <td>0.252672</td>
      <td>57</td>
      <td>20.506667</td>
      <td>48.17</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>19</td>
      <td>0.187250</td>
      <td>0.710345</td>
      <td>19</td>
      <td>24.120000</td>
      <td>45.35</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Thur</th>
      <th>No</th>
      <td>45</td>
      <td>0.160298</td>
      <td>0.266312</td>
      <td>45</td>
      <td>17.113111</td>
      <td>41.19</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>17</td>
      <td>0.163863</td>
      <td>0.241255</td>
      <td>17</td>
      <td>19.190588</td>
      <td>43.11</td>
    </tr>
  </tbody>
</table>

</div>



```python
result['tip_pct']

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
      <th>count</th>
      <th>mean</th>
      <th>max</th>
    </tr>
    <tr>
      <th>day</th>
      <th>smoker</th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th rowspan="2" valign="top">Fri</th>
      <th>No</th>
      <td>4</td>
      <td>0.151650</td>
      <td>0.187735</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>15</td>
      <td>0.174783</td>
      <td>0.263480</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Sat</th>
      <th>No</th>
      <td>45</td>
      <td>0.158048</td>
      <td>0.291990</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>42</td>
      <td>0.147906</td>
      <td>0.325733</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Sun</th>
      <th>No</th>
      <td>57</td>
      <td>0.160113</td>
      <td>0.252672</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>19</td>
      <td>0.187250</td>
      <td>0.710345</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Thur</th>
      <th>No</th>
      <td>45</td>
      <td>0.160298</td>
      <td>0.266312</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>17</td>
      <td>0.163863</td>
      <td>0.241255</td>
    </tr>
  </tbody>
</table>

</div>



```python
ftuples = [('Durchschnitt', 'mean'),('Abweichung', np.var)]

```

```python
grouped['tip_pct', 'total_bill'].agg(ftuples)

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
      <th></th>
      <th colspan="2" halign="left">tip_pct</th>
      <th colspan="2" halign="left">total_bill</th>
    </tr>
    <tr>
      <th></th>
      <th></th>
      <th>Durchschnitt</th>
      <th>Abweichung</th>
      <th>Durchschnitt</th>
      <th>Abweichung</th>
    </tr>
    <tr>
      <th>day</th>
      <th>smoker</th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th rowspan="2" valign="top">Fri</th>
      <th>No</th>
      <td>0.151650</td>
      <td>0.000791</td>
      <td>18.420000</td>
      <td>25.596333</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.174783</td>
      <td>0.002631</td>
      <td>16.813333</td>
      <td>82.562438</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Sat</th>
      <th>No</th>
      <td>0.158048</td>
      <td>0.001581</td>
      <td>19.661778</td>
      <td>79.908965</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.147906</td>
      <td>0.003767</td>
      <td>21.276667</td>
      <td>101.387535</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Sun</th>
      <th>No</th>
      <td>0.160113</td>
      <td>0.001793</td>
      <td>20.506667</td>
      <td>66.099980</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.187250</td>
      <td>0.023757</td>
      <td>24.120000</td>
      <td>109.046044</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Thur</th>
      <th>No</th>
      <td>0.160298</td>
      <td>0.001503</td>
      <td>17.113111</td>
      <td>59.625081</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.163863</td>
      <td>0.001551</td>
      <td>19.190588</td>
      <td>69.808518</td>
    </tr>
  </tbody>
</table>

</div>



```python
grouped.agg({'tip' : np.max, 'size' : 'sum'})

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
      <th>tip</th>
      <th>size</th>
    </tr>
    <tr>
      <th>day</th>
      <th>smoker</th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th rowspan="2" valign="top">Fri</th>
      <th>No</th>
      <td>3.50</td>
      <td>9</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>4.73</td>
      <td>31</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Sat</th>
      <th>No</th>
      <td>9.00</td>
      <td>115</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>10.00</td>
      <td>104</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Sun</th>
      <th>No</th>
      <td>6.00</td>
      <td>167</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>6.50</td>
      <td>49</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Thur</th>
      <th>No</th>
      <td>6.70</td>
      <td>112</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>5.00</td>
      <td>40</td>
    </tr>
  </tbody>
</table>

</div>



```python
grouped.agg({'tip_pct' : ['min', 'max', 'mean', 'std'],   
             'size' : 'sum'})

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
      <th></th>
      <th colspan="4" halign="left">tip_pct</th>
      <th>size</th>
    </tr>
    <tr>
      <th></th>
      <th></th>
      <th>min</th>
      <th>max</th>
      <th>mean</th>
      <th>std</th>
      <th>sum</th>
    </tr>
    <tr>
      <th>day</th>
      <th>smoker</th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th rowspan="2" valign="top">Fri</th>
      <th>No</th>
      <td>0.120385</td>
      <td>0.187735</td>
      <td>0.151650</td>
      <td>0.028123</td>
      <td>9</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.103555</td>
      <td>0.263480</td>
      <td>0.174783</td>
      <td>0.051293</td>
      <td>31</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Sat</th>
      <th>No</th>
      <td>0.056797</td>
      <td>0.291990</td>
      <td>0.158048</td>
      <td>0.039767</td>
      <td>115</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.035638</td>
      <td>0.325733</td>
      <td>0.147906</td>
      <td>0.061375</td>
      <td>104</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Sun</th>
      <th>No</th>
      <td>0.059447</td>
      <td>0.252672</td>
      <td>0.160113</td>
      <td>0.042347</td>
      <td>167</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.065660</td>
      <td>0.710345</td>
      <td>0.187250</td>
      <td>0.154134</td>
      <td>49</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Thur</th>
      <th>No</th>
      <td>0.072961</td>
      <td>0.266312</td>
      <td>0.160298</td>
      <td>0.038774</td>
      <td>112</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.090014</td>
      <td>0.241255</td>
      <td>0.163863</td>
      <td>0.039389</td>
      <td>40</td>
    </tr>
  </tbody>
</table>

</div>



```python
# 以“没有行索引”的形式返回聚合数据 
tips.groupby(['day', 'smoker'], as_index=False).mean()

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
      <th>day</th>
      <th>smoker</th>
      <th>total_bill</th>
      <th>tip</th>
      <th>size</th>
      <th>tip_pct</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>Fri</td>
      <td>No</td>
      <td>18.420000</td>
      <td>2.812500</td>
      <td>2.250000</td>
      <td>0.151650</td>
    </tr>
    <tr>
      <th>1</th>
      <td>Fri</td>
      <td>Yes</td>
      <td>16.813333</td>
      <td>2.714000</td>
      <td>2.066667</td>
      <td>0.174783</td>
    </tr>
    <tr>
      <th>2</th>
      <td>Sat</td>
      <td>No</td>
      <td>19.661778</td>
      <td>3.102889</td>
      <td>2.555556</td>
      <td>0.158048</td>
    </tr>
    <tr>
      <th>3</th>
      <td>Sat</td>
      <td>Yes</td>
      <td>21.276667</td>
      <td>2.875476</td>
      <td>2.476190</td>
      <td>0.147906</td>
    </tr>
    <tr>
      <th>4</th>
      <td>Sun</td>
      <td>No</td>
      <td>20.506667</td>
      <td>3.167895</td>
      <td>2.929825</td>
      <td>0.160113</td>
    </tr>
    <tr>
      <th>5</th>
      <td>Sun</td>
      <td>Yes</td>
      <td>24.120000</td>
      <td>3.516842</td>
      <td>2.578947</td>
      <td>0.187250</td>
    </tr>
    <tr>
      <th>6</th>
      <td>Thur</td>
      <td>No</td>
      <td>17.113111</td>
      <td>2.673778</td>
      <td>2.488889</td>
      <td>0.160298</td>
    </tr>
    <tr>
      <th>7</th>
      <td>Thur</td>
      <td>Yes</td>
      <td>19.190588</td>
      <td>3.030000</td>
      <td>2.352941</td>
      <td>0.163863</td>
    </tr>
  </tbody>
</table>

</div>



```python
# apply：一般性的“拆分－应用－合并”
def top(df, n=5, column='tip_pct'):   
    return df.sort_values(by=column)[-n:] 

```

```python
top(tips, n=6)

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
      <th>total_bill</th>
      <th>tip</th>
      <th>smoker</th>
      <th>day</th>
      <th>time</th>
      <th>size</th>
      <th>tip_pct</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>109</th>
      <td>14.31</td>
      <td>4.00</td>
      <td>Yes</td>
      <td>Sat</td>
      <td>Dinner</td>
      <td>2</td>
      <td>0.279525</td>
    </tr>
    <tr>
      <th>183</th>
      <td>23.17</td>
      <td>6.50</td>
      <td>Yes</td>
      <td>Sun</td>
      <td>Dinner</td>
      <td>4</td>
      <td>0.280535</td>
    </tr>
    <tr>
      <th>232</th>
      <td>11.61</td>
      <td>3.39</td>
      <td>No</td>
      <td>Sat</td>
      <td>Dinner</td>
      <td>2</td>
      <td>0.291990</td>
    </tr>
    <tr>
      <th>67</th>
      <td>3.07</td>
      <td>1.00</td>
      <td>Yes</td>
      <td>Sat</td>
      <td>Dinner</td>
      <td>1</td>
      <td>0.325733</td>
    </tr>
    <tr>
      <th>178</th>
      <td>9.60</td>
      <td>4.00</td>
      <td>Yes</td>
      <td>Sun</td>
      <td>Dinner</td>
      <td>2</td>
      <td>0.416667</td>
    </tr>
    <tr>
      <th>172</th>
      <td>7.25</td>
      <td>5.15</td>
      <td>Yes</td>
      <td>Sun</td>
      <td>Dinner</td>
      <td>2</td>
      <td>0.710345</td>
    </tr>
  </tbody>
</table>

</div>



```python
tips.groupby('smoker').apply(top)

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
      <th>total_bill</th>
      <th>tip</th>
      <th>smoker</th>
      <th>day</th>
      <th>time</th>
      <th>size</th>
      <th>tip_pct</th>
    </tr>
    <tr>
      <th>smoker</th>
      <th></th>
      <th></th>
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
      <th rowspan="5" valign="top">No</th>
      <th>88</th>
      <td>24.71</td>
      <td>5.85</td>
      <td>No</td>
      <td>Thur</td>
      <td>Lunch</td>
      <td>2</td>
      <td>0.236746</td>
    </tr>
    <tr>
      <th>185</th>
      <td>20.69</td>
      <td>5.00</td>
      <td>No</td>
      <td>Sun</td>
      <td>Dinner</td>
      <td>5</td>
      <td>0.241663</td>
    </tr>
    <tr>
      <th>51</th>
      <td>10.29</td>
      <td>2.60</td>
      <td>No</td>
      <td>Sun</td>
      <td>Dinner</td>
      <td>2</td>
      <td>0.252672</td>
    </tr>
    <tr>
      <th>149</th>
      <td>7.51</td>
      <td>2.00</td>
      <td>No</td>
      <td>Thur</td>
      <td>Lunch</td>
      <td>2</td>
      <td>0.266312</td>
    </tr>
    <tr>
      <th>232</th>
      <td>11.61</td>
      <td>3.39</td>
      <td>No</td>
      <td>Sat</td>
      <td>Dinner</td>
      <td>2</td>
      <td>0.291990</td>
    </tr>
    <tr>
      <th rowspan="5" valign="top">Yes</th>
      <th>109</th>
      <td>14.31</td>
      <td>4.00</td>
      <td>Yes</td>
      <td>Sat</td>
      <td>Dinner</td>
      <td>2</td>
      <td>0.279525</td>
    </tr>
    <tr>
      <th>183</th>
      <td>23.17</td>
      <td>6.50</td>
      <td>Yes</td>
      <td>Sun</td>
      <td>Dinner</td>
      <td>4</td>
      <td>0.280535</td>
    </tr>
    <tr>
      <th>67</th>
      <td>3.07</td>
      <td>1.00</td>
      <td>Yes</td>
      <td>Sat</td>
      <td>Dinner</td>
      <td>1</td>
      <td>0.325733</td>
    </tr>
    <tr>
      <th>178</th>
      <td>9.60</td>
      <td>4.00</td>
      <td>Yes</td>
      <td>Sun</td>
      <td>Dinner</td>
      <td>2</td>
      <td>0.416667</td>
    </tr>
    <tr>
      <th>172</th>
      <td>7.25</td>
      <td>5.15</td>
      <td>Yes</td>
      <td>Sun</td>
      <td>Dinner</td>
      <td>2</td>
      <td>0.710345</td>
    </tr>
  </tbody>
</table>

</div>



```python
tips.groupby(['smoker', 'day']).apply(top, n=1, column='total_bill')

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
      <th></th>
      <th>total_bill</th>
      <th>tip</th>
      <th>smoker</th>
      <th>day</th>
      <th>time</th>
      <th>size</th>
      <th>tip_pct</th>
    </tr>
    <tr>
      <th>smoker</th>
      <th>day</th>
      <th></th>
      <th></th>
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
      <th rowspan="4" valign="top">No</th>
      <th>Fri</th>
      <th>94</th>
      <td>22.75</td>
      <td>3.25</td>
      <td>No</td>
      <td>Fri</td>
      <td>Dinner</td>
      <td>2</td>
      <td>0.142857</td>
    </tr>
    <tr>
      <th>Sat</th>
      <th>212</th>
      <td>48.33</td>
      <td>9.00</td>
      <td>No</td>
      <td>Sat</td>
      <td>Dinner</td>
      <td>4</td>
      <td>0.186220</td>
    </tr>
    <tr>
      <th>Sun</th>
      <th>156</th>
      <td>48.17</td>
      <td>5.00</td>
      <td>No</td>
      <td>Sun</td>
      <td>Dinner</td>
      <td>6</td>
      <td>0.103799</td>
    </tr>
    <tr>
      <th>Thur</th>
      <th>142</th>
      <td>41.19</td>
      <td>5.00</td>
      <td>No</td>
      <td>Thur</td>
      <td>Lunch</td>
      <td>5</td>
      <td>0.121389</td>
    </tr>
    <tr>
      <th rowspan="4" valign="top">Yes</th>
      <th>Fri</th>
      <th>95</th>
      <td>40.17</td>
      <td>4.73</td>
      <td>Yes</td>
      <td>Fri</td>
      <td>Dinner</td>
      <td>4</td>
      <td>0.117750</td>
    </tr>
    <tr>
      <th>Sat</th>
      <th>170</th>
      <td>50.81</td>
      <td>10.00</td>
      <td>Yes</td>
      <td>Sat</td>
      <td>Dinner</td>
      <td>3</td>
      <td>0.196812</td>
    </tr>
    <tr>
      <th>Sun</th>
      <th>182</th>
      <td>45.35</td>
      <td>3.50</td>
      <td>Yes</td>
      <td>Sun</td>
      <td>Dinner</td>
      <td>3</td>
      <td>0.077178</td>
    </tr>
    <tr>
      <th>Thur</th>
      <th>197</th>
      <td>43.11</td>
      <td>5.00</td>
      <td>Yes</td>
      <td>Thur</td>
      <td>Lunch</td>
      <td>4</td>
      <td>0.115982</td>
    </tr>
  </tbody>
</table>

</div>



```python
result = tips.groupby('smoker')['tip_pct'].describe()

```

```python
result 

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
      <th>count</th>
      <th>mean</th>
      <th>std</th>
      <th>min</th>
      <th>25%</th>
      <th>50%</th>
      <th>75%</th>
      <th>max</th>
    </tr>
    <tr>
      <th>smoker</th>
      <th></th>
      <th></th>
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
      <th>No</th>
      <td>151.0</td>
      <td>0.159328</td>
      <td>0.039910</td>
      <td>0.056797</td>
      <td>0.136906</td>
      <td>0.155625</td>
      <td>0.185014</td>
      <td>0.291990</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>93.0</td>
      <td>0.163196</td>
      <td>0.085119</td>
      <td>0.035638</td>
      <td>0.106771</td>
      <td>0.153846</td>
      <td>0.195059</td>
      <td>0.710345</td>
    </tr>
  </tbody>
</table>

</div>



```python
result.unstack('smoker')

```



```
       smoker
count  No        151.000000
       Yes        93.000000
mean   No          0.159328
       Yes         0.163196
std    No          0.039910
       Yes         0.085119
min    No          0.056797
       Yes         0.035638
25%    No          0.136906
       Yes         0.106771
50%    No          0.155625
       Yes         0.153846
75%    No          0.185014
       Yes         0.195059
max    No          0.291990
       Yes         0.710345
dtype: float64

```



```python
f = lambda x: x.describe() 
grouped.apply(f)

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
      <th></th>
      <th>total_bill</th>
      <th>tip</th>
      <th>size</th>
      <th>tip_pct</th>
    </tr>
    <tr>
      <th>day</th>
      <th>smoker</th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th rowspan="16" valign="top">Fri</th>
      <th rowspan="8" valign="top">No</th>
      <th>count</th>
      <td>4.000000</td>
      <td>4.000000</td>
      <td>4.000000</td>
      <td>4.000000</td>
    </tr>
    <tr>
      <th>mean</th>
      <td>18.420000</td>
      <td>2.812500</td>
      <td>2.250000</td>
      <td>0.151650</td>
    </tr>
    <tr>
      <th>std</th>
      <td>5.059282</td>
      <td>0.898494</td>
      <td>0.500000</td>
      <td>0.028123</td>
    </tr>
    <tr>
      <th>min</th>
      <td>12.460000</td>
      <td>1.500000</td>
      <td>2.000000</td>
      <td>0.120385</td>
    </tr>
    <tr>
      <th>25%</th>
      <td>15.100000</td>
      <td>2.625000</td>
      <td>2.000000</td>
      <td>0.137239</td>
    </tr>
    <tr>
      <th>50%</th>
      <td>19.235000</td>
      <td>3.125000</td>
      <td>2.000000</td>
      <td>0.149241</td>
    </tr>
    <tr>
      <th>75%</th>
      <td>22.555000</td>
      <td>3.312500</td>
      <td>2.250000</td>
      <td>0.163652</td>
    </tr>
    <tr>
      <th>max</th>
      <td>22.750000</td>
      <td>3.500000</td>
      <td>3.000000</td>
      <td>0.187735</td>
    </tr>
    <tr>
      <th rowspan="8" valign="top">Yes</th>
      <th>count</th>
      <td>15.000000</td>
      <td>15.000000</td>
      <td>15.000000</td>
      <td>15.000000</td>
    </tr>
    <tr>
      <th>mean</th>
      <td>16.813333</td>
      <td>2.714000</td>
      <td>2.066667</td>
      <td>0.174783</td>
    </tr>
    <tr>
      <th>std</th>
      <td>9.086388</td>
      <td>1.077668</td>
      <td>0.593617</td>
      <td>0.051293</td>
    </tr>
    <tr>
      <th>min</th>
      <td>5.750000</td>
      <td>1.000000</td>
      <td>1.000000</td>
      <td>0.103555</td>
    </tr>
    <tr>
      <th>25%</th>
      <td>11.690000</td>
      <td>1.960000</td>
      <td>2.000000</td>
      <td>0.133739</td>
    </tr>
    <tr>
      <th>50%</th>
      <td>13.420000</td>
      <td>2.500000</td>
      <td>2.000000</td>
      <td>0.173913</td>
    </tr>
    <tr>
      <th>75%</th>
      <td>18.665000</td>
      <td>3.240000</td>
      <td>2.000000</td>
      <td>0.209240</td>
    </tr>
    <tr>
      <th>max</th>
      <td>40.170000</td>
      <td>4.730000</td>
      <td>4.000000</td>
      <td>0.263480</td>
    </tr>
    <tr>
      <th rowspan="14" valign="top">Sat</th>
      <th rowspan="8" valign="top">No</th>
      <th>count</th>
      <td>45.000000</td>
      <td>45.000000</td>
      <td>45.000000</td>
      <td>45.000000</td>
    </tr>
    <tr>
      <th>mean</th>
      <td>19.661778</td>
      <td>3.102889</td>
      <td>2.555556</td>
      <td>0.158048</td>
    </tr>
    <tr>
      <th>std</th>
      <td>8.939181</td>
      <td>1.642088</td>
      <td>0.784960</td>
      <td>0.039767</td>
    </tr>
    <tr>
      <th>min</th>
      <td>7.250000</td>
      <td>1.000000</td>
      <td>1.000000</td>
      <td>0.056797</td>
    </tr>
    <tr>
      <th>25%</th>
      <td>14.730000</td>
      <td>2.010000</td>
      <td>2.000000</td>
      <td>0.136240</td>
    </tr>
    <tr>
      <th>50%</th>
      <td>17.820000</td>
      <td>2.750000</td>
      <td>2.000000</td>
      <td>0.150152</td>
    </tr>
    <tr>
      <th>75%</th>
      <td>20.650000</td>
      <td>3.390000</td>
      <td>3.000000</td>
      <td>0.183915</td>
    </tr>
    <tr>
      <th>max</th>
      <td>48.330000</td>
      <td>9.000000</td>
      <td>4.000000</td>
      <td>0.291990</td>
    </tr>
    <tr>
      <th rowspan="6" valign="top">Yes</th>
      <th>count</th>
      <td>42.000000</td>
      <td>42.000000</td>
      <td>42.000000</td>
      <td>42.000000</td>
    </tr>
    <tr>
      <th>mean</th>
      <td>21.276667</td>
      <td>2.875476</td>
      <td>2.476190</td>
      <td>0.147906</td>
    </tr>
    <tr>
      <th>std</th>
      <td>10.069138</td>
      <td>1.630580</td>
      <td>0.862161</td>
      <td>0.061375</td>
    </tr>
    <tr>
      <th>min</th>
      <td>3.070000</td>
      <td>1.000000</td>
      <td>1.000000</td>
      <td>0.035638</td>
    </tr>
    <tr>
      <th>25%</th>
      <td>13.405000</td>
      <td>2.000000</td>
      <td>2.000000</td>
      <td>0.091797</td>
    </tr>
    <tr>
      <th>50%</th>
      <td>20.390000</td>
      <td>2.690000</td>
      <td>2.000000</td>
      <td>0.153624</td>
    </tr>
    <tr>
      <th>...</th>
      <th>...</th>
      <th>...</th>
      <td>...</td>
      <td>...</td>
      <td>...</td>
      <td>...</td>
    </tr>
    <tr>
      <th rowspan="14" valign="top">Sun</th>
      <th rowspan="6" valign="top">No</th>
      <th>std</th>
      <td>8.130189</td>
      <td>1.224785</td>
      <td>1.032674</td>
      <td>0.042347</td>
    </tr>
    <tr>
      <th>min</th>
      <td>8.770000</td>
      <td>1.010000</td>
      <td>2.000000</td>
      <td>0.059447</td>
    </tr>
    <tr>
      <th>25%</th>
      <td>14.780000</td>
      <td>2.000000</td>
      <td>2.000000</td>
      <td>0.139780</td>
    </tr>
    <tr>
      <th>50%</th>
      <td>18.430000</td>
      <td>3.020000</td>
      <td>3.000000</td>
      <td>0.161665</td>
    </tr>
    <tr>
      <th>75%</th>
      <td>25.000000</td>
      <td>3.920000</td>
      <td>4.000000</td>
      <td>0.185185</td>
    </tr>
    <tr>
      <th>max</th>
      <td>48.170000</td>
      <td>6.000000</td>
      <td>6.000000</td>
      <td>0.252672</td>
    </tr>
    <tr>
      <th rowspan="8" valign="top">Yes</th>
      <th>count</th>
      <td>19.000000</td>
      <td>19.000000</td>
      <td>19.000000</td>
      <td>19.000000</td>
    </tr>
    <tr>
      <th>mean</th>
      <td>24.120000</td>
      <td>3.516842</td>
      <td>2.578947</td>
      <td>0.187250</td>
    </tr>
    <tr>
      <th>std</th>
      <td>10.442511</td>
      <td>1.261151</td>
      <td>0.901591</td>
      <td>0.154134</td>
    </tr>
    <tr>
      <th>min</th>
      <td>7.250000</td>
      <td>1.500000</td>
      <td>2.000000</td>
      <td>0.065660</td>
    </tr>
    <tr>
      <th>25%</th>
      <td>17.165000</td>
      <td>3.000000</td>
      <td>2.000000</td>
      <td>0.097723</td>
    </tr>
    <tr>
      <th>50%</th>
      <td>23.100000</td>
      <td>3.500000</td>
      <td>2.000000</td>
      <td>0.138122</td>
    </tr>
    <tr>
      <th>75%</th>
      <td>32.375000</td>
      <td>4.000000</td>
      <td>3.000000</td>
      <td>0.215325</td>
    </tr>
    <tr>
      <th>max</th>
      <td>45.350000</td>
      <td>6.500000</td>
      <td>5.000000</td>
      <td>0.710345</td>
    </tr>
    <tr>
      <th rowspan="16" valign="top">Thur</th>
      <th rowspan="8" valign="top">No</th>
      <th>count</th>
      <td>45.000000</td>
      <td>45.000000</td>
      <td>45.000000</td>
      <td>45.000000</td>
    </tr>
    <tr>
      <th>mean</th>
      <td>17.113111</td>
      <td>2.673778</td>
      <td>2.488889</td>
      <td>0.160298</td>
    </tr>
    <tr>
      <th>std</th>
      <td>7.721728</td>
      <td>1.282964</td>
      <td>1.179796</td>
      <td>0.038774</td>
    </tr>
    <tr>
      <th>min</th>
      <td>7.510000</td>
      <td>1.250000</td>
      <td>1.000000</td>
      <td>0.072961</td>
    </tr>
    <tr>
      <th>25%</th>
      <td>11.690000</td>
      <td>1.800000</td>
      <td>2.000000</td>
      <td>0.137741</td>
    </tr>
    <tr>
      <th>50%</th>
      <td>15.950000</td>
      <td>2.180000</td>
      <td>2.000000</td>
      <td>0.153492</td>
    </tr>
    <tr>
      <th>75%</th>
      <td>20.270000</td>
      <td>3.000000</td>
      <td>2.000000</td>
      <td>0.184843</td>
    </tr>
    <tr>
      <th>max</th>
      <td>41.190000</td>
      <td>6.700000</td>
      <td>6.000000</td>
      <td>0.266312</td>
    </tr>
    <tr>
      <th rowspan="8" valign="top">Yes</th>
      <th>count</th>
      <td>17.000000</td>
      <td>17.000000</td>
      <td>17.000000</td>
      <td>17.000000</td>
    </tr>
    <tr>
      <th>mean</th>
      <td>19.190588</td>
      <td>3.030000</td>
      <td>2.352941</td>
      <td>0.163863</td>
    </tr>
    <tr>
      <th>std</th>
      <td>8.355149</td>
      <td>1.113491</td>
      <td>0.701888</td>
      <td>0.039389</td>
    </tr>
    <tr>
      <th>min</th>
      <td>10.340000</td>
      <td>2.000000</td>
      <td>2.000000</td>
      <td>0.090014</td>
    </tr>
    <tr>
      <th>25%</th>
      <td>13.510000</td>
      <td>2.000000</td>
      <td>2.000000</td>
      <td>0.148038</td>
    </tr>
    <tr>
      <th>50%</th>
      <td>16.470000</td>
      <td>2.560000</td>
      <td>2.000000</td>
      <td>0.153846</td>
    </tr>
    <tr>
      <th>75%</th>
      <td>19.810000</td>
      <td>4.000000</td>
      <td>2.000000</td>
      <td>0.194837</td>
    </tr>
    <tr>
      <th>max</th>
      <td>43.110000</td>
      <td>5.000000</td>
      <td>4.000000</td>
      <td>0.241255</td>
    </tr>
  </tbody>
</table>
<p>64 rows × 4 columns</p>

</div>



```python
# 禁止分组键
tips.groupby('smoker', group_keys=False).apply(top)

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
      <th>total_bill</th>
      <th>tip</th>
      <th>smoker</th>
      <th>day</th>
      <th>time</th>
      <th>size</th>
      <th>tip_pct</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>88</th>
      <td>24.71</td>
      <td>5.85</td>
      <td>No</td>
      <td>Thur</td>
      <td>Lunch</td>
      <td>2</td>
      <td>0.236746</td>
    </tr>
    <tr>
      <th>185</th>
      <td>20.69</td>
      <td>5.00</td>
      <td>No</td>
      <td>Sun</td>
      <td>Dinner</td>
      <td>5</td>
      <td>0.241663</td>
    </tr>
    <tr>
      <th>51</th>
      <td>10.29</td>
      <td>2.60</td>
      <td>No</td>
      <td>Sun</td>
      <td>Dinner</td>
      <td>2</td>
      <td>0.252672</td>
    </tr>
    <tr>
      <th>149</th>
      <td>7.51</td>
      <td>2.00</td>
      <td>No</td>
      <td>Thur</td>
      <td>Lunch</td>
      <td>2</td>
      <td>0.266312</td>
    </tr>
    <tr>
      <th>232</th>
      <td>11.61</td>
      <td>3.39</td>
      <td>No</td>
      <td>Sat</td>
      <td>Dinner</td>
      <td>2</td>
      <td>0.291990</td>
    </tr>
    <tr>
      <th>109</th>
      <td>14.31</td>
      <td>4.00</td>
      <td>Yes</td>
      <td>Sat</td>
      <td>Dinner</td>
      <td>2</td>
      <td>0.279525</td>
    </tr>
    <tr>
      <th>183</th>
      <td>23.17</td>
      <td>6.50</td>
      <td>Yes</td>
      <td>Sun</td>
      <td>Dinner</td>
      <td>4</td>
      <td>0.280535</td>
    </tr>
    <tr>
      <th>67</th>
      <td>3.07</td>
      <td>1.00</td>
      <td>Yes</td>
      <td>Sat</td>
      <td>Dinner</td>
      <td>1</td>
      <td>0.325733</td>
    </tr>
    <tr>
      <th>178</th>
      <td>9.60</td>
      <td>4.00</td>
      <td>Yes</td>
      <td>Sun</td>
      <td>Dinner</td>
      <td>2</td>
      <td>0.416667</td>
    </tr>
    <tr>
      <th>172</th>
      <td>7.25</td>
      <td>5.15</td>
      <td>Yes</td>
      <td>Sun</td>
      <td>Dinner</td>
      <td>2</td>
      <td>0.710345</td>
    </tr>
  </tbody>
</table>

</div>



```python
# 分位数和桶分析
frame = pd.DataFrame({'data1': np.random.randn(1000),  
                      'data2': np.random.randn(1000)})

```

```python
quartiles = pd.cut(frame.data1, 4)

```

```python
quartiles[:10]

```



```
0    (-3.512, -1.919]
1     (-0.332, 1.255]
2    (-1.919, -0.332]
3     (-0.332, 1.255]
4     (-0.332, 1.255]
5     (-0.332, 1.255]
6    (-1.919, -0.332]
7    (-1.919, -0.332]
8     (-0.332, 1.255]
9     (-0.332, 1.255]
Name: data1, dtype: category
Categories (4, interval[float64]): [(-3.512, -1.919] < (-1.919, -0.332] < (-0.332, 1.255] < (1.255, 2.842]]

```



```python
def get_stats(group):   
    return {'min': group.min(), 'max': group.max(), 'count': group.count(), 'mean': group.mean()}

```

```python
grouped = frame.data2.groupby(quartiles)

```

```python
grouped.apply(get_stats).unstack()

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
      <th>count</th>
      <th>max</th>
      <th>mean</th>
      <th>min</th>
    </tr>
    <tr>
      <th>data1</th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>(-3.512, -1.919]</th>
      <td>28.0</td>
      <td>1.976240</td>
      <td>0.075564</td>
      <td>-1.432494</td>
    </tr>
    <tr>
      <th>(-1.919, -0.332]</th>
      <td>312.0</td>
      <td>3.494041</td>
      <td>0.043385</td>
      <td>-2.869138</td>
    </tr>
    <tr>
      <th>(-0.332, 1.255]</th>
      <td>546.0</td>
      <td>3.531713</td>
      <td>0.053309</td>
      <td>-2.854234</td>
    </tr>
    <tr>
      <th>(1.255, 2.842]</th>
      <td>114.0</td>
      <td>2.842356</td>
      <td>0.042646</td>
      <td>-2.445807</td>
    </tr>
  </tbody>
</table>

</div>



```python
grouping = pd.qcut(frame.data1, 10, labels=False)

```

```python
grouped = frame.data2.groupby(grouping)

```

```python
grouped.apply(get_stats).unstack()

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
      <th>count</th>
      <th>max</th>
      <th>mean</th>
      <th>min</th>
    </tr>
    <tr>
      <th>data1</th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>100.0</td>
      <td>1.976240</td>
      <td>0.161969</td>
      <td>-1.432494</td>
    </tr>
    <tr>
      <th>1</th>
      <td>100.0</td>
      <td>3.494041</td>
      <td>0.045114</td>
      <td>-1.946867</td>
    </tr>
    <tr>
      <th>2</th>
      <td>100.0</td>
      <td>2.066210</td>
      <td>-0.063048</td>
      <td>-2.869138</td>
    </tr>
    <tr>
      <th>3</th>
      <td>100.0</td>
      <td>1.946660</td>
      <td>0.108066</td>
      <td>-1.943618</td>
    </tr>
    <tr>
      <th>4</th>
      <td>100.0</td>
      <td>1.956075</td>
      <td>0.203224</td>
      <td>-2.662204</td>
    </tr>
    <tr>
      <th>5</th>
      <td>100.0</td>
      <td>2.962145</td>
      <td>-0.120810</td>
      <td>-2.174919</td>
    </tr>
    <tr>
      <th>6</th>
      <td>100.0</td>
      <td>3.531713</td>
      <td>0.045377</td>
      <td>-2.670236</td>
    </tr>
    <tr>
      <th>7</th>
      <td>100.0</td>
      <td>3.109824</td>
      <td>0.029800</td>
      <td>-2.279203</td>
    </tr>
    <tr>
      <th>8</th>
      <td>100.0</td>
      <td>1.954388</td>
      <td>0.026314</td>
      <td>-2.854234</td>
    </tr>
    <tr>
      <th>9</th>
      <td>100.0</td>
      <td>2.842356</td>
      <td>0.060194</td>
      <td>-2.445807</td>
    </tr>
  </tbody>
</table>

</div>



```python
# 示例：用特定于分组的值填充缺失值
s = pd.Series(np.random.randn(6))

```

```python
s[::2] = np.nan

```

```python
s

```



```
0         NaN
1   -0.437237
2         NaN
3   -0.582311
4         NaN
5   -0.105394
dtype: float64

```



```python
s.fillna(s.mean())

```



```
0   -0.374981
1   -0.437237
2   -0.374981
3   -0.582311
4   -0.374981
5   -0.105394
dtype: float64

```



```python
states = ['Ohio', 'New York', 'Vermont', 'Florida', 
          'Oregon', 'Nevada', 'California', 'Idaho']

```

```python
group_key = ['East'] * 4 + ['West'] * 4 

```

```python
data = pd.Series(np.random.randn(8), index=states)

```

```python
data 

```



```
Ohio         -0.613274
New York      1.055734
Vermont       0.589914
Florida       1.066370
Oregon        0.547077
Nevada        0.564267
California    0.929933
Idaho        -0.876713
dtype: float64

```



```python
data[['Vermont', 'Nevada', 'Idaho']] = np.nan

```

```python
data 

```



```
Ohio         -0.613274
New York      1.055734
Vermont            NaN
Florida       1.066370
Oregon        0.547077
Nevada             NaN
California    0.929933
Idaho              NaN
dtype: float64

```



```python
data.groupby(group_key).mean()

```



```
East    0.502943
West    0.738505
dtype: float64

```



```python
fill_mean = lambda g: g.fillna(g.mean())

```

```python
data.groupby(group_key).apply(fill_mean)

```



```
Ohio         -0.613274
New York      1.055734
Vermont       0.502943
Florida       1.066370
Oregon        0.547077
Nevada        0.738505
California    0.929933
Idaho         0.738505
dtype: float64

```



```python
fill_values = {'East': 0.5, 'West': -1}

```

```python
fill_func = lambda g: g.fillna(fill_values[g.name])

```

```python
data.groupby(group_key).apply(fill_func)

```



```
Ohio         -0.613274
New York      1.055734
Vermont       0.500000
Florida       1.066370
Oregon        0.547077
Nevada       -1.000000
California    0.929933
Idaho        -1.000000
dtype: float64

```



```python
# 示例：随机采样和排列
suits = ['H', 'S', 'C', 'D']
card_val = (list(range(1, 11)) + [10] * 3) * 4
base_names = ['A'] + list(range(2, 11)) + ['J', 'K', 'Q']
cards = []
for suit in ['H', 'S', 'C', 'D']:
    cards.extend(str(num) + suit for num in base_names)

deck = pd.Series(card_val, index=cards)

```

```python
deck[:13]

```



```
AH      1
2H      2
3H      3
4H      4
5H      5
6H      6
7H      7
8H      8
9H      9
10H    10
JH     10
KH     10
QH     10
dtype: int64

```



```python
def draw(deck, n=5): 
    return deck.sample(n)

```

```python
draw(deck)

```



```
6C     6
6H     6
9D     9
KH    10
8D     8
dtype: int64

```



```python
get_suit = lambda card: card[-1]

```

```python
deck.groupby(get_suit).apply(draw, n=2)

```



```
C  7C      7
   8C      8
D  4D      4
   8D      8
H  10H    10
   4H      4
S  5S      5
   KS     10
dtype: int64

```



```python
deck.groupby(get_suit, group_keys=False).apply(draw, n=2)

```



```
10C    10
7C      7
JD     10
AD      1
7H      7
KH     10
7S      7
KS     10
dtype: int64

```



```python
# 示例：分组加权平均数和相关系数
df = pd.DataFrame({'category': ['a', 'a', 'a', 'a',   
                                'b', 'b', 'b', 'b'],   
                   'data': np.random.randn(8),  
                   'weights': np.random.rand(8)})

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
      <th>category</th>
      <th>data</th>
      <th>weights</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>a</td>
      <td>2.179318</td>
      <td>0.466945</td>
    </tr>
    <tr>
      <th>1</th>
      <td>a</td>
      <td>-0.404187</td>
      <td>0.655105</td>
    </tr>
    <tr>
      <th>2</th>
      <td>a</td>
      <td>-1.345918</td>
      <td>0.525992</td>
    </tr>
    <tr>
      <th>3</th>
      <td>a</td>
      <td>0.157931</td>
      <td>0.199705</td>
    </tr>
    <tr>
      <th>4</th>
      <td>b</td>
      <td>-0.045654</td>
      <td>0.365906</td>
    </tr>
    <tr>
      <th>5</th>
      <td>b</td>
      <td>1.884341</td>
      <td>0.794533</td>
    </tr>
    <tr>
      <th>6</th>
      <td>b</td>
      <td>-0.335041</td>
      <td>0.880956</td>
    </tr>
    <tr>
      <th>7</th>
      <td>b</td>
      <td>1.429629</td>
      <td>0.922770</td>
    </tr>
  </tbody>
</table>

</div>



```python
grouped = df.groupby('category') 

```

```python
get_wavg = lambda g: np.average(g['data'], weights=g['weights'])

```

```python
grouped.apply(get_wavg)

```



```
category
a    0.041366
b    0.844935
dtype: float64

```



```python
close_px = pd.read_csv('examples/stock_px_2.csv', parse_dates=True,   
                       index_col=0)

```

```python
close_px.info()

```

```
<class 'pandas.core.frame.DataFrame'>
DatetimeIndex: 2214 entries, 2003-01-02 to 2011-10-14
Data columns (total 4 columns):
AAPL    2214 non-null float64
MSFT    2214 non-null float64
XOM     2214 non-null float64
SPX     2214 non-null float64
dtypes: float64(4)
memory usage: 86.5 KB

```



```python
close_px[-4:]

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
      <th>AAPL</th>
      <th>MSFT</th>
      <th>XOM</th>
      <th>SPX</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>2011-10-11</th>
      <td>400.29</td>
      <td>27.00</td>
      <td>76.27</td>
      <td>1195.54</td>
    </tr>
    <tr>
      <th>2011-10-12</th>
      <td>402.19</td>
      <td>26.96</td>
      <td>77.16</td>
      <td>1207.25</td>
    </tr>
    <tr>
      <th>2011-10-13</th>
      <td>408.43</td>
      <td>27.18</td>
      <td>76.37</td>
      <td>1203.66</td>
    </tr>
    <tr>
      <th>2011-10-14</th>
      <td>422.00</td>
      <td>27.27</td>
      <td>78.11</td>
      <td>1224.58</td>
    </tr>
  </tbody>
</table>

</div>



```python
spx_corr = lambda x: x.corrwith(x['SPX'])

```

```python
rets = close_px.pct_change().dropna()

```

```python
get_year = lambda x: x.year

```

```python
by_year = rets.groupby(get_year)

```

```python
by_year.apply(spx_corr)

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
      <th>AAPL</th>
      <th>MSFT</th>
      <th>XOM</th>
      <th>SPX</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>2003</th>
      <td>0.541124</td>
      <td>0.745174</td>
      <td>0.661265</td>
      <td>1.0</td>
    </tr>
    <tr>
      <th>2004</th>
      <td>0.374283</td>
      <td>0.588531</td>
      <td>0.557742</td>
      <td>1.0</td>
    </tr>
    <tr>
      <th>2005</th>
      <td>0.467540</td>
      <td>0.562374</td>
      <td>0.631010</td>
      <td>1.0</td>
    </tr>
    <tr>
      <th>2006</th>
      <td>0.428267</td>
      <td>0.406126</td>
      <td>0.518514</td>
      <td>1.0</td>
    </tr>
    <tr>
      <th>2007</th>
      <td>0.508118</td>
      <td>0.658770</td>
      <td>0.786264</td>
      <td>1.0</td>
    </tr>
    <tr>
      <th>2008</th>
      <td>0.681434</td>
      <td>0.804626</td>
      <td>0.828303</td>
      <td>1.0</td>
    </tr>
    <tr>
      <th>2009</th>
      <td>0.707103</td>
      <td>0.654902</td>
      <td>0.797921</td>
      <td>1.0</td>
    </tr>
    <tr>
      <th>2010</th>
      <td>0.710105</td>
      <td>0.730118</td>
      <td>0.839057</td>
      <td>1.0</td>
    </tr>
    <tr>
      <th>2011</th>
      <td>0.691931</td>
      <td>0.800996</td>
      <td>0.859975</td>
      <td>1.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
by_year.apply(lambda g: g['AAPL'].corr(g['MSFT'])) 

```



```
2003    0.480868
2004    0.259024
2005    0.300093
2006    0.161735
2007    0.417738
2008    0.611901
2009    0.432738
2010    0.571946
2011    0.581987
dtype: float64

```



```python
# 示例：组级别的线性回归
import statsmodels.api as sm 
from pandas.core import datetools
def regress(data, yvar, xvars):   
    Y = data[yvar]    
    X = data[xvars]    
    X['intercept'] = 1.   
    result = sm.OLS(Y, X).fit()  
    return result.params

```

```python
by_year.apply(regress, 'AAPL', ['SPX'])

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
      <th>SPX</th>
      <th>intercept</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>2003</th>
      <td>1.195406</td>
      <td>0.000710</td>
    </tr>
    <tr>
      <th>2004</th>
      <td>1.363463</td>
      <td>0.004201</td>
    </tr>
    <tr>
      <th>2005</th>
      <td>1.766415</td>
      <td>0.003246</td>
    </tr>
    <tr>
      <th>2006</th>
      <td>1.645496</td>
      <td>0.000080</td>
    </tr>
    <tr>
      <th>2007</th>
      <td>1.198761</td>
      <td>0.003438</td>
    </tr>
    <tr>
      <th>2008</th>
      <td>0.968016</td>
      <td>-0.001110</td>
    </tr>
    <tr>
      <th>2009</th>
      <td>0.879103</td>
      <td>0.002954</td>
    </tr>
    <tr>
      <th>2010</th>
      <td>1.052608</td>
      <td>0.001261</td>
    </tr>
    <tr>
      <th>2011</th>
      <td>0.806605</td>
      <td>0.001514</td>
    </tr>
  </tbody>
</table>

</div>



```python
# 透视表和交叉表
tips.pivot_table(index=['day', 'smoker'])

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
      <th>size</th>
      <th>tip</th>
      <th>tip_pct</th>
      <th>total_bill</th>
    </tr>
    <tr>
      <th>day</th>
      <th>smoker</th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th rowspan="2" valign="top">Fri</th>
      <th>No</th>
      <td>2.250000</td>
      <td>2.812500</td>
      <td>0.151650</td>
      <td>18.420000</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>2.066667</td>
      <td>2.714000</td>
      <td>0.174783</td>
      <td>16.813333</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Sat</th>
      <th>No</th>
      <td>2.555556</td>
      <td>3.102889</td>
      <td>0.158048</td>
      <td>19.661778</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>2.476190</td>
      <td>2.875476</td>
      <td>0.147906</td>
      <td>21.276667</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Sun</th>
      <th>No</th>
      <td>2.929825</td>
      <td>3.167895</td>
      <td>0.160113</td>
      <td>20.506667</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>2.578947</td>
      <td>3.516842</td>
      <td>0.187250</td>
      <td>24.120000</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Thur</th>
      <th>No</th>
      <td>2.488889</td>
      <td>2.673778</td>
      <td>0.160298</td>
      <td>17.113111</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>2.352941</td>
      <td>3.030000</td>
      <td>0.163863</td>
      <td>19.190588</td>
    </tr>
  </tbody>
</table>

</div>



```python
tips.pivot_table(['tip_pct', 'size'], index=['time', 'day'], columns='smoker') 

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
      <th></th>
      <th colspan="2" halign="left">size</th>
      <th colspan="2" halign="left">tip_pct</th>
    </tr>
    <tr>
      <th></th>
      <th>smoker</th>
      <th>No</th>
      <th>Yes</th>
      <th>No</th>
      <th>Yes</th>
    </tr>
    <tr>
      <th>time</th>
      <th>day</th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th rowspan="4" valign="top">Dinner</th>
      <th>Fri</th>
      <td>2.000000</td>
      <td>2.222222</td>
      <td>0.139622</td>
      <td>0.165347</td>
    </tr>
    <tr>
      <th>Sat</th>
      <td>2.555556</td>
      <td>2.476190</td>
      <td>0.158048</td>
      <td>0.147906</td>
    </tr>
    <tr>
      <th>Sun</th>
      <td>2.929825</td>
      <td>2.578947</td>
      <td>0.160113</td>
      <td>0.187250</td>
    </tr>
    <tr>
      <th>Thur</th>
      <td>2.000000</td>
      <td>NaN</td>
      <td>0.159744</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Lunch</th>
      <th>Fri</th>
      <td>3.000000</td>
      <td>1.833333</td>
      <td>0.187735</td>
      <td>0.188937</td>
    </tr>
    <tr>
      <th>Thur</th>
      <td>2.500000</td>
      <td>2.352941</td>
      <td>0.160311</td>
      <td>0.163863</td>
    </tr>
  </tbody>
</table>

</div>



```python
tips.pivot_table(['tip_pct', 'size'], index=['time', 'day'],columns='smoker', margins=True)

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
      <th></th>
      <th colspan="3" halign="left">size</th>
      <th colspan="3" halign="left">tip_pct</th>
    </tr>
    <tr>
      <th></th>
      <th>smoker</th>
      <th>No</th>
      <th>Yes</th>
      <th>All</th>
      <th>No</th>
      <th>Yes</th>
      <th>All</th>
    </tr>
    <tr>
      <th>time</th>
      <th>day</th>
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
      <th rowspan="4" valign="top">Dinner</th>
      <th>Fri</th>
      <td>2.000000</td>
      <td>2.222222</td>
      <td>2.166667</td>
      <td>0.139622</td>
      <td>0.165347</td>
      <td>0.158916</td>
    </tr>
    <tr>
      <th>Sat</th>
      <td>2.555556</td>
      <td>2.476190</td>
      <td>2.517241</td>
      <td>0.158048</td>
      <td>0.147906</td>
      <td>0.153152</td>
    </tr>
    <tr>
      <th>Sun</th>
      <td>2.929825</td>
      <td>2.578947</td>
      <td>2.842105</td>
      <td>0.160113</td>
      <td>0.187250</td>
      <td>0.166897</td>
    </tr>
    <tr>
      <th>Thur</th>
      <td>2.000000</td>
      <td>NaN</td>
      <td>2.000000</td>
      <td>0.159744</td>
      <td>NaN</td>
      <td>0.159744</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Lunch</th>
      <th>Fri</th>
      <td>3.000000</td>
      <td>1.833333</td>
      <td>2.000000</td>
      <td>0.187735</td>
      <td>0.188937</td>
      <td>0.188765</td>
    </tr>
    <tr>
      <th>Thur</th>
      <td>2.500000</td>
      <td>2.352941</td>
      <td>2.459016</td>
      <td>0.160311</td>
      <td>0.163863</td>
      <td>0.161301</td>
    </tr>
    <tr>
      <th>All</th>
      <th></th>
      <td>2.668874</td>
      <td>2.408602</td>
      <td>2.569672</td>
      <td>0.159328</td>
      <td>0.163196</td>
      <td>0.160803</td>
    </tr>
  </tbody>
</table>

</div>



```python
tips.pivot_table('tip_pct', index=['time', 'smoker'],columns='day',aggfunc=len, margins=True)

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
      <th>day</th>
      <th>Fri</th>
      <th>Sat</th>
      <th>Sun</th>
      <th>Thur</th>
      <th>All</th>
    </tr>
    <tr>
      <th>time</th>
      <th>smoker</th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th rowspan="2" valign="top">Dinner</th>
      <th>No</th>
      <td>3.0</td>
      <td>45.0</td>
      <td>57.0</td>
      <td>1.0</td>
      <td>106.0</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>9.0</td>
      <td>42.0</td>
      <td>19.0</td>
      <td>NaN</td>
      <td>70.0</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Lunch</th>
      <th>No</th>
      <td>1.0</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>44.0</td>
      <td>45.0</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>6.0</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>17.0</td>
      <td>23.0</td>
    </tr>
    <tr>
      <th>All</th>
      <th></th>
      <td>19.0</td>
      <td>87.0</td>
      <td>76.0</td>
      <td>62.0</td>
      <td>244.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
tips.pivot_table('tip_pct', index=['time', 'size', 'smoker'], 
                 columns='day', aggfunc='mean', fill_value=0)

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
      <th>day</th>
      <th>Fri</th>
      <th>Sat</th>
      <th>Sun</th>
      <th>Thur</th>
    </tr>
    <tr>
      <th>time</th>
      <th>size</th>
      <th>smoker</th>
      <th></th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th rowspan="11" valign="top">Dinner</th>
      <th rowspan="2" valign="top">1</th>
      <th>No</th>
      <td>0.000000</td>
      <td>0.137931</td>
      <td>0.000000</td>
      <td>0.000000</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.000000</td>
      <td>0.325733</td>
      <td>0.000000</td>
      <td>0.000000</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">2</th>
      <th>No</th>
      <td>0.139622</td>
      <td>0.162705</td>
      <td>0.168859</td>
      <td>0.159744</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.171297</td>
      <td>0.148668</td>
      <td>0.207893</td>
      <td>0.000000</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">3</th>
      <th>No</th>
      <td>0.000000</td>
      <td>0.154661</td>
      <td>0.152663</td>
      <td>0.000000</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.000000</td>
      <td>0.144995</td>
      <td>0.152660</td>
      <td>0.000000</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">4</th>
      <th>No</th>
      <td>0.000000</td>
      <td>0.150096</td>
      <td>0.148143</td>
      <td>0.000000</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.117750</td>
      <td>0.124515</td>
      <td>0.193370</td>
      <td>0.000000</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">5</th>
      <th>No</th>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.206928</td>
      <td>0.000000</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.000000</td>
      <td>0.106572</td>
      <td>0.065660</td>
      <td>0.000000</td>
    </tr>
    <tr>
      <th>6</th>
      <th>No</th>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.103799</td>
      <td>0.000000</td>
    </tr>
    <tr>
      <th rowspan="10" valign="top">Lunch</th>
      <th rowspan="2" valign="top">1</th>
      <th>No</th>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.181728</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.223776</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.000000</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">2</th>
      <th>No</th>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.166005</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.181969</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.158843</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">3</th>
      <th>No</th>
      <td>0.187735</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.084246</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.204952</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">4</th>
      <th>No</th>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.138919</td>
    </tr>
    <tr>
      <th>Yes</th>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.155410</td>
    </tr>
    <tr>
      <th>5</th>
      <th>No</th>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.121389</td>
    </tr>
    <tr>
      <th>6</th>
      <th>No</th>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.000000</td>
      <td>0.173706</td>
    </tr>
  </tbody>
</table>

</div>



```python
# 交叉表：crosstab
data = pd.DataFrame({'Sample': [1,2,3,4,5,6,7,8,9,10],   
                   'Nationality': ['USA','Japan','USA','Japan','Japan','Japan','USA','USA','Japan','USA'],  
                   'Handedness': ['Right-handed','Left-handed','Right-handed','Right-handed','Left-handed','Right-handed','Right-handed','Left-handed','Right-handed','Right-handed']})

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
      <th></th>
      <th>Handedness</th>
      <th>Nationality</th>
      <th>Sample</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>Right-handed</td>
      <td>USA</td>
      <td>1</td>
    </tr>
    <tr>
      <th>1</th>
      <td>Left-handed</td>
      <td>Japan</td>
      <td>2</td>
    </tr>
    <tr>
      <th>2</th>
      <td>Right-handed</td>
      <td>USA</td>
      <td>3</td>
    </tr>
    <tr>
      <th>3</th>
      <td>Right-handed</td>
      <td>Japan</td>
      <td>4</td>
    </tr>
    <tr>
      <th>4</th>
      <td>Left-handed</td>
      <td>Japan</td>
      <td>5</td>
    </tr>
    <tr>
      <th>5</th>
      <td>Right-handed</td>
      <td>Japan</td>
      <td>6</td>
    </tr>
    <tr>
      <th>6</th>
      <td>Right-handed</td>
      <td>USA</td>
      <td>7</td>
    </tr>
    <tr>
      <th>7</th>
      <td>Left-handed</td>
      <td>USA</td>
      <td>8</td>
    </tr>
    <tr>
      <th>8</th>
      <td>Right-handed</td>
      <td>Japan</td>
      <td>9</td>
    </tr>
    <tr>
      <th>9</th>
      <td>Right-handed</td>
      <td>USA</td>
      <td>10</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.crosstab(data.Nationality, data.Handedness, margins=True)

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
      <th>Handedness</th>
      <th>Left-handed</th>
      <th>Right-handed</th>
      <th>All</th>
    </tr>
    <tr>
      <th>Nationality</th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>Japan</th>
      <td>2</td>
      <td>3</td>
      <td>5</td>
    </tr>
    <tr>
      <th>USA</th>
      <td>1</td>
      <td>4</td>
      <td>5</td>
    </tr>
    <tr>
      <th>All</th>
      <td>3</td>
      <td>7</td>
      <td>10</td>
    </tr>
  </tbody>
</table>

</div>



```python
pd.crosstab([tips.time, tips.day], tips.smoker, margins=True)

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
      <th>smoker</th>
      <th>No</th>
      <th>Yes</th>
      <th>All</th>
    </tr>
    <tr>
      <th>time</th>
      <th>day</th>
      <th></th>
      <th></th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th rowspan="4" valign="top">Dinner</th>
      <th>Fri</th>
      <td>3</td>
      <td>9</td>
      <td>12</td>
    </tr>
    <tr>
      <th>Sat</th>
      <td>45</td>
      <td>42</td>
      <td>87</td>
    </tr>
    <tr>
      <th>Sun</th>
      <td>57</td>
      <td>19</td>
      <td>76</td>
    </tr>
    <tr>
      <th>Thur</th>
      <td>1</td>
      <td>0</td>
      <td>1</td>
    </tr>
    <tr>
      <th rowspan="2" valign="top">Lunch</th>
      <th>Fri</th>
      <td>1</td>
      <td>6</td>
      <td>7</td>
    </tr>
    <tr>
      <th>Thur</th>
      <td>44</td>
      <td>17</td>
      <td>61</td>
    </tr>
    <tr>
      <th>All</th>
      <th></th>
      <td>151</td>
      <td>93</td>
      <td>244</td>
    </tr>
  </tbody>
</table>

</div>

