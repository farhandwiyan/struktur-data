/* File : list3.c */
/* Deskripsi : ADT list berkait dengan representasi fisik pointer */
/* NIM & Nama : Farhan Dwiyan Akbar - 24060124140137 */
/* Tanggal : 20 November 2025 */

#include <stdio.h>
#include <stdlib.h>

#include "list3.h"

/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) //representasi fisik fungsi
{	//kamus lokal
	address P;

	//algoritma
	P = (address)malloc(sizeof(Elm));

	if (P != NIL) {
      info(P) = E;
		next(P) = NIL;
		prev(P) = NIL;
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
	if ( *P != NIL ) {
		free(*P);
	}
}

/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List3)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List3 *L) {
   /* kamus lokal */

   /* algoritma */
   First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List3) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List3 L) {
   /* kamus lokal */

   /* algoritma */
   return First(L) == NIL;
}

/*PENELUSURAN*/
/*procedure PrintList(input L:List3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(List3 L) {
   /* kamus lokal */
   address P;

   /* algoritma */
   P = First(L);

   printf("Elemen = ");
   if (!IsEmptyList(L)) {  // jika tidak kosong
      
      do {
         printf("\t%c", info(P));
         P = next(P);
      } while (P != NIL);
      
   }
}

/*function NbElm(L:List3) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List3 L) {
   /* kamus lokal */
   address P;
   int count;

   /* algoritma */
   count = 0;  // mulai dari 0

   if (!IsEmptyList(L)) {  // jika tidak kosong
      
      // mulai P dari elemen pertama
      P = First(L);

      // loop untuk mencari banyak elemen
      while (P != NIL) {
         count++;
         P = next(P);
      } // endwhile jika next(P) = NIL atau berada di elemen terakhir

      return count;

   } else { // jika kosong
      return count;
   }
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List3 *L, infotype V ) {
   /* kamus lokal */
   address P, A;

   /* algoritma */
   A = Alokasi(V);

   if (A != NIL) {     
      if (!IsEmptyList(*L)) { // jika tidak kosong
      
      // mulai dari elemen pertama
      P = First(*L);

      // ubah prev elemen pertama jadi A (elemen baru)
      prev(P) = A;

      // ubah next dari A menjadi elemen first yang lama
      next(A) = P;

      // jadikan prev A menjadi NIL karena A akan menjadi elemen pertama yang baru
      prev(A) = NIL;

      // jadikan A sebagai elemen pertama yang baru
      First(*L) = A;

      } else { // jika kosong  
   
      // jadikan A menjadi elemen pertama
      First(*L) = A;

      }
   }  
}

/*Procedure InsertVLast(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List3 *L, infotype V ) {
   /* kamus lokal */
   address P, A;

   /* algoritma */
   A = Alokasi(V);

   if (!IsEmptyList(*L)) { // jika tidak kosong
      
      // mulai dari elemen pertama
      P = First(*L);

      // loop untuk cari elemen terakhir
      while (next(P) != NIL) {
         P = next(P);
      }  // end while jika next(P) = NIL

      // ubah next P menjadi A (elemen baru)
      next(P) = A;

      // ubah prev A menjadi P 
      prev(A) = P;

      // ubah next A menjadi NIL karena A sekarag sebagai elemen terakhir
      next(A) = NIL;
      
   } else { // jika kosong

      // jadikan A sebagai elemen pertama
      First(*L) = A;

   }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List3 *L, infotype *V) {
   /* kamus lokal */
   address P;

   /* algoritma */
   if (!IsEmptyList(*L)) { // jika tidak kosong
      
      // elemen pertama
      P = First(*L);
      
      // simpan elemen pertama ke V
      *V = info(P);

      if (next(P) != NIL) {

         // ubah prev dari elemen kedua menjadi NIL karena akan menjadi elemen pertama
         prev(next(P)) = NIL;

         // jadikan elemen kedua menjadi elemen pertama dari list
         First(*L) = next(P);

      } else {
         First(*L) = NIL;
      }

      Dealokasi(&P);

   } else { // jika kosong
      *V = '#';
   }
}

