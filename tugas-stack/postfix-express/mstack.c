/* Nama    : Kelompok 4 */
/* Tanggal : 20/09/2025 */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// program utama
int main() {
    // kamus
    char infix1[] = "3+4";                     
    char infix2[] = "3+4*5";                   
    char infix3[] = "(3+4)*5";                 
    char infix4[] = "3+4*5/2";                 
    char infix5[] = "(1+2)*(3+4)";             
    char infix6[] = "9*(5-3)/2";               

    char *postfix;

    // algoritma
    printf("\n============================\n");
    printf("==== Tes postFixExpress ====\n");
    printf("============================\n");
    
    postfix = postfixExpress(infix1);
    printf("Infix  : %s\nPostfix: %s\n\n", infix1, postfix);
    free(postfix);
    
    postfix = postfixExpress(infix2);
    printf("Infix  : %s\nPostfix: %s\n\n", infix2, postfix);  
    free(postfix);
    
    postfix = postfixExpress(infix3);
    printf("Infix  : %s\nPostfix: %s\n\n", infix3, postfix);  
    free(postfix);
    
    postfix = postfixExpress(infix4);
    printf("Infix  : %s\nPostfix: %s\n\n", infix4, postfix);  
    free(postfix);
        
    postfix = postfixExpress(infix5);
    printf("Infix  : %s\nPostfix: %s\n\n", infix5, postfix);  
    free(postfix);
    
    postfix = postfixExpress(infix6);
    printf("Infix  : %s\nPostfix: %s\n\n", infix6, postfix); 
    free(postfix);

    return 0;
}