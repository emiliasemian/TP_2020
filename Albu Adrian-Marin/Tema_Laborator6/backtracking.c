#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>
#define SOLUTION_ARRAY_MAX_SIZE 10u
#define TRUE 1u
#define FALSE 0u
#define _no_PERMUTARI
#define _no_ARANJAMENTE
#define COMBINARI 
typedef unsigned char boolean;
unsigned char SolutionArray[SOLUTION_ARRAY_MAX_SIZE] = { 0 };
unsigned char n = 0u;
#ifndef PERMUTARI
unsigned char k = 0u; 
#endif

void Backtracking(int level);
boolean  IsValid(int level);
boolean  IsSolution(int level);
int  GetNextElement(int level);
void PrintSolution(int level);

#ifdef COMBINARI
boolean IsValid(int level) {
	boolean valid = TRUE;
	unsigned char ndx = 0;
	for (ndx = 0; ((ndx < level) && (valid == TRUE)); ndx++) {
		if (SolutionArray[ndx] == SolutionArray[level] || SolutionArray[ndx] > SolutionArray[level]) {
			valid = FALSE;
		}
	}
	return valid;
}
#else
boolean IsValid(int level) {
	boolean valid = TRUE;
	unsigned char ndx = 0;
	for (ndx = 0; ((ndx < level) && (valid == TRUE)); ndx++) {
		if (SolutionArray[ndx] == SolutionArray[level]) {
			valid = FALSE;
		}
	}
	return valid;
}
#endif
#ifdef PERMUTARI
/ solution permutari /
boolean IsSolution(int level) {
	boolean isSol = FALSE;
	if (level == (n - 1)) {
		isSol = TRUE;
	}
	return isSol;
}
#endif
#ifdef ARANJAMENTE
/ solution aranjamente /
boolean IsSolution(int level) {
	boolean isSol = FALSE;
	if (level == (k - 1)) {
		isSol = TRUE;
	}
	return isSol;
}
#endif
#ifdef COMBINARI
boolean IsSolution(int level) {
	boolean isSol = FALSE;
	if (level == (k - 1)) {
		isSol = TRUE;
	}
	return isSol;
}
#endif
void PrintSolution(int level) {
	unsigned char ndx;
	printf("\n");
	printf("solution: ");
	for (ndx = 0; ndx < level; ndx++) {
		const unsigned char noToPrint = SolutionArray[ndx] + 1u;
		printf(" %d ", noToPrint);
	}
	printf("\n");
}

int GetNextElement(int level) {
	return level;
}

void Backtracking(int level) {
	int index;
	for (index = 0; index < n; index++) {
		SolutionArray[level] = GetNextElement(index);
		if (TRUE == IsValid(level)) {
			if (TRUE == IsSolution(level)) {
				PrintSolution(level + 1);
			}
			else {
				Backtracking(level + 1);
			}
		}
		else {
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	printf("n= ");
	scanf("%hhd", &n);
#ifndef PERMUTARI
	printf("k= ");
	scanf("%hhd", &k);
#endif
	Backtracking(0);
	getchar();
	system("pause");
	return 0;
}