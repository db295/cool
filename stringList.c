/*********************************************************
*  stringList.c                                          *
*  ~~~~~~~~~~~~                                          *
*  file implementing data structure and functions for    *
*  string list                                           *
*********************************************************/

/*** use only these C libraries ***/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>        // for isspace()
#include "stringList.h"   // header file contains all function declaration for StringList



/*********************************************************************************/
/**********    YOUR  SOLUTUON TO PROBLEM 1.1 - 1.7 UNDER HERE         ************/
/*********************************************************************************/


/*** Problem 1.1 ***/
int numStrsInList(const char* strList) {
	int strCounter = 0;
	int amountOfZeros = 0;
	const char *strIndex = strList;
	// In case strList is null - returns -1
	if (NULL == strList) {
		return -1;
	}
	// Goes through the str, searches for /0. Ends when there are 2 \0.
	while (2 > amountOfZeros) {
		// In case end of word
		if ('\0' == *strIndex)
		{
			++amountOfZeros;
		} else if (0 != amountOfZeros || strList == strIndex) {
			/*
			 When the amountOfZeros is not 0 - meaning it was 1, the last character was \0,
				or the beginning of the str.
			 */
			++strCounter;
			amountOfZeros = 0;
		}
		++strIndex;
	}
	return strCounter;
}

/*** Problem 1.2 ***/
int strListLen(const char* strList) {
	int amountOfZeros = 0;
	int charCount = 0;
	const char *strIndex = strList;
	// In case strList is null - returns -1
	if (NULL == strList) {
		return -1;
	}
	while (2 > amountOfZeros) {
		if ('\0' == *strIndex) {
			++amountOfZeros;
		}
		else {
			amountOfZeros = 0;
		}
		++strIndex;
		++charCount;
	}
	return charCount - 2;
}

/*** Problem 1.3 ***/
int emptyStrList(char* target) {
	// In case strList is null - returns -1
	if (NULL == target) {
		return -1;
	}
	*target = '\0';
	++target;
	*target = '\0';
	return 0;
}

/*** Problem 1.4 ***/
int strListFromWords(const char* source, char* target, int buffSize) {
	// TODO: when source NULL - should validate ?
	const char *sourcePtr = source;
	char *targerPtr = target;
	int isSpace = 0;
	int countBufferSize = 0;
	if (2 > buffSize) {
		return -1;
	}
	while ('\0' != *sourcePtr) {
		// In case buffer size is enough
		if (countBufferSize > buffSize) {
			break;
		}
		if (isspace(*sourcePtr)){
			*targerPtr = '\0';
			isSpace = 1;
		}
		else {
			// At start of string, dont put spaces
			if (targerPtr != target) {
				targerPtr += isSpace;
				countBufferSize += isSpace;
			}
			// Copy
			*targerPtr = *sourcePtr;
			++targerPtr;
			++countBufferSize;
			isSpace = 0;
		}
		++sourcePtr;
	}
	// Return when bufferSize isn't valid
	if (countBufferSize + 2 > buffSize) {
		emptyStrList(target);
		return 0;
	}
	emptyStrList(targerPtr);
	return numStrsInList(target);
}

/*** Problem 1.5 ***/
char* createStrList(const char* str) {
    return NULL; /* Not yet implemented  */
}

/*** Problem 1.6 ***/
char* nextStrInList(char* stringList) {
    return NULL; /* Not yet implemented  */
}

/*** Problem 1.7 ***/
void printStrList(char* strList, char delim) {
    return;     /* Not yet implemented  */
}

/*** end of stringList.c ***/
