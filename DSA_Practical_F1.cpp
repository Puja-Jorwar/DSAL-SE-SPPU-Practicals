#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
struct Student {
    int rollNumber;
    char name[50];
    char division;
    char address[100];
};

void addStudent() {
    ofstream outFile("students.dat", ios::binary | ios::app);
    Student student;
    cout << "Enter Roll Number: ";
    cin >> student.rollNumber;
    cin.ignore(); 
    cout << "Enter Name: ";
    cin.getline(student.name, 50);
    cout << "Enter Division: ";
    cin >> student.division;
    cin.ignore(); 
    cout << "Enter Address: ";
    cin.getline(student.address, 100);

    outFile.write(reinterpret_cast<char*>(&student), sizeof(Student));

    outFile.close();
}

void deleteStudent(int rollNumber) {
    ifstream inFile("students.dat", ios::binary);
    ofstream outFile("temp.dat", ios::binary);

    Student student;
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.rollNumber != rollNumber) {
            outFile.write(reinterpret_cast<char*>(&student), sizeof(Student));
        } 
        else {
            found = true;
        }
    }

    inFile.close();
    outFile.close();

    if (found) {
        remove("students.dat");
        rename("temp.dat", "students.dat");
        cout << "Student record deleted successfully." << endl;
    } 
    else {
        remove("temp.dat");
        cout << "Student record not found." << endl;
    }
}

void displayStudent(int rollNumber) {
    ifstream inFile("students.dat", ios::binary);

    Student student;
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.rollNumber == rollNumber) {
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            found = true;
            break;
        }
    }

    inFile.close();
    if (!found) {
        cout << "Student record not found." << endl;
    }
}

int main() {
    int choice;
    int rollNumber;

    do {
        cout << "----- Student Information System -----" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Display Student" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                cout << "Enter Roll Number of student to delete: ";
                cin >> rollNumber;
                deleteStudent(rollNumber);
                break;
            case 3:
                cout << "Enter Roll Number of student to display: ";
                cin >> rollNumber;
                displayStudent(rollNumber);
                break;
            case 4:
            	cout<<"Thanks for using the program !!!";
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    } while (choice != 4);
    return 0; 
}
