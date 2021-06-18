#include <stdio.h>
#include <stdlib.h>

/*本例设计一个元素类型为整数的线性表
 *通用起见，此处将整数重定义为DataType
 */
typedef int DataType;

//定义线性表的结构
typedef struct LIST
{
	DataType* list;    //指向线性表的指针
	int length;   //表长
	int maxLength;     //表容量
}ListType;

//声明线性表具有的方法
ListType* CreateList(int length);     //创建一个长度为length的线性表
void DestroyList(ListType* pList);     //销毁线性表
void ClearList(ListType* pList);      //置空线性表
int IsEmptyList(ListType* pList);     //检测线性表是否为空
int GetListLength(ListType* pList);   //获取线性表长度
int GetListElement(ListType* pList, 
	int n, DataType* data);   //获取线性表中第n个元素
int FindElement(ListType* pList, 
	int pos, DataType data);      //从pos起查找data 第一次出现的位置
int GetPriorElement(ListType* pList, 
	int n, DataType* data);   //获取第n个元素的前驱
int GetNextElement(ListType* pList, int n, DataType* data);     //获取第n个元素的后继
int InsertToList(ListType* pList, int pos, DataType data);  //将 data插入到 pos 处
int DeleteFromList(ListType* pList, int pos);             //删除线性表上位置为pos 的元素
void PrintList(ListType* pList);          //输出线性表

/* 主函数，创建一个线性表，并测试*/
int main()
{
	const int MAXLENGTH = 1000;   //假设最大容量为1000
	//创建线性表
	ListType* sqList = CreateList(MAXLENGTH);
	//以下是对线形表的测试
	sqList->list[0] = 9;
	sqList->length++;
	
	ClearList(sqList);         //置表为空
	//插入10个元素并显示
	for (int i = 0; i < 10; ++i)
		InsertToList(sqList, i, i + 1);
	//输出线性表
	PrintList(sqList);
	//在位置5插入99并显示
	InsertToList(sqList, 5, 99);
	printf("插入99后的线性表\n");
	PrintList(sqList);
	//删除第8个元素
	DeleteFromList(sqList, 8);
	printf("删除第8个元素后的线性表\n");
	PrintList(sqList);
	//显示第3个元素的前驱
	DataType data;
	if (GetPriorElement(sqList, 3, &data) > -1)
		printf("第3个元素的前驱是%d\n", data);
	
	DataType x;
	int success=GetListElement(sqlist, 2, &x);
	return 0;
}
//线性表方法实现
/**
 *@brief 创建一个新的线性表
 *@param length 线性表的最大容量
 *@return 成功返回直线该表的指针，否则返回NULL
*/
