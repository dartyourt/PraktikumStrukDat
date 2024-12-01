/* File : pohon2.h */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* pohon2 melengkapi operator ADT bintree yang ada dalam pohon1 */
/* NIM & Nama : */
/* Tanggal : */

#include "pohon2.h"

/*PENELUSURAN*/
/* procedure PrintTreeInden (input P : BinTree, input H : integer)
{ I.S. P terdefinisi, h adalah jarak indentasi subpohon }
{ F.S. Semua simpul P ditulis dengan indentasi berjenjang,mirip file explorer} */
void PrintTreeInden(bintree P, int H ){
    //kamus lokal
    //algoritma
    if (!IsEmptyTree(P)) {
        printf("%c\n", GetAkar(P));
        if (!IsEmptyTree(GetLeft(P))) {
            for (int i = 1; i <= H; i++) {
                printf(" ");
            }
            PrintTreeInden(GetLeft(P), 2*H);
        }
        if (!IsEmptyTree(GetRight(P))) {
            for (int i = 1; i <= H; i++) {
                printf(" ");
            }
            PrintTreeInden(GetRight(P), 2*H);
        }
    }
}

/* procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N} */
void PrintLevel(bintree P, int N){
    //kamus lokal
    //algoritma
    if (!IsEmptyTree(P)) {
        if (N == 1) {
            printf("%c ", GetAkar(P));
        } else {
            PrintLevel(GetLeft(P), N-1);
            PrintLevel(GetRight(P), N-1);
        }
    }
}

/*KONSTRUKTOR*/
/*function BuildBalanceTree (n : integer) -> BinTree
{ Menghasilkan balanced tree dengan n node, nilai setiap node dibaca dari keyboard }*/
bintree BuildBalanceTree(int n){
    //kamus lokal
    bintree P;
    infotype X;
    //algoritma
    if (n == 0) {
        return NIL;
    } else {
        scanf(" %c", &X);
        P = Alokasi(X);
        left(P) = BuildBalanceTree(n/2);
        right(P) = BuildBalanceTree(n - n/2 - 1);
        return P;
    }
}

/*PREDIKAT*/
/*function IsBalanceTree (P : BinTree) -> boolean
{ Menghasilkan true jika P seimbang, banyak node kiri ~= kanan }*/
boolean IsBalanceTree(bintree P){
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        return true;
    } else {
        return abs(NbElm(left(P)) - NbElm(right(P))) <= 1;
    }
}

/******* PENAMBAHAN ELEMEN bintree ********/
/*procedure AddDaunTerkiri (input/output P : BinTree, input X : infotype)
{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri }*/
void AddDaunTerkiri(bintree P, infotype X){
    //kamus lokal
    //algoritma
    if (P == NIL) {
        P = Alokasi(X);
    } else {
        if (IsEmptyTree(GetLeft(P))) {
            left(P) = Alokasi(X);
        } else {
            AddDaunTerkiri(GetLeft(P), X);
        }
    }
}

/*procedure AddDaun (input/Output P : BinTree, input X, Y : infotype, input Kiri : boolean)
{ I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau sebagai anak Kanan X (jika not Kiri) }*/
void AddDaun(bintree P, infotype X, infotype Y, boolean Kiri){
    //kamus lokal
    //algoritma
    if (IsEmptyTree(P)) {
        return;
    } else {
        if (GetAkar(P) == X) {
            if (Kiri) {
                left(P) = Alokasi(Y);
            } else {
                right(P) = Alokasi(Y);
            }
        } else {
            AddDaun(GetLeft(P), X, Y, Kiri);
            AddDaun(GetRight(P), X, Y, Kiri);
        }
    }
}

/*procedure InsertX (input/output P : BinTree, input X : infotype)
{ Menghasilkan sebuah pohon P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
void InsertX(bintree *P, infotype X){
    //kamus lokal
    //algoritma
    if (IsEmptyTree(*P)) {
        *P = Alokasi(X);
    }
    else {
        if (!SearchX(*P, X)) {
            AddDaunTerkiri(*P, X);
        }
        else {
            return;
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*procedure DelDaunTerkiri (input/output P : BinTree, output X : infotype)
{ I.S. P tidak kosong }
{ F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang
semula disimpan pada daun terkiri yang dihapus }*/
void DelDaunTerkiri(bintree *P, infotype *X) {
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(*P)) {
        if (IsDaun(*P)) {
            *X = akar(*P);
            Dealokasi(P);
            *P = NIL;
        }   
        else {
            if (left(*P) != NIL) {
                DelDaunTerkiri(&left(*P), X);
            }
            else {
                DelDaunTerkiri(&right(*P), X);
            }
        }
    }
}

