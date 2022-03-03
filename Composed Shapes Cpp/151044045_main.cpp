#include <iostream>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "ComposedShapes.h"
using namespace std;



/*    TRASH TRASH THRASGATRAHARTAHS
//rec_cir(rec,cir,400.0,400.0,20.0);
//rec_rec(rec,rec,400.0,400.0,20.0,20.0)
//rec_tri(rec,tri,400.0,400.0,20.0);
//cir_cir(cir,cir,400.0,20.0)
//cir_rec(cir,rec,400.0,20.0,20.0)
//cir_tri(cir,tri,400.0,20.0);
//tri_rec(tri,rec,200.0,20.0,20.0),
//tri_cir(tri,cir,200.0,20.0)
//tri_tri(tri,tri,200.0,20.0);


*/
void mymain();
void testit();

void mymain(){

	testit();
}

int main(void){
	mymain();
}

void testit(){
	/*Constructors take parameters*/
	Rectangle Crec(0.0,0.0,400.0,400.0);
	Triangle  Ctri(400.0);
	Circle    Ccir(200,200,200);
	Rectangle Srec(0.0,0.0,20.0,45.0);
	Triangle  Stri(20.0);
	Circle 	  Scir(20.0,20.0,20.0);
	/*ComposedShapes Constructors*/
	ComposedShapes CrSr(Crec,Srec);
	ComposedShapes CrSc(Crec,Scir); 
	ComposedShapes CrSt(Crec,Stri); 

	ComposedShapes CtSr(Ctri,Srec);
	ComposedShapes CtSt(Ctri,Stri);
	ComposedShapes CtSc(Ctri,Scir);

	ComposedShapes CcSr(Ccir,Srec);
	ComposedShapes CcSt(Ccir,Stri);
	ComposedShapes CcSc(Ccir,Scir);
	/*Calling Fucntions*/
	CrSr.optimalFit();
	CrSc.optimalFit();
	CrSt.optimalFit();

	CtSr.optimalFit();
	CtSt.optimalFit();
	CtSc.optimalFit();

	CcSr.optimalFit();
	CcSt.optimalFit();
	CcSc.optimalFit();

}