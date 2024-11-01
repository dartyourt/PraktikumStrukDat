/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : */
/* Tanggal : Oktober 2024 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.c"
int main()
{ //kamus
  address A; 
  address B;
  address P;
  List1 Senarai;
  //algoritma
  
  /*aplikasi tipe address
  A = (address) malloc ( sizeof (Elm) ); // Alokasi('G')
  A->info = 'G';   A->next = NIL;
  printf("info(A)=%c\t", A->info );
  B = (address) malloc ( sizeof (Elm) ); // Alokasi('N')
  B->info = 'N';   B->next = A;
  printf("info(B)=%c\n", B->info );
  
  //aplikasi tipe List1
  Senarai.First = B; //First(Senarai) = B;
  printf("Isi Senarai :");
  P = First(Senarai);
  while (P != NIL) {
	  printf("\t%c",info(P));
	  P = next(P);
  }
  //PrintList( Senarai );8*/

  CreateList(&Senarai);
  InsertVFirst(&Senarai,'G');
  InsertVLast(&Senarai,'N');
  PrintList(Senarai);
  DeleteVLast(&Senarai,&P);
  printf("Elemen terakhir yang dihapus : %c\n",P);
  PrintList(Senarai);
  InsertVFirst(&Senarai,'A');
  InsertVLast(&Senarai,'Z');
  InsertVLast(&Senarai,'J');
  InsertVFirst(&Senarai,'X');
  PrintList(Senarai);
  Invers(&Senarai);
  PrintList(Senarai);
  prinrf("Jumlah elemen : %d\n",NbElm(Senarai));
  return 0;
}
