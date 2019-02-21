struct nod
{
	int elt;
	nod* succ;
};

// 1. Delete the first node;

void deleteFirst(nod *&prim)
{
	nod *p;
	p = prim;
	prim = prim->succ;
	delete p;
		
}

// 2. Delete a given node; 

void deleteValue(nod *&prim, int position)
{
	nod *p;
	p = new nod;
	if (prim == NULL) return;
	nod *temp = prim;
	if (position == 0)
	{
		prim = temp->succ;
		delete(temp);
		return;
	}
	for (int i = 1; temp != NULL && i < position - 1; i++)
		temp = temp->succ;
	if (temp == NULL || temp->succ == NULL)
		return;

	nod *succ = temp->succ->succ;
	delete(temp->succ);
	temp->succ = succ;

}

// 3. Delete the last node;

void deleteLast(nod *&prim)
{
	nod *p;
	nod *temp = prim;
	while (temp->succ != NULL)
	{
		p = temp;
		temp = temp->succ;
	}
	delete(p->succ);
	p->succ = NULL;

}
