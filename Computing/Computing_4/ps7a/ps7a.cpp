// <Copyright Owners Albara Mehene & Sean Nishi>
// regex_match example
#include <boost/regex.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>
#include <string>
#include <fstream>

using boost::gregorian::date;
using boost::gregorian::years;
using boost::gregorian::months;
using boost::gregorian::days;
using boost::gregorian::date_duration;
using boost::gregorian::date_period;
using boost::gregorian::from_simple_string;

using boost::posix_time::ptime;
using boost::posix_time::hours;
using boost::posix_time::minutes;
using boost::posix_time::seconds;
using boost::posix_time::time_duration;


int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "ERROR: input only one file" << std::endl;
    return -1;
  }

  // open the input file
  std::ifstream logFile;
  logFile.open(argv[1]);
  // name of file
  std::string logName(argv[1]);
  std::string outputName = logName + ".rpt";
  // create the output file
  std::ofstream outputFile;
  outputFile.open(outputName.c_str());
  // space
  std::string line;
  date stored_date;
  date finished_date;
  ptime beginTime;
  ptime endTime;
  boost::smatch m;
  time_duration total_time;
  // space
  bool s_boot = false;
  int lineNum = 1;

  // Start of boot: 2014-02-01 14:02:32: (log.c.166) server started
  boost::regex Boot_Start(
    "([0-9]{4})-([0-9]{2})-([0-9]{2}) "
    "([0-9]{2}):([0-9]{2}):([0-9]{2}): "
    "\\(log.c.166\\) server started.*");
  // If we find the text:
  // "2014-01-26 09:58:04.362:INFO:oejs.AbstractConnector:Started
  // SelectChannelConnector@0.0.0.0:9080"
  boost::regex Boot_End(
    "([0-9]{4})-([0-9]{2})-([0-9]{2}) "
    "([0-9]{2}):([0-9]{2}):([0-9]{2}).([0-9]{3}):INFO:"
    "oejs.AbstractConnector:Started SelectChannelConnector@0.0.0.0:9080.*");
  // check if input file is open
  if (!logFile.is_open()) {
     std::cout << "ERROR: no input log file" << std::endl;
     return -1;
  } else {
     // Go through the loop
     while (getline(logFile, line)) {
     // search the start regex code
      if (regex_search(line, m, Boot_Start)) {
        // store them into date and time
        stored_date = date(stoi(m[1]), stoi(m[2]), stoi(m[3]));
        beginTime = ptime(stored_date,
          time_duration(stoi(m[4]), stoi(m[5]), stoi(m[6])));
       // condition to see if it will fail to go to the next condition
        if (s_boot) {
        s_boot = false;
        outputFile << "**** Incomplete boot ****\n" << std::endl;
      }
      // draw the start into the output file
      outputFile << "=== Device boot ===\n"
                 << lineNum << "(" << logName << "): "
                 << m[1] << "-" << m[2] << "-" << m[3]
                 << " "
                 << m[4] << ":" << m[5] << ":" << m[6]
                 << "Boot Start" << std::endl;
       s_boot = true;
      // Then do the same to the end buy checking the regex
     } else if (regex_search(line, m, Boot_End)) {
        finished_date = date(stoi(m[1]), stoi(m[2]), stoi(m[3]));
        endTime = ptime(stored_date,
          time_duration(stoi(m[4]), stoi(m[5]), stoi(m[6])));
        // output the rest
        outputFile << lineNum << "(" << logName << "): "
                   << m[1] << "-" << m[2] << "-" << m[3]
                   << m[4] << ":" << m[5] << ":" << m[6]
                   << " Boot Completed" << std::endl;
      total_time = endTime - beginTime;
      outputFile << "   "
                 << "Boot Time: " << total_time.total_milliseconds()
                 << "ms\n" << std::endl;
      s_boot = false;
     }
     // increment line number to go to next line
     lineNum++;
  }
  // closing the files
  logFile.close();
  outputFile.close();
  }
  return 0;
}
