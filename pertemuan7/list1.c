/* File 		: list1.c */
/* Deskripsi 	: realisasi body ADT list berkait representasi fisik pointer */
/* NIM & Nama : 24060124140137 - Farhan Dwiyan Akbar */
/* Tanggal    : 6 November 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

/********* manajemen memori ********/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) {
	//kamus lokal
	address P;

	//algoritma
	P = (address) malloc(sizeof(Elm));

	if (P != NIL) { //ruang memori tersedia
		info(P) = E;
		next(P) = NIL;
	}

	return P;
}

/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke NIL  
	Proses: Melakukan pengosongan address P} */
void Dealokasi (address P) {
	//kamus lokal
	
	//algoritma
	if ( P != NIL ) {
		free(P);
	}
}

/** PEMBUATAN LIST KOSONG **/
/* Procedure CreateList(output L:List1) */
void CreateList (List1 *L) {
	//kamus lokal

	//algoritma
	First(*L) = NIL;
}

/** TEST LIST KOSONG **/
/* function IsEmptyList(L:List1) --> boolean */
boolean IsEmptyList (List1 L){
	if (First(L) == NIL) {
		return true;
	} else {
		return false;
	}
}

/**************** PENELUSURAN ****************/
/*procedure PrintList(input L:List1)
{I.S. L terdefinisi; F.S. :-}
{Proses: menampilkan info semua elemen list L} */
void PrintList(List1 L){
	//kamus lokal 
	address P;

	//algoritma
	P = First(L);
	if (P != NIL) {
		printf("\nElemen = ");

		do {
			printf("\t%c", info(P));
			P = next(P);
		} while( P != NIL );
	}

    printf("\n");
}


/*function NbElm(L:List1) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List1 L){
	//kamus lokal
	address P;
	int count;

	//algoritma
    P = First(L);
	count = 0;

    while (P != NIL) {
        count++;
        P = next(P);
    }

    return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List1 *L, infotype V ){
	//kamus lokal
	address P;

	//algoritma
	P = Alokasi(V);

	if (IsEmptyList(*L)) {
		First(*L) = P; 
	} else {
		next(P) = First(*L);
		First(*L) = P;
	}
}

/*Procedure InsertVLast(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List1 *L, infotype V ){
	//kamus lokal
	address P;
	address last;

	//algoritma
	P = Alokasi(V);
	last = First(*L);

	if (IsEmptyList(*L)) {
		First(*L) = P; 
	} else {
		while (next(last) != NIL) {
			last = next(last);
		}

		next(last) = P;
	}
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi,  }
{ F.S. L tetap, atau berkurang elemen pertamanya.
Proses: Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List1 *L, infotype *V){
	//kamus lokal
	address P;

	//algoritma
	if (!IsEmptyList(*L)) {
		P = First(*L);
		*V = info (P);
		First(*L) = next(P);
		Dealokasi(P);
	}
	else{
		*V = '#';
	}
}

/*Procedure DeleteVLast(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi }
{ F.S. L tetap atau berkurang elemen terakhirnya.
Proses: Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List1 *L, infotype *V){
    // kamus lokal
    address P, sebelum;

    // algoritma
    if (!IsEmptyList(*L)){
        P = First(*L);
        sebelum = NIL;

        while (next(P) != NIL){
            sebelum = P;
            P = next(P);
        }

        *V = info(P);

        if (sebelum == NIL){
            First(*L) = NIL;
        } else {
            next(sebelum) = NIL;
        }

        Dealokasi(P);
    }
    else{
        *V = '#';
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List1, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Proses: Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List1 L, infotype X, address *A){
	// kamus lokal
	address P;

	//algoritma
	P = First(L);
	*A = NIL;

	while (P != NIL && *A == NIL) {
		if (info(P) == X) {
			*A = P;	
		}

		P = next(P);
	}
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Proses: Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(List1 *L, infotype X, infotype Y){
    // kamus lokal
    address P;

    // algoritma
    P = First(*L);

    while (P != NIL && info(P) != X) {
        P = next(P);
    }

    if (P != NIL) {
        info(P) = Y;
    }
} 

/*Procedure Invers(input/output L:List1)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {'i','t','u'} menjadi {'u','t','i'} }*/
void Invers(List1 *L){
    // kamus lokal
    address prev, curr, nextElmt;

    // algoritma
    if (!IsEmptyList(*L)) {
        prev = NIL;
        curr = First(*L);

        while (curr != NIL) {
            nextElmt = next(curr); 
            next(curr) = prev;      
            prev = curr;            
            curr = nextElmt;       
        }

        First(*L) = prev;  
    }	
}


/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*function CountVocal(L:List1, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List1 L){
    // kamus lokal
    int vocal;
    address P;
    char c;

    // algoritma
    P = First(L);
    vocal = 0;

    while (P != NIL) {
        c = info(P);

        if (c == 'a' || c == 'i' || c =='u' || c =='e' || c == 'o' || c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O') {
            vocal++;
        }

        P = next(P);
    } 

    return vocal;
}

