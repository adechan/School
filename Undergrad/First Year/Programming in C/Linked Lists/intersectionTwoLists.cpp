// Given two lists sorted in increasing order, create and return a new list representing the intersection of the two lists. 
// The new list should be made with its own memory — the original lists should not be changed.

struct nod
{
	int elt;
	nod* succ;
};

void creeaza(nod *& prim)
void afisare(nod * prim)

struct nod* intersectionLists(nod *&lista1, nod *&lista2)
{
	if (lista1 == NULL || lista2 == NULL) 
		return nullptr;
	if (lista1->elt < lista2->elt)
		return intersectionLists(lista1->succ, lista2);

	if (lista1->elt > lista2->elt)
		return intersectionLists(lista1, lista2->succ);

	nod *temp = new nod;
	temp->elt = lista1->elt;
	temp->succ = intersectionLists(lista1->succ, lista2->succ);
	return temp;
}

int main()
{
	nod *list1 = new nod;
	nod *list2 = new nod;
	nod *intersection = new nod;
	creeaza(list1);
	afisare(list1);

	creeaza(list2);
	afisare(list2);

	intersection = intersectionLists(list1, list2);
	std::cout << "elemente comune" << intersection;


	return 0;
}
