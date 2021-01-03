---
title: 'Python进行数据分析task4：数据清洗和准备'
date: 2019-07-09 15:41:42
tags: [Data Analysis]
published: true
hideInList: false
feature: /post-images/python-jin-xing-shu-ju-fen-xi-task4shu-ju-qing-xi-he-zhun-bei.png
---


```python
# 处理缺失数据
import pandas as pd
string_data = pd.Series(['aardvark', 'artichoke', np.nan, 'avocado'])
```

```python
string_data
```



```
0     aardvark
1    artichoke
2          NaN
3      avocado
dtype: object
```



```python
string_data.isnull()
```



```
0    False
1    False
2     True
3    False
dtype: bool
```



```python
#将缺失值表示为 NA
string_data[0] = None#Python 内置的 None 值在对象数组中也可以作为 NA
```

```python
string_data.isnull()
```



```
0     True
1    False
2     True
3    False
dtype: bool
```



```python
from numpy import nan as NA
data = pd.Series([1, NA, 3.5, NA, 7])
data.dropna()

```



```
0    1.0
2    3.5
4    7.0
dtype: float64

```



```python
data[data.notnull()] 

```



```
0    1.0
2    3.5
4    7.0
dtype: float64

```



```python
data = pd.DataFrame([[1., 6.5, 3.], [1., NA, NA],
                     [NA, NA, NA], [NA, 6.5, 3.]])

```

```python
cleaned = data.dropna()
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
      <th>0</th>
      <th>1</th>
      <th>2</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1.0</td>
      <td>6.5</td>
      <td>3.0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1.0</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>2</th>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>3</th>
      <td>NaN</td>
      <td>6.5</td>
      <td>3.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
cleaned

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
      <th>0</th>
      <td>1.0</td>
      <td>6.5</td>
      <td>3.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
data.dropna(how='all')

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
      <th>0</th>
      <td>1.0</td>
      <td>6.5</td>
      <td>3.0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1.0</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>3</th>
      <td>NaN</td>
      <td>6.5</td>
      <td>3.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
data[4] = NA

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
      <th>0</th>
      <th>1</th>
      <th>2</th>
      <th>4</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1.0</td>
      <td>6.5</td>
      <td>3.0</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1.0</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>2</th>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>3</th>
      <td>NaN</td>
      <td>6.5</td>
      <td>3.0</td>
      <td>NaN</td>
    </tr>
  </tbody>
</table>

</div>



```python
data.dropna(axis=1, how='all')

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
      <th>0</th>
      <td>1.0</td>
      <td>6.5</td>
      <td>3.0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1.0</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>2</th>
      <td>NaN</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>3</th>
      <td>NaN</td>
      <td>6.5</td>
      <td>3.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
df = pd.DataFrame(np.random.randn(7, 3))

```

```python
df.iloc[:4, 1] = NA

```

```python
df.iloc[:2, 2] = NA

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
      <th>0</th>
      <th>1</th>
      <th>2</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>-0.287769</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>1</th>
      <td>0.463930</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>2</th>
      <td>0.595689</td>
      <td>NaN</td>
      <td>0.582149</td>
    </tr>
    <tr>
      <th>3</th>
      <td>1.060007</td>
      <td>NaN</td>
      <td>0.917274</td>
    </tr>
    <tr>
      <th>4</th>
      <td>-1.533122</td>
      <td>-0.169736</td>
      <td>-0.009099</td>
    </tr>
    <tr>
      <th>5</th>
      <td>0.308635</td>
      <td>0.643079</td>
      <td>1.023105</td>
    </tr>
    <tr>
      <th>6</th>
      <td>-0.789453</td>
      <td>0.576045</td>
      <td>1.009088</td>
    </tr>
  </tbody>
</table>

</div>



```python
df.dropna()

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
      <th>4</th>
      <td>-1.533122</td>
      <td>-0.169736</td>
      <td>-0.009099</td>
    </tr>
    <tr>
      <th>5</th>
      <td>0.308635</td>
      <td>0.643079</td>
      <td>1.023105</td>
    </tr>
    <tr>
      <th>6</th>
      <td>-0.789453</td>
      <td>0.576045</td>
      <td>1.009088</td>
    </tr>
  </tbody>
</table>

</div>



```python
df.dropna(thresh=2)

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
      <th>2</th>
      <td>0.595689</td>
      <td>NaN</td>
      <td>0.582149</td>
    </tr>
    <tr>
      <th>3</th>
      <td>1.060007</td>
      <td>NaN</td>
      <td>0.917274</td>
    </tr>
    <tr>
      <th>4</th>
      <td>-1.533122</td>
      <td>-0.169736</td>
      <td>-0.009099</td>
    </tr>
    <tr>
      <th>5</th>
      <td>0.308635</td>
      <td>0.643079</td>
      <td>1.023105</td>
    </tr>
    <tr>
      <th>6</th>
      <td>-0.789453</td>
      <td>0.576045</td>
      <td>1.009088</td>
    </tr>
  </tbody>
</table>

</div>



