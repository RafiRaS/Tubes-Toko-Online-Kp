#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>


int main() {
    int input;
    int validasi;
    do{
    validasi = scanf("%d", &input);
    getchar(); 

    if (validasi != 1) {
    input = 10; 
    }
    }while(input>2||input<0);



    return 0;
}
