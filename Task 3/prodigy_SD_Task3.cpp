#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
class Contact 
{
public:
    string name;
    string phoneNumber;
    string email;

    Contact(const string& name, const string& phoneNumber, const string& email)
        : name(name), phoneNumber(phoneNumber), email(email) {}
};

class ContactManager 
{
private:
    vector<Contact> contacts;
    string filename;

public:
    ContactManager(const string& filename) : filename(filename) 
    {
        loadContactsFromFile();
    }

    void addContact() 
    {
        string name, phoneNumber, email;
        cout << "Enter contact details:" << endl;
        cout << "Name: ";
        cin.ignore();
        getline(std::cin, name);
        cout << "Phone Number: ";
        cin >> phoneNumber;
        cout << "Email: ";
        cin >> email;

        Contact contact(name, phoneNumber, email);
        contacts.push_back(contact);
        cout << "Contact added successfully." << endl;
    }

    void displayContacts() 
    {
        if (contacts.empty()) 
        {
            std::cout << "No contacts to display." << endl;
        } 
        else 
        {
            cout << "Contact List:" << endl;
            for (const Contact& contact : contacts) 
            {
                cout << "Name: " << contact.name << endl;
                cout << "Phone Number: " << contact.phoneNumber << endl;
                cout << "Email: " << contact.email << endl;
                cout << "-------------------------" << endl;
            }
        }
    }

    void saveContactsToFile() 
    {
        ofstream file(filename);
        if (!file.is_open()) 
        {
            cout << "Error: Unable to open the file for writing." << endl;
            return;
        }
        for (const Contact& contact : contacts) 
        {
            file << contact.name << "," << contact.phoneNumber << "," << contact.email << endl;
        }
        file.close();
    }

    void loadContactsFromFile() 
    {
        ifstream file(filename);
        if (!file.is_open()) 
        {
            std::cout << "No contacts file found." << endl;
            return;
        }
        contacts.clear();
        string line;
        while (getline(file, line)) 
        {
            size_t comma1 = line.find(",");
            size_t comma2 = line.find(",", comma1 + 1);
            if (comma1 != std::string::npos && comma2 != std::string::npos) 
            {
                Contact contact(
                    line.substr(0, comma1),
                    line.substr(comma1 + 1, comma2 - comma1 - 1),
                    line.substr(comma2 + 1)
                );
                contacts.push_back(contact);
            }
        }
        file.close();
    }
};

int main() 
{
    ContactManager contactManager("contacts.txt");

    while (true) 
    {
        cout << "Contact Management System" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Display Contacts" << endl;
        cout << "3. Save and Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) 
        {
            case 1:
                contactManager.addContact();
                break;
            case 2:
                contactManager.displayContacts();
                break;
            case 3:
                contactManager.saveContactsToFile();
                cout << "Contacts saved. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}