```python
df.fillna(0)

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
      <th>0</th>
      <td>-0.287769</td>
      <td>0.000000</td>
      <td>0.000000</td>
    </tr>
    <tr>
      <th>1</th>
      <td>0.463930</td>
      <td>0.000000</td>
      <td>0.000000</td>
    </tr>
    <tr>
      <th>2</th>
      <td>0.595689</td>
      <td>0.000000</td>
      <td>0.582149</td>
    </tr>
    <tr>
      <th>3</th>
      <td>1.060007</td>
      <td>0.000000</td>
      <td>0.917274</td>
    </tr>
    <tr>
      <th>4</th>
      <td>-1.533122</td>
      <td>-0.169736</td>
      <td>-0.009099</td>
    </tr>
    <tr>
      <th>5</th>
      <td>0.308635</td>
      <td>0.643079</td>
      <td>1.023105</td>
    </tr>
    <tr>
      <th>6</th>
      <td>-0.789453</td>
      <td>0.576045</td>
      <td>1.009088</td>
    </tr>
  </tbody>
</table>

</div>



```python
df.fillna({1: 0.5, 2: 0})

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
      <th>0</th>
      <td>-0.287769</td>
      <td>0.500000</td>
      <td>0.000000</td>
    </tr>
    <tr>
      <th>1</th>
      <td>0.463930</td>
      <td>0.500000</td>
      <td>0.000000</td>
    </tr>
    <tr>
      <th>2</th>
      <td>0.595689</td>
      <td>0.500000</td>
      <td>0.582149</td>
    </tr>
    <tr>
      <th>3</th>
      <td>1.060007</td>
      <td>0.500000</td>
      <td>0.917274</td>
    </tr>
    <tr>
      <th>4</th>
      <td>-1.533122</td>
      <td>-0.169736</td>
      <td>-0.009099</td>
    </tr>
    <tr>
      <th>5</th>
      <td>0.308635</td>
      <td>0.643079</td>
      <td>1.023105</td>
    </tr>
    <tr>
      <th>6</th>
      <td>-0.789453</td>
      <td>0.576045</td>
      <td>1.009088</td>
    </tr>
  </tbody>
</table>

</div>



```python
_ = df.fillna(0, inplace=True)

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
      <th>0</th>
      <th>1</th>
      <th>2</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>-0.287769</td>
      <td>0.000000</td>
      <td>0.000000</td>
    </tr>
    <tr>
      <th>1</th>
      <td>0.463930</td>
      <td>0.000000</td>
      <td>0.000000</td>
    </tr>
    <tr>
      <th>2</th>
      <td>0.595689</td>
      <td>0.000000</td>
      <td>0.582149</td>
    </tr>
    <tr>
      <th>3</th>
      <td>1.060007</td>
      <td>0.000000</td>
      <td>0.917274</td>
    </tr>
    <tr>
      <th>4</th>
      <td>-1.533122</td>
      <td>-0.169736</td>
      <td>-0.009099</td>
    </tr>
    <tr>
      <th>5</th>
      <td>0.308635</td>
      <td>0.643079</td>
      <td>1.023105</td>
    </tr>
    <tr>
      <th>6</th>
      <td>-0.789453</td>
      <td>0.576045</td>
      <td>1.009088</td>
    </tr>
  </tbody>
</table>

</div>



```python
df = pd.DataFrame(np.random.randn(6, 3))
df.iloc[2:, 1] = NA
df.iloc[4:, 2] = NA 
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
      <th>0</th>
      <th>1</th>
      <th>2</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>0.937978</td>
      <td>-1.48690</td>
      <td>0.504684</td>
    </tr>
    <tr>
      <th>1</th>
      <td>2.038022</td>
      <td>-0.71188</td>
      <td>-0.918484</td>
    </tr>
    <tr>
      <th>2</th>
      <td>-0.336318</td>
      <td>NaN</td>
      <td>0.550304</td>
    </tr>
    <tr>
      <th>3</th>
      <td>0.246116</td>
      <td>NaN</td>
      <td>1.934958</td>
    </tr>
    <tr>
      <th>4</th>
      <td>-0.338333</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
    <tr>
      <th>5</th>
      <td>-0.756406</td>
      <td>NaN</td>
      <td>NaN</td>
    </tr>
  </tbody>
</table>

</div>



```python
df.fillna(method='ffill')

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
      <th>0</th>
      <td>0.937978</td>
      <td>-1.48690</td>
      <td>0.504684</td>
    </tr>
    <tr>
      <th>1</th>
      <td>2.038022</td>
      <td>-0.71188</td>
      <td>-0.918484</td>
    </tr>
    <tr>
      <th>2</th>
      <td>-0.336318</td>
      <td>-0.71188</td>
      <td>0.550304</td>
    </tr>
    <tr>
      <th>3</th>
      <td>0.246116</td>
      <td>-0.71188</td>
      <td>1.934958</td>
    </tr>
    <tr>
      <th>4</th>
      <td>-0.338333</td>
      <td>-0.71188</td>
      <td>1.934958</td>
    </tr>
    <tr>
      <th>5</th>
      <td>-0.756406</td>
      <td>-0.71188</td>
      <td>1.934958</td>
    </tr>
  </tbody>
</table>

</div>



```python
df.fillna(method='ffill', limit=2)

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
      <th>0</th>
      <td>0.937978</td>
      <td>-1.48690</td>
      <td>0.504684</td>
    </tr>
    <tr>
      <th>1</th>
      <td>2.038022</td>
      <td>-0.71188</td>
      <td>-0.918484</td>
    </tr>
    <tr>
      <th>2</th>
      <td>-0.336318</td>
      <td>-0.71188</td>
      <td>0.550304</td>
    </tr>
    <tr>
      <th>3</th>
      <td>0.246116</td>
      <td>-0.71188</td>
      <td>1.934958</td>
    </tr>
    <tr>
      <th>4</th>
      <td>-0.338333</td>
      <td>NaN</td>
      <td>1.934958</td>
    </tr>
    <tr>
      <th>5</th>
      <td>-0.756406</td>
      <td>NaN</td>
      <td>1.934958</td>
    </tr>
  </tbody>
</table>

</div>



```python
data = pd.Series([1., NA, 3.5, NA, 7])

```

```python
data.fillna(data.mean())

```



```
0    1.000000
1    3.833333
2    3.500000
3    3.833333
4    7.000000
dtype: float64

```



```python
# 数据转换
# 移除重复数据

```

