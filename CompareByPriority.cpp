//
// Created by clinton schultz on 4/27/21.
//
#ifndef HOSPITALADMINCONSOLEAPP_COMPAREBYPRIORITY
#define HOSPITALADMINCONSOLEAPP_COMPAREBYPRIORITY

#import "Patient.h"
#include "Logger.h"

class CompareByPriority
{
public:
    bool operator() (const Patient &lhs, const Patient &rhs) const
    { return lhs.getPriority() > rhs.getPriority(); }

};

#endif