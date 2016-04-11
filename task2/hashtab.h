#ifndef HASHTAB_H
#define HASHTAB_H

typedef struct listnode
{
	
} ListNode;

unsigned int hashtab_hash(char *key);
void hashtab_init(ListNode **hashtab);
void hashtab_add(ListNode **hashtab, char *key, int value);
ListNode *hashtab_lookup(ListNode **hashtab, char *key);
void hashtab_delete(ListNode **hashtab, char *key);

#endif
 
