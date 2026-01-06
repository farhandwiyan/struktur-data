/* File : List2.h */
/* Deskripsi : ADT list berkait SIRKULAR dengan representasi fisik pointer */
/* NIM & Nama : 24060124140137 - Farhan Dwiyan Akbar */
/* Tanggal : 13 November 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "list2.h"

/*================== PROTOTYPE =======================*/
/****************** Manajemen Memori ******************/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) {
    /* kamus lokal */
    address P;

    /* algoritma */
    P = (address) malloc(sizeof(Elm2)); //casting
    if (P != NULL ) {
        info(P) = E;
        next(P) = NIL;
    }
    return P;
}
 
/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P) {
   /* kamus lokal */

   /* algoritma */
   if (*P != NIL) {
      free(*P);
      *P = NIL;
   }
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List2)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List2 *L) {
   /* kamus lokal */

   /* algoritma */
   First(*L) = NIL;
}

/****************** TEST KONDISI LIST ******************/
/* function IsEmptyList(L:List2) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List2 L) {
   /* kamus lokal */

   /* algoritma */
   return First(L) == NIL;
}

/* function IsOneElm(L:List2) --> boolean 
   {mengembalikan true bila list L hanya punya satu elemen} */
boolean IsOneElm (List2 L) {
   /* kamus lokal */
   address P;

   /* algoritma */
   P = First(L);

   return First(L) == next(P);
}

/*********** PENELUSURAN ***********/
/*procedure PrintList(input L:List2)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List2 L) {
   /* kamus lokal */
   address P;

   /* algoritma */

   // inisialisasi P dengan elemen pertama
   P = First(L);

   printf("Elemen = ");
   if (!IsEmptyList(L)) {  // jika list tidak kosong
      do {
         printf("%c\t", info(P));
         P = next(P);
      } while (P != First(L));
   }
}

/*function NbElm(L:List2) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List2 L) {
   /* kamus lokal */
   address P;
   int count;  // menghitung nilai elemen

   /* algoritma */

   // inisialisasi nilai count = 0
   count = 0; 
   
   if (!IsEmptyList(L)) {  // jika list tidak kosong
      P = First(L);

      // loop untuk menghitung count
      do {
         count++;
         P = next(P);
      } while (P != First(L));

      return count;
   } else {
      return count;
   }
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List2 *L, infotype V ) {
   /* kamus lokal */
   address P, A;

   /* algortima */
   A = Alokasi(V);

   if (A != NIL) {
      if (!IsEmptyList(*L)) {

         // inisialisasi P dengan alamat elemen pertama
         P = First(*L);

         // loop untuk mencari elemen terakhir
         while (next(P) != First(*L)) {
            P = next(P);
         }

         // jika next(P) == First(L)
         next(P) = A;
         next(A) = First(*L);
         First(*L) = A;
         
      } else {
         First(*L) = A;
         P = First(*L);
         next(P) = First(*L);
      }
   }
}

/*Procedure InsertVLast(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V, next(P)=First(L)}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List2 *L, infotype V ) {
   /* kamus lokal */
   address P, A;

   /* algoritma */
   A = Alokasi(V);

   if (!IsEmptyList(*L)) { // jika list tidak kosong
      
      // inisialisasi nilai P dengan elemen pertama 
      P = First(*L); 

      // loop mencari elemen terakhir
      while (next(P) != First(*L)) {
         P = next(P);
      }

      // jika next(P) = First(L)
      next(P) = A;
      next(A) = First(*L);
   } else {  // jika list kosong
      First(*L) = A;
      P = First(*L);
      next(P) = First(*L);
   }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen pertama list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List2 *L, infotype *V) {
   /* kamus lokal */
   address P, first;

   /* kamus lokal */
   if (!IsEmptyList(*L)) { // jika tidak kosong
      first = First(*L);

      if (IsOneElm(*L)) {  // jika satu elemen
      
         // masukan elemen pertama P ke V
         *V = info(first);

         // jadikan list kosong
         First(*L) = NIL;

      } else { // jika lebih dari satu elemen
         
         // inisialisasi P dengan elemen pertama
         P = First(*L);
         
         // loop untuk cari elemen terakhir
         while (next(P) != First(*L)) {
            P = next(P);
         }

         // masukan elemen pertama ke V
         *V = info(first);
         
         // ganti first elemen menjadi elemen selanjutnya dari elemen pertama
         First(*L) = next(first); 

         // ganti next dari elemen terakhir menjadi elemen pertama yang baru
         next(P) = First(*L);
      }

      Dealokasi(&first);
   } else {    // jika list kosong
      *V = '#';
   }
}

