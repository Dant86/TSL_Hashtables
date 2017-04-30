tsl: main.o tsl.o hashtable.o account.o
	gcc -o tsl main.o tsl.o hashtable.o account.o

main.o: main.c tsl.h account.h hashtable.h
	gcc -c main.c

tsl.o: tsl.c tsl.h account.h hashtable.h
	gcc -c tsl.c

hashtable.o: hashtable.c hashtable.h account.h
	gcc -c hashtable.c

account.o: account.c account.h
	gcc -c account.c