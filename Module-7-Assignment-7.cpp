/*
Name: Afe Abota
Course: C++
Assignment: Module 7
Instructor: Lakisha Brooks
Description: This program reads flight ticket data from a CSV file
and displays the first 10 flight records.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Flight {
public:
    string airline;
    string origin;
    string destination;
    string flightClass;
    string price;
};

int main() {

    ifstream file("flight_data.csv");
    string line;
    vector<Flight> flights;

    if (!file.is_open()) {
        cout << "Error opening file. Please make sure flight_data.csv is in the same folder as this program." << endl;
        return 1;
    }

    getline(file, line);

    int count = 0;

    while (getline(file, line) && count < 10) {

        stringstream ss(line);
        string ticketID, distanceKM, daysBeforeDeparture;
        Flight f;

        getline(ss, ticketID, ',');
        getline(ss, f.airline, ',');
        getline(ss, f.origin, ',');
        getline(ss, f.destination, ',');
        getline(ss, distanceKM, ',');
        getline(ss, f.flightClass, ',');
        getline(ss, daysBeforeDeparture, ',');
        getline(ss, f.price);

        flights.push_back(f);
        count++;
    }

    file.close();

    if (flights.empty()) {
        cout << "No flight data found." << endl;
        return 0;
    }

cout << "Flight Ticket Data" << endl;
cout << "==============================" << endl;

    for (size_t i = 0; i < flights.size(); i++) {

        const Flight& f = flights[i];

        cout << "Flight " << i + 1 << ":" << endl;
        cout << "Airline: " << f.airline << endl;
        cout << "Origin: " << f.origin << endl;
        cout << "Destination: " << f.destination << endl;
        cout << "Class: " << f.flightClass << endl;
        cout << "Price (USD): " << f.price << endl;
        cout << "------------------------------" << endl;
    }

    return 0;
}
