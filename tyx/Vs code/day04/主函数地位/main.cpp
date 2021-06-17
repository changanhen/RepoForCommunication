#include <stdio.h>

int count;
extern void write_extern();

int main()
{
	count = 5;
	write_extern();
}
/*程序运行时只会运行主函数，所以必须把其它函数添入才能完整运行*/