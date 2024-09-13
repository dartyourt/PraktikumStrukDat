/* Program   : mmatriks.c */
/* Deskripsi : driver ADT matriks integer */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include "matriks.c"

int main() {
	/*kamus*/
	Matriks M;
	int baris, kolom;
	
	/*algoritma*/
	initMatriks(&M);
	printf("%s\n", isFullMatriks(M) ? "penuh" : "kosong");
	addX(&M, 1, 1, 1);
	addX(&M, 12, 5, 2);
	addX(&M, 3, 2, 3);
	printMatriks(M);
	viewMatriks(M);
	delX(&M, 12);
	printMatriks(M);
	viewMatriks(M);
	printf("baris = %d, kolom = %d\n", getNBaris(M), getNKolom(M));
	return 0;
}
