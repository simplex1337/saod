#include "hashtab.h"
#include <stdlib.h>
#include <stdio.h>

unsigned int hashtab_hash(char *key)
{
	unsigned int h = 0;
	char *p;
	for (p = key; *p != '\0'; p++) {
		h = h * HASHTAB_MUL + (unsigned int)*p;
	}
	return h % HASHTAB_SIZE;
}

void hashtab_init(struct listnode **hashtab)
{
	int i;
	for (i = 0; i < HASHTAB_SIZE; i++) {
		hashtab[i] = NULL;
	}
}

void hashtab_add(struct listnode **hashtab, char *key, int value)
{
	struct listnode *node;
	int index = hashtab_hash(key);
	// Вставка в начало списка
	node = malloc(sizeof(*node));
	if (node != NULL) {
		node->key = key;
		node->value = value;
		node->next = hashtab[index];
		hashtab[index] = node;
	}
}

struct listnode *hashtab_lookup(struct listnode **hashtab, char *key)
{
	int index;
	struct listnode *node;
	index = hashtab_hash(key);
	for (node = hashtab[index]; node != NULL; node = node->next) {
		if (strcmp(node->key, key) == 0)
		return node;
	}
	return NULL;
}

void hashtab_delete(struct listnode **hashtab, char *key)
{
	int index;
	struct listnode *p, *prev = NULL;
	index = hashtab_hash(key);
	for (p = hashtab[index]; p != NULL; p = p->next) {
		if (strcmp(p->key, key) == 0) {
			if (prev == NULL hashtab[index] = p->next;
		else
			prev->next = p->next;
		free(p);
		return;
		}
	prev = p;
	}
}

/*int main()
{
	struct listnode *node;
	hashtab_init(hashtab);
	hashtab_add(hashtab, "Tigr", 190);
	hashtab_add(hashtab, "Slon", 2300);
	hashtab_add(hashtab, "Volk", 60);
	node = hashtab_lookup(hashtab, "Slon");
	printf("Node: %s, %d\n", node->key, node->value);
	return 0;	
}
*/
