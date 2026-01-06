/* File : pohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124140137 - Farhan Dwiyan Akbar */
/* Tanggal : 27 - November - 2025*/

#include "pohon1.h"
#include "pohon1.c"

#include <stdio.h>
#include <stdlib.h>

int main() { 
    //kamus
    bintree B, A, C;

    //algirtma
    B = Tree('T',
             Tree('I',
                  Tree('N',NIL,NIL),
                  Tree('F',
                       Tree('O',NIL,NIL),
                       NIL)),
             Tree('R',
                  Tree('M',
                       Tree('A',NIL,NIL),
                       Tree('T',NIL,NIL)),
                  Tree('I',
                       NIL,
                       Tree('K',
                            NIL,
                            Tree('A',NIL,NIL))))
            );
    printf("==================================================\n");
    printf("            PROGRAM TESTING ADT TREE 1            \n");
    printf("==================================================\n");

    printf("\n==== PRINT PREFIX ====\n");
    printf("Prefix dari pohon B:\n");
    PrintPrefix(B);

    printf("\n\nAnak kiri dari node T: %c", info(GetLeft(B)));
    printf("\nAnak kanan dari node T: %c", info(GetRight(B)));
    printf("\nApakah pohon B kosong: %d\n", IsEmptyTree(B));
    printf("==================================================\n");

    printf("\n==== IS DAUN DAN IS BINER ====\n");
    A = Tree('A', 
                Tree('B', NIL, NIL), 
                Tree('C', NIL, 
                                Tree('D', NIL, NIL)));
    printf("Prefix dari pohon A:\n");
    PrintPrefix(A);

    printf("\n\nApakah node B daun: %d", IsDaun(left(A)));
    printf("\nApakah node A biner: %d", IsBiner(A));
    printf("\n==================================================\n");

    printf("\n==== IS UNER RIGHT DAN IS UNER LEFT ====\n");
    printf("Prefix dari pohon:\n");
    PrintPrefix(A);
    printf("\n\nApakah node C isUnerRight: %d\n", IsUnerRight(right(A)));
    printf("Apakah node C isUnerLeft: %d", IsUnerLeft(right(A)));
	printf("\n==================================================\n");

    printf("\n==== NB ELEMENT  DAN NB DAUN ====\n");
    printf("Jumlah elemen dari pohon A: %d\n", NbElm(A));
    printf("Jumlah daun dari pohon A: %d", NbDaun(A));
    printf("\n==================================================\n");

    printf("\n==== TINGGI ====\n");
    printf("Tinggi pohon B: %d\n", Tinggi(B));
    printf("Tinggi pohon A: %d", Tinggi(A));
    printf("\n==================================================\n");

    printf("\n==== SEARCH X ====\n");
    printf("Apakah 'D' ada di pohon A: %d\n", SearchX(A, 'D'));
    printf("Apakah 'D' ada di pohon B: %d", SearchX(B, 'D'));
    printf("\n==================================================\n");

    printf("\n==== UPDATE X ====\n");
    printf("Prefix dari pohon A:\n");
    PrintPrefix(A);
    UpdateX(&A, 'D', 'F');
    printf("\n\nUbah 'D' -> 'F' di pohon A\n");
    printf("Prefix dari pohon A setelah update:\n");
    PrintPrefix(A);
    printf("\n==================================================\n");

    printf("\n==== COUNT X ====\n");
    printf("Jumlah node 'F' pada pohon A: %d", CountX(A, 'F'));
    printf("\nJumlah node 'T' pada pohon B: %d", CountX(B, 'T'));
    printf("\nJumlah node 'I' pada pohon B: %d", CountX(B, 'I'));
    printf("\n==================================================\n");

    printf("\n==== IS SKEW LEFT DAN IS SKEW RIGHT ====\n");
    C = Tree('F', 
            Tree('I', 
                 Tree('H', 
                       Tree('M', NIL, NIL), 
                      NIL), 
                  NIL), 
             NIL);
     printf("Prefix dari pohon C:\n");
     PrintPrefix(C);

     printf("\n\nApakah pohon C condong kiri: %d", IsSkewLeft(C));
     printf("\nApakah pohon C condong kanan: %d", IsSkewRight(C));
     printf("\n==================================================\n");

     printf("\n==== PRINT PREFIX RINGKAS ====\n");
     printf("Prefix dari pohon A:\n");
     PrintPrefixRingkas(A);
     printf("\n\nPrefix dari pohon B:\n");
     PrintPrefixRingkas(B);
     printf("\n\nPrefix dari pohon C:\n");
     PrintPrefixRingkas(C);
     printf("\n==================================================\n");

     printf("\n==== LEVEL X ====\n");
     printf("Level dari node 'M' di pohon C: %d", LevelX(C, 'M'));
     printf("\nLevel dari node 'Z' di pohon C: %d", LevelX(C, 'Z'));
     printf("\n==================================================\n");

     printf("\n==== COUNT LEVEL ====\n");
     printf("Banyaknya node pada level 3 di pohon B: %d\n", CountLevel(B, 3));
     printf("Banyaknya node pada level 2 di pohon C: %d", CountLevel(C, 2));
     printf("\n==================================================\n");

     printf("\n==== PRINT LEVEL ====\n");
     printf("Print level 3 pada pohon B:\n");
     PrintLevel(B, 3);
     printf("\n\nPrint level 2 pada pohon c:\n");
     PrintLevel(C, 2);
     printf("\n==================================================\n");

     printf("\n\n==== Get DAUN TERKIRI ====\n");
     printf("Daun terkiri dari pohon A: %c\n", GetDaunTerkiri(A));
     printf("Daun terkiri dari pohon B: %c\n", GetDaunTerkiri(B));
     printf("Daun terkiri dari pohon C: %c", GetDaunTerkiri(C));
     printf("\n==================================================\n");

     printf("\n==== FREKUENSI X ====\n");
     printf("Frekuensi X = T pada pohon B: %.2f\n", FrekuensiX(B, 'T'));
     printf("Frekuensi X = Z pada pohon B: %.2f", FrekuensiX(B, 'Z'));
     printf("\n==================================================\n");

     printf("\n==== COUNT VOCAL ====\n");
     printf("Banyaknya kemunculan huruf vocal di pohon A: %d\n", CountVocal(A));
     printf("Banyaknya kemunculan huruf vocal di pohon B: %d\n", CountVocal(B));
     printf("Banyaknya kemunculan huruf vocal di pohon C: %d", CountVocal(C));
     printf("\n==================================================\n");

     printf("\n==== PRINT VOCAL ====\n");
     printf("Huruf vocal pada pohon A: ");
     PrintVocal(A);
     printf("\nHuruf vocal pada pohon B: ");
     PrintVocal(B);
     printf("\nHuruf vocal pada pohon C: ");
     PrintVocal(C);
     printf("\n==================================================\n");

     printf("\n==== COUNT CONSONANT ====\n");
     printf("Banyaknya kemunculan huruf konsonan di pohon A: %d\n", CountConsonant(A));
     printf("Banyaknya kemunculan huruf konsonan di pohon B: %d\n", CountConsonant(B));
     printf("Banyaknya kemunculan huruf konsonan di pohon C: %d", CountConsonant(C));
     printf("\n==================================================\n");

     printf("\n==== PRINT CONSONANT ====\n");
     printf("Huruf konsonan pada pohon A: ");
     PrintConsonant(A);
     printf("\nHuruf konsonan pada pohon B: ");
     PrintConsonant(B);
     printf("\nHuruf konsonan pada pohon C: ");
     PrintConsonant(C);
     printf("\n==================================================\n");
     
     printf("\n==== MODUS ====\n");
     printf("Modus pada pohon A: %c\n", Modus(A));
     printf("Modus pada pohon B: %c\n", Modus(B));
     printf("Modus pada pohon C: %c", Modus(C));
     printf("\n==================================================\n");

     printf("\n============  SELESAI PROGRAM TESTING  ===========");
     return 0;
}