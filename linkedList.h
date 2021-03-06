#ifndef LINKED_LIST
#define LINKED_LIST
/* ^^ these are the include guards */

typedef struct Subject{
	int id;
	int status;
	int iniPeriod;
	int endPeriod;
	int relations;
	struct Subject *next;
} SUBJECT;

void subjectFactory(SUBJECT *v, int n, int t);
int infectRandomSubject(SUBJECT *v, int n, int t, int iteration);
int initList(SUBJECT **start); 
int insert(SUBJECT *subject, SUBJECT *subject2);
int print(SUBJECT *subject);
int printAll(SUBJECT *v, int length);
int getNumberOfRelations(SUBJECT *s);
int isRelationValid(SUBJECT *s, int id);
void infectSubject(SUBJECT *subjects, int id, int iteration, int infectionPeriod);
int recoverSubject(SUBJECT *subjects, int id, int iteration);

#endif
