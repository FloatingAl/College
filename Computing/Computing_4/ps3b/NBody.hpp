#ifndef NBODY_H
#define NBODY_H


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

class Body : public sf::Drawable
{
 private:
  double _time;
  sf::Vector2f _position;
  sf::Vector2f _velocity;
  sf::Vector2f _acceleration;
  double _mass;
  std::string _filename;
  sf::Vector2f _netforce;
  int _numberOfPlanets;
  sf::Vector2f _updatedAcceleration;
  sf::Vector2f _updatedPosition;
  sf::Vector2f _updatedVelocity;

 public:
  Body(double xCoord, double yCoord, double xVelocity, double yVelocity, double mass, std::string fileName);
  
  Body();
  //friend istream &operator>>( istream &input, const Body &B);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  //input stream overloader
  friend std::istream& operator>>(std::istream& in, Body& Body);

  void step(double t_time);
  
  void setNetforce(sf::Vector2f sNetforce);
  sf::Vector2f getNetforce();

  void setNumPlanets(int sNoplanets);
  int getNumPlanets();

  void setupdatePos(sf::Vector2f sUpdatepos);
  sf::Vector2f getupdatePos();  

  /*void Body::setupdateVel(sf::Vector2f sUpdateVel);
  sf::Vector2f getupdateVel();*/

  /*void setupdatedAccel(sf::Vector2f sUpdatedAccel);
  sf::Vector2f getupdatedAccel();*/

  void setTime(double sTime);
  double getTime();
  
  void setPosition(sf::Vector2f sPosition);
  sf::Vector2f getPosition();

  void setVel(sf::Vector2f sVel);
  sf::Vector2f getVel();

  void setAccel(sf::Vector2f sAccel);
  sf::Vector2f getAccel();

  void setMass(double sMass);
  double getMass();

  void setFilename(std::string sFile);
  std::string getFilename();

  ~Body();
};

#endif