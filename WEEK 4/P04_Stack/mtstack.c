/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include "tstack.c"
/* include tstack+boolean */

boolean isPalindrom(char kata[]){
	Tstack pal;
	int i;

	int length = strlen(kata);
	createStack(&pal);
	int half = length / 2;
	for (i = 0; i < half; i++)
	{
		push(&pal, kata[i]);
	}
	if (length % 2 != 0)
	{
		i++;
	}
	while (kata[i] != '\0')
	{
		char poppedValue;
		pop(&pal, &poppedValue);
		if (poppedValue != kata[i])
		{
			return false;
		}
		i++;

	}
	return true;

}

int main() 
{	/* kamus main */
	Tstack A; // variabel A bertipe tStack
	
	/* algoritma */
	createStack( &A );
	printf("top = %d\n", top(A));
	printf("infotop = %c\n", infotop(A));
	push( &A, 'A');
	push( &A, 'B');
	push( &A, 'C');
	push( &A, 'D');
	printf("top = %d\n", top(A));
	printf("infotop = %c\n", infotop(A));
	printStack(A);
	viewStack(A);
	char poppedValue;
	pop( &A, &poppedValue);
	printf("Popped value: %c\n", poppedValue);
	viewStack(A);
	char str[] = "kasur 
	rusak";
	if (isPalindrom(str))
	{
		printf("String is palindrom\n");
	}
	else
	{
		printf("String is not palindrom\n");
	}
	
	
	return 0;
}