```python
data = pd.DataFrame({'k1': ['one', 'two'] * 3 + ['two'],
                     'k2': [1, 1, 2, 3, 3, 4, 4]})
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
      <th>k1</th>
      <th>k2</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>one</td>
      <td>1</td>
    </tr>
    <tr>
      <th>1</th>
      <td>two</td>
      <td>1</td>
    </tr>
    <tr>
      <th>2</th>
      <td>one</td>
      <td>2</td>
    </tr>
    <tr>
      <th>3</th>
      <td>two</td>
      <td>3</td>
    </tr>
    <tr>
      <th>4</th>
      <td>one</td>
      <td>3</td>
    </tr>
    <tr>
      <th>5</th>
      <td>two</td>
      <td>4</td>
    </tr>
    <tr>
      <th>6</th>
      <td>two</td>
      <td>4</td>
    </tr>
  </tbody>
</table>

</div>



```python
# DataFrame 的 duplicated 方法返回一个布尔型 Series，
# 表示各行是否是重复行（前面出现过的行）
data.duplicated()

```



```
0    False
1    False
2    False
3    False
4    False
5    False
6     True
dtype: bool

```



```python
# drop_duplicates 方法，会返回一个 DataFrame，重复的数组会标为 False
data.drop_duplicates()

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
      <th>k1</th>
      <th>k2</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>one</td>
      <td>1</td>
    </tr>
    <tr>
      <th>1</th>
      <td>two</td>
      <td>1</td>
    </tr>
    <tr>
      <th>2</th>
      <td>one</td>
      <td>2</td>
    </tr>
    <tr>
      <th>3</th>
      <td>two</td>
      <td>3</td>
    </tr>
    <tr>
      <th>4</th>
      <td>one</td>
      <td>3</td>
    </tr>
    <tr>
      <th>5</th>
      <td>two</td>
      <td>4</td>
    </tr>
  </tbody>
</table>

</div>



```python
data['v1'] = range(7)
data.drop_duplicates(['k1'])

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
      <th>k1</th>
      <th>k2</th>
      <th>v1</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>one</td>
      <td>1</td>
      <td>0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>two</td>
      <td>1</td>
      <td>1</td>
    </tr>
  </tbody>
</table>

</div>



```python
data.drop_duplicates(['k1', 'k2'], keep='last')

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
      <th>k1</th>
      <th>k2</th>
      <th>v1</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>one</td>
      <td>1</td>
      <td>0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>two</td>
      <td>1</td>
      <td>1</td>
    </tr>
    <tr>
      <th>2</th>
      <td>one</td>
      <td>2</td>
      <td>2</td>
    </tr>
    <tr>
      <th>3</th>
      <td>two</td>
      <td>3</td>
      <td>3</td>
    </tr>
    <tr>
      <th>4</th>
      <td>one</td>
      <td>3</td>
      <td>4</td>
    </tr>
    <tr>
      <th>6</th>
      <td>two</td>
      <td>4</td>
      <td>6</td>
    </tr>
  </tbody>
</table>

</div>



```python
# 利用函数或映射进行数据转换
data = pd.DataFrame({'food': ['bacon', 'pulled pork', 'bacon', 
                              'Pastrami', 'corned beef', 'Bacon', 
                              'pastrami', 'honey ham', 'nova lox'], 
                              'ounces': [4, 3, 12, 6, 7.5, 8, 3, 5, 6]})
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
      <th>food</th>
      <th>ounces</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>bacon</td>
      <td>4.0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>pulled pork</td>
      <td>3.0</td>
    </tr>
    <tr>
      <th>2</th>
      <td>bacon</td>
      <td>12.0</td>
    </tr>
    <tr>
      <th>3</th>
      <td>Pastrami</td>
      <td>6.0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>corned beef</td>
      <td>7.5</td>
    </tr>
    <tr>
      <th>5</th>
      <td>Bacon</td>
      <td>8.0</td>
    </tr>
    <tr>
      <th>6</th>
      <td>pastrami</td>
      <td>3.0</td>
    </tr>
    <tr>
      <th>7</th>
      <td>honey ham</td>
      <td>5.0</td>
    </tr>
    <tr>
      <th>8</th>
      <td>nova lox</td>
      <td>6.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
meat_to_animal = {   'bacon': 'pig',   
                  'pulled pork': 'pig',  
                  'pastrami': 'cow',  
                  'corned beef': 'cow',  
                  'honey ham': 'pig',  
                  'nova lox': 'salmon' }

```

```python
lowercased = data['food'].str.lower()
lowercased 

```



```
0          bacon
1    pulled pork
2          bacon
3       pastrami
4    corned beef
5          bacon
6       pastrami
7      honey ham
8       nova lox
Name: food, dtype: object

```



```python
data['animal'] = lowercased.map(meat_to_animal)
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
      <th>food</th>
      <th>ounces</th>
      <th>animal</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>bacon</td>
      <td>4.0</td>
      <td>pig</td>
    </tr>
    <tr>
      <th>1</th>
      <td>pulled pork</td>
      <td>3.0</td>
      <td>pig</td>
    </tr>
    <tr>
      <th>2</th>
      <td>bacon</td>
      <td>12.0</td>
      <td>pig</td>
    </tr>
    <tr>
      <th>3</th>
      <td>Pastrami</td>
      <td>6.0</td>
      <td>cow</td>
    </tr>
    <tr>
      <th>4</th>
      <td>corned beef</td>
      <td>7.5</td>
      <td>cow</td>
    </tr>
    <tr>
      <th>5</th>
      <td>Bacon</td>
      <td>8.0</td>
      <td>pig</td>
    </tr>
    <tr>
      <th>6</th>
      <td>pastrami</td>
      <td>3.0</td>
      <td>cow</td>
    </tr>
    <tr>
      <th>7</th>
      <td>honey ham</td>
      <td>5.0</td>
      <td>pig</td>
    </tr>
    <tr>
      <th>8</th>
      <td>nova lox</td>
      <td>6.0</td>
      <td>salmon</td>
    </tr>
  </tbody>
</table>

</div>



```python
data['food'].map(lambda x: meat_to_animal[x.lower()])

