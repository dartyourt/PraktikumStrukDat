/* Program   : mmatriks.c */
/* Deskripsi : driver ADT matriks integer */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include "matriks.c"

int main() {
	/*kamus*/
	Matriks M, M1, M2;
	
	/*algoritma*/
	initMatriks(&M);
	initMatriks(&M1);
	initMatriks(&M2);
	//printf("%s\n", isFullMatriks(M) ? "penuh" : "kosong");
	//addX(&M, 1, 1, 1);
	//addX(&M, 12, 5, 2);
	//addX(&M, 3, 2, 3);
	//printMatriks(M);
	//viewMatriks(M);
	//delX(&M, 12);
	//printMatriks(M);
	//viewMatriks(M);
	//printf("baris = %d, kolom = %d\n", getNBaris(M), getNKolom(M));
	populateMatriks(&M1, 3, 3);
	populateMatriks(&M2, 3, 3);
	viewMatriks(M1);
	printf("baris = %d, kolom = %d\n", getNBaris(M1), getNKolom(M1));
	printf("x ada %d\n", countX(M1, 2));
	viewMatriks(addMatriks(M1, M2));
	printf("rata-rata = %f\n", getAverageMatriks(M1));
	return 0;
}
