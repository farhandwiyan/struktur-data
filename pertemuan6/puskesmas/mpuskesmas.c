/* Program   : mpuskesmas.c */
/* Deskripsi : main program module puskesmas */
/* NIM/Nama  : 24060124140137 - Farhan Dwiyan Akbar */
/* Tanggal   : 11/10/2025 */
/***********************************/

#include <stdio.h>
#include "puskesmas.c"

/* Program Utama */
int main() {
    /* kamus */
    pasien P1, P2, P3, P4, P5, P;
    tqueue T;
    
    /* algoritma */
    printf("=== MULAI UJI COBA MODUL PUSKESMAS ===\n");

    printf("\n=== CREATE QUEUE ===\n");
    // buat pasien
    makePasien(&P1, 19, 1);
    makePasien(&P2, 23, 2);
    makePasien(&P3, 30, 2);
    makePasien(&P4, 98, 1);
    makePasien(&P5, 45, 3);

    // buat tqueue
    createQueue(&T);
    printf("Antrian sebelum ada pasien: ");
    printQueue(T);
    printf("\n");

    printf("\n=== ENQUEUE P1 DAN P2 ===\n");
    enqueue(&T, P1);
    enqueue(&T, P2);
    printf("Antrian saat ini: ");
    viewQueue(T);
    printf("\n");

    printf("\n=== ENQUEUE P3 ===\n");
    enqueue(&T, P3);
    printf("Antrian saat ini: ");
    viewQueue(T);
    printf("\n");

    printf("\n=== ENQUEUE P4 ===\n");
    enqueue(&T, P4);
    printf("Antrian saat ini: ");
    viewQueue(T);
    printf("\n");

    printf("\n=== ENQUEUE P5 ===\n");
    enqueue(&T, P5);
    printf("Antrian saat ini: ");
    viewQueue(T);
    printf("\n");

    printf("\n=== DEQUEUE SAMPE KOSONG ===\n");
    while (!isEmptyQueue(T)) {
        dequeue(&T, &P);

        printf("Pasien yang keluar antrian: [%d, %d]\n", P.id, P.prioritas);
        printf("Antrian saat ini: ");
        viewQueue(T);
        printf("\n\n");
    }

    printf("=== SELESAI UJI COBA MODUL PUSKESMAS ===");
    return 0;
}