```



```
0       pig
1       pig
2       pig
3       cow
4       cow
5       pig
6       cow
7       pig
8    salmon
Name: food, dtype: object

```



```python
# 替换值 
data = pd.Series([1., -999., 2., -999., -1000., 3.])
#-999 这个值可能是一个表示缺失数据的标记值。
data

```



```
0       1.0
1    -999.0
2       2.0
3    -999.0
4   -1000.0
5       3.0
dtype: float64

```



```python
data.replace(-999, np.nan)

```



```
0       1.0
1       NaN
2       2.0
3       NaN
4   -1000.0
5       3.0
dtype: float64

```



```python
data.replace([-999, -1000], np.nan)

```



```
0    1.0
1    NaN
2    2.0
3    NaN
4    NaN
5    3.0
dtype: float64

```



```python
# 可以传递一个替换列表
data.replace([-999, -1000], [np.nan, 0])

```



```
0    1.0
1    NaN
2    2.0
3    NaN
4    0.0
5    3.0
dtype: float64

```



```python
data.replace({-999: np.nan, -1000: 0})

```



```
0    1.0
1    NaN
2    2.0
3    NaN
4    0.0
5    3.0
dtype: float64

```



```python
# 重命名轴索引
data = pd.DataFrame(np.arange(12).reshape((3, 4)), 
                    index=['Ohio', 'Colorado', 'New York'],
                    columns=['one', 'two', 'three', 'four'])

```

```python
transform = lambda x: x[:4].upper()
data.index.map(transform)

```



```
Index(['OHIO', 'COLO', 'NEW '], dtype='object')

```



```python
#将其赋值给 index，这样就可以对 DataFrame 进行就地修改
data.index = data.index.map(transform)
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
      <th>one</th>
      <th>two</th>
      <th>three</th>
      <th>four</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>OHIO</th>
      <td>0</td>
      <td>1</td>
      <td>2</td>
      <td>3</td>
    </tr>
    <tr>
      <th>COLO</th>
      <td>4</td>
      <td>5</td>
      <td>6</td>
      <td>7</td>
    </tr>
    <tr>
      <th>NEW</th>
      <td>8</td>
      <td>9</td>
      <td>10</td>
      <td>11</td>
    </tr>
  </tbody>
</table>

</div>



```python
# 创建数据集的转换版（不是修改原始数据）
data.rename(index=str.title, columns=str.upper)

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
      <th>ONE</th>
      <th>TWO</th>
      <th>THREE</th>
      <th>FOUR</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>Ohio</th>
      <td>0</td>
      <td>1</td>
      <td>2</td>
      <td>3</td>
    </tr>
    <tr>
      <th>Colo</th>
      <td>4</td>
      <td>5</td>
      <td>6</td>
      <td>7</td>
    </tr>
    <tr>
      <th>New</th>
      <td>8</td>
      <td>9</td>
      <td>10</td>
      <td>11</td>
    </tr>
  </tbody>
</table>

</div>



```python
# rename 可以结合字典型对象实现对部分轴标签的更新
data.rename(index={'OHIO': 'INDIANA'},
            columns={'three': 'peekaboo'})

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
      <th>peekaboo</th>
      <th>four</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>INDIANA</th>
      <td>0</td>
      <td>1</td>
      <td>2</td>
      <td>3</td>
    </tr>
    <tr>
      <th>COLO</th>
      <td>4</td>
      <td>5</td>
      <td>6</td>
      <td>7</td>
    </tr>
    <tr>
      <th>NEW</th>
      <td>8</td>
      <td>9</td>
      <td>10</td>
      <td>11</td>
    </tr>
  </tbody>
</table>

</div>



```python
data.rename(index={'OHIO': 'INDIANA'}, inplace=True)
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
      <th>one</th>
      <th>two</th>
      <th>three</th>
      <th>four</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>INDIANA</th>
      <td>0</td>
      <td>1</td>
      <td>2</td>
      <td>3</td>
    </tr>
    <tr>
      <th>COLO</th>
      <td>4</td>
      <td>5</td>
      <td>6</td>
      <td>7</td>
    </tr>
    <tr>
      <th>NEW</th>
      <td>8</td>
      <td>9</td>
      <td>10</td>
      <td>11</td>
    </tr>
  </tbody>
</table>

</div>



```python
# 离散化和面元划分
ages = [20, 22, 25, 27, 21, 23, 37, 31, 61, 45, 41, 32]
bins = [18, 25, 35, 60, 100]
cats = pd.cut(ages, bins)
cats

```



```
[(18, 25], (18, 25], (18, 25], (25, 35], (18, 25], ..., (25, 35], (60, 100], (35, 60], (35, 60], (25, 35]]
Length: 12
Categories (4, interval[int64]): [(18, 25] < (25, 35] < (35, 60] < (60, 100]]

```



```python
cats.codes 

```



```
array([0, 0, 0, 1, 0, 0, 2, 1, 3, 2, 2, 1], dtype=int8)

```



```python
cats.categories

```



```
IntervalIndex([(18, 25], (25, 35], (35, 60], (60, 100]]
              closed='right',
              dtype='interval[int64]')

```



```python
pd.value_counts(cats)

```



```
(18, 25]     5
(35, 60]     3
(25, 35]     3
(60, 100]    1
dtype: int64

```



```python
pd.cut(ages, [18, 26, 36, 61, 100], right=False)

```



```
[[18, 26), [18, 26), [18, 26), [26, 36), [18, 26), ..., [26, 36), [61, 100), [36, 61), [36, 61), [26, 36)]
Length: 12
Categories (4, interval[int64]): [[18, 26) < [26, 36) < [36, 61) < [61, 100)]

```



```python
group_names = ['Youth', 'YoungAdult', 'MiddleAged', 'Senior']

```

```python
pd.cut(ages, bins, labels=group_names)

