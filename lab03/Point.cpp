//
// Created by Wotro on 23/09/2025.
//

#include "Point.h"

#include <iostream>
#include <ostream>
#include <complex>

using namespace std;

Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000) {
        this->x = x;
        this->y = y;
    } else {
        this->x = 0;
        this->y = 0;
    }
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::print() const {
    cout << "(" << this->x << ", " << this->y << ")" << endl;
}

double Point::distanceTo(const Point &point) const {
    return sqrt(pow(getX() - point.getX(), 2) + pow(getY() - point.getY(), 2));
}

