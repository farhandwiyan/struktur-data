/* Program   : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM/Nama  : 24060124140137 - Farhan Dwiyan Akbar */
/* Tanggal   : 6 November 2025 */
/***********************************/

#include "list1.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Kamus lokal
    List1 L, Senarai, LGabungan, LSplit1, LSplit2, LCopy;
    infotype X, Y, V;
    address A;

    // Algoritma
    printf("==================================================\n");
    printf("        PROGRAM TESTING ADT LIST BERKAIT I        \n");
    printf("==================================================\n");

    printf("\n=== TEST CREATE LIST ===\n");
    CreateList(&L);
    PrintList(L);
    printf("\nApakah list kosong : %d\n", IsEmptyList(L));
    printf("==================================================\n");

    printf("=== TEST INSERT FIRST ===\n");
    InsertVFirst(&L, 'P');
    printf("Isi list sekarang: ");
    PrintList(L);
    printf("\nJumlah element list: %d\n", NbElm(L));
    printf("==================================================\n");

    printf("\n=== TEST INSERT LAST ===\n");
    InsertVLast(&L, 'Q');
    InsertVLast(&L, 'R');
    InsertVLast(&L, 'S');
    InsertVLast(&L, 'T');
    printf("Isi list sekarang: ");
    PrintList(L);
    printf("\nJumlah element list: %d\n", NbElm(L));
    printf("==================================================\n");

    printf("\n=== TEST INSERT 'O' FIRST LAGI ===");
    InsertVFirst(&L, 'O');
    PrintList(L);
    printf("==================================================\n");

    printf("Jumlah elemen dalam list: %d\n", NbElm(L));
    printf("==================================================\n");

    printf("\n=== TEST UPDATEX ===\n");
    printf("Ubah elemen 'R' menjadi 'Z'\n");
    UpdateX(&L, 'R', 'Z');
    printf("Isi list setelah UpdateX('R' -> 'Z'):\n");
    PrintList(L);
    printf("==================================================\n");

    printf("Ubah elemen 'X' menjadi 'M' (tidak ada di list)\n");
    UpdateX(&L, 'X', 'M');
    printf("Isi list setelah mencoba UpdateX('X' -> 'M'):\n");
    PrintList(L);
    printf("==================================================\n");

    printf("\n=== TEST SEARCHX ===\n");
    printf("Mencari elemen 'S'\n");
    SearchX(L, 'S', &A);
    if (A != NIL) {
        printf("Elemen 'S' ditemukan.\n");
    } else {
        printf("Elemen 'S' tidak ditemukan.\n");
    }
    printf("==================================================\n");

    printf("\n=== TEST DELETE ELEMENT ===\n");
    DeleteVFirst(&L, &V);
    printf("Elemen pertama yang dihapus: %c\n", V);
    printf("Isi list setelah penghapusan: ");
    PrintList(L);
    DeleteVLast(&L, &V);
    printf("Elemen terakhir yang dihapus: %c\n", V);
    printf("Isi list setelah penghapusan: ");
    PrintList(L);
    printf("==================================================\n");

    printf("\n=== TEST COUNTVOCAL ===\n");
    InsertVLast(&L, 'I');   // insert huruf vocal 'I' ke dalam list
    printf("Isi list: ");
    PrintList(L);
    printf("\nJumlah kemunculan huruf vocal: %d\n", CountVocal(L));
    printf("==================================================\n");

    printf("\n=== TEST COUNTX ===\n");
    printf("Isi list: ");
    PrintList(L);
    printf("\nJumlah kemunculan huruf 'Q': %d\n", CountX(L, 'Q'));
    printf("==================================================\n");

    printf("Cari jumlah kemunculan huruf 'A' (A tidak ada dalam list)\n");
    printf("Jumlah kemunculan huruf 'A': %d\n", CountX(L, 'A'));
    printf("==================================================\n");

    printf("\n=== TEST FREKUENSIX ===\n");
    printf("Isi list:");
    PrintList(L);
    printf("FrekuensiX untuk V='S' adalah %.2f", FrekuensiX(L, 'S'));
    printf("\n==================================================\n");

    printf("Hitung FrekuensiX untuk V='Q' (Q ada lebih dari 1)\n");
    InsertVFirst(&L, 'Q');  // insert nilai Q diawal List
    InsertVLast(&L, 'Q');   // insert nilai Q diakhir List
    printf("Isi list setelah insert Q:\n");
    PrintList(L);
    printf("\nFrekuensiX untuk V='Q' adalah %.2f", FrekuensiX(L, 'Q'));
    printf("\n==================================================\n");

    printf("Hitung FrekuensiX untuk V='A' (A tidak ada dalam list)\n");
    printf("FrekuensiX untuk V='A' adalah %.2f", FrekuensiX(L, 'A'));
    printf("\n==================================================\n");

    printf("\n=== TEST SEARCHALLX ===\n");
    printf("Isi list:");
    PrintList(L);
    printf("\nCari Elemen 'Q' dalam list'\n");
    SearchAllX(L, 'Q');
    printf("\n==================================================\n");

    printf("Cari Elemen 'B' (B tidak ada di dalam list)\n");
    SearchAllX(L, 'B');
    printf("\n==================================================\n");

    printf("\n=== TEST UPDATEALLX ===\n");
    printf("Isi list awal:");
    PrintList(L);
    printf("\nUbah elemen 'Q' menjadi 'F'\n");
    UpdateAllX(&L, 'Q', 'F');
    printf("Isi list setelah UpdateX('Q' -> 'F')\n");
    PrintList(L);
    printf("==================================================\n");

    printf("Ubah elemen 'A' menjadi 'C' (A tidak ada dalam list)\n");
    UpdateAllX(&L, 'A', 'C');
    printf("Isi list setelah UpdateX('A' -> 'C')\n");
    PrintList(L);
    printf("==================================================\n");

    printf("\n=== TEST UPDATEALLX ===\n");
    printf("Isi list awal:");
    PrintList(L);
    printf("\nInsert 'E' setelah 'F'\n");
    InsertVAfter(&L, 'F', 'E');
    printf("Isi list setelah insert:\n");
    PrintList(L);
    printf("==================================================\n");

    printf("Insert 'L' setelah 'M' (M tidak ada dalam list)\n");
    UpdateAllX(&L, 'M', 'L');
    printf("Isi list setelah insert:\n");
    PrintList(L);
    printf("==================================================\n");

    printf("\n=== TEST MODUS ===\n");
    printf("Isi list:");
    PrintList(L);
    printf("\nElemen modus pada list: %c\n", Modus(L));
    printf("==================================================\n");

    printf("\n=== TEST NBMODUS ===\n");
    printf("Isi list:");
    PrintList(L);
    printf("\nJumlah elemen modus pada list: %d\n", NbModus(L));
    printf("==================================================\n");

    printf("\n=== TEST INVERS ===\n");
    printf("Isi list sebelum invers:");
    PrintList(L);
    Invers(&L);
    printf("\nIsi list setelah invers:");
    PrintList(L);
    printf("==================================================\n");

    printf("\n=== TEST CONCATLIST ===\n");
    // buat dan insert ke Senarai
    CreateList(&Senarai);
    InsertVLast(&Senarai, 'A');
    InsertVLast(&Senarai, 'B');
    InsertVLast(&Senarai, 'C');
    InsertVLast(&Senarai, 'D');
    InsertVLast(&Senarai, 'E');
    InsertVLast(&Senarai, 'F');

    printf("List L1:");
    PrintList(L);
    printf("\nList L2:");
    PrintList(Senarai);
    ConcatList(L, Senarai, &LGabungan);
    printf("\nList yang telah digabung:");
    PrintList(LGabungan);
    printf("==================================================\n");

    printf("\n=== TEST SPLITLIST ===\n");
    printf("Isi list:");
    PrintList(LGabungan);
    printf("\nIsi list setelah split\n");
    SplitList(LGabungan, &LSplit1, &LSplit2);
    printf("Isi list L1:\n");
    PrintList(LSplit1);
    printf("\nIsi list L2:\n");
    PrintList(LSplit2);
    printf("==================================================\n");

    printf("\n=== TEST COPYLIST ===\n");
    printf("Isi list asal:");
    PrintList(Senarai);
    printf("\nIsi list copy-an\n");
    CopyList(Senarai, &LCopy);
    printf("Isi list LCopy:\n");
    PrintList(LCopy);
    printf("==================================================\n");

    printf("\n============  SELESAI PROGRAM TESTING  ===========");

    return 0;
}
