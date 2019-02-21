// Delete first element (Single Linked List)

struct nod
{
	int elt;
	nod* succ;
};

nod *prim, *ultim;
nod *p;

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
void afisare(nod *&prim)
{
	nod *p;
	p = prim;
	while (p != nullptr)
	{
		std::cout << p->elt << " ";
		p = p->succ;
	}
	std::cout << std::endl;
}

// Deletes the first element;
void deleteValue(nod *&prim)
{
	nod * p;
	p = prim;
	prim = prim->succ;
	delete p;
}


int main()
{
	nod *lista;
	creeaza(lista);
	afisare(lista);
	deleteValue(lista);
	afisare(lista);
	return 0;
}
