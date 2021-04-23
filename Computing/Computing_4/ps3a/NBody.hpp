#ifndef NBODY_H
#define NBODY_H


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>


class Body : public sf::Drawable
{
 private:
  double _time;
  sf::Vector2f _position;
  sf::Vector2f _velocity;
  float _mass;
  std::string _filename;

 public:
  Body(float xCoord, float yCoord, float xVelocity, float yVelocity, float mass, std::string fileName);
  
  Body();
  //friend istream &operator>>( istream &input, const Body &B);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  //input stream overloader
  friend std::istream& operator>>(std::istream& in, Body& Body);

  void setTime(double sTime);
  double getTime();
  
  void setPosition(sf::Vector2f sPosition);
  sf::Vector2f getPosition();

  void setVel(sf::Vector2f sVel);
  sf::Vector2f getVel();

  void setMass(float sMass);
  float getMass();

  void setFilename(std::string sFile);
  std::string getFilename();

  ~Body();
};

#endif