#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Item {
    int id;
    string name;
    int quantity;
    float price;
};

vector<Item> inventory;

void addItem() {
    Item item;

    cout << "Enter Item ID: ";
    cin >> item.id;

    cout << "Enter Item Name: ";
    cin >> item.name;

    cout << "Enter Quantity: ";
    cin >> item.quantity;

    cout << "Enter Price: ";
    cin >> item.price;

    inventory.push_back(item);

    cout << "Item added successfully!\n";
}

void displayItems() {
    if (inventory.empty()) {
        cout << "Inventory is empty.\n";
        return;
    }

    for (const Item& item : inventory) {
        cout << "\nID: " << item.id;
        cout << "\nName: " << item.name;
        cout << "\nQuantity: " << item.quantity;
        cout << "\nPrice: " << item.price << "\n";
    }
}

void saveData() {
    ofstream file("inventory.txt");

    for (const Item& item : inventory) {
        file << item.id << " "
             << item.name << " "
             << item.quantity << " "
             << item.price << "\n";
    }

    file.close();
    cout << "Inventory saved successfully!\n";
}

void loadData() {
    ifstream file("inventory.txt");
    Item item;

    while (file >> item.id >> item.name
                >> item.quantity >> item.price) {
        inventory.push_back(item);
    }

    file.close();
}

int main() {
    loadData();

    int choice;

    do {
        cout << "\n===== INVENTORY MANAGEMENT =====\n";
        cout << "1. Add Item\n";
        cout << "2. Display Items\n";
        cout << "3. Save Inventory\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice) {
            case 1: addItem(); break;
            case 2: displayItems(); break;
            case 3: saveData(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    saveData();
    return 0;
}