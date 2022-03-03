#include <iostream>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "ComposedShapes.h"
#include <fstream>
#include <cmath>


#include <vector> 
using namespace std;

ComposedShapes::ComposedShapes(){}

ComposedShapes::ComposedShapes(Rectangle CoRec,Circle SmCir): Firstshape('R'),Secondshape('C'){
	CRec=CoRec;
	SCir=SmCir;

}
ComposedShapes::ComposedShapes(Rectangle CoRec,Rectangle SmRec): Firstshape('R'),Secondshape('R'){

	CRec=CoRec;
	SRec=SmRec;
	
}
ComposedShapes::ComposedShapes(Rectangle CoRec,Triangle SmTri): Firstshape('R'),Secondshape('T'){

	CRec=CoRec;
	STri=SmTri;
}

ComposedShapes::ComposedShapes(Circle CoCir,Circle SmCir): Firstshape('C'),Secondshape('C'){
	
	CCir=CoCir;
	SCir=SmCir;
}
ComposedShapes::ComposedShapes(Circle CoCir,Rectangle SmRec): Firstshape('C'),Secondshape('R'){

	CCir=CoCir;
	SRec=SmRec;
}
ComposedShapes::ComposedShapes(Circle CoCir,Triangle SmTri): Firstshape('C'),Secondshape('T'){

	CCir=CoCir;
	STri=SmTri;
}

ComposedShapes::ComposedShapes(Triangle CoTri,Triangle SmTri): Firstshape('T'),Secondshape('T'){

	CTri=CoTri;
	STri=SmTri;
}
ComposedShapes::ComposedShapes(Triangle CoTri,Rectangle SmRec): Firstshape('T'),Secondshape('R'){

	CTri=CoTri;
	SRec=SmRec;
}
ComposedShapes::ComposedShapes(Triangle CoTri,Circle SmCir): Firstshape('T'),Secondshape('C'){

	CTri=CoTri;
	SCir=SmCir;
}



void ComposedShapes::set_vector_rec(Rectangle rec){

	RectVec.push_back(rec);
}

void ComposedShapes::set_vector_cir(Circle cir){

	CircVec.push_back(cir);
}

void ComposedShapes::set_vector_tri(Triangle tri){

	TriVec.push_back(tri);
}


vector<Rectangle> ComposedShapes::get_vector_rec()const{
	

	return RectVec;
}
vector<Circle> ComposedShapes::get_vector_cir()const{
	


	return CircVec;
}
vector<Triangle> ComposedShapes::get_vector_tri()const{
	

	return TriVec;
}
/*draws vector for class type */
void ComposedShapes::drawvectors(ofstream& myfile){
	

	if(Firstshape=='R' && Secondshape=='R'){
		Rectangle Irgat;/*take 1 member from class and draw it*/
		CRec.draw(myfile);/*Container Draw*/
		for(auto i=0;i<RectVec.size();i++){
			Irgat=RectVec[i];
			Irgat.draw(myfile);
		}

	}
	else if(Firstshape=='R' && Secondshape=='C'){
		Circle Irgat;
		CRec.draw(myfile);
		for(auto i=0;i<CircVec.size();i++){
			Irgat=CircVec[i];
			Irgat.draw(myfile);
		}

	}else if(Firstshape=='R' && Secondshape=='T'){
		Triangle Irgat;
		CRec.draw(myfile);/*!!!*/
		for(auto i=0;i<TriVec.size();i++){
			Irgat=TriVec[i];
			Irgat.draw(myfile);
		}

	}else if(Firstshape=='T' && Secondshape=='R'){
		Rectangle Irgat;
		CTri.draw(myfile);
		for(auto i=0;i<RectVec.size();i++){
			Irgat=RectVec[i];
			Irgat.draw(myfile);
		}

	}else if(Firstshape=='T' && Secondshape=='T'){
		Triangle Irgat;
		CTri.draw(myfile);
		for(auto i=0;i<TriVec.size();i++){
			Irgat=TriVec[i];
			Irgat.draw(myfile);
		}

	}else if(Firstshape=='T' && Secondshape=='C'){
        Circle Irgat;
        CTri.draw(myfile);
        for(auto i=0;i<CircVec.size();i++){
            Irgat=CircVec[i];
            Irgat.draw(myfile);
        }

    }else if(Firstshape=='C' && Secondshape=='R'){
        Rectangle Irgat;
        CCir.draw(myfile);
        for(auto i=0;i<RectVec.size();i++){
            Irgat=RectVec[i];
            Irgat.draw(myfile);
        }

    }else if(Firstshape=='C' && Secondshape=='T'){
        Triangle Irgat;
        CCir.draw(myfile);
        for(auto i=0;i<TriVec.size();i++){
            Irgat=TriVec[i];
            Irgat.draw(myfile);
        }

    }else if(Firstshape=='C' && Secondshape=='C'){

        Circle Irgat;
        CCir.draw(myfile);
        for(auto i=0;i<CircVec.size();i++){
            Irgat=CircVec[i];
            Irgat.draw(myfile);
        }

    }
	
}

