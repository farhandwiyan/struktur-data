#ifndef puskesmas_H
#define puskesmas_H
#include "boolean.h"

/* Program   : puskesmas.h */
/* Deskripsi : definisi dan spesifikasi module puskesmas */
/* NIM/Nama  : 24060124140137 - Farhan Dwiyan Akbar */
/* Tanggal   : 11/10/2025 */
/***********************************/

/* type pasien = <  id: integer ,
				    prioritas: integer> */
typedef struct {  int id; // nomor id pasien
                  int prioritas; // 1 = lansia, 2 = anak, 3 = dewasa
                } pasien;

/* type tQueue = <  wadah: array [1..5] of pasien ,
					head: integer ,
					tail: integer >
{cara akses: Q:tQueue, Q.head=head(Q) ...} */
typedef struct { pasien wadah[6]; //kapasitas 5 elemen, indeks 0 tidak dipakai
                  int head; 
                  int tail; 
                } tqueue;

/*procedure createQueue ( output T:tQueue)
{I.S.: -}
{F.S.: T terdefinisi, kosong}
{Proses: mengisi elemen dengan huruf '-', head=tail=0 }*/ 
void createQueue(tqueue *T);

/*procedure makePasien ( output P:pasien, input i: integer, p: integer)
{I.S.: -}
{F.S.: P terdefinisi}
{Proses: mengisi P id = i dan prioritas = p}*/ 
void makePasien(pasien *P, int i, int p);

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
pasien infoHead(tqueue T);

/*function infoTail(T:tQueue)-> pasien 
{mengembalikan nilai elemen terakhir antrian T} */
/*pikirkan bila antrian kosong*/
pasien infoTail(tqueue T);

/*function sizeQueue(T:tQueue)-> integer 
{mengembalikan panjang antrian T} */
int sizeQueue(tqueue T);

/*procedure printQueue(input T:tQueue)
{I.S.: T terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(tqueue T);

/*procedure viewQueue(input T:tQueue)
{I.S.: T terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void viewQueue(tqueue T);

/*function isEmptyQueue(T:tQueue) -> boolean
{mengembalikan true jika T kosong}*/
boolean isEmptyQueue(tqueue T);
 
/*function isFullQueue(T:tQueue) -> boolean
{mengembalikan true jika T penuh}*/
boolean isFullQueue(tqueue T);

/*function isOneElement(T:tQueue) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(tqueue T);

/*procedure enqueue( input/output T:tQueue, input P: pasien )
{I.S.: T dan P terdefinisi}
{F.S.: elemen wadah T bertambah 1, bila belum penuh}
{proses: menambah elemen wadah T } */
void enqueue(tqueue *T, pasien P);
  
/*procedure deQueue( input/output T:tQueue, output P: pasien )
{I.S.: T, P terdefinisi}
{F.S.: T berkurang satu elemen atau tetap}
{proses: mengambil elemen di posisi head (paling depan)} */
void dequeue(tqueue *T, pasien *P);

#endif