#ifndef RATING_H_INCLUDED
#define RATING_H_INCLUDED

#include "customer.h"
#include "product.h"

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define product(P) P->product
#define customer(P) P->customer

using namespace std;

typedef int infotype_R;
typedef struct elmlist_R *address_R;

struct elmlist_R {
    infotype_R info;
    address_R next;
    address_P product;
    address_C customer;
};

struct List_R {
    address_R first;
};

void createlist_R(List_R &L);
address_R allocation_R(infotype_R x);
void deallocation_R(address_R &P);
void insertfirst_R(List_R &L, address_R R, address_C C, address_P P);
void viewrelation_R(List_R L, address_P P);
void viewrelation_RC(List_R L, address_C C);
address_R findrelation_R(List_R L, address_P P, address_C C);
void deleterelation_RP(List_R &L, address_P &P, address_R &R);
void deleterelation_RC(List_R &L, address_C &C, address_R &R);
void deletefirst_R(List_R &L, address_R &P);
void deleteafter_R(List_R &L, address_R &P);
void deletelast_R(List_R &L, address_R &P);
float relationavg(List_R L, address_P P);

#endif // RATING_H_INCLUDED
