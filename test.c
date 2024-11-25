#include <stdio.h>
#include <time.h>

int main() {
    // Mendapatkan jumlah detik sejak 1 Januari 1970
    time_t epoch_time = time(NULL);

    // Menampilkan jumlah detik
    printf("Jumlah detik sejak 1 Januari 1970: %ld\n", epoch_time);

    // Menyimpan dalam variabel untuk digunakan nanti
    long detik = (long)epoch_time;
    printf("Detik disimpan: %ld\n", detik);

    return 0;
}
