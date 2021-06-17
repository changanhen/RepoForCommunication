struct struct_name* invert(struct struct_name* head)
{
	struct struct_name* p, * q, * r;
	p = head;
	q = p->next;
	p->next = NULL;
	while (q != NULL)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	return p;
}