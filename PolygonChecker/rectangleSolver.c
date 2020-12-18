#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#pragma warning(disable : 4996)

#include"rectangleSolver.h"

void RectangleSolver()
{
    int n = 0;
    point a, b, c, d;

    printf("Enter the coordinates of the rectangle. Press enter to enter the 'x' coordinate then press enter to enter the 'y' coordinate.\n\n");

    printf("First Corner: \n");
    a.x = input(n);
    a.y = input(n);

    printf("\nSecond Corner: \n");
    b.x = input(n);
    b.y = input(n);

    printf("\nThird Corner: \n");
    c.x = input(n);
    c.y = input(n);

    printf("\nFourth Corner: \n");
    d.x = input(n);
    d.y = input(n);

    pointsView(a, b, c, d);
    makeSides(a, b, c, d);
}

void pointsView(point p1, point p2, point p3, point p4) {
    printf("\nThe entered coordinates are: \n");
    printf("(%d,%d), (%d,%d), (%d,%d), (%d,%d)\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, p4.x, p4.y);
}


int input(int n) {
    scanf("%d", &n);
    return n;
}