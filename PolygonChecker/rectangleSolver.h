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