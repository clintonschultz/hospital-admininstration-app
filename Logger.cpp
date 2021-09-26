//
// Created by clinton schultz on 4/28/21.
//
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#include "Logger.h"

Logger::Logger()
{

}

Logger& Logger::getInstance()
{
    static Logger instance;
    return instance;
}

void Logger::log(string output)
{
    if (debugMode) {
        cout << output << endl;
    }
    else {
        ofstream myfile("log.txt", std::fstream::app);
        myfile << output;
    }
}

void Logger::setDebugMode(bool b) {
    Logger::debugMode = b;
}

bool Logger::getDebugMode() {
    return debugMode;
}

Logger & logger = Logger::getInstance();