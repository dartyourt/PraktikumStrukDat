/* File : pohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : */
/* Tanggal : */

#include "pohon1.h"


/************************ PROTOTYPE ************************/
/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* function Alokasi( E: infotype)-> bintree */
/* {menghasilkan alokasi memori pohon dengan info=E, left=NIL, right=NIL  } */
bintree Alokasi(infotype E){
    //kamus lokal
    bintree P;
    //algoritma
    P = (bintree) malloc(sizeof(node));
    if (P != NIL) {
        info(P) = E;
        left(P) = NIL;
        right(P) = NIL;
    }
    return P;
} //representasi fisik fungsi
 
/* procedure Dealokasi (input/output P:bintree) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian bintree P} */
void Dealokasi (bintree *P){
    //kamus lokal
    //algoritma
    free(*P);
    *P = NIL;
}

/********** PEMBUATAN bintree KOSONG ***********/
/* function Tree(Akar:infotype, Left:BinTree, Right:BinTree)-> BinTree
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree Tree (infotype akar, bintree left, bintree right){
    //kamus lokal
    bintree P;
    //algoritma
    P = Alokasi(akar);
    if (P != NIL) {
        left(P) = left;
        right(P) = right;
        akar(P) = akar;
    }
    return P;
}

/****** SELEKTOR *****/
/*function GetAkar (P : BinTree) -> infotype
{ Mengirimkan nilai Akar pohon biner P }*/
infotype GetAkar(bintree P){
    //kamus lokal
    //algoritma
    return info(P);
}

/*function GetLeft (P : BinTree) -> BinTree
{ Mengirimkan Anak Kiri pohon biner P }*/
bintree GetLeft(bintree P){
    //kamus lokal
    //algoritma
    return left(P);
}

/*function GetRight (P : BinTree) -> BinTree
{ Mengirimkan Anak Kanan pohon biner P }*/
bintree GetRight(bintree P){
    //kamus lokal
    //algoritma
    return right(P);
}

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree) --> boolean 
   {mengembalikan true bila bintree L kosong} */
boolean IsEmptyTree (bintree P){
    //kamus lokal
    //algoritma
    return P == NIL;
}

/* function IsDaun (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree P){
    //kamus lokal
    //algoritma
    return  (!IsEmptyTree(P)) && (left(P) == NIL) && (right(P) == NIL);
}

/* function IsBiner (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree P){
    //kamus lokal
    //algoritma
    return (left(P) != NIL) && (right(P) != NIL);
}

/* function IsUnerLeft(P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree P){
    //kamus lokal
    //algoritma
    return (left(P) != NIL) && (right(P) == NIL);
}

/* function IsUnerRight(P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree P){
    //kamus lokal
    //algoritma
    return (left(P) == NIL) && (right(P) != NIL);
}

/*PENELUSURAN*/
/* procedure PrintPrefix(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier lengkap} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void PrintPrefix(bintree P){
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) {
    printf("( )");
  } else {
    printf("%c", GetAkar(P));
    printf("(");
    PrintPrefix(GetLeft(P));
    printf(",");
    PrintPrefix(GetRight(P));
    printf(")");
  }
}

/* function NbElm(P:bintree) --> integer
{ menghitung banyaknya elemen bintree P} */
int NbElm(bintree P){
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        return 0;
    } else {
        return 1 + NbElm(left(P)) + NbElm(right(P));
    }
}

/* function NbDaun(P:BinTree)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree P){
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
int max2(int a, int b){
    //kamus lokal
    //algoritma
    return (a > b) ? a : b;
}

/* function Tinggi(P:BinTree)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen yaitu 0 }*/
int Tinggi(bintree P){
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        return -1;
    } else {
        return 1 + max2(Tinggi(left(P)), Tinggi(right(P)));
    }
}

/******* PENAMBAHAN ELEMEN bintree ********/

/******* PENGHAPUSAN ELEMEN ********/

