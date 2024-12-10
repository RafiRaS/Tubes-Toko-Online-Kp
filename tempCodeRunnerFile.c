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