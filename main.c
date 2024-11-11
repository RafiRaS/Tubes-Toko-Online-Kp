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

char buku[1000][5][50];
char obat[1000][5][50];
char fashion[1000][5][50];
char others[1000][5][50];

//fungsi untuk menghitung banyak data dalam array
int menghitungBanyakData(char arr[1000][5][50]) {
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
        printf("1.login user\n");
        printf("2.login seller\n");
        printf("3.register user\n");
        printf("4.keluar program\n");
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

        strncpy(buku[index][0], nama, 50);
        strncpy(buku[index][1], harga, 50);
        strncpy(buku[index][2], stok, 50);
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

        strncpy(fashion[index][0], nama, 50);
        strncpy(fashion[index][1], harga, 50);
        strncpy(fashion[index][2], stok, 50);
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

        strncpy(obat[index][0], nama, 50);
        strncpy(obat[index][1], harga, 50);
        strncpy(obat[index][2], stok, 50);
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

        strncpy(others[index][0], nama, 50);
        strncpy(others[index][1], harga, 50);
        strncpy(others[index][2], stok, 50);
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
                scanf("%d",&input);
                getchar();
            }while (input>3 || input<0);
            
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
                    printf("ketik angka jika ingin memasukan barang ke dalam keranjang\n");
                    printf("==============================================\n");
                    printf("0.kembali\n");
                    for(int i = 0;i<jumlahBuku;i++){
                        printf("%d.%s\n",i+1,buku[i][0]);
                    }
                    printf("==============================================\n");
                    scanf("%d",&input);
                    if(input == 0){
                        goto menuBuku;
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
                    printf("ketik angka jika ingin memasukan barang ke dalam keranjang\n");
                    printf("==============================================\n");
                    printf("0.kembali\n");
                    
                    for(int i = 0;i<jumlahFashion;i++){
                        printf("%d.%s\n",i+1,fashion[i][0]);
                    }
                    printf("==============================================\n");
                    scanf("%d",&input);
                    if(input == 0){
                        goto menuBuku;
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
                    printf("ketik angka jika ingin memasukan barang ke dalam keranjang\n");
                    printf("==============================================\n");
                    printf("0.kembali\n");
                    
                    for(int i = 0;i<jumlahObat;i++){
                        printf("%d.%s\n",i+1,obat[i][0]);
                    }
                    printf("==============================================\n");
                    scanf("%d",&input);
                    if(input == 0){
                        goto menuBuku;
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
                    printf("ketik angka jika ingin memasukan barang ke dalam keranjang\n");
                    printf("==============================================\n");
                    printf("0.kembali\n");
                    
                    for(int i = 0;i<jumlahOthers;i++){
                        printf("%d.%s\n",i+1,others[i][0]);
                    }
                    printf("==============================================\n");
                    scanf("%d",&input);
                    if(input == 0){
                        goto menuBuku;
                    }
                }
            }
            
            else if(input == 0){
                goto menu;
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
            if(input == 1){
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
            if(input == 2){

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
    if(input == 4){
        system("cls");
        printf("Terimakasih");
    }





    return 0;
}