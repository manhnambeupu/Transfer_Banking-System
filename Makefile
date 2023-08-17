all:
	gcc common.h asciiart.c userstruct.c menu.c filehandler.c authentication.c transactionhandler.c main.c -o banking
	.\banking
default: clean
	cp wallets.csv.default wallets.csv
	gcc common.h asciiart.c userstruct.c menu.c filehandler.c authentication.c transactionhandler.c main.c -o banking

debug:
	gcc -Wall common.h asciiart.c userstruct.c menu.c filehandler.c authentication.c transactionhandler.c main.c -o banking

mac: clean
	cp wallets.csv.default wallets.csv
	gcc common.h asciiart.c userstruct.c menu.c filehandler.c authentication.c transactionhandler.c main.c
	

clean:
	@echo "Cleaning..."
	rm -f banking wallets.csv *.txt
	