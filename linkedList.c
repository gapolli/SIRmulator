#include "linkedList.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


/************************* CONSTANTS SECTION **************************/

#define SUSCEPTIBLE	0 // S status
#define INFECTED	1 // I status
#define RECOVERED	2 // R status

/************************* FUNCTIONS SECTION **************************/

void subjectFactory(SUBJECT *v, int n){
	// SUBJECT* v[n];

	while(n > 0){
		SUBJECT *subject;
    initList(&subject);
	  subject = (SUBJECT *) malloc(sizeof(SUBJECT));
    subject->status = SUSCEPTIBLE;
		v[n-1] = *subject;
		n--;
	}
}

int infectOneSubject(SUBJECT *v, int n){
  int populationSize = n;
  int randomNumber = rand() % populationSize;
  v[randomNumber].status = INFECTED;
  return 1;
}

int initList(SUBJECT **start){
  SUBJECT *sub = NULL;
  return 0;
}

int insertAtTheEnd(SUBJECT **start, int status){
  return 0;
}

int print(SUBJECT *start){
  return 0;
}

int empty(SUBJECT **start){
  return 0;
}

int clear(SUBJECT **start){
  return 0;
}

int getListLength(SUBJECT *start){
  return 0;
}