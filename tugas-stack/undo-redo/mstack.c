/* Nama    : Kelompok 4 */
/* Tanggal : 20/09/2025 */
/***********************************/

#include <stdio.h>
#include <string.h>
#include "stack.h"

int main() {
    Tstack undo, redo;
    char temp[20];

    CreateStack(&undo);
    CreateStack(&redo);

    printf("=== Simulasi Undo–Redo Text Editor ===\n");

    /* Perintah baru */
    Push(&undo, "Buka");
    Push(&undo, "Ketik");
    Push(&undo, "Simpan");
    printf("\nSetelah 3 perintah awal:\n");
    printf("Undo stack: ");
    PrintStack(undo);
    printf("Redo stack: ");
    PrintStack(redo);

    /* Undo 1 */
    Pop(&undo, temp);
    if (strcmp(temp, "") != 0) {
        Push(&redo, temp);
        printf("\nUndo: %s\n", temp);
    }
    printf("Undo stack: ");
    PrintStack(undo);
    printf("Redo stack: ");
    PrintStack(redo);

    /* Redo 1 */
    Pop(&redo, temp);
    if (strcmp(temp, "") != 0) {
        Push(&undo, temp);
        printf("\nRedo: %s\n", temp);
    }
    printf("Undo stack: ");
    PrintStack(undo);
    printf("Redo stack: ");
    PrintStack(redo);

    /* Perintah baru */
    Push(&undo, "Simpan");
    CreateStack(&redo); // redo dikosongkan
    printf("\nSetelah perintah baru 'Simpan':\n");
    printf("Undo stack: ");
    PrintStack(undo);
    printf("Redo stack: ");
    PrintStack(redo);

    return 0;
}