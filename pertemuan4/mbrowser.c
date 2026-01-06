/* Program   : mbrowser.c */
/* Deskripsi : file simulasi tombol Backward & Forward browser menggunakan ADT Stack */
/* NIM/Nama  : Farhan Dwiyan Akbar - 24060124140137*/
/* Tanggal   : 25/09/2025 */
/***********************************/

#include <stdio.h>
#include "tstack.c"

int main() {
    /* kamus main */
    Tstack backward, forward;
    char url, currentPage;
    int kode;

    /* algoritma */
    printf("==============================\n");
    printf("====== SIMULASI BROWSER ======\n");
    printf("==============================\n");

    printf("\nPilih Kode :\n");
    printf("1. Menambahkan url baru\n");
    printf("2. Melakukan backward\n");
    printf("3. Melakukan forward\n");
    printf("4. Exit\n");

    // buat stack
    createStack(&backward);
    createStack(&forward);

    // mulai perulangan
    do {
        printf("\nMasukan kode pilihan anda: ");
        scanf("%d", &kode);

        if (kode == 1) {
            printf("Masukan url baru: ");
            scanf(" %c", &url);
            push(&backward, url);

            if (!isEmptyStack(forward)) {
                createStack(&forward);   // reset stack forward
            }

            // menampilkan isi stack dan current page
            currentPage = infotop(backward);
            printf("\nCurrent page -> %c\n", currentPage);
            printf("\nIsi Stack backward:\n");
            viewStack(backward);
            printf("\nIsi Stack forward:\n");
            viewStack(forward);
            printf("\n===========================\n");
        } else if (kode == 2) {
            if (!isEmptyStack(backward)) {
                pop(&backward, &url);
                push(&forward, url);

                // menampilkan isi stack dan current page
                currentPage = infotop(backward);
                printf("\nCurrent page -> %c\n", currentPage);
                printf("\nIsi Stack backward:\n");
                viewStack(backward);
                printf("\nIsi Stack forward:\n");
                viewStack(forward);
                printf("\n===========================\n");
            } else {
                printf("Tidak dapat melakukan backward karena stack backward kosong!\n");
            }
        } else if (kode == 3) {
            if (!isEmptyStack(forward)) {
                pop(&forward, &url);
                push(&backward, url);

                // menampilkan isi stack dan current page
                currentPage = infotop(backward);
                printf("\nCurrent page -> %c\n", currentPage);
                printf("\nIsi Stack backward:\n");
                viewStack(backward);
                printf("\nIsi Stack forward:\n");
                viewStack(forward);
                printf("\n===========================\n");
            } else {
                printf("Tidak dapat melakukan forward karena stack forward kosong!\n");
            }
        } else if (kode == 4) {
            printf("\n===========================\n");
            printf("===== KELUAR SIMULASI =====\n");
            printf("===========================\n");
        } else {
            printf("Kode tidak valid. Silahkan masukan kode yang sesuai!\n");
        }
    } while (kode != 4);

    printf("\n===== Program Selesai =====");

    return 0;
}