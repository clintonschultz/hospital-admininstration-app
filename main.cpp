
#include "HospitalMethods.cpp"
#include "Patient.h"
#include "Logger.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>

/* we want to bulk add patients into system from file
 * we want all operations to be logged to a file in normal mode
 * we want some way to turn on debug mode
 * we want all operations logged to the console in debug mode
*/

using namespace std;

int main() {

    priority_queue<Patient, vector<Patient>, CompareByPriority> triagedPatients;
    vector<Patient> treatedPatients;
    vector<Patient> nextPatient;
    vector<string> ailments;
    int x, cont = 1;
    ofstream myfile ("log.txt");

    if (myfile.is_open()) {
        logger.log("\"log.txt\" logger file was opened\n");
    }
    if (!myfile.is_open()) {
        logger.log("\"log.txt\" logger file failed to open\n");
    }

    // create patients
    Patient patient1;
    Patient patient2;
    Patient patient3;

    // update patient 1
    patient1.setFirstName("Stevie");
    patient1.setMiddleName("Ray");
    patient1.setLastName("Vaughn");
    patient1.setSuffix("jr");
    patient1.setDoctor("Seuss");
    ailments.push_back("Burnt raw butt region");
    ailments.push_back("Rotting fleshwound");
    patient1.setAilments(ailments);
    ailments.clear();
    patient1.setTreated(0);
    patient1.setPriority(110);
    triagedPatients.push(patient1);
    logger.log("patient1 created\n");

    // update patient 2
    patient2.setFirstName("Jimmy");
    patient2.setMiddleName("John");
    patient2.setLastName("Jorgenson");
    patient2.setSuffix("");
    patient2.setDoctor("Kevorkian");
    ailments.push_back("Burnt raw penile region");
    ailments.push_back("Bad time in general");
    patient2.setAilments(ailments);
    ailments.clear();
    patient2.setTreated(0);
    patient2.setPriority(209);
    triagedPatients.push(patient2);
    logger.log("patient2 created\n");

    // update patient 3
    patient3.setFirstName("Billy");
    patient3.setMiddleName("Ray");
    patient3.setLastName("Xyrus");
    patient3.setSuffix("sr");
    patient3.setDoctor("Seuss");
    ailments.push_back("Burnt raw gooch region");
    ailments.push_back("Stankbreath");
    patient3.setAilments(ailments);
    ailments.clear();
    patient3.setTreated(0);
    patient3.setPriority(300);
    triagedPatients.push(patient3);
    logger.log("patient3 created\n");

    while (cont == 1) {

        logger.log("Main menu was accessed\n");

        cout << "** WELCOME TO OUR SHODDY LITTLE HOSPITAL Y'ALL **" << endl;
        cout << "Please choose from the following options below.\n" << endl;
        cout << "***** Press '1' to Add Patient to the System *****" << endl;
        cout << "***** Press '2' to Treat a Patient in Triaged Order *****" << endl;
        cout << "***** Press '3' to Print a Patient's Info as a Report *****" << endl;
        cout << "***** Press '4' to Print a Report of All Treated Patients *****" << endl;
        cout << "***** Press '5' to Find the Next Patient to be Treated *****" << endl;
        cout << "***** Press '6' to Print Out a Report of All Patients in Triage *****" << endl;
        cout << "***** Press '7' to Treat All Patients (Bad Idea - Less Money) *****" << endl;
        cout << "***** Press '8' to Get Printout of All Patients By Doctor *****" << endl;
        cout << "***** Press '9' to Print Out Help Guide *****" << endl;
        cout << "***** Press '0' for More Options *****" << endl;

        cout << "Your Choice: " << endl;
        cin >> x;
        logger.log("Main menu selection was made\n");

        switch (x) {
            case 1:

                addPatient(triagedPatients, treatedPatients);
                logger.log("addPatient() has finished\n");
                break;
            case 2:

                logger.log("Size of treatedPatients pre treatPatient: " + treatedPatients.size());
                treatPatient(triagedPatients, treatedPatients);
                logger.log("treatPatient() has finished\n");
                logger.log("Size of treatedPatients post treatPatient: " + treatedPatients.size());
                break;
            case 3:

                printPatientInfo(triagedPatients, treatedPatients);
                logger.log("printPatientInfo() has finished\n");
                break;
            case 4:

                printTreatedPatients(treatedPatients);
                logger.log("printTreatedPatients() has finished\n");
                break;

            case 5:
                nextPatientTreated(triagedPatients, nextPatient);
                logger.log("nextPatientTreated() has finished");
                nextPatient.clear();
                logger.log("nextPatient vector has been cleared\n");
                break;

            case 6:
                printPatientsInTriage(triagedPatients);
                logger.log("printPatientsInTriage() has finished");
                break;

            case 7:
                treatAllPatients(triagedPatients, treatedPatients);
                logger.log("treatAllPatients() has finished");
                cout << "All patients have been treated\n" << endl;
                break;

            case 8:
                patientsByDoctor(triagedPatients, treatedPatients);
                logger.log("patientsByDoctor() has finished");
                break;

            case 9:
                printGuide();
                logger.log("printGuide() has finished");
                break;

            case 0:

                int y;
                cout << "***** Press '1' to Add Patients in Bulk to the System *****" << endl;
                cout << "***** Press '2' to Toggle Debug Mode *****" << endl;
                cin >> y;

                switch (y) {

                    case 1:
                        bulkAddPatients(triagedPatients, treatedPatients);
                        logger.log("bulkAddPatients() has finished");
                        break;

                    case 2:
                        logger.setDebugMode(!logger.getDebugMode());
                        logger.log("Debug mode toggled\n");
                        break;
                }
                break;

            default:
                cout << "\nIncorrect Digit Pressed\n" << endl;
                logger.log("Incorrect key was pressed at main menu");
        }
        //return x;

        cout << "\nPlease press 1 to continue. Otherwise, press any other key to exit." << endl;
        cin >> cont;
    }
    cout << "\n*** Just so you know, ALL of the data you just entered is now gone forever! Yay! ***" << endl;
    cout << "\n*** Thank you for choosing our piece of shid system and have a wonderfully splendid day! ***" << endl;
    logger.log("The user has ended the session");
    myfile.close();
    return 0;
}