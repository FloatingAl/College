#include "GuitarString.hpp"

/*create a guitar string of the given frequency using a 
sampling rate of 44,100.*/
GuitarString::GuitarString(double frequency){
	G_cap = (ceil(SAMPLING_RATE/frequency));
	
	this->_rb = new RingBuffer(G_cap);

	//fill with 0s to represent the guitar string at rest
	for(int i = 0; i < G_cap; i++){
		this->_rb->enqueue(0);
	}
}

/*create a guitar string with size and initial values are given
by the vector*/
GuitarString::GuitarString(std::vector <sf::Int16> init){

	this->_rb = new RingBuffer(init.size());

	for (std::vector<sf::Int16>::iterator i = init.begin(); i != init.end(); ++i){
      _rb->enqueue(*i);
	
	}
}	

GuitarString::GuitarString(){

}

/*Pluck the guitar string by replacing the buffer with random
values, representing white noise*/
void GuitarString::pluck(){
		//empty the buffer
		delete _rb;
		_rb = new RingBuffer(G_cap);
		
		//replace with random noise (white noise)
		for(int i = 0; i < G_cap; ++i){

			_rb->enqueue((int16_t)(rand() & 0xffff));
		}

}

/*advance the simulation one time step */
void GuitarString::tic(){
	_ticNum++;
	
	double first = _rb->dequeue();
	double front = sample();

	//std::cout << "Decay: " << DECAY << std::endl;

	double value = DECAY * ((first + front)/2);

	//std::cout << "value:   " << value << std::endl;c;
	_rb->enqueue(value);
}
/*return the current sample*/
sf::Int16 GuitarString::sample(){
	//May be returning this incorrectly
	return _rb->peek();
}

/*return number of times tic was called so far*/
int GuitarString::time(){
	
	return _ticNum;
}

GuitarString::~GuitarString(){
	//need to use delete function
	delete _rb;

}
