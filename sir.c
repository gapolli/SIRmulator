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


/************************* LIBRARIES SECTION **************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/************************* CONSTANTS SECTION **************************/

#define SUSCEPTIBLE	0 // S status
#define INFECTED	1 // I status
#define RECOVERED	2 // R status


/************************* STRUCTURES SECTION *************************/

typedef struct Subject{
	int status;
	int iniPeriod;
	int endPeriod;
	struct Node *next;
} SUBJECT;


/************************* CODE CONVENTIONS ***************************/

/*
 * In function returns:
 * 1 - means success
 * 0 - means failure
 */
 

/************************** HEADERS SECTION ***************************/

int initVector(int populationLimit);
int calculateGraphDegree(int* vector);
int connectIndividuals();
void iterate();
int verifyIndividualPeriod();
int changeIndividualStatus();
int saveInfected();
int plotCurve();

void printHelp();
SUBJECT** subjectFactory(int n);
int getArg(char* string);

  

/*
 * https://c-for-dummies.com/blog/?p=831
 * https://cboard.cprogramming.com/c-programming/51799-plot-graph-screen.html
 */
/*********************** MAIN FUNCTION SECTION ************************/

int main(int argc, char* argv[]){
	if(argc < 6 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0){
		printHelp();
		exit(0);
	}

	int n = getArg(argv[1]);
	int x = getArg(argv[2]);
	int a = getArg(argv[3]);
	int t = getArg(argv[4]);
	int d = getArg(argv[5]);

	printf("%d, %d, %d, %d, %d\n", n, x, a, t, d);

	// SUBJECT* subjects = subjectFactory(n);
	
	return 0;
}


/************************* FUNCTIONS SECTION **************************/

SUBJECT** subjectFactory(int n){
	SUBJECT* v[n];

	while(n > 0){
		SUBJECT *subject;
		subject->status = 0;
		subject->next = NULL;
		v[n] = subject;
		n--;
	}

	return v;
}

int getArg(char* string){
	int stringLen = strlen(string); //3
	char* substr[stringLen - 2]; // len = 1

	for(int i = 0; i < (stringLen - 2); i++){
		substr[i] = &string[i+2];
	}

	int arg = strtol(*substr, NULL, 10);

	return arg;
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