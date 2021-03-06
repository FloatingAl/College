/*Copyright [2016] <Albara Mehene> */
/*#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
*/

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

#include <stdint.h>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

#include "RingBuffer.hpp"

BOOST_AUTO_TEST_CASE(RBcontructor) {
    // normal constructor
    BOOST_REQUIRE_NO_THROW(RingBuffer(100));

    // this should fail
    BOOST_REQUIRE_THROW(RingBuffer(0), std::exception);
    BOOST_REQUIRE_THROW(RingBuffer(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(RBenque_dequeue) {
    RingBuffer rb(100);

    rb.enqueue(2);
    rb.enqueue(1);
    rb.enqueue(0);

    BOOST_REQUIRE(rb.dequeue() == 2);
    BOOST_REQUIRE(rb.dequeue() == 1);
    BOOST_REQUIRE(rb.dequeue() == 0);

    BOOST_REQUIRE_THROW(rb.dequeue(), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(test1) {
    RingBuffer rb(3);
    rb.enqueue(2);
    rb.enqueue(3);
    rb.enqueue(4);
    BOOST_REQUIRE(rb.isFull());
    BOOST_REQUIRE_THROW(rb.enqueue(5), std::runtime_error)
} 