void ComposedShapes::optimalFit(){

	if(Firstshape=='R' && Secondshape=='R'){
		rectangle_rectangle();

	    ofstream myfile;
	    myfile.open ("output");
	    myfile << "<svg version=\"1.1\"\n\t\t"
	    <<"baseProfile=\"full\" \n\t\t"
	    << "width=\""<< CRec.getwidth() <<"\""<<"  height=\""<< CRec.getheight() <<"\"\n\t\t" 
	    <<"xmlns=\"http://www.w3.org/2000/svg\">\n";
	    
	    drawvectors(myfile);
	    
	    myfile << "</svg>";
	    myfile.close();
	    }
	else if(Firstshape=='R' && Secondshape=='C'){
        rectangle_circle();

        ofstream myfile;
        myfile.open ("output1");
        myfile << "<svg version=\"1.1\"\n\t\t"
        <<"baseProfile=\"full\" \n\t\t"
        << "width=\""<< CRec.getwidth() <<"\""<<"  height=\""<< CRec.getheight() <<"\"\n\t\t" 
        <<"xmlns=\"http://www.w3.org/2000/svg\">\n";
        drawvectors(myfile);
        
        myfile << "</svg>";
        myfile.close();
    
    }else if(Firstshape=='R' && Secondshape=='T'){
    	rectangle_triangle();
    	
    	ofstream myfile;
	    myfile.open ("output2");
	    myfile << "<svg version=\"1.1\"\n\t\t"
	    <<"baseProfile=\"full\" \n\t\t"
	    << "width=\""<< CRec.getwidth() <<"\""<<"  height=\""<< CRec.getheight() <<"\"\n\t\t" 
	    <<"xmlns=\"http://www.w3.org/2000/svg\">\n\t\t";

	    drawvectors(myfile);
        
        myfile << "</svg>";
        myfile.close();

    }else if(Firstshape=='T' && Secondshape=='R'){
        triangle_rectangle();
	    ofstream myfile;
	    myfile.open ("output3");
	    myfile << "<svg version=\"1.1\"\n\t\t"
	    <<"baseProfile=\"full\" \n\t\t"
	    << "width=\""<< CTri.getside() <<"\""<<"  height=\""<<CTri.getbottomlefty()<<"\"\n\t\t" 
	    <<"xmlns=\"http://www.w3.org/2000/svg\">\n";
	    
	    drawvectors(myfile);
	    
	    myfile << "</svg>";
	    myfile.close();

	}else if(Firstshape=='T' && Secondshape=='T'){

		triangle_triangle();
	    ofstream myfile;
	    myfile.open ("output4");
	    myfile << "<svg version=\"1.1\"\n\t\t"
	    <<"baseProfile=\"full\" \n\t\t"
	    << "width=\""<< CTri.getside() <<"\""<<"  height=\""<<CTri.getbottomlefty()<<"\"\n\t\t" 
	    <<"xmlns=\"http://www.w3.org/2000/svg\">\n";
	    
	    drawvectors(myfile);
	    
	    myfile << "</svg>";
	    myfile.close();
	}else if(Firstshape=='T' && Secondshape=='C'){

        triangle_circle();
        ofstream myfile;
        myfile.open ("output5");
        myfile << "<svg version=\"1.1\"\n\t\t"
        <<"baseProfile=\"full\" \n\t\t"
        << "width=\""<< CTri.getside() <<"\""<<"  height=\""<<CTri.getbottomlefty()<<"\"\n\t\t" 
        <<"xmlns=\"http://www.w3.org/2000/svg\">\n";
        
        drawvectors(myfile);
        
        myfile << "</svg>";
        myfile.close();
    }else if(Firstshape=='C' && Secondshape=='R'){
        double main_width=CCir.getradius()*2;
        circle_rectangle();
        ofstream myfile;
        myfile.open ("output6");
        myfile << "<svg version=\"1.1\"\n\t\t"
        <<"baseProfile=\"full\" \n\t\t"
        << "width=\""<<main_width<<"\""<<"  height=\""<<main_width<<"\"\n\t\t" 
        <<"xmlns=\"http://www.w3.org/2000/svg\">\n";
        
        drawvectors(myfile);
        
        myfile << "</svg>";
        myfile.close();
    }else if(Firstshape=='C' && Secondshape=='T'){
        double main_width=CCir.getradius()*2;
        circle_triangle();
        ofstream myfile;
        myfile.open ("output7");
        myfile << "<svg version=\"1.1\"\n\t\t"
        <<"baseProfile=\"full\" \n\t\t"
        << "width=\""<<main_width<<"\""<<"  height=\""<<main_width<<"\"\n\t\t" 
        <<"xmlns=\"http://www.w3.org/2000/svg\">\n";
        
        drawvectors(myfile);
        
        myfile << "</svg>";
        myfile.close();
    }else if(Firstshape=='C' && Secondshape=='C'){
        double main_width=CCir.getradius()*2;
        circle_circle();
        ofstream myfile;
        myfile.open ("output8");
        myfile << "<svg version=\"1.1\"\n\t\t"
        <<"baseProfile=\"full\" \n\t\t"
        << "width=\""<<main_width<<"\""<<"  height=\""<<main_width<<"\"\n\t\t" 
        <<"xmlns=\"http://www.w3.org/2000/svg\">\n";
        
        drawvectors(myfile);
        
        myfile << "</svg>";
        myfile.close();
    }
}
/*i had problem because of rotating I will fix it other home work*/
double ComposedShapes::circle_circle(){

    double radius,info=0,shapes=0;

    double circle_radius=CCir.getradius();

        /*    cout << "Please enter circle radius.\n";
               cin >> radius;
        */
    if(radius>circle_radius || radius<0){
        cout<<"wrong size!!";
        return -1;
    }



    double main_width=2*circle_radius;
    double main_height=2*circle_radius;



    double my_x=main_height/2;
    double my_y=main_height/2;
    double current_x=my_x;
    int k=60;
    radius=SCir.getradius();

    //myfile << "<circle cx=\""<<my_x<<"\""<<" cy=\""<<my_y<<"\""<<" r=\""<< radius<<"\""<<" fill=\"black\"/>\n\t\t";
    int i=0,count=0;
    while(k<360){
        my_x=main_height/2;
        my_y=main_height/2;
        current_x=my_x;
        i=0;
        count=0;
        
        while(my_y<(circle_radius*2)-(radius*2)){
            i=0;
            while(i<=count){

                SCir.setradius(radius);
                SCir.setmyy(my_y);
                SCir.setmyx(my_x);

                CircVec.push_back(SCir);

                //myfile << "<circle transform=\"rotate("<<k<<" "<<circle_radius<<" "<<circle_radius<<")\" cx=\""<<my_x<<"\""<<" cy=\""<<my_y<<"\""<<" r=\""<< radius<<"\""<<" fill=\"black\"/>\n\t\t";
                my_x+=2*radius;
                i++;
                shapes++;
            }
            current_x-=radius;
            my_x=current_x;
            my_y+=radius*sqrt(3);
            count++;
                

        }
        k+=60;
    }

    info=(pow(circle_radius,2)*3.14)-(pow(radius,2)*3.14*shapes);
    cout<<"I can fit at most "<<shapes<<" small shapes into the main container.The empty area in container is "<<info<<endl;

}

