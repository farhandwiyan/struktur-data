/* File : pohon2.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* pohon2 melengkapi operator ADT bintree yang ada dalam pohon1 */
/* NIM & Nama : 24060124140137 - Farhan Dwiyan Akbar */
/* Tanggal : 04 - 12 - 2025*/

#include <stdio.h>
#include <stdlib.h>

#include "pohon2.h"

/*PENELUSURAN*/
/* procedure PrintTreeInden (input P : BinTree, input H : integer)
{ I.S. P terdefinisi, h adalah jarak indentasi subpohon }
{ F.S. Semua simpul P ditulis dengan indentasi berjenjang,mirip file explorer} */
void PrintTreeInden(bintree P, int H ) {
    // kamus lokal
    int i;

    // algoritma
    if (!IsEmptyTree(P)) {  // jika tidak kosong
        printf("%c\n", info(P));

        if (!IsEmptyTree(left(P)) || !IsEmptyTree(right(P))) {  // jika kiri atau kanan tidak kosong
            for (i = 0; i < H; i++) {
                printf(" ");
            }
            PrintTreeInden(left(P), H + 3);

            for (i = 0; i < H; i++) {
                printf(" ");
            }
            PrintTreeInden(right(P), H + 3);
        }
    } else {    // jika kosong
        printf("()\n");
    }
}

// /* procedure PrintLevel(input P:bintree, input N:integer)
// {I.S. L terdefinisi; F.S. :-}
// { menampilkan info semua elemen bintree P pada generasi/level N} */
// void PrintLevel(bintree P, int N);

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateAllX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y. Mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(bintree *P, infotype X, infotype Y) {
    if (!IsEmptyTree(*P)) { // jika tidak kosong
        if (info(*P) == X) {    // jika elemen P sama dengan X
            info(*P) = Y;   // ganti elemen P dengan Y
        }

        UpdateAllX(&left(*P), X, Y);
        UpdateAllX(&right(*P), X, Y);
    } 
    
}

/******* PENAMBAHAN ELEMEN bintree ********/
/*procedure AddDaunTerkiri (input/output P : BinTree, input X : infotype)
{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri }*/
void AddDaunTerkiri(bintree *P, infotype X) {
    // kamus lokal
    
    // algoritma
    if (IsEmptyTree(*P)) {  // jika kosong
        *P = Tree(X, NIL, NIL);
    } else {    // jika tidak kosong
        if (!IsDaun(*P)) {
            if (!IsEmptyTree(left(*P))) {   // jika kiri tidak kosong
                AddDaunTerkiri(&left(*P), X);
            } else {    // jika kiri kosong
                AddDaunTerkiri(&right(*P), X);
            }
        } else {
            AddDaunTerkiri(&left(*P), X);
        }
    }
}

/*procedure AddDaun (input/Output P : BinTree, input X, Y : infotype, input Kiri : boolean)
{ I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau sebagai anak Kanan X (jika not Kiri) }*/
void AddDaun(bintree *P, infotype X, infotype Y, boolean Kiri) {
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(*P)) { // jika tidak kosong
        if (IsDaun(*P) && info(*P) == X) {  // jika P adalah daun dan elemen P = X
            if (Kiri) { // jika Kiri = True
                left(*P) = Tree(Y, NIL, NIL);
            } else {    // jika Kiri = False
                right(*P) = Tree(Y, NIL, NIL);
            }
        } else {    // jika bukan daun 
            AddDaun(&left(*P), X, Y, Kiri);
            AddDaun(&right(*P), X, Y, Kiri);
        }
    }   // jika kosong tidak akan melakukan apa apa karena tidak memiliki sebuah daun
}

