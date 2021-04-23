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
    std::cout << count << std::endl << cap << std::endl;

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
    
    if (last == (array+cap)){
         last = 0;
    }
     
     count++; 
     (*last) = x;
     last = (last + 1);
    
}

// deletes and returns the item from the front of the buffer
int16_t RingBuffer::dequeue() {
    if (isEmpty() == 1) {
       throw std::runtime_error("can't dequeue to a empty ring");
    }
    count--;
    int16_t temp;
    temp = (*first);
    first = (first+1);
    return temp;
}

// returns item from the front without deleting it
int16_t RingBuffer::peek() {
    int16_t temp = *(first);
    return temp;
}

RingBuffer::~RingBuffer() {
    delete[] array;
}