```



```
[Youth, Youth, Youth, YoungAdult, Youth, ..., YoungAdult, Senior, MiddleAged, MiddleAged, YoungAdult]
Length: 12
Categories (4, object): [Youth < YoungAdult < MiddleAged < Senior]

```



```python
data = np.random.rand(20)
pd.cut(data, 4, precision=2)

```



```
[(0.29, 0.52], (0.74, 0.97], (0.061, 0.29], (0.74, 0.97], (0.29, 0.52], ..., (0.061, 0.29], (0.29, 0.52], (0.29, 0.52], (0.74, 0.97], (0.74, 0.97]]
Length: 20
Categories (4, interval[float64]): [(0.061, 0.29] < (0.29, 0.52] < (0.52, 0.74] < (0.74, 0.97]]

```



```python
data = np.random.randn(1000)  # 正常分布
cats = pd.qcut(data, 4)  # 1/4
cats

```



```
[(0.0369, 0.716], (-3.042, -0.702], (-3.042, -0.702], (-3.042, -0.702], (-3.042, -0.702], ..., (0.0369, 0.716], (0.716, 3.279], (0.716, 3.279], (0.0369, 0.716], (-0.702, 0.0369]]
Length: 1000
Categories (4, interval[float64]): [(-3.042, -0.702] < (-0.702, 0.0369] < (0.0369, 0.716] < (0.716, 3.279]]

```



```python
pd.value_counts(cats)

```



```
(0.716, 3.279]      250
(0.0369, 0.716]     250
(-0.702, 0.0369]    250
(-3.042, -0.702]    250
dtype: int64

```



```python
pd.qcut(data, [0, 0.1, 0.5, 0.9, 1.])

```



```
[(0.0369, 1.307], (-1.331, 0.0369], (-3.042, -1.331], (-1.331, 0.0369], (-3.042, -1.331], ..., (0.0369, 1.307], (1.307, 3.279], (1.307, 3.279], (0.0369, 1.307], (-1.331, 0.0369]]
Length: 1000
Categories (4, interval[float64]): [(-3.042, -1.331] < (-1.331, 0.0369] < (0.0369, 1.307] < (1.307, 3.279]]

```



```python
# 检测和过滤异常值
data = pd.DataFrame(np.random.randn(1000, 4))
data.describe()

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
      <th>3</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>count</th>
      <td>1000.000000</td>
      <td>1000.000000</td>
      <td>1000.000000</td>
      <td>1000.000000</td>
    </tr>
    <tr>
      <th>mean</th>
      <td>-0.004033</td>
      <td>0.025026</td>
      <td>-0.025663</td>
      <td>0.033355</td>
    </tr>
    <tr>
      <th>std</th>
      <td>0.965683</td>
      <td>0.992877</td>
      <td>0.966177</td>
      <td>0.976610</td>
    </tr>
    <tr>
      <th>min</th>
      <td>-3.262478</td>
      <td>-3.038965</td>
      <td>-3.440712</td>
      <td>-2.846379</td>
    </tr>
    <tr>
      <th>25%</th>
      <td>-0.655577</td>
      <td>-0.625746</td>
      <td>-0.629501</td>
      <td>-0.590840</td>
    </tr>
    <tr>
      <th>50%</th>
      <td>-0.040904</td>
      <td>0.007496</td>
      <td>-0.032268</td>
      <td>-0.000206</td>
    </tr>
    <tr>
      <th>75%</th>
      <td>0.658279</td>
      <td>0.661891</td>
      <td>0.619206</td>
      <td>0.686097</td>
    </tr>
    <tr>
      <th>max</th>
      <td>4.120138</td>
      <td>3.274903</td>
      <td>3.908081</td>
      <td>3.087324</td>
    </tr>
  </tbody>
</table>

</div>



```python
col = data[2]
col[np.abs(col) > 3] 

```



```
131   -3.386029
192    3.908081
541   -3.440712
Name: 2, dtype: float64

```



