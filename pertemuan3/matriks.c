/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : Farhan Dwiyan Akbar - 24060124140137 */
/* Tanggal   : 18/09/2025 */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"

/* KONSTRUKTOR */		
/* procedure initMatriks(output M: Matriks)
	{I.S.: - }
	{F.S.: Matriks M terdefinisi}
	{Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
void initMatriks(Matriks *M) {
    // kamus lokal
    int i, j;

    // algoritma
    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 10; j++) {
            (*M).cell[i][j] = -999;
        }
    }

    (*M).nbaris = 0;
    (*M).nkolom = 0;
}

/* SELEKTOR */
/* function getNBaris(M: Matriks) -> integer
	{mengembalikan banyak baris matriks M yang terisi } */
int getNBaris(Matriks M) {
    return M.nbaris;
}

/* function getNKolom(M: Matriks) -> integer
	{mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M) {
    return M.nkolom;
}

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M) {
    return M.nbaris == 0 && M.nkolom == 0;
}

/* function isFullMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M){
    return M.nbaris == 10 && M.nkolom == 10;
}

/* MUTATOR */
/* procedure addX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
	{Proses: mengisi elemen M.cell dengan nilai X} */
void addX(Matriks *M, int X, int row, int col) {
    if (!isFullMatriks(*M) && row > 0 && col > 0) {
        if ((*M).cell[row][col] == -999) {
            (*M).cell[row][col] = X;

            if (row > getNBaris(*M)) {
                (*M).nbaris = row;
            }

            if (col > getNKolom(*M)) {
                (*M).nkolom = col;
            }
        }
    }
}

/* procedure delX (input/output M:Matriks, input X:integer )
	{I.S.: M terdefinisi, X terdefinisi}
	{F.S.: elemen M.cell berkurang 1}
	{Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX (Matriks *M, int X) {
    // kamus lokal 
    int i, j, k;
    boolean found;
    boolean hasElmt;

    // algoritma
    if (!isEmptyMatriks(*M)) {
        found = false;
        i = 1;

        while ((i <= getNBaris(*M)) && !found) {
            j = 1;

            while ((j <= getNKolom(*M)) && !found) {
                if ((*M).cell[i][j] == X) {
                    (*M).cell[i][j] = -999;
                    found = true;
                } else {
                    j++;
                }
            }
            if (!found) {
                i++;
            }
        }

        if (found) {
            hasElmt = false;
            k = 1;

            // cek apakah terdapat baris yang kosong
            while (k <= getNKolom(*M) && !hasElmt) {
                if ((*M).cell[i][k] != -999) {
                    hasElmt = true;
                } else {
                    k++;
                }
            }

            if (!hasElmt) {
                (*M).nbaris--;
            }

            hasElmt = false;
            k = 1;

            // cek apakah terdapat kolom yang kosong
            while (k <= getNBaris(*M) && !hasElmt) {
                if ((*M).cell[k][j] != -999) {
                    hasElmt = true;
                } else {
                    k++;
                }
            }
            
            if (!hasElmt) {
                (*M).nkolom--;
            }
        }
    }
}

/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
	{proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y) {
    // kamus lokal
    int i, j;
    
    // algoritma
    for (i = 1; i <= x; i++) {
        for (j = 1; j <= y; j++) {
            (*M).cell[i][j] = rand();
        }
    }

    (*M).nbaris = x;
    (*M).nkolom = y;
}

/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
	{proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n) {
    // kamus lokal
    int i, j;

    // algoritma
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) {
                (*M).cell[i][j] = 1;
            } else {
                (*M).cell[i][j] = 0;
            }
        }
    }

    (*M).nbaris = n;
    (*M).nkolom = n;
}

/* OPERASI BACA/TULIS */
/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
void populateMatriks(Matriks *M, int x, int y) {
    // kamus lokal
    int i, j;

    // algoritma
    for (i = 1; i <= x; i++) {
        for (j = 1; j <= y; j++) {
            printf("Masukan elemen pada cell ke-[%d, %d] = ",  i, j);
            scanf("%d", &(*M).cell[i][j]);
        }
    }

    (*M).nbaris = x;
    (*M).nkolom = y;
}

