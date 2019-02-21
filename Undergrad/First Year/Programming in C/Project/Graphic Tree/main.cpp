// WinBGI Console Project.cpp : Defines the entry point for the console application.
#include <iostream>
#include <string.h>
#include "graphics.h"
#include "winbgim.h"

#include "parse.h"		// Librarie persoanala pentru a converti un string in simbol
#include "queue.h"		// Librarie personala pentru coada;
#include "stack.h"		// Librarie personala pentru stiva;
#include "tree.h"		// Librarie personala pentru arbori;

// Calculeaza dinstanta dintre doua puncte; 
float distanta(int tailX, int tailY, int headX, int headY)
{
	return abs(sqrt((headX - tailX)*(headX - tailX) + (headY - tailY) * (headY - tailY)));
};

// Initializam graficul pentru a desena arborele;
void initGraphics(int windowWidth, int windowHeight)
{
	
	//int gd = DETECT, gm;
	//initgraph(&gd, &gm, "");
	initwindow(windowWidth, windowHeight);
}

// Desenam un nod; 
void drawNode(int x, int y, int raza, char simbol)
{
	int inaltimeLitera = 10;
	int latimeLitera = 4;

	char text[10];

	// Obtinem reprezentarea textuala a simbolului;
	symbolToText(simbol, text);

	// Desenam un cerc in jurul simbolului pentru a reprezenta nodul;
	circle(x, y, raza);

	// Afisam textul;
	outtextxy(x - latimeLitera * strlen(text), y - inaltimeLitera, text);
}

void drawSyntaxTree(int x, int y, int raza, node* radacina)
{
	// Folosit pentru a face nodurile mai departate unul de celalalt pe verticala
	int inaltimeFactor = 3;

	// Deseneaza nodul curent;
	drawNode(x, y, raza, radacina->simbol);
	Sleep(1000);

	// Amplasati nodurile pe orizontala in functie de cat de inalti suntem din partea de jos a copacului.
	int nodeSpacing = raza * inaltimeArbore(radacina);

	// Deseneaza restul arborelui:

	// Daca doar right nu este null, atunci nodul current este operator unar;
	// in convertPostfixToTree, avem ->right, ->left = nullptr pentru operator unar;
	if (radacina->right && !radacina->left)
	{
		int childY = y + raza * inaltimeFactor;

		// Parametrizarea segmentului de linie intre vectorul nostru curent si vectorul tinta;
		// v1 + (1 - t)v2
		float scale = (((float)raza / distanta(x, y, x, childY)));

		// Deseneaza linia pentru a conecta noduri;
		line(x, y + scale*(childY - y), x, y + (1 - scale)*(childY - y));
		
		// Deseneaza restul arborelui;
		drawSyntaxTree(x, childY, raza, radacina->right);
	}

	// Altfel; 
	// Daca nodurile left si right nu sunt null, atunci nodul current este binar;
	else if (radacina->left && radacina->right)
	{
		// Variabile pentru lizibilitate;
		int leftChildX = x - nodeSpacing;			
		int leftChildY = y + raza * inaltimeFactor;
		int rightChildX = x + nodeSpacing;
		int rightChildY = leftChildY;

		// Linie pentru parametrizare;
		// v1 + (1 - t)v2
		float scale = (((float)raza / distanta(x, y, leftChildX, leftChildY)));
		//float scaleEnd = (1 - ((float)raza / distanta(x, y, leftX, leftY)));

		// Deseneaza linia pentru a conecta noduri;
		line(x + scale*(leftChildX - x), y + scale*(leftChildY - y), x + (1 - scale)*(leftChildX - x), y + (1 - scale)*(leftChildY - y));
		line(x + scale*(rightChildX - x), y + scale*(rightChildY - y), x + (1 - scale)*(rightChildX - x), y + (1 - scale)*(rightChildY - y));

		// Deseneaza ramura stanga a arborelui de dedesubt;
		drawSyntaxTree(x - nodeSpacing, y + raza * inaltimeFactor, raza, radacina->left);

		// Deseneaza ramura dreapta a arborelui de dedesubt;
		drawSyntaxTree(x + nodeSpacing, y + raza * inaltimeFactor, raza, radacina->right);
	}
}

int main()
{
	initGraphics(1000, 500);

	int centerX = getmaxx() / 2;
	int topY = 40;
	char input[256];

	while (1)
	{
		queue infix;
		queue postfix;
		createEmptyQueue(infix, 100);
		createEmptyQueue(postfix, 100);

		std::cout << "Dati o expresie: ";
		std::cin.getline(input, 256);
		cleardevice();

		// Converteste toate string operatori (sin, cos, tg, ctg, log) in simboluri ASCII pe care noi le putem analiza;
		convertOperatorsToSymbols(input);

		// Umple coada infix;
		for (int i = 0; i < strlen(input); i++)
			pushQueue(infix, input[i]);

		// Converteste din infix in postfix;
		convInfix2Postfix(infix, postfix);

		// Converteste coada postfixata intr-un arbore usor de desenat;
		node* tree = convertPostfixToTree(postfix);

		// Deseneaza arborele;
		drawSyntaxTree(centerX, topY, 20, tree);
		freeTree(tree);
		freeQueue(infix);
		freeQueue(postfix);
	}

	// Elibereaza memoria folosita;

	getch();

	closegraph();
	return 0;
}