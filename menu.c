#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "userstruct.h"
#include "menu.h"
#include "authentication.h"
#include "transactionhandler.h"
#include "asciiart.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

//Main Menu
void load_menu_main(struct User *wallet) {
    //clear terminal
    printf("\e[1;1H\e[2J");

    int choice = -1;
    printf("\n\n");
    printf("%s\n", ASCII_BANKING);
    printf("\n\n");
    printf("1) Benutzer Informationen ansehen\n");
    printf("2) Ueberweisung tätigen\n");
    printf("0) Verlassen\n");

    scanf("%d", &choice);
    fflush(stdin);

    switch (choice) {
    case 0:
        exit(0);
        break;
    case 1:
        load_menu_show_info(wallet);
        break;
    case 2:
        load_menu_transaction(wallet);
        break;

    default:
        load_menu_main(wallet);
        break;
    }
}

//wallet balance
void load_menu_show_info(struct User *wallet) {
    //clear terminal
    printf("\e[1;1H\e[2J");

    int cent = wallet->balance % 100;
    int euro = wallet->balance / 100;
    int choice = -1;

    printf("\n\n");
    printf("%s\n", ASCII_BANKING);
    printf("\n\n");
    printf("Ihr Kontostand betraegt: %d.%d Euro\n", euro, cent);
    printf("Name: %s\n", wallet->name);
    printf("Kontonummer: %d", wallet->wallet_id);
    printf("\n\n");
    printf("1) Hauptmenu\n");
    printf("0) Verlassen\n");

    scanf("%d", &choice);
    fflush(stdin);

    switch (choice) {
    case 0:
        exit(0);
        break;
    case 1:
        load_menu_main(wallet);
        break;
    default:
        break;
    }
}

void load_menu_authenticate(struct User *wallet) {
    //clear terminal
    printf("\e[1;1H\e[2J");

    int auth = -1;
    int wallet_nmb = 0;
    int pincode = 0;

    printf("\n\n");
    printf("%s\n", ASCII_BANKING);
    printf("\n\n");

    printf("Kontonummer: ");
    scanf("%d", &wallet_nmb);

    printf("Pincode:     ");
    scanf("%d", &pincode);
    fflush(stdin);

    //Load wallet from file
    int w_found = load_wallet(wallet, wallet_nmb);

    printf("w_found: %d\n", w_found);

    if(w_found != 0) {
        //printf("\n\nFalsche Kontonummer!\n");
        printf("\n\nFalsche Kontonummer oder falscher Pin!\n");
        exit(1);
    }

    auth = authenticate(wallet, pincode);

    if(auth != 0) {
        //printf("Falscher Pincode!");
        printf("\n\nFalsche Kontonummer oder falscher Pin!\n");
        exit(1);
    }

    wallet->authenticated = 0;

    load_menu_main(wallet);
}

void load_menu_transaction(struct User *wallet) {
    //clear Terminal
    printf("\e[1;1H\e[2J");

    int reicv_nmb = -1;
    struct User *reicv_wallet = (struct User *) malloc(sizeof(*reicv_wallet));
    int euro = 0;
    int cent = 0;
    int money = 0; //euro & cent
    int check=-1;
    printf("\n\n");
    printf("%s\n", ASCII_BANKING);
    printf("\n\n");

    printf("An wen moechten sie ueberweisen?\n");
    scanf("%d", &reicv_nmb);

    printf("Wie viel moechten sie ueberweisen [Euro.Cent]?");
    scanf("%d.%d", &euro, &cent);
    fflush(stdin);

    //Load wallet from file
    int w_found = load_wallet(reicv_wallet, reicv_nmb);

    if(w_found != 0) {
        printf("\n\nEmpfaenger nicht gefunden!\n");
        printf("\nENTER zum fortfahren!\n");
        while( getchar() != '\n' );
        while( getchar() != '\n' );
        fflush(stdin);
        load_menu_transaction(wallet);
    }

    money = (euro * 100) + cent;

    check_auth(wallet);

    int transaction =  transfer_money(wallet, reicv_wallet, money);

    if(transaction != 0) {
        printf("\n\nUberweisung fehlgeschlagen.\n");
        free(reicv_wallet);
        exit(1);
    }

    printf("\n\nUeberweisung war erfolgreich!\n\n");

    save_wallet(wallet, wallet->wallet_id);
    save_wallet(reicv_wallet, reicv_wallet->wallet_id);


    free(reicv_wallet);

    load_menu_main(wallet);
}
