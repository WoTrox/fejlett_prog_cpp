//
// Created by Wotro on 23/09/2025.
//

#include "Util.h"
#include <fstream>

#include <complex>
#include <iostream>
#include <random>

double pointDistance(const Point& a, const Point& b) {
    return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
}

bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d) {
    if (a.getX()==b.getX()==c.getX()==d.getX() && a.getY()==b.getY()==c.getY()==d.getY()) {return false;}

    if (pointDistance(a, b) == pointDistance(c, d)) {
        if (pointDistance(a, c) == pointDistance(b, d)) {
            if (pointDistance(a, d) == pointDistance(b, c)) {
                return true;
            }
        }
    }

    if (pointDistance(c, b) == pointDistance(a, d)) {
        if (pointDistance(a, c) == pointDistance(b, d)) {
            if (pointDistance(c, d) == pointDistance(a, b)) {
                return true;
            }
        }
    }
    return false;
}

void testIsSquare(const char * filename) {
    ifstream file(filename);
    if (!file.is_open()) return;
    int n = 1;
    while (!file.eof()) {
        cout << n << ". 4 pont: ";

        Point *points[4] = {};
        for (int i = 0; i < 4; ++i) {
            int x, y;
            file>>x>>y;
            points[i] = new Point(x, y);
            cout << "(" << x << ", " << y << ") ";
        }

        (isSquare(*points[0], *points[1], *points[2], *points[3])) ? cout << "negyzet" << endl : cout << "nem negyzet" << endl;
        n++;
    }
}

Point* createArray(int numPoints) {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> dis(0, 2000);

    Point* points = new Point[numPoints];

    for (int i = 0; i < numPoints; ++i) {
        points[i] = *(new Point(dis(gen), dis(gen)));
    }

    return points;
}