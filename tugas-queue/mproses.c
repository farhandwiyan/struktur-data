/* Program   : mproses.c */
/* Deskripsi : main program ADT Proses */
/* NIM/Nama  : 24060124140137 - Farhan Dwiyan Akbar */
/* Tanggal   : 08/10/2025 */
/***********************************/

#include <stdio.h>
#include "proses.c"

/* Program Utama */
int main() {
    /* kamus */
    Proses P1, P2, P3, P4, P5, P;
    tqueue Q;
    int start, finish;
    
    /* algoritma */
    printf("=== MULAI UJI COBA PROSES ===\n");

    printf("\n=== CREATE PROSES ===\n");
    
    // buat proses dari 5 digit terakir nim 40137
    makeProses(&P1, 'A', 4);
    makeProses(&P2, 'B', 7);
    makeProses(&P3, 'C', 1);
    makeProses(&P4, 'D', 3);
    makeProses(&P5, 'E', 7);

    printf("P1: ");
    printProses(P1);
    printf("\nP2: ");
    printProses(P2);
    printf("\nP3: ");
    printProses(P3);
    printf("\nP4: ");
    printProses(P4);
    printf("\nP5: ");
    printProses(P5);
    printf("\n");

    printf("\n=== CREATE QUEUE ===\n");
    createQueue(&Q);
    printf("Sebelum diisi elemen -> ");
    printf("Q: ");
    printQueue(Q);
    printf("\n");

    // enqueue proses ke queue
    enqueue(&Q, P1);
    enqueue(&Q, P2);
    enqueue(&Q, P3);
    enqueue(&Q, P4);
    enqueue(&Q, P5);
    printf("\nSetelah diisi elemen -> ");
    printf("Q: ");
    viewQueue(Q);
    printf("\n");

    printf("\n=== DEQUEUE PROSES ===\n");
    printf("Antrian awal: ");
    viewQueue(Q);
    printf("\n\n");

    start = 0;
    finish = 0;
    printf("Mulai eksekusi proses: \n");
    while (!isEmptyQueue(Q)) {
        // melakukan proses dequeue
        dequeueSJF(&Q, &P);
        
        // menampilkan proses yang dieksekusi
        printf("Proses yang dieksekusi -> ");
        printProses(P);
        printf("\n");

        // menampilakn waktu mulai dan waktu selesai
        finish += getBurstTime(P);
        printf("Start = %d, Finish = %d\n", start, finish);
        start = finish;

        // menampilkan proses yang tersisa pada queue
        printf("Q: ");
        viewQueue(Q);
        printf("\n\n");
    }

    printf("=== UJI COBA PROSES SELESAI ===");

    return 0;
}