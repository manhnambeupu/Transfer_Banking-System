#ifndef USERSTRUCT_H
#define USERSTRUCT_H
struct User {
    int wallet_id;
    char name[BUFFER];
    int pincode;
    int balance;
    int authenticated;
};

int load_wallet(struct User *wallet, int _wallet_id);
void save_wallet(struct User *wallet, int _wallet_id);
#endif