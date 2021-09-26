//
// Created by clinton schultz on 4/28/21.
//

#ifndef HOSPITALADMINCONSOLEAPP_LOGGER_H
#define HOSPITALADMINCONSOLEAPP_LOGGER_H

#include <string>

using namespace std;

class Logger
{
private:
    Logger();
    bool debugMode = false;

public:
    static Logger& getInstance();
    void log(string output);
    void setDebugMode(bool);
    bool getDebugMode();
};

extern Logger & logger;
//extern bool debugMode = false;

#endif //HOSPITALADMINCONSOLEAPP_LOGGER_H
