all: hash_1 hash_2 hash_6 bstree_1 bstree_2

clean: 
	rm -rf hash_1 hash_2 bstree_1 bstree_2 hash_6 bstree_5 ./hash/obj/* ./bstree/obj/*

hash_1: ./hash/obj/main.o ./hash/obj/hash.o
	gcc -o hash_1 ./hash/obj/main.o ./hash/obj/hash.o

hash_2: ./hash/obj/main_2.o ./hash/obj/hash.o
	gcc -o hash_2 ./hash/obj/main_2.o ./hash/obj/hash.o

bstree_1: ./bstree/obj/main.o ./bstree/obj/bstree.o
	gcc -o bstree_1 ./bstree/obj/main.o ./bstree/obj/bstree.o
	
bstree_2: ./bstree/obj/main_2.o ./bstree/obj/bstree.o
	gcc -o bstree_2 ./bstree/obj/main_2.o ./bstree/obj/bstree.o
	
hash_6: ./hash/obj/main_6.o ./hash/obj/hash.o
	gcc -o hash_6 ./hash/obj/main_6.o ./hash/obj/hash.o
	
./hash/obj/main.o: ./hash/src/main.c
	gcc -c -o ./hash/obj/main.o ./hash/src/main.c

./hash/obj/main_2.o: ./hash/src/main_2.c
	gcc -c -o ./hash/obj/main_2.o ./hash/src/main_2.c
	
./hash/obj/main_6.o: ./hash/src/main_6.c
	gcc -c -o ./hash/obj/main_6.o ./hash/src/main_6.c
	
./bstree/obj/main.o: ./bstree/src/main.c
	gcc -c -o ./bstree/obj/main.o ./bstree/src/main.c
	
./bstree/obj/main_2.o: ./bstree/src/main_2.c
	gcc -c -o ./bstree/obj/main_2.o ./bstree/src/main_2.c
	
./hash/obj/hash.o: ./hash/src/hash.c
	gcc -c -o ./hash/obj/hash.o ./hash/src/hash.c
	
./bstree/obj/bstree.o: ./bstree/src/bstree.c
	gcc -c -o ./bstree/obj/bstree.o ./bstree/src/bstree.c
