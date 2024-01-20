#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Contact {
    string name;
    string phoneNumber;
    string email;
};

vector<Contact> contacts; 

void saveContactsToFile() {
    ofstream file("contacts.txt");
    if (file.is_open()) {
        for (const auto &contact : contacts) {
            file << contact.name << "," << contact.phoneNumber << "," << contact.email << endl;
        }
        file.close();
    } else {
        cout << "Unable to save contacts to file." << endl;
    }
}

void loadContactsFromFile() {
    ifstream file("contacts.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            Contact contact;
            size_t pos = line.find(",");
            contact.name = line.substr(0, pos);
            line.erase(0, pos + 1);
            pos = line.find(",");
            contact.phoneNumber = line.substr(0, pos);
            line.erase(0, pos + 1);
            contact.email = line;
            contacts.push_back(contact);
        }
        file.close();
    }
}

void displayContacts() {
    if (contacts.empty()) {
        cout << "No contacts found." << endl;
    } else {
        cout << "Contacts:\n";
        for (size_t i = 0; i < contacts.size(); ++i) {
            cout << i + 1 << ". Name: " << contacts[i].name << ", Phone: " << contacts[i].phoneNumber << ", Email: " << contacts[i].email << endl;
        }
    }
}

void addContact() {
    Contact newContact;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, newContact.name);
    cout << "Enter phone number: ";
    getline(cin, newContact.phoneNumber);
    cout << "Enter email: ";
    getline(cin, newContact.email);
    contacts.push_back(newContact);
    saveContactsToFile();
    cout << "Contact added successfully." << endl;
}

void editContact() {
    int index;
    displayContacts();
    cout << "Enter the index of the contact you want to edit: ";
    cin >> index;
    if (index >= 1 && index <= static_cast<int>(contacts.size())) {
        cout << "Enter new name: ";
        cin.ignore();
        getline(cin, contacts[index - 1].name);
        cout << "Enter new phone number: ";
        getline(cin, contacts[index - 1].phoneNumber);
        cout << "Enter new email: ";
        getline(cin, contacts[index - 1].email);
        saveContactsToFile();
        cout << "Contact edited successfully." << endl;
    } else {
        cout << "Invalid index." << endl;
    }
}

void deleteContact() {
    int index;
    displayContacts();
    cout << "Enter the index of the contact you want to delete: ";
    cin >> index;
    if (index >= 1 && index <= static_cast<int>(contacts.size())) {
        contacts.erase(contacts.begin() + index - 1);
        saveContactsToFile();
        cout << "Contact deleted successfully." << endl;
    } else {
        cout << "Invalid index." << endl;
    }
}

int main() {
    loadContactsFromFile();

    int choice;
    while (true) {
        cout << "\nContact Management System\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Edit Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                editContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}