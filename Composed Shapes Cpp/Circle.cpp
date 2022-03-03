#include <iostream>
#include "Circle.h"
using namespace std;


void Circle::setmyx(double myx){primyx=myx;}
void Circle::setmyy(double myy){primyy=myy;}
void Circle::setradius(double radius){priradius=radius;}

 double Circle::getmyx()const{return primyx;}
 double Circle::getmyy()const{return primyy;}
 double Circle::getradius()const{return priradius;}

Circle::Circle(){
    primyy=0;
    primyx=0;
    priradius=0;
}

Circle::Circle(double myx,double myy,double radius){
    primyy=myy;
    primyx=myx;
    priradius=radius;
}

void Circle::draw(ofstream& myfile){

	myfile << "<circle cx=\""<<primyx<<"\""<<" cy=\""<<primyy<<"\""<<" r=\""<< priradius<<"\""<<" stroke-width = \"1px\" "<<" stroke = \"black\" "<<" fill=\"green\"/>\n\t\t";


}