#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "account.h"
#include "hashtable.h"

//works
bool tsl_save(const Table* t, const char* filename);

bool tsl_load(Table* t, const char* filename);

void tsl_printTable(const Table* t);

void tsl_set(Table* t, char* name, float balance, bool trusted);