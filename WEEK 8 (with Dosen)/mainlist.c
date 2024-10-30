#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

int main() {
    //kamus
    address A, B, P;
    List1 L;
    //algoritma
    A = (address) malloc(sizeof(Elm));
    B = (address) malloc(sizeof(Elm));
    A->info = 'X'; A->next = B;
    B->info = 'G'; B->next = NULL;
    L.first = A;
    P = L.first;
    while (P != NULL) {
        printf("%c\n", P->info);
        P = P->next;
    }
}