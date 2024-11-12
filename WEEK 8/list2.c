/* File : List2.h */
/* Deskripsi : ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : */
/* Tanggal : */
#include "list2.h"
/*================== PROTOTYPE =======================*/
/****************** Manajemen Memori ******************/
/* Function Alokasi(E:infotype)->address */
/* {mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E){
   //kamus lokal
   address P;
   //algoritma
   P = (address) malloc(sizeof(Elm));
   if (P != NIL) { //ruang memori tersedia
      info(P) = E;
      next(P) = NIL;
   }
   return P;
} //representasi fisik fungsi
 
/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P){
   //kamus lokal
   
   //algoritma
   free(*P);
   *P = NIL;
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List2)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List2 *L){
   //kamus lokal
   
   //algoritma
   First(*L) = NIL;
}

/****************** TEST KONDISI LIST ******************/
/* function IsEmptyList(L:List2) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List2 L){
   //kamus lokal

   //algoritma
   return First(L)==NIL;
}

/* function IsOneElm(L:List2) --> boolean 
   {mengembalikan true bila list L hanya punya satu elemen} */
boolean IsOneElm (List2 L){
   return (First(L)!=NIL && next(First(L))==First(L));
}

/*********** PENELUSURAN ***********/
/*procedure PrintList(input L:List2)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List2 L){
   //kamus lokal
   address P;
   //algoritma
   P = First(L);
   if (P != NIL) {
      do {
         printf("\t%c",info(P));
         P = next(P);
      } while (P != First(L));
   }
   printf("\n");
}

/*function NbElm(L:List2) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List2 L){
   //kamus lokal
   address P;
   int count;
   //algoritma
   count = 0;
   P = First(L);
   if (P != NIL) {
      do {
         count++;
         P = next(P);
      } while (P != First(L));
   }
   return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List2 *L, infotype V ){
   //kamus lokal
   address P, Last;
   //algoritma
   P = Alokasi(V);
   if (IsEmptyList(*L)) {
      First(*L) = P;
      next(P) = First(*L);
   }
   else {
      Last = First(*L);
      while (next(Last) != First(*L)) {
         Last = next(Last);
      }
      next(P) = First(*L);
      next(Last) = P;
      First(*L) = P;
   }
}

/*Procedure InsertVLast(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V, next(P)=First(L)}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List2 *L, infotype V ){
   //kamus lokal
   address P, Last;
   //algoritma
   P = Alokasi(V);
   if (P != NIL) {
      if (IsEmptyList(*L)) {
         First(*L) = P;
         next(P) = First(*L);
   }
      else {
         Last = First(*L);
         while (next(Last) != First(*L)) {
         Last = next(Last);

      }
         next(P) = First(*L);
         next(Last) = P;
   }
   }

}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen pertama list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List2 *L, infotype *V){
   //kamus lokal
   address Last, P;
   //algoritma
   if (!IsEmptyList(*L)) {
      P = First(*L);
      *V = info(P);
      if (IsOneElm(*L)) {
         Dealokasi(&P);
         First(*L) = NIL;
      }
      else {
         Last = First(*L);
         while (next(Last) != First(*L)) {
            Last = next(Last);
         }
         First(*L) = next(First(*L));
         next(Last) = First(*L);
         Dealokasi(&P);
      }
   }
   else {
      *V = '#';
   }
}

/*Procedure DeleteVLast(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List2 *L, infotype *V){
   //kamus lokal
   address Prec, Last;
   //algoritma
   if (!IsEmptyList(*L)) {
      Prec = First(*L);
      Last = First(*L);
      while (next(Last) != First(*L)) {
         Prec = Last;
         Last = next(Last);
      }
      *V = info(Last);
      if (IsOneElm(*L)) {
         Dealokasi(&Last);
         First(*L) = NIL;
      }
      else {
         next(Prec) = First(*L);
         Dealokasi(&Last);
      }
   }
   else {
      *V = '#';
   }
}

/*Procedure DeleteX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteX(List2 *L, infotype X){
   //kamus lokal
   address Prec, P;
   //algoritma
   if (!IsEmptyList(*L)) {
      Prec = First(*L);
      P = First(*L);
      while (info(P) != X && next(P) != First(*L)) {
         Prec = P;
         P = next(P);
      }
      if (info(P) == X) {
         if (IsOneElm(*L)) {
            First(*L) = NIL;
         }
         else {
            if (P == First(*L)) {
               DeleteVFirst(L, &X);
            }
            else {
               next(Prec) = next(P);
               Dealokasi(&P);
            }
         }
      }
   }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List2 L, infotype X, address *A){
   //kamus lokal
   address P;
   //algoritma
   P = First(L);
   *A = NIL;
   if (!IsEmptyList(L)) {
      do {
         if (info(P) == X) {
            *A = P;
         }
         P = next(P);
      } while (P != First(L) && *A == NIL);
   }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List2 *L, infotype X, infotype Y){
   //kamus lokal
   address P;
   //algoritma
   SearchX(*L, X, &P);
   if (P != NIL) {
      info(P) = Y;
   }
}

/*Procedure Invers(input/output L:List2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, 
misal {'A','B','C'} menjadi {'C','B','A'} }*/
void Invers(List2 *L){
   //kamus lokal
   address P, Prec, Last, F;
   //algoritma
   Prec = NIL;
   P = First(*L);
   if (P != NIL) {
      F = First(*L);
      do {
         Last = P;
         P = next(P);
         next(Last) = Prec;
         Prec = Last;
      } while (P != F);
      First(*L) = Last;
      next(F) = Last;
   }

}
void Invers2(List2 *L){
   //kamus lokal
   infotype P;
   List2 L2;
   //algoritma
   CreateList(&L2);
   do {
      DeleteVLast(L, &P);
      InsertVLast(&L2, P);
   } while (!IsEmptyList(*L));
   First(*L) = First(L2);

}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(L:List2, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List2 L, infotype X){
   //kamus lokal
   address P;
   int countX;
   //algoritma
   P = First(L);
   countX = 0;
   if (P!= NIL) {
      do {
         if (info(P) == X) {
            countX++;
         }
         P = next(P);
      } while (P != First(L));
   }
   return countX;
}

