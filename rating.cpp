#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "rating.h"

void createlist_R(List_R &L){
    first(L) = NULL;
}

address_R allocation_R(infotype_R x){
    address_R R = new elmlist_R;
    info(R) = x;
    product(R) = NULL;
    customer(R) = NULL;
    next(R) = NULL;
    return R;
}

void deallocation_R(address_R &P){
    P = NULL;
}

void insertfirst_R(List_R &L, address_R R, address_C C, address_P P){
    if(first(L) == NULL){
        first(L) = R;
        product(R) = P;
        customer(R) = C;
    } else {
        next(R) = first(L);
        first(L) = R;
        product(R) = P;
        customer(R) = C;
    }
}

address_R findrelation_R(List_R L, address_P P,address_C C){
    address_R R;

    if(first(L) != NULL){
        R = first(L);
        while((R != NULL) && (product(R) != P) && (customer(R)!= C)){
            R = next(R);
        }
        if((product(R) == P) && (customer(R)==C)){
            return R;
        }
        else {
            return NULL;
        }
    } else {
        return NULL;
    }
}

void viewrelation_R(List_R L, address_P P){
    address_R R;

    if(first(L) != NULL){
        R = first(L);
        while(R != NULL){
            if(product(R) == P){
                cout << "     " << info(customer(R)).uname << endl;
                cout << "     " << info(R) << endl;
            }
            R = next(R);
        }
    } else {
        cout << "              Tidak ada rating";
    }
}

void viewrelation_RC(List_R L, address_C C){
    address_R P;

    if(first(L) != NULL){
        P = first(L);
        while(P != NULL){
            if(customer(P) == C){
                cout << "     " << info(product(P)).namaprod << endl;
                cout << "     " << info(P) << endl;
            }
            P = next(P);
        }
    } else {
        cout << "              Tidak ada rating";
    }
}

void deleterelation_RP(List_R &L, address_P &P, address_R &R){
    if(first(L) != NULL){
        R = first(L);
        while(R != NULL){
            if(product(R) == P){
                if(R == first(L)){
                    deletefirst_R(L,R);
                } else if(next(R) == NULL && R != first(L)){
                    deletelast_R(L,R);
                } else {
                    deleteafter_R(L,R);
                }
//                R = first(L);
            } else {
                R = next(R);
            }
        }
    }
}

void deleterelation_RC(List_R &L, address_C &C, address_R &R){
    if(first(L) != NULL){
        R = first(L);
        while(R != NULL){
            if(customer(R) == C){
                if(R == first(L)){
                    deletefirst_R(L,R);
                } else if(next(R) == NULL && R != first(L)){
                    deletelast_R(L,R);
                } else {
                    deleteafter_R(L,R);
                }
//                R = first(L);
            } else {
                R = next(R);
            }
        }
    }
}

void deletefirst_R(List_R &L, address_R &P){
    if(next(P) == NULL){
        first(L) = NULL;
    }else{
        first(L) = next(P);
        next(P) = NULL;
    }
}

void deleteafter_R(List_R &L, address_R &P){
    address_R Q;

    Q = first(L);
    while(next(Q) != P){
        Q = next(Q);
    }
    next(Q) = next(P);
    next(P) = NULL;
}

void deletelast_R(List_R &L, address_R &P){
    address_R Q;

    while(next(Q) != P){
        Q = next(Q);
    }
    next(Q) = NULL;
}

float relationavg(List_R L, address_P P){
    int tot, i;
    address_R R;

    if(first(L) != NULL){
        R = first(L);
        tot = 0;
        i = 0;
        while(R != NULL){
            if(product(R) == P){
                i = i + 1;
                tot = tot + info(R);
            }
            R = next(R);
        }
        return tot / i;
    } else {
        return 0;
    }
}
