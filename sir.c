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


/************************* CONSTANTS SECTION **************************/

#define SUSCEPTIBLE	0 // S status
#define INFECTED	1 // I status
#define RECOVERED	2 // R status


/************************* STRUCTURES SECTION *************************/

typedef struct Node{
	int status;
	int iniPeriod;
	int endPeriod;
	struct Node *next;
} NODEPTR;


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
/*
 * https://c-for-dummies.com/blog/?p=831
 * https://cboard.cprogramming.com/c-programming/51799-plot-graph-screen.html
 */
int plotCurve();


/*********************** MAIN FUNCTION SECTION ************************/

int main(int argc, char* argv[]){
	
	// needs to receive params via command line (argv)
	
	// code blocks here
	
	return 0; // system status
}


/************************* FUNCTIONS SECTION **************************/

// functions here
