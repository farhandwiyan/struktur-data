/* Program   : tqueue2.c */
/* Deskripsi : ADT Queue representasi kontigu dengan array, 
               model II: head bergeser/jelajah */
/* NIM/Nama  : Farhan Dwiyan Akbar - 24060124140137 */
/* Tanggal   : 2/10/2025 */
/***********************************/

#include "tqueue2.h"
#include <stdio.h>

/*function isEmptyQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue2(tqueue2 Q) {
    return Q.head == 0 && Q.tail == 0;
}
 
/*function isFullQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue2(tqueue2 Q) {
    return Q.head == 1 && Q.tail == 5;
}

/*function isOneElement2(Q:tQueue2) -> boolean
{mengembalikan true jika Q berisi 1 elemen}*/
boolean isOneElement2(tqueue2 Q){
    if (isEmptyQueue2(Q)) {
        return false;
    } else {
        return Q.head == Q.tail;
    }
}

/*procedure createQueue2 ( output Q:tQueue2 )
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi head dan tail dengan 0, elemen kosong='#'}*/ 
void createQueue2(tqueue2 *Q) {
    // kamus lokal
    int i;

    // algoritma
    for (i = 1; i <= 5; i++) {
        (*Q).wadah[i] = '#';
    }

    (*Q).head = 0;
    (*Q).tail = 0;
}

/*Function Head2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terdepan} */
int head2(tqueue2 Q) {
    return Q.head;
}

/*Function Tail2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terakhir} */
int tail2(tqueue2 Q) {
    return Q.tail;
}

/*Function InfoHead2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead2(tqueue2 Q) {
    return Q.wadah[head2(Q)];
}

/*Function InfoTail2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail2(tqueue2 Q) {
    return Q.wadah[tail2(Q)];
}

/*function sizeQueue2(Q:tQueue2)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue2(tqueue2 Q) {
    if (isEmptyQueue2(Q)) {
        return 0;
    } else {
        return tail2(Q) - head2(Q) + 1;
    }
}

/*procedure printQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua isi wadah ke layar}*/
void printQueue2(tqueue2 Q) {
    // kamus lokal
    int i;

    // algoritma
    for (i = 1; i <= 5; i++) {
        printf("%c ", Q.wadah[i]);
    }
}

/*procedure viewQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue2(tqueue2 Q) {
    // kamus lokal
    int i;

    // algoritma
    if (!isEmptyQueue2(Q)) {
        for (i = head2(Q); i <= tail2(Q); i++) {
            printf("%c ", Q.wadah[i]);
        }
    } else {
        printf("Queue kosong!\n");
    }
}

/*Function IsTailStop(Q:TQueue2) -> boolean
{mengembalikan true jika Tail tidak dapat lagi geser}
{karena sudah di posisi kapasitas} */
boolean isTailStop(tqueue2 Q) {
    return Q.tail == 5;
}

/*Procedure ResetHead(input/output Q:TQueue2)
{I.S:Tail=kapasitas, head>1; F.S:head=1 }
{Proses: mengembalikan Head ke indeks 1 }
{Elemen selain head ikut bergeser menyesuaikan} */
/*CATATAN: di praktikum ini, resetHead dilakukan ketika Enqueue */
void resetHead(tqueue2 *Q) {
    // kamus lokal
    int i;
    int n;

    // algoritma
    n = sizeQueue2(*Q);
    
    if (isTailStop(*Q)) {
        for (i = 1; i <= n; i++) {
            (*Q).wadah[i] = (*Q).wadah[i + (head2(*Q) - 1)];
        }
        (*Q).tail = n;
        (*Q).head = 1;

        for (i = (*Q).tail + 1; i <= 5; i++) {
            (*Q).wadah[i] = '#';
        }
    } else {
        printf("Tail tidak berada diakhir Queue.\n");
    }
}

/*procedure enQueue2( input/output Q:tQueue2, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q, jika tail(Q)=kapasitas, 
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2(tqueue2 *Q, char E) {
    // kamus lokal
    int i;

    // algoritma
    if (!isFullQueue2(*Q)) {
        if (isEmptyQueue2(*Q)) {
            (*Q).tail = 1;
            (*Q).head = 1;

            (*Q).wadah[head2(*Q)] = E;
        } else if (isTailStop(*Q)) {
            resetHead(&(*Q));

            (*Q).tail += 1;
            (*Q).wadah[tail2(*Q)] = E;
        } else {
            (*Q).tail += 1;
            (*Q).wadah[tail2(*Q)] = E;
        }
    } else {
        printf("Queue penuh!\n");
    }
}
  
/*procedure deQueue2( input/output Q:tQueue2, output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q) lama, bila kosong, E='@'}
{proses: mengurangi elemen wadah Q, bila 1 elemen, 
maka Head dan Tail mengacu ke 0 } */
void dequeue2(tqueue2 *Q, char *E) {
    // kamus lokal
    int i;

    // algoritma
    if (!isEmptyQueue2(*Q)) {
        (*E) = (*Q).wadah[head2(*Q)];
        
        if (isOneElement2(*Q)) {
            (*Q).wadah[head2(*Q)] = '#';
            
            (*Q).head = 0;
            (*Q).tail = 0;
        } else {
            (*Q).wadah[head2(*Q)] = '#';

            (*Q).head += 1;
        }
    } else {
        printf("Queue kosong!\n");
    }
}

/*procedure enQueue2N( input/output Q:tQueue2, input N:integer )
{I.S.: Q terdefinisi, mungkin kosong, N <= kapasitas - panjang antrean}
{F.S.: elemen wadah Q bertambah <= N elemen bila belum penuh}
{proses: mengisi elemen dari keyboard, jika tail(Q) mencapai kapasitas, 
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2N(tqueue2 *Q, int N) {
    // kamus lokal
    int i, k;

    // algoritma

    if (sizeQueue2(*Q) + N <= 5) {
        if (isEmptyQueue2(*Q)) {
            (*Q).head = 1;
            (*Q).tail = N;

            for (i = 1; i <= tail2(*Q); i++) {
                printf("Masukan elemen ke-%d = ", i);
                scanf(" %c", &(*Q).wadah[i]);
            }
        } else {
            k = 1;
            for (i = tail2(*Q) + 1; k <= N; i++) {

                if (isTailStop(*Q)) {
                    resetHead(&(*Q));
                    i = tail2(*Q) + 1;
                }
                printf("Masukan elemen ke-%d: ", k);
                scanf(" %c", &(*Q).wadah[i]);

                k++;
                (*Q).tail += 1;
            }
        }
    } else {
        printf("Jumlah elemen pada Queue melebihi batas!\n");
    }
}

/*EXTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*Function isEqualQueue2(Q1:TQueue2,Q2:TQueue2) -> boolean
{mengembalikan true jika Q1 dan Q2 berisi elemen yang sama}
{ingat, kondisi head Q1 dan Q2 mungkin tidak sama} */
boolean isEqualQueue2(tqueue2 Q1,tqueue2 Q2) {
    // kamus loka
    int i, j;
    boolean equal;

    // algoritma
    i = head2(Q1);
    j = head2(Q2);
    
    if (sizeQueue2(Q1) != sizeQueue2(Q2)) {
        return false;
    }

    while (Q1.wadah[i] == Q2.wadah[j] && i < tail2(Q1) && j < tail2(Q2)) {
        i++;
        j++;
    }

    if (Q1.wadah[i] != Q2.wadah[j]) {
        return false;
    } else {
        return true;
    }
}