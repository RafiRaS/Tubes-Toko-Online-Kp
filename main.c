#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
int input;
char loginID[25];
char loginPW[25];

char login[1000][2][25];
char seller[1000][2][25];
char user[1][2][1000];

char buku[1000][5][100];
char obat[1000][5][100];
char fashion[1000][5][100];
char others[1000][5][100];
char keranjang[1000][5][100];

char namaStok[100];
char updateStok[11];

//fungsi untuk menghitung banyak data dalam array
int menghitungBanyakData(char arr[1000][5][100]) {
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        if (strlen(arr[i][0]) > 0) {
            count++;
        } else {
            break;
        }
    }
    return count;
}


int main(){
    //tampilan menu awal
    menu:
    do{
        input = 0;
        system("cls");
        printf("Selamat datang di toko kami\n");
        printf("0.keluar program\n");
        printf("1.login user\n");
        printf("2.login seller\n");
        printf("3.register user\n");
        scanf("%d",&input);
    }while (input>4 || input<0);


    //baca file login.txt terus masukin ke array
    FILE * file;
    char line[50];
    int index = 0;
    int session = 0;

    file = fopen("login.txt","r");

    while(fgets(line, sizeof(line), file) != NULL){
        line[strcspn(line,"\n")] = 0;

        char *id = strtok(line,"|");
        char *pw = strtok(NULL,"|");

        strncpy(login[index][0], id, 25);
        strncpy(login[index][1], pw, 25);
        index++;
    }
    
    fclose(file);

    //baca file seller.txt terus masukin ke array 
    index = 0;
    int sessionSeller = 0;

    file = fopen("seller.txt","r");

    while(fgets(line, sizeof(line), file) != NULL){
        line[strcspn(line,"\n")] = 0;

        char *id = strtok(line,"|");
        char *pw = strtok(NULL,"|");

        strncpy(seller[index][0], id, 25);
        strncpy(seller[index][1], pw, 25);
        index++;
    }
    
    fclose(file);

    //baca file buku.txt, masukin ke array buku
    index = 0;

    file = fopen("buku.txt","r");

    while(fgets(line, sizeof(line), file) != NULL){
        line[strcspn(line,"\n")] = 0;

        char *nama = strtok(line,"|");
        char *harga = strtok(NULL,"|");
        char *stok = strtok(NULL,"|");
        char *berat = strtok(NULL,"|");
        char *sold = strtok(NULL,"|");

        strncpy(buku[index][0], nama, 50);
        strncpy(buku[index][1], harga, 50);
        strncpy(buku[index][2], stok, 50);
        strncpy(buku[index][3], berat, 50);
        strncpy(buku[index][4], sold, 100);
        index++;
    }

    //baca file fashion.txt, masukin ke array fashion
    index = 0;

    file = fopen("fashion.txt","r");

    while(fgets(line, sizeof(line), file) != NULL){
        line[strcspn(line,"\n")] = 0;

        char *nama = strtok(line,"|");
        char *harga = strtok(NULL,"|");
        char *stok = strtok(NULL,"|");
        char *berat = strtok(NULL,"|");
        char *sold = strtok(NULL,"|");

        strncpy(fashion[index][0], nama, 50);
        strncpy(fashion[index][1], harga, 50);
        strncpy(fashion[index][2], stok, 50);
        strncpy(fashion[index][3], berat, 50);
        strncpy(fashion[index][4], sold, 100);
        index++;
    }

    //baca file obat.txt, masukin ke array obat
    index = 0;

    file = fopen("obat.txt","r");

    while(fgets(line, sizeof(line), file) != NULL){
        line[strcspn(line,"\n")] = 0;

        char *nama = strtok(line,"|");
        char *harga = strtok(NULL,"|");
        char *stok = strtok(NULL,"|");
        char *berat = strtok(NULL,"|");
        char *sold = strtok(NULL,"|");

        strncpy(obat[index][0], nama, 50);
        strncpy(obat[index][1], harga, 50);
        strncpy(obat[index][2], stok, 50);
        strncpy(obat[index][3], berat, 50);
        strncpy(obat[index][4], sold, 100);
        index++;
    }

    //baca file others.txt, masukin ke array others
    index = 0;

    file = fopen("others.txt","r");

    while(fgets(line, sizeof(line), file) != NULL){
        line[strcspn(line,"\n")] = 0;

char *nama = strtok(line,"|");
        char *harga = strtok(NULL,"|");
        char *stok = strtok(NULL,"|");
        char *berat = strtok(NULL,"|");
        char *sold = strtok(NULL,"|");

        strncpy(others[index][0], nama, 50);
        strncpy(others[index][1], harga, 50);
        strncpy(others[index][2], stok, 50);
        strncpy(others[index][3], berat, 50);
        strncpy(others[index][4], sold, 100);
        index++;
    }

    //menginisialisasi fungsi untuk menentukan banyaknya data dalam array
    int jumlahBuku = menghitungBanyakData(buku);
    int jumlahObat = menghitungBanyakData(obat);
    int jumlahFashion = menghitungBanyakData(fashion);
    int jumlahOthers = menghitungBanyakData(others);


    //login user
    if(input == 1){
        system("cls");
        printf("login user\n");
        printf("masukan id       :");
        scanf("%s",&loginID);
        printf("masukan password :");
        scanf("%s",&loginPW);


        for(int i = 0;i<1000;i++){
                
            if (strcmp(loginID,login[i][0]) == 0 && strcmp(loginPW,login[i][1]) == 0){
                session = 1;
                 
            }
        }
        // AKSESES TOKO USER

        if(session == 1){
            system("cls");
            printf("login berhasil\n");
            printf("tekan tombol apa saja untuk lanjut\n");
            getch();
            sessionuser:
            do{
                system("cls");
                printf("Selamat datang %s\n",loginID);
                printf("0.logout\n");
                printf("1.cari barang\n");
                printf("2.lihat kategori\n");
                printf("3.Produk terlaris\n");
                printf("4.Cek Keranjang\n");
                printf("5.Check Out\n");
                scanf("%d",&input);
                getchar();
            }while (input>6 || input<-1);
            
            if(input == 1){
                int searchSession = 0;
                char namaBarang[50];
                system("cls");
                printf("ketik barang yang ingin dicari:");
                fgets(namaBarang, sizeof(namaBarang), stdin);
                namaBarang[strcspn(namaBarang, "\n")] = '\0';  //supaya bisa memasukan spasi dalam input
                
                //buat nyamain sama barang buku
                for(int i = 0;i<jumlahBuku;i++){
                    if(strcmp(namaBarang,buku[i][0]) == 0){
                        searchSession = 1;
                        system("cls");
                        printf("%s ditemukan, terletak di kategori buku, nomor %d\n",buku[i][0],i+1);
                        getch();
                        goto sessionBuku;
                    }
                }

                //buat nyamain sama barang fashion
                for(int i = 0;i<jumlahFashion;i++){
                    if(strcmp(namaBarang,fashion[i][0]) == 0){
                        searchSession = 1;
                        system("cls");
                        printf("%s ditemukan, terletak di kategori fashion, nomor %d\n",fashion[i][0],i+1);
                        getch();
                        goto sessionFashion;
                    }
                }

                //buat nyamain sama barang obat
                for(int i = 0;i<jumlahObat;i++){
                    if(strcmp(namaBarang,obat[i][0]) == 0){
                        searchSession = 1;
                        system("cls");
                        printf("%s ditemukan, terletak di kategori obat, nomor %d\n",obat[i][0],i+1);
                        getch();
                        goto sessionObat;
                    }
                }

                //buat nyamain sama barang others
                for(int i = 0;i<jumlahOthers;i++){
                    if(strcmp(namaBarang,others[i][0]) == 0){
                        searchSession = 1;
                        system("cls");
                        printf("%s ditemukan, terletak di kategori others, nomor %d\n",others[i][0],i+1);
                        getch();
                        goto sessionOthers;
                    }
                }

                if(searchSession == 0){
                    system("cls");
                    printf("%s tidak ditemukan\n",namaBarang);
                    getch();
                    goto sessionuser;
                }
            }

            else if(input == 2){
                menuBuku:
                do{
                    system("cls");
                    printf("1.buku\n");
                    printf("2.fashion\n");
                    printf("3.obat\n");
                    printf("4.others\n");
                    printf("5.back\n");
                    scanf("%d",&input);
                }while (input>6 || input<0);

                //kembali ke menu
                if(input == 5){
                    goto sessionuser;
                }

                //menampilkan kategori buku
                else if(input == 1){
                    sessionBuku:
                    system("cls");
                    for(int i = 0;i<jumlahBuku;i++){
                        printf("%d.%s\n",i+1,buku[i][0]);
                        printf("  harga = %s\n",buku[i][1]);
                        printf("  stok = %s\n",buku[i][2]);
                        printf("==============================================\n");
                    }
                    printf("0.kembali\n");
                    printf("1.masukan barang ke dalam keranjang\n");
                    printf("2.sorting\n");
                    scanf("%d",&input);
                    getchar();
                    if(input == 0){
                        goto menuBuku;
                    }
                    else if(input == 2){
                        for(int i = 0;i<jumlahBuku;i++){
                            for(int j = 0;j<jumlahBuku-1;j++){
                                int num = atoi(buku[j][1]);
                                int num1 = atoi(buku[j+1][1]);
                                if(num>num1){
                                    char bantuan[1000][5][100];
                                    for(int k = 0;k<jumlahBuku;k++){
                                        strcpy(bantuan[j][k],buku[j][k]);
                                        strcpy(buku[j][k],buku[j+1][k]);
                                        strcpy(buku[j+1][k],bantuan[j][k]);
                                    }
                                }
                            }
                        }
                        system("cls");
                        for(int i = 0;i<jumlahBuku;i++){
                            printf("%d.%s\n",i+1,buku[i][0]);
                            printf("  harga = %s\n",buku[i][1]);
                            printf("  stok = %s\n",buku[i][2]);
                            printf("==============================================\n");
                        }
                        printf("0.kembali\n");
                        printf("1.masukan barang ke dalam keranjang\n");
                        scanf("%d",&input);
                        getchar();
                        if(input == 0){
                            goto menuBuku;
                        }

                        //untuk masukin buku ke dalam keranjang dalam mode sorting
                        else if(input == 1){
                            int searchSession = 0;
                        char namaBarang[50];
                        system("cls");
                        printf("ketik barang yang ingin dimasukan ke dalam keranjang:");
                        fgets(namaBarang, sizeof(namaBarang), stdin);
                        namaBarang[strcspn(namaBarang, "\n")] = '\0';  //supaya bisa memasukan spasi dalam input
                        
                        //buat nyamain sama barang buku
                        for(int i = 0;i<jumlahBuku;i++){
                            if(strcmp(namaBarang,buku[i][0]) == 0){
                                searchSession = 1;

                                char namaFile[50];
                                sprintf(namaFile, "%s.txt", loginID);

                                file = fopen(namaFile, "a");

                                fprintf(file, "%s|%s|%s|%s|%s\n", buku[i][0],buku[i][1],buku[i][2],buku[i][3],buku[i][4]);

                                fclose(file);

                                system("cls");
                                printf("%s telah dimasukan ke dalam keranjang\n",buku[i][0]);
                                getch();
                                goto sessionBuku;
                            }
                        }
                        
                        if(searchSession == 0){
                        system("cls");
                        printf("%s tidak ditemukan\n",namaBarang);
                        getch();
                        goto sessionuser;
                        }
                        }
                    }

                    //untuk masukin buku keranjang dalam mode biasa
                    else if(input == 1){
                        int searchSession = 0;
                        char namaBarang[50];
                        system("cls");
                        printf("ketik barang yang ingin dimasukan ke dalam keranjang:");
                        fgets(namaBarang, sizeof(namaBarang), stdin);
                        namaBarang[strcspn(namaBarang, "\n")] = '\0';  //supaya bisa memasukan spasi dalam input
                        
                        //buat nyamain sama barang buku
                        for(int i = 0;i<jumlahBuku;i++){
                            if(strcmp(namaBarang,buku[i][0]) == 0){
                                searchSession = 1;

                                char namaFile[50];
                                sprintf(namaFile, "%s.txt", loginID);

                                file = fopen(namaFile, "a");

                                fprintf(file, "%s|%s|%s|%s|%s\n", buku[i][0],buku[i][1],buku[i][2],buku[i][3],buku[i][4]);

                                fclose(file);

                                system("cls");
                                printf("%s telah dimasukan ke dalam keranjang\n",buku[i][0]);
                                getch();
                                goto sessionBuku;
                            }
                        }
                        
                        if(searchSession == 0){
                        system("cls");
                        printf("%s tidak ditemukan\n",namaBarang);
                        getch();
                        goto sessionuser;
                        }
                    }
                }

                //menampilkan kategori fashion
                else if(input == 2){
                    sessionFashion:
                    system("cls");
                    for(int i = 0;i<jumlahFashion;i++){
                        printf("%d.%s\n",i+1,fashion[i][0]);
                        printf("  harga = %s\n",fashion[i][1]);
                        printf("  stok = %s\n",fashion[i][2]);
                        printf("==============================================\n");
                    }
                    printf("0.kembali\n");
                    printf("1.masukan barang ke dalam keranjang\n");
                    printf("2.sorting\n");
                    printf("==============================================\n");
                    scanf("%d",&input);
                    getchar();
                    if(input == 0){
                        goto menuBuku;
                    }

                    else if(input == 2){
                        for(int i = 0;i<jumlahFashion;i++){
                            for(int j = 0;j<jumlahFashion-1;j++){
                                int num = atoi(fashion[j][1]);
                                int num1 = atoi(fashion[j+1][1]);
                                if(num>num1){
                                    char bantuan[1000][5][100];
                                    for(int k = 0;k<jumlahFashion;k++){
                                        strcpy(bantuan[j][k],fashion[j][k]);
                                        strcpy(fashion[j][k],fashion[j+1][k]);
                                        strcpy(fashion[j+1][k],bantuan[j][k]);
                                    }

                                }
                            }
                        }
                        system("cls");
                        for(int i = 0;i<jumlahFashion;i++){
                            printf("%d.%s\n",i+1,fashion[i][0]);
                            printf("  harga = %s\n",fashion[i][1]);
                            printf("  stok = %s\n",fashion[i][2]);
                            printf("==============================================\n");
                        }
                        printf("0.kembali\n");
                        printf("1.masukan barang ke dalam keranjang\n");
                        printf("==============================================\n");
                        scanf("%d",&input);
                        getchar();
                        if(input == 0){
                            goto menuBuku;
                        }

                        //masukin barang fashion ke dalam keranjang dalam mode sorting
                        else if(input == 1){
                            int searchSession = 0;
                        char namaBarang[50];
                        system("cls");
                        printf("ketik barang yang ingin dimasukan ke dalam keranjang:");
                        fgets(namaBarang, sizeof(namaBarang), stdin);
                        namaBarang[strcspn(namaBarang, "\n")] = '\0';  //supaya bisa memasukan spasi dalam input
                        
                        for(int i = 0;i<jumlahFashion;i++){
                            if(strcmp(namaBarang,fashion[i][0]) == 0){
                                searchSession = 1;

                                char namaFile[50];
                                sprintf(namaFile, "%s.txt", loginID);

                                file = fopen(namaFile, "a");

                                fprintf(file, "%s|%s|%s|%s|%s\n", fashion[i][0],fashion[i][1],fashion[i][2],fashion[i][3],fashion[i][4]);

                                fclose(file);

                                system("cls");
                                printf("%s telah dimasukan ke dalam keranjang\n",fashion[i][0]);
                                getch();
                                goto sessionFashion;
                            }
                        }
                        
                        if(searchSession == 0){
                        system("cls");
                        printf("%s tidak ditemukan\n",namaBarang);
                        getch();
                        goto sessionuser;
                        }
                        }
                    }

                    //masukin barang fashion ke dalam keranjang dalam mode biasa
                    else if(input == 1){
                        int searchSession = 0;
                        char namaBarang[50];
                        system("cls");
                        printf("ketik barang yang ingin dimasukan ke dalam keranjang:");
                        fgets(namaBarang, sizeof(namaBarang), stdin);
                        namaBarang[strcspn(namaBarang, "\n")] = '\0';  //supaya bisa memasukan spasi dalam input
                        
                        for(int i = 0;i<jumlahFashion;i++){
                            if(strcmp(namaBarang,fashion[i][0]) == 0){
                                searchSession = 1;

                                char namaFile[50];
                                sprintf(namaFile, "%s.txt", loginID);

                                file = fopen(namaFile, "a");

                                fprintf(file, "%s|%s|%s|%s|%s\n", fashion[i][0],fashion[i][1],fashion[i][2],fashion[i][3],fashion[i][4]);

                                fclose(file);

                                system("cls");
                                printf("%s telah dimasukan ke dalam keranjang\n",fashion[i][0]);
                                getch();
                                goto sessionFashion;
                            }
                        }
                        
                        if(searchSession == 0){
                        system("cls");
                        printf("%s tidak ditemukan\n",namaBarang);
                        getch();
                        goto sessionuser;
                        }
                    }

                }
                //menampilkan kategori obat
                else if(input == 3){
                    sessionObat:
                    system("cls");
                    for(int i = 0;i<jumlahObat;i++){
                        printf("%d.%s\n",i+1,obat[i][0]);
                        printf("  harga = %s\n",obat[i][1]);
                        printf("  stok = %s\n",obat[i][2]);
                        printf("==============================================\n");
                    }
                    printf("0.kembali\n");
                    printf("1.masukan barang ke dalam keranjang\n");
                    printf("2.sorting\n");
                    printf("==============================================\n");
                    scanf("%d",&input);
                    getchar();
                    if(input == 0){
                        goto menuBuku;
                    }

                    else if(input == 2){
                        for(int i = 0;i<jumlahObat;i++){
                            for(int j = 0;j<jumlahObat-1;j++){
                                int num = atoi(obat[j][1]);
                                int num1 = atoi(obat[j+1][1]);
                                if(num>num1){
                                    char bantuan[1000][5][100];
                                    for(int k = 0;k<jumlahObat;k++){
                                        strcpy(bantuan[j][k],obat[j][k]);
                                        strcpy(obat[j][k],obat[j+1][k]);
                                        strcpy(obat[j+1][k],bantuan[j][k]);
                                    }

                                }
                            }
                        }
                        system("cls");
                        for(int i = 0;i<jumlahObat;i++){
                            printf("%d.%s\n",i+1,obat[i][0]);
                            printf("  harga = %s\n",obat[i][1]);
                            printf("  stok = %s\n",obat[i][2]);
                            printf("==============================================\n");
                        }
                        printf("0.kembali\n");
                        printf("1.masukan barang ke dalam keranjang\n");
                        printf("==============================================\n");
                        scanf("%d",&input);
                        getchar();
                        if(input == 0){
                            goto menuBuku;
                        }

                        //masukan barang obat ke dalam keranjang dalam mode sorting
                        else if(input == 1){
                            int searchSession = 0;
                            char namaBarang[50];
                            system("cls");
                            printf("ketik barang yang ingin dimasukan ke dalam keranjang:");
                            fgets(namaBarang, sizeof(namaBarang), stdin);
                            namaBarang[strcspn(namaBarang, "\n")] = '\0';  //supaya bisa memasukan spasi dalam input
                            
                            for(int i = 0;i<jumlahObat;i++){
                                if(strcmp(namaBarang,obat[i][0]) == 0){
                                    searchSession = 1;

                                    char namaFile[50];
                                    sprintf(namaFile, "%s.txt", loginID);

                                    file = fopen(namaFile, "a");

                                    fprintf(file, "%s|%s|%s|%s|%s\n", obat[i][0],obat[i][1],obat[i][2],obat[i][3],obat[i][4]);

                                    fclose(file);

                                    system("cls");
                                    printf("%s telah dimasukan ke dalam keranjang\n",obat[i][0]);
                                    getch();
                                    goto sessionObat;
                                }
                            }
                            
                            if(searchSession == 0){
                            system("cls");
                            printf("%s tidak ditemukan\n",namaBarang);
                            getch();
                            goto sessionuser;
                            }
                        }
                    }

                    //masukan barang ke obat ke dalam keranjang dalam mode biasa
                    else if(input == 1){
                        int searchSession = 0;
                        char namaBarang[50];
                        system("cls");
                        printf("ketik barang yang ingin dimasukan ke dalam keranjang:");
                        fgets(namaBarang, sizeof(namaBarang), stdin);
                        namaBarang[strcspn(namaBarang, "\n")] = '\0';  //supaya bisa memasukan spasi dalam input
                        
                        for(int i = 0;i<jumlahObat;i++){
                            if(strcmp(namaBarang,obat[i][0]) == 0){
                                searchSession = 1;

                                char namaFile[50];
                                sprintf(namaFile, "%s.txt", loginID);

                                file = fopen(namaFile, "a");

                                fprintf(file, "%s|%s|%s|%s|%s\n", obat[i][0],obat[i][1],obat[i][2],obat[i][3],obat[i][4]);

                                fclose(file);

                                system("cls");
                                printf("%s telah dimasukan ke dalam keranjang\n",obat[i][0]);
                                getch();
                                goto sessionObat;
                            }
                        }
                        
                        if(searchSession == 0){
                        system("cls");
                        printf("%s tidak ditemukan\n",namaBarang);
                        getch();
                        goto sessionuser;
                        }
                    }
                }
                //menampilkan kategori others
                else if(input == 4){
                    sessionOthers:
                    system("cls");
                    for(int i = 0;i<jumlahOthers;i++){
                        printf("%d.%s\n",i+1,others[i][0]);
                        printf("  harga = %s\n",others[i][1]);
                        printf("  stok = %s\n",others[i][2]);
                        printf("==============================================\n");
                    }
                    printf("0.kembali\n");
                    printf("1.masukan barang ke dalam keranjang\n");
                    printf("2.sorting\n");
                    printf("==============================================\n");
                    scanf("%d",&input);
                    getchar();
                    if(input == 0){
                        goto menuBuku;
                    }

                    else if(input == 2){
                        for(int i = 0;i<jumlahOthers;i++){
                            for(int j = 0;j<jumlahOthers-1;j++){
                                int num = atoi(others[j][1]);
                                int num1 = atoi(others[j+1][1]);
                                if(num>num1){
                                    char bantuan[1000][5][100];
                                    for(int k = 0;k<jumlahOthers;k++){
                                        strcpy(bantuan[j][k],others[j][k]);
                                        strcpy(others[j][k],others[j+1][k]);
                                        strcpy(others[j+1][k],bantuan[j][k]);
                                    }

                                }
                            }
                        }
                        system("cls");
                        for(int i = 0;i<jumlahOthers;i++){
                            printf("%d.%s\n",i+1,others[i][0]);
                            printf("  harga = %s\n",others[i][1]);
                            printf("  stok = %s\n",others[i][2]);
                            printf("==============================================\n");
                        }
                        printf("0.kembali\n");
                        printf("1.masukan barang ke dalam keranjang\n");
                        printf("2.sorting\n");
                        printf("==============================================\n");
                        scanf("%d",&input);
                        getchar();
                        if(input == 0){
                            goto menuBuku;
                        }

                        //masukan barang others ke dalam keranjang dalam mode sorting
                        else if(input == 1){
                            int searchSession = 0;
                            char namaBarang[50];
                            system("cls");
                            printf("ketik barang yang ingin dimasukan ke dalam keranjang:");
                            fgets(namaBarang, sizeof(namaBarang), stdin);
                            namaBarang[strcspn(namaBarang, "\n")] = '\0';  //supaya bisa memasukan spasi dalam input
                            
                            for(int i = 0;i<jumlahOthers;i++){
                                if(strcmp(namaBarang,others[i][0]) == 0){
                                    searchSession = 1;

                                    char namaFile[50];
                                    sprintf(namaFile, "%s.txt", loginID);

                                    file = fopen(namaFile, "a");

                                    fprintf(file, "%s|%s|%s|%s|%s\n", others[i][0],others[i][1],others[i][2],others[i][3],others[i][4]);

                                    fclose(file);

                                    system("cls");
                                    printf("%s telah dimasukan ke dalam keranjang\n",others[i][0]);
                                    getch();
                                    goto sessionOthers;
                                }
                            }
                            
                            if(searchSession == 0){
                            system("cls");
                            printf("%s tidak ditemukan\n",namaBarang);
                            getch();
                            goto sessionuser;
                            }
                        }
                    }

                    //masukan barang others ke dalam keranjang dalam mode biasa
                    else if(input == 1){
                        int searchSession = 0;
                        char namaBarang[50];
                        system("cls");
                        printf("ketik barang yang ingin dimasukan ke dalam keranjang:");
                        fgets(namaBarang, sizeof(namaBarang), stdin);
                        namaBarang[strcspn(namaBarang, "\n")] = '\0';  //supaya bisa memasukan spasi dalam input
                        
                        for(int i = 0;i<jumlahOthers;i++){
                            if(strcmp(namaBarang,others[i][0]) == 0){
                                searchSession = 1;

                                char namaFile[50];
                                sprintf(namaFile, "%s.txt", loginID);

                                file = fopen(namaFile, "a");

                                fprintf(file, "%s|%s|%s|%s|%s\n", others[i][0],others[i][1],others[i][2],others[i][3],others[i][4]);

                                fclose(file);

                                system("cls");
                                printf("%s telah dimasukan ke dalam keranjang\n",others[i][0]);
                                getch();
                                goto sessionOthers;
                            }
                        }
                        
                        if(searchSession == 0){
                        system("cls");
                        printf("%s tidak ditemukan\n",namaBarang);
                        getch();
                        goto sessionuser;
                        }
                    }
                }
            }
            
            else if(input == 0){
                goto menu;
            }


            //fitur untuk mengecek keranjang user
            else if(input == 4){
                char namaFile[50];
                sprintf(namaFile, "%s.txt", loginID);

                file = fopen(namaFile, "r");

                index = 0;
                for (int i = 0; i < 5; i++) {
                    for(int j = 0;j<1000;j++){
                        keranjang[j][i][0] = '\0'; // Setiap elemen jadi string kosong
                    }
                    
                }

                while(fgets(line, sizeof(line), file) != NULL){
                    line[strcspn(line,"\n")] = 0;

                    char *nama = strtok(line,"|");
                    char *harga = strtok(NULL,"|");
                    char *stok = strtok(NULL,"|");
                    char *berat = strtok(NULL,"|");
                    char *sold = strtok(NULL,"|");

                    strncpy(keranjang[index][0], nama, 50);
                    strncpy(keranjang[index][1], harga, 50);
                    strncpy(keranjang[index][2], stok, 50);
                    strncpy(keranjang[index][3], berat, 50);
                    strncpy(keranjang[index][4], sold, 100);
                    index++;
                }

                fclose(file);
                int jumlahKeranjang = menghitungBanyakData(keranjang);
                int total = 0;
                system("cls");
                printf("isi keranjang %s:\n",loginID);
                for(int i = 0;i<jumlahKeranjang;i++){
                    printf("%d.%s|harga:%s\n",i+1,keranjang[i][0],keranjang[i][1]);
                    total = total + atoi(keranjang[i][1]);
                }

                printf("================================================\n");
                printf("total harga dari keranjang anda = %d\n",total);
                
                printf("tekan tombol apa saja untuk kembali\n");
                getch();
                goto sessionuser;
            }

        }

        //salah memasukan password login
        else{
            system("cls");
            printf("password atau id salah\ntekan tombol apa saja untuk kembali\n");
            getch();
            goto menu;
            
        }
    }

    //login seller
    if(input == 2){
        system("cls");
        printf("login seller\n");
        printf("masukan id       :");
        scanf("%s",&loginID);
        printf("masukan password :");
        scanf("%s",&loginPW);


        for(int i = 0;i<1000;i++){
                
            if (strcmp(loginID,seller[i][0]) == 0 && strcmp(loginPW,seller[i][1]) == 0){
                sessionSeller = 1;
                 
            }
        }
        // AKSESES TOKO SELLER

        if(sessionSeller == 1){
            system("cls");
            printf("login berhasil\n");
            printf("tekan tombol apa saja untuk lanjut\n");
            getch();
            
            menuSeller:
            do{
                system("cls");
                printf("Selamat datang min %s\n",loginID);
                printf("0.logout\n");
                printf("1.Masukin Barang\n");
                printf("2.Update Stok\n");
                scanf("%d",&input);
            }while (input>2 || input<0);

            if(input == 0){
                goto menu;
            }

            //masukin barang
            else if(input == 1){
                system("cls");
                char namaBarang[50],hargaBarang[50],stokBarang[50],beratBarang[50],kategoriBarang[50];
                printf("Masukan kategori barang:\n");
                printf("buku|fashion|obat|others\n");

                fflush(stdin);//untuk membersihkan input karna sebelumnya menggunakan scanf
                
                fgets(kategoriBarang, sizeof(kategoriBarang), stdin);
                kategoriBarang[strcspn(kategoriBarang, "\n")] = '\0';

                printf("========================\n");
                printf("Masukin nama barang                   : ");
                fgets(namaBarang, sizeof(namaBarang), stdin);
                namaBarang[strcspn(namaBarang, "\n")] = '\0';  //supaya bisa memasukan spasi dalam input

                printf("Masukin harga barang                  : ");
                fgets(hargaBarang, sizeof(hargaBarang), stdin);
                hargaBarang[strcspn(hargaBarang, "\n")] = '\0'; 

                printf("Masukin stok barang                   : ");
                fgets(stokBarang, sizeof(stokBarang), stdin);
                stokBarang[strcspn(stokBarang, "\n")] = '\0'; 

                printf("Masukin berat barang(dalam satuan kg) : ");
                fgets(beratBarang, sizeof(beratBarang), stdin);
                beratBarang[strcspn(beratBarang, "\n")] = '\0'; 


                char namaFile[50];
                sprintf(namaFile,"%s.txt",kategoriBarang);

                file = fopen(namaFile,"a");

                fprintf(file, "\n%s|",namaBarang);
                fprintf(file, "%s|",hargaBarang);
                fprintf(file, "%s|",stokBarang);
                fprintf(file, "%s|",beratBarang);
                fprintf(file, "0");

                fclose(file);
                

                system("cls");
                printf("barang berhasil dimasukan\n");
                printf("tekan tombol apa saja untuk kembali");
                getch();
                goto menuSeller;
            }

            //update stok barang
            else if(input == 2){
                menuStok:
                do{
                    system("cls");
                    printf("update stok dari kategori apa?\n");
                    printf("1.buku\n");
                    printf("2.fashion\n");
                    printf("3.obat\n");
                    printf("4.others\n");
                    printf("5.back\n");
                    scanf("%d",&input);
                    getchar();
                }while (input>6 || input<0);

                //kembali ke menu
                if(input == 5){
                    goto menuSeller;
                }

                //menampilkan kategori buku
                else if(input == 1){
                    system("cls");
                    for(int i = 0;i<jumlahBuku;i++){
                        printf("%d.%s\n",i+1,buku[i][0]);
                        printf("  harga = %s\n",buku[i][1]);
                        printf("  stok = %s\n",buku[i][2]);
                        printf("==============================================\n");
                    }
                    printf("pilih barang yang stok nya ingin diperbarui\n");
                    printf("==============================================\n");
                    
                    for(int i = 0;i<jumlahBuku;i++){
                        printf("%s\n",buku[i][0]);
                    }
                    printf("==============================================\n");

                    
                    int sessionBuku = 0;
                    fgets(namaStok, sizeof(namaStok), stdin);
                    namaStok[strcspn(namaStok, "\n")] = '\0';  //supaya bisa memasukan spasi dalam input
                    
                    //buat nyamain sama barang buku
                    for(int i = 0;i<jumlahBuku;i++){
                        if(strcmp(namaStok,buku[i][0]) == 0){
                            sessionBuku = 1;
                            system("cls");
                            printf("Ingin mengubah stok %s menjadi berapa? :",buku[i][0]);
                            scanf("%s",&updateStok);
                            strcpy(buku[i][2],updateStok);
                            FILE *file = fopen("buku.txt","w");
                            for(int j = 0;j<jumlahBuku;j++){
                                if(j == jumlahBuku-1){
                                    fprintf(file,"%s|%s|%s|%s|%s",buku[j][0],buku[j][1],buku[j][2],buku[j][3],buku[j][4]);
                                }
                                else{
                                    fprintf(file,"%s|%s|%s|%s|%s\n",buku[j][0],buku[j][1],buku[j][2],buku[j][3],buku[j][4]);
                                }
                            }
                            fclose(file);
                            system("cls");
                            printf("stok %s berhasil diperbarui\n",buku[i][0]);
                            getch();
                            goto menuSeller;
                        }
                    }
                    if(sessionBuku == 0){
                        system("cls");
                        printf("barang %s tidak ditemukan",namaStok);
                        getch();
                        goto menuStok;
                    }

                    
                }

                //menampilkan kategori fashion
                else if(input == 2){
                    system("cls");
                    for(int i = 0;i<jumlahFashion;i++){
                        printf("%d.%s\n",i+1,fashion[i][0]);
                        printf("  harga = %s\n",fashion[i][1]);
                        printf("  stok = %s\n",fashion[i][2]);
                        printf("==============================================\n");
                    }
                    printf("pilih barang yang stok nya ingin diperbarui\n");
                    printf("==============================================\n");
                    
                    
                    for(int i = 0;i<jumlahFashion;i++){
                        printf("%s\n",fashion[i][0]);
                    }
                    printf("==============================================\n");
                    
                    int sessionfashion = 0;
                    fgets(namaStok, sizeof(namaStok), stdin);
                    namaStok[strcspn(namaStok, "\n")] = '\0';  //supaya bisa memasukan spasi dalam input
                    
                    //buat nyamain sama barang fashion
                    for(int i = 0;i<jumlahFashion;i++){
                        if(strcmp(namaStok,fashion[i][0]) == 0){
                            sessionfashion = 1;
                            system("cls");
                            printf("Ingin mengubah stok %s menjadi berapa? :",fashion[i][0]);
                            scanf("%s",&updateStok);
                            strcpy(fashion[i][2],updateStok);
                            FILE *file = fopen("fashion.txt","w");
                            for(int j = 0;j<jumlahFashion;j++){
                                if(j == jumlahFashion-1){
                                    fprintf(file,"%s|%s|%s|%s|%s",fashion[j][0],fashion[j][1],fashion[j][2],fashion[j][3],fashion[j][4]);
                                }
                                else{
                                    fprintf(file,"%s|%s|%s|%s|%s\n",fashion[j][0],fashion[j][1],fashion[j][2],fashion[j][3],fashion[j][4]);
                                }
                            }
                            fclose(file);
                            system("cls");
                            printf("stok %s berhasil diperbarui\n",fashion[i][0]);
                            getch();
                            goto menuSeller;
                        }
                    }
                    if(sessionfashion == 0){
                        system("cls");
                        printf("barang %s tidak ditemukan",namaStok);
                        getch();
                        goto menuStok;
                    }

                }
                //menampilkan kategori obat
                else if(input == 3){
                    system("cls");
                    for(int i = 0;i<jumlahObat;i++){
                        printf("%d.%s\n",i+1,obat[i][0]);
                        printf("  harga = %s\n",obat[i][1]);
                        printf("  stok = %s\n",obat[i][2]);
                        printf("==============================================\n");
                    }
                    printf("pilih barang yang stok nya ingin diperbarui\n");
                    printf("==============================================\n");
                    
                    
                    for(int i = 0;i<jumlahObat;i++){
                        printf("%s\n",obat[i][0]);
                    }
                    printf("==============================================\n");

                    int sessionobat = 0;
                    fgets(namaStok, sizeof(namaStok), stdin);
                    namaStok[strcspn(namaStok, "\n")] = '\0';  //supaya bisa memasukan spasi dalam input
                    
                    //buat nyamain sama barang obat
                    for(int i = 0;i<jumlahObat;i++){
                        if(strcmp(namaStok,obat[i][0]) == 0){
                            sessionobat = 1;
                            system("cls");
                            printf("Ingin mengubah stok %s menjadi berapa? :",obat[i][0]);
                            scanf("%s",&updateStok);
                            strcpy(obat[i][2],updateStok);
                            FILE *file = fopen("obat.txt","w");
                            for(int j = 0;j<jumlahObat;j++){
                                if(j == jumlahObat-1){
                                    fprintf(file,"%s|%s|%s|%s|%s",obat[j][0],obat[j][1],obat[j][2],obat[j][3],obat[j][4]);
                                }
                                else{
                                    fprintf(file,"%s|%s|%s|%s|%s\n",obat[j][0],obat[j][1],obat[j][2],obat[j][3],obat[j][4]);
                                }
                            }
                            fclose(file);
                            system("cls");
                            printf("stok %s berhasil diperbarui\n",obat[i][0]);
                            getch();
                            goto menuSeller;
                        }
                    }
                    if(sessionobat == 0){
                        system("cls");
                        printf("barang %s tidak ditemukan",namaStok);
                        getch();
                        goto menuStok;
                    }
                    
                }
                //menampilkan kategori others
                else if(input == 4){
                    system("cls");
                    for(int i = 0;i<jumlahOthers;i++){
                        printf("%d.%s\n",i+1,others[i][0]);
                        printf("  harga = %s\n",others[i][1]);
                        printf("  stok = %s\n",others[i][2]);
                        printf("==============================================\n");
                    }
                    printf("pilih barang yang stok nya ingin diperbarui\n");
                    printf("==============================================\n");
                    
                    
                    for(int i = 0;i<jumlahOthers;i++){
                        printf("%s\n",others[i][0]);
                    }
                    printf("==============================================\n");
                    
                    int sessionothers = 0;
                    fgets(namaStok, sizeof(namaStok), stdin);
                    namaStok[strcspn(namaStok, "\n")] = '\0';  //supaya bisa memasukan spasi dalam input
                    
                    //buat nyamain sama barang others
                    for(int i = 0;i<jumlahOthers;i++){
                        if(strcmp(namaStok,others[i][0]) == 0){
                            sessionothers = 1;
                            system("cls");
                            printf("Ingin mengubah stok %s menjadi berapa? :",others[i][0]);
                            scanf("%s",&updateStok);
                            strcpy(others[i][2],updateStok);
                            FILE *file = fopen("others.txt","w");
                            for(int j = 0;j<jumlahOthers;j++){
                                if(j == jumlahOthers-1){
                                    fprintf(file,"%s|%s|%s|%s|%s",others[j][0],others[j][1],others[j][2],others[j][3],others[j][4]);
                                }
                                else{
                                    fprintf(file,"%s|%s|%s|%s|%s\n",others[j][0],others[j][1],others[j][2],others[j][3],others[j][4]);
                                }
                            }
                            fclose(file);
                            system("cls");
                            printf("stok %s berhasil diperbarui\n",others[i][0]);
                            getch();
                            goto menuSeller;
                        }
                    }
                    if(sessionothers == 0){
                        system("cls");
                        printf("barang %s tidak ditemukan",namaStok);
                        getch();
                        goto menuStok;
                    }
                }
            }
            
        }
        //salah memasukan password seller
        else{
            system("cls");
            printf("password atau id salah\ntekan tombol apa saja untuk kembali\n");
            getch();
            goto menu;
            
        }
    }
    

    //register user
    if(input == 3){
      
        char registerID[25];
        char registerPW[25];
        int cekID = 0;
        system("cls");
        printf("Register Page User\n");
        printf("masukan id       :");
        scanf("%s",&registerID);
        printf("masukan password :");
        scanf("%s",&registerPW);

        for(int i = 0;i<1000;i++){
            int cekstr = strcmp(registerID,login[i][0]);
                
            if (strcmp(registerID,login[i][0]) == 0){
                cekID = 1;
                break;
            }
        }

        
        //cek id ga boleh sama
        if (cekID == 0){

            file = fopen("login.txt","a");

            fprintf(file, "\n%s|",registerID);
            fprintf(file, "%s",registerPW);

            fclose(file);

            printf("\nanda telah berhasil registrasi\n");
            printf("tekan tombol apa saja untuk kembali\n");
            getch();
            goto menu;
        }else{
            printf("\nRegistrasi Gagal, ID telah terpakai\n");
            printf("tekan tombol apa saja untuk kembali\n");
            getch();
            goto menu;
        }
        
        
        
    }


    //untuk keluar dari program
    if(input == 0){
        system("cls");
        printf("Terimakasih");
    }





    return 0;
}