#include <iostream>
#include "Rectangle.h"
#include <fstream>
using namespace std;


void Rectangle::setmyx(double myx){primyx=myx;}
void Rectangle::setmyy(double myy){primyy=myy;}
void Rectangle::setheight(double height){priheight=height;}
void Rectangle::setwidth(double width){priwidth=width;}

double Rectangle::getmyx()const{return primyx;}
double Rectangle::getmyy()const{return primyy;}
double Rectangle::getwidth()const{return priwidth;}
double Rectangle::getheight()const{return priheight;}

void Rectangle::draw(ofstream& myfile){
	myfile << "<rect x= "<<" \""<<primyx<< "\" "<<" y= "<<"\""<<primyy<<"\" "<<" width= "<<" \""<<priwidth<<"\" "<<" height= "<<" \""<<priheight<<"\" "<<" stroke-width = \"1px\" "<<" stroke = \"black\" "<<" fill=\"green\"/>\n\t\t";
}

Rectangle::Rectangle(){
    primyx=0;
    primyy=0;
    priwidth=0;
    priheight=0;
}

Rectangle::Rectangle(double myx,double myy,double width,double height){
    primyx=myx;
    primyy=myy;
    priwidth=width;
    priheight=height;
}

/*Rectangle Rectangle::drawrec(ofstream fp,const double my_x,const double my_y){

	Rectangle Rec;
	double width,height;

	width=getwidth();
	height=getheight();


	fp << "<rect x= "<<" \""<<my_x<< "\" "<<" y= "<<"\""<<my_y<<"\" "<<" width= "<<" \""<<width<<"\" "<<" height= "<<" \""<<height<<"\" "<<" stroke-width = \"1px\" "<<" stroke = \"black\" "<<" fill=\"green\"/>\n\t\t";

	setwidth(width);
	setheigth(height);
	setmyx(my_x);
	setmyy(my_y);
	cout<<Rec.getwidth()<<"\n";
	return Rec;

}
*/