/*Procedure DeleteVLast(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List2 *L, infotype *V) {
   /* kamus lokal */
   address P, last, prev;

   /* algoritma */
   if (!IsEmptyList(*L)) {    // jika list tidak kosong
      
      // inisialisasi P dengan elemen pertama
      P = First(*L);

      if (IsOneElm(*L)) {  // jika satu elemen
         
         // masukan elemen pertama P ke V
         *V = info(P);

         // jadikan list kosong
         First(*L) = NIL;

         Dealokasi(&P);

      } else {    // jika banyak elemen

         // inisialisasi last dengan elemen pertama untuk mencari elemen terakhir
         last = First(*L);

         // loop untuk cari elemen terakhir
         while (next(last) != First(*L)) {
            
            // prev sebagai elemen sebelum last
            prev = last;

            last = next(last);
         }
   
         // masukan elemen terakhir ke V
         *V = info(last);

         // ganti next dari prev menjadi elemen P (elemen pertama)
         next(prev) = P;

         Dealokasi(&last);
      }
   } else {    // jika list kosong
      *V ='#';
   }
}

/*Procedure DeleteX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteX(List2 *L, infotype X) {
   /* kamus lokal */
   address P, first, last, prevLast, prevFound;
   boolean found;

   /* algoritma */
   if (!IsEmptyList(*L)) { // jika list tidak kosong (walaupun diasumsikan list tidak kosong)
      
      // inisialisasi nilai first dengan elemen pertama
      first = First(*L);

      if (IsOneElm(*L)) {     // jika list satu elemen

         if (info(first) == X) {    // jika elemen first sama dengan X
            
            // jadikan elemen kosong
            First(*L) = NIL;
            
            Dealokasi(&first);
         } 

      } else {   // jika list lebih dari satu elemen

          // inisialisai nilai last = elemen pertama
         last = First(*L);

         // inisialisai nilai P = NIL
         P = NIL;

         // inisialisasi found dengan nilai False
         found = False;

         // inisialisasi prevLast dengan NIL
         prevLast = NIL;

         // cari elemen yang ingin dihapus dan elemen terakhir
         while (next(last) != First(*L)) {

            // jika X = last (tidak mengecek elemen terakhir, tapi mengecek elemen pertama sampe sebelum terakhir)
            if (info(last) == X) {
                  
               // ubah nilai found menjadi True
               found = True;

               // simpan alamat ke P
               P = last;

               // simpan alamat elemen sebelumnya
               prevFound = prevLast;
             } 

            // prevLast sebagai elemen sebelum elemen terakhir
            prevLast = last;

            last = next(last);
         }

         // jika X = last (lakukan pengecekan untuk elemen terakhir)
         if (info(last) == X && !found) {
                  
            // ubah nilai found menjadi True
            found = True;

            // simpan alamat ke P
            P = last;

            // simpan alamat elemen sebelumnya
            prevFound = prevLast;
         }

         // jika ketemu
         if (found) {

            // jika ketemu di elemen pertama
            if (P == first) {

               // ganti elemen pertama menjadi elemen setelah elemen pertama
               First(*L) = next(first);

               // ganti next dari elemen terakhir menjadi elemen pertama yang baru
               next(last) = First(*L);

               Dealokasi(&first);

            } else if (P == last) {    // jika ketemu di elemen terakhir

               // ganti next dari prev menjadi elemen pertama list
               next(prevFound) = First(*L);

               Dealokasi(&last);

            } else {    // jika ketemu selain elemen pertama atau terakhir

               // ganti next prevFound menjadi elemen setelah P
               next(prevFound) = next(P);

               Dealokasi(&P);
            }
         }
      }
   }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List2 L, infotype X, address *A) {
   /* kamus lokal */
   address P;
   boolean found;

   /* algoritma */

   *A = NIL; // inisialisasi A dengan NIL

   if (!IsEmptyList(L)) {  // jika list tidak kosong

      // inisialisasi nilai P dengan elemen pertama
      P = First(L);

      // inisialisasi found dengan False
      found = False;

      // loop untuk mencara nilai X
      while (next(P) != First(L) && !found) {
         
         // jika elemen P = X
         if (info(P) == X) {

            // ubah founs menjadi True
            found = True;

            // simpan alamat ke A
            *A = P;
         }

         P = next(P);
      }

      if (!found && info(P) == X) {
         // ubah founs menjadi True
         found = True;

         // simpan alamat ke A
         *A = P;
      }
   }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List2 *L, infotype X, infotype Y) {
   /* kamus lokal*/
   address P;
   boolean found;

   /* algoritma */
   if (!IsEmptyList(*L)) {    // jika list tidak kosong
      
      // inisialisasi nilai P dengan elemen pertama
      P = First(*L);

      // inisialisasi found = False
      found = False;

      // loop untuk mencari nilai yg akan diganti
      while (next(P) != First(*L) && !found) {  
         
         // jika elemen P = X
         if (info(P) == X) {
            
            // ubah found menjadi True
            found = True;

            // ganti elemen P menjadi X
            info(P) = Y;
         }

         P = next(P);
      }

      // lakukan pengecekan elemen terakhir
      if (info(P) == X && !found) {

         // ubah found menjadi True
         found = True;

         // ganti elemen P menjadi X
         info(P) = Y;
      }
   }
}

