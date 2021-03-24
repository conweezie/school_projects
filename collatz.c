/***********************************************
Author: <Mitchell Conway>
Date: <03/18/2021>
Purpose: <Insert the purpose of the program here>
Sources of Help: <Please list any sources that you used for help
(tutors, web sites, lab TAs, etc.)>
Time Spent: <4 hours>
***********************************************/


/*
 Computing I -- COMP.1010 Honor Statement

 The practice of good ethical behavior is essential for maintaining
 good order in the classroom, providing an enriching learning
 experience for students, and as training as a practicing computing
 professional upon graduation.  This practice is manifested in the
 University's Academic Integrity policy. Students are expected to
 strictly avoid academic dishonesty and adhere to the Academic
 Integrity policy as outlined in the course catalog.  Violations
 will be dealt with as outlined therein.

 All programming assignments in this class are to be done by the
 student alone.  No outside help is permitted except the instructor
 and approved tutors.

 I certify that the work submitted with this assignment is mine and
 was generated in a manner consistent with this document, the
 course academic policy on the course website on Blackboard, and
 the UMass Lowell academic code.

 Date:03/18/2021
 Name:Mitchell Conway
 */

#include <stdio.h>
#include <math.h>
#pragma warning (disable:4996)

int getUserStart();
int getUserEnd(int userStart);
void clearKeyboardBuffer();


int main(int argc, const char* argv[]) {

    int userStart = 1; //start value provided by user
    int userEnd; // end value provided by user
    int cycles = 0; //number of times the algorithm took to each a certain point.
    int value = 2; // placeholder value for collatz calculations [only used for calculation purposes]
    int i = 0; // variable to keep the colums to 7


    // function calls to grab values from user
    userStart = getUserStart();
    userEnd = getUserEnd(userStart);

    value = userStart;

    while (value <= userEnd) {

        // Reset userStart to be incremented value 
        // to set up for Collatz calculation
        userStart = value; 
        printf("%5d:", userStart);

        // Collatz Calculation for a given value 'userStart' 
        while (userStart != 1) {
            if (userStart % 2 == 0) {
                userStart = userStart / 2;
                cycles = cycles + 1;
            } else {
                userStart = (userStart * 3) + 1;
                cycles = cycles + 1;
            }
        }

        // Print Collatz output for a given userStart value
        printf("%-5d", cycles);
        value =  value + 1;

        // Formatting (per row)
        i = i +1;
        if (i == 7) {
            printf("\n");
            i = 0;
        }
        cycles = 0;
    }
    if (i != 0) {
        printf("\n");
    }
    return 0;
}

// function to starting point from the user that is between 1 and 100.
int getUserStart() {
    int userInput1 = 0;
    int scanCheck = 0;

    printf("Enter a starting point:\n");
    while ((userInput1 <= 1) || (userInput1 >= 100) || (scanCheck == 0)) {
        scanCheck = scanf("%d", &userInput1);
        if ((userInput1 <= 1) || (userInput1 >= 100) || (scanCheck == 0)) {
            printf("Enter a valid starting point (from 2 ~ 99):\n");
        }
        clearKeyboardBuffer();
    }

    return userInput1;
}

int getUserEnd(int userStart) {
    int userInput2 = 0;
    int scanCheck = 0;

    printf("Enter an ending point:\n");
    while ((userInput2 < (userStart)) || (userInput2 >= 1000) || (scanCheck == 0)) {
        scanCheck = scanf("%d", &userInput2);
        if ((userInput2 < (userStart)) || (userInput2 >= 1000) || (scanCheck == 0)) {
            printf("Enter a valid ending point (from %d ~ 999):\n", (userStart + 1));
        }
        clearKeyboardBuffer();
    }
    return userInput2;
}

// Clears keyboard buffer to prevent errors
void clearKeyboardBuffer(void) {
    char ch;
    scanf("%c", &ch);

    while (ch != '\n' && ch != '\0') {
        scanf("%c", &ch);
    }
}