/*i had problem because of rotating I will fix it other home work*/
double ComposedShapes::circle_triangle(){

    

    double side,info=0,shapes=0,circle_radius=0;
    

/*
    cout << "Please enter triangle side.\n";
    cin >> side;
*/
    if(side>circle_radius || side<0){
        cout<<"wrong size!!";
        return -1;
    }
    circle_radius=CCir.getradius();
    
    side=STri.getside();


    double main_width=2*circle_radius;
    double main_height=2*circle_radius;

    double topx=circle_radius;
    double topy=circle_radius;
    double bottomleftx=circle_radius-side/2;
    double bottomlefty=circle_radius+(side/2*sqrt(3));
    double bottomrightx=circle_radius+side/2;
    double bottomrighty=circle_radius+(side/2*sqrt(3));
    int i=0,k=0;
    
    double current_topx=circle_radius;
    double current_topy=circle_radius;
    double current_bottomleftx=circle_radius-side/2;
    double current_bottomlefty=circle_radius+(side/2*sqrt(3));
    double current_bottomrightx=circle_radius+side/2;
    double current_bottomrighty=circle_radius+(side/2*sqrt(3));
    int degree=270;
    
    while(degree<360){
        double current_topx=circle_radius;
        double current_topy=circle_radius;
        double current_bottomleftx=circle_radius-side/2;
        double current_bottomlefty=circle_radius+(side/2*sqrt(3));
        double current_bottomrightx=circle_radius+side/2;
        double current_bottomrighty=circle_radius+(side/2*sqrt(3));

        double topx=circle_radius;
        double topy=circle_radius;
        double bottomleftx=circle_radius-side/2;
        double bottomlefty=circle_radius+(side/2*sqrt(3));
        double bottomrightx=circle_radius+side/2;
        double bottomrighty=circle_radius+(side/2*sqrt(3));
        
        k=0;


        while(bottomleftx>circle_radius/2){//for normal trangles
            while(i<=k){


                            STri.setmyy(topy);
                            STri.setmyx(topx);
                            STri.setbottomrightx(bottomrightx);
                            STri.setbottomrighty(bottomrighty);
                            STri.setbottomleftx(bottomleftx);
                            STri.setbottomlefty(bottomlefty);
                            STri.setside(side);

                            TriVec.push_back(STri);
                shapes++;
                topx+=side;
                bottomrightx+=side;
                bottomleftx+=side;
                i++;
            }
            k++;
            i=0;

            current_topx-=side/2;
            current_topy+=side/2*sqrt(3);
            current_bottomleftx-=side/2;
            current_bottomlefty+=side/2*sqrt(3);
            current_bottomrightx-=side/2;
            current_bottomrighty+=side/2*sqrt(3);
        
            topx=current_topx;
            topy=current_topy;
            bottomleftx=current_bottomleftx;
            bottomlefty=current_bottomlefty;
            bottomrightx=current_bottomrightx;
            bottomrighty=current_bottomrighty;

        }
    degree+=60;   
    }
        degree=270;

    while(degree<360){//for reverse triangles
        double current_topx=circle_radius;
        double current_topy=circle_radius+(side/2*sqrt(3))*2;
        double current_bottomleftx=circle_radius-side/2;
        double current_bottomlefty=circle_radius+(side/2*sqrt(3));
        double current_bottomrightx=circle_radius+side/2;
        double current_bottomrighty=circle_radius+(side/2*sqrt(3));

        double topx=circle_radius;
        double topy=circle_radius+(side/2*sqrt(3))*2;
        double bottomleftx=circle_radius-side/2;
        double bottomlefty=circle_radius+(side/2*sqrt(3));
        double bottomrightx=circle_radius+side/2;
        double bottomrighty=circle_radius+(side/2*sqrt(3));
        
        k=0;

        while(bottomleftx>circle_radius/2){
            while(i<=k){

                STri.setmyy(topy);
                STri.setmyx(topx);
                STri.setbottomrightx(bottomrightx);
                STri.setbottomrighty(bottomrighty);
                STri.setbottomleftx(bottomleftx);
                STri.setbottomlefty(bottomlefty);
                STri.setside(side);

                TriVec.push_back(STri);



                //myfile << "<polygon transform=\"rotate("<<degree<<" "<<circle_radius<<" "<<circle_radius<<")\" points=\""<<topx<<" "<<topy<<" "<<bottomleftx<<" "<<bottomlefty<<" "<<bottomrightx<<" "<<bottomrighty<<"\""<<" fill=\"black\"/>\n\t\t";
                shapes++;
                topx+=side;
                bottomrightx+=side;
                bottomleftx+=side;
                i++;
            }
            k++;
            i=0;




            current_topx-=side/2;
            current_topy+=side/2*sqrt(3);
            current_bottomleftx-=side/2;
            current_bottomlefty+=side/2*sqrt(3);
            current_bottomrightx-=side/2;
            current_bottomrighty+=side/2*sqrt(3);
        
            topx=current_topx;
            topy=current_topy;
            bottomleftx=current_bottomleftx;
            bottomlefty=current_bottomlefty;
            bottomrightx=current_bottomrightx;
            bottomrighty=current_bottomrighty;

            

        }
    degree+=60;   
    }

    info=(pow(circle_radius,2)*3.14)-(side*side*sqrt(3)*shapes/4);
    cout<<"I can fit at most "<<shapes<<" small shapes into the main container.The empty area in container is "<<info<<endl;

}


