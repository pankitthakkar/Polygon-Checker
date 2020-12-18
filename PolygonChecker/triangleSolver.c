#include <stdio.h>
#include <stdbool.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {

    int a = side1, b = side2, c = side3;
    char* Equilateral = "Equilateral Triangle";
    char* Scalene = "Scalene Triangle";
    char* Isosceles = "Isosceles Triangle";
    char* NotATriangle = "Not a Triangle";

    if (a + b > c && a + c > b && b + c > a)
    {
        if (side1 == side2 && side1 == side3) {
            printf("\n%s\n\n", Equilateral);
            return Equilateral;
        }

        else if ((side1 == side2 && side1 != side3) || (side1 == side3 && side1 != side2)) {
            printf("\n%s\n\n", Isosceles);
            return Isosceles;
        }

        else {
            printf("\n%s\n\n", Scalene);
            return Scalene;
        }
    }

    else {
        printf("\n%s\n\n", NotATriangle);
        return NotATriangle;
    }
}