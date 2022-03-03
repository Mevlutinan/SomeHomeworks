#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include <iostream>
#include <fstream>
using namespace std;
class Rectangle{

public:

    Rectangle();
    Rectangle(double myx,double myy,double width,double height);

    void setmyx(double myx);  //yapar
    void setmyy(double myy);
    void setwidth(double width);
    void setheight(double height);

    double getmyx()const;//okur
    double getmyy()const;
    double getwidth()const;
    double getheight()const;

    void draw(ofstream& myfile);

    //Rectangle drawrec(ofstream fp,const double my_x,const double my_y);
private:
    double primyx;
    double primyy;
    double priwidth;
    double priheight;
};

#endif 
