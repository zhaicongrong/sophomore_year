## Basics of C++

### structure of a program

```c++
#include <iostream>
int main()
{
	std::cout << "Hello World!";
}
```

the function named mai nis a special function in all C++ programs.

std::out : **standard character output** 。并不会自动换行

- std::cout: qualifies directly within the namespace std
- cout: unqualified name

为了避免每次都使用`std::cout`，因为太过麻烦，使用`using namespace std;`。

### variables and types

character types

| Type names | Notes                                         |
| ---------- | --------------------------------------------- |
| char       | 1 byte 8 bits                                 |
| char16_t   |                                               |
| char32_t   |                                               |
| wchar_t    | represent the largest supported character set |

- integer types
  - `signed char`
  - `signed short int`
  - `signed int`
  - `signed long int`
  - `signed long long int`

- integer types(unsigned) 无符号

  - `unsigned char`

    ...

- floating-point types

  - `float`
  - `double`
  - `long double`

- Boolean type

  - `bool`

- Void type

  - `void`

- Null pointer

  - `decltype`

#### 初始化变量

1. `int x= 0;`

2. `int x (0);`
3. ` int x {0};`

注：这三种方式是等价的。

#### type deduction: auto and decltype

1. 

```c++
int foo = 0;
auto bar = foo;
```

bar被定义为auto类型。与`int bar = foo`等价

2. 

```c++
int foo = 0;
decltype(foo) bar;//the same as : int bar;
```

坏处：降低了程序的可读性

#### introduction to string

`#include <string>`

注意`cout<<`和`cout<< <<endl;`的区别。`endl`表示**end line**。

### 常量

#### 整数

```c++
75 //decimal
0113 //octal
0x4b //hexadecimal
```

```c++
75 //int
75u //unsigned int
75l //long
75ul //unsigned long
75lu //unsigned long
```

#### 浮点数

```c++
3.14159L //long double
6.02e23f // float
```

#### 字符和字符串

此处有疑问？

### 基础的输入输出

- `cin`

`cin >> a >> b;`

如果想输入一整行的信息，并且读入到一个identifier中，就要用到getline函数。

将读入的字符流变为数字（可以是整型，也可以是浮点型）的函数：

​	首先，必须先加入头文件`#include <sstream>`

​	`stringstream(mystr) >> price`

​	就将mystr转为int/float型了！

`getline(cin, mystr);`

- `cout`
- `cerr` : 标准错误输出流
- `clog` ： standard logging (output) stream

### 函数结构

地址

`void add(string& a, string& b);`

非地址方式

`void add(string a, string b);`

````c++
void duplicate(const int& a, int b, int c)
{
    a++;//这边会报错，由于a虽然传进了地址，但是是const，说明值不能发生变化
    cout << "a: " << a << " b: " << b << " c: " << c << endl;
}
````

- 函数中的默认参数

`int divide (int a, int b = 2);`

在调用时可以这么写`divide(2)`，也可以这么些`divide(2, 4)`。

### overloads and templates

两个函数可以有相同的名字，如果他们中的参数类型，参数个数是不同的话。

`template <template-parameters> function-declaration`

例子：

```c++
template <class SomeType>
SomeType sum (SomeType a, SomeType b)
{
	return a+b;
}
```

通过使用`name <template-arguments> (function-arguments)`来实现

例如`x = sum<int>(10,20);`

```c++
int sum(int a, int b)
{
	return a+b;
}
```

```c++
template <class T>
void mySwap(T&a, T&b)
{
	T temp = a;
	a = b;
	b = temp;
}
```

必须要确定T的类型，才可以使用模板。  

实际的例子

```c++
     #include <iostream>
#include <string>
using namespace std;
template <class T>
T sum (T a, T b)
{
    T result;
    result = a + b;
    return result;
}
int main()
{
    int k = sum<int>(1,2);
    double j = sum<double>(2.4, 3.5);
    cout << k << endl;
    cout << j << endl;
    return 0;
}

```

当然，一个函数中有两个不同类型的参数的时候，可以这么使用

`template <class T, class U>`，则有函数的使用型式`are_equal<int, double>(10, 10.0)`。

### name visibility

- namespaces

````c++
namespace myNamespace
{
	int a, b;
}
````

引用的时候就可以使用`myNameSpace::a`和`myNameSpace::b`。

- using

using 将一个常量指定为特定block中的常量

例如

```c++
namespace first
{
	int x = 5;
	int y = 6;
}
namespace seconde
{
	double x = 3.1416;
	double y = 2.7183;
}

int main()
{
	using first::x;
	using second::y;
}
```