/*Procedure DeleteVLast(input/output L:List3, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List3 *L, infotype *V) {
   /* kamus lokal */
   address P;

   /* algoritma */
   if (!IsEmptyList(*L)) {

      // mulai dari elemen pertama
      P = First(*L);

      if (next(P) != NIL) {   // jika lebih dari satu elemen
         
         // loop untuk mencari elemen terakhir
         while (next(P) != NIL) {
            P = next(P);
         }  // end while jika next(P) = NIL

         *V = info(P);

         next(prev(P)) = NIL; 

      } else { // jika satu elemen
         *V = info(P);
      }

      Dealokasi(&P);
   } else {
      *V = '#';
   }
}

/*Procedure DeleteX(input/output L:List3, input X:infotype)
{ I.S. List L terdefinisi }
{ F.S. List mungkin menjadi kosong, atau berkurang 1 elemen. }
{ Proses: Elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteX(List3 *L, infotype X) {
   /* kamus lokal */
   address P, A;
   boolean found;

   /* algoritma */
   if (!IsEmptyList(*L)) { // jika tidak kosong

      // mulai dari elemen pertama
      P = First(*L);

      // mulai found dengan False
      found = False;

      // loop mencari X
      while (next(P) != NIL && !found) {
         if (info(P) == X) {  // jika ketemu
            found = True;
            A = P;   // simpan alamat ke A
         }

         P = next(P);   // lanjut hingga akhir
      }  // end while jika next(P) = NIL atau found = True

      // cek elemen terakhir
      if (info(P) == X && !found) {
         found = True;
      }

      // jika ketemu
      if (found) {
         if (A == First(*L)) {   // jika ketemu di elemen pertama
            
            // ubah prev dari elemen kedua menjadi NIL karena akan menjadi elemen pertama
            if (next(A) != NIL) {
               prev(next(A)) = NIL;
            }

            // jadikan elemen kedua menjadi elemen pertama dari list
            First(*L) = next(A);

         } else if (A == P) {    // jika ketemu di elemen terakhir
            
            // ubah next dari elemen sebelum terakhir jadi NIL
            next(prev(A)) = NIL;

         } else {

            // ubah next dari elemen sebelum A menjadi next A
            next(prev(A)) = next(A);

            // ubah prev elemen setelah A menjadi elemen sebelum A 
            prev(next(A)) = prev(A);

         }

         Dealokasi(&A);
      }
   } 
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List3, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X. }
{ Proses : Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List3 L, infotype X, address *A) {
   /* kamus lokal */
	address P;

	/* algoritma */
	P = First(L);  // mulai dari elemen pertama
	*A = NIL;   // inisialisasi A dengan NIL

   // loop mencari X
	while (next(P) != NIL && *A == NIL) {
		if (info(P) == X) {
			*A = P;	
		}

		P = next(P);
	}  // endwhile jika next(P) = NIL atau A != NIL

   // cek elemen terakhir
   if (*A == NIL && info(P) == X) {
      *A = P;
   }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List3, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.}
{ Proses : Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List3 *L, infotype X, infotype Y) {
   /* kamus lokal */
    address P;

   /* algoritma */
    P = First(*L);   // mulai dari elemen pertama

   // loop mencari X
   while (next(P) != NIL && info(P) != X) {
        P = next(P);
   }  // end while jika next(P) = NIL atau info(P) = X

   // cek elemen terakhir
   if (info(P) == X && P != NIL) {
        info(P) = Y;
   }
}

