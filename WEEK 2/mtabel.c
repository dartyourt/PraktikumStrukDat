#include <stdio.h>
#include "tabel.c"
/*Deskripsi : driver ADT tabel integer*/
/* NIM/Nama : 24060123140151/Haidar Ali Laudza*/
/* Tanggal  : 06/09/2024*/

int main() {
	/*kamus*/
	Tabel T1;
	
	
	/*algoritma*/
	createTable(&T1);
	printf("%d\n", getSize(T1));
	addXTable(&T1,6);
	addXTable(&T1,7);
	addXTable(&T1,9);
	addXTable(&T1,15);
	printf("%d\n", searchX(T1,9));
	addXTable(&T1,10);
	addXTable(&T1,7);
	viewTable(T1);
	delXTable(&T1,6);
	viewTable(T1);
	delAllXTable(&T1,7);
	viewTable(T1);
	printf("%d\n", getSize(T1));
	printTable(T1);
	printf("%d\n", getSize(T1));
	printf("%d\n", countX(T1,10));
	viewTable(T1);
	populate2(&T1);
	viewTable(T1);
	printf("%d\n", getSize(T1));
	printf("%d\n", SumEl(T1));
	printf("%.2f\n", AverageEl(T1));
	//dst ...
	return 0;
}
