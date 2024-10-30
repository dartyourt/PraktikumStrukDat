/* Program   : mtqueue3.c */
/* Deskripsi : file DRIVER modul Queue karakter */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include "tqueue3.c"

int main(){
    tqueue3 Q,J;
    char e;
    createQueue3(&Q);
    createQueue3(&J);
    enqueue3(&Q, 'A');
    enqueue3(&Q, 'B');
    enqueue3(&Q, 'C');
    enqueue3(&Q, 'D');
    enqueue3(&Q, 'E');
    printQueue3(Q);
    dequeue3(&Q, &e);
    printf("yang dikeluarkan: %c\n", e);
    printQueue3(Q);
    dequeue3(&Q, &e);
    printf("yang dikeluarkan: %c\n", e);
    printQueue3(Q);
    printf("head = %d\n", head3(Q));
    printf("tail = %d\n", tail3(Q));
    printf("infoHead = %c\n", infoHead3(Q));
    printf("infoTail = %c\n", infoTail3(Q));
    printf("sizeQueue = %d\n", sizeQueue3(Q));
    enqueue3(&Q, 'A');
    printQueue3(Q);
    dequeue3(&Q, &e);
    printf("yang dikeluarkan: %c\n", e);
    printQueue3(Q);
    enqueue3(&J, 'A');
    enqueue3(&J, 'B');
    enqueue3E(&J,'C');
    printQueue3(J);
    return 0;
}