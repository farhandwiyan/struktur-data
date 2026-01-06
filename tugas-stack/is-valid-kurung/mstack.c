/* Nama    : Kelompok 4 */
/* Tanggal : 20/09/2025 */
/***********************************/

#include <stdio.h>
#include "stack.h"

// program utama
int main() {
    // kamus
    char test1[] = "{[(A+B) * (C+D)] - (7*D)}";
    char test2[] = "{[(A+B) * (C+D)] - (7*D)";
    char test3[] = "{[(A+B) * (C+D]) - (7*D)}";
    char test4[] = "{[(A+B) * (C+D)] - (7*D))}";

    // algoritma
    printf("=========================\n");
    printf("=== Tes IsValidKurung ===\n");
    printf("=========================\n");
    printf("Test 1: %s -> %d\n", test1, isValidKurung(test1));
    printf("Test 2: %s -> %d\n", test2, isValidKurung(test2));
    printf("Test 3: %s -> %d\n", test3, isValidKurung(test3));
    printf("Test 4: %s -> %d\n", test4, isValidKurung(test4));

    return 0;
}