```python
data[(np.abs(data) > 3).any(1)] #选出全部含有“超过 3 或－3 的值”的行

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
      <th>3</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>131</th>
      <td>-1.868514</td>
      <td>0.115213</td>
      <td>-3.386029</td>
      <td>0.332657</td>
    </tr>
    <tr>
      <th>192</th>
      <td>-0.320247</td>
      <td>0.505288</td>
      <td>3.908081</td>
      <td>-0.514350</td>
    </tr>
    <tr>
      <th>200</th>
      <td>1.367911</td>
      <td>1.146961</td>
      <td>1.583079</td>
      <td>3.087324</td>
    </tr>
    <tr>
      <th>205</th>
      <td>-0.166522</td>
      <td>3.274903</td>
      <td>0.006452</td>
      <td>-2.026085</td>
    </tr>
    <tr>
      <th>249</th>
      <td>0.043202</td>
      <td>3.064100</td>
      <td>1.464767</td>
      <td>-0.844918</td>
    </tr>
    <tr>
      <th>261</th>
      <td>0.486530</td>
      <td>3.040366</td>
      <td>0.697331</td>
      <td>-0.510862</td>
    </tr>
    <tr>
      <th>441</th>
      <td>3.530405</td>
      <td>2.326418</td>
      <td>0.358846</td>
      <td>0.088161</td>
    </tr>
    <tr>
      <th>480</th>
      <td>-3.262478</td>
      <td>1.123064</td>
      <td>0.350535</td>
      <td>-0.096959</td>
    </tr>
    <tr>
      <th>541</th>
      <td>-0.859143</td>
      <td>1.923838</td>
      <td>-3.440712</td>
      <td>0.659413</td>
    </tr>
    <tr>
      <th>559</th>
      <td>3.022707</td>
      <td>1.419008</td>
      <td>-0.077520</td>
      <td>-0.533165</td>
    </tr>
    <tr>
      <th>695</th>
      <td>1.329980</td>
      <td>-3.038965</td>
      <td>-0.164183</td>
      <td>0.190824</td>
    </tr>
    <tr>
      <th>739</th>
      <td>-1.139582</td>
      <td>-3.006273</td>
      <td>-1.228249</td>
      <td>-0.416130</td>
    </tr>
    <tr>
      <th>976</th>
      <td>4.120138</td>
      <td>-1.188991</td>
      <td>-0.289311</td>
      <td>-0.595098</td>
    </tr>
  </tbody>
</table>

</div>



```python
data[np.abs(data) > 3] = np.sign(data) * 3
data.describe()

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
      <th>3</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>count</th>
      <td>1000.000000</td>
      <td>1000.000000</td>
      <td>1000.000000</td>
      <td>1000.000000</td>
    </tr>
    <tr>
      <th>mean</th>
      <td>-0.005443</td>
      <td>0.024692</td>
      <td>-0.025744</td>
      <td>0.033268</td>
    </tr>
    <tr>
      <th>std</th>
      <td>0.958800</td>
      <td>0.991559</td>
      <td>0.960159</td>
      <td>0.976341</td>
    </tr>
    <tr>
      <th>min</th>
      <td>-3.000000</td>
      <td>-3.000000</td>
      <td>-3.000000</td>
      <td>-2.846379</td>
    </tr>
    <tr>
      <th>25%</th>
      <td>-0.655577</td>
      <td>-0.625746</td>
      <td>-0.629501</td>
      <td>-0.590840</td>
    </tr>
    <tr>
      <th>50%</th>
      <td>-0.040904</td>
      <td>0.007496</td>
      <td>-0.032268</td>
      <td>-0.000206</td>
    </tr>
    <tr>
      <th>75%</th>
      <td>0.658279</td>
      <td>0.661891</td>
      <td>0.619206</td>
      <td>0.686097</td>
    </tr>
    <tr>
      <th>max</th>
      <td>3.000000</td>
      <td>3.000000</td>
      <td>3.000000</td>
      <td>3.000000</td>
    </tr>
  </tbody>
</table>

</div>



```python
np.sign(data).head()

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
      <th>3</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>-1.0</td>
      <td>-1.0</td>
      <td>1.0</td>
      <td>1.0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1.0</td>
      <td>1.0</td>
      <td>-1.0</td>
      <td>1.0</td>
    </tr>
    <tr>
      <th>2</th>
      <td>-1.0</td>
      <td>1.0</td>
      <td>1.0</td>
      <td>1.0</td>
    </tr>
    <tr>
      <th>3</th>
      <td>1.0</td>
      <td>-1.0</td>
      <td>-1.0</td>
      <td>-1.0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>-1.0</td>
      <td>1.0</td>
      <td>1.0</td>
      <td>1.0</td>
    </tr>
  </tbody>
</table>

</div>



```python
# 排列和随机采样
df = pd.DataFrame(np.arange(5 * 4).reshape((5, 4)))
sampler = np.random.permutation(5)
sampler

```



```
array([4, 3, 1, 2, 0])

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
      <th>0</th>
      <th>1</th>
      <th>2</th>
      <th>3</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>0</td>
      <td>1</td>
      <td>2</td>
      <td>3</td>
    </tr>
    <tr>
      <th>1</th>
      <td>4</td>
      <td>5</td>
      <td>6</td>
      <td>7</td>
    </tr>
    <tr>
      <th>2</th>
      <td>8</td>
      <td>9</td>
      <td>10</td>
      <td>11</td>
    </tr>
    <tr>
      <th>3</th>
      <td>12</td>
      <td>13</td>
      <td>14</td>
      <td>15</td>
    </tr>
    <tr>
      <th>4</th>
      <td>16</td>
      <td>17</td>
      <td>18</td>
      <td>19</td>
    </tr>
  </tbody>
</table>

</div>



```python
df.take(sampler)

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
      <th>3</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>4</th>
      <td>16</td>
      <td>17</td>
      <td>18</td>
      <td>19</td>
    </tr>
    <tr>
      <th>3</th>
      <td>12</td>
      <td>13</td>
      <td>14</td>
      <td>15</td>
    </tr>
    <tr>
      <th>1</th>
      <td>4</td>
      <td>5</td>
      <td>6</td>
      <td>7</td>
    </tr>
    <tr>
      <th>2</th>
      <td>8</td>
      <td>9</td>
      <td>10</td>
      <td>11</td>
    </tr>
    <tr>
      <th>0</th>
      <td>0</td>
      <td>1</td>
      <td>2</td>
      <td>3</td>
    </tr>
  </tbody>
</table>

</div>



```python
df.sample(n=3)

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
      <th>3</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>4</th>
      <td>16</td>
      <td>17</td>
      <td>18</td>
      <td>19</td>
    </tr>
    <tr>
      <th>3</th>
      <td>12</td>
      <td>13</td>
      <td>14</td>
      <td>15</td>
    </tr>
    <tr>
      <th>0</th>
      <td>0</td>
      <td>1</td>
      <td>2</td>
      <td>3</td>
    </tr>
  </tbody>
</table>

</div>



```python
choices = pd.Series([5, 7, -1, 6, 4])

```

```python
draws = choices.sample(n=10, replace=True)
draws

```



```
1    7
2   -1
1    7
2   -1
1    7
3    6
0    5
1    7
2   -1
4    4
dtype: int64

```



