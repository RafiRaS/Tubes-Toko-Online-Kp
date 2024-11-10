#include <stdio.h>
#include <string.h>

int main() {
    char kategoriBarang[50];
    char namaBarang[50];
    char hargaBarang[50];
    char stokBarang[50];
    char beratBarang[50];

    // Input kategori barang
    printf("Masukan kategori barang:\n");
    printf("buku|fashion|obat|others\n");
    fgets(kategoriBarang, sizeof(kategoriBarang), stdin);
    kategoriBarang[strcspn(kategoriBarang, "\n")] = '\0';  // Menghapus newline di akhir string

    // Input nama barang yang bisa mengandung spasi
    printf("Masukin nama barang: ");
    fgets(namaBarang, sizeof(namaBarang), stdin);
    namaBarang[strcspn(namaBarang, "\n")] = '\0';  // Menghapus newline di akhir string

    // Input harga barang (menggunakan fgets untuk menghindari masalah spasi)
    printf("Masukin harga barang: ");
    fgets(hargaBarang, sizeof(hargaBarang), stdin);
    hargaBarang[strcspn(hargaBarang, "\n")] = '\0';  // Menghapus newline di akhir string

    // Input stok barang
    printf("Masukin stok barang: ");
    fgets(stokBarang, sizeof(stokBarang), stdin);
    stokBarang[strcspn(stokBarang, "\n")] = '\0';  // Menghapus newline di akhir string

    // Input berat barang
    printf("Masukin berat barang: ");
    fgets(beratBarang, sizeof(beratBarang), stdin);
    beratBarang[strcspn(beratBarang, "\n")] = '\0';  // Menghapus newline di akhir string

    // Menampilkan hasil input
    printf("\nData Barang:\n");
    printf("Kategori Barang: %s\n", kategoriBarang);
    printf("Nama Barang: %s\n", namaBarang);
    printf("Harga Barang: %s\n", hargaBarang);
    printf("Stok Barang: %s\n", stokBarang);
    printf("Berat Barang: %s\n", beratBarang);

    return 0;
}