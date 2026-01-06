/* Program   : mtqueue3.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060124140137 - Farhan Dwiyan Akbar */
/* Tanggal   : 09/10/2025 */
/***********************************/

#include "tqueue3.c"
#include <stdio.h>

int main() {
    // kamus lokak
    tqueue3 Q1;
    char E;

    // algoritma
    printf("=== MULAI UJI PROGRAM TQUEUE3 ===");

    // create queue
    printf("\n=== TEST CREATE QUEUE ===\n");
    createQueue3(&Q1);
    printf("Q1: ");
    printQueue3(Q1);
    printf("\n");

    // cek apakah kosong
    printf("\n");
    printf("Apakah Q1 kosong = %d\n", isEmptyQueue3(Q1));
    printf("Apakah Q1 full = %d\n", isFullQueue3(Q1));
    printf("Apakah Q1 satu elemen = %d\n", isOneElement3(Q1));
    
    printf("\nHead = %c\n", infoHead3(Q1));
    printf("Tail = %c\n", infoTail3(Q1));
    printf("Size = %d\n", sizeQueue3(Q1));
    // Enqueue beberapa elemen
    printf("\n=== TEST ENQUEUE ===\n");
    enqueue3(&Q1, 'A');
    enqueue3(&Q1, 'B');
    enqueue3(&Q1, 'C');
    enqueue3(&Q1, 'D');
    enqueue3(&Q1, 'E');
    printf("Q1: ");
    viewQueue3(Q1);
    printf("\nHead = %c\n", infoHead3(Q1));
    printf("Tail = %c\n", infoTail3(Q1));
    printf("Size = %d\n", sizeQueue3(Q1));
    
    printf("\nApakah Q1 kosong = %d\n", isEmptyQueue3(Q1));
    printf("Apakah Q1 full = %d\n", isFullQueue3(Q1));
    printf("Apakah Q1 satu elemen = %d\n", isOneElement3(Q1));

    // Dequeue beberapa kali
    printf("\n=== TEST DEQUEUE ===\n");
    dequeue3(&Q1, &E);
    printf("Hasil dequeue E = %c\n", E);
    printf("Q1: ");
    viewQueue3(Q1);
    printf("\n");

    dequeue3(&Q1, &E);
    printf("Hasil dequeue E = %c\n", E);
    printf("Q1: ");
    viewQueue3(Q1);
    printf("\n");

    // enqueue beberapa elemen kembali
    printf("\n=== TEST ENQUEUE KEMBALI ===\n");
    printf("Sebelum di enqueue: \n");
    printf("Head = %d\n", head3(Q1));
    printf("Tail = %d\n", tail3(Q1));
    enqueue3(&Q1, 'F');
    enqueue3(&Q1, 'G');

    printf("\nQ1: ");
    viewQueue3(Q1);
    printf("\n");

    printf("\nSetelah di enqueue: \n");
    printf("Head = %d\n", head3(Q1));
    printf("Tail = %d\n", tail3(Q1));
    printf("Apakah tail lebih kecil dari head = %d\n", isTailOverHead(Q1));

    // dequeue elemen kembali
    printf("\n=== TEST DEQUEUE KEMBALI ===\n");

    dequeue3(&Q1, &E);
    printf("Hasil dequeue E = %c\n", E);
    printf("Q1: ");
    viewQueue3(Q1);
    printf("\n");

    printf("\n=== UJI PROGRAM TQUEUE3 SELESAI ===");

    return 0;
}