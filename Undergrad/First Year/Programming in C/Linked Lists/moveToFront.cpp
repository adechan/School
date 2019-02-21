// Move last element to front of a given Linked List

void moveToFront(nod *&prim)
{
	if (prim == NULL || prim->succ == NULL) return;

	nod *secondLast = NULL;
	nod *last = prim;

	while (last->succ != NULL)
	{
		secondLast = last;
		last = last->succ;
	}
	secondLast->succ = NULL;
	last->succ = prim;
	prim = last;
}
