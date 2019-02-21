// Given a liked list and a key to be deleted. Delete last occurrence of key from linked.

struct nod
{
	int elt;
	nod* succ;
};

// Create a list;
void creeaza(nod *& prim)
{
	nod *ultim;
	nod *p, *q;
	int i, n, x;
	prim = nullptr;
	std::cout << "Dati numarul de elemente ";
	std::cin >> n;
	std::cout << "Primul element = ";
	std::cin >> x;
	
	prim = new nod;
	prim->elt = x;
	ultim = prim;

	for (i = 2; i <= n; i++)
	{
		std::cout << "Elementul al " << i << " - lea ";
		std::cin >> x;
		p = new nod;
		p->elt = x;
		p->succ = nullptr;
		ultim->succ = p;
		ultim = p;
	}
}

// Display a list;
void afisare(nod * prim)
{
	nod * p = prim;
	while (p != nullptr)
	{
		std::cout << p->elt << " ";
		p = p->succ;
	}

	std::cout << std::endl;
}


// Delete the key; IT DOESN'T WORK IF KEY IS AT THE END OF THE LIST.
void deleteKey(nod *&prim, int key)
{
	nod *p = NULL;
	nod *temp = prim;
	while (temp)
	{
		if (temp->elt == key)
			p = temp;
		temp = temp->succ;
	}
	if (p != NULL)
	{
		p->elt = p->succ->elt;
		temp = p->succ;
		p->succ = p->succ->succ;
		delete (temp);
	}

}
// Delete the key; IT DOES WORK IF KEY IS AT THE END OF THE LIST;
void deleteValue(nod *&prim, int key)
{
	nod *p = NULL;
	nod *temp = prim;
	while (temp)
	{
		if (temp->succ && temp->succ->elt == key)
			p = temp;
		temp = temp->succ;
	}
	if (p)
	{
		temp = p->succ;
		p->succ = p->succ->succ;
		delete(temp);
	}
	else
	{
		if (prim && prim->elt == key)
		{
			nod *temp = prim;
			prim = prim->succ;
			delete temp;
		}
	}

}

int main()
{
	nod *list = new nod;
	creeaza(list);
	afisare(list);

	deleteKey(list, 4);
	afisare(list);
	return 0;
}
