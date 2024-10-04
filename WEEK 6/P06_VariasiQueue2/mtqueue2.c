/* Program   : mtqueue.c */
/* Deskripsi : file DRIVER modul Queue karakter */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include "tqueue2.c"

int main(){
    tqueue2 Q,J;
    char e;
    createQueue2(&Q);
    createQueue2(&J);
    enqueue2(&Q, 'A');
    enqueue2(&Q, 'B');
    enqueue2(&Q, 'C');
    enqueue2(&Q, 'D');
    enqueue2(&Q, 'E');
    printQueue2(Q);
    dequeue2(&Q, &e);
    printf("yang dikeluarkan: %c\n", e);
    printQueue2(Q);
    dequeue2(&Q, &e);
    printf("yang dikeluarkan: %c\n", e);
    printQueue2(Q);
    printf("head = %d\n", head2(Q));
    printf("tail = %d\n", tail2(Q));
    printf("infoHead = %c\n", infoHead2(Q));
    printf("infoTail = %c\n", infoTail2(Q));
    printf("sizeQueue = %d\n", sizeQueue2(Q));
    enqueue2(&Q, 'A');
    printQueue2(Q);
    dequeue2(&Q, &e);
    printf("yang dikeluarkan: %c\n", e);
    printQueue2(Q);
    enqueue2N(&Q, 2);
    printQueue2(Q);
    enqueue2N(&J, 5);
    printf("Queue tersebut: %s\n", isEqualQueue2(Q,J) ? "sama" : "tidak sama");
    return 0;
}