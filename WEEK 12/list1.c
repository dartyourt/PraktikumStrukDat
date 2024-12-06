/* File : list1.c */
/* Deskripsi : realisasi body ADT list berkait, representasi fisik pointer */
/* NIM & Nama : */
/* Tanggal : Oktober 2024 */
#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

/********* manajemen memori ********/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) {
	//kamus lokal
	address P;
	//algoritma
	P = (address) malloc(sizeof(Elm));
	if (P != NIL) { //ruang memori tersedia
		info(P) = E;
		next(P) = NIL;
	}
	return P;
}

/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke NIL  
	Proses: Melakukan pengosongan address P} */
void Dealokasi (address *P) {
	//kamus lokal
	
	//algoritma
	free(*P);
	*P = NIL;
}
/*********** OPERATORS ***********/
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List1)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List1 *L){
	//kamus lokal
	
	//algoritma
	First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List1) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List1 L){
	//kamus lokal

	//algoritma
	return First(L)==NIL;
}

/**************** PENELUSURAN ****************/
/*procedure PrintList(input L:List1)
{I.S. L terdefinisi; F.S. :-}
{Proses: menampilkan info semua elemen list L} */
void PrintList(List1 L){
	//kamus lokal
    address P;
    //algoritma
	P = First(L);
  	while (P != NIL) {
	 	 printf("\t%c",info(P));
	 	 P = next(P);
  	}
	printf("\n");
}

