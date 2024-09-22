/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include "tstack.h"
/* include tstack+boolean */

void createStack (Tstack *T)
    { /*kamus lokal*/
      int i;
    /*algoritma*/
    (*T).top = 0;
    for (i=1; i<=10; i++)
        (*T).wadah[i] = ' ';
    }

/*function top( T: Tstack) -> integer
	{mengembalikan posisi puncak stack } */
//int top (Tstack T);
//dalam praktikum ini, fungsi dapat direalisasikan
//menjadi macro dalam bahasa C.
#define top(T) (T).top

/*function infotop( T: Tstack) -> character
	{mengembalikan nilai elemen top stack } */
//char infotop (Tstack T);
#define infotop(T) (T).wadah[(T).top]

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T)
    { /*kamus lokal*/
    /*algoritma*/
    return (top(T) == 0);
    }

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T)
    { /*kamus lokal*/
    /*algoritma*/
    return (top(T) == 10);
    }

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E)
    { /*kamus lokal*/
    /*algoritma*/
    if (!isFullStack(*T))
        { top(*T)++;
          infotop(*T) = E;
        }
    }

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X)
    { /*kamus lokal*/
    /*algoritma*/
    if (!isEmptyStack(*T))
        { *X = infotop(*T);
          top(*T)--;
        }
    }

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T)
    { /*kamus lokal*/
      int i;
    /*algoritma*/
    for (i=1; i<=10; i++)
        printf("%c;", T.wadah[i]);
    printf("\n");
    }

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T)
    { /*kamus lokal*/
      int i;
    /*algoritma*/
    for (i=1; i<=top(T); i++)
        printf("%c;", T.wadah[i]);
    printf("\n");
    }

/* selanjutnya tugas algoritma palindrom dikerjakan di main */

	
/* kerjakan prosedur berikut bila tugas palindrom sudah sukses */

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN (Tstack *T, int N)
    { /*kamus lokal*/
      int i;
      char X;
    /*algoritma*/
    for (i=1; i<=N; i++)
        { 
          if (!isFullStack(*T)) {
              scanf(" %c", &X); // Added space before %c to consume any whitespace
              push(T, X);
          } else {
              printf("Stack is full. Cannot push more elements.\n");
              break;
          }
        }
    }

/*procedure pushBabel1 ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) bila belum penuh atau menjadi kosong bila stack penuh }
	{Proses: menumpuk top atau menghapus semua elemen }*/
void pushBabel1 (Tstack *T, char E)
    { /*kamus lokal*/
    /*algoritma*/
    if (!isFullStack(*T))
        push(T, E);
    else
        while (!isEmptyStack(*T))
            pop(T, &E);
    }

/*procedure pushZuma ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) atau berkurang 1 elemen bila E bernilai sama dengan top }
	{Proses: menumpuk top atau menghapus elemen top }
    {contoh: T=['A','B','C'], E='C' menjadi T=['A','B']}*/
void pushZuma (Tstack *T, char E)
    { /*kamus lokal*/
      char X;
    /*algoritma*/
    if (!isEmptyStack(*T))
        if (E == infotop(*T))
            pop(T, &X);
        else
            push(T, E);
    else
        push(T, E);
    }
