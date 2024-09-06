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
	getSize(T1);
	addXTable(&T1,6);
	addXTable(&T1,7);
	addXTable(&T1,9);
	addXTable(&T1,15);
	printf("%d", searchX(T,6));
	//printTable(T1);
	//delXTable(&T1,6);
	//printTable(T1);
	//dst ...
	return 0;
}
