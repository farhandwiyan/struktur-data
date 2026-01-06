/* Program   : proses.c */
/* Deskripsi : realisasi ADT Proses */
/* NIM/Nama  : 24060124140137 - Farhan Dwiyan Akbar */
/* Tanggal   : 08/10/2025 */
/***********************************/

#include <stdio.h>
#include "proses.h"

/*procedure makeProses (output P: Proses, input x: character, y:integer) 
{I.S.: -}
{F.S.: P terdefinisi, kosong}
{Proses: mengisi nilai IdProses dengan x dan BurstTime dengan y} */
void makeProses(Proses *P, char x, int y) {
    (*P).IdProses = x;
    (*P).BurstTime = y;
}

/*procedure createQueue ( output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi elemen wadah dengan Proses  <‘-’, -999>, head=tail=0} */ 
void createQueue(tqueue *Q) {
  // kamus lokal
  int i;
  
  // algoritma
  for (i = 1; i <= 5; i++) {
    ((*Q).wadah[i]).IdProses = '-';
    ((*Q).wadah[i]).BurstTime = -999;
  }

  (*Q).head = 0;
  (*Q).tail = 0;
}

/*function getIdProses(P: Proses) -> character 
{mengembalikan nilai komponen IdProses P} */
char getIdProses(Proses P) {
    return P.IdProses;
}

/*function getBurstTime(P: Proses) -> integer 
{mengembalikan nilai komponen BurstTime P} */
int getBurstTime(Proses P) {
    return P.BurstTime;
}

/*function Head(Q:tQueue)-> integer 
{mengembalikan elemen terdepan antrian Q} */
//int Head(tqueue Q);
#define head(Q) (Q).head 

/*function Tail(Q:tQueue)-> integer 
{mengembalikan elemen terakhir antrian Q} */
//int Tail(tqueue Q);
#define tail(Q) (Q).tail 

/*function infoHead(Q:tQueue)-> Proses
{mengembalikan nilai elemen terdepan antrian Q} */
/*pikirkan bila antrian kosong*/
Proses infoHead(tqueue Q){
  if (!isEmptyQueue(Q)) {
    return Q.wadah[head(Q)];
  } else {
    printf("Queue kosong!");
  }
}

/*function infoTail(Q:tQueue)-> Proses
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
Proses infoTail(tqueue Q) {
  if (!isEmptyQueue(Q)) {
    return Q.wadah[tail(Q)];
  } else {
    printf("Queue kosong!");
  }
}

/*procedure printProses(input P:Proses)
{I.S.: P terdefinisi}
{F.S.: -}
{proses: mencetak Proses ke layar}*/
void printProses(Proses P) {
    printf("[%c, %d]", getIdProses(P), getBurstTime(P));
}

/*procedure printQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(tqueue Q) {
  // kamus lokal
  int i;

  // algoritma
  for (i = 1; i <= 5; i++) {
    printf("[%c, %d] ", getIdProses(Q.wadah[i]), getBurstTime(Q.wadah[i]));
  }
}

/*procedure viewQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void viewQueue(tqueue Q) {
  // kamus lokal
  int i;

  //algoritma
  if (!isEmptyQueue(Q)) {
    for (i = head(Q); i <= tail(Q); i++) {
      printf("[%c, %d] ", getIdProses(Q.wadah[i]), getBurstTime(Q.wadah[i]));
    }
  } else {
    printf("Queue kosong!");
  }
}

/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(tqueue Q) {
  return head(Q) == 0 && tail(Q) == 0;
}
 
/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(tqueue Q) {
  return head(Q) == 1 && tail(Q) == 5;
}

/*function isOneElement(Q:tQueue) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(tqueue Q) {
  return head(Q) == 1 && tail(Q) == 1;
}

/*procedure enqueue( input/output Q:tQueue, input P: Proses )
{I.S.: Q dan P terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(tqueue *Q, Proses P) {
  if (!isFullQueue(*Q)) {
    if (isEmptyQueue(*Q)) {
      (*Q).head = 1;
      (*Q).tail = 1;

      (*Q).wadah[tail(*Q)] = P;
    } else {
      (*Q).tail += 1;

      (*Q).wadah[tail(*Q)] = P;
    }
  } else {
    printf("Queue penuh!\n");
  }
}
  
/*procedure deQueueSJF( input/output Q:tQueue, output P: Proses )
{I.S.: }
{F.S.: P=Proses dengan busrtTime terkecil atau P=<'-', -999> bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeueSJF(tqueue *Q, Proses *P) {
  // kamus lokal
  int i, min, index;

  // algoritma
  if (!isEmptyQueue(*Q)) {

    if (isOneElement(*Q)) {
      (*P) = (*Q).wadah[head(*Q)];
      ((*Q).wadah[head(*Q)]).IdProses = '-';
      ((*Q).wadah[head(*Q)]).BurstTime = -999;
      
      (*Q).head = 0;
      (*Q).tail = 0;
    } else {
      min = 999;
      
      for (i = head(*Q); i <= tail(*Q); i++) {
        if (getBurstTime((*Q).wadah[i]) < min) {
          min = getBurstTime((*Q).wadah[i]);
          index = i;
        }
      }

      (*P) = (*Q).wadah[index];

      for (i = index; i < tail(*Q); i++) {
        (*Q).wadah[i] = (*Q).wadah[i+1];
      }

      ((*Q).wadah[tail(*Q)]).IdProses = '-';
      ((*Q).wadah[tail(*Q)]).BurstTime = -999;

      (*Q).tail -= 1;
    }
  } else {
    (*P).IdProses = '-';
    (*P).BurstTime = -999;
  }
}