/*Procedure Invers(input/output L:List2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, 
misal {'A','B','C'} menjadi {'C','B','A'} }*/
void Invers(List2 *L){
   /* kamus lokal */
	address prev;   
   address now; 
   address after;     
	address headOld;

   /* algoritma */

   // inisialisasi pev dengan NIL
   prev = NIL;

   // mulai dari elemen pertama list
   now = First(*L);

   // inisialisasi after dengan NIL
   after = NIL;        
   
   // simpan nilai head lama
   headOld = First(*L);

   // jika list tidak kosong dan jumlah elemennya lebih dari 1
   if (!IsEmptyList(*L) && now != next(now)) {

      // loop untuk membalik list secara circular
      do {

         // simpan elemen berikutnya 
         after = next(now);

         // now menunjuk ke prev
         next(now) = prev;

         // prev berpindah ke now
         prev = now;          

          // now berpindah ke after
         now = after;    

      } while (now != First(*L));  // berhenti jika sudah kembali ke head lama

      // update head list ke elemen baru
      First(*L) = prev;      

      // elemen head lama menjadi elemen terakhir sehingga next-nya harus menunjuk ke head baru
      next(headOld) = First(*L);
   }  
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(L:List2, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List2 L, infotype X) {
   /* kamus lokal */
   address P;
   int count;

   /* algoritma */
   count = 0;  // inisialisasi nilai count dengan 0

   if (!IsEmptyList(L)) {     // jika list tidak kosong

      // inisialisasi nilai P dengan elemen pertama
      P = First(L);

      // loop untuk mencari banyaknya nilai X
      while (next(P) != First(L)) {

         // jika elemen P = X
         if (info(P) == X) {
            count++;
         }

         P = next(P);
      }

      // lakukan pengecekan elemen terakhir
      if (info(P) == X) {
         count++;
      }

      return count;

   } else {    // jika list kosong
      return count;
   }
}

/*function FrekuensiX(L:List2, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List2 L, infotype X) {
   /* kamus lokal */
   address P;
   float frek, hasil;

   /* algoritma */

   // inisialisasi nilai frek dan hasil dengan 0
   frek = 0; 
   hasil = 0;

   if (!IsEmptyList(L)) {  // jika list tidak kosong

      // inisialisi P dengan elemen pertama
      P = First(L);

      // loop untuk mencari frekuensi kemunculan X
      while (next(P) != First(L)) {
         
         // jika ketemu
         if (info(P) == X) {
            frek++;
         }

         P = next(P);
      }

      // lakukan pengecekan elemen terakhir
      if (info(P) == X) {
         frek++;
      }

      // hitung hasil dengan frekuensi / nbelmt
      hasil = frek / (float) NbElm(L);

      return hasil;

   } else {    // jika kosong
      return hasil;
   }
}

/*function CountVocal(L:List2) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List2 L) {
   /* kamus lokal */
   address P;
   infotype c;
   int countV;

   /* algoritma */
   countV = 0;    // inisialisasi countV dengan 0

   if (!IsEmptyList(L)) {     // jika tidak kosong

      // inisialisasi P dengan elemen pertama
      P = First(L);

      // loop untuk menghitung frekuensi huruf vocal dalam list
      while (next(P) != First(L)) {

         // simpan elemen P ke c
         c = info(P);

         // jika ketemu
         if (c == 'a' || c == 'i' || c =='u' || c =='e' || c == 'o' 
            || c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O') {
               countV++;
         }

         P = next(P);
      }

      // lakukan pengecekan ke elemen terakhir
      c = info(P);

      if (c == 'a' || c == 'i' || c =='u' || c =='e' || c == 'o' 
         || c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O') {
            countV++;
      }

      return countV;

   } else {    // jika kosong
      return countV;
   }
}

