/* Program   : mtqueue.c */
/* Deskripsi : Driver untuk menguji ADT Queue1 */
/* NIM/Nama  : 24060124140137 - Farhan Dwiyan Akbar */
/* Tanggal   : 02/10/2025 */
/***********************************/

#include <stdio.h>
#include "tqueue2.c"

int main() {
    /* kamus */
    tqueue2 Q1, Q2, Q3;
    char e;

    /* algoritma */
    printf("=== MULAI UJI PROGRAM TQUEUE2 ===\n");

    printf("\n=== TEST CREATE QUEUE2 ===\n");
    createQueue2(&Q1);
    createQueue2(&Q2);

    printf("Q1: ");
    printQueue2(Q1);
    printf("\nQ2: ");
    printQueue2(Q2);
    printf("\n");

    // cek apakah kosong
    printf("\nisEmptyQueue2(Q1) = %d\n", isEmptyQueue2(Q1));
    printf("isFullQueue2(Q1) = %d\n", isFullQueue2(Q1));
    printf("isOneElement2(Q1) = %d\n", isOneElement2(Q1));
    
    printf("\nisEmptyQueue2(Q2) = %d\n", isEmptyQueue2(Q2));
    printf("isFullQueue2(Q2) = %d\n", isFullQueue2(Q2));
    printf("isOneElement2(Q2) = %d\n", isOneElement2(Q2));

    // Enqueue beberapa elemen
    printf("\n=== TEST ENQUEUE2 ===\n");
    enqueue2(&Q1, 'A');
    enqueue2(&Q1, 'B');
    enqueue2(&Q1, 'C');
    enqueue2(&Q1, 'D');
    enqueue2(&Q1, 'E');
    viewQueue2(Q1);
    printf("\nHead = %c\n", infoHead2(Q1));
    printf("Tail = %c\n", infoTail2(Q1));
    printf("Size = %d\n", sizeQueue2(Q1));

    // Dequeue beberapa kali
    printf("\n=== TEST DEQUEUE ===\n");
    dequeue2(&Q1, &e);
    printf("Hasil dequeue e = %c\n", e);
    printf("Q1: ");
    viewQueue2(Q1); 
    printf("\n");

    dequeue2(&Q1, &e);
    printf("Hasil dequeue e = %c\n", e);
    printf("Q1: ");
    viewQueue2(Q1); 
    printf("\n");

    // enqueue Q1 jika isTailStop = true
    printf("\n=== TEST ENQUEUE2 JIKA iSTAILSTOP -> TRUE ===\n");
    printf("isTailStop(Q1) = %d", isTailStop(Q1));
    enqueue2(&Q1, 'F');
    printf("\nQ1: ");
    printQueue2(Q1); 
    printf("\n");

    // Coba isi sampai full
    printf("\n=== TEST FULL QUEUE ===\n");
    enqueue2(&Q2, 'V');
    enqueue2(&Q2, 'W');
    enqueue2(&Q2, 'X');
    enqueue2(&Q2, 'Y');
    enqueue2(&Q2, 'Z');
    printf("Q2: ");
    viewQueue2(Q2); 
    printf("\nisFullQueue2(Q2) = %d\n", isFullQueue2(Q2));

    printf("\n=== TEST RESET HEAD ===\n");
    dequeue2(&Q2, &e);
    printf("Hasil dequeue e = %c\n", e);
    resetHead(&Q2);
    printf("Q2: ");
    printQueue2(Q2);
    printf("\n");

    // Kosongkan Q1
    printf("\n=== TEST SISAKAN SATU ELEMEN Q1 ===\n");
    while (!isOneElement2(Q1)) {
        dequeue2(&Q1, &e);
        printf("Dequeue hasil e = %c\n", e);
    }
    printf("\nQ1: "); 
    viewQueue2(Q1);
    printf("\n");
    printf("isOneElement2(Q1) = %d\n", isOneElement2(Q1));

    printf("\n=== TEST ENQUEUE2N ===\n");
    enqueue2N(&Q1, 4);
    printf("\nQ1: "); 
    viewQueue2(Q1);
    printf("\n");

    // isi Q3
    createQueue2(&Q3);
    enqueue2(&Q3, 'W');
    enqueue2(&Q3, 'X');
    enqueue2(&Q3, 'Y');
    enqueue2(&Q3, 'Z');

    printf("\n=== TEST ISEQUAL ===\n");
    printf("Q1: ");
    printQueue2(Q1);
    printf("\nQ2: "); 
    printQueue2(Q2);
    printf("\nQ3: "); 
    printQueue2(Q3);

    printf("\n\nisEqualQueue2(Q2, Q3) = %d", isEqualQueue2(Q2, Q3));
    printf("\nisEqualQueue2(Q1, Q2) = %d\n", isEqualQueue2(Q1, Q2));

     printf("\n=== UJI PROGRAM TQUEUE2 SELESAI ===");
    return 0;
}