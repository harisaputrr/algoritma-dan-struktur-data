#include <iostream>
#include <conio.h>
#include "customer.h"

void createlist_C(List_C &L){
    first(L) = NULL;
    last(L) = NULL;
}

address_C allocation_C(infotype_C x){
    address_C P = new elmlist_C;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertcustomer_C(List_C &L, address_C C){
    address_C P;

    if(first(L) != NULL){
        P = first(L);
        if(first(L) == last(L)){
            if(info(C).uname > info(P).uname){
                insertlast_C(L,C);
            } else if(info(C).uname < info(P).uname) {
                insertfirst_C(L,C);
            }
        } else {
            while((info(P).uname < info(C).uname) && (P != last(L))){
                P = next(P);
            }
            if(P == first(L)){
                insertfirst_C(L,C);
            } else if((P == last(L)) && ((info(P).uname < info(C).uname))){
                insertlast_C(L,C);
            } else if(info(P).uname > info(C).uname){
                insertbefore_C(L,P,C);
            }
        }
    } else {
        insertfirst_C(L,C);
    }
}


void insertfirst_C(List_C &L, address_C P){
    if((first(L) == NULL) && (last(L) == NULL)) {
        first(L) = P;
        last(L) = P;
        next(last(L)) = first(L);
        prev(first(L)) = last(L);
    } else {
        prev(first(L)) = P;
        next(P) = first(L);
        first(L) = P;
        next(last(L)) = first(L);
        prev(first(L)) = last(L);
    }
}

void insertbefore_C(List_C &L, address_C Q, address_C P){
    prev(P) = prev(Q);
    next(P) = Q;
    prev(Q) = P;
    next(prev(P)) = P;
}

void insertlast_C(List_C &L, address_C P){
    if((first(L) == NULL) && (last(L) == NULL)){
        first(L) = P;
        last(L) = P;
        next(last(L)) = first(L);
        prev(first(L)) = last(L);
    }else{
        next(last(L)) = P;
        prev(P) = last(L);
        next(P) = first(L);
        prev(first(L)) = P;
        last(L) = P;
    }
}

address_C findaccount_C(List_C L, infotype_C x){
    address_C P;

    if(first(L) != NULL){
        P = first(L);
        if(first(L) == last(L)){
            if((info(P).uname == x.uname) && (info(P).pword == x.pword)){
                return P;
            } else {
                return NULL;
            }
        } else {
            while((info(P).uname != x.uname) && (P != last(L))){
                P = next(P);
            }
            if((info(P).uname == x.uname) && (info(P).pword == x.pword)){
                return P;
            } else {
                return NULL;
            }
        }
    } else {
        return NULL;
    }
}

address_C findusername_C(List_C L, infotype_C x){
    address_C P;

    if(first(L) != NULL){
        P = first(L);
        while((info(P).uname != x.uname) && (P != last(L))){
            P = next(P);
        }
        if(info(P).uname == x.uname){
            return P;
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}

void viewall_C(List_C L){
    address_C P = first(L);
    address_C Q;

    if(first(L) != NULL) {
        while(P != Q){
            cout << "     Nama Pengguna   : " << info(P).nama << endl;
            cout << "     Tanggal Lahir   : " << info(P).tgl << endl;
            cout << "     Jenis Kelamin   : " << info(P).jk << endl;
            cout << "     Username        : " << info(P).uname << endl;
            cout << "     Password        : " << info(P).pword << endl << endl;
            P = next(P);
            Q = first(L);
        }
    } else {
        cout << "     Maaf data yang anda cari tidak ada" << endl;
        cout << "             Silahkan coba lagi";
    }

}

void deletefirst_C(List_C &L, address_C &P){
    if(first(L) != NULL){
        P = first(L);
        if (first(L) == last(L)){
            first(L) = NULL;
            last(L) = NULL;
        }else{
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);
            first(L) = next(P);
            next(P) = NULL;
            prev(P) = NULL;
        }
    }
}

void deleteafter_C(List_C &L,  address_C &P){
    address_C Q;

    Q = prev(P);
    next(Q) = next(P);
    prev(next(P)) = Q;

}

void deletelast_C(List_C &L, address_C &P){
    if (first(L) != NULL){
        P = last(L);
        if (first(L) == last(L)){
            first(L) = NULL;
            last(L) = NULL;
        }else{
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);
            last(L) = prev(P);
            next(P) = NULL;
            prev(P) = NULL;
        }
    }
}
