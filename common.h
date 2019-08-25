#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>

#include "product.h"
#include "customer.h"
#include "rating.h"

void firstmenu(List_P &P, List_R &R, List_C &C);
void loginmenu(List_P &P, List_R &R, List_C &C);
void adminmenu(List_P &P, List_R &R, List_C &Lc);
void usermenu(List_P &P, List_R &R, List_C &Lc, address_C AdrC);
void guestmenu(List_P P, List_R R, List_C C);

void optlogin(List_P &P, List_R &R, List_C &C);
void optregister(List_P &P, List_R &R, List_C &C);

void insertproduct(List_P &LP);
void updateproduct(List_P &LP);
void deleteproduct(List_P &Lp, List_R &Lr);
void deletecustomer(List_C &Lc, List_R &Lr);
void viewproduct(List_P &LP, List_R &LR,List_C &Lr);
void viewallproduct(List_P LP);
void viewallcustomer(List_C LC);
void viewallrating(List_R LR);
void menurating(List_P &LP, List_R &LR,address_C AdrC);
void insertrating(List_R &Lr,List_P &Lp, address_C AdrC);
void tampillistrelasi(List_R Lr);
void deleterelasi(List_R &Lr, List_P Lp, address_C AdrC);
void viewratinghistory(List_R Lr, address_C AdrC);
void updatecustomer(List_C &Lc, address_C &AdrC);
void viewtopten(List_P Lp);

#endif // COMMON_H_INCLUDED
