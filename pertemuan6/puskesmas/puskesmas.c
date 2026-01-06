/* Program   : puskesmas.c */
/* Deskripsi : realisasi module puskesmas */
/* NIM/Nama  : 24060124140137 - Farhan Dwiyan Akbar */
/* Tanggal   : 11/10/2025 */
/***********************************/

#include <stdio.h>
#include "puskesmas.h"

/*procedure createQueue ( output T:tQueue)
{I.S.: -}
{F.S.: T terdefinisi, kosong}
{Proses: mengisi elemen dengan <0, 0>, head=tail=0 }*/ 
void createQueue(tqueue *T) {
  // kamus lokal
  int i;

  // algoritma
  for (i = 1; i <= 5; i++) {
    ((*T).wadah[i]).id = 0;
    ((*T)).wadah[i].prioritas = 0;
  }

  (*T).head = 0;
  (*T).tail = 0;
}

/*procedure makePasien ( output P:pasien, input i: integer, p: integer)
{I.S.: -}
{F.S.: P terdefinisi}
{Proses: mengisi P id = i dan prioritas = p}*/ 
void makePasien(pasien *P, int i, int p) {
  (*P).id = i;
  (*P).prioritas = p;
}

/*function Head(T:tQueue)-> integer 
{mengembalikan elemen terdepan antrian T} */
//int Head(tqueue T);
#define head(T) (T).head //implementasi fisik macro

/*function Tail(T:tQueue)-> integer 
{mengembalikan elemen terakhir antrian T} */
//int Tail(tqueue T);
#define tail(T) (T).tail //implementasi fisik macro

/*function infoHead(T:tQueue)-> pasien 
{mengembalikan nilai elemen terdepan antrian T} */
/*pikirkan bila antrian kosong*/
pasien infoHead(tqueue T) {
  if (!isEmptyQueue(T)) {
    return T.wadah[head(T)];
  } else {
    printf("Queue kosong!\n");
  }
}

/*function infoTail(T:tQueue)-> pasien 
{mengembalikan nilai elemen terakhir antrian T} */
/*pikirkan bila antrian kosong*/
pasien infoTail(tqueue T) {
  if (!isEmptyQueue(T)) {
    return T.wadah[tail(T)];
  } else {
    printf("Queue kosong!\n");
  }
}

/*function sizeQueue(T:tQueue)-> integer 
{mengembalikan panjang antrian T} */
int sizeQueue(tqueue T);

/*procedure printQueue(input T:tQueue)
{I.S.: T terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(tqueue T) {
  // kamus lokal
  int i;

  // algoritma
  for (i = 1; i <= 5; i++) {
    printf("[%d, %d] ", (T.wadah[i]).id, (T.wadah[i]).prioritas);
  }
}

/*procedure viewQueue(input T:tQueue)
{I.S.: T terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void viewQueue(tqueue T) {
  // kamus lokal
  int i;

  // algoritma
  if (!isEmptyQueue(T)) {
    for (i = head(T); i <= tail(T); i++) {
      printf("[%d, %d] ", (T.wadah[i]).id, (T.wadah[i]).prioritas);
    }
  } else {
    printf("Queue kosong!");
  }
}

/*function isEmptyQueue(T:tQueue) -> boolean
{mengembalikan true jika T kosong}*/
boolean isEmptyQueue(tqueue T) {
  return head(T) == 0 && tail(T) == 0;
}
 
/*function isFullQueue(T:tQueue) -> boolean
{mengembalikan true jika T penuh}*/
boolean isFullQueue(tqueue T) {
  return tail(T) == 5;
}

/*function isOneElement(T:tQueue) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(tqueue T) {
  return head(T) == 1 && tail(T) == 1;
}

/*procedure enqueue( input/output T:tQueue, input P: pasien )
{I.S.: T dan P terdefinisi}
{F.S.: elemen wadah T bertambah 1, bila belum penuh}
{proses: menambah elemen wadah T, posisi terurut prioritas membesar} */
void enqueue(tqueue *T, pasien P) {
  // kamus lokal
  int i, j;
  
  // algoritma
  if (!isFullQueue(*T)) {
    if (isEmptyQueue(*T)) {
      (*T).head = head(*T) + 1;
      (*T).tail = tail(*T) + 1;

      ((*T).wadah[head(*T)]).id = P.id;
      ((*T).wadah[head(*T)]).prioritas = P.prioritas;
    } else {
      i = 1;

      // Cari posisi berdasarkan prioritas membesar
      // Loop berhenti satu langkah sebelum tail agar tidak akses elemen kosong
      while ((((*T).wadah[i]).prioritas <= P.prioritas) && (i < tail(*T))) {
        i++;
      }

      // Jika menemukan elemen dengan prioritas lebih besar, sisipkan di tengah
      if (((*T).wadah[i]).prioritas > P.prioritas) {
        (*T).tail = tail(*T) + 1;

        for (j = tail(*T); j > i; j--) {
          (*T).wadah[j] = (*T).wadah[j-1];
        }

        ((*T).wadah[i]).id = P.id;
        ((*T).wadah[i]).prioritas = P.prioritas;
      } else {
        // Jika tidak, berarti P punya prioritas terbesar, taruh di akhir
        (*T).tail = tail(*T) + 1;

        ((*T).wadah[tail(*T)]).id = P.id;
        ((*T).wadah[tail(*T)]).prioritas = P.prioritas;
      }
    }
  } else {
    printf("Queue penuh\n");
  }
}
  
/*procedure deQueue( input/output T:tQueue, output P: pasien )
{I.S.: T, P terdefinisi}
{F.S.: T berkurang satu elemen atau tetap}
{proses: mengambil elemen di posisi head (paling depan)} */
void dequeue(tqueue *T, pasien *P) {
  // kamus lokal
  int i;

  // algoritma
  if (!isEmptyQueue(*T)) {
    (*P) = (*T).wadah[head(*T)]; 
    
    if (isOneElement(*T)) {
      ((*T).wadah[head(*T)]).id = 0;
      ((*T).wadah[head(*T)]).prioritas = 0;

      (*T).head = 0;
      (*T).tail = 0;
    } else {
      for (i = 1; i < tail(*T); i++) {
        (*T).wadah[i] = (*T).wadah[i+1];
      }

      (*T).wadah[tail(*T)].id = 0;
      (*T).wadah[tail(*T)].prioritas = 0;

      (*T).tail = tail(*T) - 1;
    }
  } else {
    printf("Queue kosong!\n");
  }
}
