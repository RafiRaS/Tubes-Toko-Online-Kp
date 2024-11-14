#include <stdio.h>

int main() {
    FILE *file;
    char namaFile[] = "data.txt"; // Nama file yang akan dicek dan ditulis
    char data[] = "Halo, ini adalah contoh data yang ditulis ke file.";

    // Mengecek apakah file sudah ada dengan membuka dalam mode "r"
    file = fopen(namaFile, "r");

    if (file == NULL) {
        // Jika file tidak ada, buka dalam mode "w" (write)
        file = fopen(namaFile, "w");
        printf("File belum ada, membuat file baru dengan mode 'w'.\n");
    } else {
        // Jika file ada, buka dalam mode "a" (append)
        fclose(file); // Menutup file yang dibuka dalam mode "r"
        file = fopen(namaFile, "a");
        printf("File sudah ada, menambah data dengan mode 'a'.\n");
    }

    if (file == NULL) {
        printf("File tidak dapat dibuka.\n");
        return 1;
    }

    // Menulis data ke file
    fprintf(file, "%s\n", data);
    
    // Menutup file setelah selesai
    fclose(file);

    printf("Data telah ditulis ke dalam file %s\n", namaFile);

    return 0;
}
