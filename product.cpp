#include <iostream>
#include "product.h"

void createlist_P(List_P &L){
    first(L) = NULL;
    last(L) = NULL;
}

address_P allocation_P(infotype_P x){
    address_P P = new elmlist_P;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertlast_P(List_P &L, address_P P){
    if((first(L) == NULL) && (last(L) == NULL)){
        first(L) = P;
        last(L) = P;
        next(last(L)) = first(L);
        prev(first(L)) = last(L);
    }else{
        next(last(L))=P;
        prev(P)=last(L);
        next(P)=first(L);
        prev(first(L))=P;
        last(L)=P;
    }
}

address_P findproduct_P(List_P L, string x){
    address_P P;

    if(first(L) != NULL){
        P = first(L);
        while((info(P).namaprod != x) && (P != last(L))){
            P = next(P);
        }
        if(info(P).namaprod == x){
            return P;
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}

void viewall_P(List_P L){
    address_P P;
    address_P Q;

    if(first(L) != NULL){
        P = first(L);
        while(P != Q){
            cout << "     Nama Produk   : " << info(P).namaprod << endl;
            cout << "     Deskripsi     : " << info(P).deskprod << endl;
            cout << "     Jumlah Barang : " << info(P).jumprod << endl;
            cout << "     Harga         : " << info(P).harga << endl;
            cout << "     Rata - rata   : " << info(P).avgprod << endl << endl;
            P = next(P);
            Q = first(L);
        }
    }else{
        cout << "     Maaf data yang anda cari tidak ada" << endl;
        cout << "             Silahkan coba lagi";
    }

}

void deletefirst_P(List_P &L, address_P &P){
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

void deleteafter_P(List_P &L,  address_P &P){
    address_P Q;

    Q = prev(P);
    next(Q) = next(P);
    prev(next(P)) = Q;

}

void deletelast_P(List_P &L, address_P &P){
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
