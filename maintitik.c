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
	Titik B;
	
	//algoritma
	printf("Halo, ini driver modul Titik \n");
	makeTitik(&A);
	makeTitik(&B);
	printf("Nilai absis A = %d\n",getAbsis(A));
	printf("Nilai ordinat A = %d\n",getOrdinat(A));
	printf("Nilai absis B = %d\n",getAbsis(B));
	printf("Nilai ordinat B = %d\n",getOrdinat(B));
	printf("====================================\n");
	setAbsis(&A, 5);
	setOrdinat(&A, 10);
	printf("Nilai absis A = %d\n",getAbsis(A));
	printf("Nilai ordinat A = %d\n",getOrdinat(A));
	setAbsis(&B, 10);
	setOrdinat(&B, 5);
	printf("Nilai absis B = %d\n",getAbsis(B));
	printf("Nilai ordinat B = %d\n",getOrdinat(B));
	printf("====================================\n");
	geserXY(&A, 5, -3);
	printf("Nilai absis A setelah digeser = %d\n",getAbsis(A));
	printf("Nilai ordinat A setelah digeser = %d\n",getOrdinat(A));
	printf("====================================\n");
	refleksiSumbuX(&B);
	printf("Nilai absis B setelah direfleksi = %d\n",getAbsis(B));
	printf("Nilai ordinat B setelah direfleksi = %d\n",getOrdinat(B));
	printf("====================================\n");
	refleksiSumbuY(&A);
	printf("Nilai absis A setelah direfleksi = %d\n",getAbsis(A));
	printf("Nilai ordinat A setelah direfleksi = %d\n",getOrdinat(A));
	printf("====================================\n");
	printf("Titik A berada di kuadran %d\n", Kuadran(A));
	printf("Titik B berada di kuadran %d\n", Kuadran(B));
	printf("================================\n");
	printf("jarak titik A dan B adalah %f\n", JarakTitik(A,B));
	printf("================================\n");



	return 0;
}
