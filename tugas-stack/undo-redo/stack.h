/* Program   : stack.h */
/* Deskripsi : file HEADER modul stack */
/* Nama      : Kelompok 4 */
/* Tanggal   : 20/09/2025 */
/***********************************/

#ifndef STACK_H
#define STACK_H

#include "boolean.h"

typedef struct {
    char wadah[11][20];  // kapasitas 10 elemen, tiap string max 19 karakter
    int top;
} Tstack;

/* Konstruktor */
void CreateStack(Tstack *S);

/* Predikat */
int isEmpty(Tstack S);
int isFull(Tstack S);

/* Mutator */
void Push(Tstack *S, char x[]);
void Pop(Tstack *S, char x[]);

/* Traversal */
void PrintStack(Tstack S);

#endif