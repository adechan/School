
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

nod * ultimulNod(nod *list)
{
	nod *p = list;

	// Find the end of the list;
	while (p != nullptr)
	{
		if (p->succ == nullptr)
			break;

		p = p->succ;
	}

	return p;
}

// Add a value at the end of list;
void adaugaElementLaFinal(nod * list)
{
	nod* p = ultimulNod(list);
	// Adds a new node;
	p->succ = new nod;
	p->succ->elt = -1;
	p->succ->succ = nullptr;
}

int main()
{
	nod *list = new nod;
	creeaza(list);
	afisare(list);

	adaugaElementLaFinal(list);
	afisare(list);
	return 0;
}
