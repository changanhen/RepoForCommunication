#include <stdio.h>
struct Student
{
	int num;
	float score;
	struct Student* next;
};
struct Student* invert(struct Student* head)
{
	struct Student* p, * q, * r;
	p = head;
	q = p->next;
	p->next = NULL;
	while (q)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	return p;
}