或者在main函数中使用using namespace first。直接调用所有first 的namespace中的元素。

**using和suing namespace仅仅只在一个块中有效。**

## 复合数据类型

### 数组

````c++
#include <array>
array<int, 3> myarray{10, 20, 30};
````





## 类

1. 公共权限 public **成员 类内可以访问 类外可以访问**
2. 保护权限 protected  **类外不可以访问 儿子可以访问父亲中的保护内容**

1. 私有权限 private **类外不可以访问 儿子不可以访问父亲中的私有内容**

class的默认权限是私有的。struct默认权限是公共。



## 构造函数和析构函数

### 构造函数语法

`类名()[]`

可以有参数，因此可以发生重载。

返回值不写void。即使不写系统也会自动加上， 只是没有任何操作。

创建对象时，自动调用函数只会调用函数一次。

```c++
public Person
{
	public:
		Person()
		{
			cout << "" << endl;
		}
}
```

#### 构造函数分类

无参构造（默认构造）和有参构造

```c++
person(int a)
{
    age = a;
	...
}
```

普通构造（默认构造）和拷贝构造

拷贝构造

```c++
Person( const Person &p )
{
	age = p.age;
	...
}
```

实际情况

```c++
void test01()
{
	Person p1;//默认析构函数调用，注意，此处不需要加括号
	Person p2(10);//有参构造函数
    //相当于Person p2 = 10;
	Person p3(ps);//拷贝构造函数调用
}
```



### 析构函数

`~类名()[]`

不可以有参数。

在哪一个函数体中执行，就在哪一个函数体运行 到最后的时候最后释放这个对象。

````c++
public Person
{
	public:
		~Person()
		{
			cout << "" << endl;
		}
}
````

因此如果在main.c中创建在return 0之后才会执行，几乎看不到析构函数的执行效果



## 函数

普通函数会自动发生类型转换

函数模板不会发生类型转换，在参数传递的时候，所以参数类型不同时必须要指定类型。

### 类模板

```c++
template<class NameType, class AgeType>
class Person
{
	public:
		Person(NameType name, AgeType, age)
		{
			this->m_Name = name;
			this->m_Age = age;
		}
		NameType m_Name;
		AgeType m_Age;
};

void test01()
{
	Person<string, int>
}
```



## stl

### vector

### vector容器的创建

```c++
vector<int> vectorInt;
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};
vector<Person> v;//类的vector
```

### vector容器的处理

```c++
vector<type> v;
v.pushback(..);
vector<type>::iterator itBegin = v.begin();
vector<type>::iterator itEnd = v.end();
//遍历处理
for(vector<type>::iterator it = v.begin(); it != v.end(); it++)
	cout << (*it).name << endl;//注意，it是指针值。
```

对于指针的理解

```c++
void test02(void)
{
    vector<Person*> v;
    Person p1("aaa", 10);
    Person p2("eee", 20);
    Person p3("bbb", 30);
    Person p4("ddd", 40);
    Person p5("ccc", 50);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);
    for(vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
        cout << "Name:" << (**it).m_Name << " Age:" << (**it).m_Age << endl;
}
```



#### 容器中嵌套容器

基本操作

```c++
vector<vector<int>> v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    for (int i = 0; i < 4; i++) {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        for(vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
            cout << *vit << "";
        cout << endl;
    }
```

## string容器

是`char*`的容器。

#### string的构造函数

1. 默认构造

`string s1`

2. 使用字符串s初始化

`const char * str = "hello world";`

`string s2(str);`

有const是因为“hello world”是字符串常量，常量不可修改。

3. 使用一个string对象初始化另一个string对象

`string s3(s2);`

4. 使用n个字符c初始化

`string s4(10, 'a');`

表示字符串有10个a。

#### 赋值操作

```c++
	string str1;
    str1 = "hello world";;
    cout << "str1= " << str1 << endl;

    string str2;
    str2 = str1;//"hello world"

    string str3;
    str3 = 'a';

    string str4;
    str4.assign("hello c++");//利用assign赋值

    string str5;
    str5.assign("hello c++", 5);//取前5个字符
    cout << str5 << endl;
    
    string str6;
    str6.assign(str5);//拷贝构造
    
    string str7;
    str7.assign(10, 'w');//wwwwwww
```

```c++
str1 += str2; //两字符串相连
str1.append(" which you would like to add "); //str1 += "..."
str1.append(" game happy game", 6) //添加的是" game "
str1.append(" game happy game", 4, 3) //截取第4个开始，截取3个字符
```







