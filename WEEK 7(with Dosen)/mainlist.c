#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

int main() {
    //kamus
    address A, B, P;
    List1 L;
    //algoritma
    A = Alokasi(A);
    B = Alokasi(B);
    next(A) = B;
    First(L) = A;
    P = First(L);
    while (P != NIL) {
        printf("%c\n", info(P));
        P = next(P);
    }
}