#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <cmath>
#include<fstream>
using namespace std;

/*Trianle class*/

class Triangle{

public:
    Triangle();
    /*constructor take just side create other coordinate*/
    Triangle(double side);
    
    void setmyx(double myx);
    void setmyy(double myy);
    void setbottomrightx(double bottomrightx);
    void setbottomrighty(double bottomrighty);
    void setbottomleftx(double bottomleftx);
    void setbottomlefty(double bottomlefty);
    void setside(double side);

     double getmyx()const;
     double getmyy()const;
     double getbottomrightx()const;
     double getbottomrighty()const;
     double getbottomleftx()const;
     double getbottomlefty()const;
     double getside()const;

    void draw(ofstream& myfile);

private:
    double primyx,primyy,priside;
    double pribottomrightx;
    double pribottomrighty;
    double pribottomleftx;
    double pribottomlefty;

};
#endif
