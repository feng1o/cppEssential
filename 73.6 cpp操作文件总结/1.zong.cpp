/*
1.打开的文件模式中有ios::in，则若文件不存在，不会创建文件。ofstream fin("c:\\a.txt", ios::in); 对于这句，若后面不使用fin，则编译可以通过

2.open的时候，in，out不是重点；重点要有app，或者trunc
3.打开文件的方式在iOS类(所以流式I/O的基类)中定义，有如下几种方式：http://blog.csdn.net/kingstar158/article/details/6859379

	ios::in 	为输入(读)而打开文件
	ios::out 	为输出(写)而打开文件
	ios::ate 	初始位置：文件尾
	ios::app 	所有输出附加在文件末尾
	ios::trunc 	如果文件已存在则先删除该文件
	ios::binary 	二进制方式

4.tellg() 和 tellp()

	这两个成员函数不用传入参数，返回pos_type 类型的值(根据ANSI-C++ 标准) ，就是一个整数，代表当前get 流指针的位置 (用tellg) 或 put 流指针的位置(用tellp).
5.seekg() 和seekp()

	这对函数分别用来改变流指针get 和put的位置。两个函数都被重载为两种不同的原型：

6. zong
ofstream流，以ios::app打开（或者“ios::app|ios::out”）,如果没有文件，那么生成空文件；如果有文件，那么在文件尾追加。
以ios::app|ios::in打开，不管有没有文件，都是失败。
以ios::ate打开（或者”ios::ate|ios::out”），如果没有文件，那么生成空文件；【如果有文件，那么清空该文件】
以ios::ate|ios::in打开，如果没有文件，那么打开失败；如果有文件，那么定位到文件尾，并可以写文件，但是不能读文件

ifstream流，以ios::app打开（“ios::app|ios::out”）,不管有没有文件，打开都是失败。
以ios::ate打开（“ios::ate|ios::out”）,如果没有文件，打开失败
如果有文件，打开成功，并定位到文件尾，但是不能写文件


fstream流，默认是ios::in，所以如果没有文件，ios::app和ios::ate都是失败，
以ios::app|ios::out,如果没有文件则创建文件，如果有文件，则在文件尾追加
以ios::ate|ios::out打开，如果没有文件则创建文件，如果有，则清空文件。
以ios::ate|ios::out|ios::in打开，如果没有文件，则打开失败，有文件则定位到文件尾

可见：ios::app不能用来打开输入流，即不能和ios::in相配合
而ios::ate可以和ios::in配合，此时定位到文件尾；如果没有ios::in相配合而只是同ios::out配合，那么将清空原文件

可以在《C++ 输入输出流及本地化》1.4.2中找到更详细的描述：（大意）以ios::app方式打开文件，即使修改文件指针，也只能输出到文件尾。实际上以ios::app打开的文件的写入，和文件指针五关。

奇怪的是：《C++ 输入输出流及本地化》和《C++编程思想》都说以ios::ate打开的文件，文件指针都会定位到文件尾且不清空文件，但是我发现ios::ate如果不和ios::in配合的话，将清空原文件。
//
五、C++文件流文件定位
和C的文件操作方式不同的是，C++ I/O系统管理两个与一个文件相联系的指针。一个是读指针，它说明输入操作在文件中的位置；另一个是写指针，它下次写操作的位置。每次执行输入或输出时，相应的指针自动变化。所以，C++的文件定位分为读位置和写位置的定位，对应的成员函数是 seekg()和 seekp()，seekg()是设置读位置，seekp是设置写位置。它们最通用的形式如下：
1.  istream &seekg(streamoff offset,seek_dir origin);
2.  ostream &seekp(streamoff offset,seek_dir origin);
streamoff定义于 iostream.h 中，定义有偏移量 offset 所能取得的最大值，seek_dir 表示移动的基准位置，是一个有以下值的枚举：
ios::beg： 文件开头
ios::cur： 文件当前位置
ios::end： 文件结尾
这两个函数一般用于二进制文件，因为文本文件会因为系统对字符的解释而可能与预想的值不同。
例：
1.  file1.seekg(1234,ios::cur);//把文件的读指针从当前位置向后移1234个字节
2.  file2.seekp(1234,ios::beg);//把文件的写指针从文件开头向后移1234个字节
如果vc编程的话最好使用CFile类等更加方便于文件操作.
tip:fseek（）,seekp/g（）中的 unsigned int如果想变成负数，必须先转为int，然后加-，否则会成为一个很大的数
*/