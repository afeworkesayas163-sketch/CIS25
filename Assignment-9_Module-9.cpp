/*
Name: Afe Abota
Course: C++
Assignment: Module 9
Instructor: Lakisha Brooks
*/

#include <iostream>
using namespace std;

class User {
protected:
    string username;

public:
    User(string name) {
        username = name;
    }

    virtual void accessLevel() {
        cout << username << " has general system access." << endl;
    }
};

class Employee : public User {
public:
    Employee(string name) : User(name) {
    }

    void accessLevel() override {
        cout << username << " can view inventory." << endl;
    }
};

class Manager : public User {
public:
    Manager(string name) : User(name) {
    }

    void accessLevel() override {
        cout << username << " can view and update inventory." << endl;
    }
};

class Admin : public User {
public:
    Admin(string name) : User(name) {
    }

    void accessLevel() override {
        cout << username << " has full access: add, update, and delete inventory." << endl;
    }
};

int main() {
    User user1("DefaultUser");
    Employee employee1("Alice");
    Manager manager1("Bob");
    Admin admin1("Charlie");

    cout << "Inventory System Access Levels" << endl;

    user1.accessLevel();
    employee1.accessLevel();
    manager1.accessLevel();
    admin1.accessLevel();

    return 0;
}
