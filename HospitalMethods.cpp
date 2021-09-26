//
// Created by clinton schultz on 4/10/21.
//
#ifndef HOSPITALADMINCONSOLEAPP_HOSPITALMETHODS
#define HOSPITALADMINCONSOLEAPP_HOSPITALMETHODS

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <unistd.h>

#include "Patient.h"
#include "Logger.h"
#include "CompareByPriority.cpp"

using namespace std;

// prints out any Patient vector passed in
static void printListOfPatients(vector<Patient> & v) {

    logger.log("printListOfPatients() was successfully called\n");

    for (Patient i : v) {
        cout << "First Name: " << i.getFirstName() << endl;
        cout << "Middle Name: " << i.getMiddleName() << endl;
        cout << "Last Name: " << i.getLastName() << endl;
        cout << "Suffix: " << i.getSuffix() << endl;
        cout << "Doctor: " << i.getDoctor() << endl;
        for (string s : i.getAilments()) {
            cout << "Ailments: " << s << endl;
        }
        cout << "Treated: " << i.getTreated() << endl;
        cout << "Priority: " << i.getPriority() << "\n" << endl;
    }
}

// func addPatient - adds patient to system
static void addPatient(priority_queue<Patient, vector<Patient>,
        CompareByPriority> & triagedList, vector<Patient> & treatedPatients) {

    logger.log("addPatient() was successfully called\n");

    string tempstr, temp = "0";
    int tempint = 0;
    Patient newPatient;
    vector<string> ailments;

    cout << "Patient's first name: " << endl;
    cin >> tempstr;
    newPatient.setFirstName(tempstr);
    cout << "Patient's middle name: " << endl;
    cin >> tempstr;
    newPatient.setMiddleName(tempstr);
    cout << "Patient's last name: " << endl;
    cin >> tempstr;
    newPatient.setLastName(tempstr);
    cout << "Does patient have a suffix? (y/n)" << endl;
    cin >> tempstr;
    if (tempstr != "n") {
        cout << "Patient's suffix: " << endl;
        cin >> tempstr;
        newPatient.setSuffix(tempstr);
    }
    else {
        newPatient.setSuffix("");
    }

    cout << "How many ailments would you like to add?" << endl;
    cin >> tempint;
    for (int i = 0; i < tempint; i++) {
        cout << "Enter ailment: " << endl;
        cin >> tempstr;
        ailments.push_back(tempstr);
    }
    cout << "Patient's doctor: " << endl;
    cin >> tempstr;
    newPatient.setDoctor(tempstr);
    cout << "Has patient been treated? (0 is false, 1 is true): " << endl;
    cin >> tempint;
    newPatient.setTreated(tempint);
    cout << "Indicate number of patient's priority: " << endl;
    cin >> tempint;
    newPatient.setPriority(tempint);
    newPatient.setAilments(ailments);

    if (newPatient.getTreated() == 0) {
        triagedList.push(newPatient);
    }
    else {
        treatedPatients.push_back(newPatient);
    }
}

// func treatPatient - treat patient in triaged order
static void treatPatient(priority_queue<Patient, vector<Patient>,
        CompareByPriority> & triagedList, vector<Patient> & treatedList) {

    logger.log("treatPatient() was successfully called\n");

    Patient p = triagedList.top();
    p.setTreated(1);
    cout << p.getFirstName() << " " << p.getLastName() << " is being treated..." << endl;
    treatedList.push_back(p);
    triagedList.pop();
    int delay = rand() % 3 + 1;
    sleep(delay);
    cout << "Patient treatment complete\n" << endl;
}

// func printPatientInfo - prints report of requested patient info
static void printPatientInfo(priority_queue<Patient, vector<Patient>,
        CompareByPriority> & triagedList, vector<Patient> & treatedList) {

    logger.log("printPatientInfo() was successfully called\n");

    string first, last;
    int flag = 1;

    cout << "Enter Patient's Last Name: " << endl;
    cin >> last;
    cout << "Enter Patient's First Name: " << endl;
    cin >> first;

    for (auto i : treatedList) {
        if (i.getFirstName() == first && i.getLastName() == last) {
            cout << "First Name: " << i.getFirstName() << endl;
            cout << "Middle Name: " << i.getMiddleName() << endl;
            cout << "Last Name: " << i.getLastName() << endl;
            cout << "Suffix: " << i.getSuffix() << endl;
            cout << "Doctor: " << i.getDoctor() << endl;
            for (string s : i.getAilments()) {
                cout << "Ailments: " << s << endl;
            }
            cout << "Treated: " << i.getTreated() << endl;
            cout << "Priority: " << i.getPriority() << "\n" << endl;
            flag = 0;
            break;
        }
    }
    priority_queue<Patient, vector<Patient>, CompareByPriority> pq = triagedList;
    while (!pq.empty()) {
        if (pq.top().getFirstName() == first && pq.top().getLastName() == last) {
            cout << "First Name: " << pq.top().getFirstName() << endl;
            cout << "Middle Name: " << pq.top().getMiddleName() << endl;
            cout << "Last Name: " << pq.top().getLastName() << endl;
            cout << "Suffix: " << pq.top().getSuffix() << endl;
            cout << "Doctor: " << pq.top().getDoctor() << endl;
            for (string s : pq.top().getAilments()) {
                cout << "Ailments: " << s << endl;
            }
            cout << "Treated: " << pq.top().getTreated() << endl;
            cout << "Priority: " << pq.top().getPriority() << "\n" << endl;
            flag = 0;
            break;
        }
    }
    if (flag == 1) {
        cout << "No one was found with that name. Please try again." << endl;
        logger.log("No patient info was associated with the name \"" + first + " " + last + "\"\n");
    }
}

