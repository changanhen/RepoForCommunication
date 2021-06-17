#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct Student)
struct Student
{
	int num;
	float score;
	struct Student* next;
};
int n;
struct Student* create()
{
	struct Student* p1, * p2, * head;
	n = 0;
	p1 = p2 = (struct Student*)malloc(LEN);
	scanf_s("%ld,%f", &p1->num, &p1->score);
	head = p1;
	while (p1->num)
	{
		p1 = (struct Student*)malloc(LEN);
		scanf_s("%ld,%f", &p1->num, &p1->score);
		p2->next = p1;
		p2 = p1;
	}
	p2->next = NULL;
	return(head);
}
int scan(struct Student* ptr)
{
	while (ptr->next != NULL)
	{
		printf("\nnum:%ld\nscore:%5.1f", ptr->num, ptr->score);
		ptr = ptr->next;
	}
	return 0;
}
int felloc(struct Student* ptr)
{
	struct Student* ptr_tmp;
	while (ptr->next != NULL)
	{
		ptr_tmp = ptr->next;
		free(ptr);
		ptr = ptr_tmp;
	}
	free(ptr);
	return 0;
}
int main()
{
	struct Student* ptr;	
	ptr = create();
	scan(ptr);
	felloc(ptr);
}