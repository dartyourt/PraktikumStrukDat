/* File : pohon3.h */
/* Deskripsi : ADT bintree3 berkait dengan representasi fisik pointer */
/* NIM & Nama : */
/* Tanggal : */

#include "pohon3.h"


/************************ PROTOTYPE ************************/
/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* function AlokasiTree3( E: infotype)-> bintree3 */
/* {menghasilkan alokasi memori pohon } */
bintree3 Alokasi3(infotype E){
    //kamus lokal
    bintree3 P;
    //algoritma
    P = (bintree3) malloc(sizeof(node3));
    if (P != NIL) {
        info(P) = E;
        parent(P) = NIL;
        visited(P) = false;
        left(P) = NIL;
        right(P) = NIL;
      }
   
    return P;
} //representasi fisik fungsi



/********** PEMBUATAN POHON BARU ***********/
/* function Tree(A:bintree3, X:infotype, V:boolean, kiri:bintree3, kanan:bintree3)-> bintree3
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree3 Tree3 (bintree3 A, infotype X, boolean V, bintree3 kiri, bintree3 kanan){
      //kamus lokal
      bintree3 P;
      //algoritma
      P = Alokasi3(X);
      if (P != NIL) {
         parent(P) = A;
         visited(P) = V;
         left(P) = kiri;
         right(P) = kanan;
      }
      return P;
}

/*procedure resetVisited( input/output P : bintree3 )
{I.S: P terdefinisi; F.S: -}
{proses mengubah status visited semua node di P menjadi false}*/
void resetVisited (bintree3 P){
    //kamus lokal
    //algoritma
    if (!IsEmptyTree(P)) {
        visited(P) = false;
        resetVisited(left(P));
        resetVisited(right(P));
    }
}
/****** SELEKTOR *****/
/* menggunakan macro */

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree3) --> boolean 
   {mengembalikan true bila bintree3 L kosong} */
boolean IsEmptyTree (bintree3 P){
    //kamus lokal
    //algoritma
    return P == NIL;
}

/* function IsDaun (P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun (bintree3 P){
    //kamus lokal
    //algoritma
    return  (!IsEmptyTree(P)) && (left(P) == NIL) && (right(P) == NIL);
}

/* function IsBiner (P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner (bintree3 P){
    //kamus lokal
    //algoritma
    return !IsEmptyTree(P) && left(P) != NIL && right(P) != NIL;
}

/* function IsUnerLeft(P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft (bintree3 P){
    //kamus lokal
    //algoritma
    return !IsEmptyTree(P) && left(P) != NIL && right(P) == NIL;
}

/* function IsUnerRight(P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight (bintree3 P){
      //kamus lokal
      //algoritma
      return !IsEmptyTree(P) && left(P) == NIL && right(P) != NIL;
}

/*PENELUSURAN*/
/* procedure printDFS( input P:bintree3)
{mencetak node-node P dari elemen terkiri mendalam baru ke kanan} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void printDFS (bintree3 P){
      //kamus lokal
      //algoritma
      if (IsEmptyTree(P)) {
         printf("( )");
      } else {
         printf("%c", info(P));
         if (!IsEmptyTree(left(P)) || !IsEmptyTree(right(P))) {
               printf("(");
               printDFS(left(P));
               printf(",");
               printDFS(right(P));
               printf(")");
         }
      }
}

/*function SearchX(P:BinTree, X:infotype) -> boolean 
{ Mengirimkan true jika ada node dari P yang bernilai X }*/
boolean SearchX3(bintree3 P, infotype X){
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        return false;
    } else if (info(P) == X) {
        return true;
    } else {
        return SearchX3(left(P), X) || SearchX3(right(P), X);
    }
}
/*function SearchDaunX(P:BinTree, X:infotype) -> boolean 
{ Mengirimkan true jika X adalah daun}*/
boolean SearchDaunX3(bintree3 P, infotype X){
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        return false;
    } else if (IsDaun(P) && info(P) == X) {
        return true;
    } else {
        return SearchDaunX3(left(P), X) || SearchDaunX3(right(P), X);
    }
}

/*procedure printPathX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga node bernilai X }*/
void printPathX (bintree3 P, infotype X){
   //kamus lokal
   //algoritma
   if (IsEmptyTree(P)) {
      printf("Pohon kosong\n");
      return;
   }
   
   if (info(P) == X) {
      printf("%c\n", X);
      return;
   }
   
   if (left(P) != NIL) {
      if (SearchX3(left(P), X)){
      printf("%c -> ", info(P));
      printPathX(left(P), X);
      }
   }
   
   if (right(P) != NIL) {
      if (SearchX3(right(P), X)){
      printf("%c -> ", info(P));
      printPathX(right(P), X);
      }
   }
}

/*procedure printPathDaunX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga daun bernilai X }*/
void printPathDaunX (bintree3 P, infotype X){
   //kamus lokal
   //algoritma
   if (!IsEmptyTree(P)) {
      if (SearchDaunX3(P, X)){
         printPathX(P, X);
         }        
      }
}

/*procedure printAllPaths( input P:bintree3)
{menampilkan semua jalur yang mungkin dari akar P hingga setiap daun}*/
void printAllPaths(bintree3 P) {
   if(!IsEmptyTree(P)){
      if(IsDaun(P)){
         printPathDaunX(P, info(P));
      }else{
         printAllPaths(left(P));
         printAllPaths(right(P));
      }
   }
}

