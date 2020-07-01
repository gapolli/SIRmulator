#include "linkedList.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


/************************* CONSTANTS SECTION **************************/

#define SUSCEPTIBLE	0 // S status
#define INFECTED	1 // I status
#define RECOVERED	2 // R status

/************************* FUNCTIONS SECTION **************************/

void subjectFactory(SUBJECT *v, int n, int t){
	for(int i = 0; i < n; i++){
		SUBJECT *subject;
    initList(&subject);
	  subject = (SUBJECT *) malloc(sizeof(SUBJECT));

    subject->id = i;
    subject->status = SUSCEPTIBLE;
    subject->iniPeriod = 0;
    subject->endPeriod = 0;
    subject->next = NULL;
    
    v[i] = *subject;
	}
}

int infectOneSubject(SUBJECT *v, int n, int t, int iteration){
  int populationSize = n;
  int randomNumber = rand() % populationSize;
  v[randomNumber].status = INFECTED;
  v[randomNumber].iniPeriod = iteration;
  v[randomNumber].endPeriod = iteration + t;
  return 1;
}

int initList(SUBJECT **subject){
  *subject = NULL;
  return 0;
}

int print(SUBJECT *subject){
  printf("\nid: %d\n", subject->id);
  printf("\nstatus: %d\n", subject->status);
  printf("\ninicio do periodo de infecção (iteração): %d\n", subject->iniPeriod);
  printf("\nfim do periodo de infecção (iteração): %d\n", subject->endPeriod);
  while(subject->next != NULL){
    printf("\nnext id: %d\n", (subject->next)->id);
    subject = subject->next;
  }
  return 0;
}

int printAll(SUBJECT *v, int length) {
  for(int i = 0; i < length; i++){
		print(&v[i]);
		printf("\n<---------------------------->\n");
	}

  return 0;
}

int insert(SUBJECT *subject, SUBJECT *subject2){
  SUBJECT *newSubject;
	newSubject = (SUBJECT *) malloc(sizeof(SUBJECT));
	newSubject->id = subject->id;
	newSubject->status = subject->status;
	newSubject->iniPeriod = subject->iniPeriod;
	newSubject->endPeriod = subject->endPeriod;
	newSubject->next = NULL;
  
  if(subject2->next == NULL){
    subject2->next = newSubject;
  }else{
    while(subject2->next != NULL){
      subject2 = subject2->next;
    }
    subject2->next = newSubject;
  }

  return 0;
}