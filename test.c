#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

// Deklarasi fungsi
void displayMenuBuku();
void displayCategoryOthers(char others[1000][5][100], int jumlahOthers);
int handleInput();
void sortProductsByPrice(char array[1000][5][100], int jumlah);
void showTopSellingItems(char buku[1000][5][100], int jumlahBuku, char fashion[1000][5][100], int jumlahFashion, char obat[1000][5][100], int jumlahObat, char others[1000][5][100], int jumlahOthers);
void copyDataToTopSelling(char source[1000][5][100], int sourceCount, char dest[2000][5][100], int *destIndex);
void printProductTable(char array[1000][5][100], int jumlah);

void displayCategoryOthers(char others[1000][5][100], int jumlahOthers) {
    system("cls");
    printProductTable(others, jumlahOthers);

    printf("\n0.kembali\n");
    printf("1.masukan barang ke dalam keranjang\n");
    printf("2.sorting\n");
}

void printProductTable(char array[1000][5][100], int jumlah) {
    printf("+----+--------------------------------------------+-------------------+------+\n");
    printf("| No |Nama Barang                                 |Harga              |Stok  |\n");
    printf("+----+--------------------------------------------+-------------------+------+\n");
    for (int i = 0; i < jumlah; i++) {
        printf("| %-2d | %-42s | %-17s | %-4s |\n", i + 1, array[i][0], array[i][1], array[i][2]);
        printf("+----+--------------------------------------------+-------------------+------+\n");
    }
}

int handleInput() {
    int input;
    scanf("%d", &input);
    getchar();
    return input;
}

void sortProductsByPrice(char array[1000][5][100], int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        for (int j = 0; j < jumlah - 1; j++) {
            int price1 = atoi(array[j][1]);
            int price2 = atoi(array[j + 1][1]);
            if (price1 > price2) {
                char temp[5][100];
                for (int k = 0; k < 5; k++) {
                    strcpy(temp[k], array[j][k]);
                    strcpy(array[j][k], array[j + 1][k]);
                    strcpy(array[j + 1][k], temp[k]);
                }
            }
        }
    }
}

void showTopSellingItems(char buku[1000][5][100], int jumlahBuku, char fashion[1000][5][100], int jumlahFashion, char obat[1000][5][100], int jumlahObat, char others[1000][5][100], int jumlahOthers) {
    char terlaris[2000][5][100];
    int index = 0;

    // Copy data dari kategori buku
    copyDataToTopSelling(buku, jumlahBuku, terlaris, &index);
    // Copy data dari kategori fashion
    copyDataToTopSelling(fashion, jumlahFashion, terlaris, &index);
    // Copy data dari kategori obat
    copyDataToTopSelling(obat, jumlahObat, terlaris, &index);
    // Copy data dari kategori others
    copyDataToTopSelling(others, jumlahOthers, terlaris, &index);

    int jumlahTerlaris = index;

    // Sorting berdasarkan jumlah terjual
    sortProductsByPrice(terlaris, jumlahTerlaris);

    // Menampilkan produk terlaris
    printf("+----+--------------------------------------------+-------------------+------+--------+\n");
    printf("| No |Nama Barang                                 |Harga              |Stok  |Terjual |\n");
    printf("+----+--------------------------------------------+-------------------+------+--------+\n");
    for (int i = 0; i < jumlahTerlaris; i++) {
        printf("| %-2d | %-42s | %-17s | %-4s |%-8s|\n", i + 1, terlaris[i][0], terlaris[i][1], terlaris[i][2], terlaris[i][4]);
        printf("+----+--------------------------------------------+-------------------+------+--------+\n");
    }
}

void copyDataToTopSelling(char source[1000][5][100], int sourceCount, char dest[2000][5][100], int *destIndex) {
    for (int i = 0; i < sourceCount; i++) {
        strcpy(dest[*destIndex][0], source[i][0]);
        strcpy(dest[*destIndex][1], source[i][1]);
        strcpy(dest[*destIndex][2], source[i][2]);
        strcpy(dest[*destIndex][3], source[i][3]);
        strcpy(dest[*destIndex][4], source[i][4]);
        (*destIndex)++;
    }
}

int main() {
    int input;
    char buku[1000][5][100], fashion[1000][5][100], obat[1000][5][100], others[1000][5][100];
    int jumlahBuku = 5, jumlahFashion = 5, jumlahObat = 5, jumlahOthers = 5;

    // Asumsikan array buku, fashion, obat, others telah diisi dengan data yang sesuai

    // Menampilkan kategori Others
    displayCategoryOthers(others, jumlahOthers);
    input = handleInput();

    if (input == 0) {
        // Kembali ke menu sebelumnya
    } else if (input == 2) {
        // Sorting produk
        sortProductsByPrice(others, jumlahOthers);
        displayCategoryOthers(others, jumlahOthers);
    } else if (input == 1) {
        // Menangani masukkan barang ke keranjang
        printf("Anda belum login, tidak bisa memasukkan barang ke dalam keranjang\n");
        // Kembali ke menu
    }

    // Menampilkan produk terlaris
    showTopSellingItems(buku, jumlahBuku, fashion, jumlahFashion, obat, jumlahObat, others, jumlahOthers);

    return 0;
}
