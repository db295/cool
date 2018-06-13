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
	// Get the size that is needed for the copy
	int size = strListLen(str) + 2;
	char *newStr = malloc(size * sizeof(char));
	if (NULL == newStr) {
		return NULL;
	}
	// use StrListFromWords to copy the list into the new allocated mem
	strListFromWords(str, newStr, size);
	return newStr;
}

/*** Problem 1.6 ***/
char* nextStrInList(char* stringList) {
	static char *lastWord = NULL;
	static char *lastCallWordList = NULL;

	if (NULL == stringList) {
		lastWord = NULL;
		lastCallWordList = NULL;
		return NULL;
	}
	if (NULL == lastCallWordList || lastCallWordList != stringList) {
		lastCallWordList = stringList;
		lastWord = stringList;
		// Return a pointer to the first word in the list
		// TODO: in case empty, this should return NULL
		return stringList;
	}
	else {
		// In case already at the end of the word
		if ('\0' == *lastWord) {
			return NULL;
		}
		// String in the list followed the last string
		while ('\0' != *lastWord) {
			lastWord++;
		}
		++lastWord;
		// 2 times \0 - means the end of the list.
		if ('\0' == *lastWord) {
			// If the end of the list - return NULL
			return NULL;
		}
		return lastWord;
	}
	
}

/*** Problem 1.7 ***/
void printStrList(char* strList, char delim) {
	char* currentWord;
	nextStrInList(NULL);
	currentWord = nextStrInList(strList);
	while (NULL != currentWord || '\0' != currentWord) {
		printf("%s", currentWord);
		currentWord = nextStrInList(strList);
		if (NULL != currentWord) {
			printf("%c", delim);
		}
	}
	printf("\n");
}

/*** end of stringList.c ***/
