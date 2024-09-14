/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : 24060123140151/Haidar Ali Laudza*/
/* Tanggal   : 13/09/2024*/
/***********************************/
#ifndef   matriks_c
#define   matriks_c
#include "matriks.h"
#include <stdio.h>
#include "boolean.h"
#include <stdlib.h>
/* include matriks.h & boolean.h */


/* KONSTRUKTOR */		
/* procedure initMatriks(output M: Matriks)
	{I.S.: - }
	{F.S.: Matriks M terdefinisi}
	{Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
void initMatriks(Matriks *M) {
    //kamus
    int i, j;
    //algoritma
    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 10; j++) {
            (*M).cell[i][j] = -999;
        }
    }
    (*M).nbaris = 0;
    (*M).nkolom = 0;
}

/* SELEKTOR */
/* function getNBaris(M: Matriks) -> integer
	{mengembalikan banyak baris matriks M yang terisi } */
int getNBaris(Matriks M) {
    return M.nbaris;
}

/* function getNKolom(M: Matriks) -> integer
	{mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M) {
    return M.nkolom;
}

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M){
    return M.nbaris == 0 && M.nkolom == 0;
}

/* function isFullMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M){
    //kamus
    int i, j;
    boolean full; 
    //algoritma
    full = true;
    i = 1;
    while (i <= 10 && full) {
        j = 1;
        while (j <= 10 && full) {
            if (M.cell[i][j] == -999) {
                full = false;
            } else {
                j++;
            }
        }
        i++;
    }
    return full;
}

/* OPERASI PENCARIAN*/
/* procedure searchX( input M:Matriks, input X: integer, output row: integer, output col: integer )
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: row berisi indeks baris dan col berisi indeks kolom ketemu X di M.cell, atau -999 jika tidak ketemu}
	{Proses: mencari elemen bernilai X dalam M.cell} */
void searchX(Matriks M, int X, int *row, int *col) {
    //kamus
    int i, j;
    boolean found;
    //algoritma
    found = false;
    i = 1;
    while (i <= getNBaris(M) && !found) {
        j = 1;
        while (j <= getNKolom(M) && !found) {
            if (M.cell[i][j] == X) {
                found = true;
            } else {
                j++;
            }
        }
        if (!found) {
            i++;
        }
    }
    if (found) {
        *row = i;
        *col = j;
    } else {
        *row = -999;
        *col = -999;
    }
}

/* function countX (M:Matriks, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam M.cell} */
int countX (Matriks M, int X) {
    //kamus
    int i, j, count;
    //algoritma
    count = 0;
    for (i = 1; i <= getNBaris(M); i++) {
        for (j = 1; j <= getNKolom(M); j++) {
            if (M.cell[i][j] == X) {
                count++;
            }
        }
    }
    return count;
}

/* MUTATOR */
/* procedure addX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
	{Proses: mengisi elemen M.cell dengan nilai X} */
void addX (Matriks *M, int X, int row, int col) {
    //kamus

    //algoritma
    if (!isFullMatriks(*M)) {
        printf("Matriks belum penuh\n");
        if (row > getNBaris(*M)) {
            (*M).nbaris = row;
        }
        if (col > getNKolom(*M)) {
            (*M).nkolom = col;
        }
        (*M).cell[row][col] = X;
    }
}

/* procedure editX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell pada baris ke-row dan kolom ke-col diubah dengan nilai X}
	{Proses: mengubah isi M.cell pada baris ke-row dan kolom ke-col dengan nilai X} */
void editX (Matriks *M, int X, int row, int col) {
    if (M->cell[row][col] != -999) {
        M->cell[row][col] = X;
    }
    else {
        printf("Cell tidak terdefinisi\n");
    }
}

/* procedure delX (input/output M:Matriks, input X:integer )
	{I.S.: M terdefinisi, X terdefinisi}
	{F.S.: elemen M.cell berkurang 1}
	{Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX (Matriks *M, int X){
    //kamus
    int i, j;
    boolean found;

    //algoritma
    if (!isFullMatriks(*M)) {
    found = false;
    i = 1;
    while (i <= getNBaris(*M) && !found) {
        j = 1;
        while (j <= getNKolom(*M) && !found) {
            if (M->cell[i][j] == X) {
                found = true;
                M->cell[i][j] = -999;
            } else {
                j++;
            }
        }
        if (!found) {
            i++;
        }
    }
    int maxRow = 0, maxCol = 0;
    for (i = 1; i <= getNBaris(*M); i++) {
        for (j = 1; j <= getNKolom(*M); j++) {
            if (M->cell[i][j] != -999) {
                if (i > maxRow) {
                    maxRow = i;
                }
                if (j > maxCol) {
                    maxCol = j;
                }
            }
        }
    }
    M->nbaris = maxRow;
    M->nkolom = maxCol;
    }
}

/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
	{proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y) {
    //kamus
    int i, j;
    //algoritma
    for (i = 1; i <= x; i++) {
        for (j = 1; j <= y; j++) {
            addX(M, rand() % 100, i, j);
        }
    }
}

/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
	{proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n){
    //kamus
    int i, j;
    //algoritma
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) {
                addX(M, 1, i, j);
            } else {
                addX(M, 0, i, j);
            }
        }
    }
}

/* OPERASI BACA/TULIS */
/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
void populateMatriks(Matriks *M, int x, int y) {
    //kamus
    int i, j, input;
    //algoritma
    for (i = 1; i <= x; i++) {
        for (j = 1; j <= y; j++) {
            printf("Masukkan elemen baris %d kolom %d: ", i, j);
            scanf("%d", &input);
            addX(M, input, i, j);
        }
    }
}

