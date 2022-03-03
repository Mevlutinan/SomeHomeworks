#ifndef COMPOSEDSHAPES_H_
#define COMPOSEDSHAPES_H_
#include <iostream>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "ComposedShapes.h"
#include <fstream>
#include <cmath>
#include <vector> 

using namespace std;

class ComposedShapes{

public:

	ComposedShapes();
	/*Overloaded Constructors*/
	ComposedShapes(Rectangle CoRec,Circle SmCir);
	ComposedShapes(Rectangle CoRec,Rectangle SmRec);
	ComposedShapes(Rectangle CoRec,Triangle SmTri);
	
	ComposedShapes(Circle CoCir,Circle SmCir);
	ComposedShapes(Circle CoCir,Rectangle SmRec);
	ComposedShapes(Circle CoCir,Triangle SmTri);

	ComposedShapes(Triangle CoTri,Triangle SmTri);
	ComposedShapes(Triangle CoTri,Rectangle SmRec);
	ComposedShapes(Triangle CoTri,Circle SmCir);
	/*vector's setters*/
	void set_vector_rec(Rectangle rec);
	void set_vector_cir(Circle cir);
	void set_vector_tri(Triangle tri);


	vector<Rectangle> get_vector_rec()const;
	vector<Circle> get_vector_cir()const;
	vector<Triangle> get_vector_tri()const;

	void drawvectors(ofstream& myfile);
	void optimalFit();

	
	int rectangle_rectangle();
	double rectangle_circle();
	double rectangle_triangle();


	double triangle_rectangle();
	double triangle_triangle();
	double triangle_circle();

	double circle_rectangle();
	double circle_triangle();
	double circle_circle();


private:

	char Firstshape,Secondshape;
	
	vector<Rectangle> RectVec;
	vector<Circle> CircVec;
	vector<Triangle> TriVec;
	
	Triangle CTri,STri;
	Rectangle CRec,SRec;
	Circle CCir,SCir;

};

#endif
