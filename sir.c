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
#include "linkedList.h"

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
int getArg(char* string);

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

	SUBJECT subjects[n];
	subjectFactory(subjects, n);

	// printf("\nsizeof subjects: %d\n", sizeof(subjects)/sizeof(subjects[0]));

	infectOneSubject(subjects, n);

	/* Print all subjects to debug */
	for(int i = 0; i < n; i++){
		printf("\nstatus: %d\n", subjects[i].status);
	}

	return 0;
}

/************************* FUNCTIONS SECTION **************************/

int getArg(char* string){
	int stringLen = strlen(string); 
	char* substr[stringLen - 2];

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