```python
# 计算指标/哑变量
df = pd.DataFrame({'key': ['b', 'b', 'a', 'c', 'a', 'b'],
                   'data1': range(6)})
pd.get_dummies(df['key'])

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
      <td>0</td>
      <td>1</td>
      <td>0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>0</td>
      <td>1</td>
      <td>0</td>
    </tr>
    <tr>
      <th>2</th>
      <td>1</td>
      <td>0</td>
      <td>0</td>
    </tr>
    <tr>
      <th>3</th>
      <td>0</td>
      <td>0</td>
      <td>1</td>
    </tr>
    <tr>
      <th>4</th>
      <td>1</td>
      <td>0</td>
      <td>0</td>
    </tr>
    <tr>
      <th>5</th>
      <td>0</td>
      <td>1</td>
      <td>0</td>
    </tr>
  </tbody>
</table>

</div>



```python
dummies = pd.get_dummies(df['key'], prefix='key')
df_with_dummy = df[['data1']].join(dummies) 
df_with_dummy

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
      <th>key_a</th>
      <th>key_b</th>
      <th>key_c</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>0</td>
      <td>0</td>
      <td>1</td>
      <td>0</td>
    </tr>
    <tr>
      <th>1</th>
      <td>1</td>
      <td>0</td>
      <td>1</td>
      <td>0</td>
    </tr>
    <tr>
      <th>2</th>
      <td>2</td>
      <td>1</td>
      <td>0</td>
      <td>0</td>
    </tr>
    <tr>
      <th>3</th>
      <td>3</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
    </tr>
    <tr>
      <th>4</th>
      <td>4</td>
      <td>1</td>
      <td>0</td>
      <td>0</td>
    </tr>
    <tr>
      <th>5</th>
      <td>5</td>
      <td>0</td>
      <td>1</td>
      <td>0</td>
    </tr>
  </tbody>
</table>

</div>



```python
mnames = ['movie_id', 'title', 'genres']
movies = pd.read_table('datasets/movielens/movies.dat', sep='::', 
                       header=None, names=mnames,engine='python')
#加上engine='python'可以避免正则表达式分隔符的警告信息
movies[:10]

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
      <th>movie_id</th>
      <th>title</th>
      <th>genres</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>1</td>
      <td>Toy Story (1995)</td>
      <td>Animation|Children's|Comedy</td>
    </tr>
    <tr>
      <th>1</th>
      <td>2</td>
      <td>Jumanji (1995)</td>
      <td>Adventure|Children's|Fantasy</td>
    </tr>
    <tr>
      <th>2</th>
      <td>3</td>
      <td>Grumpier Old Men (1995)</td>
      <td>Comedy|Romance</td>
    </tr>
    <tr>
      <th>3</th>
      <td>4</td>
      <td>Waiting to Exhale (1995)</td>
      <td>Comedy|Drama</td>
    </tr>
    <tr>
      <th>4</th>
      <td>5</td>
      <td>Father of the Bride Part II (1995)</td>
      <td>Comedy</td>
    </tr>
    <tr>
      <th>5</th>
      <td>6</td>
      <td>Heat (1995)</td>
      <td>Action|Crime|Thriller</td>
    </tr>
    <tr>
      <th>6</th>
      <td>7</td>
      <td>Sabrina (1995)</td>
      <td>Comedy|Romance</td>
    </tr>
    <tr>
      <th>7</th>
      <td>8</td>
      <td>Tom and Huck (1995)</td>
      <td>Adventure|Children's</td>
    </tr>
    <tr>
      <th>8</th>
      <td>9</td>
      <td>Sudden Death (1995)</td>
      <td>Action</td>
    </tr>
    <tr>
      <th>9</th>
      <td>10</td>
      <td>GoldenEye (1995)</td>
      <td>Action|Adventure|Thriller</td>
    </tr>
  </tbody>
</table>

</div>



```python
all_genres = []
for x in movies.genres:
    all_genres.extend(x.split('|'))

```

```python
genres = pd.unique(all_genres)

```

```python
genres

```



```
array(['Animation', "Children's", 'Comedy', 'Adventure', 'Fantasy',
       'Romance', 'Drama', 'Action', 'Crime', 'Thriller', 'Horror',
       'Sci-Fi', 'Documentary', 'War', 'Musical', 'Mystery', 'Film-Noir',
       'Western'], dtype=object)

```



```python
zero_matrix = np.zeros((len(movies), len(genres)))

```

```python
dummies = pd.DataFrame(zero_matrix, columns=genres)

```

```python
gen = movies.genres[0]

```

```python
gen.split('|')

```



```
['Animation', "Children's", 'Comedy']

```



```python
dummies.columns.get_indexer(gen.split('|'))

```



```
array([0, 1, 2], dtype=int64)

```



```python
for i, gen in enumerate(movies.genres):
    indices = dummies.columns.get_indexer(gen.split('|'))
    dummies.iloc[i, indices] = 1 

```

```python
movies_windic = movies.join(dummies.add_prefix('Genre_')) 
movies_windic.iloc[0]

```



```
movie_id                                       1
title                           Toy Story (1995)
genres               Animation|Children's|Comedy
Genre_Animation                                1
Genre_Children's                               1
Genre_Comedy                                   1
Genre_Adventure                                0
Genre_Fantasy                                  0
Genre_Romance                                  0
Genre_Drama                                    0
Genre_Action                                   0
Genre_Crime                                    0
Genre_Thriller                                 0
Genre_Horror                                   0
Genre_Sci-Fi                                   0
Genre_Documentary                              0
Genre_War                                      0
Genre_Musical                                  0
Genre_Mystery                                  0
Genre_Film-Noir                                0
Genre_Western                                  0
Name: 0, dtype: object

```



```python
np.random.seed(12345)
values = np.random.rand(10)
values

```



```
array([0.92961609, 0.31637555, 0.18391881, 0.20456028, 0.56772503,
       0.5955447 , 0.96451452, 0.6531771 , 0.74890664, 0.65356987])

