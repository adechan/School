struct node
{
	int elt;
	node* succ;
};

// 1. Add a node at the front;

void addValueFront(node *&prim)
{
	node *p;
	p = new node;
	p->elt = 9;
	p->succ = prim;
	prim = p;
}

// 2. Add a node after a given node;

void addValue(node *&prev)
{
   node *p;
   if (prev == NULL) return ;
   p = new node;
   p->elt = 9;
   p->succ = prev->succ;
   prev->succ = p;
}
   
// 3. Add a node at the end;

void addValueEnd(node *&prim)
{
	node *p;
	p = new node;
	node *last = prim;
	p->elt = 9;
	p->succ = NULL;
	if (prim == NULL)
	{
		prim = p;
		return;
	}
	else
		while (last->succ != NULL)
			last = last->succ;
	last->succ = p;
	return;
		
}

 
       
