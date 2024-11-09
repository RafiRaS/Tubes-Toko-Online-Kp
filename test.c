#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


intmain(){
    char buku[1000][3][50];
    FILE *file;
    int index = 0;
    char line[50];

    file = fopen("buku.txt","r");

    while(fgets(line, sizeof(line), file) != NULL){
        line[strcspn(line,"\n")] = 0;

        char *nama = strtok(line,"|");
        char *harga = strtok(NULL,"|");
        char *stok = strtok(NULL,"|");

        strncpy(buku[index][0], nama, 50);
        strncpy(buku[index][1], harga, 50);
        strncpy(buku[index][2], stok, 50);
        index++;
    }

        
        return 0;
}
