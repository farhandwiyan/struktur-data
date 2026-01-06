#ifndef stack_H
#define stack_H

/* Program    : stack.h */
/* Deskripsi  : file modul stack float */
/* Nama       : Kelompok 4 */
/* Tanggal    : 20/09/2025 */
/***********************************/

#include "boolean.h"

/* type Tstack = < wadah: array[1...10] of real, 
                   top: integer > */
typedef struct { 
    float wadah[11]; 
    int top; } Tstack;

/* KONSTRUKTOR */
/* procedure CreateStack(output S: Tstack)
    {I.S: - ; F.S; S terdefinisi }
    {Proses mengisi elemen wadah kosong dengan 0.0, top = 0} */
void CreateStack(Tstack *S);

/* FUNGSI INFO */
/* function Infotop(S: Tstack) -> real
    {mengembalikan nilai elemen puncak} */
float Infotop(Tstack S);

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
/* procedure Push(input/output S: Tstack, input e: real)
    {I.S: S,e terdefinisi, S mungkin kosong }
    {F.S: S tetap, atau Infotop(S)=e }
    {Proses mengisi elemen e ke puncak S, bila belum penuh} */
void Push(Tstack *S, float e);

/* procedure Pop(input/output S: Tstack, output e: real)
    {I.S: S terdefinisi, mungkin kosong }
    {F.S: S tetap, atau e berisi infotop(S) lama }
    {Proses mengambil elemen e dari puncak S, bila belum kosong} */
void Pop(Tstack *S, float *e);

/* procedure PrintStack(input S: Tstack)
    {I.S: - ; F.S: - ; 
     Proses menampilkan info elemen S} */
void PrintStack(Tstack S);

/* Fungsi diingikan soal*/
/* function countStr(kata: string) -> integer 
    {menghitung panjang dari string yang diinputkan } */
int countStr(char *kata);

/* function evalPostfix(postfix: string) -> real 
    {menerima sebua input string berupa operasi postfix, lalu menghasilkan output berupa bilangan real 
    hasil dari evaluasi ekspresi tersebut } */
float evalPostfix(char *postfix);

#endif
