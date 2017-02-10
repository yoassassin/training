#include<stdio.h>
#include<stdlib.h>


	/*
	%d是按照十进制整数形式输出
	%nd中的n表示有效数字的位数；
	%c是按照字符型输出；
	%f是按照浮点数输出；
	%lf是按照长浮点数输出；
	%o是按照八进制输出；
	%x是按照16进制输出；
	%e是按照科学计数法输出结果
	
	表示输出类型的格式字符 格式字符意义
	d 以十进制形式输出带符号整数(正数不输出符号)
	o 以八进制形式输出无符号整数(不输出前缀O)
	x 以十六进制形式输出无符号整数(不输出前缀OX)
	u 以十进制形式输出无符号整数
	f 以小数形式输出单、双精度实数
	e 以指数形式输出单、双精度实数
	g 以%f%e中较短的输出宽度输出单、双精度实数
	c 输出单个字符
	s 输出字符串 
	void main()
	{
	int a=88,b=89;
	printf("%d %d\n",a,b); //第四行
	printf("%d,%d\n",a,b);
	printf("%c,%c\n",a,b);
	printf("a=%d,b=%d",a,b);
	}
	a<--8,b<--89
	printf("%d %d\n",a,b);
	printf("%d,%d\n",a,b);
	printf("%c,%c\n",a,b);
	printf("a=%d,b=%d",a,b);
　　本例中四次输出了a,b的值，但由于格式控制串不同，输出的结果也不相同。第四行的输出语句格式控制串中，两格式串%d 之间加了一个空格(非格式字符)，所以输出的a,b值之间有一个空格。
    第五行的printf语句格式控制串中加入的是非格式字符逗号， 因此输出的a,b值之间加了一个逗号。第六行的格式串要求按字符型输出 a,b值。第七行中为了提示输出结果又增加了非格式字符串。
	
	*/

