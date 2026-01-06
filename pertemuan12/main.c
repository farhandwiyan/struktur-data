/* File       : main.c */
/* Deskripsi  : Pohon3 */
/* NIM/Nama   : 24060124140137 - Farhan Dwiyan Akbar */
/* Tanggal    : 11 - 12 - 2025 */

#include <stdio.h>
#include <stdlib.h>

#include "pohon3.h"
#include "list1.h"

int main() {
    // Kamus Lokal
    List1 L1, L2, L3;
    bintree3 W, B, C, D, E, F, G, H, I, J, K;

    // Algoritma
    W = Tree3(NIL, 'A', False, NIL, NIL);   
    B = Tree3(W, 'B', False, NIL, NIL);
    C = Tree3(W, 'C', False, NIL, NIL);
    left(W) = B;
    right(W) = C;

    D = Tree3(B, 'D', False, NIL, NIL);
    right(B) = D;

    E = Tree3(C, 'E', False, NIL, NIL);
    F = Tree3(C, 'F', False, NIL, NIL);
    left(C) = E;
    right(C) = F;

    G = Tree3(D, 'G', False, NIL, NIL);
    H = Tree3(E, 'H', False, NIL, NIL);
    I = Tree3(F, 'I', False, NIL, NIL);
    left(D) = G;
    right(E) = H;
    right(F) = I;

    J = Tree3(I, 'J', False, NIL, NIL);
    K = Tree3(I, 'K', False, NIL, NIL);
    left(I) = J;
    right(I) = K;

    printf("==================================================\n");
    printf("            PROGRAM TESTING ADT TREE 3            \n");
    printf("==================================================\n");

    printf("\n==== PRINT DFS ====\n");
    printf("Pohon W:\n");
    printDFS(W);
    printf("\n==================================================\n");

    
    printf("\n==== TINGGI ====\n");
    printf("Tinggi pohon: %d", Tinggi(W));
    printf("\n==================================================\n");
    
    printf("\n==== PRINT BFS ====\n");
    printf("Pohon W:\n");
    PrintBFS(W);
    printf("\n==================================================\n");
    
    printf("\n==== PRINT PATH X ====\n");
    printf("Path menuju node 'C': ");
    printPathX(W, 'C');
    printf("\n==================================================\n");

    printf("\n==== PRINT PATH DAUN X ====\n");
    printf("Path menuju node daun 'K': ");
    printPathDaunX(W, 'K');
    printf("\n==================================================\n");

    printf("\n==== PRINT ALL PATHS ====\n");
    printf("Path menuju semua daun pohon W: ");
    printAllPaths(W);
    printf("\n==================================================\n");

    printf("\n==== NB ELEMENT TREE ====\n");
    printf("Banyaknya elemen pohon W: %d", NbElmTree(W));
    printf("\n==================================================\n");

    printf("\n==== NB DAUN ====\n");
    printf("Banyaknya daun pohon W: %d", NbDaun(W));
    printf("\n==================================================\n");

    printf("\n==== LEVEL ====\n");
    printf("Level pohon W: %d", Level(W));
    printf("\n==================================================\n");

    printf("\n==== COUNT LEVEL T ====\n");
    printf("Banyaknya node di level 3 pohon W: %d", CountLevelT(W, 3));
    printf("\n==================================================\n");

    printf("\n==== P CONCAT ====\n");
    CreateList(&L1);
    InsertVLast(&L1, 'A');
    InsertVLast(&L1, 'B');
    InsertVLast(&L1, 'C');
    InsertVLast(&L1, 'D');
    
    CreateList(&L2);
    InsertVLast(&L2, 'E');
    InsertVLast(&L2, 'F');

    printf("L1:");
    PrintList(L1);
    printf("\nL2:");
    PrintList(L2);
    Pconcat(&L1, L2);
    printf("\nList 1 setelah concat:");
    PrintList(L1);
    printf("==================================================\n");

    printf("\n==== F CONCAT ====\n");
    CreateList(&L3);
    InsertVLast(&L3, 'G');
    InsertVLast(&L3, 'H');
    InsertVLast(&L3, 'I');

    printf("L2:");
    PrintList(L2);
    printf("\nL3:");
    PrintList(L3);
    printf("\nList setelah concat:");
    PrintList(Fconcat(L2, L3));
    printf("==================================================\n");

    printf("\n==== LINEAR PREFIX ====\n");
    printf("List prefix pohon W:");
    PrintList(LinearPrefix(W));
    printf("==================================================\n");

    printf("\n==== LINEAR POSFIX ====\n");
    printf("List posfix pohon W:");
    PrintList(LinearPosfix(W));
    printf("==================================================\n");

    printf("\n==== LINEAR INFIX ====\n");
    printf("List infix pohon W:");
    PrintList(LinearInfix(W));
    printf("==================================================\n");

    printf("\n==== LINEAR INFIX ====\n");
    printf("List BFS pohon W:");
    PrintList(LinearBreadthFS(W));
    printf("==================================================\n");
    
    return 0;
}