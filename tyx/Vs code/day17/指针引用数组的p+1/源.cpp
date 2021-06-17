#include <stdio.h>
int main()
{
	char a[5];
	char b[6];
	char c[3];
	char* pointer_a, * pointer_b, * pointer_c;
	pointer_a = a;
	pointer_b = b;
	pointer_c = c;
	printf("a[0]的地址是：%d\n", pointer_a);
	pointer_a = pointer_a + 1;
	printf("a[1]的地址是：%d\n", pointer_a);
	//地址的值本质是二进制的，代表着内存中的存储单元中的一个字节，对该值+1，实际上程序会认为对该字节+4，代表着一个integer型数组元素所占用的字节数。
	printf("b[0]的地址是：%d\nc[0]的地址是：%d", pointer_b, pointer_c);
	//结论：在进行内存分配时，会把数组元素个数*d+10，然后判定该值位于哪个区间，例如在12~20之间，就将12个内存二进制单元分配给该数组（具体分配情况有待后续进一步测试
	/*补充：屑书P223的注释：计算机对内存的管理是以“字”为单位的（一般以4个字节为一个“字”）。如果有一个字符变量，理应分配一个字节，但是在一个“字”中存放了一个字符
	后，不会在该“字”中其他3个字节中接着存放下一个变量，而会从下一个“字”开始存放其他数据，因此在用sizeof运算符测量长度时得到的不是理论值63，而是64，必然是4的倍数*/
	return 0;
}