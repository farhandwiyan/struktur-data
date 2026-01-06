/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : Farhan Dwiyan Akbar - 24060124140137*/
/* Tanggal   : 25/09/2025 */
/***********************************/

#include <stdio.h>
#include "tstack.c"

int main() 
{	/* kamus main */
	Tstack A; // variabel A bertipe tStack
    Tstack B;
	char X;
    char kata1[20] = "kasurrusak";
    char kata2[20] = "tembalang";

	/* algoritma */
    printf("=== Uji Modul Tstack ===");
	
    printf("\nStack sebelum diisi :\n");
    createStack(&A);
    printStack(A);
    printf("\nIndex top pada stack A = %d", top(A));
    printf("\nApakah stack A kosong = %d\n", isEmptyStack(A));
    
    printf("\n=== push ===\n");
    push(&A, 'A');
    push(&A, 'B');
    push(&A, 'C');
    push(&A, 'D');
    push(&A, 'E');
    push(&A, 'F');
    printf("Stack A setelah diisi: \n");
    viewStack(A);
    printf("\nIndex top pada stack A = %d", top(A));
    printf("\nElemen top pada stack A = %c", infotop(A));
    printf("\nApakah stack A kosong = %d\n", isEmptyStack(A));

    printf("\n=== pop ===\n");
    pop(&A, &X);
    printf("pop stack A = %c\n", X);
    printf("\nStack A setelah di pop:\n");
    viewStack(A);

	printf("\n=== isPalindrom ===\n");
    printf("Apakah kasurrusak palindrom = %d\n", isPalindrom(kata1));
    printf("Apakah tembalang palindrom = %d\n", isPalindrom(kata2));

    printf("\n=== pushN ===\n");
    pushN(&B, 5);
    printf("\nStack B setelah diisi: \n");
    viewStack(B);
	
	return 0;
}