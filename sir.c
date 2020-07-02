/************************ DESCRIPTION SECTION *************************/

/*
 * Unicamp Faculty of Technology - FT
 *
 * SI010 - Data Structures II - 1st Half 2020
 *
 * Developers:
 * 	Gustavo Adrien Polli	217357
 * 	Victor Gomes Sampaio	225133
 *
 * Description:
 * SIRmulator is a small command line epidemiological simulator
 * written in C based on the SIR (Susceptible, Infected and Recovered)
 * Model for analyzing the spread of an infectious disease.
 */
 
/************************* REFERENCES SECTION *************************/

/*
 * https://c-for-dummies.com/blog/?p=831
 * https://cboard.cprogramming.com/c-programming/51799-plot-graph-screen.html
 * https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html
 */
 

/************************* LIBRARIES SECTION **************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"


/************************* CODE CONVENTIONS ***************************/
/*
 * In function returns:
 * 1 - means success
 * 0 - means failure
 */

/************************* CONSTANTS ***************************/

#define SUSCEPTIBLE	0 // S status
#define INFECTED	1 // I status
#define RECOVERED	2 // R status
 
 
/************************** HEADERS SECTION ***************************/

void printHelp();
int getArg(char* string);
int updateStatus(SUBJECT **subject, int status);
void addRelationship(SUBJECT *s1, SUBJECT *s2);
int createGraph(SUBJECT *subjects, int n, int d);
int randomNumber(int until);
void verifyArgs(int argc, char* argv[]);
void runSimulation(SUBJECT *subjects, int x, int a, int t, int n);
int	isInfected(SUBJECT *subject);
int	isSusceptible(SUBJECT *subject);
int	isRecovered(SUBJECT *subject);
int	tryToInfectOthers(SUBJECT *subject, int a, SUBJECT *subjects, int iteration, int t);
int didInfectionOccur(int a);


/*********************** MAIN FUNCTION SECTION ************************/

int main(int argc, char* argv[]){
	verifyArgs(argc, argv);
	int n = getArg(argv[1]);
	int x = getArg(argv[2]);
	int a = getArg(argv[3]);

	if(a > 100){
		printf("Parameter \'a\' shouldn't be greater than 100");
	}
	
	int t = getArg(argv[4]);
	int d = getArg(argv[5]);
	SUBJECT subjects[n];
	subjectFactory(subjects, n, t);
	infectRandomSubject(subjects, n, t, 0);
	createGraph(subjects, n, d);


	runSimulation(subjects, x, a, t, n);

	printAll(subjects, sizeof(subjects)/sizeof(subjects[0]));
	return 0;
}


/************************* FUNCTIONS SECTION **************************/

void runSimulation(SUBJECT *subjects, int x, int a, int t, int n){
	for(int i = 0; i < x; i++){
		for(int k = 0; k < n; k++){
			if(isInfected(&subjects[k]) == 1){
				printf("Entrou aqui\n");
				tryToInfectOthers(&subjects[k], a, subjects, i, t);
				//TODO: Check if the infectionPeriod ended
			}
		}
	}
}

int	tryToInfectOthers(SUBJECT *subject, int a, SUBJECT *subjects, int iteration, int t){
	SUBJECT *aux;
	aux = subject;

	int infections = 0;

	if(aux->next == NULL){
		return infections;
	}

	while(aux->next != NULL){
		if(didInfectionOccur(a) == 1 && isSusceptible(subject)){
			infectSubject(subjects, aux->id, iteration, t);
			infections++;
			printf("\nInfectou\n");
		}
		aux = aux->next;
	}

	return infections;
}

int didInfectionOccur(int a){
	int res = randomNumber(100);

	if(res < a){
		return 1;
	}else{
		return 0;
	}
}

int	isInfected(SUBJECT *subject){
	if(subject->status == INFECTED){
		printf("\nstatus: %d\n", subject->status);
		return 1;
	}else{
		return 0;
	}
}

int	isSusceptible(SUBJECT *subject){
	if(subject->status == SUSCEPTIBLE){
		return 1;
	}else{
		return 0;
	}
}

int	isRecovered(SUBJECT *subject){
	if(subject->status == RECOVERED){
		return 1;
	}else{
		return 0;
	}
}

int createGraph(SUBJECT *subjects, int n, int d){
	if(n < d){
		printf("The number of subjects can't be smaller than the number of relations\n");
		exit(1);
	}
	for(int i = 0; i < n; i++){
		if(getNumberOfRelations(&subjects[i]) < d){
			for(int k = 0; k < d; k++){
				int randomIndex = randomNumber(n);
				addRelationship(&subjects[i], &subjects[randomIndex]);
			}
		}
	}
	return 0;
}

void addRelationship(SUBJECT *s1, SUBJECT *s2){
	insert(s1, s2);
	insert(s2, s1);
}

int updateStatus(SUBJECT **subject, int status){
  (*subject)->status = status;
  return 0;
}

int getArg(char* string){
	int stringLen = strlen(string); 
	char* substr[stringLen - 2];

	for(int i = 0; i < (stringLen - 2); i++){
		substr[i] = &string[i+2];
	}
	int arg = strtol(*substr, NULL, 10);
	return arg;
}

int randomNumber(int until){
	return rand() % until;
}

void verifyArgs(int argc, char* argv[]){
	if(argc < 6 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0){
		printHelp();
		exit(0);
	}
}

void printHelp(){
	printf("Example: \n");
	printf("	./sir n=100 x=1000 a=20 t=14 d=5 \n\n");
	printf("Params: \n");
	printf("n ------------- Number of subjects \n");
	printf("x ------------- Number of iterations \n");
	printf("a ------------- Infection probability per iteration \n");
	printf("t ------------- Time in an infected state \n");
	printf("d ------------- grade average of relations for each subject \n");
	printf("\n");
}
