#include <stdio.h>
#include <stdlib.h>
#include "account.h"
#include "tsl.h"
#include "hashtable.h"

bool tsl_save(const Table* t, const char* filename) {
	if(t == NULL || filename == NULL) {
		return 0;
	}
	FILE* f = fopen(filename, "w+");
	Entry* curr;
	for(int i = 0; i < 100; i++) { //Checks every bucket for k/v pairs
		curr = t -> entries[i]; //Resets traverse node to start of bucket
		while(curr != NULL && curr -> key != NULL && curr -> value != NULL) {
			Account* acc = curr -> value;
			fprintf(f,"%s %f %d\n", acc -> name, acc -> balance, acc -> trusted);
			curr = curr -> next;
		}
	}
	return 1;
}

void tsl_set(Table* t, char* name, float balance, bool trusted) {
	Account* foo = mkAccount(balance, name, trusted);
	hashtable_set(t, name, foo);
}

bool tsl_load(Table* t, const char* filename) {
	if(t == NULL || filename == NULL) {
		return 0;
	}
	FILE* file = fopen(filename, "r+");
	if(file == NULL) {
		return 0;
	}
	char* key;
	int trust;
	float bal;
	Account* a = NULL;
	int lineCounter = 0;
	while(!EOF) {
		fscanf(file, "%ms %f %d\n",&key,&bal,&trust);
		tsl_set(t,key,bal,trust);
		lineCounter++;
	}
	printf("%d\n", lineCounter);
	return 1;
}

void tsl_printTable(const Table* t) {
	Entry* curr;
	for(int i = 0; i < 100; i++) { //Checks every bucket for k/v pairs
		curr = t -> entries[i]; //Resets traverse node to start of bucket
		while(curr != NULL && curr -> key != NULL && curr -> value != NULL) {
			printAccount(curr -> value);
			curr = curr -> next;
		}
	}
}


