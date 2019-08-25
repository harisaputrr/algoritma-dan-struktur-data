#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info

using namespace std;

struct infotype_P {
    string namaprod ,deskprod;
    int harga, jumprod;
    float avgprod;
};

typedef struct elmlist_P *address_P;

struct elmlist_P {
    infotype_P info;
    address_P next;
    address_P prev;
};

struct List_P {
    address_P first;
    address_P last;
};

void createlist_P(List_P &L);
address_P allocation_P(infotype_P x);
void insertlast_P(List_P &L,address_P P);
address_P findproduct_P(List_P L, string x);
void viewall_P(List_P L);
void deletelast_P(List_P &L, address_P &P);
void deleteafter_P(List_P &L, address_P &P);
void deletefirst_P(List_P &L, address_P &P);
#endif // PRODUCT_H_INCLUDED