/*procedure DelDaun (input/output P : BinTree, input X : infotype)
{ I.S. P tidak kosong, X adalah salah satu daun }
{ F.S. X dihapus dari P }*/
void DelDaun(bintree *P, infotype X) {
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(*P)) {
        if (IsDaun(*P) && akar(*P) == X) {
            Dealokasi(P);
        }
        else {
            DelDaun(&left(*P), X);
            DelDaun(&right(*P), X);
        }
    }
}

/*procedure DeleteX (input/output P : BinTree, input X : infotype)
{ Menghapus simpul bernilai X bila ada dari P, HATI-HATI! }*/
void DeleteX(bintree *P, infotype X) {
    // kamus lokal
    bintree temp;

    // algoritma
    if (!IsEmptyTree(*P)) {
        if (GetAkar(*P) == X) {
            if (IsDaun(*P)) {
                Dealokasi(P);
                *P = NIL;
            } else if (left(*P) != NIL) {
                temp = left(*P);
                Dealokasi(P);
                *P = temp;
            } else {
                temp = right(*P);
                Dealokasi(P);
                *P = temp;
            }
        } else {
            DeleteX(&left(*P), X);
            DeleteX(&right(*P), X);
        }
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateAllX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y. Mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(bintree *P, infotype X, infotype Y){
    //kamus lokal
    //algoritma
    if (!IsEmptyTree(*P)) {
        if (GetAkar(*P) == X) {
            info(*P) = Y;
        }
        UpdateAllX(&left(*P), X, Y);
        UpdateAllX(&right(*P), X, Y);
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/* function maxTree(P:bintree)->character
{mengembalikan huruf "maksimal" dari elemen P, A<B<C<..<Z }*/
char maxTree(bintree P) {
    // kamus lokal
    char maxLeft, maxRight, maxVal;

    // algoritma
    if (IsEmptyTree(P)) {
        return 'A' - 1; // Nilai lebih kecil dari 'A'
    }

    maxVal = GetAkar(P);

    if (!IsEmptyTree(GetLeft(P))) {
        maxLeft = maxTree(GetLeft(P));
        if (maxLeft > maxVal) {
            maxVal = maxLeft;
        }
    }

    if (!IsEmptyTree(GetRight(P))) {
        maxRight = maxTree(GetRight(P));
        if (maxRight > maxVal) {
            maxVal = maxRight;
        }
    }

    return maxVal;
}

/* function minTree(P:bintree)->character
{mengembalikan huruf "minimal" dari elemen P, A<B<C<..<Z }*/
char minTree(bintree P){
    //kamus lokal
    char minLeft, minRight, minVal;

    //algoritma
    if (IsEmptyTree(P)) {
        return 'Z' + 1; // Nilai lebih besar dari 'Z'
    }

    minVal = GetAkar(P);

    if (!IsEmptyTree(GetLeft(P))) {
        minLeft = minTree(GetLeft(P));
        if (minLeft < minVal) {
            minVal = minLeft;
        }
    }

    if (!IsEmptyTree(GetRight(P))) {
        minRight = minTree(GetRight(P));
        if (minRight < minVal) {
            minVal = minRight;
        }
    }

    return minVal;
}

/*{ Operator KHUSUS Binary Search Tree, node kiri selalu lebih kecil daripada node kanan }*/

/*function BSearch (P : BinTree, X : infotype) → boolean
{ Mengirimkan true jika ada node dari pohon binary search P yang bernilai X }*/
boolean BSearch(bintree P, infotype X);

/*function InsSearch (P : BinTree, X : infotype) → BinTree
{ Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
bintree InsSearch(bintree P, infotype X);

/*procedure DelBtree (input/output P : BinTree, input X : infotype)
{ I.S. Pohon binary search P tidak kosong }
{ F.S. Nilai X yang dihapus pasti ada }
{ Sebuah node dg nilai X dihapus }*/
void DelBtree(bintree *P, infotype X);

