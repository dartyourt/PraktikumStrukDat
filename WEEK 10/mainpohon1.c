/* File : pohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : */
/* Tanggal : */

#include "pohon1.c"

int main () {
    //kamus
    bintree tree1;
    //algoritma
    tree1 = Tree('A', 
                    Tree('B', 
                        Tree('C', 
                            NIL, 
                            NIL), 
                        Tree('E', 
                            NIL, 
                            NIL)), 
                    Tree('C', 
                        NIL, 
                        Tree('Y', 
                            NIL, 
                            NIL))
                );
    
    printf("akar adalah: %c\n", GetAkar(tree1));
    printf("anak kiri adalah: %c\n", GetAkar(GetLeft(tree1)));
    printf("anak kanan adalah: %c\n", GetAkar(GetRight(tree1)));
    printf("is daun: %d\n", IsDaun(tree1));
    printf("is biner: %d\n", IsBiner(tree1));
    printf("is uner left: %d\n", IsUnerLeft(tree1));
    PrintPrefix(tree1);
    printf("jumlah elemen: %d\n", NbElm(tree1));
    printf("jumlah daun: %d\n", NbDaun(tree1));
    printf("tinggi: %d\n", Tinggi(tree1));
    printf("search x: %d\n", SearchX(tree1, 'D'));
    UpdateX(&tree1, 'D', 'Z');
    PrintPrefix(tree1);
    printf("\n");
    printf("count x: %d\n", CountX(tree1, 'Z'));
    printf("is skew left: %d\n", IsSkewLeft(tree1));
    printf("is skew right: %d\n", IsSkewRight(tree1));
    printf("level x: %d\n", LevelX(tree1, 'Z'));
    printf("count level t: %d\n", CountLevelT(tree1, 3));
    printf("daun paling kiri: %c\n", GetDaunTerkiri(tree1));
    printf("frekuensi x: %f\n", FrekuensiX(tree1, 'C'));
    printf("count vocal: %d\n", CountVocal(tree1));
    printf("modus: %c\n", Modus(tree1));
    return 0;
}