#pragma once	

struct queue
{
	int maxSize;			// dimensiunea maxima care poate fi folosita;
	int used;				// cate elemente au fost folosite in coada;
	char *data;				// datele cozii;
};

char frontQueue(queue& q);

char backQueue(queue& q);

bool isQueueEmpty(queue& q);

bool isQueueFull(queue& q);

void createEmptyQueue(queue& q, int capacity);

void pushQueue(queue& q, char newElement);

void popQueue(queue& q);

void printQueue(queue& q);

void clearQueue(queue& q);

void freeQueue(queue& q);
