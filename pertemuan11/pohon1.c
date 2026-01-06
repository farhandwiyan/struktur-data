/* File : pohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124140137 - Farhan Dwiyan Akbar */
/* Tanggal : 27 - November - 2025*/

#include <stdio.h>
#include <stdlib.h>

#include "pohon1.h"

/************************ PROTOTYPE ************************/
/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* function AlokasiTree( E: infotype)-> bintree */
/* {menghasilkan alokasi memori pohon dengan info=E, left=NIL, right=NIL  } */
bintree AlokasiTree(infotype E) {
    //kamus lokal
    bintree P;

    //algoritma
    P = (bintree)malloc(sizeof(node));
    if (P != NIL) {
        info(P) = E;
        left(P) = NIL;
        right(P) = NIL;
    }
    return P;
}
 
/* procedure DealokasiTree (input/output P:bintree) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian bintree P} */
void DealokasiTree (bintree *P) {
  // kamus lokal
  
  // algoritma
  if (*P != NIL) {
    free(*P);
    *P = NIL;
  }
}
/********** PEMBUATAN bintree KOSONG ***********/
/* function Tree(Akar:infotype, Left:BinTree, Right:BinTree)-> BinTree
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
/*representasi logik fungsi*/
bintree Tree (infotype akar, bintree left, bintree right) {
    //kamus lokal
    bintree P;

    //algoritma
    P = AlokasiTree(akar);
    if (P != NIL) {
        left(P) = left;
        right(P) = right;
    }
    return P;
}

/****** SELEKTOR *****/
/*function GetLeft (P : BinTree) -> BinTree
{ Mengirimkan Anak Kiri pohon biner P }*/
bintree GetLeft(bintree P) {
  // kamus lokal

  // algoritma
  return left(P);
}

/*function GetRight (P : BinTree) -> BinTree
{ Mengirimkan Anak Kanan pohon biner P }*/
bintree GetRight(bintree P) {
  // kamus lokal

  // algoritma
  return right(P);
}

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree) --> boolean 
   {mengembalikan true bila bintree L kosong} */
boolean IsEmptyTree (bintree P) {
  // kamus lokal

  // algoritma
  return P == NIL;
}

/* function IsDaun (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree P) {
  // kamus lokal

  // algoritma
  if (!IsEmptyTree(P)) {  // jika tidak kosong
    return GetRight(P) == NIL && GetLeft(P) == NIL;
  } else {  // jika kosong
    return False;
  }
}

/* function IsBiner (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree P) {
  // kamus lokal

  // algoritma
  if (!IsEmptyTree(P)) {  // jika tidak kosong
    if (GetLeft(P) != NIL && GetRight(P) != NIL) {  // jika left dan right != NIl
      return True;
    } else {  // jika left dan right = NIl
      return False;
    }
  } else {  // jika kosong
    return False;
  }
}

/* function IsUnerLeft(P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree P) {
  // kamus lokal

  // algoritma
  if (!IsEmptyTree(P)) {  // jika tidak kosong
    if (GetLeft(P) != NIL && GetRight(P) == NIL) {  // jika right kosong dan left tidak kosong
      return True;
    } else {  // jika left kosong dan right tidak kosong atau right kosong dan left kosong
      return False;
    }
  } else {  // jika kosong
    return False;
  }
}

/* function IsUnerRight(P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree P) {
  // kamus lokal

  // algoritma
  if (!IsEmptyTree(P)) {  // jika tidak kosong
    if (GetRight(P) != NIL && GetLeft(P) == NIL) {  // jika right tidak kosong dan left kosong
      return True;
    } else {  // jika right kosong dan left tidak kosong atau left kosong dan right kosong
      return False;
    }
  } else {  // jika kosong
    return False;
  }
}

/*PENELUSURAN*/
/* procedure PrintPrefix(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier lengkap} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void PrintPrefix(bintree P) {
    //kamus lokal
    
    //algoritma 
    if (P == NIL) {
        printf("()");
    } else {
        printf("%c(",info(P));
        PrintPrefix(left(P));
        printf(",");
        PrintPrefix(right(P));
        printf(")");
    }
}

/* function NbElm(P:bintree) --> integer
{ menghitung banyaknya elemen bintree P} */
int NbElm(bintree P) {
  // kamus lokal

  // algoritma
  if (!IsEmptyTree(P)) {  // jika tidak kosong
    if (IsDaun(P)) {  // jika P = daun
      return 1;
    } else {  // jika P != daun
      return 1 + NbElm(left(P)) + NbElm(right(P));
    }
  } else {  // jika kosong
    return 0;
  }
}

