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
		subject->relations = 0;
		subject->next = NULL;    
		v[i] = *subject;
	}
}

int infectRandomSubject(SUBJECT *v, int n, int t, int iteration){
	int populationSize = n;
	int randomNumber = rand() % populationSize;
	v[randomNumber].status = INFECTED;
	v[randomNumber].iniPeriod = iteration;
	v[randomNumber].endPeriod = iteration + t;
	return 1;
}

void infectSubject(SUBJECT *subjects, int id, int iteration, int infectionPeriod){
  subjects[id].status = INFECTED;
  subjects[id].iniPeriod = iteration;
  subjects[id].endPeriod = iteration + infectionPeriod;
}

int recoverSubject(SUBJECT *subjects, int id, int iteration){
  if(subjects[id].endPeriod < iteration){
    subjects[id].status = RECOVERED;
    return 1;
  }

  return 0;
}


int initList(SUBJECT **subject){
	*subject = NULL;
	return 0;
}

int print(SUBJECT *subject){  
  printf("\n");
  printf("status: %d\n", subject->status);
  printf("inicio do periodo de infecção (iteração): %d\n", subject->iniPeriod);
  printf("fim do periodo de infecção (iteração): %d\n", subject->endPeriod);
  printf("\n");
  printf("\n %d ->", subject->id);
  while(subject->next != NULL){
    printf(" %d ->", (subject->next)->id);
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
  if(isRelationValid(subject, subject2->id) == 1){
    return 1;
  }

  SUBJECT *newSubject;
	newSubject = (SUBJECT *) malloc(sizeof(SUBJECT));
	newSubject->id = subject->id;
	newSubject->status = subject->status;
	newSubject->iniPeriod = subject->iniPeriod;
	newSubject->endPeriod = subject->endPeriod;
	newSubject->next = NULL;
  
  subject2->relations = (subject2->relations + 1);
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

int getNumberOfRelations(SUBJECT *s){
  SUBJECT *aux;
  aux = s;
  int res = 0;
  if(s->next == NULL)
    return 0;

  while(aux->next != NULL){
    res++;
    aux = aux->next;
  }
  return res;
}

int isRelationValid(SUBJECT *s, int id){
  SUBJECT *aux;
  aux = s;

  if(aux->next == NULL && aux->id != id){
    return 0;
  }

  while(aux->next != NULL){
    if(aux->id == id)
      return 1;

    aux = aux->next;
  }

  return 0;
}