#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Structure to represent a patient
struct Patient {
    string name;
    int priority; // Priority of the patient, lower value means higher priority

    // Constructor
    Patient(const string& name, int priority) : name(name), priority(priority) {}

    // Overloading the < operator to compare patients based on priority
    bool operator<(const Patient& other) const {
        // Higher priority patients should come before lower priority ones
        return priority > other.priority;
    }
};

// Function to display the menu options
void displayMenu() {
    cout << "Hospital Management System\n";
    cout << "1. Add Patient\n";
    cout << "2. Serve Patient\n";
    cout << "3. Display Patients\n";
    cout << "4. Exit\n";
}

int main() {
    priority_queue<Patient> patients; // Priority queue to store patients

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int priority;
                cout << "Enter patient name: ";
                cin >> name;
                cout << "Enter patient priority: ";
                cin >> priority;
                patients.push(Patient(name, priority));
                cout << "Patient added successfully.\n";
                break;
            }
            case 2: {
                if (patients.empty()) {
                    cout << "No patients to serve.\n";
                } else {
                    cout << "Serving patient: " << patients.top().name << endl;
                    patients.pop();
                }
                break;
            }
            case 3: {
                if (patients.empty()) {
                    cout << "No patients in the queue.\n";
                } else {
                    cout << "Patients in the queue:\n";
                    priority_queue<Patient> temp = patients; // Create a copy of the priority queue
                    while (!temp.empty()) {
                        cout << "Name: " << temp.top().name << ", Priority: " << temp.top().priority << endl;
                        temp.pop();
                    }
                }
                break;
            }
            case 4: {
                cout << "Exiting program.\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != 4);

    return 0;
}

