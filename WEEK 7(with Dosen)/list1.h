#ifndef LIST1_H
#define LIST1_H

#include <stdio.h>
#include <stdlib.h>

#define NIL NULL
#define First(L) (L).first
#define info(P) (P)->info
#define next(P)  (P)->next


/*type infotype = character  */
typedef char infotype;

/*type address = pointer to Elm */
typedef struct tagElm *address;

/*type Elm = <info: infotype, next: address>*/
typedef struct tagElm {
    infotype info;
    address next;
} Elm;

/*type List1 = <first: address>*/
typedef struct {
    address first;
} List1;

/*Function Alokasi(E:infotype) -> address*/
/*{mengembalikan alamat elemen E bila berhasil, NIL bila gagal}*/
address Alokasi(infotype E);

#endif