/*function CountX(L:List1, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List1 L, infotype X) {
    // kamus lokal
    int count;
    address P;

    // algoritma
    P = First(L);
    count = 0;

    while (P != NIL) {
        if (info(P) == X) {
            count++;
        }

        P = next(P);
    }

    return count;
}

/*function FrekuensiX(L:List1, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List1 L, infotype X){
	// kamus lokal
	address P;
	int count;
	float frekX;

	// algoritma
	P = First(L);
	count = 0;
	frekX = 0;

	if (!IsEmptyList(L)) {
		while (P != NIL) {
			if (info(P) == X) {
				count++;
			}

			P = next(P);
		}

		frekX = (float) count / (float) NbElm(L);

		return frekX;
	} else {
		return frekX;
	}
}

/*Procedure SearchAllX(input L:List1, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi (1,2,3,...nbElm(L)) kemunculan elemen X dalam list L }*/
void SearchAllX(List1 L, infotype X){
	// kamus lokal
	address P;
	int posisi;
	boolean found;

	// algoritma
	P = First(L);
	posisi = 0;
	found = false;

	if (!IsEmptyList(L)) {
		printf("Elemen %c ditemukan di posisi: ", X);
		while (P != NIL) {
			posisi++;

			if (info(P) == X) {
				printf("%d ", posisi);
				found = true;
			}

			P = next(P);
		}

		// jika tidak ditemukan dalam list
		if (!found) {

			// tampilkan pesan
			printf("%c tidak ditemukan dalam list", X);
		}
	} else {
		printf("List kosong, tidak dapat mencari nilai %c", X);
	}
}

/*Procedure UpdateAllX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau semua elemen bernilai X berubah menjadi Y. 
Proses : mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(List1 *L, infotype X, infotype Y){
	// kamus lokal
	address P;

	// algoritma
	P = First(*L);

	if (!IsEmptyList(*L)) {
		while (P != NIL) {
			if (info(P) == X) {
				info(P) = Y;
			}

			P = next(P);
		}
	}
}

/* Procedure InsertVAfter(input/output L:List1, input V:infotype, input VA:infotype )
{ I.S. List L mungkin kosong, V, S terdefinisi }
{ F.S. L tetap, atau bertambah 1 elemen (VA) pada posisi setelah elemen berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=VA sebagai elemen setelah elemen V list linier L yg mungkin kosong } */
void InsertVAfter(List1 *L, infotype V, infotype VA ){
	// kamus lokal
	address P, A, S;

	// algoritma
	A = Alokasi(VA);
	P = First(*L);

	if (!IsEmptyList(*L)) {
		while (P != NIL && info(P) != V) {
			P = next(P);
		}

		if (P != NIL && info(P) == V) {
			if (next(P) == NIL) {
				next(P) = A;
			} else {
				S = next(P);
				next(P) = A;
				next(A) = S;
			}
		}
	}
}

/*function Modus(L:List1) -> infotype */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
infotype Modus(List1 L){
	// kamus lokal
	address P;
	int frek, frek_max;
	infotype modus;

	// algoritma
	P = First(L);
	modus = info(P);
	
	if (!IsEmptyList(L)) {
		frek_max = 0;
		while (P != NIL) {
			frek = 0;
			frek = CountX(L, info(P));

			if (frek_max < frek) {
				frek_max = frek;
				modus = info(P);
			}

			P = next(P);
		}

		return modus;
	} else {
		return modus;
	}
}

/*function NbModus(L:List1) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int NbModus(List1 L) {
	// kamus lokal
	address P;
	int frek, frek_max;

	// algoritma
	P = First(L);
	frek_max = 0;
	
	if (!IsEmptyList(L)) {
		while (P != NIL) {
			frek = 0;
			frek = CountX(L, info(P));

			if (frek_max < frek) {
				frek_max = frek;
			}

			P = next(P);
		}

		return frek_max;
	} else {
		return frek_max;
	}
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List1, input L2:List1, output L:List1)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List1 L1, List1 L2, List1 *L){
	// kamus lokal
	address last;

	// algoritma
	CreateList(L);
	if (IsEmptyList(L1)) {
		First(*L) = First(L2);
	} else if (IsEmptyList(L2)) {
		First(*L) = First(L1);
	} else {
		First(*L) = First(L1);

		last = First(*L);
		while (next(last) != NIL) {
			last = next(last);
		}
		
		next(last) = First(L2);
	}
}

/*Procedure SplitList(input L:List1, output L1:List1, output L2:List1)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List1 L, List1 *L1, List1 *L2){
	// kamus lokal
	address P;
	int tengah, index;

	// kamus lokal
	CreateList(L1);
	CreateList(L2);

	if (!IsEmptyList(L)) {
		P = First(L);

		tengah = NbElm(L) / 2;
		index = 1;

		while (P != NIL) {
			if (index <= tengah) {
				InsertVLast(L1, info(P));
			} else {
				InsertVLast(L2, info(P));
			}

			P = next(P);
			index++;
		}
	} 
}

/*Procedure CopyList(input L1:List1, output L2:List1)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List1 L1, List1 *L2){
	// kamus lokal
	address P;

	// algoritma
	CreateList(L2);

	if (!IsEmptyList(L1)) {
		P = First(L1);

		while (P != NIL) {
			InsertVLast(L2, info(P));
			P = next(P);
		}
	}
}