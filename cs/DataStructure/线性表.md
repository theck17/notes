---
title: '数据结构：线性表'
date: 2019-12-15 23:16:16
tags: [Data structures and algorithms]
published: true
hideInList: false
feature: /post-images/shu-ju-jie-gou-xian-xing-biao.jpg
---
# 线性表

## 线性表的定义和基本操作

* 定义：线性表数具有**相同类型**的n(n>0)个元素的**有限序列**，其中n为表长，n=0时为空表
* 特性：
  * 表中元素**有限**
  * 表中元素具有逻辑上的顺序性，在序列中各个元素排序是有其先后次序的
  * 表中都是**数据元素**，每个元素都是单个元素
  * 表彰元素的**数据类型都相同**， 这意味着每个元素战友相同大小的存储空间
  * 表中元素具有**抽象性**， 即讨论元素间一对一的逻辑关系，而不考虑元素究竟表示的内容
  * 线性表是一种**逻辑结构**， 表示元素之间一对一相邻的关系
* 基本操作
  * InitList(&L)：初始化表，构造一个空的线性表
  * DestroyList(&L)：销毁操作，销毁线性表，释放线性表L所占用的内存空间
  * LocateElem(L,e)：按值查找，在表中L查找具有给定关键字值的元素
  * GetElem(L,i)：按位查找，获取表L中第i个位置的元素的值，i要小于表长
  * ListInsert(&L,i,e)：插入操作，在表L中的第i个位置上插入指定元素e，前插
  * ListDelete(&L,i,&e)：删除操作，删除表L种第i个位置的元素，并用e返回删除元素的值
  * PrintList(L)：输出操作，按前后顺序输出线性表L的所有元素值
  * Empty(L)：判空操作，或L为空表，返回True，否则返回False
  * Length(L)：求表长，返回线性表L的长度，即L的数据元素的个数

## 线性表的顺序表示

* 顺序表的定义：线性表的顺序存储

  * ​	数组静态分配

    ```c++
    #define MaxSize 50
    typedef struct{
        ElemType data[MaxSize];
        int length;
    }SqlList;
    ```

  * 数组动态分配

    ```c++
    #define MaxSize 50
    typedef struct{
        ElemType *data;
        int length;
    }SqlList;
    ```

  * C：

    * ```c++
      L.data = (ElemType*)malloc(sizeof(ElemType)*InitSize);
      ```

  * C++

    * ```c++
      L.data = new ElemType[InitSize];
      ```

* 顺序表基本操作

  * 插入操作

    ```C++
    bool ListInsert(SqList &L,int i,ElemType e){
        //将元素e插入到顺序表L中的第i个位置
        if(i<1||i>L.length+1)
            return false;			//判断i是否有效
        if(L.length>=MaxSize)
            return false;			//判断存储空间是否已满
        for(int j=L.length;j>=j;j--)//将第i个位置及之后元素后移
            L.data[j]=L.data[j-1];
        L.data[i-1]=e;				//在位置i处放入e
        L.length++;					//线性表长度加1
        return true;
    }
    ```

  * 删除操作

    ```c++
    bool ListDelete(SqList &L,int i,int &e){
        //删除顺序表第i个位置的元素
        if(i<1||i>L.length+1)
            return false;			//判断i是否有效
        e=L.data[i-1];				//将被删除元素赋值给e
        for(int j=i;j<L.length;j++) //将第i个位置及之后元素前移
            L.data[j-1]=L.data[j];
        L.length--;					//线性表长度减1
        return true;
    }
    ```

  * 按值查找

    ```c++
    int LocateElem(SqList &L,ElemType e){
        //在顺序表汇中查找值为e的元素，成功返回元素的位序，否则返回0
        int i;
        for(i=0;i<L.length;i++)
            if(L.data[i]==e)
                return i+1;		//下标为i的元素值的等于e，返回其位号i+1
        return 0;				//退出循环，说明查找失败
    }
    ```

    

  

## 线性表的链式表示 

* 单链表定义：单链表的链式存储

  ```c++
  typedef struct LNode{
      ElemType data;
      struct LNode *next;
  }LNode, *LinkList;
  ```

