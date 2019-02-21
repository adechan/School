// Write a GetNth() function that takes a linked list and an integer index 
// and returns the data value stored in the node at that index position.

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

// Get the nth node;
int getNthNode(nod *&prim, int index)
{
	nod *current = prim;
	int count = 0;
	while (current != nullptr)
	{
		if (count == index)
			return (current->elt);
		count++;
		current = current->succ;
	}

}

int main()
{
	nod *list = new nod;
	creeaza(list);
	afisare(list);

	std::cout << "Elementul la index 3 este" << getNthNode(list, 3);

	return 0;
}