/*function CountNG(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List2 L) {
   /* kamus lokal */
   address P;
   infotype c, nextC;
   int count;

   /* algoritma */
   count = 0;     // inisialisasi count dengan 0

   if (!IsEmptyList(L)) {     // jika tidak kosong

      // inisialisasi P dengan elemen pertama
      P = First(L);

      // loop untuk mencari banyaknya huruf N yang diikuti G
      while (next(P) != First(L)) {

         // simpan elemen P ke c
         c = info(P);

         // simpan elemen setelah p ke nextC
         nextC = info(next(P));

         // lakukan pengecekan dengan membandingan c dengan elemen setelahnya
         if ((c == 'n' || c == 'N') & (nextC == 'g' || nextC == 'G')) {
            count++;
         }

         P = next(P);
      }

      return count;

   } else {    // jika kosong
      return count;
   }
}

/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List2 *L, infotype X, infotype V) {
   /* kamus lokal */
   address P, A, first;
   boolean found;

   /* algoritma */
   if (!IsEmptyList(*L)) {    // jika tidak kosong
      
      // inisialisasi first dengan elemen pertama
      first = First(*L);

      if (IsOneElm(*L) && info(first) == X) {   // jika satu elemen dan elemen pertama = X
         
         // tambahkan elemen baru ke akhir list
         InsertVLast(L, V);

      } else {

         // inisialisasi P dengan elemen pertama
         P = First(*L);

         // inisialisasi found dengan False
         found = False;

         // loop untuk mencari elemen X dan 
         while (next(P) != First(*L) && !found) {
            
            // jika ketemu
            if (info(P) == X) {

               // ubah found menjadi True
               found = True;

            } else { // jika tidak ketemu

               // lanjutkan pengecekan
               P = next(P);

            }
         }

         // lakukan pengecekan ke elemen terakhir
         if (info(P) == X && !found) {

            // ubah found menjadi True
            found = True;

         }

         if (found) {   // jika ketemu
            
            // alokasi V
            A = Alokasi(V);

            if (next(P) == First(*L)) {      // jika ketemu di elemen terakhir
               
               // ubah next dari A menjadi elemen pertama (karena A pasti elemen terakhir)
               next(A) = first;

               // ubah next dari P menjadi A
               next(P) = A;

            } else {    // jika ketemu di bukan elemen terakhir
               
               // ubah next A menjadi elemen setelah P
               next(A) = next(P);

               // ubah next P menjadi A
               next(P) = A;
            }
         }
      }
   }
}

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List2 *L, infotype X, infotype V) {
   /* kamus lokal */
   address P, A, prev;
   boolean found;

   /* algoritma */
   if (!IsEmptyList(*L)) {    // jika tidak kosong

      // inisialisasi P dengan elemen pertama
      P = First(*L);

      if (IsOneElm(*L) && info(P) == X) {  // jika satu elemen dan elemen pertama = X
         
         // tambahkan elemen baru menjadi elemen pertama list
         InsertVFirst(L, V);

      } else {

         // inisialisasi prev dengan NIL
         prev = NIL;

         // inisialisasi found dengan False
         found = False;

         // loop untuk mencari X
         while (next(P) != First(*L) && !found) {

            // jika ketemu
            if (info(P) == X) {
               
               // ubah found menjadi true
               found = True;

            } else {    // jika tidak ketemu
               
               // ubah P menjadi elemen P
               prev = P;
               
               // lanjutkan pencarian
               P = next(P);

            }
         }

         // lakukan pengecekan ke elemen terakhir
         if (info(P) == X && !found) {
            found = True;
         }

         // jika ketemu
         if (found) {
            if (P == First(*L)) {     // jika ketemu di elemen pertama

               // tambahkan elemen baru menjadi elemen pertama list
               InsertVFirst(L, V);

            } else {    // jika ketemu di bukan elemen pertama
   
               // alokasi V
               A = Alokasi(V);

               // ubah next dari prev menjadi A
               next(prev) = A;

               // ubah next dari A menjadi P
               next(A) = P;
            }
         }
      }
   }
}

