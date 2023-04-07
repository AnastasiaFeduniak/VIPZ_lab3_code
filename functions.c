#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Header.h"

//------------------------------------------------------------------------------

//Print one linked list

void Show(books* g) {
    if (sizeof(g) != sizeof(books*)) { return; }
    if (g == NULL) { return; }
    printf("----------------------------------------------------------------------------------\n");
    printf("|         Author                |         Title         |  Year  | Pages | Price | \n");
    printf("----------------------------------------------------------------------------------\n");
    do {
        printf("|\t%20s\t|%20s\t| %d\t | %d\t |  %d\t |\n", g->author, g->name, g->year, g->pages, g->price);
        g = g->next;
    } while (g != NULL);
    printf("----------------------------------------------------------------------------------\n");
}

//------------------------------------------------------------------------------

//Swaps two members of the list

void swap(books* a, books* b) {
    if (sizeof(a) != sizeof(books*) || sizeof(b) != sizeof(books*)) { return; }
    if (a == NULL || b == NULL) { return; }
    int tmp = a->year;
    a->year = b->year;
    b->year = tmp;
    tmp = a->pages;
    a->pages = b->pages;
    b->pages = tmp;
    tmp = a->price;
    a->price = b->price;
    b->price = tmp;
    char ctmp[30];
    strcpy(ctmp, a->author);
    strcpy(a->author, b->author);
    strcpy(b->author, ctmp);
    strcpy(ctmp, a->name);
    strcpy(a->name, b->name);
    strcpy(b->name, ctmp);
}

//------------------------------------------------------------------------------

//sorts list in alphabetical order by field "name"

void AlphaSort(books* a) {
    if (sizeof(a) != sizeof(books*)) { return; }
    if (a == NULL) { return; }
    books* pointer = a;
    books* pointer_a = a;
    books* pointer_b = a;
    do {
        pointer_b = a;
        while(pointer_b) {
            if (strcmp(pointer_a->name, pointer_b->name) < 0) {
                swap(pointer_a, pointer_b);
            }
            pointer_b = pointer_b->next;
        } 
        pointer_a = pointer_a->next;
    } while (pointer_a);
}

//------------------------------------------------------------------------------

//Shows three members of the list field "price" which has the biggest value

void ThreeMax(books* a) {
    if (sizeof(a) != sizeof(books*)) { return; }
    if (a == NULL) { return; }
    books* rem = a;
    int n = 0;
    do
    {
        n++;
        rem = rem->next;
    } while (rem != NULL);
    if (n <= 3) { return; }
    books* rem1 = NULL;
    books* max;
    int ch = 0;
    int f = 100000;
    books* tmp[3] = {NULL, NULL, NULL};
    printf("----------------------------------------------------------------------------------\n");
    printf("|         Author                |         Title         |  Year  | Pages | Price | \n");
    printf("----------------------------------------------------------------------------------\n");
    while (ch != 3) {
        rem = a;
        max = a;
        rem1 = a;
        books* localMax = a;
        do {
            if (max->price < rem->price && rem->price < f) {
                max = rem;
                rem1 = rem;
            }
            rem = rem->next;
        } while (rem);
        f = max->price;

        printf("|\t%20s\t|%20s\t| %d\t | %d\t |  %d\t |\n", rem1->author, rem1->name, rem1->year, rem1->pages, rem1->price);
        ch++;
    }
    printf("----------------------------------------------------------------------------------\n");

}

//------------------------------------------------------------------------------

//Removes all the members of a list field "name" of whose begins from 'D' or 'd' element

void Delete_D(books* a) {
    if(sizeof(a) != sizeof(books*)){return;}
    if (a == NULL) { return; }
    books* previous = NULL;
    books* current = a;
    while (current) {
        if (current->name[0] == 'D') {
            previous->next = current->next;
            free(current);
            current = previous;
        }
        previous = current;
        current = current->next;
    }
}


//------------------------------------------------------------------------------

//Create new member of a list and put it in alphabetic position by "name" field

void AddBooks(books* a) {
		if (a == NULL) { return; }
        int check;
        printf("Enter \"0\" if you want to add new book to the list, in other case any other number: \n");
        scanf(" %d", &check);
        while (check == 0) {
            books* tmp = (books*)malloc(sizeof(books));
            printf("Enter the name of author: ");
            getchar();
          //  gets_s(tmp->author, 29);
            fgets(tmp->author, 29, stdin);
            printf("\nEnter the name of a book: ");
          //  gets_s(tmp->name, 29);
            fgets(tmp->name, 29, stdin);
            printf("\nEnter a year of publication: ");
            scanf("%d", &tmp->year);
            printf("\nEnter a number of pages: ");
            scanf("%d", &tmp->pages);
            printf("\nEnter a price: ");
            scanf("%d", &tmp->price);
            books* ch = a, * prev = a;
            while (ch) {
                if (strcmp(tmp->name, ch->name) > 0) {
                   // printf("\nvjndk\n");
                    tmp->next = ch->next;
                    prev->next = tmp;
                    break;
                }
                books* prev = ch;
                ch = ch->next;
            }
            printf("Enter \"0\" if you want to add new book to the list, in other case any other number: ");
            scanf(" %d", &check);
        }
        Show(a);
    }


//------------------------------------------------------------------------------

// Create one linked list of structs "Books" read from file. Returns pointer on the beginning of the list

books* Reading(int* i) {
    FILE* fp;
    books* b = NULL;
    fp = fopen("List.txt", "r");
    if (fp == NULL) {
        printf("dorime\n"); return NULL;
    }
    else {
        books* cur = NULL;
        char ch[200];
        char* h;
        char lim[] = ",";
        while (fgets(ch, 200, fp)) {
            books* new = (books*)malloc(sizeof(books));
            strcpy(new->author, strtok(ch, lim));
            strcpy(new->name, strtok(NULL, lim));
            int l = 0;
            while (h = strtok(NULL, lim))
            {
                if (l == 0) new->year = atoi(h);
                if (l == 1) new->pages = atoi(h);
                if (l == 2) new->price = atoi(h);
                l++;
            }
            *i++;
            if (!b) {
                b = new;
            }
            else {
                cur->next = new;
            }
            new->next = NULL;
            cur = new;
        }
    }
    fclose(fp);
    return b;
}