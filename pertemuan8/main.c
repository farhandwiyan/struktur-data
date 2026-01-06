/* File : main.h */
/* Deskripsi : Driver ADT list berkait SIRKULAR  */
/* NIM & Nama : 24060124140137 - Farhan Dwiyan Akbar */
/* Tanggal : 13 November 2025 */

#include "list2.c"

int main() {
    /* kamus */
    List2 L1, Senarai, LGabungan, LSplit1, LSplit2, LCopy;
    address A;
    infotype V;

    /* algoritma */
    printf("==================================================\n");
    printf("    PROGRAM TESTING ADT LIST BERKAIT SIRKULAR     \n");
    printf("==================================================\n");

    printf("\n=== TEST CREATE LIST ===\n");
    CreateList(&L1);
    PrintList(L1);
    printf("\n\nApakah list kosong : %d\n", IsEmptyList(L1));
    printf("List berjumlah : %d\n", NbElm(L1));
    printf("==================================================\n");

    printf("\n=== TEST INSERTVFIRST ===\n");
    InsertVFirst(&L1, 'D');
    PrintList(L1);
    printf("\n\nApakah list kosong : %d\n", IsEmptyList(L1));
    printf("List berjumlah : %d\n", NbElm(L1));
    printf("==================================================\n");
    
    printf("\n=== TEST INSERTVFIRST LAGI ===\n");
    InsertVFirst(&L1, 'A');
    InsertVFirst(&L1, 'N');
    PrintList(L1);
    printf("\n\nApakah list kosong : %d\n", IsEmptyList(L1));
    printf("List berjumlah : %d\n", NbElm(L1));
    printf("==================================================\n");
    
    printf("\n=== TEST INSERTVLAST ===\n");
    InsertVLast(&L1, 'F');
    InsertVLast(&L1, 'Z');
    InsertVLast(&L1, 'H');
    InsertVLast(&L1, 'A');
    PrintList(L1);
    printf("\n\nApakah list kosong : %d\n", IsEmptyList(L1));
    printf("List berjumlah : %d\n", NbElm(L1));
    printf("==================================================\n");

    printf("\n=== TEST DELETEVFIRST ===\n");
    DeleteVFirst(&L1, &V);
    printf("Elemen pertama yang dihapus: %c\n", V);
    PrintList(L1);
    DeleteVFirst(&L1, &V);
    printf("\n\nElemen pertama yang dihapus: %c\n", V);
    PrintList(L1);
    printf("\n==================================================\n");

    printf("\n=== TEST DELETEVLAST ===\n");
    DeleteVLast(&L1, &V);
    printf("Elemen terakhir yang dihapus: %c\n", V);
    PrintList(L1);
    DeleteVLast(&L1, &V);
    printf("\n\nElemen terakhir yang dihapus: %c\n", V);
    PrintList(L1);
    printf("\n==================================================\n");

    printf("\n=== TEST DELETEX ===\n");
    // tambahkan elemen baru terlebih dahulu
    InsertVFirst(&L1, 'E');
    InsertVFirst(&L1, 'R');
    printf("Isi List sekarang:\n");
    PrintList(L1);

    DeleteX(&L1, 'R');
    printf("\n\nSetelah elemen 'R' (pertama) dihapus\n");
    PrintList(L1);
    printf("\n==================================================\n");
    DeleteX(&L1, 'F');
    printf("Setelah elemen 'F' (tengah) dihapus\n");
    PrintList(L1);
    printf("\n==================================================\n");
    DeleteX(&L1, 'Z');
    printf("Setelah elemen 'Z' (akhir) dihapus\n");
    PrintList(L1);
    printf("\n==================================================\n");

    printf("\n=== TEST SEARCHX ===\n");
    printf("Isi List sekarang:\n");
    PrintList(L1);
    
    SearchX(L1, 'D', &A);
    printf("\n\nMencari elemen 'D'\n");
    if (A != NIL) {
        printf("Elemen 'D' ditemukan.");
    } else {
        printf("Elemen 'D' tidak ditemukan.");
    }
    printf("\n==================================================\n");

    printf("\n=== TEST UPDATEX ===\n");
    printf("Isi List sekarang:\n");
    PrintList(L1);
    printf("\n\nUbah elemen 'D' menjadi 'F'\n");
    UpdateX(&L1, 'D', 'F');
    printf("\nIsi list setelah UpdateX('D' -> 'F'):\n");
    PrintList(L1);
    printf("\n==================================================\n");
    printf("Ubah elemen 'X' menjadi 'M' (tidak ada di list)\n");
    UpdateX(&L1, 'X', 'M');
    printf("\nIsi list setelah mencoba UpdateX('X' -> 'M'):\n");
    PrintList(L1);
    printf("\n==================================================\n");

    printf("\n=== TEST INVERS ===\n");
    printf("Isi list sebelum invers:\n");
    PrintList(L1);
    Invers(&L1);
    printf("\nIsi list setelah invers:\n");
    PrintList(L1);
    printf("\n==================================================\n");

    printf("\n=== TEST COUNTX===\n");
    // tambahkan elemen baru terlebih dahulu
    InsertVLast(&L1, 'D');
    InsertVLast(&L1, 'E');
    InsertVLast(&L1, 'A');
    InsertVLast(&L1, 'I');
    InsertVLast(&L1, 'L');
    InsertVLast(&L1, 'E');
    printf("Isi List sekarang:\n");
    PrintList(L1);
    printf("\n\nJumlah kemunculan huruf 'E': %d", CountX(L1, 'E'));
    printf("\nJumlah kemunculan huruf 'R' (tidak ada dalam list): %d", CountX(L1, 'R'));
    printf("\n==================================================\n");

    printf("\n=== TEST FREKUENSIX ===\n");
    printf("Isi List sekarang:\n");
    PrintList(L1);
    printf("\n\nFrekuensiX untuk X='E' adalah %.2f", FrekuensiX(L1, 'E'));
    printf("\nFrekuensiX untuk X='L' adalah %.2f", FrekuensiX(L1, 'L'));
    printf("\nFrekuensiX untuk X='W' (tidak ada dalam list) adalah %.2f", FrekuensiX(L1, 'W'));
    printf("\n==================================================\n");

    printf("\n=== TEST COUNTVOCAL ===\n");
    printf("Isi list sekarang:\n");
    PrintList(L1);
    printf("\n\nJumlah kemunculan huruf vocal: %d\n", CountVocal(L1));
    printf("==================================================\n");

    printf("\n=== TEST COUNTNG ===\n");
    printf("Isi list sekarang:\n");
    PrintList(L1);
    printf("\n\nJumlah kemunculan huruf NG: %d\n", CountNG(L1));
    printf("==================================================\n");
    printf("Tambahkan elemen 'N' dan 'G'\n");
    InsertVLast(&L1, 'N');
    InsertVLast(&L1, 'G');
    InsertVFirst(&L1, 'G');
    InsertVFirst(&L1, 'N');
    printf("\nIsi list setelah insert:\n");
    PrintList(L1);
    printf("\n\nJumlah kemunculan huruf NG: %d\n", CountNG(L1));
    printf("==================================================\n");

    printf("\n=== TEST INSERTVAFTERX ===\n");
    printf("Isi list awal:\n");
    PrintList(L1);
    printf("\n\nInsert 'M' setelah 'E'\n");
    InsertVAfterX(&L1, 'E', 'M');
    printf("Isi list setelah insert:\n");
    PrintList(L1);
    printf("\n==================================================\n");

    printf("\n=== TEST INSERTVBEFOREX ===\n");
    printf("Isi list awal:\n");
    PrintList(L1);
    printf("\n\nInsert 'S' sebelum 'N'\n");
    InsertVBeforeX(&L1, 'N', 'S');
    printf("Isi list setelah insert:\n");
    PrintList(L1);
    printf("\n==================================================\n");

    printf("\n=== TEST DELETEVAFTERX ===\n");
    printf("Isi list awal:\n");
    PrintList(L1);
    printf("\n\nDelete setelah 'N'\n");
    DeleteVAfterX(&L1, 'N', &V);
    printf("Elemen yang di hapus: %c", V);
    printf("\n\nDelete setelah 'I'\n");
    DeleteVAfterX(&L1, 'I', &V);
    printf("Elemen yang di hapus: %c", V);
    printf("\n\nIsi list setelah delete:\n");
    PrintList(L1);
    printf("\n==================================================\n");

    printf("\n=== TEST DELETEVBEFOREX ===\n");
    printf("Isi list awal:\n");
    PrintList(L1);
    printf("\n\nDelete sebelum 'N'\n");
    DeleteVBeforeX(&L1, 'N', &V);
    printf("Elemen yang di hapus: %c", V);
    printf("\n\nDelete sebelum 'D'\n");
    DeleteVBeforeX(&L1, 'D', &V);
    printf("Elemen yang di hapus: %c", V);
    printf("\n\nIsi list setelah delete:\n");
    PrintList(L1);
    printf("\n==================================================\n");

    printf("\n=== TEST DELETEVALLX ===\n");
    printf("Isi list awal:\n");
    PrintList(L1);
    printf("\n\nDeleteAll 'E'");
    DeleteAllX(&L1, 'E');
    printf("\nIsi list setelah delete:\n");
    PrintList(L1);
    printf("\n\nDeleteAll 'A'");
    DeleteAllX(&L1, 'A');
    printf("\nIsi list setelah delete:\n");
    PrintList(L1);
    printf("\n==================================================\n");

    printf("\n=== TEST SEARCHALLX ===\n");
    printf("Isi list sekarang:\n");
    PrintList(L1);
    printf("\n\nCari Elemen 'N' dalam list'\n");
    SearchAllX(L1, 'N');
    printf("\n==================================================\n");
    printf("Cari Elemen 'B' (B tidak ada di dalam list)\n");
    SearchAllX(L1, 'B');
    printf("\n==================================================\n");

    printf("\n=== TEST MAXMEMBER ===\n");
    printf("Isi list sekarang:\n");
    PrintList(L1);
    printf("\n\nJumlah kemunculan huruf yang paling banyak muncul: %d\n", MaxMember(L1));
    printf("==================================================\n");

    printf("\n=== TEST MODUS ===\n");
    printf("Isi list sekarang:\n");
    PrintList(L1);
    printf("\n\nElemen modus pada list: %c\n", Modus(L1));
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

    printf("List L1:\n");
    PrintList(L1);
    printf("\n\nList L2:\n");
    PrintList(Senarai);
    ConcatList(L1, Senarai, &LGabungan);
    printf("\n\nList yang telah digabung:\n");
    PrintList(LGabungan);
    printf("\n==================================================\n");

    printf("\n=== TEST SPLITLIST ===\n");
    printf("Isi list:\n");
    PrintList(LGabungan);
    printf("\n\nIsi list setelah split\n");
    SplitList(LGabungan, &LSplit1, &LSplit2);
    printf("Isi list L1:\n");
    PrintList(LSplit1);
    printf("\n\nIsi list L2:\n");
    PrintList(LSplit2);
    printf("\n==================================================\n");

    printf("\n=== TEST COPYLIST ===\n");
    printf("Isi list asal:\n");
    PrintList(Senarai);
    CopyList(Senarai, &LCopy);
    printf("\n\nIsi list LCopy:\n");
    PrintList(LCopy);
    printf("\n==================================================\n");

    printf("\n============  SELESAI PROGRAM TESTING  ===========");
    return 0;
}