#include "common.h"

using namespace std;

int main()
{
    List_P Lp;
    List_R Lr;
    List_C Lc;
    createlist_P(Lp);
    createlist_R(Lr);
    createlist_C(Lc);
    firstmenu(Lp, Lr, Lc);
    return 0;
}