/* procedure printMatriks(input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks M) {
    // kamus lokal
    int i, j;

    // algoritma
    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 10; j++) {
            printf("%5d ", M.cell[i][j]);
        }
        printf("\n");
    }
}

/* procedure viewMatriks (input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks (Matriks M) {
    // kamus lokal
    int i, j;

    // algoritma
    for (i = 1; i <= getNBaris(M); i++) {
        for (j = 1; j <= getNKolom(M); j++) {
            printf("%5d ", M.cell[i][j]);
        }
        printf("\n");
    }
}

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2) {
    // kamus lokal
    int i, j;
    Matriks NMatriks;

    // algoritma
    initMatriks(&NMatriks);

    if (getNBaris(M1) ==  getNBaris(M2) && getNKolom(M1) == getNKolom(M2)) {
        for (i = 1; i <= getNBaris(M1); i++) {
            for (j = 1; j <= getNKolom(M2); j++) {
                NMatriks.cell[i][j] = M1.cell[i][j] + M2.cell[i][j];
            }
        }
        NMatriks.nbaris = getNBaris(M1);
        NMatriks.nkolom = getNKolom(M1);
    }

    return NMatriks;
}

/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2) {
    // kamus lokal
    int i, j;
    Matriks NMatriks;

    // algoritma
    initMatriks(&NMatriks);

    if (getNBaris(M1) ==  getNBaris(M2) && getNKolom(M1) == getNKolom(M2)) {
        for (i = 1; i <= getNBaris(M1); i++) {
            for (j = 1; j <= getNKolom(M2); j++) {
                NMatriks.cell[i][j] = M1.cell[i][j] - M2.cell[i][j];
            }
        }
        NMatriks.nbaris = getNBaris(M1);
        NMatriks.nkolom = getNKolom(M1);
    }

    return NMatriks;
}

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2) {
    // kamus lokal
    int i, j, k;
    int sum;
    Matriks NMatriks;

    // algoritma
    initMatriks(&NMatriks);

    if (getNKolom(M1) == getNBaris(M2)) {
        NMatriks.nbaris = getNBaris(M1);
        NMatriks.nkolom = getNKolom(M2);

        for (i = 1; i <= getNBaris(M1); i++) {
            for (j = 1; j <= getNKolom(M2); j++) {
                sum = 0;
                
                for (k = 1; k <= getNKolom(M1); k++) {
                    sum += M1.cell[i][k] * M2.cell[k][j];
                }

                NMatriks.cell[i][j] = sum;
            }
        }
    }

    return NMatriks;
}

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M1, int x) {
    // kamus lokal
    int i, j;
    Matriks NMatriks;

    // algoritma
    initMatriks(&NMatriks);

    for (i = 1; i <= getNBaris(M1); i++) {
        for (j = 1; j <= getNKolom(M1); j++) {
            NMatriks.cell[i][j] = (x * M1.cell[i][j]);
        }
    }

    NMatriks.nbaris = getNBaris(M1);
    NMatriks.nkolom = getNKolom(M1);

    return NMatriks;
}

/* OPERASI LAINNYA */
/* procedure transposeMatriks(input/output M: Matriks)
	{I.S.: M terdefinisi}
	{F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
	{proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M) {
    // kamus lokal
    int i, j;
    int temp;
    int oldBaris;

    // algoritma
    for (i = 1; i <= getNBaris(*M); i++) {
        for (j = i + 1; j <= getNKolom(*M); j++) {
            temp = (*M).cell[i][j];
            (*M).cell[i][j] = (*M).cell[j][i];
            (*M).cell[j][i] = temp;
        }
    }

    oldBaris = getNBaris(*M);
    (*M).nbaris = getNKolom(*M);
    (*M).nkolom = oldBaris;
}

/* function getTransposeMatriks(M: Matriks)
	{menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M) {
    // kamus lokal
    int i, j;
    int temp;
    Matriks NMatriks;

    // algoritma
    initMatriks(&NMatriks);

    for (i = 1; i <= getNBaris(M); i++) {
        for (j = 1; j <= getNKolom(M); j++) {
            NMatriks.cell[j][i] = M.cell[i][j];
        }
    }

    NMatriks.nbaris = getNKolom(M);
    NMatriks.nkolom = getNBaris(M);

    return NMatriks;
}
/* function addPadding(M: Matriks, input n:integer)
	{menghasilkan matriks baru dari M yang ditambahkan padding 0 sesuai dengan ukuran padding n */
Matriks addPadding(Matriks M, int n) {
    // kamus lokal
    int i, j;
    Matriks NMatriks;

    // algoritma
    initMatriks(&NMatriks);
    NMatriks.nbaris = getNBaris(M) + (n*2);
    NMatriks.nkolom = getNKolom(M) + (n*2);

    // masukan nilai 0 ke dalam matriks NMatriks
    for (i = 1; i <= getNBaris(NMatriks); i++) {
        for (j = 1; j <= getNKolom(NMatriks); j++) {
            NMatriks.cell[i][j] =  0;
        }
    }

    // masukan elemen matriks M di tengah NMatriks
    for (i = 1; i <= getNBaris(M); i++) {
        for (j = 1; j <= getNKolom(M); j++) {
            NMatriks.cell[i + n][j + n] = M.cell[i][j];
        }
    }

    return NMatriks;
}

