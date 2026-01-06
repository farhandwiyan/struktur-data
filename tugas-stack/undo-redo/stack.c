/* Program   : stack.c */
/* Deskripsi : file modul stack */
/* Nama      : Kelompok 4 */
/* Tanggal   : 20/09/2025 */
/***********************************/

#include <stdio.h>
#include <string.h>
#include "stack.h"

/* Konstruktor */
void CreateStack(Tstack *S) {
    int i;
    for (i = 1; i <= 10; i++) {
        strcpy((*S).wadah[i], "");
    }
    (*S).top = 0;
}

/* Predikat */
int isEmptyStack(Tstack S) {
    return (S.top == 0);
}

int isFullStack(Tstack S) {
    return (S.top == 10);
}

/* Mutator */
void Push(Tstack *S, char x[]) {
    if (!isFullStack(*S)) {
        (*S).top++;
        strcpy((*S).wadah[(*S).top], x);
    }
}

void Pop(Tstack *S, char x[]) {
    if (!isEmptyStack(*S)) {
        strcpy(x, (*S).wadah[(*S).top]);
        (*S).top--;
    } else {
        strcpy(x, "");
    }
}

/* Traversal */
void PrintStack(Tstack S) {
    int i;
    if (isEmptyStack(S)) {
        printf("[kosong]");
    } else {
        for (i = 1; i <= S.top; i++) {
            printf("%s ", S.wadah[i]);
        }
    }
    printf("\n");
}