/*Procedure Invers(input/output L:List3)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(List3 *L) {
    address P, temp;

    if (!IsEmptyList(*L)) {

        P = First(*L);

        // Telusuri sambil menukar prev dan next
        while (P != NIL) {

            // Simpan prev lama
            temp = prev(P);

            // Tukar prev dan next
            prev(P) = next(P);
            next(P) = temp;

            // Pindah ke elemen selanjutnya
            P = prev(P);
        }   // end while jika P = NIL

        if (temp != NIL) {
            First(*L) = prev(temp);
        }
    }
}


/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*Procedure InsertVAfterX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List3 *L, infotype X, infotype V) {
   /* kamus lokal */
   address P, A;
   boolean found;

   /* address */
   if (!IsEmptyList(*L)) { // jika tidak kosong
      
      // mulai dari elemen petama
      P = First(*L);

      // mulai found dengan false
      found = False;

      // loop untuk mencari X
      while (next(P) != NIL && !found) {
         
         // jika ketemu
         if (info(P) == X) {
            found = True;
         } else { // jika tidak ketemu
            P = next(P);   // lajut ke elemen berikutnya
         }
      } // endwhile jika next(P) = X atau found = True

      // cek elemen terakhir
      if (!found && info(P) == X) {
         found = True;
      }

      // jika ketemu
      if (found) {
         
         if (next(P) != NIL) {   // jika ketemu tidak di elemen terakhir
            A = Alokasi(V);   // alokasi V
            
            // ubah next(A) menjadi elemen setelah P
            next(A) = next(P); 

            // ubah prev A menjadi P
            prev(A) = P;
            
            // ubah prev dari elemen setelah P menjadi A
            prev(next(P)) = A;

            // jadikan A sebagai elemen setelah P
            next(P) = A;
         } else {    // jika ketemu di elemen terakhir
            InsertVLast(L, V);
         }
      }
   }
}

/*Procedure InsertVBeforeX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List3 *L, infotype X, infotype V) {
   /* kamus lokal */
   address P, A;
   boolean found;

   /* algoritma */
   if (!IsEmptyList(*L)) {    // jika tidak kosong

      // mulai dari elemen petama
      P = First(*L);

      // mulai found dengan false
      found = False;

      // loop untuk mencari X
      while (next(P) != NIL && !found) {
         
         // jika ketemu
         if (info(P) == X) {
            found = True;
         } else { // jika tidak ketemu
            P = next(P);   // lajut ke elemen berikutnya
         }
      } // endwhile jika next(P) = X atau found = True

      // cek elemen terakhir
      if (!found && info(P) == X) {
         found = True;
      }

      if (found) {   // jika ketemu
         if (P == First(*L)) {   // jika ketemu di elemen pertama
            InsertVFirst(L, V);
         }  else {   // jika ketemu tidak di elemen pertama
            A = Alokasi(V);   // alokasi A

            // ubah prev A menjadi elemen sebelum P
            prev(A) = prev(P);

            // ubah next dari elemen sebelum P menjadi A
            next(prev(P)) = A;

            // jadikan P sebagai elemen setelah A
            next(A) = P;

            // jadikan A sebagai elemen sebelum P
            prev(P) = A;

         }
      }
   }
}

/*Procedure DeleteVAfterX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List3 *L, infotype X, infotype *V) {
   /* kamus lokal */
   address P, nextElmt;
   boolean found;

   /* algoritma */
   *V = '#';   // mulai V dengan '#' 
   if (!IsEmptyList(*L)) {    // jika tidak kosong
      
      // mulai dari elemen pertama
      P = First(*L);

      // mulai found dengan false
      found = False;

      // loop mencari X
      while (next(P) != NIL && !found) {
         
         // jika ketemu
         if (info(P) == X) {
            found = True;
         } else { // jika tidak ketemu
            P = next(P);   // lanjut ke elemen selanjutnya
         }
      }  // end while jika next(P) = NIL atau found = True

      // cek elemen terakhir
      if (!found && info(P) == X) {
         found = True;
      }


      // jika ketemu
      if (found) {
         if (next(P) != NIL) {   // jika ketemu tidak di elemen terakhir
            
            // simpan elemen setelah P
            nextElmt = next(P);
               
            // simpan elemen setelah P ke V
            *V = info(nextElmt); 
            
            if (NbElm(*L) > 2) { // jika jumlah elemen dari list lebih dari 2
               
               // ubah next P menjadi elemen setelah nextElmt
               next(P) = next(nextElmt);

               // ubah prev dari elemen setelah nextElmt menjadi P
               prev(next(nextElmt)) = P;

            } // jika jumlah elemen <= 2 maka akan langsung menghapus elemen kedua 

            Dealokasi(&nextElmt);
         }  // asumsi: jika ketemu di elemen terakhir maka V akan mengeluarkan nilai kosong, yaitu '#'
      }  // asumsi: jika tidak ketemu maka V akan mengeluarkan nilai kosong, yaitu '#'
   }  // asumsi: jika list kosong maka V akan mengeluarkan nilai kosong, yaitu '#'
}

