/* File : main.c */
/* Deskripsi : ADT list berkait dengan representasi fisik pointer  */
/* NIM & Nama : 24060124140137 - Farhan Dwiyan Akbar */
/* Tanggal : 20 November 2025 */

#include "list3.c"

int main() {
    /* kamus */
    List3 L, Senarai, LGabungan, LSplit1, LSplit2, LCopy;
    address A;
    infotype V;

    /* algoritma */
    printf("==================================================\n");
    printf("         PROGRAM TESTING ADT LIST BERKAIT         \n");
    printf("==================================================\n");

    printf("\n=== TEST CREATE LIST ===\n");
    CreateList(&L);
    PrintList(L);
    printf("\n\nApakah list kosong : %d\n", IsEmptyList(L));
    printf("Elemen list berjumlah : %d\n", NbElm(L));
    printf("==================================================\n");

    printf("\n=== TEST INSERT FIRST ===\n");
    InsertVFirst(&L, 'P');
    InsertVFirst(&L, 'A');
    printf("Isi list sekarang:\n");
    PrintList(L);
    printf("\n\nJumlah element list: %d\n", NbElm(L));
    printf("==================================================\n");

    printf("\n=== TEST INSERT LAST ELEMENT ===\n");
    InsertVLast(&L, 'Q');
    InsertVLast(&L, 'R');
    InsertVLast(&L, 'S');
    InsertVLast(&L, 'T');
    printf("Isi list sekarang:\n");
    PrintList(L);
    printf("\n\nJumlah element list: %d\n", NbElm(L));
    printf("==================================================\n");

    printf("\n=== TEST DELETE FIRST ELEMENT ===\n");
    DeleteVFirst(&L, &V);
    printf("Elemen pertama yang dihapus: %c\n", V);
    printf("\nIsi list setelah penghapusan:\n");
    PrintList(L);
    printf("\n==================================================\n");

    printf("\n=== TEST DELETE LAST ELEMENT ===\n");
    DeleteVLast(&L, &V);
    printf("Elemen terakhir yang dihapus: %c\n", V);
    printf("\nIsi list setelah penghapusan:\n");
    PrintList(L);
    printf("\n==================================================\n");

    printf("\n=== TEST DELETE X ===\n");
    DeleteX(&L, 'R');
    printf("Elemen yang dihapus: R\n");
    printf("\nIsi list setelah penghapusan:\n");
    PrintList(L);
    printf("\n==================================================\n");

    printf("\n=== TEST SEARCHX ===\n");
    printf("Mencari elemen 'S'\n");
    SearchX(L, 'S', &A);
    if (A != NIL) {
        printf("Elemen 'S' ditemukan.\n");
    } else {
        printf("Elemen 'S' tidak ditemukan.\n");
    }
    printf("==================================================\n");

    printf("\n=== TEST UPDATEX ===\n");
    printf("Ubah elemen 'S' menjadi 'Z'\n\n");
    UpdateX(&L, 'S', 'Z');
    printf("Isi list setelah UpdateX('S' -> 'Z'):\n");
    PrintList(L);
    printf("\n==================================================\n");

    printf("Ubah elemen 'X' menjadi 'M' (tidak ada di list)\n");
    UpdateX(&L, 'X', 'M');
    printf("\nIsi list setelah mencoba UpdateX('X' -> 'M'):\n");
    PrintList(L);
    printf("\n==================================================\n");

    printf("\n=== TEST INVERS ===\n");
    printf("Isi list sebelum invers:\n");
    PrintList(L);
    Invers(&L);
    printf("\n\nIsi list setelah invers:\n");
    PrintList(L);
    printf("\n==================================================\n");

    printf("\n=== TEST INSERT V AFTER X ===\n");
    printf("Isi list awal:\n");
    PrintList(L);
    printf("\n\nInsert 'F' setelah 'Z'\n");
    InsertVAfterX(&L, 'Z', 'F');
    printf("Isi list setelah insert:\n");
    PrintList(L);
    printf("\n==================================================\n");
    printf("Insert 'M' setelah 'P'\n");
    InsertVAfterX(&L, 'P', 'M');
    printf("Isi list setelah insert:\n");
    PrintList(L);
    printf("\n==================================================\n");
    printf("Insert 'A' setelah 'D' (tidak ada dalam list)\n");
    InsertVAfterX(&L, 'D', 'A');
    printf("Isi list setelah insert:\n");
    PrintList(L);
    printf("\n==================================================\n");

    printf("\n=== TEST INSERT V BEFORE X ===\n");
    printf("Isi list awal:\n");
    PrintList(L);
    printf("\n\nInsert 'E' sebelum 'Q'\n");
    InsertVBeforeX(&L, 'Q', 'E');
    printf("Isi list setelah insert:\n");
    PrintList(L);
    printf("\n==================================================\n");
    printf("Insert 'L' sebelum 'Z'\n");
    InsertVBeforeX(&L, 'Z', 'L');
    printf("Isi list setelah insert:\n");
    PrintList(L);
    printf("\n==================================================\n");
    printf("Insert 'Y' sebelum 'G' (tidak ada dalam list)\n");
    InsertVBeforeX(&L, 'G', 'Y');
    printf("Isi list setelah insert:\n");
    PrintList(L);
    printf("\n==================================================\n");

    printf("\n=== TEST DELETE V AFTER X ===\n");
    printf("Isi list awal:\n");
    PrintList(L);
    printf("\n\nDelete elemen setelah 'L'\n");
    DeleteVAfterX(&L, 'L', &V);
    printf("Elemen yang dihapus: %c\n\n", V);
    printf("Isi list setelah delete:\n");
    PrintList(L);
    printf("\n==================================================\n");
    printf("Delete elemen setelah 'M' (elemen terakhir)\n");
    DeleteVAfterX(&L, 'M', &V);
    printf("Elemen yang dihapus: %c\n\n", V);
    printf("Isi list setelah delete:\n");
    PrintList(L);
    printf("\n==================================================\n");
    printf("Delete elemen setelah 'D' (tidak ada dalam list)\n");
    DeleteVAfterX(&L, 'D', &V);
    printf("Elemen yang dihapus: %c\n\n", V);
    printf("Isi list setelah delete:\n");
    PrintList(L);
    printf("\n==================================================\n");

    printf("\n=== TEST DELETE V BEFORE X ===\n");
    printf("Isi list awal:\n");
    PrintList(L);
    printf("\n\nDelete elemen sebelum 'M'\n");
    DeleteVBeforeX(&L, 'M', &V);
    printf("Elemen yang dihapus: %c\n\n", V);
    printf("Isi list setelah delete:\n");
    PrintList(L);
    printf("\n==================================================\n");
    printf("Delete elemen sebelum 'L' (elemen pertama)\n");
    DeleteVBeforeX(&L, 'L', &V);
    printf("Elemen yang dihapus: %c\n\n", V);
    printf("Isi list setelah delete:\n");
    PrintList(L);
    printf("\n==================================================\n");
    printf("Delete elemen sebelum 'D' (tidak ada dalam list)\n");
    DeleteVBeforeX(&L, 'D', &V);
    printf("Elemen yang dihapus: %c\n\n", V);
    printf("Isi list setelah delete:\n");
    PrintList(L);
    printf("\n==================================================\n");

    printf("\n=== TEST COUNTX ===\n");
    // isi elemen baru
    InsertVLast(&L, 'L');
    InsertVLast(&L, 'H');
    InsertVLast(&L, 'F');
    InsertVLast(&L, 'F');
    printf("Isi list: \n");
    PrintList(L);
    printf("\n\nJumlah kemunculan huruf 'F': %d\n", CountX(L, 'F'));
    printf("\nJumlah kemunculan huruf 'A' (tidak ada dalam list): %d\n", CountX(L, 'A'));
    printf("==================================================\n");

    printf("\n=== TEST FREKUENSIX ===\n");
    printf("Isi list:\n");
    PrintList(L);
    printf("\n\nFrekuensiX untuk X='F' adalah %.2f", FrekuensiX(L, 'F'));
    printf("\nFrekuensiX untuk X='A' (tidak ada dalam list) adalah %.2f", FrekuensiX(L, 'A'));
    printf("\n==================================================\n");

    printf("\n=== TEST MAX MEMBER ===\n");
    printf("Isi list:\n");
    PrintList(L);
    printf("\n\nJumlah kemunculan huruf yang paling banyak muncul: %d\n", MaxMember(L));
    printf("==================================================\n");

    printf("\n=== TEST MODUS ===\n");
    printf("Isi list:\n");
    PrintList(L);
    printf("\n\nElemen modus pada list: %c\n", Modus(L));
    printf("==================================================\n");

    printf("\n=== TEST COUNT VOCAL ===\n");
    InsertVLast(&L, 'I');   // insert huruf vocal 'I' ke dalam list
    printf("Isi list: \n");
    PrintList(L);
    printf("\n\nJumlah kemunculan huruf vocal: %d\n", CountVocal(L));
    printf("==================================================\n");

    printf("\n=== TEST COUNT NG ===\n");
    printf("Isi list: \n");
    PrintList(L);
    printf("\n\nJumlah kemunculan huruf NG: %d\n", CountNG(L));
    printf("==================================================\n");
    InsertVLast(&L, 'N');   // insert huruf vocal 'N' dan 'G' ke list
    InsertVLast(&L, 'G');
    printf("Isi list setelah insert 'N' dan 'G': \n");
    PrintList(L);
    printf("\n\nJumlah kemunculan huruf NG: %d\n", CountNG(L));

    printf("\n=== TEST SEARCH ALL X ===\n");
    printf("Isi list:\n");
    PrintList(L);
    printf("\n\nCari Elemen 'F' dalam list'\n");
    SearchAllX(L, 'F');
    printf("\n==================================================\n");
    printf("Cari Elemen 'B' (B tidak ada di dalam list)\n");
    SearchAllX(L, 'B');
    printf("\n==================================================\n");

    printf("\n=== TEST DELETEALLX ===\n");
    printf("Isi list awal:\n");
    PrintList(L);
    printf("\n\nDeleteAll 'L'");
    DeleteAllX(&L, 'L');
    printf("\nIsi list setelah delete:\n");
    PrintList(L);
    printf("\n\nDeleteAll 'A' (tidak ada dalam list)");
    DeleteAllX(&L, 'A');
    printf("\nIsi list setelah delete:\n");
    PrintList(L);
    printf("\n==================================================\n");

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
    PrintList(L);
    printf("\n\nList L2:\n");
    PrintList(Senarai);
    ConcatList(L, Senarai, &LGabungan);
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