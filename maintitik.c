/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/
#include <stdio.h>
#include "titik.c"

int main() {
	//kamus main
	Titik A;
	
	//algoritma
	printf("Halo, ini driver modul Titik \n");
	makeTitik(&A);
	setAbsis(&A,3);
	printf("\nNilai absis = %d",A.absis);
	
	return 0;
}
