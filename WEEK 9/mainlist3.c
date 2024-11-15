/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait ganda, representasi fisik pointer */
/* NIM & Nama : */
/* Tanggal : Oktober 2024 */
#include "list3.c"
int main()
{ //kamus
  address A; 
  address B;
  address P;
  infotype D;
  List3 Senarai/*, Seranai, Senam, Sese, Nana, Rai*/;
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
  //CreateList(&Seranai);
  InsertVFirst(&Senarai,'G');
  InsertVLast(&Senarai,'N');
  InsertVFirst(&Senarai,'A');
  InsertVLast(&Senarai,'Z');
  InsertVLast(&Senarai,'J');
  InsertVFirst(&Senarai,'X');
  PrintList(Senarai);
  DeleteVLast(&Senarai, &D);
  printf("Elemen terakhir yang dihapus : %c\n", D);
  DeleteVFirst(&Senarai, &D);
  printf("Elemen pertama yang dihapus : %c\n", D);
  PrintList(Senarai);
  DeleteX(&Senarai,'N');
  PrintList(Senarai);
  InsertVFirst(&Senarai,'L');
  InsertVLast(&Senarai,'M');
  PrintList(Senarai);
  Invers(&Senarai);
  PrintList(Senarai);
  SearchX(Senarai,'Z',&A);
  printf("prev : %c\n", info(prev(A)));
  /*printf("Jumlah elemen A : %d\n",CountX(Senarai,'A'));
  printf("Frekuensi A : %.2f\n",FrekuensiX(Senarai,'A'));
  SearchAllX(Senarai,'A');
  printf("Jumlah elemen : %d\n",NbElm(Senarai));
  UpdateAllX(&Senarai,'A','B');
  InsertVAfter(&Senarai,'G','L');
  PrintList(Senarai);
  InsertVFirst(&Seranai,'G');
  InsertVLast(&Seranai,'N');
  PrintList(Seranai);
  ConcatList(Senarai, Seranai, &Senam);
  PrintList(Senam);
  SplitList(Senam, &Sese, &Nana);
  PrintList(Sese);
  PrintList(Nana);
  CopyList(Sese, &Rai);
  PrintList(Rai);*/
  return 0;
}