double ComposedShapes::circle_rectangle(){
    
    double width,height,info=0,shapes=0,circle_radius=0;

    circle_radius=CCir.getradius();
    /*
    cout << "Please enter rectangle width.\n";
    cin >> width;

    cout << "Please enter rectangle height.\n";
    cin >> height;
    */

    height=SRec.getheight();
    width=SRec.getwidth();

    if(width>circle_radius || height>circle_radius || width<0 || height<0){
        cout<<"wrong size!!";
        return -1;
    }
    double main_width=2*circle_radius;
    double main_height=2*circle_radius;
    
    /*!!!!!!*/
   // myfile << "<circle cx=\""<<circle_radius<<"\""<<" cy=\""<<circle_radius<<"\""<<" r=\""<< circle_radius<<"\""<<" fill=\"yellow\"/>\n\t\t";

    double my11x,my12x,my21x,my22x,my11y,my12y,my21y,my22y;


    my11x=0;
    my11y=0;
    
    my12x=width;
    my12y=0;
    
    my21x=0;
    my21y=height;
    
    my22x=width;
    my22y=height;    




    while(my22y<=main_height){
        if(true){
            while(my12x<=main_width){
                if(//my circle borders like(x^2+y^2=r^2) 
                pow(circle_radius,2)>(pow(circle_radius-my11x,2))+(pow(circle_radius-my11y,2)) &&
                pow(circle_radius,2)>(pow(circle_radius-my21x,2))+(pow(circle_radius-my21y,2)) &&
                pow(circle_radius,2)>(pow(circle_radius-my12x,2))+(pow(circle_radius-my12y,2)) &&
                pow(circle_radius,2)>(pow(circle_radius-my22x,2))+(pow(circle_radius-my22y,2)) )
                {
                    
                    SRec.setwidth(width);
                    SRec.setheight(height);
                    SRec.setmyx(my11x);
                    SRec.setmyy(my11y);

                    RectVec.push_back(SRec);

                    //myfile << "<rect x= "<<" \""<<my11x<< "\" "<<" y= "<<"\""<<my11y<<"\" "<<" width= "<<" \""<<width<<"\" "<<" height= "<<" \""<<height<<"\" "<<" stroke-width = \"1px\" "<<" stroke = \"black\" "<<" fill=\"green\"/>\n\t\t";
                    shapes++; 
                    my11x+=width;
                    my12x+=width;
                    my21x+=width;
                    my22x+=width; 
                }else{//if not in conteiner circle update the x axis
                    my11x+=width;
                    my12x+=width;
                    my21x+=width;
                    my22x+=width; 
                }

            }

        }

        my11x=0;
        my12x=width;
        my21x=0;
        my22x=height; 

        my11y+=height;
        my12y+=height;
        my21y+=height;
        my22y+=height; 

    }
    info=(pow(circle_radius,2)*3.14)-(width*height*shapes);
    cout<<"I can fit at most "<<shapes<<" small shapes into the main container.The empty area in container is "<<info<<endl;

}




