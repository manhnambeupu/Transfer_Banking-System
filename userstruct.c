#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "userstruct.h"
#include "filehandler.h"
#include "common.h"
//returns 0 if wallet loaded, 1 if wallet not found
int load_wallet(struct User *wallet, int _wallet_id) {
    int wallet_id = 0;
    int pincode = 0;
    int balance = 0;
    int w_found = 1;
    char *name = malloc(BUFFER * sizeof(char));

    if(!check_File_Exists(FILENAME)) {
        printf("File does not exist.");
        exit(1);
    }
    FILE *fp = fopen(FILENAME, "r");
    //skip header line
    fscanf(fp, "%*[^\n]\n");
    while(fscanf(fp, "%d,%d,%d,%s", &wallet_id, &pincode, &balance, name) != EOF) {
        //printf("%d,%d,%d,%s\n", wallet_id, pincode, balance, name);
        if(wallet_id == _wallet_id) {
            //if found
            //printf("wallet_id == _wallet_id: %d\n", wallet_id);
            wallet->wallet_id = _wallet_id;
            wallet->pincode = pincode;
            wallet->balance = balance;
            strcpy(wallet->name, name);
            w_found = 0;
            break;
        }
    }

    fclose(fp);
    free(name);

    return w_found;
}
void save_wallet(struct User *wallet, int _wallet_id) {
    int wallet_id = 0;
    int pincode = 0;
    int balance = 0;
    char *name = malloc(BUFFER * sizeof(char));

    if(!check_File_Exists(FILENAME)) {
        printf("File does not exist.");
        exit(1);
    }

    FILE *fp_in = fopen(FILENAME, "r");
    FILE *fp_out = fopen(FILEBUFFER, "w");

    //skip header line
    fscanf(fp_in, "%*[^\n]\n");
    //add file header to new file
    fputs(" wallet_id, pincode, balance, name\n", fp_out);
    while(fscanf(fp_in, "%d,%d,%d,%s", &wallet_id, &pincode, &balance, name) != EOF) {
        if(wallet_id == _wallet_id) {
            //modify content
            //wallet->wallet_id = _wallet_id;
            pincode = wallet->pincode;
            balance = wallet->balance;

            strcpy(name,wallet->name);

            //write content
            fprintf(fp_out, "%d,%d,%d,%s\n", wallet_id, pincode, balance, name);
        } else {
            //copy content from file
            fprintf(fp_out, "%d,%d,%d,%s\n", wallet_id, pincode, balance, name);
        }
    }

    fclose(fp_in);
    fclose(fp_out);
    free(name);
    //writeback to csv
    remove(FILENAME);
    rename(FILEBUFFER, FILENAME);
}
