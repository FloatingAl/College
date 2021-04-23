/*Copyright [2016] <Albara Mehene> */
#ifndef GUITARSTRING_H
#define GUITARSTRING_H

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>
#include <cmath>

#include "RingBuffer.hpp"

const double DECAY = 0.996;
const double SAMPLING_RATE = 44100;

class GuitarString{
 public:
    explicit GuitarString(double frequency);
    explicit GuitarString(std::vector <sf::Int16> init);
    GuitarString();
    void pluck();
    void tic();
    sf::Int16 sample();
    int time();
    ~GuitarString();
 private:
    RingBuffer *_rb;
    int _ticNum;
    int G_cap;
};

#endif
