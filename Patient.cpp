//
// Created by clinton schultz on 4/17/21.
//
#include <string>
#include <vector>
#include <iostream>

#include "Patient.h"
// #include "Logger.h"

using namespace std;

Patient::Patient()
{

}

string Patient::getFirstName() const
    { return firstName; }

void Patient::setFirstName(string newFirstName)
    { firstName = newFirstName; }

string Patient::getMiddleName() const
    { return middleName; }

void Patient::setMiddleName(string newMiddleName)
    { middleName = newMiddleName;}

string Patient::getLastName() const
    { return lastName; }

void Patient::setLastName(string newLastName)
    { lastName = newLastName; }


string Patient::getSuffix() const
    { return suffix; }

void Patient::setSuffix(string newSuffix)
    { suffix = newSuffix; }

string Patient::getDoctor() const
    { return doctor; }

void Patient::setDoctor(string newDoctor)
    { doctor = newDoctor; }

int Patient::getTreated() const
    { return treated; }

void Patient::setTreated(int newTreated)
    { treated = newTreated; }

int Patient::getPriority() const
    { return priority; }

void Patient::setPriority(int newPriority)
    { priority = newPriority; }

vector<string> Patient::getAilments() const
    { return ailments; }

void Patient::setAilments(const vector<string> &ailmentList) {
    ailments.clear();
    for (int i = 0; i < ailmentList.size(); i++) {
        ailments.push_back(ailmentList[i]);
    }
}

