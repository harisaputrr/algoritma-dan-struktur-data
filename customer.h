#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info

using namespace std;

struct infotype_C {
    string nama, tgl, jk, uname,pword;
};

typedef struct elmlist_C *address_C;

struct elmlist_C {
    infotype_C info;
    address_C next;
    address_C prev;
};

struct List_C {
    address_C first;
    address_C last;
};

void createlist_C(List_C &L);
address_C allocation_C(infotype_C x);
void insertcustomer_C(List_C &L,address_C P);
void insertfirst_C(List_C &L,address_C P);
void insertafter_C(List_C &L,address_C P, address_C Q);
void insertbefore_C(List_C &L,address_C Q, address_C P);
void insertlast_C(List_C &L,address_C P);
void viewall_C(List_C L);
address_C findaccount_C(List_C L,infotype_C x);
address_C findusername_C(List_C L,infotype_C x);
void deletefirst_C(List_C &L, address_C &P);
void deleteafter_C(List_C &L, address_C &P);
void deletelast_C(List_C &L, address_C &P);

#endif // CUSTOMER_H_INCLUDED
