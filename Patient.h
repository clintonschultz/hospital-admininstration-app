//
// Created by clinton schultz on 4/17/21.
//
#ifndef HOSPITALADMINCONSOLEAPP_PATIENT_H
#define HOSPITALADMINCONSOLEAPP_PATIENT_H

#include <vector>
#include <string>

#include "Logger.h"

using namespace std;

class Patient {
    public:
        Patient();
        string getFirstName() const;
        void setFirstName(string newFirstName);
        string getMiddleName() const;
        void setMiddleName(string newMiddleName);
        string getLastName() const;
        void setLastName(string newLastName);
        string getSuffix() const;
        void setSuffix(string newSuffix);
        string getDoctor() const;
        void setDoctor(string newDoctor);
        int getTreated() const;
        void setTreated(int newTreated);
        int getPriority() const;
        void setPriority(int newPriority);
        vector<string> getAilments() const;
        void setAilments(const vector<string> & newAilments);
        // void printReport();

    private:
        string firstName, middleName, lastName, suffix, doctor;
        int treated, priority;
        vector<string> ailments;
};

#endif //HOSPITALADMINCONSOLEAPP_PATIENT_H