/*function FrekuensiX(L:List2, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List2 L, infotype X){
   //kamus lokal
   
   //algoritma
   return (float) CountX(L, X) / NbElm(L);
}

/*function CountVocal(L:List2) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List2 L){
   //kamus lokal
   address P;
   int countVocal;
   //algoritma
   P = First(L);
   countVocal = 0;
   if (P != NIL) {
      do {
         if (info(P) == 'A' || info(P) == 'I' || info(P) == 'U' || info(P) == 'E' || info(P) == 'O') {
            countVocal++;
         }
         P = next(P);
      } while (P != First(L));
   }
   return countVocal;
}

/*function CountNG(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List2 L){
   //kamus lokal
   address P;
   int countNG;
   //algoritma
   P = First(L);
   countNG = 0;
   if (P != NIL) {
      do {
         if (info(P) == 'N' && info(next(P)) == 'G') {
            countNG++;
         }
         P = next(P);
      } while (P != First(L));
   }
   return countNG;
}




/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List2 *L, infotype X, infotype V){
   //kamus lokal
   address P, Prec;
   //algoritma
   P = Alokasi(V);
   if (P != NIL) {
      SearchX(*L, X, &Prec);
      if (Prec != NIL) {
         next(P) = next(Prec);
         next(Prec) = P;
      }
      else {
         InsertVFirst(L, V);
      }
   }
}

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List2 *L, infotype X, infotype V){
   //kamus lokal
   address P, Prec, Last;
   //algoritma
   P = Alokasi(V);
   if (P != NIL) {
      SearchX(*L, X, &Prec);
      if (Prec != NIL) {
         if (Prec == First(*L)) {
            InsertVFirst(L, V);
         }
         else {
            Last = First(*L);
            while (next(Last) != Prec) {
               Last = next(Last);
            }
            next(P) = Prec;
            next(Last) = P;
         }
      }
      else {
         InsertVLast(L, V);
      }
   }
}

/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List2 *L, infotype X, infotype *V){
   //kamus lokal
   address Prec, P;
   //algoritma
   SearchX(*L, X, &Prec);
   if (Prec != NIL) {
      P = next(Prec);
      if (P != NIL) {
         *V = info(P);
         if (next(P) == Prec) {
            next(Prec) = First(*L);
         }
         else {
            next(Prec) = next(P);
         }
         Dealokasi(&P);
      }
   }
}

/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List2 *L, infotype X, infotype *V) {
   // kamus lokal
   address P, Prec, Suc;
   // algoritma
   P = NIL;
   Prec = NIL;
   Suc = First(*L);
   if (Suc != NIL) {
      while (next(Suc) != First(*L) && info(Suc) != X) {
         Prec = P;
         P = Suc;
         Suc = next(Suc);
      }
      if (First(*L) != P && info(Suc) == X) {
         next(Prec) = Suc;
         *V = info(P);
         Dealokasi(&P);
      }
      else if (First(*L) == P && info(Suc) == X) {
         *V = info(P);
         DeleteVFirst(L, V);
      }
   }
}


/*Procedure DeleteAllX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Semua elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteAllX(List2 *L, infotype X){
   //kamus lokal
   int sum;
   //algoritma
   sum = CountX(*L, X);
   for (int i = 1; i <= sum; i++) {
      DeleteX(L, X);
   }
}

/*Procedure SearchAllX(input L:List2, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List2 L, infotype X){
   //kamus lokal
   address P;
   int count;
   //algoritma
   P = First(L);
   count = 0;
   if (P != NIL) {
      do {
         count++;
         if (info(P) == X) {
            printf("%d ", count);
         }
         P = next(P);
      } while (P != First(L));
   }
   printf("\n");
}

/*function MaxMember(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List2 L){
   //kamus lokal
   address P;
   int max, count;
   //algoritma
   P = First(L);
   max = 0;
   if (P != NIL) {
      do {
         count = CountX(L, info(P));
         if (count > max) {
            max = count;
         }
         P = next(P);
      } while (P != First(L));
   }
   return max;
}

/*function Modus(L:List2) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List2 L){
   //kamus lokal
   address P;
   char modus;
   //algoritma
   P = First(L);
   if (P != NIL) {
      do {
         if (CountX(L, info(P)) == MaxMember(L)) {
            modus = info(P);
         }
         P = next(P);
      } while (P != First(L) && MaxMember(L) > 1);
   }
   return modus;
}


/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List2, input L2:List2, output L:List2)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List2 L1, List2 L2, List2 *L){
   //kamus lokal
   address P;
   //algoritma
   CreateList(L);
   if (!IsEmptyList(L1)) {
      P = First(L1);
      do {
         InsertVLast(L, info(P));
         P = next(P);
      } while (P != First(L1));
   }
   if (!IsEmptyList(L2)) {
      P = First(L2);
      do {
         InsertVLast(L, info(P));
         P = next(P);
      } while (P != First(L2));
   }
}

/*Procedure SplitList(input L:List2, output L1:List2, output L2:List2)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List2 L, List2 *L1, List2 *L2){
   //kamus lokal
   address P;
   int i, n;
   //algoritma
   CreateList(L1);
   CreateList(L2);
   n = NbElm(L);
   if (n % 2 == 0) {
      n = n / 2;
   }
   else {
      n = n / 2 + 1;
   }
   P = First(L);
   for (i = 1; i <= n; i++) {
      InsertVLast(L1, info(P));
      P = next(P);
   }
   for (i = n + 1; i <= NbElm(L); i++) {
      InsertVLast(L2, info(P));
      P = next(P);
   }
}

/*Procedure CopyList(input L1:List2, output L2:List2)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List2 L1, List2 *L2){
   //kamus lokal
   address P;
   //algoritma
   CreateList(L2);
   P = First(L1);
   if (P != NIL) {
      do {
         InsertVLast(L2, info(P));
         P = next(P);
      } while (P != First(L1));
   }
}
