// demo regex code
// Copyright (C) 2015 Fred Martin, fredm@cs.uml.edu for 91.204 Computing IV
// Thu Apr 16 11:08:45 2015

// compile with
// g++ stdin_boost.cpp -lboost_regex

// regex_match example
#include <boost/regex.hpp>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

int main() {
  std::string s, rs;
  boost::regex re;

  cout << "If you get errors when constructing the regex, see:\n";
  cout << "http://www.boost.org/doc/libs/1_58_0/";
  cout << "boost/regex/v4/error_type.hpp\n";
  cout << endl;

  cout << "Enter regex > ";
  getline(cin, rs);

  try {
    re = boost::regex(rs);
    cout << "mark_count() is " << re.mark_count() << endl;
  } catch (boost::regex_error& exc) {
    cout << "Regex constructor failed with code " << exc.code() << endl;
    exit(1);
  }

  cout << "Enter line > ";

  while (getline(cin, s)) {
    cout << endl;

    boost::smatch matches;
    boost::regex_match(s, matches, re);

    cout << "matches[0].matched is "
         << (matches[0].matched ? "true" : "false") << endl;

    if (matches[0].matched) {
      cout << "the matches were: ";
      for (unsigned i = 0; i < matches.size(); i++) {
        cout << "index=" << i << " [" << matches[i] << "] " << endl;
      }
    }

    cout << endl;
    cout << "Enter line > ";
  }

  return 0;
}
