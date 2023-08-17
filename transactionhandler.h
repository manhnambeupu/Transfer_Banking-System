#ifndef TRANSACTIONHANDLER_H
#define TRANSACTIONHANDLER_H
int transfer_money(struct User *sender, struct User *receiver, int amount); //returns 0 for successful transaction
void print_wallet_user_info(struct User *wallet); //prints user info with printf()
int get_balance(struct User *wallet); //returns user balance as int (eg: 10,40€ = 1040)
#endif