/* Program   : stack.c */
/* Deskripsi : file modul stack */
/* Nama      : Kelompok 4 */
/* Tanggal   : 20/09/2025 */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* KONSTRUKTOR */
/* procedure CreateStack(output S: Tstack)
    {I.S: - ; F.S; S terdefinisi }
    {Proses mengisi elemen wadah kosong dengan '_', top = 0} */
void CreateStack(Tstack *S) {
    // kamus lokal
    int i;

    // algoritma
    for (i = 1; i <= 10; i++) {
        (*S).wadah[i] = '_';
    }

    (*S).top = 0;
}

/* FUNGSI INFO */
/* function Infotop(S: Tstack) -> character
    {mengembalikan nilai elemen puncak} */
char Infotop(Tstack S) {
    return S.wadah[S.top];
}

/* function Top(S: Tstack) -> integer
    {mengembalikan posisi puncak} */
int Top(Tstack S) {
    return S.top;
}

/* function isEmptyStack(S: Tstack) -> boolean
    {mengembalikan true bila S kosong} */
boolean isEmptyStack(Tstack S) {
    return S.top == 0;
}

/* function isFullStack(S: Tstack) -> boolean
    {mengembalikan true bila S penuh} */
boolean isFullStack(Tstack S) {
    return S.top == 10;
}

/* OPERATOR */
/* procedure Push(input/output S: Tstack, input e: character)
    {I.S: S,e terdefinisi, S mungkin kosong }
    {F.S: S tetap, atau Infotop(S)=e }
    {Proses mengisi elemen e ke puncak S, bila belum penuh} */
void Push(Tstack *S, char e) {
    if (!isFullStack(*S)) {
        (*S).top = (Top(*S) + 1);
        (*S).wadah[Top(*S)] = e;
    }
}

/* procedure Pop(input/output S: Tstack, output e: character)
    {I.S: S terdefinisi, mungkin kosong }
    {F.S: S tetap, atau e berisi infotop(S) lama }
    {Proses mengambil elemen e dari puncak S, bila belum kosong} */
void Pop(Tstack *S, char *e) {
    if (!isEmptyStack(*S)) {
        *e = Infotop(*S);
        (*S).wadah[Top(*S)] = '_';
        (*S).top--;
    }
}

/* procedure PrintStack(input S: Tstack)
    {I.S: - ; F.S: - ; 
     Proses menampilkan info elemen S} */
void PrintStack(Tstack S) {
    // kamus lokal
    int i;

    // algoritma
    for (i = Top(S); i >= 1; i--) {
        printf("[%d] : %c\n", i, S.wadah[i]);
    }
}

/* Fungsi diinginkan soal */
/* function countStr(kata: string) -> integer 
    {menghitung panjang dari string yang diinputkan } */
int countStr(char *kata) {
    // kamus lokal
    int i;

    // algoritma
    i = 0;
    while (kata[i] != '\0') {
        i++;
    }

    return i;
}

/* function postfixExpress(infix: string) -> string 
    {menerima masukan string berisi infix expression dan menghasilkan ouput string berupa postfix expression } */
char *postfixExpress(char *infix) {
    // kamus lokal
    Tstack S;
    int length;
    int i, j;
    char c, e;
    char *postFix;

    // algoritma
    CreateStack(&S);
    length = countStr(infix);
    postFix  = (char *)malloc((length + 1) *sizeof(char));

    j = 0;
    for (i = 0; i < length; i++) {
        c = infix[i];

        if (c >= '0' && c <= '9') {
            postFix[j] = c;
            j++;
        } else if (c == '(') {
            Push(&S, c);
        } else if ( c == ')') {
            while (!isEmptyStack(S) && Infotop(S) != '(') {
                Pop(&S, &e);
                postFix[j] = e;
                j++;
            }
            Pop(&S, &e);
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!isEmptyStack(S) && (Infotop(S) == '*' || Infotop(S) == '/')) {
                Pop(&S, &e);
                postFix[j] = e;
                j++;
            }
            Push(&S, c);
        }
    }

    while (!isEmptyStack(S)) {
        Pop(&S, &e);
        postFix[j] = e;    
        j++;
    }

    postFix[j] = '\0';
    
    return postFix;
}