//
// Created by Wotro on 23/09/2025.
//

#ifndef UTIL_H
#define UTIL_H
#include "Point.h"
using namespace std;

double pointDistance(const Point& a, const Point& b);

bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);

void testIsSquare(const char * filename);

Point* createArray(int numPoints);

#endif //UTIL_H