void main()
{
	int num = 10;
	//int *numPointer = &num;    
	/*
	chat *p，*指示定义了一个指针。
	*p是p指向的内容（这个*和定义时候的*不同）

	铭记：（P是一个地址(保存的是指针指向的某个地址,如&xxx)。*p是p指向的内容（&xxx地址的空间里的数据，既xxx的值）；ps：&这个是取地址符号，所以 &*p 和 p 相等）
	*/

	int **doublePointer = &num; //*指示定义了一个指针， **代表了一个指针指向了另一个指针，指针的指针。  
	int *anotherPointer;
	anotherPointer = &num; //真正使用指针的时候其实是没*的， 有*的地方代表了指针指向的来源的 地址上的空间数据， 比如&num地址上的num的值为10； 


	printf("%p\n", &num); //地址为0042FDBC，内存中显示0x0042FDBC， 0x代表16进制
	//printf("%x\n", num);//a（既16进制的正数10）既地址里的内容。（后面解释是错的？）  %p 是以16进制的形式输出内存地, %p表示要输出变量的地址。比如printf("%p",a);就表示输出a的地址，
	//printf("%p\n", &numPointer);//0042FDB0（内存中显示：0x0042FDB0） 指针numPointer声明后，占用的地址 
	//printf("%p\n", numPointer);//指针里保存的内容保存的是地址0042FDBC（内存中显示：0x0042FDBC）
	//
	//printf("%x\n", numPointer);//42FDB0 ，16进制显示，0042FDB0去掉前面的2个0）
	//printf("%d\n", numPointer);//一串数字， 42FDB0的十进制形式

	/*以下测试，把指针的内容或者地址改变后，原来的值和地址的改变*/
	int num2 = 20;
	int num3 = 30;
	int *numPointer2 = &num2; //numPointer2是指针，保存在地址着num2的地址信息。 *是取值符号，取出指针保存的地址里的空间中的数据。 *也代表声明了一个指针。
	printf("begin\n");
	printf("%d\n", num2);	//20 原来的内容值
	printf("%p\n", num2);	//相当于把内容值20 转为了16进制的完整形式， 20-->00000014
	printf("%x\n", num2);	//20的16进制， 20-->14
	printf("%p\n", &num2);	//num2的地址
	/*测试改变指针变量里的内容 原来的值会如何*/
	//下行，理论上保存的是指针指向的源 的地址， 既num2的地址
	printf("%p\n", numPointer2); //的确是num2的地址
	//更改内容后,看是否输出是2222
	*numPointer2 = 2222;//*是取值符号，取出指针保存的地址里的空间中的数据。 也就指针指向了num2, 改变的是num2空间里的数据的值。
	printf("%d\n", numPointer2); //还是输出的是numPointer2的原先保存的num2的地址，numPointer2的内容并不是2222.
	printf("%d\n", num2); //num2居然变成了2222

	/*
	//所以*numPointer2 = 2222;的意思：
	 *是取值，取出指针numPointer2指向的那个东西所对应的值， numPointer2指向的就是Num。 *numPointer2并
	 不是取出当前指针的地址里面保存的值（保存的值是num的地址），&numPointer2是取出地址，取出的是指针本身的地址，
	 指针本身也在内存中开辟了空间，有自己的地址，空间里保存了指向的东西的地址
	*/


	////numPointer2 = 22; //Exception thrown: write access violation. 无法直接给地址赋值，无法直接操作寄存器。
	printf("\n\n\n");
	printf("%d\n", numPointer2);
	printf("%p\n", numPointer2);
	printf("%x\n", numPointer2);
	printf("%p\n", &numPointer2);


	printf("\n\n\n");
	*numPointer2 = 22;
	printf("%d\n", num2);
	printf("%p\n", &num2);
	*numPointer2 = &num3;

	printf("%p\n", &num2); //地址为0042FDBC，内存中显示0x0042FDBC， 0x代表16进制
	printf("%x\n", num2);//a（既16进制的正数10）既地址里的内容。
	printf("%p\n", &numPointer2);//0042FDB0（内存中显示：0x0042FDB0） 指针numPointer声明后，占用的地址，是指针本身的地址 
	
	//  %p 是以16进制的形式输出内存地, %p表示要输出变量的地址。比如printf("%p", &a); 就表示输出a的地址
	printf("%p\n", numPointer2);//输出的是指针本身存储的数据，指针里保存的内容num2的地址0042FDBC（内存中显示：0x0042FDBC） 这里的写法类似%x的16进制， 应该不这样使用的，要加&符号
	printf("%x\n", numPointer2);//42FDB0 ，16进制显示，0042FDB0去掉前面的2个0）
	printf("%d\n", numPointer2);//一串数字， 42FDB0的十进制形式
	printf("%d\n", *numPointer2);//错误的写法， *numPointer2并不是取出numPointer2里保存的数据，而是取出指向的Num保存的数据。想得到num的数据，只有printf("%d\n", num)

	numPointer2 = &num;//使指针指向num的地址
	printf("%x\n", numPointer2);//保存了num的地址 为42FDBC 16进制会省略前面的0， 完整形式查看可以用%p看到结果为0042FDBC
	printf("%p\n", &numPointer2);//指针本身的地址是不改变的

	*numPointer2 = &num;//使指针指向num的地址，同时num地址的空间内容就是它本身。 等于是废话：指针指向的地址 所保存的信息 就是它自己

	/**测试Char/String类型的的指针**/

	printf("\n test pointer of CHAR type..\n");

	char a = 'a'; //若是有  error MSB6006: link.exe  ， 关闭VS2013相关联的conhost.exe
	char *p = &a;

	*p = 'b'; //改变 char a的值为b 

	//printf("检查地址是否相同。");
	printf("%c\n", a); //a的值变为b了


	printf("\n test pointer of String type..\n");

	char b[] = "acsd";
	printf("%s", b);    //string写法

	char c[] = { '1','2','3','4' };
	printf("%s", c);

	//char str[5] = "abcde"; //若是有  error MSB6006: link.exe  ， 关闭VS2013相关联的conhost.exe
	//char (*p)[5] = str;

	//*p = "edcba";
	//
	////printf("检查地址是否相同。");
	//printf("%s\n", str);


	system("pause");
}