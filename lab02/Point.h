//
// Created by Wotro on 23/09/2025.
//

#ifndef POINT_H
#define POINT_H

class Point{
private:
    int x, y;
public:
    Point( int x=0, int y=0);
    int getX() const;
    int getY() const;
    void print() const;
};


#endif //POINT_H