/* function NbDaun(P:BinTree)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree P) {
  // kamus lokal

  // algoritma
  if (!IsEmptyTree(P)) {  // jika tidak kosong
    if (IsDaun(P)) {  // jika P = daun
      return 1;
    } else {  // jika P != daun
      return NbDaun(left(P)) + NbDaun(right(P));
    }
  } else {  // jika kosong
    return 0;
  }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int max2(int a, int b) {
  // kamus lokal

  // algoritma
  if (a > b) {  // jika a lebih besar dari b
    return a;
  } else {  // jika b lebih besar dari a
    return b;
  }
}

/* function Tinggi(P:BinTree)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen yaitu 0 }*/
int Tinggi(bintree P) {
  // kamus lokal

  // algoritma
  if (!IsEmptyTree(P)) {  // jika tidak kosong
    if (IsDaun(P)) {  // jika P = daun
      return 0;
    } else {  // jika P != daun
      return 1 + max2(Tinggi(left(P)), Tinggi(right(P)));
    }
  } else {  // jika kosong
    return 0;
  }
}

/*** PENCARIAN ***/
/*function SearchX(P:BinTree, X:infotype) -> boolean 
{ Mengirimkan true jika ada node dari P yang bernilai X }*/
boolean SearchX(bintree P, infotype X) {
  // kamus lokal

  // algoritma
  if (!IsEmptyTree(P)) {  // jika tidak kosong
    if (info(P) == X) { // jika ketemu
      return True;
    } else {  // jika tidak ketemu
      return SearchX(left(P), X) || SearchX(right(P), X);
    }
  } else {  // jika kosong
    return False;
  }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(bintree *P, infotype X, infotype Y) {
  // kamus lokal

  // algoritma
  if (!IsEmptyTree(*P)) { // jika tidak kosong
    if (info(*P) == X) {  // jika ketemu
      info(*P) = Y; // ganti elemen P dengan Y
    } else {  // jika tidak ketemu
      UpdateX(&left(*P), X, Y);
      UpdateX(&right(*P), X, Y);
    }
  } // jika kosong, maka tidak melakukan apa-apa
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(P:BinTree, X:infotype) -> integer 
{ Mengirimkan banyaknya node dari P yang bernilai X }*/
int CountX(bintree P, infotype X) {
  // kamus lokal

  // algoritma
  if (!IsEmptyTree(P)) {  // jika tidak kosong
    if (info(P) == X) { // jika ketemu
      return 1 + CountX(left(P), X) + CountX(right(P), X); 
    } else {  // jika tidak ketemu
      return CountX(left(P), X) + CountX(right(P), X);
    }
  } else {  // jika kosong
    return 0;
  }
}

/*function IsSkewLeft (P : BinTree)-> boolean 
{ Mengirim true jika P adalah pohon condong kiri } */
boolean IsSkewLeft (bintree P) {
  // kamus lokal

  // algoritma
  if (!IsEmptyTree(P)) {  // jika tidak kosong
    if (GetRight(P) == NIL) { // jika right kosong
      return IsSkewLeft(left(P));
    } else {  // jika right tidak kosong
      return False;
    }
  } else {  // jika kosong
    return True;
  }
}

/*function IsSkewRight (P : BinTree) -> boolean
{ Mengirim true jika P adalah pohon condong kanan }*/
boolean IsSkewRight (bintree P) {
  // kamus lokal

  // algoritma
  if (!IsEmptyTree(P)) {  // jika tidak kosong
    if (GetLeft(P) == NIL) { // jika left kosong
      return IsSkewRight(right(P));
    } else {  // jika left tidak kosong
      return False;
    }
  } else {  // jika kosong
    return True;
  }
}

/* procedure PrintPrefixRingkas(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier ringkas} */
/*contoh: A(B(( ),D),C)*/
void PrintPrefixRingkas(bintree P) {
  // kamus lokal

  // algoritma
  if (!IsEmptyTree(P)) {  // jika tidak kosong
    if (!IsDaun(P)) { // jika P bukan daun
      printf("%c(", info(P));
      PrintPrefixRingkas(left(P));
      printf(",");
      PrintPrefixRingkas(right(P));
      printf(")");
    } else {  // jika P adalah daun
      printf("%c", info(P));
    }
  } else {  // jika kosong
    printf("()");
  }
}

/*function LevelX(P:BinTree, X:infotype)-> integer
{ Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }*/
int LevelX(bintree P, infotype X) {
  // kamus lokal

  // algoritma
  if (!IsEmptyTree(P)) {  // jika tidak kosong
    if (info(P) == X) { // jika ketemu
      return 1;
    } else {  // jika tidak ketemu
      if (LevelX(left(P), X) > 0) { // jika ketemu di kiri
        return 1 + LevelX(left(P), X);  
      }

      if (LevelX(right(P), X) > 0) {  // jika ketemu di kanan
        return 1 + LevelX(right(P), X);
      }

      return 0; // jika tidak ketemu
    }
  } else {  // jika kosong
    return 0;
  }
}

/*function CountLevel(P:BinTree, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevel(bintree P, int T) {
  // kamus lokal

  // algoritma
  if (!IsEmptyTree(P) && T > 0) { // jika tidak kosong dan T > 0
    if (T == 1) { // jika T = 1
      return 1;
    } else {  // jika T != 1
      return CountLevel(left(P), T - 1) + CountLevel(right(P), T - 1);
    }
  } else {  // jika kosong atau T <= 0
    return 0;
  }
}

/*procedure PrintLevel( input P:bintree, input N: integer )
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N}*/
void PrintLevel(bintree P, int N) {
  // kamus lokal

  // algoritma
  if (!IsEmptyTree(P) && N > 0) { // jika tidak kosong dan N > 0
    if (N == 1) {
      printf("%c ", info(P));
    } else {
      PrintLevel(left(P), N - 1);
      PrintLevel(right(P), N - 1);
    }
  }
}

/*function GetDaunTerkiri(bintree P)-> infotype 
{mengembalikan nilai info daun terkiri, bila tidak ada, hasilnya '#' }*/
infotype GetDaunTerkiri(bintree P) {
  // kamus lokal

  // algoritma
  if (!IsEmptyTree(P)) {  // jika tidak kosong
    if (!IsDaun(P)) { // jika P bukan daun
      if (IsUnerLeft(P)) {  // jika hanya punya anak kiri
        return GetDaunTerkiri(left(P));
      } else {  // jika hanya punya anak kanan
        return GetDaunTerkiri(right(P));
      }
    } else {  // jika P adalah daun
      return info(P);
    }
  } else {  // jika kosong
    return '#';
  }
}

/*function FrekuensiX(P:bintree, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran bintree P }*/
float FrekuensiX(bintree P, infotype X) {
  // kamus lokal

  // algoritma
  if (NbElm(P) > 0) { // jika banyaknya elemen > 0
    return (float) CountX(P, X) / (float) NbElm(P);
  } else {  // jika banyaknya elemen <= 0
    return 0;
  }
}

/*function CountVocal(P:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam bintree P}*/
int CountVocal(bintree P) {
  // kamus lokal
  infotype c;

  // algoritma
  if (!IsEmptyTree(P)) {  // jika tidak kosong
    c = info(P);  // simpan elemen pada P ke c
    if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' ||
        c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O') { // jika c = vocal
          return 1 + CountVocal(left(P)) + CountVocal(right(P));
    } else {  // jika c bukan vocal
      return CountVocal(left(P)) + CountVocal(right(P));
    }
  } else {  // jika kosong
    return 0;
  }
}

/*procedure PrintVocal( input P:bintree) */
/*{ I.S.: P terdefinisi; F.S.: -
Proses: menampilkan semua huruf vokal dalam bintree P}*/
void PrintVocal(bintree P) {
  // kamus lokal
  infotype c;

  // algoritma
  if (!IsEmptyTree(P)) {  // jika tidak kosong
    c = info(P);  // simpan elemen P ke c
    if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' ||
        c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O') { // jika c = vocal
          printf("%c ", c); // tampilkan c
    }
    
    PrintVocal(left(P));
    PrintVocal(right(P));
  } // jika kosong, maka tidak melakukan apa-apa
}

