//21125141 - Trần Thúc Minh Trí
//Not the part I was assigned, but it's something you can look at for more information.

/*
Instructions:
To add the new Rhombus class to the visitor, uncomment all comments to see the difference.
*/
#include <iostream>
#include "visitor.h"

using namespace std;

int main() {
    AreaVisitor *v1 = new AreaVisitor;
    Polygon* p1 = new Triangle(4, 3);
    Polygon* p2 = new Rectangle(4, 3);
    Polygon* p3 = new Parallelogram(4, 3);
    //Polygon* p4 = new Rhombus(4, 3);
    cout << p1->Area(v1) << endl;
    cout << p2->Area(v1) << endl;
    cout << p3->Area(v1) << endl;
    cout << "Total = " << p1->Area(v1) + p2->Area(v1) + p3->Area(v1) << endl;
    //cout << p4->Area(v1) << endl;
    delete p1;
    delete p2;
    delete p3;
    //delete p4;
    return 0;
}
