#pragma once
#include"main.h"
struct Point // Pankit Chandrakant Thakkar
{
    int x, y;
};


typedef struct Point point; // Pankit Chandrakant Thakkar

void RectangleSolver(); // Pankit Chandrakant Thakkar
void pointsView(point p1, point p2, point p3, point p4); // Pankit Chandrakant Thakkar
int input(int n); // Pankit Chandrakant Thakkar
int IsOrthogonal(point a, point b, point c); 
int IsRectangle(point a, point b, point c, point d);
int ok(point a, point b, point c, point d);
int makeSides(point p1, point p2, point p3, point p4);