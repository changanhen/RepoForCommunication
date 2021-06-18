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
	sqList->length++；
	
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
ListType* CreateList(int length)
{
	ListType* sqList=(ListType*)malloc(sizeof(ListType));
	if (sqList != NULL)
	{
		//为线性表分配内存
		sqList->list = (DataType*)malloc(sizeof(DataType)*length);
		//如果分配失败，返回NULL
		if (sqList->list == NULL)
			return NULL;
		//置为空表
		sqList->length = 0;
		//最大长度
		sqList->maxLength = length;
	}
	return sqList;
}
/**
 *@brief 销毁线性表
 *@param pList 指向需要销毁的线性表的指针
*/
void DestroyList(ListType* pList)  
{
	free(pList->list);
	free(pList);
}
/**
*@brief 置空线性表
*@param pList 指向需要置空线性表的指针
*/
void ClearList(ListType* pList) 
{
	pList->length = 0;
}
/**
*@brief 检测线性表是否为空
*@param pList 指向线性表的指针
*@return 如果线性表为空，返回1；否则返回0
*/
int IsEmptyList(ListType* pList)
{
	return pList->length == 0 ? 1 : 0;
}
/**
*@brief 获取线性表长度
*@param pList 指向线性表的指针
*@return 线性表的长度
*/
int GetListLength(ListType* pList)  
{
	return pList->length;
}
/**
 *@brief 获取线性表中第n个元素
 *@param pList 指向线性表的指针
 *@param n 要获取元素在线性表中的位置
 *@param data 获取成功，取得元素存放与data中
 *@return 获取成功返回1, 失败则返回0
 */
int GetListElement(ListType* pList, 
	int n, DataType* data)
{
	if (n<0 || n>pList->length - 1)
		return 0;
	*data = pList->list[n];
	return 1;
}
/**
 *@brief 从pos起查找data第一次出现的位置
 *@param pList 指向线性表的指针
 *@param pos 查找的起始位置
 *@param data 要查找的元素
  *@return 找到则返回该位置, 未找到，返回-1
  */
int FindElement(ListType* pList, int pos, DataType data)
{
	for (int n = pos; n < pList->length; ++n)
	{
		if (data == pList->list[n])
			return n;
	}
	return -1;
}
/**
*@brief 获取第n个元素的前驱
*@param pList 指向线性表的指针
*@param n n的前驱
*@param data 获取成功，取得元素存放与data中
*@return 找到则返回前驱的位置（n-1）, 未找到，返回-1
*/
int GetPriorElement(ListType* pList, 
	int n , DataType* data)
{
	if (n < 1 || n>pList->length-1)
		return -1;
	*data = pList->list[n - 1];
	return n-1;
}
/**
*@brief 获取第n个元素的后继
*@param pList 指向线性表的指针
*@param n n的后继
*@param data 获取成功，取得元素存放与data中
*@return 找到则返回后继的位置（n+1）, 未找到，返回-1
*/
int GetNextElement(ListType* pList, int n,DataType* data)
{
	if (n<0 || n>pList->length - 2)
		return -1;
	*data = pList->list[n + 1];
	return n+1;
}
/**
*@brief 将 data插入到线性表的 pos位置处
*@param pList 指向线性表的指针
*@param pos 插入的位置
*@param data 要插入的元素存放data中
*@return 成功，返回新的表长（原表长+1）, 失败，返回-1
*/
int InsertToList(ListType* pList, 
	int pos, DataType data)
{
	//如果插入的位置不正确或者线性表已满，则插入失败
	if (pos<0 || pos>pList->length || pList->length == pList->maxLength)
		return -1;
	//从pos起，所有的元素向后移动1位
	for (int n = pList->length; n > pos; --n)
	{
		pList->list[n] = pList->list[n - 1];
	}
	//插入新的元素
	pList->list[pos] = data;
	//表长增加1
	return ++pList->length;
}
/**
*@brief 将pos位置处的元素删除
*@param pList 指向线性表的指针
*@param pos 删除元素的位置
*@return 成功，返回新的表长（原表长-1）, 失败，返回-1
*/
int DeleteFromList(ListType* pList, int pos)
{
	if (pos<0 || pos>pList->length)
		return -1;
	//将pos后的元素向前移动一位
	for (int n = pos; n < pList->length - 1; ++n)
		pList->list[n] = pList->list[n + 1];
	return --pList->length;
}
/**
*@brief 输出线性表
*@param pList 指向线性表的指针
*/
void PrintList(ListType* pList)
{
	for (int n = 0; n < pList->length; ++n)
		printf("第%d项: %d\n", n, pList->list[n]);
}