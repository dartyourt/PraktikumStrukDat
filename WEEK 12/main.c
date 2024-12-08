/*Nama file:   */
/*Deskripsi:   */
/*Tanggal  :   */
/*Pembuat  :   */
#include "pohon3.c"
int main() {
	//kamus
	bintree3 W;
      List1 L, J;
	
	//algoritma
      W = Tree3(NIL,'A',false,
              Tree3(W,'B',false, 
                    NIL, 
                    Tree3(left(W),'D',false,NIL,NIL)),
              Tree3(W,'C',false, 
                    Tree3(right(W),'E',false,NIL,NIL),
                    Tree3(right(W),'F',false,NIL,NIL)));
      printf("********************Print DFS********************\n");
	printDFS(W);
      printf("\n");
      printf("********************Print Path X********************\n");
	printPathX(W,'E');
      printf("\n");
      printf("********************Print Level********************\n");
      PrintLevel(W,3);
      printf("\n");
      printf("********************Print BFS********************\n");
      PrintBFS(W);
      printf("\n");
      printf("********************Print Path DaunX********************\n");
      printPathDaunX(W,'D');
      printf("\n");
      printf("********************Print ALL Path********************\n");
      printAllPaths(W);
      printf("\n");
      printf("********************Linear Prefix********************\n");
      L = LinearPrefix(W);
      PrintList(L);
      printf("\n");
      printf("********************Linear Posfix********************\n");
      J = LinearPosfix(W);
      PrintList(J);
      printf("\n");

	return 0;
}