 #include <stdio.h>
 #include "common.h"
 #include "userstruct.h"

 int transfer_money(struct User *sender, struct User *receiver, int amount) {

	// gebühren ca. 1€
	int trans_price = 100;

	// überprüfen ob genug  guthaben
	if ((amount + trans_price) >= sender->balance) {
		// fehlermeldung bei nicht genug Guthaben
		printf("Sie haben für die Transaktion nicht genug Guthaben zur Verfügung. Die Transaktion wird abgebrochen!\n");
		return 1;

	} else if(amount <0) {
		printf("Der Überweisungsbetrag ist Ungültig. Die Transaktion wird abgebrochen!\n");
		return 1;

	} else {
		sender->balance -= amount + trans_price;
		printf("Der Überweisungsbetrag beträgt %d zus. %d Gebühr\n", amount, trans_price);
		receiver->balance += amount;
		printf("Überweisung erfolgreich!\n");
		printf("Ihr aktuelles Guthaben beträgt %d\n", sender->balance);
	}
     return 0;
 }
