#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
int input;
char loginID[25];
char loginPW[25];

char login[20][2][25];

FILE * file;
int main(){

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
    
    menu:
    do{
        system("cls");
        printf("Selamat datang di toko kami\n");
        printf("1.login\n");
        printf("2.register\n");
        scanf("%d",&input);
    }while (input>2 || input<0);

    if(input == 1){
        system("cls");
        printf("Login Page\n");
        printf("masukan id       :");
        scanf("%s",&loginID);
        printf("masukan password :");
        scanf("%s",&loginPW);


        for(int i = 0;i<20;i++){
                
            if (strcmp(loginID,login[i][0]) == 0 && strcmp(loginPW,login[i][1]) == 0){
                session = 1;
                 
            }
        }

        if(session == 1){
            system("cls");
            printf("login berhasil");
        }
        else{
            system("cls");
            printf("password salah\ntekan tombol apa saja untuk kembali\n");
            getch();
            goto menu;
            
        }
    }

    if(input == 2){
        
        char registerID[25];
        char registerPW[25];
        system("cls");
        printf("Register Page\n");
        printf("masukan id       :");
        scanf("%s",&registerID);
        printf("masukan password :");
        scanf("%s",&registerPW);

        FILE * file;

        file = fopen("login.txt","w");
        fprintf(file, "\n%s|",registerID);
        fprintf(file, "%s",registerPW);

        fclose(file);
        printf("anda telah berhasil registrasi\n");
        printf("tekan tombol apa saja untuk kembali\n");
        getch();
        goto menu;
    }


   
    
   

    



    return 0;
}