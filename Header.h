#pragma once
typedef struct account {
	char author[30];
	char name[30];
	int year;
	int pages;
	int price;
	struct account* next;
} books;
void Show(books* g);
void AddBooks(books* a);
void Delete_D(books* a);
void ThreeMax(books* a);
void AlphaSort(books* a);
void swap(books* a, books* b);
books* Reading();
// void swap(books*a, books*b);
// void AlphaSort(books* a);