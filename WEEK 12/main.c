/*Nama file:   */
/*Deskripsi:   */
/*Tanggal  :   */
/*Pembuat  :   */
#include "pohon3.c"
int main() {
	//kamus
	bintree3 W, WL, WR, WLD, WRE, WRF;
;
      List1 L, J;
	
	//algoritma
      /*W = Tree3(NIL,'A',false,
              Tree3(W,'B',false, 
                    NIL, 
                    Tree3(left(W),'D',false,NIL,NIL)),
              Tree3(W,'C',false, 
                    Tree3(right(W),'E',false,NIL,NIL),
                    Tree3(right(W),'F',false,NIL,NIL)));*/
      WLD = Tree3(NIL, 'D', false, NIL, NIL);
      WL = Tree3(NIL, 'B', false, NIL, WLD);
      WRE = Tree3(NIL, 'E', false, NIL, NIL);
      WRF = Tree3(NIL, 'F', false, NIL, NIL);
      WR = Tree3(NIL, 'C', false, WRE, WRF);
      W = Tree3(NIL, 'A', false, WL, WR);

      if (WLD != NIL){ 
            parent(WLD) = WL;
      }
      if (WL  != NIL){
            parent(WL)  = W;
      }
      if (WRE != NIL){
            parent(WRE) = WR;
      }
      if (WRF != NIL){
            parent(WRF) = WR;
      }
      if (WR  != NIL){
            parent(WR) = W;
      }
      
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
      printf("********************Linear Infix********************\n");
      J = LinearInfix(W);
      PrintList(J);
      printf("\n");
      printf("********************Level********************\n");
      printf("%d\n", Level(W));
      printf("********************Count Level T********************\n");
      printf("%d\n", CountLevelT(W,2));
      printf("********************Liner Breadth********************\n");
      L = LinearBreadthFS(W);
      PrintList(L);
      printf("\n");
	return 0;
}