/* procedure printMatriks(input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks M) {
    //kamus
    int i, j;
    //algoritma
    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 10; j++) {
            printf("%d ", M.cell[i][j]);
        }
        printf("\n");
    }
}

/* procedure viewMatriks (input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks (Matriks M) {
    //kamus
    int i, j;
    //algoritma
    for (i = 1; i <= M.nbaris; i++) {
        for (j = 1; j <= M.nkolom; j++) {
            printf("%d ", M.cell[i][j]);
        }
        printf("\n");
    }
}

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2) {
    //kamus
    Matriks M;
    int i, j;
    //algoritma
    initMatriks(&M);
    if (getNBaris(M1) == getNBaris(M2) && getNKolom(M1) == getNKolom(M2)) {
        for (i = 1; i <= getNBaris(M1); i++) {
            for (j = 1; j <= getNKolom(M1); j++) {
                addX(&M, M1.cell[i][j] + M2.cell[i][j], i, j);
            }
        }
    }
    return M;
}

/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2) {
    //kamus
    Matriks M;
    int i, j;
    //algoritma
    initMatriks(&M);
    if (getNBaris(M1) == getNBaris(M2) && getNKolom(M1) == getNKolom(M2)) {
        for (i = 1; i <= getNBaris(M1); i++) {
            for (j = 1; j <= getNKolom(M1); j++) {
                addX(&M, M1.cell[i][j] - M2.cell[i][j], i, j);
            }
        }
    }
    return M;
}

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2) {
    //kamus
    Matriks M;
    int i, j, k, sum;
    //algoritma
    initMatriks(&M);
    if (getNKolom(M1) == getNBaris(M2)) {
        for (i = 1; i <= getNBaris(M1); i++) {
            for (j = 1; j <= getNKolom(M2); j++) {
                sum = 0;
                for (k = 1; k <= getNKolom(M1); k++) {
                    sum += M1.cell[i][k] * M2.cell[k][j];
                }
                addX(&M, sum, i, j);
            }
        }
    }
    return M;
}   

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M1, int x) {
    //kamus
    Matriks M;
    int i, j;
    //algoritma
    initMatriks(&M);
    for (i = 1; i <= getNBaris(M1); i++) {
        for (j = 1; j <= getNKolom(M1); j++) {
            addX(&M, M1.cell[i][j] * x, i, j);
        }
    }
    return M;
}

/* OPERASI STATISTIK*/
/* function getSumMatriks (M:Matriks) -> integer 
	{mengembalikan jumlah semua elemen pengisi M.cell} */
int getSumMatriks (Matriks M) {
    //kamus
    int i, j, sum;
    //algoritma
    sum = 0;
    for (i = 1; i <= getNBaris(M); i++) {
        for (j = 1; j <= getNKolom(M); j++) {
            sum += M.cell[i][j];
        }
    }
    return sum;
}

/* function getAveragematriks (M:Matriks) -> real 
	{mengembalikan nilai rata-rata elemen pengisi M.cell} */
float getAverageMatriks (Matriks M) {
    //kamus
    int sum;
    //algoritma
    sum = getSumMatriks(M);
    return (float) sum / (getNBaris(M) * getNKolom(M));
}

/* function getMaxMatriks (M:Matriks) -> integer
	{mengembalikan nilai elemen terbesar pengisi M.cell } */
int getMaxMatriks (Matriks M) {
    //kamus
    int i, j, max;
    //algoritma
    max = M.cell[1][1];
    for (i = 2; i <= getNBaris(M); i++) {
        for (j = 2; j <= getNKolom(M); j++) {
            if (M.cell[i][j] > max) {
                max = M.cell[i][j];
            }
        }
    }
    return max;
}

/* function getMinMatriks (M:Matriks) -> integer
	{mengembalikan nilai elemen terkecil pengisi M.cell} */
int getMinMatriks (Matriks M) {
    //kamus
    int i, j, min;
    //algoritma
    min = M.cell[1][1];
    for (i = 2; i <= getNBaris(M); i++) {
        for (j = 2; j <= getNKolom(M); j++) {
            if (M.cell[i][j] < min) {
                min = M.cell[i][j];
            }
        }
    }
    return min;
}

/* OPERASI LAINNYA */
/* procedure transposeMatriks(input/output M: Matriks)
	{I.S.: M terdefinisi}
	{F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
	{proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M) {
    //kamus
    int i, j, temp;
    //algoritma
    for (i = 1; i <= getNBaris(*M); i++) {
        for (j = i; j <= getNKolom(*M); j++) {
            temp = M->cell[i][j];
            M->cell[i][j] = M->cell[j][i];
            M->cell[j][i] = temp;
        }
    }
    temp = M->nbaris;
    M->nbaris = M->nkolom;
    M->nkolom = temp;
}

/* function getTransposeMatriks(M: Matriks)
	{menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M) {
    //kamus
    Matriks T;
    int i, j;
    //algoritma
    initMatriks(&T);
    for (i = 1; i <= getNBaris(M); i++) {
        for (j = 1; j <= getNKolom(M); j++) {
            addX(&T, M.cell[j][i], i, j);
        }
    }
    return T;
}
#endif