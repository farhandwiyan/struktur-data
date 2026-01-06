/* Nama    : Kelompok 4 */
/* Tanggal : 20/09/2025 */
/***********************************/

#include <stdio.h>
#include "stack.h"

// program utama
int main() {
    // kamus
    char test1[] = "9 3 4 * 8 + 4 / -";  
    char test2[] = "5 1 2 + 4 * + 3 -";  
    char test3[] = "1 2 /";              
    char test4[] = "9 2 /";               
    char test5[] = "7 3 - 2 *";           

    // algoritma
    printf("===========================\n");
    printf("===== Tes evalPostfix =====\n");
    printf("===========================\n");
    printf("Test 1: %s = %.2f\n", test1, evalPostfix(test1));
    printf("Test 2: %s = %.2f\n", test2, evalPostfix(test2));
    printf("Test 3: %s = %.2f\n", test3, evalPostfix(test3));
    printf("Test 4: %s = %.2f\n", test4, evalPostfix(test4));
    printf("Test 5: %s = %.2f\n", test5, evalPostfix(test5));

    return 0;
}