* 单链表基本操作

  * 头插法建立单链表

  ```c++
  Linklist CreatList1(LinkList &L) {
      //从表尾到表头逆向建立单链表L，每次均在头结点之后插入元素
      LNode *s;int x;
      L=(LinkList)malloc(sizeof(LNode));  //创建头结点
      L->next=NULL;						//初始化为空链表
      scanf("%d",&x);						//输入结点的值
      while(x!=9999){						//输入9999表示结束
          s=(LNode*)malloc(sizeof(LNode));//创建新节点结点
          s->data=x;
          s->next=L->next;
          L->next=s;						//将新结点插入到表中，L为头指针
          scanf("%d",&x);
      }									//while结束
      return L;
  }
  ```

  

  * 尾插法建立单链表

  ```c++
  Linklist CreatList2(LinkList &L) {
      //从表头到表尾正向建立单链表L，每次均在表尾插入元素
      int x;								//设置元素类型为整型
      L=(LinkList)malloc(sizeof(LNode));  //创建尾结点
      LNode *s,*r=L;						//r为表尾指针
      scanf("%d",&x);						//输入结点的值
      while(x!=9999){						//输入9999表示结束
          s=(LNode*)malloc(sizeof(LNode));//创建新节点结点
          s->data=x;
          r->next=s;
          r=s;							//r指向新的表尾结点
          scanf("%d",&x);
      }									//while结束
      r->next=NULL;						//尾结点指针置空	
      return L;
  }
  ```

  

  * 按序号查找结点

  ```c++
  LNode *GetElem(LinkList L,int i){
      //取出单链表L（带头结点）中第i个位置的结点指针
  	int j=i;				//计数，初始为1
      LNode *p=L->next;		//头结点指针赋值给p
      if(i==0)
          return L;			//若i==0，则返回头结点
      if(i<1)
          return NULL;		//若i无效，则返回NULL
      while(p&&j<i){			//从第1个结点开始找，查找第i个结点
  		p=p->next;
          j++;
      }
      return p;				//返回第i个结点的指针，如果i大于表长，p=NULL，直接返回p即可
  }
  ```

  

  * 按值查找结点

  ```c++
  LNode *LocateElem(LinkList L,ElemType e){
      //查找单链表L（带头结点）中数据域值等于e的结点指针，否则返回NULL
      LNode *p=L->next;
      while(p!=NULL&&p->data!=e)		//从第1个结点开始查找data域为e的结点
          p=p->next;
      return p;						//找到后返回该结点指针，否则返回NULL
  }
  ```

  

  * 插入节点

  ```c++
  //插入结点代码片段
  ①p=GetElem(L,i-1);//查找插入位置的前驱结点
  ②s->next=p->next;
  ③p->next=s;
  //将*s结点插入到*p之前的主要代码片段
  s->next=p->next;//修改指针域，不能颠倒
  p->next=s;
  temp=p->data;//交换数据域部分
  p->data=s->data;
  s->data=temp;
  ```

  

  * 删除节点

  ```c++
  //删除结点代码片段
  p=GetElem(L,i-1);	//查找删除位置的前驱结点
  q=p->next;			//令q指向被删除结点
  p->next=q->next;	//将*q结点从链中“断开”
  free(q);			//释放结点存储空间
  //删除操作代码片段
  q=p->next;			//令q指向*p的后继结点
  p->data=p->next->data;//和后继结点交换数据域
  p->next=q->next;	//将*q结点从链中“断开”
  free(q);			//释放后继结点的存储空间
  ```

  

  * 求表长

  ```c++
  int count=0;
  p=head;
  while(p->next!=NULL){
      count++;
      p=p->next;
  }
  ```

  

* 几种常用链表：

  * 双链表

  ```c++
  typedef struct DNode{		//定义双链表的结点类型
      ElemType data;			//数据域
      struct DNode *prior, *next;//前驱和后继指针
  }DNode,*DLinklist;
  ```

  

  * 循环链表
  * 静态链表

  ```c++
  #define MaxSize 50		//静态链表的最大长度
  typedef struct{			//静态链表结构类型的定义
      ElemType data;		//存储数据元素
      int next;			//下一个元素的数组下标
  }SLinkList[MaxSize];
  ```

  

