/* File : pohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : */
/* Tanggal : */

#include "pohon2.c"

int main () {
    //kamus
    bintree tree1, tree2;
    infotype Z;
    //algoritma
    tree1 = Tree('A', 
                    Tree('B', 
                        Tree('C', 
                            NIL, 
                            NIL), 
                        Tree('F', 
                            NIL, 
                            NIL)), 
                    Tree('F', 
                        NIL, 
                        Tree('D', 
                            NIL, 
                            NIL))
                );
    PrintTreeInden(tree1, 3);
    PrintLevel(tree1, 2);
    printf("\n");
    printf("#################################################################");
    printf("\n");
    //tree2 = BuildBalanceTree(4);
    //PrintTreeInden(tree2, 3);
    //PrintPrefix(tree2);
    printf("\n");
    printf("tree adalah: %s\n", IsBalanceTree(tree1) ? "seimbang" : "tidak seimbang");
    AddDaunTerkiri(tree1, 'Z');
    AddDaun(tree1, 'C', 'X', true);
    PrintTreeInden(tree1, 3);
    InsertX(&tree1, 'G');
    //PrintTreeInden(tree1, 3);
    PrintPrefix(tree1);
    printf("\n");
    printf("#############################################################");
    printf("\n");
    DelDaunTerkiri(&tree1, &Z);
    PrintTreeInden(tree1, 3);
    printf("elemen dihapus: %c\n", Z);
    DelDaun(&tree1, 'G');
    PrintTreeInden(tree1, 3);
    printf("max tree: %c\n", maxTree(tree1));
    printf("min tree: %c\n", minTree(tree1));
    return 0;
}