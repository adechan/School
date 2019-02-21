// Swap nodes in a linked list without swapping data;

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

// Swap Nodes;
void swapNodes(nod *&prim, int info1, int info2)
{
	if (info1 == info2) return;

	nod *prevInfo1 = NULL;
	nod *currInfo1 = prim;
	while (currInfo1 && currInfo1->elt != info1)
	{
		prevInfo1 = currInfo1;
		currInfo1 = currInfo1->succ;
	}

	nod *prevInfo2 = NULL;
	nod *currInfo2 = prim;
	while (currInfo2 && currInfo2->elt != info2)
	{
		prevInfo2 = currInfo2;
		currInfo2 = currInfo2->succ;
	}

	if (prevInfo1 == NULL || currInfo2 == NULL) return;

	if (prevInfo1 != NULL)
		prevInfo1->succ = currInfo2;
	else
		prim = currInfo2;

	if (prevInfo2 != NULL)
		prevInfo2->succ = currInfo1;
	else 
		prim = currInfo1;

	nod * temp = currInfo2->succ;
	currInfo2->succ = currInfo1->succ;
	currInfo1->succ = temp;

}

int main()
{
	nod *list = new nod;
	creeaza(list);
	afisare(list);

	swapNodes(list, 1, 8);
	afisare(list);

	return 0;
}