```



```python
bins = [0, 0.2, 0.4, 0.6, 0.8, 1]
pd.get_dummies(pd.cut(values, bins))

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
      <th>(0.0, 0.2]</th>
      <th>(0.2, 0.4]</th>
      <th>(0.4, 0.6]</th>
      <th>(0.6, 0.8]</th>
      <th>(0.8, 1.0]</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>0</th>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
    </tr>
    <tr>
      <th>1</th>
      <td>0</td>
      <td>1</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
    </tr>
    <tr>
      <th>2</th>
      <td>1</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
    </tr>
    <tr>
      <th>3</th>
      <td>0</td>
      <td>1</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
    </tr>
    <tr>
      <th>4</th>
      <td>0</td>
      <td>0</td>
      <td>1</td>
      <td>0</td>
      <td>0</td>
    </tr>
    <tr>
      <th>5</th>
      <td>0</td>
      <td>0</td>
      <td>1</td>
      <td>0</td>
      <td>0</td>
    </tr>
    <tr>
      <th>6</th>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
    </tr>
    <tr>
      <th>7</th>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
      <td>0</td>
    </tr>
    <tr>
      <th>8</th>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
      <td>0</td>
    </tr>
    <tr>
      <th>9</th>
      <td>0</td>
      <td>0</td>
      <td>0</td>
      <td>1</td>
      <td>0</td>
    </tr>
  </tbody>
</table>

</div>



```python
# 字符串操作
val = 'a,b,  guido' 
val.split(',')

```



```
['a', 'b', '  guido']

```



```python
# split 常常与 strip 一起使用，以去除空白符（包括换行符）
pieces = [x.strip() for x in val.split(',')]
pieces

```



```
['a', 'b', 'guido']

```



```python
first, second, third = pieces
first + '::' + second + '::' + third

```



```
'a::b::guido'

```



```python
'::'.join(pieces)

```



```
'a::b::guido'

```



```python
'guido' in val

```



```
True

```



```python
val.index(',')

```



```
1

```



```python
val.find(':')

```



```
-1

```



```python
val.index('b')
# 注意 find 和 index 的区别：
# 如果找不到字符串，index 将会引发一个异常（而不是返回－1）
# val.index(':')

```



```
2

```



```python
val.count(',')

```



```
2

```



```python
val.replace(',', '::')

```



```
'a::b::  guido'

```



```python
val.replace(',', '')

```



```
'ab  guido'

```



```python
# 正则表达式 
import re
text = "foo    bar\t baz  \tqux"
re.split('\s+', text)

```



```
['foo', 'bar', 'baz', 'qux']

```



```python
regex = re.compile('\s+')
regex.split(text)

```



```
['foo', 'bar', 'baz', 'qux']

```



```python
regex.findall(text)

```



```
['    ', '\t ', '  \t']

```



```python
text = """Dave dave@google.com 
        Steve steve@gmail.com 
        Rob rob@gmail.com 
        Ryan ryan@yahoo.com """ 
pattern = r'[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,4}' 
# re.IGNORECASE 不区分大小写 
regex = re.compile(pattern, flags=re.IGNORECASE)
regex.findall(text)

```



```
['dave@google.com', 'steve@gmail.com', 'rob@gmail.com', 'ryan@yahoo.com']

```



```python
m = regex.search(text)
m

```



```
<_sre.SRE_Match object; span=(5, 20), match='dave@google.com'>

```



```python
text[m.start():m.end()]

```



```
'dave@google.com'

```



```python
print(regex.match(text))

```

```
None

```



```python
print(regex.sub('REDACTED', text))

```

```
Dave REDACTED 
        Steve REDACTED 
        Rob REDACTED 
        Ryan REDACTED 

```



```python
pattern = r'([A-Z0-9._%+-]+)@([A-Z0-9.-]+)\.([A-Z]{2,4})'
regex = re.compile(pattern, flags=re.IGNORECASE)

```

```python
m = regex.match('wesm@bright.net')
m.groups()

```



```
('wesm', 'bright', 'net')

```



```python
regex.findall(text)

```



```
[('dave', 'google', 'com'),
 ('steve', 'gmail', 'com'),
 ('rob', 'gmail', 'com'),
 ('ryan', 'yahoo', 'com')]

```



```python
print(regex.sub(r'Username: \1, Domain: \2, Suffix: \3', text))

```

```
Dave Username: dave, Domain: google, Suffix: com 
        Steve Username: steve, Domain: gmail, Suffix: com 
        Rob Username: rob, Domain: gmail, Suffix: com 
        Ryan Username: ryan, Domain: yahoo, Suffix: com 

```



```python
data = {'Dave': 'dave@google.com', 'Steve': 'steve@gmail.com',
        'Rob': 'rob@gmail.com', 'Wes': np.nan}

```

```python
data = pd.Series(data)
data

```



```
Dave     dave@google.com
Rob        rob@gmail.com
Steve    steve@gmail.com
Wes                  NaN
dtype: object

```



```python
data.isnull()

```



```
Dave     False
Rob      False
Steve    False
Wes       True
dtype: bool

```



```python
data.str.contains('gmail') 

```



```
Dave     False
Rob       True
Steve     True
Wes        NaN
dtype: object

```



```python
pattern

```



```
'([A-Z0-9._%+-]+)@([A-Z0-9.-]+)\\.([A-Z]{2,4})'

```



```python
data.str.findall(pattern, flags=re.IGNORECASE)

```



```
Dave     [(dave, google, com)]
Rob        [(rob, gmail, com)]
Steve    [(steve, gmail, com)]
Wes                        NaN
dtype: object

```



```python
matches = data.str.match(pattern, flags=re.IGNORECASE)
matches

```



```
Dave     True
Rob      True
Steve    True
Wes       NaN
dtype: object

```



```python
matches.str.get(1)

```



```
Dave    NaN
Rob     NaN
Steve   NaN
Wes     NaN
dtype: float64

```



```python
matches.str[0]

```



```
Dave    NaN
Rob     NaN
Steve   NaN
Wes     NaN
dtype: float64

```



```python
data.str[:5]

```



```
Dave     dave@
Rob      rob@g
Steve    steve
Wes        NaN
dtype: object

```

