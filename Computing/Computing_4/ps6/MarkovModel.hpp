/* <Copyright Abara Mehene*/
#ifndef MARKOV_MODEL_HPP
#define MARKOV_MODEL_HPP

#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <algorithm>

class MarkovModel {
 private:
    int _order;
    std::map <std::string, int> _kgrams;  // must #include <map>
    std::string _alphabet;
    // space
 public:
    // create a Markov model of order k from given text
    // Assume that text has length at least k.
    MarkovModel(std::string text, int k);

    // order k of Markov model
    int order();

    // number of occurrences of kgram in text
    // (throw an exception if kgram is not of length k)
    int freq(std::string kgram);

    // number of times that character c follows kgram
    // if order=0, return num of times char c appears
    // (throw an exception if kgram is not of length k)
    int freq(std::string kgram, char c);

    // random character following given kgram
    // (Throw an exception if kgram is not of length k.
    //  Throw an exception if no such kgram.)
    char randk(std::string kgram);

    // generate a string of length T characters
    // by simulating a trajectory through the corresponding
    // Markov chain.  The first k characters of the newly
    // generated string should be the argument kgram.
    // Throw an exception if kgram is not of length k.
    // Assume that T is at least k.
    std::string gen(std::string kgram, int T);

    // overload the stream insertion operator and display
    // the internal state of the Markov Model. Print out
    // the order, the alphabet, and the frequencies of
    // the k-grams and k+1-grams.
    friend std::ostream& operator<<(std::ostream &out, MarkovModel &mm);

  ~MarkovModel();
};

#endif
