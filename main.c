#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
int input;
char loginID[25];
char loginPW[25];

char login[1000][2][25];
char seller[1000][2][25];

char buku[1000][3][50];
char obat[1000][3][50];
char fashion[1000][3][50];
char others[1000][3][50];


int main(){
    //tampilan menu awal
    menu:
    do{
        system("cls");
        printf("Selamat datang di toko kami\n");
        printf("1.login user\n");
        printf("2.login seller\n");
        printf("3.register user\n");
        printf("4.register seller\n");
        printf("5.keluar program\n");
        scanf("%d",&input);
    }while (input>5 || input<0);


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
                printf("1.cari barang\n");
                printf("2.lihat kategori\n");
                printf("3.logout\n");
                scanf("%d",&input);
            }while (input>3 || input<0);
            
            if(input == 1){
                printf("ketik barang yang ingin dicari:");
            }

            else if(input == 2){
                do{
                    system("cls");
                    printf("1.buku\n");
                    printf("2.fashion\n");
                    printf("4.obat\n");
                    printf("5.others\n");
                    printf("6.back\n");
                    scanf("%d",&input);
                }while (input>6 || input<0);

                //kembali ke menu
                if(input == 5){
                    goto sessionuser;
                }

                //menampilkan kategori buku
                else if(input == 1){

                }

                //menampilkan kategori fashion
                else if(input == 2){

                
                }
                //menampilkan kategori obat
                else if(input == 3){

                }
                //menampilkan kategori others
                else if(input == 4){

                }
            }
            
            else if(input == 3){
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
            system("cls");
            printf("Selamat datang %s",loginID);
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

    //register seller sama seperti cara bikin akun user
    if(input == 4){
      
        char registerID[25];
        char registerPW[25];
        int cekID = 0;
        system("cls");
        printf("Register Page Seller\n");
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

        
        //cek id seller juga tidak boleh sama dengan id seller lain
        if (cekID == 0){

            file = fopen("seller.txt","a");

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

    if(input == 5){
        system("cls");
        printf("Terimakasih");
    }





    return 0;
}