double ComposedShapes::triangle_circle(){

    double main_radius=CTri.getside()/2;
    double radius;
    double main_triangle_side=main_radius*2;
    double info=0;
    double shapes=0;
    /*cout<<"Please enter radius.\n";
    cin>>radius;
    */
    if(radius>main_radius || radius<0){
        cout<<"wrong size!!";
        return -1;
    }

    radius=SCir.getradius();
    
    double main_width=2*main_radius, main_height=(main_radius)*sqrt(3),index=0;

    

    

    double main_topx=main_triangle_side/2;
    double main_topy=0;
    double main_bottomleftx=0;
    double main_bottomlefty=(main_triangle_side/2)*sqrt(3);
    double main_bottomrightx=main_triangle_side;
    double main_bottomrighty=(main_triangle_side/2)*sqrt(3);



    double my_x=radius*sqrt(3);
    double my_y=main_height-radius;

    double current_x=radius*sqrt(3);
    double current_y=main_height-radius;
    

    while(current_y>(0+radius)){
        while((main_width-(radius*sqrt(3))-(index*radius))>my_x){


            SCir.setmyy(my_y);
            SCir.setmyx(my_x);
            SCir.setradius(radius);

            CircVec.push_back(SCir);

            //myfile << "<circle cx=\""<<my_x<<"\""<<" cy=\""<<my_y<<"\""<<" r=\""<<radius<<"\""<<" fill=\"black\"/>\n\t\t";
            


            shapes++;
            my_x+=2*radius;
        }

        current_y-=radius*sqrt(3);
        current_x+=radius;

        my_x=current_x;
        my_y=current_y;
        index++;
    }
    info=(main_radius*main_radius*sqrt(3))-(pow(radius,2)*3.14*shapes);
    cout<<"I can fit at most "<<shapes<<" small shapes into the main container.The empty area in container is "<<info<<endl;


return 1;
}


