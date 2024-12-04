file = fopen(filename,"w");
                                        fprintf(file, "%d",saldo - totalAkhir);                                        
                                        printf("anda telah berhasil checkout barang anda\n");
                                        printf("\n+------------+------------+\n");
                                        printf("| sisa saldo | %-11d|\n",saldo-totalAkhir);
                                        printf("+------------+------------+\n\n");
                                        printf("untuk lebih detail silahkan cek pada menu status belanja\n");
                                        fclose(file);