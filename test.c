#include <stdio.h>
#include <time.h>

int main() {
    // Nama file
    const char *filename = "userwaktu.txt";

    // Membuka file untuk dibaca
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Gagal membuka file");
        return 1;
    }

    // Variabel untuk menyimpan waktu mentah
    time_t raw_time;

    // Membaca waktu mentah dari file
    if (fscanf(file, "%ld", &raw_time) != 1) {
        perror("Gagal membaca waktu dari file");
        fclose(file);
        return 1;
    }

    // Menutup file setelah selesai membaca
    fclose(file);

    // Mengonversi waktu mentah ke struct tm (waktu lokal)
    struct tm *time_info = localtime(&raw_time);

    // Buffer untuk menyimpan string tanggal
    char formatted_date[100];

    // Memformat struct tm menjadi string (hari, tanggal, bulan, tahun, jam, menit)
    strftime(formatted_date, sizeof(formatted_date), "%A, %d %B %Y %H:%M", time_info);

    // Menampilkan hasil
    printf("Waktu dalam format: %s\n", formatted_date);

    return 0;
}