/*Procedure DeleteVBeforeX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List3 *L, infotype X, infotype *V) {
   /* kamus lokal */
   address P, prevElmt;
   boolean found;

   /* algoritma */
   *V = '#';   // mulai V dengan '#'
   if (!IsEmptyList(*L)) {    // jika tidak kosong
      
      // mulai dari elemen pertama
      P = First(*L);

      // mulai found dengan false
      found = False;

      // loop mencari X
      while (next(P) != NIL && !found) {
         
         // jika ketemu
         if (info(P) == X) {
            found = True;
         } else { // jika tidak ketemu
            P = next(P);   // lanjut ke elemen selanjutnya
         }
      }  // end while jika next(P) = NIL atau found = True

      // cek elemen terakhir
      if (!found && info(P) == X) {
         found = True;
      }


      if (found) {   // jika ketemu
         if (prev(P) != NIL) {   // jika ketemu tidak di elemen pertama
            
            // simpan elemen sebelum P
            prevElmt = prev(P); 

            // simpan elemen sebelum P ke V
            *V = info(prevElmt);
            
            if (NbElm(*L) > 2) { // jumlah elemen list lebih dari 2

               // ubah next dari elemen sebelum prevElmt menjadi P
               next(prev(prevElmt)) = P;

               // ubah prev dari P menjadi elemen sebelum prevElmt
               prev(P) = prev(prevElmt);

            } else { // jika jumlah elemen list <= 2
               First(*L) = P; // jadikan P sebagai elemen pertama
            }

            Dealokasi(&prevElmt);
         }  // asumsi: jika ketemu di elemen pertama maka V akan mengeluarkan nilai kosong, yaitu '#'
      }  // asumsi: jika tidak ketemu maka V akan mengeluarkan nilai kosong, yaitu '#'
   }  // asumsi: jika list kosong maka V akan mengeluarkan nilai kosong, yaitu '#'
}

/*function CountX(L:List3, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List3 L, infotype X) {
   /* kamus lokal */
   address P;
   int count;

   /* algoritma */
   count = 0;  // mulai count dari 0
   
   if (!IsEmptyList(L)) {  // jika tidak kosong
      P = First(L); // mulai dari elemen pertama

      // loop untuk menghitung jumlah kemunculan X
      while (next(P) != NIL) {
         if (info(P) == X) {  // jika ketemu
            count++;
         }

         // lanjut ke elemen selanjutnya
         P = next(P);
      }  // end while jika next(P) = NIL

      // cek elemen terakhir
      if (info(P) == X && next(P) == NIL) {
         count++;
      }

      return count;
   } else { // jika kosong
      return count;
   }
}

/*function FrekuensiX(L:List3, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List3 L, infotype X) {
   /* kamus lokal */
   
   /* algoritma */
   return (float) CountX(L, X) / (float) NbElm(L);
}

/*function MaxMember(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List3 L) {
   /* kamus lokal */
   address P;
   int max, frek;

   /* algoritma */
   max = 0; // mulai dari 0

   if (!IsEmptyList(L)) {  // jika tidak kosong
      P = First(L); // mulai dari elemen pertama

      // loop untuk mencari banyaknya huruf yang paling banyak muncul
      while (next(P) != NIL) {
         
         // hitung banyaknya frekuensi tiap elemen
         frek = CountX(L, info(P));

         if (frek > max) { // jika frek lebih banyak dari jumlah max
            max = frek; // ganti nilai max menjadi frek
         }

         // lanjut ke elemen berikutnya
         P = next(P);
      }  // end while jika next(P) = NIL

      // cek elemen terakhir
      if (next(P) == NIL) {
         frek = CountX(L, info(P));

         if (frek > max) {
            max = frek;
         }
      }

      return max;
   } else {
      return max;
   }
}