/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List2 *L, infotype X, infotype *V) {
   /* kamus lokal */
   address P, A;
   boolean found;

   /* algoritma */
   if (!IsEmptyList(*L)) {    // jika tidak kosong

      // inisialisasi nilai P dengan elemen pertama list
      P = First(*L);

      if (IsOneElm(*L) && info(P) == X) {    // jika satu elemen dan elemen pertama = X
         
         // lakukan penghapusan elemen berikutnya (elemen pertama) 
         DeleteVLast(L, V);

      } else {    // jika lebih dari satu elemen

         // inisialisasi found = False
         found = False;

         // lakukan loop untuk mencari X
         while (next(P) != First(*L) && !found) {

            // jika ketemu
            if (info(P) == X) {
               
               // ubah found menjadi True
               found = True;

            } else {

               // lanjutkan pencarian
               P = next(P);
            }
         }

         // lakukan pengecekan elemen terahir
         if (info(P) == X && !found) {
               
            // ubah found menjadi True
            found = True;
         }

      }   

      if (found) {
         if (next(P) == First(*L)) {   // jika ketemu di elemen terakhir
               
            // hapus elemen pertama
            DeleteVFirst(L, V);

         } else {    // jika ketemu di elemen selain terakhir dan pertama

            // simpan yang akan dihapus
            A = next(P);

            // simpan nilainya
            *V = info(A);    

            // ubah next dari P menjadi next dari A
            next(P) = next(A); 

            // hapus A
            Dealokasi(&A);
         }
      }
   }
}

/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List2 *L, infotype X, infotype *V) {
   /* kamus lokal */
   address P, prev, prev2;
   boolean found;

   /* algoritma */
   if (!IsEmptyList(*L)) {    // jika tidak kosong
      
      // inisialisasi P dengan elemen pertama
      P = First(*L);

      if (IsOneElm(*L) && info(P) == X) {    // jika satu elemen dan P = x
         
         // lakukan penghapusan
         DeleteVFirst(L, V);

      } else {    // jika lebih dari satu elemen

         // inisialisasi prev dan prev2 dengan NIL
         prev = NIL;
         prev2 = NIL;

         // inisialisasi found = False
         found = False;

         // loop untuk mencari X
         while (next(P) != First(*L) && !found) {

            // jika ketemu
            if (info(P) == X) {
               
               // ubah found menjadi True
               found = True;

            } else {    // jika tidak ketemu
               
               // ubah prev2 menjadi prev
               prev2 = prev;

               // ubah prev menjadi P
               prev = P;

               // lanjutkan pencarian
               P = next(P);
            }
         }  

         // lakukan pengecekan elemen terakhir
         if (!found && info(P) == X) {

            // ubah found menjadi True
            found = True;
         }

         // jika ketemu
         if (found) {
            if (P == First(*L)) {     // jika ketemu di elemen pertama  
               
               // hapus elemen terakhir
               DeleteVLast(L, V);

            } else if (prev2 != NIL) { // jika ketemu di urutan ke > 2

               // elemen yang akan dihapus
               *V = info(prev);

               // ubah next prev2 menjadi P
               next(prev2) = P;

               Dealokasi(&prev);

            } else {    // jika ketemu urutan ke 2 
               
               // hapus elemen pertama
               DeleteVFirst(L, V);
            }
         }
      }
   }
}

/*Procedure DeleteAllX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Semua elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteAllX(List2 *L, infotype X) {
   /* kamus lokal */
   address P, A;
   
   /* algoritma */
   if (!IsEmptyList(*L)) {    // jika tidak kosong
      
      // inisialisasi P dengan elemen pertama
      P = First(*L);

      // loop selama belum kembali ke awal
      do {
         A = next(P);

         // jika elemen berikutnya bernilai X
         if (info(A) == X) {

            // hapus X
            DeleteX(L, X);

         } else {

            // lanjutkan pengecekan
            P = next(P);
         }

      } while (P != First(*L));   // berhenti saat P = First

      // cek apakah elemen pertama bernilai X
      if (!IsEmptyList(*L) && info(First(*L)) == X) {

         // hapus X
         DeleteX(L, X);

      }
   }
}

/*Procedure SearchAllX(input L:List2, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List2 L, infotype X) {
   /* kamus lokal */
   address P;
   int index;

   /* algoritma */
   if (!IsEmptyList(L)) {    // jika tidak kosong

      // inisialisasi P dengan elemen pertama
      P = First(L);

      // inisialisai index = 0
      index = 0;

      // loop mencari X
      printf("Elemen %c ketemu di posisi: ", X);
      while (next(P) != First(L)) {
         
         // index + 1
         index++;

         // jika ketemu
         if (info(P) == X) {
            printf("%d ", index);
         }

         P = next(P);
      }

      // lakukan pengecekan elemen terakhir
      index++;
      if (info(P) == X) {
         printf("%d", index);
      }
   }
}

