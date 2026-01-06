/* Program   : mmatriks.c */
/* Deskripsi : driver ADT matriks integer */
/* NIM/Nama  : Farhan Dwiyan Akbar - 24060124140137*/
/* Tanggal   : 18/09/2025 */
/***********************************/

#include <stdio.h>
#include "matriks.h"

int main() {
    // kamus
    Matriks M1, M2, M3, M4, M5, M6, MHasil, Kernel;
    int row, col;

    // algoritma
    printf("=== Tes Uji Modul Matriks ===\n");

    // inisialisasi matriks
    printf("\n=== Matriks sebelum diisi ===\n");
    initMatriks(&M1);
    printMatriks(M1);
    printf("\nApakah matriks M1 kosong = %d", isEmptyMatriks(M1));
    printf("\njumlah baris dalam matriks M1 = %d\n", getNBaris(M1));
    printf("jumlah kolom dalam matriks M1 = %d\n", getNKolom(M1));

    // isi matriks
    printf("\n=== Matriks setelah diisi (addX) ===\n");
    addX(&M1, 1, 1, 1);
    addX(&M1, 2, 1, 2);
    addX(&M1, 3, 1, 3);
    addX(&M1, 4, 2, 1);
    addX(&M1, 5, 2, 2);
    addX(&M1, 6, 2, 3);
    viewMatriks(M1);
    printf("\nApakah matriks M1 kosong = %d", isEmptyMatriks(M1));
    printf("\njumlah baris dalam matriks M1 = %d\n", getNBaris(M1));
    printf("jumlah kolom dalam matriks M1 = %d\n", getNKolom(M1));

    // delX
    printf("\n=== delX ===\n");
    printf("Matriks M1 sebelum elemen dihapus :\n");
    viewMatriks(M1);
    delX(&M1, 3); 
    printf("\nHapus elemen 3 dalam Matriks M1 :\n");
    viewMatriks(M1);
    delX(&M1, 6);
    printf("\nHapus elemen 6 dalam Matriks M1 :\n");
    viewMatriks(M1);

    // isiMatriksIdentitas
    printf("\n=== isiMatriksIdentitas ===\n");
    printf("Matriks M2 setelah diisi matriks identitas :\n");
    isiMatriksIdentitas(&M2, 4);
    viewMatriks(M2);

    // isiMatriksRandom 
    printf("\n=== isiMatriksRandom ===\n");
    isiMatriksRandom(&M3, 4, 4);
    printf("Isi Matriks M3 setelah diisi bilangan random : \n");
    viewMatriks(M3);

    // populateMatriks
    printf("\n=== populateMatriks ===\n");
    populateMatriks(&M6, 3, 2);
    printf("\nMatriks M6 :\n");
    viewMatriks(M6);

    // transposeMatriks
    printf("\n=== transposeMatriks ===\n");
    printf("Matriks M1 sebelum ditranspose :\n");
    viewMatriks(M1);
    transposeMatriks(&M1);
    printf("\nMatriks M1 setelah ditranpose :\n");
    viewMatriks(M1);

    // getTransposeMatriks
    printf("\n=== getTransposeMatriks ===\n");
    printf("Matriks M3 sebelum ditranspose :\n");
    viewMatriks(M3);
    printf("\nMatriks M3 setelah ditranpose :\n");
    MHasil = getTransposeMatriks(M3);
    viewMatriks(MHasil);

    // addMatriks 
    printf("\n=== addMatriks ===\n");
    initMatriks(&M4);
    addX(&M4, 10, 1, 1);
    addX(&M4, 20, 1, 2);
    addX(&M4, 13, 2, 1);
    addX(&M4, 25, 2, 2);
    printf("Matriks M1 :\n");
    viewMatriks(M1);
    printf("\nMatriks M4 :\n");
    viewMatriks(M4);
    printf("\nHasil penjumlahan Matriks M1 dengan M4 :\n");
    MHasil = addMatriks(M1, M4);
    viewMatriks(MHasil);

    // subMatriks
    printf("\n=== subMatriks ===\n");
    printf("Matriks M1 :\n");
    viewMatriks(M1);
    printf("\nMatriks M4 :\n");
    viewMatriks(M4);
    MHasil = subMatriks(M1, M4);
    printf("\nHasil pengurangan Matriks M1 dengan M4 :\n");
    viewMatriks(MHasil);

    // kaliSkalarMatriks
    printf("\n=== kaliSkalarMatriks ===\n");
    printf("Matriks M1 :\n");
    viewMatriks(M1);
    MHasil = kaliSkalarMatriks(M1, 3);
    printf("\nHasil perkalian skalar sebesar 3 pada Matriks M1 :\n");
    viewMatriks(MHasil);

    // kaliMatriks
    printf("\n=== kaliMatriks ===\n");
    printf("Matriks M1 :\n");
    viewMatriks(M1);
    printf("\nMatriks M4 :\n");
    viewMatriks(M4);
    MHasil = kaliMatriks(M1, M4);
    printf("\nHasil perkalian Matriks M1 dengan M4 :\n");
    viewMatriks(MHasil);

    // addPadding 
    printf("\n=== addPadding ===\n");
    printf("Matriks M1 :\n");
    viewMatriks(M1);
    MHasil = addPadding(M1, 2);
    printf("\nHasil padding pada matriks M1 :\n");
    viewMatriks(MHasil);

    // buat matriks M5
    initMatriks(&M5);
    addX(&M5, 1, 1, 1);
    addX(&M5, 1, 1, 2);
    addX(&M5, 3, 1, 3);
    addX(&M5, 3, 1, 4);
    addX(&M5, 1, 2, 1);
    addX(&M5, 1, 2, 2);
    addX(&M5, 3, 2, 3);
    addX(&M5, 3, 2, 4);
    addX(&M5, 5, 3, 1);
    addX(&M5, 5, 3, 2);
    addX(&M5, 7, 3, 3);
    addX(&M5, 7, 3, 4);
    addX(&M5, 5, 4, 1);
    addX(&M5, 5, 4, 2);
    addX(&M5, 7, 4, 3);
    addX(&M5, 7, 4, 4);

    // maxPooling
    printf("\n=== maxPooling ===\n");
    printf("Matriks M5\n");
    viewMatriks(M5);
    MHasil = maxPooling(M5, 2);
    printf("\nHasil maxPooling pada matriks M5 :\n");
    viewMatriks(MHasil);

    // avgPooling
    printf("\n=== avgPooling ===\n");
    printf("Matriks M5\n");
    viewMatriks(M5);
    MHasil = avgPooling(M5, 2);
    printf("\nHasil avgPooling pada matriks M5 :\n");
    viewMatriks(MHasil);

    // conv
    printf("\n=== conv ===\n");
    initMatriks(&Kernel);
    addX(&Kernel, 1, 1, 1);
    addX(&Kernel, 0, 1, 2);
    addX(&Kernel, -1, 2, 1);
    addX(&Kernel, 1, 2, 2);
    printf("Kernel:\n");
    viewMatriks(Kernel);
    printf("\nMatriks M5\n");
    viewMatriks(M5);
    MHasil = conv(M5, Kernel);
    printf("\nHasil konvolusi M5 dengan Kernel:\n");
    viewMatriks(MHasil);

    // searchX dan countX 
    printf("\n=== searchX & countX ===\n");
    searchX(M4, 25, &row, &col);
    printf("Elemen 25 pada matriks M4 ditemukan pada baris=%d kolom=%d\n", row, col);
    printf("Jumlah elemen 7 dalam M5 = %d\n", countX(M5, 7));

    printf("\n=== Selesai Uji Coba Matriks ===\n");

    return 0;
}
