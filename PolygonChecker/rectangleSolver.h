#pragma once
#include"main.h"
struct Point
{
    int x, y;
};


typedef struct Point point;

void RectangleSolver();
void pointsView(point p1, point p2, point p3, point p4);
int input(int n);
int IsOrthogonal(point a, point b, point c);
int IsRectangle(point a, point b, point c, point d);
int ok(point a, point b, point c, point d);
int makeSides(point p1, point p2, point p3, point p4);