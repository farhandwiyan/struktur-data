/* Program   : mtabel.c */
/* Deskripsi : Aplikasi driver modul Tabel */
/* NIM/Nama  : 24060124140137 - Farhan Dwiyan Akbar */
/* Tanggal   : 11/09/2025 */
/***********************************/
#include <stdio.h>
#include "tabel.h"

int main() {
    // kamus
    Tabel T1;
    Tabel T2;
    Tabel T3;
    Tabel T4;
    int pos;
    char x;

    // algoritma
    printf("=== Test Uji Modul Tabel ===\n");

    printf("\n=== Tabel Sebelum Diisi ===\n");
    createTable(&T1);
    printTable(T1);

    printf("\n=== getSize ====\n");
    printf("size pada T1 = %d\n", getSize(T1));

    printf("\n=== isEmptyTable ====\n");
    printf("Apakah T1 kosong = %d\n", isEmptyTable(T1));

    printf("\n=== Tabel Setelah Diisi ===\n");
    addXTable(&T1, 'K');
    addXTable(&T1, 'A');
    addXTable(&T1, 'C');
    addXTable(&T1, 'D');
    addXTable(&T1, 'E');
    addXTable(&T1, 'A');
    addXTable(&T1, 'F');
    addXTable(&T1, 'H');
    addXTable(&T1, 'K');
    addXTable(&T1, 'K');
    viewTable(T1);

    printf("\n=== isFullTable ===\n");
    printf("Apakah T1 full = %d\n", isFullTable(T1));

    printf("\n=== searchX ===\n");
    x = 'C';
    searchX(T1, x, &pos);
    printf("Posisi %c dalam T1 berada di index = %d\n", x, pos);
    x = 'Z';
    searchX(T1, x, &pos);
    printf("Posisi %c dalam T1 berada di index = %d\n", x, pos);

    printf("\n=== CountX ===\n");
    x = 'A';
    printf("Nilai %c pada tabel T1 berjumlah = %d\n", x, countX(T1, x));
    x = 'X';
    printf("Nilai %c pada tabel T1 berjumlah = %d\n", x, countX(T1, x));

    printf("\n=== CountVokal ===\n");
    printf("Jumlah huruf vokal dalam tabel = %d\n", countVocal(T1));

    // buat T2
    createTable(&T2);
    addXTable(&T2, 'A');
    addXTable(&T2, 'B');
    addXTable(&T2, 'C');
    addXTable(&T2, 'D');
    addXTable(&T2, 'E');

    printf("\n=== addUniqueTable ===\n");
    x = 'X';
    printf("Tambahkan %c pada T2 : ", x);
    addUniqueXTable(&T2, x);
    viewTable(T2);
    x = 'A';
    printf("Tambahkan %c pada T2 : ", x);
    addUniqueXTable(&T2, x);
    viewTable(T2);

    printf("\n=== Modus ===\n");
    printf("Elemen yang paling sering muncul di T1 = %c\n", Modus(T1));
    printf("Elemen yang paling sering muncul di T2 = %c\n", Modus(T2));

    printf("\n=== Populate Table ===\n");
    populateTable(&T4, 6);
    printf("\nIsi Tabel T4 : \n");
    viewTable(T4);
    
    printf("\n=== isEqual ===\n");
    printf("Status T1 dan T2 = %d\n", isEqualTable(T1, T2));

    // buat T3
    createTable(&T3);
    addXTable(&T3, 'A');
    addXTable(&T3, 'B');
    addXTable(&T3, 'C');
    addXTable(&T3, 'D');
    addXTable(&T3, 'E');
    addXTable(&T3, 'X');
    printf("Status T2 dan T3 = %d\n", isEqualTable(T2, T3));

    printf("\n=== getInverseTable ===\n");
    printf("Tabel T3 sebelum di inverse :\n");
    viewTable(T3);
    printf("\nTabel T3 setelah di inverse :\n");
    viewTable(getInverseTable(T3));

    printf("\n=== inverseTable ===\n");
    printf("Tabel T1 sebelum di inverse :\n");
    viewTable(T1);
    printf("\nTabel T1 setelah di inverse :\n");
    inverseTable(&T1);
    viewTable(T1);

    printf("\n=== delXTable ===\n");
    x = 'D';
    printf("Tabel T2 sebelum delete %c :\n", x);
    viewTable(T2);
    printf("\nTabel T2 seteah delete %c :\n", x);
    delXTable(&T2, x);
    viewTable(T2);

    printf("\n=== delTable ===\n");
    printf("Tabel T3 sebelum delete pada idx ke-1:\n");
    viewTable(T3);
    printf("\nTabel T3 setelah delete pada idx ke-1 :\n");
    delTable(&T3, 1);
    viewTable(T3);

    printf("\n=== delAllXTable ===\n");
    x = 'K';
    printf("Tabel T1 sebelum delete %c :\n", x);
    viewTable(T1);
    printf("\nTabel T1 setelah delete %c :\n", x);
    delAllXTable(&T1, x);
    viewTable(T1);

    printf("\n=== sortAsc ===\n");
    printf("Tabel T1 sebelum sortAsc :\n");
    viewTable(T1);
    printf("\nTabel T1 setelah sortAsc :\n");
    sortAsc(&T1);
    viewTable(T1);

    printf("\n=== sorDesc ===\n");
    printf("Tabel T3 sebelum sortDesc :\n");
    viewTable(T3);
    printf("\nTabel T3 setelah sortDesc :\n");
    sortDesc(&T3);
    viewTable(T3);

    return 0;
}