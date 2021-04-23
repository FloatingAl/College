#include <iostream>
#include <typeinfo>
#include <cmath>

using namespace std;


class Shape {
public:
Shape(){
}

virtual double getArea() {}
virtual double getVolume() {}
	
};

class TwoDS : public Shape{

public:
	TwoDS(){
	}

	
};

class ThreeDS : public Shape{
public:
	ThreeDS(){

	}

};

class Circle : public TwoDS{
public:
	void setRadius(double sRadius);
	double getRadius();
	double getArea();
	Circle(double radius)
	{
		radius_ = radius;
	}
	Circle(){

	}
private:
	double radius_;
};

class Square : public TwoDS{
public:
	void setLength(double sLength);
	double getLength();
	void setWidth(double sWidth);
	double getWidth();
	double getArea();

	Square(double length, double width)
	{
		length_ = length;
		width_ = width;
	}
	Square(){

	}
private:
	double	length_;
	double	width_;
};

class Triangle : public TwoDS{
public:
	void setBase(double sBase);
	double getBase();
	void setHeight(double sHeight);
	double getHeight();
	double getArea();

	Triangle(double base, double height)
	{
		base_ = base;
		height_ = height;
	}
	Triangle(){

	}

private:
	double base_;
	double height_;
};

class Sphere : public ThreeDS{
public:

	void setRadius(double sRadius);
	double getRadius();
	double getArea();
	double getVolume();

	Sphere(double radius){

		radius_ = radius;
	}

private:
	double base_;
	double radius_;
};

class Cube : public ThreeDS{
public:
	void setLength(double sLength);
	double getLength();
	void setWidth(double sWidth);
	double getWidth();
	void setHeight(double sHeight);
	double getHeight();
	double getArea();
	double getVolume();

	Cube(double length, double width, double height)
	{
		length_ = length;
		width_ = width;
		height_ = height;
	}
private:
	double length_;
	double width_;
	double height_;
};

class  Tetrahedron : public ThreeDS{
public:
	void setLength(double sLength);
	double getLength();
	double getArea();
	double getVolume();

	Tetrahedron(double length)
	{
		length_ = length;
	}
private:
	double length_; 
};

