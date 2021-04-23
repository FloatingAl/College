#include <iostream>
#include "lab4.h"
#include <typeinfo>
#include <cmath>


void Circle::setRadius(double sRadius)
{
	radius_ = sRadius;
}
double Circle::getRadius()
{
	return radius_;
}
double Circle::getArea()
{
	return M_PI * (pow(radius_, 2.0)) ;
}
void Square::setLength(double sLength)
{
	length_ = sLength;
}
double Square::getLength()
{
	return length_;
}
void Square::setWidth(double sWidth)
{
	width_ = sWidth;
}
double Square::getWidth()
{
	return width_;
}
double Square::getArea()
{
	return length_* width_;
}
void Triangle::setBase(double sBase)
{
	base_ = sBase;
}
double Triangle::getBase()
{
	return base_;
}
void Triangle::setHeight(double sHeight)
{
	height_ = sHeight;
}
double Triangle::getHeight()
{
	return height_;
}
double Triangle::getArea() 
{
	return (height_*base_)/2;
}

void Sphere::setRadius(double sRadius){

	radius_ = sRadius;

}
double Sphere::getRadius(){

	return radius_;
}
double Sphere::getArea(){
	return 4 * M_PI *(pow(radius_, 2.0));
}
double Sphere::getVolume(){
	return (4 * M_PI*(pow(radius_,3)))/3 ;
}

void Cube::setLength(double sLength){

	length_ = sLength;

}
double Cube::getLength(){

	return length_;
}
void Cube::setWidth(double sWidth){

	width_ = sWidth;
}
double Cube::getWidth(){

	return width_;
}
void Cube::setHeight(double sHeight){
	height_ = sHeight;

}
double Cube::getHeight(){
	return height_;
}
double Cube::getArea(){
	return length_ * width_ * height_;
}
double Cube::getVolume(){
	return  6 * (pow(length_, 2));
}
void Tetrahedron::setLength(double sLength)
{
	length_ = sLength;
}
double Tetrahedron::getLength()
{
	return length_;
}
double Tetrahedron::getArea(){
	return sqrt(3) * (pow (length_,2));
}
double Tetrahedron::getVolume(){
	return (pow(length_,3))/(6*sqrt(2));
}