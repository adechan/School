// Reverse a list;

void reverseList(nod *&prim)
{
	nod * prev = NULL;
	nod * current = prim;
	nod * next;

	while (current != NULL)
	{
		next = current->succ;
		current->succ = prev;
		prev = current;
		current = next;
	}
	prim = prev;
}
