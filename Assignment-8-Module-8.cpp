/*
Name: Afe Abota
Course: C++
Assignment: Module 8
Instructor: Lakisha Brooks
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    string gender;
    string diagnosis;
};

void loadPatients(Patient* patients, int& count) {
    ifstream infile("patients.txt");

    if (!infile) {
        return;
    }

    count = 0;

    while (infile >> patients[count].id) {
        infile.ignore();
        getline(infile, patients[count].name);
        infile >> patients[count].age;
        infile.ignore();
        getline(infile, patients[count].gender);
        getline(infile, patients[count].diagnosis);
        count++;
    }

    infile.close();
}

void savePatients(Patient* patients, int count) {
    ofstream outfile("patients.txt");

    for (int i = 0; i < count; i++) {
        outfile << patients[i].id << endl;
        outfile << patients[i].name << endl;
        outfile << patients[i].age << endl;
        outfile << patients[i].gender << endl;
        outfile << patients[i].diagnosis << endl;
    }

    outfile.close();
    cout << "Patient records saved." << endl;
}

void sortPatients(Patient* patients, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (patients[j].id > patients[j + 1].id) {
                Patient temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }
}

void addPatient(Patient* patients, int& count) {
    if (count == 100) {
        cout << "Patient list is full." << endl;
        return;
    }

    cout << "Enter patient ID: ";
    cin >> patients[count].id;
    cin.ignore();

    cout << "Enter patient name: ";
    getline(cin, patients[count].name);

    cout << "Enter age: ";
    cin >> patients[count].age;
    cin.ignore();

    cout << "Enter gender: ";
    getline(cin, patients[count].gender);

    cout << "Enter diagnosis: ";
    getline(cin, patients[count].diagnosis);

    count++;
    sortPatients(patients, count);

    cout << "Patient added." << endl;
}

void displayPatients(Patient* patients, int count) {
    if (count == 0) {
        cout << "No patient records found." << endl;
        return;
    }

    cout << "\nPatient List" << endl;
    cout << "------------------------" << endl;

    for (int i = 0; i < count; i++) {
        cout << "ID: " << patients[i].id << endl;
        cout << "Name: " << patients[i].name << endl;
        cout << "Age: " << patients[i].age << endl;
        cout << "Gender: " << patients[i].gender << endl;
        cout << "Diagnosis: " << patients[i].diagnosis << endl;
        cout << "------------------------" << endl;
    }
}

int binarySearch(Patient* patients, int count, int targetId) {
    int first = 0;
    int last = count - 1;

    while (first <= last) {
        int middle = (first + last) / 2;

        if (patients[middle].id == targetId) {
            return middle;
        } else if (patients[middle].id < targetId) {
            first = middle + 1;
        } else {
            last = middle - 1;
        }
    }

    return -1;
}

void searchPatient(Patient* patients, int count) {
    if (count == 0) {
        cout << "No patient records found." << endl;
        return;
    }

    int id;
    cout << "Enter patient ID to search: ";
    cin >> id;

    int position = binarySearch(patients, count, id);

    if (position == -1) {
        cout << "Patient not found." << endl;
    } else {
        cout << "Patient found:" << endl;
        cout << "ID: " << patients[position].id << endl;
        cout << "Name: " << patients[position].name << endl;
        cout << "Age: " << patients[position].age << endl;
        cout << "Gender: " << patients[position].gender << endl;
        cout << "Diagnosis: " << patients[position].diagnosis << endl;
    }
}

void updatePatient(Patient* patients, int count) {
    if (count == 0) {
        cout << "No patient records found." << endl;
        return;
    }

    int id;
    cout << "Enter patient ID to update: ";
    cin >> id;
    cin.ignore();

    int position = binarySearch(patients, count, id);

    if (position == -1) {
        cout << "Patient not found." << endl;
    } else {
        cout << "Enter new name: ";
        getline(cin, patients[position].name);

        cout << "Enter new age: ";
        cin >> patients[position].age;
        cin.ignore();

        cout << "Enter new gender: ";
        getline(cin, patients[position].gender);

        cout << "Enter new diagnosis: ";
        getline(cin, patients[position].diagnosis);

        cout << "Patient updated." << endl;
    }
}

int main() {
    Patient* patients = new Patient[100];
    int count = 0;
    int choice;

    loadPatients(patients, count);
    sortPatients(patients, count);

    do {
        cout << "\nHospital Patient Management System" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. Display Patients" << endl;
        cout << "3. Search Patient" << endl;
        cout << "4. Update Patient" << endl;
        cout << "5. Save Patients" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addPatient(patients, count);
                break;
            case 2:
                displayPatients(patients, count);
                break;
            case 3:
                searchPatient(patients, count);
                break;
            case 4:
                updatePatient(patients, count);
                break;
            case 5:
                savePatients(patients, count);
                break;
            case 6:
            savePatients(patients, count);
            cout << "Good Bye!" << endl;
            break;
            default:
                cout << "Invalid choice." << endl;
        }

    } while (choice != 6);

    delete[] patients;
    return 0;
}
