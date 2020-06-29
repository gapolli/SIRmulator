#ifndef LINKED_LIST
#define LINKED_LIST
/* ^^ these are the include guards */
typedef struct Subject{
	int status;
	int iniPeriod;
	int endPeriod;
	struct Node *next;
} SUBJECT;

void subjectFactory(SUBJECT *v, int n);
int initList(SUBJECT **start); /* Start an empty list */
int insertAtTheEnd(SUBJECT **start, int status); /* Receives a char and add it to the end of the list */
int print(SUBJECT *start); /* Print the list content to the stdout */
int empty(SUBJECT **start); /* Checks if the list is empty */
int clear(SUBJECT **start);
int getListLength(SUBJECT *start);

#endif