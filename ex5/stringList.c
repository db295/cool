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

    // When reaches 2 consecutive \0s - the StringList ends
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

    // Subtracts 2 last \0s
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
    const char *sourcePtr = source;
    char *targetPtr = target;
    int isSpace = 0;
    int countBufferSize = 0;

    // buffsize too small
    if (2 > buffSize) {
        return -1;
    }


    while ('\0' != *sourcePtr) {
        // In case buffer size is sufficient
        if (countBufferSize > buffSize) {
            break;
        }

        // In StringList, words are separated by one \0
        if (isspace(*sourcePtr)){
            *targetPtr = '\0';
            isSpace = 1;
        }
        else {
            // At start of string, don't put spaces
            if (targetPtr != target) {
                targetPtr += isSpace;
                countBufferSize += isSpace;
            }
            // Copy the char into target
            *targetPtr = *sourcePtr;
            // Increment the pointers towards the next char
            ++targetPtr;
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
    // End the target with 2 \0
    emptyStrList(targetPtr);
    return numStrsInList(target);
}


/*** Problem 1.5 ***/
char* createStrList(const char* str) {
    int strListLength = strlen(str) + 2;

    // Maximum space which might be needed
    char *p = malloc((strListLength) * sizeof(char));
    if (!p) {
        return NULL;
    }

    // Creates StringList from str
    strListFromWords(str, p, strListLength);

    // Adjusts space to fit exactly the size of the StringList
    p = realloc(p, (strListLen(p) + 2) * sizeof(char));
    if (!p) {
        return NULL;
    }

    return p;
}

/*** Problem 1.6 ***/
char* nextStrInList(char* stringList) {
    static char *lastListRead = NULL;
    static char* str = NULL;          // points at string to return

    if (stringList == NULL) {
        lastListRead = NULL;
        str = NULL;
        return NULL;
    }

    // Consecutive call to this function on the same StringList
    if (lastListRead == stringList) {
        // Checks if reached end of StringList
        if (!(*str)) {
            return NULL;
        }

        // Moves pointer to the next string
        str += strlen(str) + 1;
    } else {
        // New StringList. Resets pointers
        lastListRead = stringList;
        str = stringList;
    }

    // Checks if list is empty. If '\0' must be end of StringList (see 1.4)
    if (!(*str)) {
        return NULL;
    }

    return str;
}

/*** Problem 1.7 ***/
void printStrList(char* strList, char delim) {
    char *str;        // points at string to print

    // Resets nextStrInList
    nextStrInList(NULL);

    // Prints strings in StringList
    str = nextStrInList(strList);
    while (str) {
        printf("%s", str);
        str = nextStrInList(strList);
        if (str) {
            printf("%c", delim);
        }
    }
    printf("\n");
}

/*** end of stringList.c ***/