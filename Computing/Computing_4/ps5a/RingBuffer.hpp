/*Copyright [2016] <Albara Mehene> */
#ifndef RINGBUFFER_HPP
#define RINGBUFFER_HPP

#include <boost/test/unit_test.hpp>

#include <stdint.h>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

class RingBuffer{
 public:
    explicit RingBuffer(int capacity);
    int size();
    bool isEmpty();
    bool isFull();
    void enqueue(int16_t x);
    int16_t dequeue();
    int16_t peek();
    ~RingBuffer();
 private:
    int16_t *first;
    int16_t *last;
    int16_t *array;
    int count;
    int cap;
};

#endif