/* function NbElmTree(P:bintree3) --> integer
{ menghitung banyaknya elemen bintree3 P} */
int NbElmTree (bintree3 P){
      //kamus lokal
      //algoritma
      if (IsEmptyTree(P)) {
         return 0;
      } else {
         return 1 + NbElmTree(left(P)) + NbElmTree(right(P));
      }
}

/* function NbDaun(P:bintree3)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun (bintree3 P){
      //kamus lokal
      //algoritma
      if (IsEmptyTree(P)) {
         return 0;
      } else if (IsDaun(P)) {
         return 1;
      } else {
         return NbDaun(left(P)) + NbDaun(right(P));
      }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int Max2 (int a, int b){
      //kamus lokal
      //algoritma
      return (a > b) ? a : b;
}

/* function Tinggi(P:bintree3)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen = 0 }*/
int Tinggi (bintree3 P){
      //kamus lokal
      //algoritma
      if (IsEmptyTree(P)) {
         return -1;
      } else {
         return 1 + Max2(Tinggi(left(P)), Tinggi(right(P)));
      }
}

/* function Level(P:bintree3)-> integer
{menghitung tingkat/generasi node pohon P, level akar=1 }*/
int Level (bintree3 P){
      //kamus lokal
      //algoritma
      if (IsEmptyTree(P)) {
         return 0;
      } else {
         return 1 + Level(parent(P));
      }
}

/*function CountLevelT(P:bintree3, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT (bintree3 P, int T){
      //kamus lokal
      //algoritma
      if (IsEmptyTree(P)) {
         return 0;
      } else if (T == 1) {
         return 1;
      } else {
         return CountLevelT(left(P), T-1) + CountLevelT(right(P), T-1);
      }
}

/*procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N}*/
void PrintLevel (bintree3 P, int N){
   if (IsEmptyTree(P)) {
      return;
   }
   if (N == 1) {
      printf("%c ", info(P));
   } else if (N > 1) {
      PrintLevel(left(P), N-1);
      PrintLevel(right(P), N-1);
   }
}

/* procedure PrintBFS( input P:bintree3)
{mencetak node-node P dari generasi paling terkecil ke terbesar}*/
/*contoh: A B C D */
void PrintBFS (bintree3 P){
      //kamus lokal
      int i;
      //algoritma
      if(!IsEmptyTree(P)){
         for(i=1; i<=Tinggi(P)+1; i++){
            PrintLevel(P, i);
         }
      }
      else{
         printf("Pohon kosong\n");
      }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*** operator khusus LIST1 ***/
//printList sudah ADA di list1.h

/*procedure Pconcat( input/output Asli:list1, input Tambahan:list1) */
/*{I.S:- ; F.S: list Asli berubah karena disambung list Tambahan}*/
/*{menyambung list Tambahan ke belakang list Asli}*/
void Pconcat (List1 *Asli, List1 Tambahan){
      //kamus lokal
      address P;
      //algoritma
      if (IsEmptyList(*Asli)) {
         *Asli = Tambahan;
      } else {
         P = First(*Asli);
         while (next(P) != NIL) {
               P = next(P);
         }
         next(P) = First(Tambahan);
      }
}

/*function fconcat( Asli:List1, Tambahan:List1) -> List1 */
/*{membentuk list Baru hasil penyambungan list Tambahan ke belakang list Asli}*/
/*{periksa dampaknya, list Asli tidak boleh berubah }*/
List1 Fconcat (List1 Asli, List1 Tambahan){
      //kamus lokal
      List1 L;
      address P;
      //algoritma
      if (IsEmptyList(Asli)) {
         return Tambahan;
      } else {
         L = Asli;
         P = First(L);
         while (next(P) != NIL) {
               P = next(P);
         }
         next(P) = First(Tambahan);
         return L;
      }
}

/*** LINEARISASI POHON ***/
/*function linearPrefix(P:bintree3) -> List1
{menghasilkan list node dari P terurut prefix akar,kiri,kanan}*/
List1 LinearPrefix (bintree3 P){
   List1 L;
   CreateList(&L);
   if (!IsEmptyTree(P)) {
      InsertVLast(&L, info(P));
      List1 leftList = LinearPrefix(left(P));
      List1 rightList = LinearPrefix(right(P));
      Pconcat(&L, leftList);
      Pconcat(&L, rightList);
   }
   return L;
}

/*function linearPosfix(P:bintree3) -> List1
{menghasilkan list node dari P terurut posfix kiri,kanan,akar}*/
List1 LinearPosfix (bintree3 P){
   List1 L;
   CreateList(&L);
   if (!IsEmptyTree(P)) {
      List1 leftList = LinearPosfix(left(P));
      List1 rightList = LinearPosfix(right(P));
      Pconcat(&L, leftList);
      Pconcat(&L, rightList);
      InsertVLast(&L, info(P));
   }
   return L;
}

/*function linearInfix(P:bintree3) -> List1
{menghasilkan list node dari P terurut infix kiri,akar,kanan}*/
List1 LinearInfix (bintree3 P){
   List1 L;
   CreateList(&L);
   if (!IsEmptyTree(P)) {
      List1 leftList = LinearInfix(left(P));
      InsertVLast(&L, info(P));
      List1 rightList = LinearInfix(right(P));
      Pconcat(&L, rightList);
   }
   return L;
}

/*function linearBreadthFS(P:bintree3) -> List1
{menghasilkan list node dari P terurut level/tingkat}*/
List1 LinearBreadthFS (bintree3 P);
