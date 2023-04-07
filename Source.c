#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Header.h"
static books* book = NULL;

int main(void) {
	int i = 0;
	books* book = Reading();
	if (book == NULL) { exit(1); }
	printf("Original list\n");
	Show(book);
	printf("Alphabetically sorted list\n");
	AlphaSort(book);
	Show(book);
	printf("List of the most expensive Books\n");
	ThreeMax(book);
	printf("List without Books name of whose title begins from letter \"D\"\n");
	Delete_D(book);
	Show(book);
	AddBooks(book);
}

//George Orwell, 1984, 1949, 328, 120
//Mary Shelley, Frankenstein, 1818, 280, 95
//Scott Fitzgerald, The Great Gatsby, 1925, 208, 229
//Agatha Christie, Death on the Nile, 1937, 288, 175
//Aldous Huxley, Brave New World, 1932, 311, 332
//Bram Stoker, Dracula, 1897, 418, 550
//Donna Tartt, The secret history, 1992, 544, 570