// func printTreatedPatients - prints report of all treated patients
static void printTreatedPatients(vector<Patient> & v) {

    logger.log("printTreatedPatients() was successfully called\n");

    printListOfPatients(v);
    logger.log("printListOfPatients() was called\n");
}

// func nextPatientTreated - returns the next patient in queue to be treated
static void nextPatientTreated(priority_queue<Patient, vector<Patient>,
        CompareByPriority> & triagedList, vector<Patient> & nextPatient) {

    logger.log("nextPatientTreated() was successfully called\n");

    priority_queue<Patient, vector<Patient>, CompareByPriority> tList = triagedList;
    tList.pop();
    nextPatient.push_back(tList.top());
    printListOfPatients(nextPatient);
    logger.log("printListOfPatients() was called\n");
}

// func printPatientsInTriage - prints report of all patients in triage
static void printPatientsInTriage(priority_queue<Patient, vector<Patient>,
        CompareByPriority> & triagedList)
{
    logger.log("printPatientsInTriage() was successfully called\n");

    priority_queue<Patient, vector<Patient>, CompareByPriority> pq = triagedList;
    vector<Patient> p;

    while (!pq.empty()) {
        p.push_back(pq.top());
        pq.pop();
    }
    printListOfPatients(p);
    logger.log("printListOfPatients() was called\n");
}

// func treatAllPatients - single command that treats all patients
static void treatAllPatients(priority_queue<Patient, vector<Patient>,
        CompareByPriority> & triagedList, vector<Patient> & treatedList) {

    logger.log("treatAllPatients() was successfully called\n");

    while (!triagedList.empty()) {
        treatPatient(triagedList, treatedList);
    }
}

// func patientsByDoctor - prints out a report of patients by doctor
static void patientsByDoctor(priority_queue<Patient, vector<Patient>,
        CompareByPriority> & triagedList, vector<Patient> & treatedList) {

    logger.log("patientsByDoctor() was successfully called\n");

    vector<Patient> patientsByDoctor;
    string doctorName;

    // need to clear vector from last call
    patientsByDoctor.clear();

    cout << "Please enter the name of the doctor to get patient info." << endl;
    cin >> doctorName;

    priority_queue<Patient, vector<Patient>, CompareByPriority> pq = triagedList;
    while (!pq.empty()) {
        if (pq.top().getDoctor() == doctorName) {
            patientsByDoctor.push_back(pq.top());
        }
        pq.pop();
    }
    for (Patient i : treatedList) {
        if (i.getDoctor() == doctorName) {
            patientsByDoctor.push_back(i);
        }
    }
    cout << "*** Patients under Dr. " << doctorName << "'s care ***\n" << endl;
    logger.log("Patients under Dr. " + doctorName + " requested\n");
    printListOfPatients(patientsByDoctor);
    logger.log("printListOfPatients() was called\n");
}

