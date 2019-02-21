// Remove duplicates from an unsorted linked list

void removeDuplicates(nod *&prim)
{
	nod *first;
	nod *second;
	nod *duplicate;
	first = prim;

	while (first != NULL && first->succ != NULL)
	{
		second = first;
		while (second->succ != NULL)
		{
			if (first->elt == second->succ->elt)
			{
				duplicate = second->succ;
				second->succ = second->succ->succ;
				delete (duplicate);
			}
			else
				second = second->succ;
		}
		first = first->succ;
	}
}
