/* File : mainlist2.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : */
/* Tanggal : Oktober 2024 */
#include "list2.c"
int main()
{ //kamus
  address P;
  infotype D, J;
  List2 Senarai, Seranai, Sese, Nana, Rai;
  //algoritma
  
  /*aplikasi tipe address
  A = (address) malloc ( sizeof (Elm) ); // Alokasi('G')
  A->info = 'G';   A->next = NIL;
  printf("info(A)=%c\t", A->info );
  B = (address) malloc ( sizeof (Elm) ); // Alokasi('N')
  B->info = 'N';   B->next = A;
  printf("info(B)=%c\n", B->info );
  
  //aplikasi tipe List2
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
  PrintList(Senarai);
  DeleteVLast(&Senarai, &D);
  printf("Elemen terakhir yang dihapus : %c\n", D);
  PrintList(Senarai);
  InsertVFirst(&Senarai,'A');
  InsertVLast(&Senarai,'Z');
  InsertVLast(&Senarai,'J');
  InsertVFirst(&Senarai,'X');
  PrintList(Senarai);
  printf("Jumlah elemen Senarai : %d\n",NbElm(Senarai));
  DeleteX(&Senarai,'G');
  PrintList(Senarai);
  SearchX(Senarai,'Z',&P);
  printf("Alamat Z : %p\n", P);
  UpdateX(&Senarai,'Z','G');
  UpdateX(&Senarai,'A','N');
  InsertVFirst(&Senarai,'A');
  InsertVLast(&Senarai,'Z');
  InsertVLast(&Senarai,'N');
  InsertVFirst(&Senarai,'G');
  PrintList(Senarai);
  Invers(&Senarai);
  PrintList(Senarai);
  Invers2(&Senarai);
  PrintList(Senarai);
  InsertVAfterX(&Senarai,'N','G');
  InsertVBeforeX(&Senarai,'A','C');
  PrintList(Senarai);
  printf("Jumlah elemen NG : %d\n",CountNG(Senarai));
  printf("Jumlah elemen A : %d\n",CountX(Senarai,'A'));
  DeleteVAfterX(&Senarai,'N',&J);
  printf("Elemen setelah N yang dihapus : %c\n", J);
  PrintList(Senarai);
  DeleteAllX(&Senarai,'N');
  PrintList(Senarai);
  SearchAllX(Senarai,'G');
  DeleteVBeforeX(&Senarai,'X',&J);
  printf("Elemen sebelum X yang dihapus : %c\n", J);
  printf("Modus adalah : %c\n",Modus(Senarai));
  PrintList(Senarai);
  SplitList(Senarai,&Seranai,&Sese);
  printf("Seranai : ");
  PrintList(Seranai);
  printf("Sese : ");
  PrintList(Sese);
  ConcatList(Seranai,Sese,&Nana);
  printf("Nana : ");
  PrintList(Nana);
  CopyList(Nana,&Rai);
  printf("Rai : ");
  PrintList(Rai);
}