/*function Modus(L:List3) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List3 L) {
   /* kamus lokal */
   address P;
   int frek, max;
   infotype modus;

   /* algoritma */
   
   if (!IsEmptyList(L)) {  // jika tidak kosong
      
      // mulai dari elemen pertama
      P = First(L); 
      modus = info(P);

      // mulai dari 0
      max = 0;

      // loop untuk mencari modus
      while (next(P) != NIL) {
         frek = CountX(L, info(P)); // hitung frek masing masing elemen

         if (frek > max) { // jika frek lebih banyak dari nilai max
            max = frek; // ubah max dengan frek
            modus = info(P);  // ubah modus dengan elemen P
         }

         // lanjut ke elemen berikutnya
         P = next(P);
      }  // end while jika next(P) = NIL

      // cek elemen terakhir
      if (next(P) == NIL) {
         frek = CountX(L, info(P)); // hitung frek masing masing elemen

         if (frek > max) { // jika frek lebih banyak dari nilai max
            max = frek; // ubah max dengan frek
            modus = info(P);  // ubah modus dengan elemen P
         }
      }

      return modus;
   } else { // jika kosong
      modus = '#';   // asumsi: jika list kosong maka akan mengembalikan elemen kosong, yaitu '#'
      
      return modus;
   }
}

/*function CountVocal(L:List3) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List3 L) {
   /* kamus lokal */
   int vocal;
   address P;
   infotype c;

   /* algoritma */
   vocal = 0;  // mulai dari 0

   if (!IsEmptyList(L)) {  // jika tidak kosong
      P = First(L);  // mulai dari elemen pertama

      // loop mencari banyaknya huruf vocal
      while (next(P) != NIL) {
         c = info(P);   // simpan elemen P ke c

         // jika c adalah huruf vocal
         if (c == 'a' || c == 'i' || c =='u' || c =='e' || c == 'o' ||
             c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O') {
            vocal++; 
         }

         // lanjut ke elemen berikutnya
         P = next(P);
      } // end while jika next(P) = NIL

      // cek elemen terakhir
      c = info(P);  
      if ((next(P) == NIL) && (c == 'a' || c == 'i' || c =='u' || c =='e' || c == 'o' ||
         c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O')) {
            vocal++; 
      }

      return vocal;
   } else { // jika kosong
      return vocal;
   }
}

/*function CountNG(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List3 L) {
   /* kamus lokal */
   address P;
   infotype c, nextC;
   int count;

   /* algoritma */
   count = 0;     // mulai count dengan 0

   if (!IsEmptyList(L)) {     // jika tidak kosong

      // inisialisasi P dengan elemen pertama
      P = First(L);

      // loop untuk mencari banyaknya huruf N yang diikuti G
      while (next(P) != NIL) {

         // simpan elemen P ke c
         c = info(P);

         // simpan elemen setelah p ke nextC
         nextC = info(next(P));

         // lakukan pengecekan dengan membandingan c dengan elemen setelahnya
         if ((c == 'n' || c == 'N') & (nextC == 'g' || nextC == 'G')) {
            count++;
         }

         // lanjut ke elemen berikutnya
         P = next(P);
      }  // end while jika next(P) = NIL

      return count;

   } else {    // jika kosong
      return count;
   }
}

/*Procedure SearchAllX(input L:List3, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. - }
{ Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List3 L, infotype X) {
   /* kamus lokal */
   address P;
   int index;
   boolean found;

   /* algoritma */
   index = 0;  // mulai dari 0

   if (!IsEmptyList(L)) {    // jika tidak kosong

      // mulai dari elemen pertama
      P = First(L);


      // mulai found dengan false
      found = False;

      // loop mencari X
      printf("Elemen %c ketemu di posisi: ", X);
      while (next(P) != NIL) {
         
         // index + 1
         index++;

         // jika ketemu
         if (info(P) == X) {
            printf("%d ", index);
            found = True;
         }

         // lanjut ke elemen berikutnya
         P = next(P);
      }  // end while jika next(P) = NIL

      // lakukan pengecekan elemen terakhir
      index++;
      if (info(P) == X) {
         printf("%d", index);
      }

      // jika tidak ketemu
      if (!found) {
         index = 0;  // ubah index menjadi 0 (karena tidak ketemu di list)
         printf("%d", index);
      }
   } else { // jika kosong
      printf("%d", index);
   }
}

