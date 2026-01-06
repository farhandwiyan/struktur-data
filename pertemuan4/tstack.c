/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : Farhan Dwiyan Akbar - 24060124140137*/
/* Tanggal   : 25/09/2025 */
/***********************************/

#include <stdio.h>
#include <string.h>
#include "tstack.h"
				 
/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T) {
	// kamus lokal
	int i;

	// algoritma
	for (i = 1; i <= 10; i++) {
		(*T).wadah[i] = '#';
	}

	(*T).top = 0;
}

/*function top( T: Tstack) -> integer
	{mengembalikan posisi puncak stack } */
//int top (Tstack T);
//dalam praktikum ini, fungsi dapat direalisasikan
//menjadi macro dalam bahasa C.
#define top(T) (T).top

/*function infotop( T: Tstack) -> character
	{mengembalikan nilai elemen top stack } */
//char infotop (Tstack T);
#define infotop(T) (T).wadah[(T).top]

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T) {
	return T.top == 0;
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T) {
	return T.top == 10;
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E) {
	if (!isFullStack(*T)) {
		(*T).top = top(*T) + 1;
		(*T).wadah[top(*T)] = E;
	}
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X) {
	if (!isEmptyStack(*T)) {
		(*X) = infotop(*T);
		
		(*T).wadah[top(*T)] = '#';
		(*T).top--;
	}
}

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T) {
	// kamus lokal
	int i;

	// algoritma
	for (i = 10; i >= 1; i--) {
		printf("[%c] -> %d\n", T.wadah[i], i);
	}
}

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T) {
	// kamus lokal
	int i;

	// algoritma
	for (i = top(T); i >= 1; i--) {
		printf("[%c] -> %d\n", T.wadah[i], i);
	}
}
/* boolean isPalindrom(kata:String) 
   {mengembalikan true jika kata merupakan palindrom, false jika tidak},
   {asumsi panjang kata maksimum adalah 30 karakter} */
boolean isPalindrom(char kata[30]) {
    // kamus lokal
	int p, i, start;
    char c;
    Tstack T;
    boolean hasil;
	
	// algoritma
	hasil = true;
    p = strlen(kata);

    if (p == 0) {
		return false;
	}

    createStack(&T);

    // push setengah pertama
    for (i = 0; i < p/2; i++) {
        push(&T, kata[i]);
    }

    // kalau ganjil, skip satu karakter tengah
    if (p % 2 == 1)
        start = p/2 + 1;
    else
        start = p/2;

    // cek setengah kedua
    for (i = start; i < p; i++) {
        pop(&T, &c);
        if (c != kata[i]) {
            hasil = false;
            return hasil;
        }
    }

    return hasil;
}

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN (Tstack *T, int N) {
	// kamus lokal
	int i;

	// algoritma
	for (i = 1; i <= N; i++) {
		printf("Masukan elemen pada index ke-%d: ", i);
		scanf(" %c", &(*T).wadah[i]);
	}

	(*T).top = N;
}
