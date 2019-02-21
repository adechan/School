// Find the middle of a given linked list

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

// Get the node in the middle of the list;
int getMiddleNode(nod *&prim)
{
	nod *fast_nod = prim;
	nod *slow_nod = prim;

	if (prim != nullptr)
	{
		while (fast_nod != nullptr && fast_nod->succ != nullptr)
		{
			fast_nod = fast_nod->succ->succ;
			slow_nod = slow_nod->succ;
		}
		return slow_nod->elt;
	}

}

int main()
{
	nod *list = new nod;
	creeaza(list);
	afisare(list);

	std::cout << "Nodul din mijloc contine: " << getMiddleNode(list);
	return 0;
}
