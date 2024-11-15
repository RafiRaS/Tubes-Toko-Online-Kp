#include <stdio.h>
#include <string.h>

int main() {
    // Deklarasi array
    char obat[1000][5][100] = {{"Paracetamol", "10", "2", "0", "Ready"}};
    char fashion[1000][5][100] = {{"T-Shirt", "150000", "1", "0", "Ready"}};
    char others[1000][5][100] = {{"Book", "50000", "3", "10", "Out of Stock"}};
    char keranjang[1000][5][100] = {{"Notebook", "25000", "5", "5", "Ready"}};
    
    // Array pointer untuk mengakses setiap array
    char (*arrays[4])[5][100] = {obat, fashion, others, keranjang};
    const char *array_names[4] = {"Obat", "Fashion", "Others", "Keranjang"};
    
    // Satu loop untuk mencetak semua isi array
    for (int i = 0; i < 4; i++) {
        printf("Kategori: %s\n", array_names[i]);
        for (int j = 0; j < 1000; j++) {
            if (strlen(arrays[i][j][0]) == 0) break; // Berhenti jika data kosong
            printf("  Item %d:\n", j + 1);
            printf("    Nama   : %s\n", arrays[i][j][0]);
            printf("    Harga  : %s\n", arrays[i][j][1]);
            printf("    Jumlah : %s\n", arrays[i][j][2]);
            printf("    Diskon : %s%%\n", arrays[i][j][3]);
            printf("    Status : %s\n", arrays[i][j][4]);
        }
    }

    return 0;
}
