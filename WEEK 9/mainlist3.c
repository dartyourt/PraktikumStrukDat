/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait ganda, representasi fisik pointer */
/* NIM & Nama : */
/* Tanggal : Oktober 2024 */
#include "list3.c"
int main()
{ //kamus
  address A;
  infotype D;
  List3 Senarai, Seranai, Senam, Sese, Nana, Rai;
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
  CreateList(&Seranai);
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
  SearchX(Senarai,'G',&A);
  printf("prev : %c\n", info(prev(A)));
  InsertVAfterX(&Senarai,'G','L');
  PrintList(Senarai);
  InsertVBeforeX(&Senarai,'Z','E');
  PrintList(Senarai);
  DeleteVAfterX(&Senarai,'Z',&D);
  printf("Elemen setelah Z yang dihapus : %c\n", D);
  PrintList(Senarai);
  DeleteVBeforeX(&Senarai,'E',&D);
  printf("Elemen sebelum E yang dihapus : %c\n", D);
  InsertVFirst(&Senarai,'G');
  InsertVFirst(&Senarai,'N');
  PrintList(Senarai);
  printf("First L : %c\n",info(First(Senarai)));
  printf("Jumlah elemen L : %d\n",CountX(Senarai,'L'));
  printf("Frekuensi L : %.2f\n",FrekuensiX(Senarai,'L'));
  printf("Max Member : %d\n",MaxMember(Senarai));
  printf("Modus : %c\n",Modus(Senarai));
  printf("Vokal : %d\n",CountVocal(Senarai));
  printf("NG : %d\n",CountNG(Senarai));
  SearchAllX(Senarai,'A');
  DeleteAllX(&Senarai,'L');
  PrintList(Senarai);
  InsertVFirst(&Seranai,'Y');
  InsertVLast(&Seranai,'W');
  InsertVFirst(&Seranai,'I');
  InsertVLast(&Seranai,'O');
  PrintList(Seranai);
  ConcatList(Senarai, Seranai, &Senam);
  PrintList(Senam);
  printf("Jumlah vokal : %d\n",CountVocal(Senam));
  SplitList(Senam, &Sese, &Nana);
  PrintList(Sese);
  PrintList(Nana);
  CopyList(Sese, &Rai);
  PrintList(Rai);
  return 0;
}
