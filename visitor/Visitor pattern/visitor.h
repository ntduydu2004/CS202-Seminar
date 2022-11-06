//Base on: https://github.com/codetechandtutorials/DesignPatterns/tree/master/DesignPatterns/Visitor
//21125141 - Trần Thúc Minh Trí
//Not the part I was assigned, but it's something you can look at for more information.

/*
Instructions:
To add the new Rhombus class to the visitor, uncomment all comments to see the difference.
*/
#ifndef VISITOR_H_INCLUDED
#define VISITOR_H_INCLUDED

class Triangle;
class Rectangle;
class Parallelogram;
//class Rhombus;

class Visitor {
public:
    virtual float VisitTriangle( Triangle* comp) = 0;
    virtual float VisitRectangle( Rectangle* comp) = 0;
    virtual float VisitParallelogram( Parallelogram* comp) = 0;
    //virtual float VisitRhombus( Rhombus* comp) = 0;
};

class Polygon {
public:
    virtual ~Polygon() {}
    virtual float Area(Visitor* visitor) = 0;
    float getX();
    float getY();
protected:
    float x;
    float y;
};
float Polygon::getX(){
    return x;
}
float Polygon::getY(){
    return y;
}

#include <string>
class Triangle : public Polygon {
public:
    Triangle(float x, float y){
        this->x = x;
        this->y = y;
    }
    /*
    https://stackoverflow.com/questions/18198314/what-is-the-override-keyword-in-c-used-for
    The override keyword serves two purposes:
    - Shows the reader: this is a virtual method that is overriding a virtual method of the base class
    - The compiler also knows that it's an override, if you write it incorrectly it will raise an error
    */
    virtual float Area(Visitor* visitor) override { //Overriden method
        return visitor->VisitTriangle(this);
    }
};

class Rectangle : public Polygon {
public:
    Rectangle(float x, float y){
        this->x = x;
        this->y = y;
    }
    virtual float Area(Visitor* visitor) override { //Overriden method
        return visitor->VisitRectangle(this);
    }
};

class Parallelogram : public Polygon {
public:
    Parallelogram(float x, float y){
        this->x = x;
        this->y = y;
    }
    virtual float Area(Visitor* visitor) override { //Overriden method
        return visitor->VisitParallelogram(this);
    }
};
/*
class Rhombus : public Polygon {
public:
    Rhombus(float x, float y){
        this->x = x;
        this->y = y;
    }
    virtual float Area(Visitor* visitor) override { //Overriden method
        return visitor->VisitRhombus(this);
    }
};
*/
class AreaVisitor : public Visitor {
public: //Methods added by the visitor, override the above
    float VisitTriangle( Triangle* comp) override  {
        return comp->getX() * comp->getY() / (float)2;
    }
    float VisitRectangle( Rectangle* comp) override {
        return comp->getX() * comp->getY();
    }
    float VisitParallelogram( Parallelogram* comp) override {
        return comp->getX() * comp->getY();
    }
    /*
    float VisitRhombus( Rhombus* comp) override {
        return comp->getX() * comp->getY() / (float)2;
    }
    */
};
#endif // VISITOR_H_INCLUDED
