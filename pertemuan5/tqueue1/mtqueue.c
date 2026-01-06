/* Program   : mtqueue.c */
/* Deskripsi : Driver untuk menguji ADT Queue1 */
/* NIM/Nama  : 24060124140137 - Farhan Dwiyan Akbar */
/* Tanggal   : 02/10/2025 */
/***********************************/

#include <stdio.h>
#include "tqueue.c"

int main() {
    // Kamus
    tqueue Q1, Q2;
    char e;

    // Create Queue
    printf("=== MULAI UJI PROGRAM TQUEUE1 ===\n");

    printf("\n=== TEST CREATE QUEUE ===\n");
    createQueue(&Q1);
    createQueue(&Q2);
    printf("Q1: ");
    printQueue(Q1); 
    printf("\n");
    printf("Q2: ");
    printQueue(Q2); 
    printf("\n");

    // Cek apakah kosong
    printf("\n");
    printf("isEmptyQueue(Q1) = %d\n", isEmptyQueue(Q1));
    printf("isFullQueue(Q1)  = %d\n", isFullQueue(Q1));
    printf("isOneElement(Q1) = %d\n", isOneElement(Q1));

    printf("\n");
    printf("isEmptyQueue(Q2) = %d\n", isEmptyQueue(Q2));
    printf("isFullQueue(Q2)  = %d\n", isFullQueue(Q2));
    printf("isOneElement(Q2) = %d\n", isOneElement(Q2));

    // Enqueue beberapa elemen
    printf("\n=== TEST ENQUEUE ===\n");
    enqueue(&Q1, 'A');
    enqueue(&Q1, 'B');
    enqueue(&Q1, 'C');
    enqueue(&Q1, 'D');
    enqueue(&Q1, 'E');
    viewQueue(Q1);
    printf("\nHead = %c\n", infoHead(Q1));
    printf("Tail = %c\n", infoTail(Q1));
    printf("Size = %d\n", sizeQueue(Q1));

    // Dequeue beberapa kali
    printf("\n=== TEST DEQUEUE ===\n");
    dequeue(&Q1, &e);
    printf("Hasil dequeue e = %c\n", e);
    viewQueue(Q1); 
    printf("\n");

    dequeue(&Q1, &e);
    printf("Hasil dequeue e = %c\n", e);
    viewQueue(Q1); 
    printf("\n");

    // Coba isi sampai full
    printf("\n=== TEST FULL QUEUE ===\n");
    enqueue(&Q1, 'F');
    enqueue(&Q1, 'G');
    viewQueue(Q1); 
    printf("\nisFullQueue(Q1) = %d\n", isFullQueue(Q1));

    // Test queue kedua + enqueue2
    printf("\n=== TEST ENQUEUE2 ===\n");
    enqueue(&Q2, 'X');
    enqueue(&Q2, 'Y');
    enqueue2(&Q1, &Q2, 'Z'); // masuk ke queue yang lebih pendek (Q2)
    printf("Q1: "); 
    viewQueue(Q1);
    printf("\nQ2: "); 
    viewQueue(Q2); 
    printf("\n");

    // Test dequeue2
    printf("\n=== TEST DEQUEUE2 ===\n");
    dequeue2(&Q1, &Q2, &e);
    printf("Hasil dequeue2 e = %c\n", e);
    printf("Q1: "); 
    viewQueue(Q1);
    printf("\nQ2: "); 
    viewQueue(Q2); 
    printf("\n");

    // Kosongkan Q2
    printf("\n=== TEST KOSONGKAN Q2 ===\n");
    while (!isEmptyQueue(Q2)) {
        dequeue(&Q2, &e);
        printf("Dequeue hasil e = %c\n", e);
    }
    printf("\nQ2: "); 
    viewQueue(Q2);
    printf("\n");
    printf("isEmptyQueue(Q2) = %d\n\n", isEmptyQueue(Q2));

    printf("=== UJI PROGRAM TQUEUE1 SELESAI ===\n");

    return 0;
}
