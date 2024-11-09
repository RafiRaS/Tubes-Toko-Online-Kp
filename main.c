#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
int input;
char loginID[25];
char loginPW[25];

char login[1000][2][25];
char seller[1000][2][25];


int main(){
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
            system("cls");
            printf("Selamat datang %s",loginID);
        }


        else{
            system("cls");
            printf("password salah\ntekan tombol apa saja untuk kembali\n");
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
        else{
            system("cls");
            printf("password salah\ntekan tombol apa saja untuk kembali\n");
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

        

        if (cekID == 0){
            FILE * file;

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

    //register seller
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

        

        if (cekID == 0){
            FILE * file;

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