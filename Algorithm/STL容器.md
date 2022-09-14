# STL容器

## 向量（vector）

定义方式：

```c++
vector<int> v1;		//定义元素为int的向量v1
vector<int> v2(10);		//指定向量v2的初始大小为10个int元素
vector<double> v3(10，1.23);	//指定v3的10个初始元素的初值为1.23
vector<int> v4(a，a+5);	//用数组a[0..4]共5个元素初始化v4
```

vector容器方式：

```c++
empty()：判断当前向量容器是否为空。
size()：返回当前向量容器的中的实际元素个数。
[]：返回指定下标的元素。
reserve(n)：为当前向量容器预分配n个元素的存储空间。
capacity()：返回当前向量容器在重新进行内存分配以前所能容纳的元素个数。
resize(n) ：调整当前向量容器的大小，使其能容纳n个元素。
push_back()：在当前向量容器尾部添加了一个元素。
insert(pos，elem)：在pos位置插入元素elem，即将元素elem插入到迭代器pos指定元素之前。
front()：获取当前向量容器的第一个元素。
back()：获取当前向量容器的最后一个元素。
erase()：删除当前向量容器中某个迭代器或者迭代器区间指定的元素。
clear()：删除当前向量容器中所有元素。
迭代器函数：begin()、end()、rbegin()、rend()。

```

## 字符串（string）

定义方式：

```c++
char cstr[]="China! Greate Wall";	//C-字符串
string s1(cstr);			// s1:China! Greate Wall
string s2(s1);				// s2:China! Greate Wall
string s3(cstr，7，11);		// s3:Greate Wall
string s4(cstr，6);			// s4:China!
string s5(5，'A');			// s5:AAAAA

```

sting容器方式：

```c++
empty()：判断当前字符串是否为空串。
size()：返回当前字符串的实际字符个数（返回结果为size_type类型）。
length()：返回当前字符串的实际字符个数。
[idx]：返回当前字符串位于idx位置的字符，idx从0开始。
at(idx)：返回当前字符串位于idx位置的字符。
compare(const string& str)：返回当前字符串与字符串str的比较结果。在比较时，若两者相等，返回0；前者小于后者，返回-1；否则返回1。
append(cstr)：在当前字符串的末尾添加一个字符串str。
insert(size_type idx，const string& str)	：在当前字符串的idx处插入一个字符串str。
迭代器函数：begin()、end()、rbegin()、rend()。
```

## 双端队列容器（deque）

定义方式：

```c++
deque<int> dq1;	//定义元素为int的双端队列dq1
deque<int> dq2(10);	//指定dq2的初始大小为10个int元素
deque<double> dq3(10，1.23);
			//指定dq3的10个初始元素的初值为1.23
deque<int> dq4(dq2.begin()，dq2.end());	
			//用dq2的所有元素初始化dq4

```

方法：

```c++
empty()：判断双端队列容器是否为空队。
size()：返回双端队列容器中元素个数。
push_front(elem)：在队头插入元素elem。
push_back(elem)：在队尾插入元素elem。
pop_front()：删除队头一个元素。
pop_back()：删除队尾一个元素。
erase()：从双端队列容器中删除一个或几个元素。
clear()：删除双端队列容器中所有元素。
迭代器函数：begin()、end()、rbegin()、rend()。

```

