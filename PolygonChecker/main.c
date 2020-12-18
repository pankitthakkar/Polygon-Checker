#include <stdio.h>
#include <stdbool.h>
#include <math.h>
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


int main() {
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

        default:
            printf("\nInvalid value entered. Please try again.\n");
            break;
        }
    }
    return 0;
}