double ComposedShapes::triangle_triangle(){
    
    double side,info=0,shapes=0,main_triangle_side=0;

 //   cout<<"Please enter side.\n";
  //  cin>>side;

    main_triangle_side=CTri.getside();

    
    if(side>main_triangle_side || side<0){
        cout<<"wrong size!!";
        return -1;
    }

    side=STri.getside();


    double main_width=main_triangle_side, main_height=(main_triangle_side/2)*sqrt(3);
    double index=0;
    //container triangle  
    double main_topx=main_triangle_side/2;
    double main_topy=0;
    double main_bottomleftx=0;
    double main_bottomlefty=(main_triangle_side/2)*sqrt(3);
    double main_bottomrightx=main_triangle_side;
    double main_bottomrighty=(main_triangle_side/2)*sqrt(3);




    double topx=side/2;
    double topy=((main_triangle_side/2)*sqrt(3))-(side/2)*(sqrt(3));
    double bottomleftx=0;
    double bottomlefty=(main_triangle_side/2)*sqrt(3);
    double bottomrightx=side;
    double bottomrighty=(main_triangle_side/2)*sqrt(3);

    double first_topx=side/2;
    double first_topy=((main_triangle_side/2)*sqrt(3))-(side/2)*(sqrt(3));
    double first_bottomleftx=0;
    double first_bottomlefty=(main_triangle_side/2)*sqrt(3);
    double first_bottomrightx=side;
    double first_bottomrighty=(main_triangle_side/2)*sqrt(3); 
    
    while(first_topy>=0){//draw normal triangles
        while(bottomrightx<=main_triangle_side-(index*side/2)){
            
            
            STri.setmyx(topx);
            STri.setmyy(topy);
            STri.setbottomrightx(bottomleftx);
            STri.setbottomrighty(bottomlefty);
            STri.setbottomleftx(bottomrightx);
            STri.setbottomlefty(bottomrighty);

            TriVec.push_back(STri);
            //myfile << "<polygon points=\""<<topx<<" "<<topy<<" "<<bottomleftx<<" "<<bottomlefty<<" "<<bottomrightx<<" "<<bottomrighty<<"\""<<" fill=\"black\"/>\n\t\t";
            

            topx+=side;
            bottomrightx+=side;
            bottomleftx+=side;
            shapes++;

        }
        index++;
        
        topx=(first_topx+(index*side/2));
        bottomleftx=(first_bottomleftx+(index*side/2));
        bottomrightx=(first_bottomrightx+(index*side/2));
        
        topy-=(side/2)*sqrt(3);
        bottomrighty-=(side/2)*sqrt(3);
        bottomlefty-=(side/2)*sqrt(3);
        first_topy-=(side/2)*sqrt(3);
    }

    topx=side;
    topy=(main_triangle_side/2)*sqrt(3);
    bottomleftx=side/2;
    bottomlefty=(main_triangle_side/2)*sqrt(3)-((side/2)*sqrt(3));
    bottomrightx=side*1.5;
    bottomrighty=(main_triangle_side/2)*sqrt(3)-((side/2)*sqrt(3));

    first_topx=side;
    first_topy=(main_triangle_side/2)*sqrt(3);
    first_bottomleftx=side/2;
    first_bottomlefty=(main_triangle_side/2)*sqrt(3)-((side/2)*sqrt(3));
    first_bottomrightx=side*1.5;
    first_bottomrighty=(main_triangle_side/2)*sqrt(3)-((side/2)*sqrt(3));
    index=0;
        while(first_topy>=0){//draw reverse triangles
        while(topx<=main_triangle_side-side-(index*side/2)){
           
            STri.setmyx(topx);
            STri.setmyy(topy);
            STri.setbottomrightx(bottomleftx);
            STri.setbottomrighty(bottomlefty);
            STri.setbottomleftx(bottomrightx);
            STri.setbottomlefty(bottomrighty);

            TriVec.push_back(STri);

            //myfile << "<polygon points=\""<<topx<<" "<<topy<<" "<<bottomleftx<<" "<<bottomlefty<<" "<<bottomrightx<<" "<<bottomrighty<<"\""<<" fill=\"cyan\"/>\n\t\t";
            topx+=side;
            bottomrightx+=side;
            bottomleftx+=side;
            shapes++;

        }
        index++;
        
        topx=(first_topx+(index*side/2));
        bottomleftx=(first_bottomleftx+(index*side/2));
        bottomrightx=(first_bottomrightx+(index*side/2));
        
        topy-=(side/2)*sqrt(3);
        bottomrighty-=(side/2)*sqrt(3);
        bottomlefty-=(side/2)*sqrt(3);
        first_topy-=(side/2)*sqrt(3);
    }

    info=(main_triangle_side*main_triangle_side*sqrt(3)/4)-(side*side*sqrt(3)/4*shapes);
    cout<<"I can fit at most "<<shapes<<" small shapes into the main container.The empty area in container is "<<info<<endl;

}

