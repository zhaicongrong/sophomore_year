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

