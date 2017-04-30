#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "account.h"

Account* mkAccount(float balance, char* name, _Bool trusted) {
	Account* a;
	if((a = malloc(sizeof(Account))) == NULL) {
		return NULL;
	}
	a -> balance = balance;
	a -> name = name;
	a -> trusted = trusted;
	return a;
}

Account* withdraw(Account* a, float amt) {
	float bal = a -> balance - amt;
	if(a -> trusted == false) {
		if(bal < 0) {
			printf("transaction failed for %s\n", a -> name);
		}
		else {
			a -> balance = bal;
		}
	}
	else {
		if(bal < -1000) {
			printf("transaction failed for %s\n", a -> name);
		}
		else {
			a -> balance = bal;
		}
	}
	return a;
}

Account* deposit(Account* a, float amt) {
	if(amt < 0) {
		printf("transaction failed for %s\n", a -> name);
		return a;
	}
	a -> balance += amt;
	return a;
}

void printAccount(Account* a) {
	if(a -> trusted == 0) {
		printf("%s:		$%.2f 	 (not trusted)\n",a -> name, a -> balance);
	}
	else {
		printf("%s:		$%.2f	 (trusted)\n",a -> name, a -> balance);
	}
}

