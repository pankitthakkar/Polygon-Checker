#include <stdio.h>
#include <stdbool.h>
#include <math.h>  

#include "triangleSolver.h"

#pragma warning(disable : 4996)

#define PI 3.1415926535

char* analyzeTriangle(int side1, int side2, int side3) { // Pankit Chandrakant Thakkar

    int a = side1, b = side2, c = side3;
    char* Equilateral = "Equilateral Triangle";
    char* Scalene = "Scalene Triangle";
    char* Isosceles = "Isosceles Triangle";
    char* NotATriangle = "Not a Triangle";

    if (a + b > c && a + c > b && b + c > a) // this is the most important condition for the formation of triangles
    {
        if (side1 == side2 && side1 == side3) {
            printf("\n%s\n\n", Equilateral);
            printAngle(side1, side2, side3);
            return Equilateral;
        }

        else if ((side1 == side2 && side1 != side3) || (side1 == side3 && side1 != side2)) {
            printf("\n%s\n\n", Isosceles);
            printAngle(side1, side2, side3);
            return Isosceles;
        }

        else {
            printf("\n%s\n\n", Scalene);
            printAngle(side1, side2, side3);
            return Scalene;
        }
    }

    else {
        printf("\n%s\n\n", NotATriangle);
        return NotATriangle;
    }
}

void printAngle(int a1, int b1, int c1) // Dhyey Brijeshkumar Vaghela
{
    printf("Angles of the triangle:\n");

    float a = (int)(a1);
    float b = (int)(b1);
    float c = (int)(c1);

    float alphavalue = GiveAlpha(a, b, c);
    float betavalue = GiveBeta(a, b, c);
    float gammavalue = GiveGamma(a, b, c);

    printf("\nalpha: %f\n", alphavalue);
    printf("beta : %f\n", betavalue);
    printf("gamma: %f\n", gammavalue);
}

float GiveAlpha(float a, float b, float c) { // Dhyey Brijeshkumar Vaghela

    float a2 = a * a;
    float b2 = b * b;
    float c2 = c * c;

    float alpha = acos((b2 + c2 - a2) / (2 * b * c));
    alpha = alpha * 180 / PI;

    return alpha;
}

float GiveBeta(float a, float b, float c) { // Dhyey Brijeshkumar Vaghela

    float a2 = a * a;
    float b2 = b * b;
    float c2 = c * c;

    float beta = acos((a2 + c2 - b2) / (2 * a * c));

    beta = beta * 180 / PI;

    return beta;
}

float GiveGamma(float a, float b, float c) { // Dhyey Brijeshkumar Vaghela

    float a2 = a * a;
    float b2 = b * b;
    float c2 = c * c;

    float gamma = acos((a2 + b2 - c2) / (2 * a * b));
    gamma = gamma * 180 / PI;

    return gamma;
}