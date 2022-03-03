#ifndef CIRCLE_H_
#define CIRCLE_H_
#include <iostream>
#include <fstream>
using namespace std;
class Circle{

public:

    Circle();
    Circle(double myx,double myy,double radius);

    void setmyx(double myx);
    void setmyy(double myy);
    void setradius(double radius);

    double getmyy()const;
    double getmyx()const;
    double getradius()const;

    void draw(ofstream& myfile);
private:

    double primyx,primyy,priradius;

};

#endif
