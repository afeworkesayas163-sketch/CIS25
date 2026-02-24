#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Item {
public:
    string name;
    double price;
    int quantity;

    double getTotalPrice() {
        return price * quantity;
    }

    void saveToFile() {
        ofstream out("cart.txt", ios::app);
        if (out.is_open()) {
            out << name << " " << price << " " << quantity << endl;
            out.close();
        } else {
            cout << "Unable to open file." << endl;
        }
    }
};

void addItem() {
    Item item;

    cout << "Enter item name: ";
    cin >> item.name;

    cout << "Enter item price: ";
    cin >> item.price;

    cout << "Enter item quantity: ";
    cin >> item.quantity;

    item.saveToFile();

    cout << "Item added to cart." << endl;
}

void viewCheckout() {
    ifstream in("cart.txt");

    if (!in.is_open()) {
        cout << "Cart is empty or file not found." << endl;
        return;
    }

    Item item;
    double grandTotal = 0;

    cout << "\n===== CHECKOUT =====" << endl;

    while (in >> item.name >> item.price >> item.quantity) {
        double total = item.getTotalPrice();

        cout << item.name << " - $" 
             << item.price << " x " 
             << item.quantity << " = $" 
             << total << endl;

        grandTotal += total;
    }

    in.close();

    cout << "--------------------" << endl;
    cout << "Total: $" << grandTotal << endl;
}

int main() {

    int choice;

    do {
        cout << "\n===== SHOPPING CART MENU =====" << endl;
        cout << "1. Add item to cart" << endl;
        cout << "2. View checkout" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";

        cin >> choice;

        if (choice == 1) {
            addItem();
        }
        else if (choice == 2) {
            viewCheckout();
        }
        else if (choice == 3) {
            cout << "Thank you for shopping!" << endl;
        }
        else {
            cout << "Invalid option." << endl;
        }

    } while (choice != 3);

    return 0;
}
