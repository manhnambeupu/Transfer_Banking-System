#include <stdio.h>
#include "common.h"
#include "userstruct.h"
int authenticate(struct User *wallet,int pincode){
    int authenticated;
    if(pincode == wallet->pincode){
        authenticated=0; //then load menu main
    }
    else{
        return 1;
    }

    return 0;
}
int check_auth(struct User *wallet){
    int spincode;
    printf("Bitte dein code, um Überweisung zu bestättigen ");
    scanf("%d",&spincode);
    if(spincode == wallet->pincode){
       return 0;
    }
    else{
        printf("falsche Pincode\n");
        return check_auth(wallet);
    }
    return 0;
}
