#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "userstruct.h"
#include "transactionhandler.h"
#include "authentication.h"
#include "filehandler.h"
#include "asciiart.h"
#include "menu.h"

int main(void) {
    //struct User *main_wallet = (struct User *) malloc(sizeof(*main_wallet));

    initFile(); //temporary

    //temporary
    int authenticated = 1;
    struct User *ptest_wallet = (struct User *) malloc(sizeof(*ptest_wallet));

    ptest_wallet->wallet_id = 123;
    ptest_wallet->pincode = 1234;
    ptest_wallet->balance = 69420;
    strcpy(ptest_wallet->name, "Ein Name");  
    //tmp end

    if(authenticated != 0) {
        //TODO: Authentication
        load_menu_authenticate(ptest_wallet);
    } else {
        //TODO: Main Menu
        load_menu_main(ptest_wallet);
    }


    return 0;
}