/* function maxPooling(M: Matriks, input size:integer)
	{menghasilkan matriks hasil max pooling matriks M dengan pool size = size  */
Matriks maxPooling(Matriks M, int size) {
    // kamus lokal
    int i, j, x, y;
    int max;
    int baris, kolom;
    Matriks NMatriks;

    // algoritma
    initMatriks(&NMatriks);
    NMatriks.nbaris = (getNBaris(M)/size);
    NMatriks.nkolom = (getNKolom(M)/size);

    for (i = 1; i <= getNBaris(M); i += size) {
        for (j = 1; j <= getNKolom(M); j += size) {
            max = -9999;

            for (x = i; x < i + size; x++) {
                for (y = j; y < j + size; y++) {
                    if (M.cell[x][y] > max) {
                        max = M.cell[x][y];
                    }
                }
            }

            baris = (i - 1) / size + 1;
            kolom = (j - 1) / size + 1;
            NMatriks.cell[baris][kolom] = max;
        }
    }

    return NMatriks;
}

/* function avgPooling(M: Matriks, input size:integer)
	{menghasilkan matriks hasil average pooling matriks M dengan pool size = size  */
Matriks avgPooling(Matriks M, int size) {
    // kamus lokal
    int i, j, x, y;
    int count;
    int countElmt;
    int avg;
    int baris, kolom;
    Matriks NMatriks;
    
    // algoritma
    initMatriks(&NMatriks);
    NMatriks.nbaris = (getNBaris(M)/size);
    NMatriks.nkolom = (getNKolom(M)/size);

    for (i = 1; i <= getNBaris(M); i += size) {
        for (j = 1; j <= getNKolom(M); j += size) {
            count = 0;
            countElmt = 0;

            for (x = i; x < i + size; x++) {
                for (y = j; y < j + size; y++) {
                    count += M.cell[x][y];
                    countElmt++;
                }
            }

            avg = (count/countElmt);
            baris = (i - 1) / size + 1;
            kolom = (j - 1) / size + 1;
            NMatriks.cell[baris][kolom] = avg;
        }
    }

    return NMatriks;
}

/* function conv(M: Matriks, K:Matriks)
	{menghasilkan matriks hasil konvolusi matriks M dengan kernel K  */
Matriks conv(Matriks M, Matriks K) {
    // kamus lokal
    int i, j, x, y;
    int sum;
    Matriks NMatriks;

    // algoritma
    initMatriks(&NMatriks);
    NMatriks.nbaris = getNBaris(M) - getNBaris(K) + 1;
    NMatriks.nkolom = getNKolom(M) - getNKolom(K) + 1;

    for (i = 1; i <= getNBaris(NMatriks); i++) {
        for (j = 1; j <= getNKolom(NMatriks); j++) {
            sum = 0;

            for (x = 1; x <= getNBaris(K); x++) {
                for (y = 1; y <= getNKolom(K); y++) {
                    sum += M.cell[i + x - 1][j + y - 1] * K.cell[x][y];
                }
            }

            NMatriks.cell[i][j] = sum;
        }
    }

    return NMatriks;
}

/* OPERASI PENCARIAN*/
/* procedure searchX( input M:Matriks, input X: integer, output row: integer, output col: integer )
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: row berisi indeks baris dan col berisi indeks kolom ketemu X di M.cell, atau -999 jika tidak ketemu}
	{Proses: mencari elemen bernilai X dalam M.cell} */
void searchX(Matriks M, int X, int *row, int *col) {
    // kamus lokal
    int i, j;
    boolean found;

    // algoritma
    i = 1;
    found = false;

    while (i <= getNBaris(M) && !found) {
        j = 1;

        while (j <= getNKolom(M) && !found) {
            if (M.cell[i][j] == X) {
                found = true;
                *row = i;
                *col = j;
            } else {
                j++;
            }
        }

        i++;
    }

    if (!found) {
        *row = -999;
        *col = -999;
    }
}

/* function countX (M:Matriks, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam M.cell} */
int countX (Matriks M, int X) {
    // kamus lokal
    int i, j;
    int count;

    // algoritma
    count = 0;

    for (i = 1; i <= getNBaris(M); i++) {
        for (j = 1; j <= getNKolom(M); j++) {
            if (M.cell[i][j] == X) {
                count++;
            }
        }
    }

    return count;
}
