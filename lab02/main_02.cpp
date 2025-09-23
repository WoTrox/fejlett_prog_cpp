#include <iostream>

#include "Point.h"
#include "Util.h"

using namespace std;

int main() {
    Point p1(2, 3);
    cout << "p1( " << p1.getX() << "," << p1.getY() << ")" << endl;
    Point p2(100, 200);
    cout << "p2( " << p2.getX() << "," << p2.getY() << ")" << endl;
    Point *pp1 = new Point(300, 400);
    Point *pp2 = new Point(500, 1000);
    cout << "pp1( " << pp1->getX() << "," << pp1->getY() << ")" << endl;
    cout << "pp2( " << pp2->getX() << "," << pp2->getY() << ")" << endl;

    pp1->print();

    cout<<"pp1 es pp2 kozotti tavolsag: "<<pointDistance(*pp1, *pp2)<<endl;

    Point *pp3 = new Point(0, 0);
    Point *pp4 = new Point(0, 10);
    Point *pp5 = new Point(10, 0);
    Point *pp6 = new Point(10, 10);

    (isSquare(*pp3, *pp4, *pp5, *pp6)) ? cout<<"Negyzet" << endl : cout<<"Nem negyzet" << endl;

    testIsSquare("points.txt");

    delete pp1;
    delete pp2;

    return 0;
}