/*Procedure DeleteAllX(input/output L:List3, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. List mungkin menjadi kosong. }
{ Proses: Semua elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteAllX(List3 *L, infotype X) {
   /* kamus lokal */
   address P, del;

   /* algoritma */
   if (!IsEmptyList(*L)) { // jika tidak kosong
      P = First(*L); // mulai dari elemen pertama

      // loop untuk hapus X sampai elemen sebelum terakhir
      while (P != NIL) {
         
         // jika ketemu
         if (info(P) == X) { 
            del = P; // simpan yang ingin dihapus

            if (prev(P) == NIL) {   // jika ketemu di elemen pertama
               
               // ubah prev elemen setelah P menjadi NIL
               if (next(P) != NIL) {
                    prev(next(P)) = NIL;
                }

               // jadikan elemen setelah P menjadi elemen pertama
               First(*L) = next(P);
            } else { // jika ketemu tidak di elemen pertama 

               // ubah next elemen sebelum P menjadi elemen setelah P
               next(prev(P)) = next(P);  

               // ubah prev dari elemen setelah P menjadi elemen sebelum P
               if (next(P) != NIL) {
                  prev(next(P)) = prev(P);
               }
            }

            P = next(P);
            Dealokasi(&del);
         } else { // tidak tidak ketemu
            
            // lanjut ke elemen berikutnya
            P = next(P);
         }
      }  // end while jika next(P) = NIL
   }
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List3, input L2:List3, output L:List3)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List3 L1, List3 L2, List3 *L) {
   /* kamus lokal */
	address P;

	/*algoritma */
	CreateList(L); // buat list L

	if (IsEmptyList(L1)) {  // jika L1 kosong
		
      // jadikan elemen pertama L2 sebagai elemen pertama L
      First(*L) = First(L2); 

	} else if (IsEmptyList(L2)) {  // jika L2 kosong

      // jadikan elemen pertama L1 sebagai elemen pertama L
		First(*L) = First(L1);

	} else { // jika L1 dan L2 tidak kosong

		P = First(L1); // mulai dari elemen pertama L1

      // loop sampai elemen terakhir dari L1
		while (P != NIL) {
         InsertVLast(L, info(P));  // insert elemen P ke list L
			
         // lanjut ke elemen berikutnya
         P = next(P);
		}  // end while jika P = NIL

      P = First(L2); // mulai dari elemen pertama L2

      // loop sampai elemen terakhir dari L2
		while (P != NIL) {
         InsertVLast(L, info(P));  // insert elemen P ke list L
			
         // lanjut ke elemen berikutnya
         P = next(P);
		}  // end while jika P = NIL
		
	}
}

/*Procedure SplitList(input L:List3, output L1:List3, output L2:List3)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List3 L, List3 *L1, List3 *L2) {
   /* kamus lokal */
	address P;
	int tengah, index;

	/* algoritma */
	CreateList(L1);   // buat list L1
	CreateList(L2);   // buat list L2

	if (!IsEmptyList(L)) {  // jika tidak kosong
		P = First(L);  // mulai dari elemen pertama

		tengah = NbElm(L) / 2;
		index = 1;  // mulai dari 1

      // loop untuk split list
		while (P != NIL) {
			if (index <= tengah) {  // jika index dari 1 sampe tengah
				InsertVLast(L1, info(P));  // insert ke list L1
			} else { // jika index sudah lebih dari tengah
				InsertVLast(L2, info(P));  // insert ke list L2
			}  // end while jika P = NIL

         // lanjutkan ke elemen berikutnya
			P = next(P);

         // index + 1
			index++;
		}
	} 
}

/*Procedure CopyList(input L1:List3, output L2:List3)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List3 L1, List3 *L2) {
   /* kamus lokal */
	address P;

	/* algoritma */
	CreateList(L2);   // buat list L2

	if (!IsEmptyList(L1)) { // jika tidak kosong
		P = First(L1); // mulai dari elemen pertama

      // loop untuk copy tiap elemen L1 ke L2
		while (P != NIL) {   
			InsertVLast(L2, info(P));  // insert elemen P ke L2
			
         // lanjutkan ke elemen berikutnya
         P = next(P);
		}  // end while jika P = NIL
	}
}
