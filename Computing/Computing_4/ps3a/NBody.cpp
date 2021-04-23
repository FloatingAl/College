#include "NBody.hpp"
//.000000002
const float SCALE = (2.50e+11);//This number negates the e+10 in the x position.

void Body::draw(sf::RenderTarget &target, sf::RenderStates states) const{
  sf::Image image;
  sf::Texture texture;
  sf::Sprite sprite;
  
  //std::cout << _position.x << _position.y << _filename << std::endl;

  if(!image.loadFromFile(_filename)){
      std::cout << "ERROR: could not load image from file" << std::endl;
      return;
    }

    texture.loadFromFile(_filename);
    sprite.setTexture(texture);

    //need to multiply the x position by SCALE so the planets are not off the screen
    sprite.setPosition((_position.x/SCALE) * 500 + target.getSize().x/2,(_position.y/SCALE) * 400 + target.getSize().y/2);
//x position / universe size * window size
    target.draw(sprite);

}

std::istream& operator>>(std::istream& in, Body& body){

  in >> body._position.x  >> body._position.y >> body._velocity.x >> body._velocity.y >> body._mass >> body._filename;

  return in;
  
}

Body::Body(float xCoord, float yCoord, float xVelocity, float yVelocity, float mass, std::string fileName){
  //setting vars to specifications
  _position.x = xCoord;
  _position.y = yCoord;
  _velocity.x = xVelocity;
  _velocity.y = yVelocity;
  _mass = mass;
  _filename = fileName;
  
}
Body::Body(){

}

 sf::Vector2f Body::getPosition(){
  return _position;
 }
 
 sf::Vector2f Body::getVel(){
  return _velocity;
 }
 
 float Body::getMass(){
  return _mass;
 }
 
 std::string Body::getFilename(){
  return _filename;
 }

 Body::~Body(){

 }

//in main, before we make a new Body, we read in the file name that has the proper characteristics, save them into multiple vars or strings, then feed them into the Body constructor
