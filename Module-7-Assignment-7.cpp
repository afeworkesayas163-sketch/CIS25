#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

// Class to store flight information
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

    // Check if the file opens correctly
    if (!file.is_open()) {
        cout << "Error opening file. Please make sure flight_data.csv is in the same folder as this program." << endl;
        return 1;
    }

    // Skip the header row
    getline(file, line);

    int count = 0;

    // Read the first 10 rows from the CSV file
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

    // Display the flight data
    cout << "Flight Ticket Data" << endl;
    cout << "==============================" << endl;

    for (size_t i = 0; i < flights.size(); i++) {
        cout << "Flight " << i + 1 << ":" << endl;
        cout << "Airline: " << flights[i].airline << endl;
        cout << "Origin: " << flights[i].origin << endl;
        cout << "Destination: " << flights[i].destination << endl;
        cout << "Class: " << flights[i].flightClass << endl;
        cout << "Price (USD): " << flights[i].price << endl;
        cout << "------------------------------" << endl;
    }

    return 0;
}
