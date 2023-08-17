#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "userstruct.h"

//returns 1 if file exists and 0 if file not
int check_File_Exists(const char *fn) {
    FILE *fp;
    if ((fp = fopen(fn, "r")) != 0) {
        fclose(fp);
        return 1;
    } else {
        return 0;
    }
}

//CSV Header: wallet_id, pincode, balance, name
void initFile() {
    if(!(check_File_Exists(FILENAME))) {
        FILE *fp = fopen(FILENAME, "w");
        fputs("wallet_id, pincode, balance, name", fp);

        fclose(fp);
    }
}