/* Program    : stack.c */
/* Deskripsi  : file modul stack float */
/* Nama       : Kelompok 4 */
/* Tanggal    : 20/09/2025 */
/***********************************/

#include <stdio.h>
#include "stack.h"

/* KONSTRUKTOR */
/* procedure CreateStack(output S: Tstack)
    {I.S: - ; F.S; S terdefinisi }
    {Proses mengisi elemen wadah kosong dengan 0.0, top = 0} */
void CreateStack(Tstack *S) {
    int i;
    for (i = 1; i <= 10; i++) {
        (*S).wadah[i] = 0.0f;   
    }
    (*S).top = 0;
}

/* FUNGSI INFO */
/* function Infotop(S: Tstack) -> real
    {mengembalikan nilai elemen puncak} */
float Infotop(Tstack S) {
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
/* procedure Push(input/output S: Tstack, input e: real)
    {I.S: S,e terdefinisi, S mungkin kosong }
    {F.S: S tetap, atau Infotop(S)=e }
    {Proses mengisi elemen e ke puncak S, bila belum penuh} */
void Push(Tstack *S, float e) {
    if (!isFullStack(*S)) {
        (*S).top = Top(*S) + 1;
        (*S).wadah[Top(*S)] = e;
    }
}

/* procedure Pop(input/output S: Tstack, output e: real)
    {I.S: S terdefinisi, mungkin kosong }
    {F.S: S tetap, atau e berisi infotop(S) lama }
    {Proses mengambil elemen e dari puncak S, bila belum kosong} */
void Pop(Tstack *S, float *e) {
    if (!isEmptyStack(*S)) {
        *e = Infotop(*S);
        (*S).wadah[Top(*S)] = 0.0f;
        (*S).top--;
    }
}

/* procedure PrintStack(input S: Tstack)
    {I.S: - ; F.S: - ; 
     Proses menampilkan info elemen S} */
void PrintStack(Tstack S) {
    int i;
    for (i = Top(S); i >= 1; i--) {
        printf("[%d] : %.2f\n", i, S.wadah[i]);
    }
}

/* Fungsi diingikan soal*/
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

/* function evalPostfix(postfix: string) -> real 
    {menerima sebua input string berupa operasi postfix, lalu menghasilkan output berupa bilangan real 
    hasil dari evaluasi ekspresi tersebut } */
float evalPostfix(char *postfix) {
    // kamus lokal
    int i;
    int length;
    float val1, val2;
    char c;
    Tstack S;

    // algoritma
    CreateStack(&S);
    length = countStr(postfix);

    for (i = 0; i < length; i++) {
        c = postfix[i];

        if (c >= '0' && c <= '9') {
            val1 = c - '0';
            Push(&S, val1);
        } else if (c == '*' || c == '/' || c == '+' || c == '-') {
            if (c == '*') {
                Pop(&S, &val1);
                Pop(&S, &val2);

                Push(&S, val1 * val2);
            } else if (c == '/'){
                Pop(&S, &val1);
                Pop(&S, &val2);

                Push(&S, val2 / val1);
            } else if (c == '+') {
                Pop(&S, &val1);
                Pop(&S, &val2);

                Push(&S, val1 + val2);
            } else {
                Pop(&S, &val1);
                Pop(&S, &val2);

                Push(&S, val2 - val1);
            }
        }
    }

    Pop(&S, &val1);

    return val1;
}
