/* File : main.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124140137 - Farhan Dwiyan Akbar */
/* Tanggal : 27 - November - 2025*/

#include "pohon1.h"
#include "pohon2.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    // kamus
    bintree B, C, BST;
    infotype E;

    // algoritma
    B = Tree('F', 
            Tree('I', 
                 Tree('H', 
                       Tree('L', NIL, NIL), 
                      NIL), 
                  NIL), 
            Tree('L', NIL, NIL));
    printf("==================================================\n");
    printf("            PROGRAM TESTING ADT TREE 2            \n");
    printf("==================================================\n");
    
    printf("\n==== PRINT TREE INDEN ====\n");
    printf("Pohon B:\n");
    PrintTreeInden(B, 3);
    printf("==================================================\n");

    printf("\n==== UPDATE ALL X ====\n");
    printf("Pohon B:\n");
    PrintTreeInden(B, 3);
    UpdateAllX(&B, 'L', 'E');
    printf("\nPohon B setelah update L -> E:\n");
    PrintTreeInden(B, 3);
    printf("==================================================\n");
    
    printf("\n==== ADD DAUN TERKIRI ====\n");
    printf("Pohon B:\n");
    PrintTreeInden(B, 3);
    AddDaunTerkiri(&B, 'L');
    printf("\nPohon B setelah menambah daun terkiri -> 'L':\n");
    PrintTreeInden(B, 3);
    printf("==================================================\n");

    printf("\n==== ADD DAUN ====\n");
    printf("Pohon B:\n");
    PrintTreeInden(B, 3);
    AddDaun(&B, 'E', 'H', !True);
    printf("\nPohon B setelah menambah daun -> 'H':\n");
    PrintTreeInden(B, 3);
    printf("==================================================\n");

    printf("\n==== INSERT X ====\n");
    printf("Pohon B:\n");
    PrintTreeInden(B, 3);
    InsertX(&B, 'H');
    printf("\nPohon B setelah menambah 'H' (sudah ada dalam pohon):\n");
    PrintTreeInden(B, 3);
    printf("==================================================\n");

    printf("\n==== DEL DAUN TERKIRI ====\n");
    printf("Pohon B:\n");
    PrintTreeInden(B, 3);
    DelDaunTerkiri(&B, &E);
    printf("\nPohon B setelah hapus daun terkiri\n");
    printf("Elemen yang terhapus: %c\n", E);
    PrintTreeInden(B, 3);
    printf("==================================================\n");

    printf("\n==== DEL DAUN ====\n");
    printf("Pohon B:\n");
    PrintTreeInden(B, 3);
    DelDaun(&B, 'E');
    printf("\nPohon B setelah hapus daun 'E':\n");
    PrintTreeInden(B, 3);
    printf("==================================================\n");

    printf("\n==== DELETE X ====\n");
    printf("Pohon B:\n");
    PrintTreeInden(B, 3);
    DeleteX(&B, 'I');
    printf("\nPohon B setelah hapus 'I' :\n");
    PrintTreeInden(B, 3);
    printf("==================================================\n");

    printf("\n==== BUILD BALANCE TREE ====\n");
    C = BuildBalanceTree(8);
    PrintTreeInden(C, 3);
    printf("==================================================\n");

    printf("\n==== IS BALANCE TREE ====\n");
    printf("Apakah pohon C balance: %d\n", IsBalanceTree(C));
    printf("Apakah pohon B balance: %d\n", IsBalanceTree(B));
    printf("==================================================\n");

    printf("\n==== MAX TREE ====\n");
    printf("Huruf 'maxsimal' pohon B: %c\n", maxTree(B));
    printf("Huruf 'maxsimal' pohon C: %c\n", maxTree(C));
    printf("==================================================\n");

    printf("\n==== MIN TREE ====\n");
    printf("Huruf 'minimal' pohon B: %c\n", minTree(B));
    printf("Huruf 'minimal' pohon C: %c\n", minTree(C));
    printf("==================================================\n");
    
    printf("\n==== B SEARCH ====\n");
    BST = Tree('M',
                Tree('C',
                     Tree('A', NIL, NIL),
                     Tree('F', NIL, NIL)
                ),
                Tree('T',
                     NIL,
                     Tree('Z', NIL, NIL)
                )
               );
    printf("BST:\n");
    PrintTreeInden(BST, 3);
    printf("\nApakah ada 'F' pada BST: %d\n", BSearch(BST, 'F'));
    printf("==================================================\n");
    
    printf("\n==== INS SEARCH ====\n");
    printf("BST:\n");
    PrintTreeInden(BST, 3);
    printf("\nBST setelah ditambah 'B':\n");
    BST = InsSearch(BST, 'B');
    PrintTreeInden(BST, 3);
    printf("==================================================\n");

    printf("\n==== DEL B TREE ====\n");
    printf("BST:\n");
    PrintTreeInden(BST, 3);
    DelBtree(&BST, 'B');
    printf("\nBST setelah dihapus 'B':\n");
    PrintTreeInden(BST, 3);
    printf("==================================================\n");
    
    
    return 0;
}