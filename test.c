#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
intmain(){
    char registerID,registerPW;
        system("cls");
        printf("masukan id       :");
        scanf("%s",&registerID);
        printf("masukan password :");
        scanf("%s",&registerPW);

        FILE * file;

        fopen("login.txt","w");
        fprintf("\n%s|",registerID);
        fprintf("%s",registerPW);

        fclose(file);

        
        return 0;
}