/*procedure InsertX (input/output P : BinTree, input X : infotype)
{ Menghasilkan sebuah pohon P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
void InsertX(bintree *P, infotype X) {
    // kamus lokal

    // algoritma
    if (IsEmptyTree(*P)) {  // jika kosong
        *P = Tree(X, NIL, NIL);
    } else {    // jika tidak kosong
        if (info(*P) != X) {    // jika elemen P != X
            if (X < info(*P)) { // jika X < elemen P
                InsertX(&left(*P), X);
            } else {    // jika X > elemen P
                InsertX(&right(*P), X);
            }
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*procedure DelDaunTerkiri (input/output P : BinTree, output X : infotype)
{ I.S. P tidak kosong }
{ F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang
semula disimpan pada daun terkiri yang dihapus }*/
void DelDaunTerkiri(bintree *P, infotype *X) {
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(*P)) { // jika tidak kosong
        if (!IsDaun(*P)) {  // jika bukan daun
            if (!IsEmptyTree(left(*P))) {   // jika kiri tidak kosong
                DelDaunTerkiri(&left(*P), X);
            } else {    // jika kiri kosong
                DelDaunTerkiri(&right(*P), X);
            }
        } else {    // jika P adalah daun
            *X = info(*P);
            DealokasiTree(&(*P));
        }
    }   // jika kosong maka tidak akan melakukan apa apa karena tidak ada daun
}

/*procedure DelDaun (input/output P : BinTree, input X : infotype)
{ I.S. P tidak kosong, X adalah salah satu daun }
{ F.S. X dihapus dari P }*/
void DelDaun(bintree *P, infotype X) {
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(*P)) { // jika tidak kosong
        if (IsDaun(*P)) {   // jika daun 
            if (info(*P) == X) {    // jika elemen P = X
                DealokasiTree(&(*P));
            }
        } else {    // jika bukan daun
            DelDaun(&left(*P), X);
            DelDaun(&right(*P), X);
        }
    }   // jika kosong maka tidak akan melakukan apa apa karena tidak ada daun
}

/*procedure DeleteX (input/output P : BinTree, input X : infotype)
{ Menghapus simpul bernilai X bila ada dari P, HATI-HATI! }*/
void DeleteX(bintree *P, infotype X) {
    // kamus lokal
    infotype E;

    // algoritma
    if (!IsEmptyTree(*P)) { // jika tidak kosong
        if (info(*P) == X) {    // jika ketemu
            if (IsDaun(*P)) {   // jika P adalah daun
                DealokasiTree(&(*P));
            } else {    // jika P bukan daun
                if (!IsEmptyTree(left(*P))) {   // jika kiri tidak kosong
                    E = info(left(*P));
                    info(*P) = E;
                    DeleteX(&left(*P), E);
                } else {    // jika kanan tidak kosong
                    E = info(right(*P));
                    info(*P) = E;
                    DeleteX(&right(*P), E);
                }
            }
        } else {
            DeleteX(&left(*P), X);
            DeleteX(&right(*P), X);
        }
    }   // jika kosong tidak akan melakukan apa apa
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*KONSTRUKTOR*/
/*function BuildBalanceTree (n : integer) -> BinTree
{ Menghasilkan balanced tree dengan n node, nilai setiap node dibaca dari keyboard }*/
bintree BuildBalanceTree(int n) {
    // kamus lokal
    bintree P;
    int i, tengah;
    infotype E;

    // algoritma
    if (n == 0) {   // jika n = 0
        return P = NIL;    // buat pohon kosong
    } else {    // jika n != 0
        tengah = n / 2;

        scanf(" %c", &E);
        P = AlokasiTree(E);

        if (P != NIL) {
            left(P) = BuildBalanceTree(tengah);

            right(P) = BuildBalanceTree(n - tengah - 1);
        }

        return P;
    }
}

/*PREDIKAT*/
/*function IsBalanceTree (P : BinTree) -> boolean
{ Menghasilkan true jika P seimbang, banyak node kiri ~= kanan }*/
boolean IsBalanceTree(bintree P) {
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(P)) {  // jika tidak kosong
        return (Tinggi(left(P)) - Tinggi(right(P))) <= 1;
    } else {    // jika kosong
        return True;
    }
}

/* function maxTree(P:bintree)->character
{mengembalikan huruf "maksimal" dari elemen P, A<B<C<..<Z }*/
infotype maxTree(bintree P) {
    // kamus lokal
    infotype L, R, E;

    // algoritma
    if (!IsEmptyTree(P)) {  // jika tidak kosong
        E = info(P);
        L = '#';    // nilai ASCII lebih kecil dari [A-Z] dan [a-z]
        R = '#';    // nilai ASCII lebih kecil dari [A-Z] dan [a-z]

        if (!IsEmptyTree(left(P))) {
            L = maxTree(left(P));
        }

        if (!IsEmptyTree(right(P))) {
            R = maxTree(right(P));
        }

        if (L > E) {    // jika kiri > E
            E = L;  // ganti E dengan L
        }

        if (R > E) {    // jika kanan > E
            E = R;  // ganti E dengan R
        }

        return E;
    } else {    // jika kosong
        return '#'; // asumsi: jika kosong akan mengembalikan nilai kosong
    }
}

