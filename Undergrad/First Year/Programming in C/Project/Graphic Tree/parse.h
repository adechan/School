#pragma once

#include "queue.h"

void symbolToText(char symbol, char* outputText);

void convertOperatorsToSymbols(char* expression);

void convInfix2Postfix(queue& infix, queue& postfix);

bool isOperator(char oper);

bool isOperand(char operand);

unsigned int aritateOperator(char op);



