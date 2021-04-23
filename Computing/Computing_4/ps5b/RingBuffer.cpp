/*Copyright [2016] <Albara Mehene> */

#include "RingBuffer.hpp"

// creates a empty ringbuffer with a max capacity
RingBuffer::RingBuffer(int capacity) {
if(capacity < 1) {
    throw std::invalid_argument("capacity must be greater than zero");
}   
    cap = capacity;
    count = 0;
    array = new int16_t[capacity];
    first = array;
    last = array;
}

// returns the number of items currently in the buffer
int RingBuffer::size() {
    return count;
}

// checks to see if the buffer is empty
bool RingBuffer::isEmpty() {
    if (count == 0) {
        return 1;
    } else {
        return 0;
    }
}

// checks to see if the buffer is full
bool RingBuffer::isFull() {
    if (count == cap) {
       return 1;
    } else {
       return 0;
    }
}

// add item x to the end of buffer
void RingBuffer::enqueue(int16_t x) {
if(isFull() == 1) {
    throw std::runtime_error("can't enqueue to a full ring");
}
    
    if (last == (array+(cap-1))){
         count++; 
         (*last) = x;
         last = array;
    }else{
        count++; 
        (*last) = x;
        last = (last + 1);
    }
}

// deletes and returns the item from the front of the buffer
int16_t RingBuffer::dequeue() {
    if (isEmpty() == 1) {
       throw std::runtime_error("can't dequeue to a empty ring");
    }
     
    int16_t store;
    
    if(first == (array+(cap-1))){
      count--;
      store = (*first);
      first = array;
      return store;
    }else{   
        count--;
        store = (*first);
        first = (first+1);
        return store;
    }
}

// returns item from the front without deleting it
int16_t RingBuffer::peek() {
    int16_t temp = (*first);
    return temp;
}

RingBuffer::~RingBuffer() {
    delete[] array;
}
void RingBuffer::print_out(){

    for(int i = 0; i < cap;i++){
        std::cout << "Array:   " << array[i] << std::endl;
    }
}