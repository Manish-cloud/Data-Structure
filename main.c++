#include<iostream>
#include<cmath>
        
using namespace std;

class RegularPolygon
{
private:
    int n;
    double side;
    double x;
    double y;
public :
    RegularPolygon();
    RegularPolygon(int , double);
    RegularPolygon(int , double , double , double);
    double getPerimeter();
    double getArea();
};

RegularPolygon::RegularPolygon()
{
    n=3;
    side=1;
    x=0;
    y=0;
}

RegularPolygon::RegularPolygon(int n, double side)
{
    this->n=n;
    this->side=side;
    this->x=0;
    this->y=0;
}

RegularPolygon::RegularPolygon(int n,double side,double x,double y)
{
    this->n=n;
    this->side=side;
    this->x=x;
    this->y=y;
}

double RegularPolygon::getPerimeter()
{
    return(n*side);
}

double RegularPolygon::getArea()
{
    double numerator;
    double denominator;
    
    numerator=n*side*side;
    
    denominator=4*tan(M_PI/n);
    
    return(numerator/denominator);
}



int main()
{
    double Perimeter;
    double Area;
    
    RegularPolygon polygon_1;
    Perimeter=polygon_1.getPerimeter();
    Area=polygon_1.getArea();
    cout<<"Perimeter Of Polygon = "<<Perimeter<<" cm"<<endl;
        cout<<"Area Of Polygon = "<<Area<<" cm²"<<endl;
    
    RegularPolygon polygon_2(6,4);
    Perimeter=polygon_2.getPerimeter();
    Area=polygon_2.getArea();
    cout<<"Perimeter Of Polygon = "<<Perimeter<<" cm"<<endl;
    cout<<"Area Of Polygon = "<<Area<<" cm²"<<endl;
    
    RegularPolygon polygon_3(10,4,5.6,7.8);
    Perimeter=polygon_3.getPerimeter();
    Area=polygon_3.getArea();
    cout<<"Perimeter Of Polygon = "<<Perimeter<<" cm"<<endl;
    cout<<"Area Of Polygon = "<<Area<<" cm²"<<endl;
    
    return 0;
}