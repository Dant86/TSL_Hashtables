#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

typedef struct account {
	_Bool trusted;
	float balance;
	char* name;
} Account;

Account* mkAccount(float balance, char* name, _Bool trusted);

Account* withdraw(Account* a, float amt);

Account* deposit(Account* a, float amt);

void printAccount(Account* a);

#endif