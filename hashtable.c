#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "account.h"
#include "hashtable.h"

Entry* entry_cons(char* key, ValueType* value) {
	if(key == NULL) {
		return NULL;
	}
	if(value == NULL) {
		return NULL;
	}
	Entry* new_entry = malloc(sizeof(Entry));
	new_entry -> key = key;
	new_entry -> value = value;
	new_entry -> next = NULL;
	return new_entry;
}

Table* hashtable_mkTable() {
	Table* hashtable;
	//If prgm fails to allocate memory for hashtable
	if((hashtable = malloc(sizeof(Table))) == NULL) {
		return NULL;
	}
	//If prgm fails to allocate memory for array within hashtable
	if((hashtable -> entries = malloc(sizeof(Entry)*100)) == NULL) {
		return NULL;
	}
	//Init all buckets to null
	for(int i = 0; i < 100; i++) {
		hashtable -> entries[i] = NULL;
	}
	return hashtable;
}

int hashtable_hash(const char* key) {
	char* str = strdup(key);
	int len = strlen(str);
	unsigned long res = 17;
	for(int i = 0; i < len; i++) {
		res = (37*res)+(int)str[i];
	}
	return (res % 100);
}

ValueType* hashtable_set(Table* t, const char* key, ValueType* value) {
	Entry* newpair = NULL;
	Entry* temp = NULL;
	Entry* prev = NULL;
	int bucket = hashtable_hash(strdup(key));

	temp = t -> entries[bucket];

	while(temp != NULL && temp->key != NULL && strcmp(strdup(key), temp->key) > 0) {
		prev = temp;
		temp = temp->next;
	}

	/* There's already a pair.  Let's replace that string. */
	if(temp != NULL && temp->key != NULL && strcmp(strdup(key), temp->key) == 0) {
		ValueType* val = temp -> value;
		free(temp->value);
		temp->value = value;
		return val;

	/* Nope, could't find it.  Time to grow a pair. */
	}
	else {
		newpair = entry_cons(strdup(key),value);

		/* We're at the start of the linked list in this bin. */
		if(temp == t -> entries[bucket]) {
			newpair -> next = temp;
			t -> entries[bucket] = newpair;
		/* We're at the end of the linked list in this bin. */
		}
		else if (temp == NULL) {
			prev->next = newpair;
		/* We're in the middle of the list. */
		}
		else  {
			newpair->next = temp;
			prev->next = newpair;
		}
	}
	return NULL;
}

_Bool hashtable_contains(const Table* t, const char* key) {
	char* dupKey = strdup(key);
	Entry* newpair = NULL;
	Entry* temp = NULL;
	Entry* prev = NULL;
	int bucket = hashtable_hash(strdup(key));

	temp = t -> entries[bucket];

	while(temp != NULL && temp->key != NULL && strcmp(strdup(key), temp->key) > 0) {
		prev = temp;
		temp = temp -> next;
	}

	if(temp != NULL && temp->key != NULL && strcmp(strdup(key), temp->key) == 0) {
		return true;
	}
	return false;
}

ValueType* hashtable_get(const Table* t, const char* key) {
	if(!hashtable_contains(t,strdup(key))) {
		return NULL;
	}
	Entry* temp = NULL;
	Entry* prev = NULL;
	int bucket = hashtable_hash(strdup(key));

	temp = t -> entries[bucket];

	while(temp != NULL && temp->key != NULL && strcmp(strdup(key), temp->key) > 0) {
		prev = temp;
		temp = temp -> next;
	}

	if(temp != NULL && temp->key != NULL && strcmp(strdup(key), temp->key) == 0) {
		return temp -> value;
	}
	return NULL;
}

Entry* hashtable_entriesSet(const Table* t) {
	Entry* temp;
	Entry* front;
	Entry* new;
	Entry* curr;
	for(int i = 0; i < 100; i++) { //Checks every bucket for k/v pairs
		curr = t -> entries[i]; //Resets traverse node to start of bucket
		while(curr != NULL && curr -> key != NULL && curr -> value != NULL) {
			printf("%d\n",i);
			printAccount(curr -> value);
			temp = entry_cons(curr -> key, curr -> value);
			if(front == NULL) {
				front = temp;
				new = temp;
			}
			new -> next = temp;
			new = new -> next;
			curr = curr -> next;
		}
	}
	return front;
}

int hashtable_size(const Table* t) {
	int size = 0;
	Entry* curr;
	for(int i = 0; i < 100; i++) { //Checks every bucket for k/v pairs
		curr = t -> entries[i]; //Resets traverse node to start of bucket
		while(curr != NULL && curr -> key != NULL && curr -> value != NULL) {
			curr = curr -> next;
			size++;
		}
	}
	return size;
}