/*function MaxMember(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List2 L) {
   /* kamus lokal */
   address P;
   int max, frek;

   /* algoritma */
   max = 0;    // inisialisasi max dengan 0

   if (!IsEmptyList(L)) {    // jika tidak kosong

      // inisialisasi P dengan elemen pertama
      P = First(L);

      // loop untuk mencari elemen max
      while (next(P) != First(L)) {

         // mulai frek dengan 0
         frek = 0;

         // hitung banyaknya frekuensi kemunculan elemen
         frek = CountX(L, info(P));

         // frek kurang dari max frekuensi
         if (max < frek) {
            max = frek;
         }

         P = next(P);
      }

      return max;
   } else {    // kalo kosong
      return max;
   }
}

/*function Modus(L:List2) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List2 L) {
   /* kamus lokal */
   address P;
   int max, frek, maxElmt;

   /* algoritma */
   max = 0;    // inisialisasi max dengan 0
   maxElmt = info(First(L));    // inisialisasi maxElmt dengan elemen pertama

   if (!IsEmptyList(L)) {    // jika tidak kosong

      // inisialisasi P dengan elemen pertama
      P = First(L);

      // loop untuk mencari elemen max
      while (next(P) != First(L)) {

         // mulai frek dengan 0
         frek = 0;

         // hitung banyaknya frekuensi kemunculan elemen
         frek = CountX(L, info(P));

         // frek kurang dari max frekuensi
         if (max < frek) {
            max = frek;
            maxElmt = info(P);
         }

         P = next(P);
      }

      return maxElmt;
   } else {    // kalo kosong
      return maxElmt;
   }
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List2, input L2:List2, output L:List2)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List2 L1, List2 L2, List2 *L) {
   /* kamus lokal */ 
   address P;

   /* algoritma */

   CreateList(L);    // buat L

   // copy L1
   if (!IsEmptyList(L1)) {    // jika L1 tidak kosong

      // inisialisasi P dengan elemen pertama L1
      P = First(L1);

      // loop untuk mengcopy setiap elemen L1 ke L
      do {

         // masukan elemen P ke L
         InsertVLast(L, info(P));

         // lanjutkan
         P = next(P);

      } while (P != First(L1));  // berhenti jika P = First
   }

   // copy L2
   if (!IsEmptyList(L2)) {
      // inisialisasi P dengan elemen pertama L1
      P = First(L2);
     
      // loop untuk mengcopy setiap elemen L1 ke L
      do {

         // masukan elemen P ke L
         InsertVLast(L, info(P));

         // lanjutkan
         P = next(P);

      } while (P != First(L2));  // berhenti jika P = First
   }
}

/*Procedure SplitList(input L:List2, output L1:List2, output L2:List2)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List2 L, List2 *L1, List2 *L2) {
   /* kamus lokal */
   address P;
   int tengah, index;
   
   /* algoritma */

   // buat L1 dan L1
   CreateList(L1);
   CreateList(L2);

   if (!IsEmptyList(L)) {     // jika tidak kosong

      // insialisasi P dengan elemen pertana L
      P = First(L);

      // cari index tengah L
      tengah = NbElm(L) / 2;

      // mulai dari index ke 1
      index = 1;

      // loop untuk memecah list
      while (next(P) != First(L)) {

         // jika index masih <= tengah
         if (index <= tengah) {
            
            // masukan elemen P ke L1
            InsertVLast(L1, info(P));

         } else { // jika index sudah lebih dari tengah
            
            // masukan elemen P ke L2
            InsertVLast(L2, info(P));

         }

         P = next(P);
         index++;
      }

      // tambahkan elemen terakhir ke L2
      InsertVLast(L2, info(P));
   }
}

/*Procedure CopyList(input L1:List2, output L2:List2)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List2 L1, List2 *L2) {
   /* kamus lokal */
	address P;

	/* algoritma */

   // buat list L2
	CreateList(L2);

	if (!IsEmptyList(L1)) { // jika tidak kosong

      // inisialisasi P dengan elemen pertama L1
		P = First(L1);

      // loop untuk mengcopy elemen pertama sampe sebelum terakhir 
		while (next(P) != First(L1)) {

         // masukan elemen P ke L2
			InsertVLast(L2, info(P));

         
			P = next(P);
		}

      // masukan elemen terakhir ke L2
      InsertVLast(L2, info(P));
	}
}
