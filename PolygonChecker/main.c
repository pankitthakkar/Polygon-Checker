// Group Project
// PolygonChecker
// Arun Kumar Thulaseedharan Pillai, Dhyey Brijeshkumar Vaghela & Pankit Chandrakant Thakkar
// CSCN71020 - Fall 2020
// Professor David Allison

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "rectangleSolver.h"
#include "triangleSolver.h"

#pragma warning(disable : 4996)

int side = 0;

void printWelcome() {
    printf("\n**********************\n");
    printf("*     Welcome to     *\n");
    printf("*   Polygon Checker  *\n");
    printf("**********************\n");
}

int printShapeMenu() {
    printf("\n1. Triangle\n");
    printf("2. Rectangle \n");
    printf("0. Exit\n\n");

    int shapeChoice;

    printf("Enter number: ");
    scanf("%1o", &shapeChoice);

    return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
    printf("Enter the three sides of the triangle: \n");
    int i;
    for (i = 0; i < 3; i++)
    {
        scanf("%d", &triangleSides[i]);
    }
    return triangleSides;
}


int main() { // Pankit Chandrakant Thakkar
    bool continueProgram = true;

    while (continueProgram) {
        printWelcome();

        int shapeChoice = printShapeMenu();

        switch (shapeChoice)
        {
        case 0:
            printf("\nHave a nice day!\n");
            return 0;

        case 1:
            printf("\nTriangle selected.\n\n");
            int triangleSides[3] = { 0, 0, 0 };
            int* triangleSidesPtr = getTriangleSides(triangleSides);
            analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
            break;

        case 2:
            printf("\nRectangle selected.\n\n");
            RectangleSolver();
            break;

        default:
            printf("\nInvalid value entered. Please try again.\n");
            break;
        }
    }
    return 0;
}