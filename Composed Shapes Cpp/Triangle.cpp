#include <iostream>
#include <fstream>
#include "Triangle.h"
#include "ComposedShapes.h"
#include<cmath>
using namespace std;


void Triangle::setmyx(double myx){primyx=myx;}
void Triangle::setmyy(double myy){primyy=myy;}
void Triangle::setbottomrightx(double bottomrightx){pribottomrightx=bottomrightx;}
void Triangle::setbottomrighty(double bottomrighty){pribottomrighty=bottomrighty;}
void Triangle::setbottomleftx(double bottomleftx){pribottomleftx=bottomleftx;}
void Triangle::setbottomlefty(double bottomlefty){pribottomlefty=bottomlefty;}
void Triangle::setside(double side){priside=side;}

 double Triangle::getmyx()const{return primyx;}
 double Triangle::getmyy()const{return primyy;}
 double Triangle::getbottomrightx()const{return pribottomrightx;}
 double Triangle::getbottomrighty()const{return pribottomrighty;}
 double Triangle::getbottomleftx()const{return pribottomleftx;}
 double Triangle::getbottomlefty()const{return pribottomlefty;}
 double Triangle::getside()const{return priside;}

void Triangle::draw(ofstream& myfile){

    myfile << "<polygon points=\""<<primyx<<" "<<primyy<<" "<<pribottomleftx<<" "<<pribottomlefty<<" "<<pribottomrightx<<" "<<pribottomrighty<<"\""<<" stroke-width = \"1px\" "<<" stroke = \"black\" "<<" fill=\"green\"/>\n\t\t";
}

Triangle::Triangle(){
    primyx=0;
    primyy=0;
    pribottomrightx=0;
	pribottomrighty=0;
	pribottomleftx=0;
	pribottomlefty=0;
    priside=0;
}

Triangle::Triangle(double side){
    primyx=side/2;
    primyy=0;
    pribottomrightx=side;
    pribottomrighty=side/2*sqrt(3);
    pribottomleftx=0;
    pribottomlefty=side/2*sqrt(3);
    priside=side;
}




