/* Program   : mtqueue.c */
/* Deskripsi : file DRIVER modul Queue karakter */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include "tqueue.c"
/* include tqueue+boolean */

int main() {
    /* kamus main */
    tqueue Q, H; // variabel Q bertipe tQueue
    char e; // variabel e bertipe character

    /* algoritma */
    createQueue(&Q);
    createQueue(&H);
    enqueue(&Q, 'A');
    enqueue(&Q, 'B');
    enqueue(&Q, 'C');
    enqueue(&Q, 'D');
    enqueue(&Q, 'E');
    enqueue(&H, 'E');
    enqueue(&H, 'F');
    enqueue(&H, 'G');
    printf("Queue terpanjang: %d\n", maxlength(Q, H));
    enqueue2(&Q, &H, 'H');
    viewQueue(Q);
    viewQueue(H);
    dequeue2(&Q, &H, &e);
    printf("huruf yang dikeluarkan: %c\n", e);
    viewQueue(Q);
    viewQueue(H);
    //printQueue(Q);
    //viewQueue(Q);
    //dequeue(&Q, &e);
    //printQueue(Q);
    //viewQueue(Q);
    //printf("head = %d\n", head(Q));
    //printf("tail = %d\n", tail(Q));
    //printf("infoHead = %c\n", infoHead(Q));
    //printf("infoTail = %c\n", infoTail(Q));
    //printf("sizeQueue = %d\n", sizeQueue(Q));
    return 0;
}