/*function NbElm(L:List1) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List1 L){
	//kamus lokal
	address P;
	int count;
	//algoritma
	P = First(L);
	count = 0;
	while (P != NIL) {
		count++;
		P = next(P);
	}
	return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List1 *L, infotype V ){
	//kamus lokal
	address P;
	//algoritma
	P = Alokasi(V);
	if (IsEmptyList(*L)) {
		First(*L) = P;

	}
	else {
		next(P) = First(*L);
		First(*L) = P;
	}
}

/*Procedure InsertVLast(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List1 *L, infotype V ){
	//kamus lokal
	address P, Last;
	//algoritma
	P = Alokasi(V);
	if (IsEmptyList(*L)) {
		First(*L) = P;
	}
	else {
		Last = First(*L);
		while (next(Last) != NIL) {
			Last = next(Last);
		}
		next(Last) = P;
	}

}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi,  }
{ F.S. L tetap, atau berkurang elemen pertamanya.
Proses: Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List1 *L, infotype *V){
	//kamus lokal
	address P;
	//algoritma
	if (!IsEmptyList(*L)) {
		P = First(*L);
		*V = info(P);
		First(*L) = next(P);
		Dealokasi(&P);
	}
	else {
		*V = '#';
	}
}

/*Procedure DeleteVLast(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi }
{ F.S. L tetap atau berkurang elemen terakhirnya.
Proses: Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List1 *L, infotype *V){
	//kamus lokal
	address Prec, Last;
	//algoritma
	if (!IsEmptyList(*L)) {
		Prec = First(*L);
		Last = First(*L);
		while (next(Last) != NIL) {
			Prec = Last;
			Last = next(Last);
		}
		*V = info(Last);
		next(Prec) = NIL;
		Dealokasi(&Last);
	}
	else {
		*V = '#';}


}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List1, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Proses: Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List1 L, infotype X, address *A){
	//kamus lokal
	address P;
	//algoritma
	P = First(L);
	while (P != NIL && info(P) != X) {
		P = next(P);
	}
	*A = P;
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Proses: Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(List1 *L, infotype X, infotype Y){
	//kamus lokal
	address P;
	//algoritma
	SearchX(*L, X, &P);
	if (P != NIL) {
		info(P) = Y;
	}
}

/*Procedure Invers(input/output L:List1)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {'i','t','u'} menjadi {'u','t','i'} }*/
void Invers(List1 *L){
	//kamus lokal
	address P, Prec, Last;
	//algoritma
	Prec = NIL;
	P = First(*L);
	while (P != NIL) {
		Last = P;
		P = next(P);
		next(Last) = Prec;
		Prec = Last;
	}
	First(*L) = Last;
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*function CountX(L:List1, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List1 L, infotype X){
	//kamus lokal
	address P;
	int countX;
	//algoritma
	P = First(L);
	countX = 0;
	while (P != NIL) {
		if (info(P) == X) {
			countX++;
		}
		P = next(P);
	}
	return countX;
}

/*function FrekuensiX(L:List1, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List1 L, infotype X){
	//kamus lokal
	
	//algoritma
	return (float) CountX(L, X) / NbElm(L);
}

/*Procedure SearchAllX(input L:List1, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi (1,2,3,...nbElm(L)) kemunculan elemen X dalam list L }*/
void SearchAllX(List1 L, infotype X){
	//kamus lokal
	address P;
	int i;
	//algoritma
	P = First(L);
	i = 1;
	while (P != NIL) {
		if (info(P) == X) {
			printf("%d ", i);
		}
		P = next(P);
		i++;
	}
	printf("\n");
}

/*Procedure UpdateAllX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau semua elemen bernilai X berubah menjadi Y. 
Proses : mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(List1 *L, infotype X, infotype Y){
	//kamus lokal
	address P;
	//algoritma
	P = First(*L);
	while (P!=NIL) {
		if (info(P)== X) {
			info(P) = Y;
		}
		P = next(P);
	}
}

/* Procedure InsertVAfter(input/output L:List1, input V:infotype, input VA:infotype )
{ I.S. List L mungkin kosong, V, S terdefinisi }
{ F.S. L tetap, atau bertambah 1 elemen (VA) pada posisi setelah elemen berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=VA sebagai elemen setelah elemen V list linier L yg mungkin kosong } */
void InsertVAfter(List1 *L, infotype V, infotype VA ){
	//kamus lokal
	address P, prec;
	//algoritma
	P=Alokasi (VA);
	SearchX(*L,V,&prec);
	if (prec!=NIL) {
		next(P)=next(prec);
		next(prec)=P;
	}
}

/*function MaxMember(L:List1) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List1 L){
	//kamus lokal
	address P;
	int max, count;
	//algoritma
	P = First(L);
	max = 0;
	while (P != NIL) {
		count = CountX(L, info(P));
		if (count > max) {
			max = count;
		}
		P = next(P);
	}
	return max;
}

/*function Modus(L:List1) -> infotype */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
infotype Modus(List1 L){
	//kamus lokal
	address P;
	//algoritma
	P = First(L);
	while (P != NIL) {
		if (CountX(L, info(P)) == MaxMember(L)) {
			return info(P);
		}
		P = next(P);
	}
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List1, input L2:List1, output L:List1)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List1 L1, List1 L2, List1 *L){
	//kamus lokal
	address P, Last;
	//algoritma
	CreateList(L);
	if (!IsEmptyList(L1)) {
		P = First(L1);
		while (P != NIL) {
			InsertVLast(L, info(P));
			P = next(P);
		}
	}
	if (!IsEmptyList(L2)) {
		P = First(L2);
		while (P != NIL) {
			InsertVLast(L, info(P));
			P = next(P);
		}
	}
}

/*Procedure SplitList(input L:List1, output L1:List1, output L2:List1)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List1 L, List1 *L1, List1 *L2){
	//kamus lokal
	address P;
	int i, n;
	//algoritma
	CreateList(L1);
	CreateList(L2);
	n = NbElm(L);
	P = First(L);
	i = 1;
	while (P != NIL) {
		if (i <= n/2) {
			InsertVLast(L1, info(P));
		}
		else {
			InsertVLast(L2, info(P));
		}
		P = next(P);
		i++;
	}
}

/*Procedure CopyList(input L1:List1, output L2:List1)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List1 L1, List1 *L2){
	//kamus lokal
	address P;
	//algoritma
	CreateList(L2);
	P = First(L1);
	while (P != NIL) {
		InsertVLast(L2, info(P));
		P = next(P);
	}
}