/* function minTree(P:bintree)->character
{mengembalikan huruf "minimal" dari elemen P, A<B<C<..<Z }*/
infotype minTree(bintree P) {
    // kamus lokal
    infotype L, R, E;

    // algoritma
    if (!IsEmptyTree(P)) {  // jika tidak kosong
        E = info(P);
        L = '{';   // nilai ASCII lebih besar dari [a-z] dan [A-Z]
        R = '{';   // nilai ASCII lebih besar dari [a-z] dan [A-Z]

        if (!IsEmptyTree(left(P))) {
            L = minTree(left(P));
        }

        if (!IsEmptyTree(right(P))) {
            R = minTree(right(P));
        }

        if (L < E) {    // jika kiri lebih kecil dari E
            E = L;
        }

        if (R < E) {    // jika kanan lebih kecil dari E
            E = R;
        }

        return E;
    } else {    // jika kosong
        return '#';     // asumsi: jika kosong akan mengembalikan nilai kosong
    }
}

/*{ Operator KHUSUS Binary Search Tree, node kiri selalu lebih kecil daripada node kanan }

/*function BSearch (P : BinTree, X : infotype) → boolean
{ Mengirimkan true jika ada node dari pohon binary search P yang bernilai X }*/
boolean BSearch(bintree P, infotype X) {
    // kamus lokal

    // algoritma
    if (!IsEmptyTree(P)) {  // jika tidak kosong
        if (info(P) == X) { // jika ketemu
            return True;
        } else {    // jika blm ketemu
            if (info(P) > X) {  // jika elemen P > X
                return BSearch(left(P), X);    // cari di kiri
            } else {    // jika elemen P < X
                return BSearch(right(P), X);   // cari di kanan
            }
        }
    } else {    // jika kosong
        return False;
    }
}

/*function InsSearch (P : BinTree, X : infotype) → BinTree
{ Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
bintree InsSearch(bintree P, infotype X) {
    // kamus lokal

    // algoritma
    if (IsEmptyTree(P)) {   // jika kosong
        P = Tree(X, NIL, NIL);
    } else {    // jika tidak kosong
        if (info(P) != X) { // jika elemen P tidak sama dengan X
            if (info(P) > X) {  // jika elemen P > X
                left(P) = InsSearch(left(P), X);   // teruskan ke kiri
            } else {    // jika elemen P < X 
                right(P) = InsSearch(right(P), X);  // teruskan ke kanan
            }
        }
    }

    return P;
}

/*procedure DelBtree (input/output P : BinTree, input X : infotype)
{ I.S. Pohon binary search P tidak kosong }
{ F.S. Nilai X yang dihapus pasti ada }
{ Sebuah node dg nilai X dihapus }*/
void DelBtree(bintree *P, infotype X) {
    // kamus lokal
    infotype E;

    // algoritma
    if (!IsEmptyTree(*P)) { // jika tidak kosong walaupun diasumsikan pohon tidak kosong
        if (info(*P) == X) {    // jika katemu
            if (IsDaun(*P)) {   // jika P adalah daun
                DealokasiTree((&*P));
            } else {    // jika P bukan daun
                if (!IsEmptyTree(left(*P))) { // jika kiri tidak kosong
                    E = info(left(*P));
                    info(*P) = E;
                    DelBtree(&left(*P), E);
                } else {    // jika kanan tidak kosong
                    E = info(right(*P));
                    info(*P) = E;
                    DelBtree(&right(*P), E);
                }
            }
        } else {    // jika blm ketemu
            if (info(*P) > X) { // jika elemen P > X
                DelBtree(&left(*P), X); // cari di kiri
            } else {    // jika P < X
                DelBtree(&right(*P), X); // cari di kanan
            }
        }
    }
}