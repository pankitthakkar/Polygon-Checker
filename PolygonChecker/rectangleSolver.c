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

int IsOrthogonal(point a, point b, point c) {
    return (b.x - a.x) * (b.x - c.x) + (b.y - a.y) * (b.y - c.y) == 0;
}

int IsRectangle(point a, point b, point c, point d) {
    return
        IsOrthogonal(a, b, c) &&
        IsOrthogonal(b, c, d) &&
        IsOrthogonal(c, d, a);
}

int ok(point a, point b, point c, point d) {
    return IsRectangle(a, b, c, d) ||
        IsRectangle(b, c, a, d) ||
        IsRectangle(c, a, b, d);
}

int makeSides(point p1, point p2, point p3, point p4) {
    int k = ok(p1, p2, p3, p4);

    if (k) {

        int side1, side2;

        if (p1.y == p2.y) {
            side1 = abs(p1.x - p2.x);
        }

        else if (p1.y == p3.y) {
            side1 = abs(p1.x - p3.x);
        }

        else if (p1.y == p4.y) {
            side1 = abs(p1.x - p4.x);
        }

        if (p1.x == p2.x) {
            side2 = abs(p1.y - p2.y);
        }

        else if (p1.x == p3.x) {
            side2 = abs(p1.y - p3.y);
        }

        else if (p1.x == p4.x) {
            side2 = abs(p1.y - p4.y);
        }

        printf("\nThe entered coordinates form a Rectangle");
        printf("\n\nArea of the Rectangle is: %d", side1 * side2);
        printf("\nPerimeter of Rectangle is: %d\n\n", (2 * (side1 + side2)));
        return 0;
    }

    else {
        printf("\n\nSorry, the entered coordinates do not form a rectangle.\n");
        return 1;
    }
}