#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
int authenticate(struct User *wallet, int pincode); //checks pincode for user and writes authenticated to 0 in struct User, returns 0 for success
int check_auth(struct User *wallet); //returns 0 for authenticated and 1 for not authenticated
#endif