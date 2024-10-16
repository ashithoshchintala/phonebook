#include<iostream>
#include<thread>
using namespace std;
class Contact {
private:
    string name;
    string phoneNumber;
    string email;
    string address;
public:
    Contact() {} // Default constructor
    Contact(string name, string phoneNumber, string email, string address);
    string getName();
    string getPhoneNumber();
    string getEmail();
    string getAddress();
    void displayContact(); // Method to display contact info
};
class BinarySearchTree {
private:
    BSTNode* root;
    void insert(BSTNode*& node, Contact newContact);
    void inorder(BSTNode* node); // Inorder traversal for sorting
    BSTNode* search(BSTNode* node, string name);
public:
    BinarySearchTree() { root = nullptr; }
    void insertContact(Contact newContact);
    void displayContacts();
    void searchContact(string name);
    void deleteContact(string name);
};

class PhoneBook {
private:
    BinarySearchTree bst; // BST structure to store contacts
public:
    void addContact(Contact newContact);
    void deleteContact(string name);
    void searchContactByName(string name);
    void searchContactByPhone(string phoneNumber);
    void displayAllContacts();
    void sortContacts(); // Sorting by name
    void editContact(string name);
};
struct BSTNode {
    Contact contact;
    BSTNode* left;
    BSTNode* right;
};
void parallelSearch(PhoneBook& phonebook, string name) {
    thread searchThread(&PhoneBook::searchContactByName, &phonebook, name); // Pass object instance and name
    searchThread.join(); // Wait for search to finish
}

class FileHandler {
public:
    void saveToFile(PhoneBook phonebook);  // Save contacts to file
    void loadFromFile(PhoneBook &phonebook); // Load contacts on startup
};
void displayMenu() {
    cout << "1. Add Contact" << endl;
    cout << "2. Search Contact" << endl;
    cout << "3. Delete Contact" << endl;
    cout << "4. Display All Contacts" << endl;
    cout << "5. Save & Exit" << endl;
}
int main() {
    PhoneBook phonebook;
    FileHandler fileHandler;
    
    // Load existing contacts
    fileHandler.loadFromFile(phonebook);
    
    // Example: Add a contact
    Contact c1("John Doe", "1234567890", "john@example.com", "123 Main St");
    phonebook.addContact(c1);
    
    // Example: Search for a contact
    phonebook.searchContactByName("John Doe");
    
    // Example: Display all contacts
    phonebook.displayAllContacts();
    
    // Save and exit
    fileHandler.saveToFile(phonebook);
    
    return 0;
}