double ComposedShapes::triangle_rectangle(){

    double width,height,info=0,shapes=0,triangle_side=0;

    //cout<<"Please enter width.\n";
    //cin>>width;
    //cout<<"Please enter height.\n";
    //cin>>height;

    triangle_side=CTri.getside();

    width=SRec.getwidth();
    height=SRec.getheight();

    
    if(width>triangle_side || height>triangle_side || width<=0 || height<=0){
        cout<<"wrong size!!";
        return -1;
    }


    double my_x=height/sqrt(3),my_y=(triangle_side/2*sqrt(3))-height;
    double main_width=triangle_side, main_height=(triangle_side/2)*sqrt(3);
    double index=1;
    
    double main_topx=triangle_side/2;
    double main_topy=0;
    double main_bottomleftx=0;
    double main_bottomlefty=(triangle_side/2)*sqrt(3);
    double main_bottomrightx=triangle_side;
    double main_bottomrighty=(triangle_side/2)*sqrt(3);
  



    double current_x=my_x;
    double current_y=my_y;

	CTri.setside(triangle_side);
    CTri.setmyx(main_topx);
	CTri.setmyy(main_topy);
	CTri.setbottomrightx(main_bottomrightx);
	CTri.setbottomrighty(main_bottomrighty);
	CTri.setbottomleftx(main_bottomleftx);
	CTri.setbottomlefty(main_bottomlefty);
    
   //myfile << "<polygon points=\""<<main_topx<<" "<<CTri.getside();<<" "<<CTri.getside();<<" "<<CTri.getside();<<" "<<main_bottomrightx<<" "<<main_bottomrighty<<"\""<<" fill=\"yellow\"/>\n\t\t";

    while(0<my_y){
         while(my_x<main_width-width-(index*(current_x))){
         	

		    SRec.setmyx(my_x);
		    SRec.setmyy(my_y);
		    SRec.setwidth(width);
		    SRec.setheight(height);

		    RectVec.push_back(SRec);
            shapes++;
            my_x+=width;
        }
        SRec.setmyx(current_x);
        my_x=current_x;
        my_y-=height;
        my_x+=(height*index)/sqrt(3);
        index++;
    }   

    info=(triangle_side*triangle_side*sqrt(3)/4)-(width*height*shapes);
    cout<<"I can fit at most "<<shapes<<" small shapes into the main container.The empty area in container is "<<info<<endl;

}



double ComposedShapes::rectangle_triangle(){

    double one_kiss,info=0,shapes=0,main_width,main_height;

    //cout<<"Please enter side.\n";
    //cin>>one_kiss;


	main_width=CRec.getwidth();
	main_height=CRec.getheight();


	one_kiss=STri.getside();



    if(one_kiss>main_height || one_kiss>main_width || one_kiss<0){
        cout<<"wrong size!!";
        return -1;
    }

    
    double topx=one_kiss/2;
    double topy=0;
    double bottomleftx=0;
    double bottomlefty=(one_kiss/2)*sqrt(3);
    double bottomrightx=one_kiss;
    double bottomrighty=(one_kiss/2)*sqrt(3);

    while(main_height>=bottomrighty){
        while(main_width-(one_kiss*0.5)>=topx){

        	STri.setmyy(topy);
        	STri.setmyx(topx);
			STri.setbottomrightx(bottomrightx);
			STri.setbottomrighty(bottomrighty);
			STri.setbottomleftx(bottomleftx);
			STri.setbottomlefty(bottomlefty);
        	STri.setside(one_kiss);

        	TriVec.push_back(STri);
            
           // myfile << "<polygon points=\""<<topx<<" "<<topy<<" "<<bottomleftx<<" "<<bottomlefty<<" "<<bottomrightx<<" "<<bottomrighty<<"\""<<" fill=\"green\"/>\n\t\t";
            topx+=one_kiss;
            bottomrightx+=one_kiss;
            bottomleftx+=one_kiss;
            shapes++;
        }
        topx=one_kiss/2;
        bottomleftx=0;
        bottomrightx=one_kiss;
    
        topy+=(one_kiss/2)*sqrt(3);
        bottomrighty+=(one_kiss/2)*sqrt(3);
        bottomlefty+=(one_kiss/2)*sqrt(3);       
    }
    topx=one_kiss;
    topy=(one_kiss/2)*sqrt(3);
    bottomleftx=one_kiss/2;
    bottomlefty=0;
    bottomrightx=one_kiss*(1.5);
    bottomrighty=0;

    while(main_height>=topy){
        while(main_width-(one_kiss*0.5)>=topx){

        	STri.setmyy(topy);
        	STri.setmyx(topx);
			STri.setbottomrightx(bottomrightx);
			STri.setbottomrighty(bottomrighty);
			STri.setbottomleftx(bottomleftx);
			STri.setbottomlefty(bottomlefty);
        	STri.setside(one_kiss);

        	TriVec.push_back(STri);
           
            //myfile << "<polygon points=\""<<topx<<" "<<topy<<" "<<bottomleftx<<" "<<bottomlefty<<" "<<bottomrightx<<" "<<bottomrighty<<"\""<<" fill=\"green\"/>\n\t\t";
            topx+=one_kiss;
            bottomrightx+=one_kiss;
            bottomleftx+=one_kiss;
            shapes++;

        }
        topx=one_kiss;
        bottomleftx=one_kiss/2;
        bottomrightx=one_kiss*(1.5);
    
        topy+=(one_kiss/2)*sqrt(3);
        bottomrighty+=(one_kiss/2)*sqrt(3);
        bottomlefty+=(one_kiss/2)*sqrt(3);       
    }

    info=(main_width*main_height)-(shapes*one_kiss*one_kiss*sqrt(3)/4);
    cout<<"I can fit at most "<<shapes<<" small shapes into the main container.The empty area in container is "<<info<<endl;

}

