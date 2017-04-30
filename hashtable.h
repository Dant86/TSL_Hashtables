#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "account.h"

typedef Account ValueType;

typedef struct entry {
	char* key;
	ValueType* value;
	struct entry* next;
} Entry;

typedef struct table {
	//Assume size = 100
	Entry** entries;
} Table;

//works
Table* hashtable_mkTable();

Entry* hashtable_entriesSet(const Table* t); 

//works
_Bool hashtable_contains(const Table* t, const char* key);

//works
int hashtable_hash(const char* key); 

//works
ValueType* hashtable_get(const Table* t, const char* key); 

//works
ValueType* hashtable_set(Table* t, const char* key, ValueType* value); 

int hashtable_size(const Table* t);

#endif
