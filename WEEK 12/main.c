/*Nama file:   */
/*Deskripsi:   */
/*Tanggal  :   */
/*Pembuat  :   */
#include "pohon3.c"
int main() {
	//kamus
	bintree3 W;
	
	//algoritma
      W = Tree3(NIL,'A',false,
              Tree3(W,'B',false, 
                    NIL, 
                    Tree3(left(W),'D',false,NIL,NIL)),
              Tree3(W,'C',false, 
                    Tree3(right(W),'E',false,NIL,NIL),
                    Tree3(right(W),'F',false,NIL,NIL)));
	printDFS(W);
      printf("\n");
	printPathX(W,'D');

	return 0;
}