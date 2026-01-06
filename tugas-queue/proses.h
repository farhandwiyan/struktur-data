#ifndef proses_H
#define proses_H
#include "boolean.h"

/* Program   : proses.h */
/* Deskripsi : module ADT Proses */
/* NIM/Nama  : 24060124140137 - Farhan Dwiyan Akbar */
/* Tanggal   : 08/10/2025 */
/***********************************/

/* type Proses = < IdProses: character, BurstTime: integer > */
typedef struct {
    char IdProses;
    int BurstTime;
} Proses;

/* type tQueue = <  wadah: array [1..5] of Proses ,
					head: integer ,
					tail: integer >
{cara akses: Q:tQueue, Q.head=head(Q) ...} */
typedef struct { Proses wadah[6]; //kapasitas 5 elemen, indeks 0 tidak dipakai
                  int head; 
                  int tail; 
                } tqueue;

/*procedure makeProses (output P: Proses, input x: character, y:integer) 
{I.S.: -}
{F.S.: P terdefinisi}
{Proses: mengisi nilai IdProses dengan x dan BurstTime dengan y} */
void makeProses(Proses *P, char x, int y);

/*procedure createQueue ( output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi elemen wadah dengan Proses  <‘-’, -999>, head=tail=0} */ 
void createQueue(tqueue *Q);

/*function getIdProses(P: Proses) -> character 
{mengembalikan nilai komponen IdProses P} */
char getIdProses(Proses P);

/*function getBurstTime(P: Proses) -> integer 
{mengembalikan nilai komponen BurstTime P} */
int getBurstTime(Proses P);

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
Proses infoHead(tqueue Q);

/*function infoTail(Q:tQueue)-> Proses
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
Proses infoTail(tqueue Q);

/*procedure printProses(input P:Proses)
{I.S.: P terdefinisi}
{F.S.: -}
{proses: mencetak Proses ke layar}*/
void printProses(Proses P);

/*procedure printQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(tqueue Q);

/*procedure viewQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void viewQueue(tqueue Q);

/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(tqueue Q);
 
/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(tqueue Q);

/*function isOneElement(Q:tQueue) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(tqueue Q);

/*procedure enqueue( input/output Q:tQueue, input P: Proses )
{I.S.: Q dan P terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(tqueue *Q, Proses P);
  
/*procedure deQueueSJF( input/output Q:tQueue, output P: Proses )
{I.S.: Q dan P terdefinisi}
{F.S.: P=Proses dengan busrtTime terkecil atau P=<'-', -999> bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeueSJF(tqueue *Q, Proses *P);

#endif