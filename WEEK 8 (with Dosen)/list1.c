#include "list1.h"

/*Function Alokasi(E:infotype) -> address*/
/*{mengembalikan alamat elemen E bila berhasil, NIL bila gagal}*/
address Alokasi(infotype E){
    //kamus lokal
    address P;
    //algoritma
    P = (address) malloc(sizeof(Elm));
    if (P != NULL) {
        P->info = E;
        P->next = NULL;
    }
    return P;
}
