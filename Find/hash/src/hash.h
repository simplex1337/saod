#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASHTAB_SIZE 1001
#define HASHTAB_MUL 253

typedef struct listnode {
    char *key;
    int value;
    struct listnode *next;
} listnode;

struct listnode *hashtab_kp[HASHTAB_SIZE];
struct listnode *hashtab_xor[HASHTAB_SIZE];

unsigned int hashtab_hash(char *key);
unsigned int xor_hash(char *key);
void hashtab_init(struct listnode **hashtab);
void hashtab_add_kp(struct listnode **hashtab, char *key, int value);
void hashtab_add_xor(struct listnode **hashtab, char *key, int value);
struct listnode *hashtab_lookup(struct listnode **hashtab, char *key);
struct listnode *hashtab_lookup_xor(struct listnode **hashtab, char *key);
void hashtab_delete(struct listnode **hashtab, char *key);
