// It searches for a given key. If it can find the key inside of the list returns true, else returns false. 

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

// Searches for a given key;
bool searchValue(nod *&prim, int key)
{
	nod *current = prim;

	while (current != nullptr)
	{
		if (current->elt == key) 
			return true;
		current = current->succ;
	}
	return false;
}

int main()
{
	nod *list = new nod;
	creeaza(list);
	afisare(list);

	searchValue(list, 7) ? std::cout << "Yes" : std::cout << "No";
	std::cout << std::endl;

	return 0;
}
