/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : Farhan Dwiyan Akbar - 24060124140137 */
/* Tanggal   : 04/09/2025 */
/***********************************/
#include <stdio.h>
#include "titik.h"

int main() {
	//kamus main
	Titik T1;
    Titik T2;
    Titik T3;
    Titik T4;
	
	//algoritma
	printf("Halo, ini driver modul Titik \n");

    printf("\n=== getAbsis dan getOrdinat ===");
	makeTitik(&T1, 4, 5);
	printf("\nNilai absis T1 = %d", getAbsis(T1));
    printf("\nNilai ordinat T1 = %d\n", getOrdinat(T1));

    printf("\n=== SetAbsis dan setOrdinat===");
    makeTitik0(&T2); // buat titik dengan absis dan ordiant 0

    // sebelum diubah
    printf("\nNilai absis T2 sebelum diubah = %d", getAbsis(T2));
    printf("\nNilai ordinat T2 sebelum diubah = %d\n", getOrdinat(T2));
    
    // setelah diubah
    setAbsis(&T2, 5);
    setOrdinat(&T2, 7);
    printf("\nNilai absis T2 setelah diubah = %d", getAbsis(T2));
    printf("\nNilai ordinat T2 setelah diubah= %d\n", getOrdinat(T2));
    
    // cek isOrigin
    printf("\n=== isOrigin ===");
    makeTitik0(&T3);
    printf("\nApakah isOrigin pada T1 (%d,%d) = %d", getAbsis(T1), getOrdinat(T1), isOrigin(T1));
    printf("\nApakah isOrigin pada T3 (%d,%d) = %d\n", getAbsis(T3), getOrdinat(T3), isOrigin(T3));
    
    // cek isOnSumbuX
    printf("\n=== isOnSumbuX ===");
    printf("\nApakah T1 (%d,%d) berada di sumbu X = %d", getAbsis(T1), getOrdinat(T1), isOnSumbuX(T1));
    printf("\nApakah T3 (%d,%d) berada di sumbu X = %d\n", getAbsis(T3), getOrdinat(T3), isOnSumbuX(T3));

    // cek isOnSumbuY
    printf("\n=== isOnSumbuY ===");
    printf("\nApakah T1 (%d,%d) berada di sumbu Y = %d", getAbsis(T1), getOrdinat(T1), isOnSumbuY(T1));
    setAbsis(&T1, 0); // ubah absis T1 menjadi 0
    printf("\nApakah T1 (%d,%d) setelah absis berubah berada di sumbu Y = %d\n", getAbsis(T1), getOrdinat(T1), isOnSumbuY(T1));
    
    // cek isEqual
    printf("\n=== isEqual ===");
    makeTitik(&T4, 0, 5); // buat T4 dengan x = 4 dan y = 0
    printf("\nApakah T1 dan T4 sama = %d", isEqual(T1, T4));
    printf("\nApakah T1 dan T2 sama = %d\n", isEqual(T1, T2));

    // test prosedur geser
    printf("\n=== geser ===");
    printf("\nT3 sebelum digeser = (%d, %d)", getAbsis(T3), getOrdinat(T3));
    geser(&T3, 2, 4);
    printf("\nT3 setelah digeser = (%d, %d)\n", getAbsis(T3), getOrdinat(T3));
    
    printf("\nT4 sebelum digeser = (%d, %d)", getAbsis(T4), getOrdinat(T4));
    geser(&T4, 3, 10);
    printf("\nT4 setelah digeser = (%d, %d)\n", getAbsis(T4), getOrdinat(T4));
    
    // test prosedur refleksiX
    printf("\n=== refleksiX ===");
    printf("\nT3 sebelum direfleksikan terhadap sumbu X = (%d, %d)\n", getAbsis(T3), getOrdinat(T3));
    refleksiX(&T3);
    printf("T3 setelah direfleksikan terhadap sumbu X = (%d, %d)\n", getAbsis(T3), getOrdinat(T3));
	
    // test prosedur refleksiY
    printf("\n=== refleksiY ===");
    printf("\nT4 sebelum direfleksikan terhadap sumbu Y = (%d, %d)\n", getAbsis(T4), getOrdinat(T4));
    refleksiY(&T4);
    printf("T4 setelah direfleksikan terhadap sumbu Y = (%d, %d)\n", getAbsis(T4), getOrdinat(T4));
	
    // test prosedur dilatasi
    printf("\n=== dilatasi ===");
    printf("\nT2 sebelum dilatasi = (%d, %d)\n", getAbsis(T2), getOrdinat(T2));
    dilatasi(&T2, 3);
    printf("T2 setelah dilatasi = (%d, %d)\n", getAbsis(T2), getOrdinat(T2));
	
    // test prosedur dilatasiX
    printf("\n=== dilatasiX ===");
    printf("\nT1 sebelum dilatasi  = (%d, %d)\n", getAbsis(T1), getOrdinat(T1));
    dilatasiX(&T1, T3, 4);
    printf("T1 setelah dilatasi  = (%d, %d)\n", getAbsis(T1), getOrdinat(T1));
    
    // test kuadran
    printf("\n=== kuadran ===");
    printf("\nT1 berada di kuadran = %d\n", kuadran(T1));
    printf("T2 berada di kuadran = %d\n", kuadran(T2));
    printf("T3 berada di kuadran = %d\n", kuadran(T3));
    printf("T4 berada di kuadran = %d\n", kuadran(T4));
	
    return 0;
}