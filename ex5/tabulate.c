/*********************************************************
*  tabulate.c                                            *
*  ~~~~~~~~~~                                            *
*  file implementing program for taking a file named     *
*  and turning it into a comma-delimeter table in        *
*  outFile.                                              *
*********************************************************/

/*** use only these C libraries ***/
#include <stdio.h>
#include <stdlib.h>
#include "stringList.h"   // header file contains all function declaration for StringList

#define INFILE        "inFile.txt"
#define DELIM         ','
#define MAX_LINE_LEN  500


/*********************************************************************************/
/**********         YOUR  SOLUTUON TO PROBLEM 2 UNDER HERE            ************/
/*********************************************************************************/

int main() {
    char line[MAX_LINE_LEN + 1];
    FILE *inFile;

    inFile = fopen(INFILE, "r");
    if (!inFile) {
        fprintf(stderr, "File %s cannot be opened\n", INFILE);
        return 1;
    }

    // Reads file, one line at a time, creates a StringList and processes it
    while (fgets(line, MAX_LINE_LEN, inFile)) {
        char *strList = createStrList(line);
        if (!strList) {
            fprintf(stderr, "Out of memory\n");
            fclose(inFile);
            return 2;
        }

        // Processes StringList
        printStrList(strList, DELIM);

        // Frees up allocated memory
        free(strList);
    }

    // Cleans up
    fclose(inFile);

    return 0;
}

/*** end of stringList.c ***/