double ComposedShapes::rectangle_circle(){
	
	double main_width,main_height,main_radius,info=0;
	int shapes=0;

	main_width=CRec.getwidth();
	main_height=CRec.getheight();

    //cout<<"Please enter radius.\n";
    //cin>>main_radius;

	main_radius=SCir.getradius();

    if(main_radius>main_width || main_radius>main_height || main_radius<0){
        cout<<"wrong size!!";
        return -1;
    }

    double my_x=0,my_y=0;
    int flag=0;
    //circle cout !!
	my_x=main_radius;//!!need cout
	my_y=main_radius;

        while(main_height>my_y+(main_radius/2)){//kac satir varsa   
            while(my_x+(main_radius)<=main_width && flag==0){//satir tekken
                

            	SCir.setmyy(my_y);
            	SCir.setmyx(my_x);
            	SCir.setradius(main_radius);

            	CircVec.push_back(SCir);

                //myfile << "<circle cx=\""<<my_x<<"\""<<" cy=\""<<my_y<<"\""<<" r=\""<< main_radius<<"\""<<" fill=\"yellow\"/>\n\t\t";
                my_x+=main_radius*2;
                shapes++;
            }
            my_x=0;
            flag=1;
            while(my_x+(main_radius*2)<main_width && flag==1){//satır ciftse
                if(my_x==0)my_y+=sqrt((main_radius*2)*(main_radius*2)-(main_radius*main_radius));
                my_x+=main_radius*2;
            	SCir.setmyy(my_y);
            	SCir.setmyx(my_x);
            	SCir.setradius(main_radius);

            	CircVec.push_back(SCir);               
            	shapes++;
            }
            my_x=main_radius;
            my_y+=sqrt((main_radius*2)*(main_radius*2)-(main_radius*main_radius));
            flag=0;
        }

        info=(main_width*main_height)-(pow(main_radius,2)*3.14);
        cout<<"I can fit at most "<<shapes<<" small shapes into the main container.The empty area in container is "<<info<<endl;

}



int ComposedShapes::rectangle_rectangle(){

    double my_x=0,my_y=0,current_x=0,current_y=0,last_x=0;
    int flag=1,repeat=0;
	double width,height,info=0,shapes=0,main_height=0,main_width=0;


   // cout<<"Please enter width.\n";
   // cin>>width;

   // cout<<"Please enter height.\n";
   // cin>>height;

	main_width=CRec.getwidth();
	main_height=CRec.getheight();

	width=SRec.getwidth();
	height=SRec.getheight();


    if(width>main_width || height>main_height|| width>main_height || height>main_width || width<0 || height<0){
        cout<<"wrong size!!";
    	return -1;    
    }


	 


    if(height>=width){
    int temp=0;
    
        temp=height;
        height=width;
        width=temp;
    }

    while(my_x<=(main_width-width) && my_y<=(main_height-height)){
        //parallel x axis rectangles

    	//set_vector_rec(drawrec(myfile,my_x,my_y));

     	SRec.setmyy(my_y);
     	SRec.setmyx(my_x);
     	SRec.setwidth(width);
     	SRec.setheight(height);

     	RectVec.push_back(SRec);
        

        shapes++;
        my_x+=width;
        current_x+=width;    
        
        if(my_x>=(main_width-width)){
            if(current_x<=main_width-height){
                while(current_x<=main_width-height){
                    while(current_y<=(main_height-width)){//parallel y axis rectangles

						//set_vector_rec(drawrec(myfile,my_x,my_y));
	                 	
	                 	SRec.setmyy(current_y);
	                 	SRec.setmyx(current_x);
	                 	SRec.setwidth(height);
	                 	SRec.setheight(width);

	                 	RectVec.push_back(SRec);

                        current_y+=width;
                        shapes++;
                    }
                    current_y=0;
                    current_x+=height;
                }
            }
             my_x=0;
             my_y+=height;
         }
    }

    info=(main_width*main_height)-(width*height*shapes);
    cout<<"I can fit at most "<<shapes<<" small shapes into the main container.The empty area in container is "<<info<<endl;

return 1;
}