/*function CountConsonant(P:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf konsonan dalam bintree L}*/
int CountConsonant(bintree P) {
  // kamus lokal
  infotype c;

  // algoritma
  if (!IsEmptyTree(P)) {  // jka tidak kosong
    c = info(P);  // simpan elemen P ke c
    if (!(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' ||
        c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O')) { // jika c != vocal
         return 1 + CountConsonant(left(P)) + CountConsonant(right(P));
    } else {  // jika c = vocal
      return CountConsonant(left(P)) + CountConsonant(right(P));
    }
  } else {  // jika kosong
    return 0;
  }
}

/*procedure PrintConsonant( input P:bintree) */
/*{ I.S.: P terdefinisi; F.S.: -
Proses: menampilkan semua huruf konsonan dalam bintree P}*/
void PrintConsonant(bintree P) {
  // kamus lokal
  infotype c;

  // algoritma
  if (!IsEmptyTree(P)) {  // jika tidak kosong
    c = info(P);  // simpan elemen P ke c
    if (!(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' ||
        c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O')) { // jika c != vocal
          printf("%c ", c); // tampilkan c
    }
    
    PrintConsonant(left(P));
    PrintConsonant(right(P));
  } // jika kosong, maka tidak melakukan apa-apa
}

/*function Modus(P:bintree) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam bintree L}*/
char Modus(bintree P) {
  // kamus lokal
  int frek_kiri, frek_kanan, frek_akar;
  infotype kiri, kanan, akar;

  // algoritma
  if (!IsEmptyTree(P)) {  // jika tidak kosong
    if (NbElm(P) == 1) {  // jika jumlah elemen = 1
      return info(P);
    } else {  // jika jumlah elemen > 1
      akar = info(P);    
      kiri = Modus(left(P));
      kanan = Modus(right(P));

      frek_akar  = CountX(P, akar);
      frek_kiri = CountX(P, kiri);
      frek_kanan = CountX(P, kanan);

      // bandingkan  akar, kiri, dan kanan
      if (frek_akar >= frek_kiri && frek_akar >= frek_kanan) {
        return akar;
      }

      if (frek_kiri > frek_kanan) {
        return kiri;
      } else {
        return kanan;
      }
    }
  } else {  // jika kosong
    return '#'; // asumsi
  }
}