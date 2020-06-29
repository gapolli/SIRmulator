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
int infectOneSubject(SUBJECT *v, int n);
int initList(SUBJECT **start); 
int insertAtTheEnd(SUBJECT **start, int status); 
int print(SUBJECT *start); 
int empty(SUBJECT **start);
int clear(SUBJECT **start);
int getListLength(SUBJECT *start);

#endif