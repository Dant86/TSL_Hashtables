#include <stdio.h>
#include <stdlib.h>
#include "account.h"
#include "tsl.h"
#include "hashtable.h"

int main(int argc, char* argv[]) {
	Table* t = hashtable_mkTable();
	Account* foo = mkAccount(55.55, "Vedant", 0);
	Account* bar = mkAccount(5555.55, "Hagedorn", 1);
	hashtable_set(t,foo -> name, foo);
	hashtable_set(t,bar -> name, bar);
	Entry* baz = hashtable_entriesSet(t);
	tsl_load(t, "out.txt");
}