#include <stdio.h>

int main() {
    // Membuka atau membuat file baru dengan nama "userwallet.txt"
    FILE *file = fopen("userwallet.txt", "w");

    // Mengecek apakah file berhasil dibuka
    if (file) {
        // Menulis angka 0 ke dalam file
        fprintf(file, "0");

        // Menutup file setelah selesai menulis
        fclose(file);
        printf("File userwallet.txt telah dibuat dan diisi dengan 0.\n");
    } else {
        printf("Gagal membuka file untuk penulisan.\n");
    }

    return 0;
}