/*** PENCARIAN ***/
/*function SearchX(P:BinTree, X:infotype) -> boolean 
{ Mengirimkan true jika ada node dari P yang bernilai X }*/
boolean SearchX(bintree P, infotype X){
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        return false;
    } else {
        return (info(P) == X) || SearchX(left(P), X) || SearchX(right(P), X);
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(bintree *P, infotype X, infotype Y){
    //kamus lokal
    //algoritma
    if (!IsEmptyTree(*P)) {
        if (info(*P) == X) {
            info(*P) = Y;
        } else {
            UpdateX(&left(*P), X, Y);
            UpdateX(&right(*P), X, Y);
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(P:BinTree, X:infotype) -> integer 
{ Mengirimkan banyaknya node dari P yang bernilai X }*/
int CountX(bintree P, infotype X){
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        return 0;
    } else {
        if (info(P) == X) {
            return 1 + CountX(left(P), X) + CountX(right(P), X);
        } else {
            return CountX(left(P), X) + CountX(right(P), X);
        }
    }
}

/*function IsSkewLeft (P : BinTree)-> boolean 
{ Mengirim true jika P adalah pohon condong kiri } */
boolean IsSkewLeft (bintree P){
    //kamus lokal
    //algoritma
    if (!IsEmptyTree(P)) {
      if (IsDaun(P)) {
        return true;
      } else {
        IsUnerLeft(P) && IsSkewLeft(left(P));
      }
    }
    else {
      return false;
    }
  }

/*function IsSkewRight (P : BinTree) -> boolean
{ Mengirim true jika P adalah pohon condong kanan }*/
boolean IsSkewRight (bintree P){
    //kamus lokal
    //algoritma
    if (!IsEmptyTree(P)) {
      if (IsDaun(P)) {
        return true;
      } else {
        IsUnerRight(P) && IsSkewRight(right(P));
      }
    }
    else {
      return false;
    }
}

/* procedure PrintPrefix2input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier ringkas} */
/*contoh: A(B(( ),D),C)*/
void PrintPrefix2(bintree P){
}


/*function LevelX(P:BinTree, X:infotype)-> integer
{ Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }*/
int LevelX(bintree P, infotype X){
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        return 0;
    } else if (info(P) == X) {
        return 1;
    } else {
        if (LevelX(left(P), X) != 0) {
            return 1 + LevelX(left(P), X);
        } else {
            return 1 + LevelX(right(P), X);
        }
    }
}

/*function CountLevelT(P:BinTree, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT(bintree P, int T){
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

/*function GetDaunTerkiri(bintree P)-> infotype 
{mengembalikan nilai info daun terkiri, bila tidak ada, hasilnya '#' }*/
infotype GetDaunTerkiri(bintree P){
   // Kamus lokal

    // Algoritma
    if (IsEmptyTree(P)) {
        return '#'; 
    }

    if (left(P) == NIL && right(P) == NIL) {
        return info(P);
    }

    if (left(P) != NIL) {

        return GetDaunTerkiri(left(P));
    }

    return GetDaunTerkiri(right(P));
}

/*function FrekuensiX(L:bintree, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran bintree L }*/
float FrekuensiX(bintree P, infotype X){
    //kamus lokal
    //algoritma
    return (float) CountX(P, X) / NbElm(P);
}

/*function CountVocal(L:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam bintree L}*/
int CountVocal(bintree L){
    //kamus lokal
    //algoritma
    if (IsEmptyTree(L)) {
        return 0;
    } else {
        if (info(L) == 'A' || info(L) == 'I' || info(L) == 'U' || info(L) == 'E' || info(L) == 'O') {
            return 1 + CountVocal(left(L)) + CountVocal(right(L));
        } else {
            return CountVocal(left(L)) + CountVocal(right(L));
        }
    }
}

/*function Modus(L:bintree) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam bintree L}*/
char Modus(bintree P){
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        return '#';
    } else {
        int max, count;
        char modus;
        max = 0;
        bintree temp = P;
        while (temp != NIL) {
            count = CountX(P, info(temp));
            if (count > max) {
                max = count;
                modus = info(temp);
            }
            temp = temp->right;
        }
        return modus;
    }
}