// func printGuide - prints out a guide with all command functionality
static void printGuide() {
    int x;

    logger.log("printGuide() was successfully called\n");

    cout << "** Hello and Welcome to the Help Menu! **\n" << endl;
    cout << "Press 1 to learn more about addPatient() function." << endl;
    cout << "Press 2 to learn more about treatPatient() function." << endl;
    cout << "Press 3 to learn more about printPatientInfo() function." << endl;
    cout << "Press 4 to learn more about printTreatedPatients() function." << endl;
    cout << "Press 5 to learn more about nextPatientTreated() function." << endl;
    cout << "Press 6 to learn more about printPatientsInTriage() function." << endl;
    cout << "Press 7 to learn more about treatAllPatients() function." << endl;
    cout << "Press 8 to learn more about patientsByDoctor() function." << endl;
    cout << "Press 9 to learn more about printGuide() function." << endl;
    cout << "Press 0 to learn more about bulkAddPatients() function.\n" << endl;
    cout << "Please indicate the corresponding number to the function you would like to know more about: " << endl;
    cin >> x;

    switch(x)
    {
        case 1:

            //HospitalMethods::addPatient();
            logger.log("addPatient() info requested\n");
            cout << "addPatient() prompts the user to add a new patient's information." << endl;
            break;
        case 2:

            //HospitalMethods::treatPatient();
            logger.log("treatPatient() info requested\n");
            cout << "treatPatient() asks for the patient's information and then treats that patient "
                    "of their ailments." << endl;
            break;
        case 3:

            //HospitalMethods::printPatientInfo();
            logger.log("printPatientInfo() info requested\n");
            cout << "printPatientInfo() prints out a detailed report on any patient in the system" << endl;
            break;
        case 4:

            //HospitalMethods::printTreatedPatients();
            logger.log("printTreatedPatients() info requested\n");
            cout << "printTreatedPatients() prints off a list of patients that have been treated." << endl;
            break;

        case 5:
            //HospitalMethods::nextPatientTreated();
            logger.log("nextPatientTreated() info requested\n");
            cout << "nextPatientTreated() prints the name of the next patient to be treated." << endl;
            break;

        case 6:
            //HospitalMethods::printPatientsInTriage();
            logger.log("printPatientsInTriage() info requested\n");
            cout << "printPatientsInTriage() prints out a list of patients that are in triage." << endl;
            break;

        case 7:
            //HospitalMethods::treatAllPatients();
            logger.log("treatAllPatients() info requested\n");
            cout << "treatAllPatients() when called, will treat all of the patients waiting to be treated" << endl;
            break;

        case 8:
            //HospitalMethods::patientsByDoctor();
            logger.log("patientsByDoctor() info requested\n");
            cout << "patientsByDoctor() returns a list of patients organized by doctor." << endl;
            break;

        case 9:
            //HospitalMethods::printGuide();
            logger.log("printGuide() info requested\n");
            cout << "printGuide() is the function you are currently using. C'mon man." << endl;
            break;

        case 0:
            //HospitalMethods::bulkAddPatients(v);
            logger.log("bulkAddPatients() info requested\n");
            cout << "bulkAddPatients() allows user to add several patients at a time." << endl;
            break;

        default:
            logger.log("Incorrect key was pressed in main menu of printGuide()\n");
            cout<<"\nYour entry was invalid. Please try again.\n";
    }
}

// func bulkAddPatients - bulk adds patients to system by reading .txt file
static void bulkAddPatients(priority_queue<Patient, vector<Patient>,
        CompareByPriority> & triagedList, vector<Patient> & treatedList) {

    logger.log("printGuide() was successfully called\n");

    cout << "Enter Filepath Name: " << endl;
    string filepath1;
    cin >> filepath1;
    ifstream file;

    file.open(filepath1);

    if (!file.is_open()) {
        cout << "File did not open" << endl;
    }
    int counter = 0;
    Patient newPatient;
    string line;
    vector<string> ailments;

    while (getline(file, line)) {

        string key, value;
        int intval;
        string delim = ":";

        key = line.substr(0, line.find(delim));
        value = line.substr(line.find(delim) + 1);

        if (line.empty()) {
            if (newPatient.getTreated() == 1) {
                treatedList.push_back(newPatient);
            }
            else {
                triagedList.push(newPatient);
            }
            counter++;
            cout << "Added Patient number " << counter << "\n" << endl;
            logger.log("Finished adding patient: " + newPatient.getFirstName() + " " + newPatient.getLastName() + "\n");
            ailments.clear();
            logger.log("ailments list cleared\n");

        } else {
            logger.log("Key: " + key + " Value: " + value);
            if (key == "firstName") {
                newPatient.setFirstName(value);
            }
            if (key == "middleName") {
                newPatient.setMiddleName(value);
            }
            if (key == "lastName") {
                newPatient.setLastName(value);
            }
            if (key == "suffix") {
                newPatient.setSuffix(value);
            }
            if (key == "doctor") {
                newPatient.setDoctor(value);
            }
            if (key == "ailment") {
                ailments.push_back(value);
            }
            if (key == "treated") {
                newPatient.setTreated(intval);
            }
            if (key == "priority") {
                newPatient.setPriority(intval);
            }
        }
    }
    file.close();
    logger.log("Input file was closed\n");
}

#endif //HOSPITALADMINCONSOLEAPP_HOSPITALMETHODS