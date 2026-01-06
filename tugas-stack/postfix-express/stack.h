#ifndef stack_H
#define stack_H

/* Program   : stack.h */
/* Deskripsi : file HEADER modul stack */
/* Nama      : Kelompok 4 */
/* Tanggal   : 20/09/2025 */
/***********************************/

#include "boolean.h"

/* type Tstack = < wadah: array[1...10] of character, 
                   top: integer > */
typedef struct { char wadah[11]; 
                 int top; } Tstack;

/* KONSTRUKTOR */
/* procedure CreateStack(output S: Tstack)
    {I.S: - ; F.S; S terdefinisi }
    {Proses mengisi elemen wadah kosong dengan '_', top = 0} */
void CreateStack(Tstack *S);

/* FUNGSI INFO */
/* function Infotop(S: Tstack) -> character
    {mengembalikan nilai elemen puncak} */
char Infotop(Tstack S);

/* function Top(S: Tstack) -> integer
    {mengembalikan posisi puncak} */
int Top(Tstack S);

/* function isEmptyStack(S: Tstack) -> boolean
    {mengembalikan true bila S kosong} */
boolean isEmptyStack(Tstack S);

/* function isFullStack(S: Tstack) -> boolean
    {mengembalikan true bila S penuh} */
boolean isFullStack(Tstack S);

/* OPERATOR */
/* procedure Push(input/output S: Tstack, input e: character)
    {I.S: S,e terdefinisi, S mungkin kosong }
    {F.S: S tetap, atau Infotop(S)=e }
    {Proses mengisi elemen e ke puncak S, bila belum penuh} */
void Push(Tstack *S, char e);

/* procedure Pop(input/output S: Tstack, output e: character)
    {I.S: S terdefinisi, mungkin kosong }
    {F.S: S tetap, atau e berisi infotop(S) lama }
    {Proses mengambil elemen e dari puncak S, bila belum kosong} */
void Pop(Tstack *S, char *e);

/* procedure PrintStack(input S: Tstack)
    {I.S: - ; F.S: - ; 
     Proses menampilkan info elemen S} */
void PrintStack(Tstack S);

/* Fungsi diinginkan soal */
/* function countStr(kata: string) -> integer 
    {menghitung panjang dari string yang diinputkan } */
int countStr(char *kata);

/* function postfixExpress(infix: string) -> string 
    {menerima masukan string berisi infix expression dan menghasilkan ouput string berupa postfix expression } */
char *postfixExpress(char *infix);

#endif